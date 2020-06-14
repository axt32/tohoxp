#include "GamePlay.h"

void PreTreat()
{
	switch (iGameState)
	{
	case INTRO:
		break;
	case MAINMENULOGO:
		break;
	case MAINMENU:
		break;
	case CHARASELECT:
		break;
	case GAMESTATE_GAME:
		PreTreat_Game();
		break;
	case GAMECREDITS:
		break;
	case RECORDSTATUS:
		break;
	}

}

void ApplyKeyInput()
{
	switch (iGameState)
	{
	case INTRO:
		Input_Intro();
		break;
	case MAINMENULOGO:
		break;
	case MAINMENU:
		Input_MainMenu();
		break;
	case CHARASELECT:
		Input_CharaSelect();
		break;
	case GAMESTATE_GAME:
		Input_Game();
		break;
	case GAMECREDITS:
		Input_GameCredits();
		break;
	case RECORDSTATUS:
		Input_RecordStatus();
		break;
	}
	
	GameInput.FlushInput();
}

void GamePlay()
{
	PreTreat();
	ApplyKeyInput();
	//키입력을 받은 결과, 강제종료 명령이 있을경우.
	if (bRunning == false)
	{
		return;
	}
	
	GameScreen.FillColor();
	DrawGame();
//	GameScreen.FromBackBuffer();

	GameScreen.Flip();

}

void DrawGame()
{
	switch (iGameState)
	{
	case INTRO:
		Draw_Intro();
		break;
	case MAINMENULOGO:
		break;
	case MAINMENU:
		Draw_MainMenu();
		break;
	case CHARASELECT:
		Draw_CharaSelect();
		break;
	case GAMESTATE_GAME:
		GameState_Game();
		break;
	case GAMECREDITS:
		Draw_GameCredits();
		break;
	case RECORDSTATUS:
		Draw_ScoreBoard_State();
		break;
	}

	//UI는 전 모드 공통으로 이 코드에서 출력된다.
	DrawFPS();
}

void DrawFPS()
{
//	GameScreen.SetWindowCaption("Toho Explosion (Ver : 1.10) - " + std::to_string((_ULonglong)GameBulletVector.size()));
	std::string fpsstring = "MS : " + std::to_string((double long)iFrameTime) +  " fps" + std::to_string((double long)fFrameRate).substr(0, 4);
	Shooter_DrawText(&Spr_TinyFont, fpsstring, 0, UI_FPS_Y);

}