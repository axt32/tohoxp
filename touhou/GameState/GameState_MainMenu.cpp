#include "GameState_MainMenu.h"

int iMainMenu_CurrentMenu;

void Init_MainMenu(bool IN_PlayBGM)
{
	if (IN_PlayBGM == true)
	{
		StopMusicAllinOne();
		FreeMusicAllInOne();
		if (bBGM_Use == true)
		{
			Music_MainMenu.LoadSound("data.rom", "music/mainmenu.ogg", &MySoundManager);
			Music_MainMenu.Play(true, NULL, fVolume_BGM);
		}

	}
	iGameState = MAINMENU;
	iMainMenu_CurrentMenu = MAINMENU_SORTIE;
}

void Input_MainMenu()
{
	if (GameInput.GetInput(QUIT))
	{
		//'QUIT' 명령시 ->  강제종료.
		bRunning = false;
		return;
	}

	if (GameInput.GetPreviousInput(iKey_Down) == false && GameInput.GetInput(iKey_Down))
	{
		Sound_Select.Play(false, NULL, fVolume_SE);
		iMainMenu_CurrentMenu++;

		if (iMainMenu_CurrentMenu > MAINMENU_EXIT)
		{
			iMainMenu_CurrentMenu = MAINMENU_SORTIE;
		}
	}
	else if (GameInput.GetPreviousInput(iKey_Up) == false && GameInput.GetInput(iKey_Up))
	{
		Sound_Select.Play(false, NULL, fVolume_SE);
		iMainMenu_CurrentMenu--;

		if (iMainMenu_CurrentMenu < MAINMENU_SORTIE)
		{
			iMainMenu_CurrentMenu = MAINMENU_EXIT;
		}
	}
	else if ( (GameInput.GetPreviousInput(KEY_RETURN) == false && GameInput.GetInput(KEY_RETURN))
		|| (GameInput.GetPreviousInput(iKey_Attack) == false && GameInput.GetInput(iKey_Attack)))
	{
		Sound_Okay.Play(false, NULL, fVolume_SE);
		switch (iMainMenu_CurrentMenu)
		{
		case MAINMENU_SORTIE:
			Init_CharaSelect();
			break;
		case MAINMENU_RECORD:
			Init_ScoreBoard_State(false);
			break;
		case MAINMENU_EXIT:
			bRunning = false;
		default:
			printf ("MainMenu Exception!!\n");
		}
	}
}

void Draw_MainMenu()
{
	Spr_UI_MainMenu_Background.DrawSprite(0, 0, 0);
	Spr_UI_MainMenu_Gamelogo.DrawSprite(UI_MAINMENU_GAMELOGO_X, UI_MAINMENU_GAMELOGO_Y, 0);
	
	if (iMainMenu_CurrentMenu == MAINMENU_SORTIE)
	{
		Spr_UI_MainMenu_Sortie_Selected.DrawSpriteCenter(UI_MAINMENU_MENU_SORTIE_CENTER_X, UI_MAINMENU_MENU_SORTIE_CENTER_Y, 0);
	}
	else
	{
		Spr_UI_MainMenu_Sortie.DrawSpriteCenter(UI_MAINMENU_MENU_SORTIE_CENTER_X, UI_MAINMENU_MENU_SORTIE_CENTER_Y, 0);
	}

	if (iMainMenu_CurrentMenu == MAINMENU_RECORD)
	{
		Spr_UI_MainMenu_Record_Selected.DrawSpriteCenter(UI_MAINMENU_MENU_OPTIONS_CENTER_X, UI_MAINMENU_MENU_OPTIONS_CENTER_Y, 0);

	}
	else
	{
		Spr_UI_MainMenu_Record.DrawSpriteCenter(UI_MAINMENU_MENU_OPTIONS_CENTER_X, UI_MAINMENU_MENU_OPTIONS_CENTER_Y, 0);
	}

	if (iMainMenu_CurrentMenu == MAINMENU_EXIT)
	{
		Spr_UI_MainMenu_Exit_Selected.DrawSpriteCenter(UI_MAINMENU_MENU_EXIT_CENTER_X, UI_MAINMENU_MENU_EXIT_CENTER_Y, 0);

	}
	else
	{
		Spr_UI_MainMenu_Exit.DrawSpriteCenter(UI_MAINMENU_MENU_EXIT_CENTER_X, UI_MAINMENU_MENU_EXIT_CENTER_Y, 0);
	}

	Spr_UI_MainMenu_Copyright.DrawSprite(UI_MAINMENU_COPYRIGHT_X, UI_MAINMENU_COPYRIGHT_Y, 0);

}