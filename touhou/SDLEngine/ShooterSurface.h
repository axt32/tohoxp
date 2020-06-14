#pragma once
#include "../MemoryLeakChecker.h"
#include "ShooterObject.h"
#include "ShooterRect.h"
#include "ShooterScreen.h"
#include <SDL_Image.h>
#include <vector>
#include <algorithm>
#include <cctype>

//#define DEV_MODE
#ifdef DEV_MODE
//#define PREPATH "..\\Debug\\"
#define PREPATH ""
#else
#define PREPATH ""
#endif

class FilePacker;
class ShooterSurface : public ShooterObject
{
private:

	ShooterScreen * pScreen;

	std::vector<SDL_Texture *> vTexture;

	bool CreateTextureFromSurface(SDL_Surface * IN_Source, std::vector<SDL_Texture *> *IN_Destination);

	bool FreeSurfaceAtPtr (SDL_Surface * IN_Surface);
	bool DestroyTextureAtVector (std::vector<SDL_Texture *> * IN_Vector);

	bool SetColorKey(SDL_Surface * IN_Surface, Uint32 IN_ColorKey);

	bool bUseColorKey;
	Uint32 ColorKey;
	Uint8 Alpha;

	bool isPNG;

	bool _LoadSurface(std::string IN_Path, SDL_Surface * IN_Surface, ShooterScreen * IN_Screen, bool IN_ColorKey = true, bool IN_AutoColorKey = true, Uint8 IN_Red = 0, Uint8 IN_Green = 0, Uint8 IN_Blue = 0);

public:
	static void InitPNG();
	static void ExitPNG();

	ShooterSurface();
	~ShooterSurface();
	bool LoadSurface(std::string IN_Path, ShooterScreen * IN_Screen, bool IN_ColorKey = true, bool IN_AutoColorKey = true, Uint8 IN_Red = 0, Uint8 IN_Green = 0, Uint8 IN_Blue = 0);
	bool LoadSurface(std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, bool IN_ColorKey = true, bool IN_AutoColorKey = true, Uint8 IN_Red = 0, Uint8 IN_Green = 0, Uint8 IN_Blue = 0);

	void FreeSurface();

	//pSrcRect�� NULL�� �ϸ� �ǰ�, pDestRect�� x, y���� �������ָ� ���ϴ� ��ġ�� ��ο� �����ϴ�.
	bool DrawSurface(ShooterRect * pSrcRect, ShooterRect * pDestRect, double IN_angle = 0.0, double IN_zoom = 1.0);

	bool SetAlpha(Uint8 IN_Alpha);
	bool GetAlpha(Uint8 * OUT_Alpha);

	int GetSurfaceWidth();
	int GetSurfaceHeight();

	Uint32 * GetPixels();
	SDL_PixelFormat * GetFormat();
	int GetPitch();
	SDL_Surface * GetSurface();
	bool SetSurface(SDL_Surface * IN_Surface, ShooterScreen * IN_Screen);
};