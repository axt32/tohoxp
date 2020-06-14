#include "ShooterSurface.h"

#include "FilePacker/FilePacker.h"

ShooterSurface :: ShooterSurface()
{
	ColorKey = 0;		//문제의 소지가 있을수도..
	vTexture.clear();
	Alpha = SDL_ALPHA_OPAQUE;

	isPNG = false;
}

ShooterSurface :: ~ShooterSurface()
{
	//	printf("테스트용 : ShooterSurface Destructor\n");
	FreeSurface();
}

void ShooterSurface :: InitPNG()
{
	printf ("Initalizing PNG Library ...\n");
	SDL_version compile_version;
	const SDL_version * link_version = IMG_Linked_Version();
	SDL_IMAGE_VERSION(&compile_version);
	printf ("SDL_Image Compiled Version : %d.%d.%d\n", compile_version.major, compile_version.minor, compile_version.patch);
	printf ("SDL_Image Running Version : %d.%d.%d\n", link_version->major, link_version->minor, link_version->patch);

	int result = IMG_Init(IMG_INIT_PNG);
	if ( result == IMG_INIT_PNG)
	{
		printf ("OK\n");
	}
	else
	{
		printf ("Failed.\n");
	}
}

void ShooterSurface :: ExitPNG()
{
	IMG_Quit();
}

bool ShooterSurface :: CreateTextureFromSurface(SDL_Surface * IN_Source, std::vector<SDL_Texture *> *IN_Destination)
{
	CommonState * pState;
	pScreen->GetState(&pState);

	//텍스처를 만들음.

	for (int i = 0; i < pState->num_windows; i++)
	{
		SDL_Renderer *renderer = pState->renderers[i];		
		SDL_Texture * pTexture = SDL_CreateTextureFromSurface(renderer, IN_Source);
		if (! pTexture ) {
			printf("Couldn't create texture: %s\n", SDL_GetError());
			SDL_FreeSurface(IN_Source);
			return false;
		}

		SDL_SetTextureBlendMode( pTexture, SDL_BLENDMODE_BLEND);
		IN_Destination->push_back(pTexture);		

	}

	return true;
}

bool ShooterSurface :: FreeSurfaceAtPtr (SDL_Surface * IN_Surface)
{
	if (IN_Surface != NULL)
	{
		SDL_FreeSurface (IN_Surface);
		return true;
	}

	return false;
}

bool ShooterSurface :: DestroyTextureAtVector (std::vector<SDL_Texture *> * IN_Vector)
{
	if (IN_Vector->size() > 0)
	{
		for (int i = 0; i < IN_Vector->size(); i++)
		{
			SDL_DestroyTexture( (*IN_Vector)[i]);
			// 			if ( (*IN_Vector)[i])
			// 			{
			// 				SDL_free ( (*IN_Vector)[i] );
			// 			}
		}

		IN_Vector->clear();

		return true;
	}

	return false;
}

bool ShooterSurface :: SetColorKey (SDL_Surface * IN_Surface, Uint32 IN_ColorKey)
{
	ColorKey = IN_ColorKey;
	//			Uint32 Key = (*(Uint32 *) pSurface->pixels);
	if (IN_Surface->format->palette) {
		SDL_SetColorKey(IN_Surface, 1, (Uint8) ColorKey);
	} else {
		switch (IN_Surface->format->BitsPerPixel) {
		case 15:
			SDL_SetColorKey(IN_Surface, 1, ((Uint16 )ColorKey) & 0x00007FFF);
			break;
		case 16:
			SDL_SetColorKey(IN_Surface, 1, (Uint16) ColorKey);
			break;
		case 24:
			//SDL_SetColorKey(IN_Surface, 1, ColorKey);
			SDL_SetColorKey(IN_Surface, 1, (Uint32) ColorKey & 0x00FFFFFF);
			break;
		case 32:
			SDL_SetColorKey(IN_Surface, 1, (Uint32 ) ColorKey);
			break;
		default:
			return false;
		}

	}

	return true;
}

bool ShooterSurface :: _LoadSurface(std::string IN_Path, SDL_Surface * IN_Surface, ShooterScreen * IN_Screen, bool IN_ColorKey, bool IN_AutoColorKey, Uint8 IN_Red, Uint8 IN_Green, Uint8 IN_Blue)
{
	if (IN_Surface == NULL)
	{
		printf ("Load Failed : %s\n", IN_Path.c_str());		//touhou custom
		return false;
	}

	//서페이스에 컬러키를 입힘
	bUseColorKey = IN_ColorKey;

	if (bUseColorKey == true)
	{
		if (IN_AutoColorKey == true)
		{
			Uint32 * pPixels = (Uint32*)(IN_Surface->pixels);
			SetColorKey(IN_Surface, pPixels[0]);
		}
		else
		{
			SetColorKey(IN_Surface, SDL_MapRGB(IN_Surface->format, IN_Red, IN_Green, IN_Blue));
		}
	}

	pScreen = IN_Screen;		

	CreateTextureFromSurface(IN_Surface, &vTexture);

	SetObject(IN_Surface);

//	printf ("OK\n");

	return true;
}

bool ShooterSurface :: LoadSurface(std::string IN_Path, ShooterScreen * IN_Screen, bool IN_ColorKey, bool IN_AutoColorKey, Uint8 IN_Red, Uint8 IN_Green, Uint8 IN_Blue)
{

	if (GetLoaded() == false)
	{
		//파일을 불러와 서페이스를 만들기
		std::string CombinedPath;
		CombinedPath = PREPATH;
		CombinedPath.append(IN_Path);
		SDL_Surface * pSurface = NULL;
		//printf ("Loading Image : %s ... ", CombinedPath.c_str(), CombinedPath.c_str());

		std::string Extension = (CombinedPath.substr(CombinedPath.length() - 3, 3));
		std::transform(Extension.begin(), Extension.end(), Extension.begin(), std::tolower);

		if ( Extension == "png" )
		{
			isPNG = true;
			pSurface = IMG_Load(IN_Path.c_str());
		}
		else
		{
			isPNG = false;
			pSurface = SDL_LoadBMP(IN_Path.c_str());
		}

		return _LoadSurface(IN_Path, pSurface, IN_Screen, IN_ColorKey, IN_AutoColorKey, IN_Red, IN_Green, IN_Blue);

	}

	return false;

}

bool ShooterSurface :: LoadSurface(std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, bool IN_ColorKey, bool IN_AutoColorKey, Uint8 IN_Red, Uint8 IN_Green, Uint8 IN_Blue)
{
	if (GetLoaded() == false)
	{
		//패킹 파일에서 불러와 서페이스를 만들기
		//printf ("Loading Image : %s ... ", IN_Path.c_str());

		char * FilePtr = NULL;
		int iFileSize = 0;
		FilePacker filepacker;
		
		filepacker.GetFilePtr(IN_PackFilePath, IN_Path, &FilePtr, &iFileSize);

		if (FilePtr == NULL)
		{
			printf ("Failed\n");
			return false;
		}

		SDL_Surface * pSurface = NULL;

		std::string Extension = (IN_Path.substr(IN_Path.length() - 3, 3));
		std::transform(Extension.begin(), Extension.end(), Extension.begin(), std::tolower);

		if ( Extension == "png" )
		{
			isPNG = true;
			pSurface = IMG_Load_RW(SDL_RWFromMem(FilePtr, iFileSize), 1);
		}
		else
		{
			isPNG = false;
			pSurface = SDL_LoadBMP_RW(SDL_RWFromMem(FilePtr, iFileSize), 1);
		}

		filepacker.DeleteFilePtr();

		return _LoadSurface(IN_Path, pSurface, IN_Screen, IN_ColorKey, IN_AutoColorKey, IN_Red, IN_Green, IN_Blue);

	}

	return false;
}

void ShooterSurface :: FreeSurface()
{
	if (GetLoaded() == true)
	{

		FreeSurfaceAtPtr ( GetSurface() );
		DestroyTextureAtVector(&vTexture);

		SetLoaded(false);
	}

}

bool ShooterSurface :: DrawSurface(ShooterRect * pSrcRect, ShooterRect * pDestRect, double IN_Angle, double IN_Zoom)
{
	if (GetLoaded() == false)
	{
		return false;
	}

	pDestRect->Set_W( pDestRect->Get_W() * IN_Zoom);
	pDestRect->Set_H( pDestRect->Get_H() * IN_Zoom);


	CommonState *pState;
	pScreen->GetState(&pState);
	for (int i = 0; i < pState->num_windows; ++i)
	{
		for (int i = 0; i < pState->num_windows; ++i)
		{
			if (pSrcRect == NULL)
			{
				SDL_Point point;
				point.x = GetSurfaceWidth() / 2;
				point.y = GetSurfaceHeight() / 2;
				if (SDL_RenderCopyEx(pState->renderers[i], vTexture[i], NULL, pDestRect->GetRect(), IN_Angle, NULL, SDL_FLIP_NONE) < 0)
				{
					printf ("FAIL!\n");
				}
			}
			else
			{
				SDL_Point point;
				point.x = pSrcRect->Get_W() / 2;
				point.y = pSrcRect->Get_H() / 2;
				if (SDL_RenderCopyEx(pState->renderers[i], vTexture[i], pSrcRect->GetRect(), pDestRect->GetRect(), IN_Angle, NULL, SDL_FLIP_NONE) < 0)
				{
					printf ("FAIL!\n");
				}
			}
		}
	}

	return true;
}

bool ShooterSurface :: SetAlpha(Uint8 IN_Alpha)
{
	if (GetLoaded() == true)
	{
		Alpha = IN_Alpha;
		CommonState * pState;
		pScreen->GetState(&pState);

		auto SetAlphaAtVector = [&] (std::vector<SDL_Texture *> * IN_Vector)
		{
			if (IN_Vector->size() > 0)
			{
				for (int i = 0; i < IN_Vector->size(); ++i)
				{
					if ( (*IN_Vector)[i])
					{
						SDL_SetTextureAlphaMod((*IN_Vector)[i], IN_Alpha);
					}
				}

			}
		};

		SetAlphaAtVector(&vTexture);

		return true;
	}
	return false;
}

bool ShooterSurface :: GetAlpha(Uint8 * OUT_Alpha)
{
	if (GetLoaded() == true)
	{
		*OUT_Alpha = Alpha;
		return true;
	}

	return false;
}

int ShooterSurface :: GetSurfaceWidth()
{
	if (GetLoaded() == true)
	{
		return GetSurface()->w;
	}

	return -1;
}
int ShooterSurface :: GetSurfaceHeight()
{
	if (GetLoaded() == true)
	{
		return GetSurface()->h;
	}

	return -1;
}

Uint32 * ShooterSurface :: GetPixels()
{
	if (GetLoaded() == true)
	{
		return (Uint32*)(GetSurface()->pixels);
	}

	return NULL;
}

SDL_PixelFormat * ShooterSurface :: GetFormat()
{
	if (GetLoaded() == true)
	{
		return GetSurface()->format;
	}

	return NULL;
}

int ShooterSurface :: GetPitch()
{
	return GetSurface()->pitch;
}

SDL_Surface * ShooterSurface :: GetSurface()
{
	if (GetLoaded() == true)
	{
		return (SDL_Surface*)GetObject();
	}

	return NULL;

}

bool ShooterSurface :: SetSurface(SDL_Surface * IN_Surface, ShooterScreen * IN_Screen)
{
	if (GetLoaded() == false)
	{
		pScreen = IN_Screen;
		if (vTexture.size() == 0)
		{
			CreateTextureFromSurface(IN_Surface, &vTexture);
		}
		SetObject(IN_Surface);

		return true;
	}

	return false;

}