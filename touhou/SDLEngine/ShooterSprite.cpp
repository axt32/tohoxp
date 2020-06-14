#include "ShooterSprite.h"
#include "FilePacker/FilePacker.h"

ShooterSprite :: ShooterSprite()
{
	w = 0;
	h = 0;
	iMaxFrame = 0;
}

ShooterSprite :: ~ShooterSprite()
{

}

bool ShooterSprite :: LoadSprite(std::string IN_Path, ShooterScreen * IN_Screen, bool IN_ColorKey, bool IN_AutoColorKey)
{
	if (LoadSprite(IN_Path, IN_Screen, 0, 0, 1, IN_ColorKey, IN_AutoColorKey) == true)
	{

		w = GetSurface()->w;
		h = GetSurface()->h;

		return true;
	}

	return false; 
}
bool ShooterSprite :: LoadSprite(std::string IN_Path, ShooterScreen * IN_Screen, Uint8 IN_Red, Uint8 IN_Green, Uint8 IN_Blue)
{
	if (LoadSprite(IN_Path, IN_Screen, 0, 0, 1, true, false, IN_Red, IN_Green, IN_Blue) == true)
	{
		w = GetSurface()->w;
		h = GetSurface()->h;

		return true;
	}

	return false;
}

bool ShooterSprite :: LoadSprite(std::string IN_Path, ShooterScreen * IN_Screen, int IN_w, int IN_h, int IN_frames, bool IN_ColorKey, bool IN_AutoColorKey, Uint8 IN_Red, Uint8 IN_Green, Uint8 IN_Blue)
{
	if (GetLoaded() == false)
	{
		if (LoadSurface(IN_Path, IN_Screen, IN_ColorKey, IN_AutoColorKey, IN_Red, IN_Green, IN_Blue) == false)
		{
			return false;
		}

		w = IN_w;
		h = IN_h;
		iMaxFrame = IN_frames;

		return true;
	}

	return false;
}

bool ShooterSprite :: LoadSprite(std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, bool IN_ColorKey, bool IN_AutoColorKey)
{
	if (LoadSprite(IN_PackFilePath, IN_Path, IN_Screen, 0, 0, 1, IN_ColorKey, IN_AutoColorKey) == true)
	{

		w = GetSurface()->w;
		h = GetSurface()->h;

		return true;
	}

	return false; 
}
bool ShooterSprite :: LoadSprite(std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, Uint8 IN_Red, Uint8 IN_Green, Uint8 IN_Blue)
{
	if (LoadSprite(IN_PackFilePath, IN_Path, IN_Screen, 0, 0, 1, true, false, IN_Red, IN_Green, IN_Blue) == true)
	{
		w = GetSurface()->w;
		h = GetSurface()->h;

		return true;
	}

	return false;
}
bool ShooterSprite :: LoadSprite(std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, int IN_w, int IN_h, int IN_frames, bool IN_ColorKey, bool IN_AutoColorKey, Uint8 IN_Red, Uint8 IN_Green, Uint8 IN_Blue)
{
	if (GetLoaded() == false)
	{
		if (LoadSurface(IN_PackFilePath, IN_Path, IN_Screen, IN_ColorKey, IN_AutoColorKey, IN_Red, IN_Green, IN_Blue) == false)
		{
			return false;
		}

		w = IN_w;
		h = IN_h;
		iMaxFrame = IN_frames;

		return true;
	}

	return false;
}


bool ShooterSprite :: DrawSprite(int IN_x, int IN_y, int IN_Frame, double IN_Angle, double IN_Zoom)
{
	ShooterRect rect1(IN_Frame * w, 0, w, h);
	//SDL 2.0 : DestRect에도 Width, Height를 넣어야 됩니다.
	ShooterRect rect2(IN_x, IN_y, w, h);

	return DrawSurface(&rect1, &rect2, IN_Angle, IN_Zoom);
}

bool ShooterSprite :: DrawSpriteCenter(int IN_x, int IN_y, int IN_Frame, double IN_Angle, double IN_Zoom)
{
	return DrawSprite ( RoundInt((double)IN_x - (double)GetWidth() / 2.0), RoundInt((double)IN_y - (double)GetHeight() / 2.0), IN_Frame, IN_Angle, IN_Zoom);
}

int ShooterSprite :: GetMaxFrame()
{
	if (GetLoaded() == false)
	{
		return -1;
	}
	return iMaxFrame;
}

int ShooterSprite :: GetWidth()
{
	return w;
}

int ShooterSprite :: GetHeight()
{
	return h;
}

void ShooterSprite :: SetMaxFrame(int IN_MaxFrame)
{
	iMaxFrame = IN_MaxFrame;
}
void ShooterSprite :: SetWidth(int IN_w)
{
	w = IN_w;
}
void ShooterSprite :: SetHeight(int IN_h)
{
	h = IN_h;
}

void ShooterSprite :: FreeSprite()
{
	FreeSurface();
}