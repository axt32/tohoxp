#include "ShooterFont.h"
#include "FilePacker/FilePacker.h"
#include <windows.h>

std::wstring MBToWC(std::string IN_String)
{
	WCHAR WideCharStr[255];
	int iLength = IN_String.length();

	MultiByteToWideChar(CP_ACP,MB_ERR_INVALID_CHARS,IN_String.c_str(), iLength, WideCharStr, 255);


	//한글, 영어 관계없이 '한 글자'를 1로 계산하는 Length함수 제작.
	int iNewLength = 0;
	bool bEven = false;

	for (std::string::iterator Iter = IN_String.begin(); Iter != IN_String.end(); Iter++)
	{

		if ( *Iter < 0)
		{
			if (bEven == true)
			{
				iNewLength++;
				bEven = false;
			}
			else
			{
				bEven = true;
			}
		}
		else
		{
			iNewLength++;
		}
	}
	
	for (int i = iNewLength; i < 255; i++)
	{
		WideCharStr[i] = NULL;
	}

	std::wstring result;
	result = std::wstring(WideCharStr);
	return result;
}

ShooterFont :: ShooterFont()
{
	m_pFontRawData = NULL;
}
ShooterFont :: ~ShooterFont()
{
	UnloadFont();
}

void ShooterFont :: InitFont()
{
	printf ("Initalizing Font System ... ");
	if (TTF_Init() == -1)
	{
		printf ("Failed\n");
	}
	else
	{
		printf ("OK\n");
	}
}

bool ShooterFont :: _LoadFont(std::string IN_Path, TTF_Font * IN_Font, ShooterScreen * IN_Screen, int IN_FontSize)
{
	if (IN_Font == NULL)
	{
		printf ("Failed : %s\n", IN_Path.c_str());
		return false;
	}

	iFontSize = IN_FontSize;
	SetObject( IN_Font );
	m_pFont = IN_Font;

	pScreen = IN_Screen;

	//printf ("OK\n");

	TTF_SetFontHinting(IN_Font, TTF_HINTING_LIGHT);

	return true;
}

bool ShooterFont :: LoadFont(std::string IN_Path, ShooterScreen * IN_Screen, int IN_FontSize)
{
//	printf ("Loading Font : %s ... ", IN_Path.c_str());

	if (GetLoaded() == true)
	{
		printf ("Failed : %s\n", IN_Path.c_str());
		return false;
	}

	TTF_Font * pFont = TTF_OpenFont(IN_Path.c_str(), IN_FontSize);

	_LoadFont(IN_Path, pFont, IN_Screen, IN_FontSize);

	return true;

}

bool ShooterFont :: LoadFont (std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, int IN_FontSize)
{
	//printf ("Loading Font : %s ... ", IN_Path.c_str());

	if (GetLoaded() == true)
	{
		printf ("Failed : %s\n", IN_Path.c_str());
		return false;
	}

	int iFileSize = 0;
	FilePacker filepacker;

	filepacker.GetFilePtr(IN_PackFilePath, IN_Path,  &m_pFontRawData, &iFileSize);

	if (m_pFontRawData == NULL)
	{
		printf ("Failed : %s\n", IN_Path.c_str());
		return false;
	}

	TTF_Font * pFont = TTF_OpenFontRW(SDL_RWFromMem(m_pFontRawData, iFileSize), 1, IN_FontSize);
	//filepacker.DeleteFilePtr();

	return _LoadFont(IN_Path, pFont, IN_Screen, IN_FontSize);

}

bool ShooterFont :: SetFontStyle (FONT_STYLE IN_Style)
{

	if (GetLoaded() == false)
	{
		return false;
	}

	TTF_SetFontStyle(m_pFont, IN_Style);

	return true;
}

bool ShooterFont :: SetFontOutline (int IN_Thickness)
{
	if (GetLoaded() == false)
	{
		return false;
	}

	TTF_SetFontOutline(m_pFont, IN_Thickness);

	return true;
}

bool ShooterFont :: UnloadFont()
{
	if (GetLoaded() == true)
	{
		if (  m_pFont != NULL)
		{
			TTF_CloseFont(m_pFont);
			delete[] m_pFontRawData;
		}
	}

	return false;
}
bool ShooterFont :: PrintFont(ShooterSprite * IN_Sprite, std::string IN_Text, int IN_R, int IN_G, int IN_B, PRINT_STYLE IN_Style, int IN_ShadeR, int IN_ShadeG, int IN_ShadeB)
{

	if (IN_Sprite->GetLoaded() == true)
	{
		IN_Sprite->FreeSprite();
	}
	
	SDL_Surface * output_surface;
	SDL_Color MyColor = {IN_R, IN_G, IN_B};
	SDL_Color MyShadeColor = {IN_ShadeR, IN_ShadeG, IN_ShadeB};
	
	if (IN_Style == FONT_SOLID)
	{
		output_surface = TTF_RenderUNICODE_Solid(m_pFont, (Uint16*)(MBToWC(IN_Text).c_str()), MyColor);
	}
	else if (IN_Style == FONT_SHADED)
	{
		output_surface = TTF_RenderUNICODE_Shaded(m_pFont, (Uint16*)(MBToWC(IN_Text).c_str()), MyColor, MyShadeColor);
	}
	else if (IN_Style == FONT_BLENDED)
	{
		output_surface = TTF_RenderUNICODE_Blended(m_pFont, (Uint16*)(MBToWC(IN_Text).c_str()), MyColor);
	}

	IN_Sprite->FreeSprite();
	IN_Sprite->SetSurface(output_surface, pScreen);
	IN_Sprite->SetWidth(output_surface->w);
	IN_Sprite->SetHeight(output_surface->h);
	IN_Sprite->SetMaxFrame(1);

	return true;
}

int ShooterFont :: GetFontSize()
{
	if (GetLoaded() == false)
	{
		return -1;
	}

	return iFontSize;
}