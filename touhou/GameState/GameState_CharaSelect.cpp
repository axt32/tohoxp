#include "GameState_CharaSelect.h"

int iCharaSelect_CurrentCharacter;

int iCharaSelect_Portrait_CurrentTime;
int iCharaSelect_Description_CurrentTime;

void Input_CharaSelect()
{
	if (GameInput.GetInput(QUIT))
	{
		//'QUIT' 명령시 ->  강제종료.
		bRunning = false;
		return;
	}

	if ( (GameInput.GetPreviousInput(iKey_Left) == false && GameInput.GetInput(iKey_Left))
		|| (GameInput.GetPreviousInput(iKey_Up) == false && GameInput.GetInput(iKey_Up)))
	{
		if (iCharaSelect_CurrentCharacter == PLAYERCHARA_REIMU)
		{
			iCharaSelect_CurrentCharacter = PLAYERCHARA_REISEN;
		}
		else
		{
			iCharaSelect_CurrentCharacter--;
		}

		iCharaSelect_Portrait_CurrentTime = 0;
		iCharaSelect_Description_CurrentTime = 0;

		Sound_Select.Play(false, NULL, fVolume_SE);
	}
	if ( (GameInput.GetPreviousInput(iKey_Right) == false && GameInput.GetInput(iKey_Right))
		|| (GameInput.GetPreviousInput(iKey_Down) == false && GameInput.GetInput(iKey_Down)))
	{
		if (iCharaSelect_CurrentCharacter == PLAYERCHARA_REISEN)
		{
			iCharaSelect_CurrentCharacter = PLAYERCHARA_REIMU;
		}
		else
		{
			iCharaSelect_CurrentCharacter++;
		}

		iCharaSelect_Portrait_CurrentTime = 0;
		iCharaSelect_Description_CurrentTime = 0;

		Sound_Select.Play(false, NULL, fVolume_SE);
	}
	else if ( (GameInput.GetPreviousInput(iKey_Attack) == false && GameInput.GetInput(iKey_Attack))
				|| (GameInput.GetPreviousInput(KEY_RETURN) == false && GameInput.GetInput(KEY_RETURN)))
	
	{
		iGameState = GAMESTATE_GAME;
		bOnceDescreteInput = true;
		Sound_Okay.Play(false, NULL, fVolume_SE);
		InitGame((PlayerCharaType)iCharaSelect_CurrentCharacter);
	}
	else if ( (GameInput.GetPreviousInput(iKey_Bomber) == false && GameInput.GetInput(iKey_Bomber) )
			|| (GameInput.GetPreviousInput(KEY_ESCAPE) == false && GameInput.GetInput(KEY_ESCAPE)) )
	{
		Init_MainMenu(false);
		Sound_Cancel.Play(false, NULL, fVolume_SE);
	}
	
}

void Init_CharaSelect()
{
	iGameState = CHARASELECT;
	iCharaSelect_CurrentCharacter = PLAYERCHARA_REIMU;
	iCharaSelect_Portrait_CurrentTime = 0;
	iCharaSelect_Description_CurrentTime = 0;
}

void Draw_CharaSelect()
{
	Spr_UI_MainMenu_Background.DrawSprite(0, 0, 0);

	ShooterSprite * pCharaPortrait;
	ShooterSprite * pCharaDescription;

	switch (iCharaSelect_CurrentCharacter)
	{
	case PLAYERCHARA_REIMU:
		pCharaPortrait = &Spr_FullPortrait_Reimu;
		pCharaDescription = &Spr_UI_CharaSelect_Description_Reimu;
		break;
	case PLAYERCHARA_MARISA:
		pCharaPortrait = &Spr_FullPortrait_Marisa;
		pCharaDescription = &Spr_UI_CharaSelect_Description_Marisa;
		break;
	case PLAYERCHARA_REISEN:
		pCharaPortrait = &Spr_FullPortrait_Reisen;
		pCharaDescription = &Spr_UI_CharaSelect_Description_Reisen;
	}


	int iCharaSelect_Portrait_X = UI_CHARASELECT_PORTRAIT_X - pCharaPortrait->GetWidth() + 
		(int)(  (double)(pCharaPortrait->GetWidth()) *
		(double) (iCharaSelect_Portrait_CurrentTime) / (double)(UI_CHARASELECT_PORTRAIT_SHOWANIMATION_DURATION) );
	int iCharaSelect_Portrait_Y = UI_CHARASELECT_PORTRAIT_Y;

	int iDescription_Portrait_X = UI_CHARASELECT_DESCRIPTION_X;
	int iDescription_Portrait_Y  = UI_CHARASELECT_DESCRIPTION_Y + pCharaDescription->GetHeight() -
		(int)(  (double)(pCharaDescription->GetHeight()) *
		(double) (iCharaSelect_Description_CurrentTime) / (double)(UI_CHARASELECT_DESCRIPTION_SHOWANIMATION_DURATION) );


	Spr_UI_CharaSelect_Title.DrawSprite(UI_CHARASELECT_TITLE_X, UI_CHARASELECT_TITLE_Y, 0);
	
	pCharaPortrait->DrawSprite(iCharaSelect_Portrait_X, iCharaSelect_Portrait_Y, 0);

	pCharaDescription->DrawSprite(iDescription_Portrait_X, iDescription_Portrait_Y, 0);



	if (iCharaSelect_Portrait_CurrentTime <= UI_CHARASELECT_PORTRAIT_SHOWANIMATION_DURATION)
	{
		iCharaSelect_Portrait_CurrentTime++;
	}
	if (iCharaSelect_Description_CurrentTime <= UI_CHARASELECT_DESCRIPTION_SHOWANIMATION_DURATION)
	{
		iCharaSelect_Description_CurrentTime++;
	}
}

// 선택 시
