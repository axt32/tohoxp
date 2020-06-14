#include "GameState_GameOver_Score.h"

void InitGameOver_Score()
{
	ClearRecord();
	PauseMusicAllInOne();
//	StopMusicAllinOne();
	//FreeMusicAllInOne();
	if (bBGM_Use == true)
	{
		Music_GameOver.LoadSound("data.rom", "music/gameover.ogg", &MySoundManager);
		Music_GameOver.Play(true, NULL, fVolume_BGM);
	}

	if (LoadRecord() == true)
	{
		bool bRanked = CheckRecord();
		if (bRanked == true)
		{
			iScoreBoard_Score_PosCol = 0;
			iScoreBoard_Score_PosRow = 0;
			iGameState_Game_PauseType = PAUSE_GAMEOVERSCORE;
		}
		else
		{
			ClearRecord();
			iGameState_Game_PauseType = PAUSE_GAMEOVERMENU;
			iCurrentGameOverMenuStatus = GAMEOVERMENU_CONTINUE;
		}
	}
	else
	{
		printf ("Record Load Failed !!\n");
		ClearRecord();
		iGameState_Game_PauseType = PAUSE_GAMEOVERMENU;
		iCurrentGameOverMenuStatus = GAMEOVERMENU_CONTINUE;
	}

	bPause = true;
}

void DrawGameOver_Score()
{
	Shooter_DrawText(&Spr_NormalFont, "Score Ranking!!", (double)GAMEOVER_SCORE_TITLE_X, (double)GAMEOVER_SCORE_TITLE_Y);
	
	std::string sName;
	int iScore;
	int iStage;

	int iRow = 0;
	GoToFirst();
	bool bIsPlayer = false;
	while (GetRecord(&sName, NULL, &iScore, NULL, &iStage, &bIsPlayer) == true)
	{
		ShooterSprite * pFont;
		if (bIsPlayer == true)
		{
			pFont = &Spr_NormalFont_Selected;
		}
		else
		{
			pFont = &Spr_NormalFont_Gray;
		}
		Shooter_DrawText(pFont, std::to_string((_Longlong)(iRow + 1)), GAMEOVER_SCORE_TABLE_COLUMN0_X, GAMEOVER_SCORE_TABLE_COLUMN0_Y + iRow * 17);
		Shooter_DrawText(pFont, sName, GAMEOVER_SCORE_TABLE_COLUMN1_X, GAMEOVER_SCORE_TABLE_COLUMN1_Y + iRow * 17);
		Shooter_DrawText(pFont, std::to_string((_Longlong)(iScore)), GAMEOVER_SCORE_TABLE_COLUMN2_X, GAMEOVER_SCORE_TABLE_COLUMN2_Y + iRow * 17, 9);
		if (iStage < 3)
		{
			Shooter_DrawText(pFont, "Stage" + std::to_string((_Longlong)(iStage)), GAMEOVER_SCORE_TABLE_COLUMN3_X, GAMEOVER_SCORE_TABLE_COLUMN3_Y + iRow * 17);
		}
		else
		{
			Shooter_DrawText(pFont, "Clear", GAMEOVER_SCORE_TABLE_COLUMN3_X, GAMEOVER_SCORE_TABLE_COLUMN3_Y + iRow * 17);
		}
		iRow++;
	}

	DrawCharTable(SCOREBOARD_STATUS_CHARTABLE_X, SCOREBOARD_STATUS_CHARTABLE_Y);
}