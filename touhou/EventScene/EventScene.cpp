#include "EventScene.h"

std::vector <Chara*> CharaVector;
std::vector <Script*> ScriptVector;

std::vector<Script*>::iterator ScriptIter;
Chara * pCurrentChara0;
Chara* pCurrentChara1;

ShooterSprite PrintedCharaName;
ShooterSprite PrintedTextLine0;
ShooterSprite PrintedTextLine1;

int iColor_Event_CharaName_R = 0;
int iColor_Event_CharaName_G = 0;
int iColor_Event_CharaName_B = 0;

void RegisterChara(std::string IN_Name, int IN_ImageQuantity, ShooterSprite * IN_Image)
{
	Chara * pChara = new Chara;
	pChara->Name = IN_Name;	
	pChara->Images.push_back(IN_Image);

	CharaVector.push_back(pChara);

}
void DeleteAllChara()
{
	if (CharaVector.size() > 0)
	{
		for ( std::vector<Chara *>::iterator Iter = CharaVector.begin(); Iter != CharaVector.end(); Iter++)
		{
			delete (*Iter);
		}

		CharaVector.clear();
	}

}

void AddScript(std::string IN_Chara0, int IN_Chara0_ImageNum, std::string IN_Chara1, int IN_Chara1_ImageNum, int IN_CurrentChara, std::string IN_Speech)
{
	Script* pScript = new Script;
	pScript->Chara0_Name = IN_Chara0;
	pScript->Chara0_ImageNum = IN_Chara0_ImageNum;
	pScript->Chara1_Name = IN_Chara1;
	pScript->Chara1_ImageNum = IN_Chara1_ImageNum;
	pScript->CurrentChara = IN_CurrentChara;
	pScript->Speech = IN_Speech;

	ScriptVector.push_back(pScript);
}

void DeleteAllScripts()
{
	if (ScriptVector.size() > 0)
	{
		for ( std::vector<Script *>::iterator Iter = ScriptVector.begin(); Iter != ScriptVector.end(); Iter++)
		{
			delete (*Iter);
		}

		ScriptVector.clear();	
	}
}

void StartScript()
{
	ScriptIter = ScriptVector.begin();
	PrintScript();
}

bool NextScript()
{
	ScriptIter++;
	if (ScriptIter == ScriptVector.end())
	{
		return false;
	}
	
	PrintScript();
	return true;

}

void PrintScript()
{
	std::vector<Chara*>::iterator Found_Iter;
	std::string CurrentCharaName;

	auto FindChara = [&] (std::string IN_Name)
	{
		if (CharaVector.size() > 0)
		{
			for (std::vector<Chara*>::iterator Iter = CharaVector.begin(); Iter != CharaVector.end(); Iter++)
			{
				if ( IN_Name == (*Iter)->Name)
				{
					Found_Iter = Iter;
				}
			}
		}
	};

	if ((*ScriptIter)->CurrentChara == 0)
	{
		if ( (*ScriptIter)->Chara0_Name == "")
		{
			pCurrentChara0 = NULL;
		}
		else
		{
			FindChara((*ScriptIter)->Chara0_Name);
			if (((*Found_Iter)->Images[(*ScriptIter)->Chara0_ImageNum]) != NULL)
			{
				((*Found_Iter)->Images[(*ScriptIter)->Chara0_ImageNum])->SetAlpha(SDL_ALPHA_OPAQUE);
			}
			pCurrentChara0 = (*Found_Iter);
			CurrentCharaName = (*Found_Iter)->Name;
		}

		if ( (*ScriptIter)->Chara1_Name == "")
		{
			pCurrentChara1 = NULL;
		}
		else
		{
			FindChara((*ScriptIter)->Chara1_Name);
			if (((*Found_Iter)->Images[(*ScriptIter)->Chara1_ImageNum]) != NULL)
			{
				((*Found_Iter)->Images[(*ScriptIter)->Chara1_ImageNum])->SetAlpha(150);
			}
			pCurrentChara1 = (*Found_Iter);
		}
	}
	else if ((*ScriptIter)->CurrentChara == 1)
	{
		if ( (*ScriptIter)->Chara0_Name == "")
		{
			pCurrentChara0 = NULL;
		}
		else
		{
			FindChara((*ScriptIter)->Chara0_Name);
			if ( ((*Found_Iter)->Images[(*ScriptIter)->Chara0_ImageNum]) != NULL)
			{
				((*Found_Iter)->Images[(*ScriptIter)->Chara0_ImageNum])->SetAlpha(150);
			}
			pCurrentChara0 = (*Found_Iter);
		}

		if ( (*ScriptIter)->Chara1_Name == "")
		{
			pCurrentChara1 = NULL;
		}
		else
		{
			FindChara((*ScriptIter)->Chara1_Name);
			if ( ((*Found_Iter)->Images[(*ScriptIter)->Chara1_ImageNum]) != NULL)
			{
				((*Found_Iter)->Images[(*ScriptIter)->Chara1_ImageNum])->SetAlpha(SDL_ALPHA_OPAQUE);
			}
			pCurrentChara1 = (*Found_Iter);
			CurrentCharaName = (*Found_Iter)->Name;
		}
	}
	else		//두명다 떠들때
	{
		FindChara((*ScriptIter)->Chara0_Name);
		if (((*Found_Iter)->Images[(*ScriptIter)->Chara0_ImageNum]) != NULL)
		{
			((*Found_Iter)->Images[(*ScriptIter)->Chara0_ImageNum])->SetAlpha(SDL_ALPHA_OPAQUE);
		}
		pCurrentChara0 = (*Found_Iter);
		CurrentCharaName = (*Found_Iter)->Name;

		FindChara((*ScriptIter)->Chara1_Name);
		if ( ((*Found_Iter)->Images[(*ScriptIter)->Chara1_ImageNum]) != NULL)
		{
			((*Found_Iter)->Images[(*ScriptIter)->Chara1_ImageNum])->SetAlpha(SDL_ALPHA_OPAQUE);
		}
		pCurrentChara1 = (*Found_Iter);
		CurrentCharaName += ", ";
		CurrentCharaName += (*Found_Iter)->Name;
	}

	//스크립트창에 맞춰서 출력
	bool bSuccess = false;
	bool bOnceAttempt = true;
	int iLength = 	(*ScriptIter)->Speech.length();

	while (bSuccess == false)
	{
		std::string TempText;
		TempText += (*ScriptIter)->Speech.substr(0, iLength);
		GameNormalSizeFont.PrintFont(&PrintedTextLine0, TempText, 0, 0, 0, FONT_BLENDED);
		
		if (PrintedTextLine0.GetWidth() > GAME_UI_SCRIPTBOX_WIDTH - 10)
		{

			if ( (*ScriptIter)->Speech[iLength - 1] < 0)
			{
				iLength = iLength - 2;
			}
			else
			{
				iLength--;
			}
			bOnceAttempt = false;

			if (iLength - 1 == 0)
			{
				break;
			}
		}
		else
		{
			bSuccess = true;
		}
	}

	if (bOnceAttempt == false)
	{
		std::string TempText;
		if ( !(iLength == 0) )
		{
			TempText = (*ScriptIter)->Speech.substr(iLength, (*ScriptIter)->Speech.length() - iLength);
			GameNormalSizeFont.PrintFont(&PrintedTextLine1, TempText, 0, 0, 0, FONT_BLENDED);
		}

	}
	else		//첫번째 줄(0번 줄)만 출력되고 두번째 줄(1번 줄)이 출력이 안되면 두번째 줄은 이전의 데이터가 남아있을 수 있으므로 지워준다.
	{
		PrintedTextLine1.FreeSurface();
	}

	if (CurrentCharaName != "")
	{
		GameNormalSizeFont.PrintFont(&PrintedCharaName, CurrentCharaName, iColor_Event_CharaName_R, iColor_Event_CharaName_G, iColor_Event_CharaName_B, FONT_BLENDED);
	}
	else
	{
		PrintedCharaName.FreeSprite();
	}

}

void DrawScript()
{

	double fAddX0 = 0.0;
	double fAddX1 = 0.0;

	if ( (*ScriptIter)->CurrentChara == 0)
	{
		fAddX0 = 10.0;
	}
	else if ( (*ScriptIter)->CurrentChara == 1)
	{
		fAddX1 = -10.0;
	}
	else	//두명 다 떠들때
	{
		fAddX0 = 10.0;
		fAddX1 = -10.0;
	}

	if (pCurrentChara0 != NULL)
	{
		if ( pCurrentChara0->Images[ (*ScriptIter)->Chara0_ImageNum] != NULL)
		{
			pCurrentChara0->Images[ (*ScriptIter)->Chara0_ImageNum]->DrawSprite(GAME_UI_SCRIPTBOX_X - 16.0 + fAddX0, GAME_UI_SCRIPTBOX_Y + GAME_UI_SCRIPTBOX_HEIGHT + 50.0 - pCurrentChara0->Images[ (*ScriptIter)->Chara0_ImageNum]->GetHeight(), 0);
		}
	}
	if (pCurrentChara1 != NULL)
	{
		if ( pCurrentChara1->Images[ (*ScriptIter)->Chara1_ImageNum] != NULL)
		{
			pCurrentChara1->Images[ (*ScriptIter)->Chara1_ImageNum]->DrawSprite(GAME_UI_SCRIPTBOX_X + GAME_UI_SCRIPTBOX_WIDTH- pCurrentChara1->Images[ (*ScriptIter)->Chara1_ImageNum]->GetWidth() + 16.0 + fAddX1, GAME_UI_SCRIPTBOX_Y + GAME_UI_SCRIPTBOX_HEIGHT + 50.0 - pCurrentChara1->Images[ (*ScriptIter)->Chara1_ImageNum]->GetHeight(), 0);
		}
	}

	Spr_ScriptBox.DrawSprite(GAME_UI_SCRIPTBOX_X, GAME_UI_SCRIPTBOX_Y, 0);
	
	PrintedCharaName.DrawSprite(GAME_UI_SCRIPTBOX_X + 10, GAME_UI_SCRIPTBOX_Y - 5 - PrintedCharaName.GetHeight(), 0);
	
	PrintedTextLine0.DrawSprite(GAME_UI_SCRIPTBOX_X + 5, GAME_UI_SCRIPTBOX_Y + 2, 0);
	//내부에서 로드되지 않았을 경우 false 반환.
	PrintedTextLine1.DrawSprite(GAME_UI_SCRIPTBOX_X + 5, GAME_UI_SCRIPTBOX_Y + 2 + GameNormalSizeFont.GetFontSize(), 0);
}