#pragma once
#include "../MemoryLeakChecker.h"
#include "ShooterObject.h"
#include "ShooterSprite.h"
#include "ShooterScreen.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string.h>

typedef enum FONT_STYLE
{
	FONT_NORMAL	= 0x00,
	FONT_BOLD = 0x01,
	FONT_ITALIC = 0x02,
	FONT_UNDERLINE = 0x04,
	FONT_STRIKETHROUGH = 0x08
};

typedef enum PRINT_STYLE
{
	FONT_SOLID = 0,
	FONT_SHADED,
	FONT_BLENDED
};

std::wstring MBToWC(std::string IN_Strings);

class ShooterFont : public ShooterObject
{
private:
	int iFontSize;
	SDL_Surface * font_surface;

	ShooterScreen * pScreen;
	TTF_Font * m_pFont;
	char * m_pFontRawData;

	bool _LoadFont(std::string IN_Path, TTF_Font * IN_Font, ShooterScreen * IN_Screen, int IN_FontSize);
public:
	ShooterFont();
	~ShooterFont();
	static void InitFont();
	bool LoadFont(std::string IN_Path, ShooterScreen * IN_Screen, int IN_FontSize);
	bool LoadFont (std::string IN_PackFilePath, std::string IN_Path, ShooterScreen * IN_Screen, int IN_FontSize);
	bool SetFontStyle (FONT_STYLE IN_Style);
	bool SetFontOutline (int IN_Thickness);
	bool UnloadFont();
	bool PrintFont(ShooterSprite * IN_Sprite, std::string IN_Text, int IN_R = 0, int IN_G = 0, int IN_B = 0, PRINT_STYLE IN_Style = FONT_SOLID, int IN_ShadeR = 255, int IN_ShadeG = 255, int IN_ShadeB = 255);
	int GetFontSize();
};