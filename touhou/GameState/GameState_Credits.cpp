#include "GameState_Credits.h"


int iCurrentGameCreditItem = 0;

int iCurrentGameCreditLastItemRemainTime = 0;

std::vector<GameObject *> vGameCreditItems;

std::vector<ShooterSprite * > vSpr_GameCreditItems;

void InitGameCredits()
{
	Spr_UI_NowLoading.DrawSprite(UI_NOWLOADING_X, UI_NOWLOADING_Y, 0);
	GameScreen.Flip();

	if (vGameCreditItems.size() == 0)
	{
		for (int i = 0; i < CREDIT_MAX_ITEMS; i++)
		{
			ShooterSprite * pSprite = new ShooterSprite();

			char num_char[4];
			_itoa(i, num_char, 10);
			std::string sPath = "spr/credits/credits_";
			sPath += num_char;
			sPath += ".png";
			pSprite->LoadSprite ("data.rom", sPath, &GameScreen);
			vSpr_GameCreditItems.push_back(pSprite);
		}
	}

	iCurrentGameCreditItem = 0;
	iCurrentGameCreditLastItemRemainTime = 0;
	MakeCreditItem();

	iGameState = GAMECREDITS;
	StopMusicAllinOne();
	FreeMusicAllInOne();
	if (bBGM_Use == true)
	{
		Music_Credits.LoadSound("data.rom", "music/credits.ogg", &MySoundManager);
		Music_Credits.Play(true, NULL, fVolume_BGM);
	}
}

void MakeCreditItem()
{
	GameObject * pGameObject = new GameObject();
	pGameObject->SetSprite( vSpr_GameCreditItems[iCurrentGameCreditItem]);
	pGameObject->x = (double)GAMEWIDTH / 2.0 - ((double)(pGameObject->GetSprite()->GetWidth()) / 2.0);
	pGameObject->y = UI_WINDOW_BOTTOM_Y + UI_WINDOW_BOTTOM_HEIGHT;
	pGameObject->SetAngle(90.0);
	pGameObject->speed = CREDIT_ITEMS_SPEED;

	vGameCreditItems.push_back(pGameObject);

}

void Input_GameCredits()
{
	if (GameInput.GetInput(QUIT))
	{
		//'QUIT' 명령시 ->  강제종료.
		Music_Credits.Stop();
		FreeMusicAllInOne();
		UnloadGameCredits();
		bRunning = false;
		return;
	}

	if ( (GameInput.GetInput(iKey_Attack) && GameInput.GetPreviousInput(iKey_Attack) == false)
		|| (GameInput.GetInput(iKey_Bomber) && GameInput.GetPreviousInput(iKey_Bomber) == false)
		|| (GameInput.GetInput(KEY_RETURN) && GameInput.GetPreviousInput(KEY_RETURN) == false)
		|| (GameInput.GetInput(KEY_ESCAPE)) && GameInput.GetPreviousInput(KEY_ESCAPE) == false)
	{
		ExitGameCredits();
	}


}

void Draw_GameCredits()
{
	Spr_Credits_Background.DrawSprite(0, 0, 0);

	if (vGameCreditItems.size() > 0)
	{
		std::vector<GameObject *>::iterator Iter = vGameCreditItems.begin();
		while ( true )
		{
			if (Iter == vGameCreditItems.end())
			{
				break;
			}

			(*Iter)->Draw();

			if (Iter == vGameCreditItems.end() - 1)
			{
				if ( (*Iter)->y + (*Iter)->GetSprite()->GetHeight() <= UI_WINDOW_BOTTOM_Y - CREDIT_ITEMS_SPAN )
				{
					if (iCurrentGameCreditItem < CREDIT_MAX_ITEMS - 1)
					{
						iCurrentGameCreditItem++;
						MakeCreditItem();
						break;
					}
				}
			}

			if ( Iter == vGameCreditItems.end() - 1 && iCurrentGameCreditItem == CREDIT_MAX_ITEMS - 1
			&& (*Iter)->y <= ((double)(GAMEHEIGHT) / 2.0) - (double)((*Iter)->GetSprite()->GetHeight()) / 2.0)
			{
				if (iCurrentGameCreditLastItemRemainTime >= CREDIT_ITEMS_LAST_ITEM_REMAIN_TIME - 1)
				{
					ExitGameCredits();
					break;
				}
				else
				{
					iCurrentGameCreditLastItemRemainTime++;
				}
			}
			else
			{
				(*Iter)->y = (*Iter)->y - ((*Iter)->speed);
			}

			if ( (*Iter)->y < (*Iter)->y - (*Iter)->GetSprite()->GetHeight())
			{
				DeleteObject(*Iter);
				Iter = vGameCreditItems.erase(Iter);
			}
			else
			{
				Iter++;
			}
		}

	}

}

void ExitGameCredits()
{
	Music_Credits.Stop();
	FreeMusicAllInOne();
	UnloadGameCredits();
	Init_ScoreBoard_State(true);
}

void UnloadGameCredits()
{
	if (vGameCreditItems.size() > 0)
	{	
		std::vector<GameObject *>::iterator Iter = vGameCreditItems.begin();
		while ( true )
		{
			if (Iter == vGameCreditItems.end())
			{
				break;
			}

			DeleteObject(*Iter);

			Iter++;
		}

		vGameCreditItems.clear();
	}

}

void UnloadGameCreditsSprite()
{
	if (vSpr_GameCreditItems.size() > 0)
	{
		std::vector<ShooterSprite *>::iterator Iter = vSpr_GameCreditItems.begin();
	
		while ( true )
		{
			if (Iter == vSpr_GameCreditItems.end())
			{
				break;
			}
	
			delete (*Iter);
			Iter++;
		}
	
		vSpr_GameCreditItems.clear();
	}
}