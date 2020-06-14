
#pragma once
#include "../MemoryLeakChecker.h"
#include "ShooterObject.h"
#include "ShooterSurface.h"
#include "../GameCore/Angle360.h"

class FilePacker;
class ShooterSprite : public ShooterSurface
{
private:
	int w;
	int h;
	int iMaxFrame;	//1부터이다.

public:
	ShooterSprite();
	~ShooterSprite();
	bool LoadSprite(std::string IN_Path, ShooterScreen * IN_Screen, bool IN_ColorKey = true, bool IN_AutoColorKey = true);
	bool LoadSprite(std::string IN_Path, ShooterScreen * IN_Screen, Uint8 IN_Red, Uint8 IN_Green, Uint8 IN_Blue);
	bool LoadSprite(std::string IN_Path, ShooterScreen * IN_Screen, int IN_w, int IN_h, int IN_frames, bool IN_ColorKey = true, bool IN_AutoColorKey = true, Uint8 IN_Red =  0, Uint8 IN_Green = 0, Uint8 IN_Blue = 0);

	bool LoadSprite(std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, bool IN_ColorKey = true, bool IN_AutoColorKey = true);
	bool LoadSprite(std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, Uint8 IN_Red, Uint8 IN_Green, Uint8 IN_Blue);
	bool LoadSprite(std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, int IN_w, int IN_h, int IN_frames, bool IN_ColorKey = true, bool IN_AutoColorKey = true, Uint8 IN_Red =  0, Uint8 IN_Green = 0, Uint8 IN_Blue = 0);

	
	bool DrawSprite(int IN_x, int IN_y, int IN_Frame, double IN_Angle = 0.0, double IN_Zoom = 1.0);
	bool DrawSpriteCenter(int IN_x, int IN_y, int IN_Frame, double IN_Angle = 0.0, double IN_Zoom = 1.0);

	int GetMaxFrame();
	int GetWidth();
	int GetHeight();
	void FreeSprite();

	void SetMaxFrame(int IN_MaxFrame);
	void SetWidth(int IN_w);
	void SetHeight(int IN_h);
};