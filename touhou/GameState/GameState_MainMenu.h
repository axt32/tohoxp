#pragma once
#include "../MemoryLeakChecker.h"
#include "../GameCore/Declarations.h"
#include "../GameCore/CommonUtil.h"

#define UI_MAINMENU_GAMELOGO_X 175
#define UI_MAINMENU_GAMELOGO_Y 58


#define UI_MAINMENU_MENU_SORTIE_CENTER_X 501
#define UI_MAINMENU_MENU_SORTIE_CENTER_Y 278

#define UI_MAINMENU_MENU_OPTIONS_CENTER_X 501
#define UI_MAINMENU_MENU_OPTIONS_CENTER_Y 339

#define UI_MAINMENU_MENU_EXIT_CENTER_X 501
#define UI_MAINMENU_MENU_EXIT_CENTER_Y 400

#define UI_MAINMENU_COPYRIGHT_X 385
#define UI_MAINMENU_COPYRIGHT_Y 439

enum MAINMENU_ENUMS
{
	MAINMENU_SORTIE = 0,
	MAINMENU_RECORD,
	MAINMENU_EXIT
};

extern int iMainMenu_CurrentMenu;

void Init_MainMenu(bool IN_PlayBGM = true);
void Input_MainMenu();
void Draw_MainMenu();