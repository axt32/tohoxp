#include "GameState_Result.h"

int iCurrentResultTime = 0;
ShooterSprite * pResultSprite;

std::string sResult_Title;
std::string sResult_Item0;
std::string sResult_Item1;
std::string sResult_Item2;
std::string sResult_Item3;
std::string sResult_Item4;

void InitResult()
{
	iCurrentResultTime = 0;
	switch (Player.iPlayerCharaType)
	{
	case PLAYERCHARA_REIMU:
		pResultSprite = &Spr_UI_Result_Reimu;
		break;
	case PLAYERCHARA_MARISA:
		pResultSprite = &Spr_UI_Result_Marisa;
		break;
	case PLAYERCHARA_REISEN:
		pResultSprite = &Spr_UI_Result_Reisen;
		break;
	}

	iGameState_Game_Status = GAMESTATE_GAME_RESULT;

	int iBigScoreItemBonus = Player.iBigScoreItemCount * 1500;
	int iSmallScoreItemBonus = Player.iSmallScoreItemCount * 1000;
	int iNoMissBonus = 0;

	sResult_Title = "Stage " + std::to_string( (_Longlong)iCurrentStage) + " Clear !!";
	sResult_Item0 = " X " + std::to_string ( (_Longlong)Player.iBigScoreItemCount) + " = " + std::to_string ( (_Longlong)iBigScoreItemBonus);
	sResult_Item1 = " X " + std::to_string ( (_Longlong)Player.iSmallScoreItemCount) + " = " +  std::to_string ( (_Longlong)iSmallScoreItemBonus);

	if (Player.bNoMiss == true)
	{
		iNoMissBonus = 200000;
		sResult_Item2 = "No Miss = " +  std::to_string ( (_Longlong)iNoMissBonus );
	}
	else
	{
		iNoMissBonus = 0;
		sResult_Item2 = "";
	}

	int iTotal = iBigScoreItemBonus + iSmallScoreItemBonus + iNoMissBonus;

	sResult_Item3 = "Total = " + std::to_string ( (_Longlong)iTotal);

	if (iCurrentStage < 2)
	{
		sResult_Item4 = "Try Next Stage!";
	}
	else
	{
		sResult_Item4 = "All Clear !";
	}

	Player.iScore += iTotal;

}

void DrawResult()
{
	int DrawX = UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH;
	int DrawY = UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT;

	pResultSprite->SetAlpha( SDL_ALPHA_TRANSPARENT + (Uint8) ( (double)iCurrentResultTime / (double)RESULTTIME * 255.0) );

	if (iCurrentResultTime < RESULTTIME)
	{
		iCurrentResultTime++;
	}

	pResultSprite->DrawSprite(DrawX, DrawY, 0);

	DarkScreen_Result.DrawSprite(UI_RESULT_TITLE_X, UI_RESULT_TITLE_Y, 0);

	Shooter_DrawText(&Spr_NormalFont, sResult_Title, UI_RESULT_TITLE_X, UI_RESULT_TITLE_Y);
	Spr_ScoreItem_Big.DrawSpriteCenter(UI_RESULT_ITEMS_X + Spr_ScoreItem_Big.GetWidth() / 2, UI_RESULT_ITEMS_Y + Spr_ScoreItem_Big.GetHeight() / 2, 0);
	Shooter_DrawText(&Spr_NormalFont, sResult_Item0, UI_RESULT_ITEMS_X + Spr_ScoreItem_Big.GetWidth() + 5, UI_RESULT_ITEMS_Y);
	Spr_ScoreItem_Small.DrawSpriteCenter(UI_RESULT_ITEMS_X + Spr_ScoreItem_Small.GetWidth() / 2, UI_RESULT_ITEMS_Y + Spr_NormalFont.GetHeight() + 3 + Spr_ScoreItem_Small.GetHeight() / 2, 0);
	Shooter_DrawText(&Spr_NormalFont, sResult_Item1, UI_RESULT_ITEMS_X + Spr_ScoreItem_Small.GetWidth() + 5, UI_RESULT_ITEMS_Y + Spr_NormalFont.GetHeight() + 3);
	Shooter_DrawText(&Spr_NormalFont, sResult_Item2, UI_RESULT_ITEMS_X, UI_RESULT_ITEMS_Y + (Spr_NormalFont.GetHeight() + 3) * 2);
	Shooter_DrawText(&Spr_NormalFont, sResult_Item3, UI_RESULT_ITEMS_X, UI_RESULT_ITEMS_Y + (Spr_NormalFont.GetHeight() + 3) * 3);
	Shooter_DrawText(&Spr_NormalFont, sResult_Item4, UI_RESULT_ITEMS_X, UI_RESULT_ITEMS_Y + (Spr_NormalFont.GetHeight() + 3) * 4 + 100);

}