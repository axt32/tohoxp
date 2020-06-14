#include "GamePlayer.h"
GamePlayer ::GamePlayer() : GameObject(TYPE_PLAYER)
{
	InitPlayer();
}

GamePlayer :: GamePlayer(ShooterSprite * IN_Sprite) : GameObject ( TYPE_PLAYER, IN_Sprite, false, true)
{
	InitPlayer();
}

void GamePlayer :: InitPlayer()
{
	iPlayerCharaType = PLAYERCHARA_REIMU;

	pLeftSprite = NULL;
	pRightSprite = NULL;

	x = 0.0;
	y = 0.0;
	life = 0;
	bomber = 0;
	iScore = 0;
	iGrazeCount = 0;

	iPlayerShotCoolTime = DEFAULT_PLAYER_SHOT_COOLTIME;
	iPlayerShotQuantity = DEFAULT_PLAYER_SHOT_QUANTITY;
	iPlayerShotSubCoolTime = DEFAULT_PLAYER_SHOT_SUBCOOLTIME;

	iShotCurrentWaitTime = iPlayerShotCoolTime - 1;
	iShotCurrentWaitSubTime = iPlayerShotQuantity - 1;
	bCoupleShot = false;
	iCurrentPower = 0;
	iCurrentShieldTime = 0;
	iCurrentStatus = PLAYERSTATUS_NONE;
	bShield = false;

	iGravity = 0;
	iOldGravity = 0;
	iCurrentGravityFrameTime = 0;

	bNowShooting = false;
	iShotCount = 0;

	ClearPlayerShot();

	pPlayerHeatBox = NULL;

	pPlayerBomberInit = NULL;
	pPlayerBomber = NULL;

	for (int i = 0; i < 10; i++)
	{
		iBomberParameters[i] = 0;
	}

	iCurrentBomberPortraitTime = 0;

	bNowBomberPortrait = false;

	pBomberPortrait = NULL;

	fConstNormalSpeed = 0.0;
	fConstSlowSpeed = 0.0;

	iSmallScoreItemCount = 0;
	iBigScoreItemCount = 0;
	bNoMiss = true;

}

bool GamePlayer :: SetSprite(ShooterSprite * IN_FrontSprite, ShooterSprite * IN_LeftSprite, ShooterSprite * IN_RightSprite)
{
	if (IN_FrontSprite == NULL || IN_LeftSprite == NULL || IN_RightSprite == NULL)
	{
		return false;
	}

	pFrontSprite = IN_FrontSprite;
	pLeftSprite = IN_LeftSprite;
	pRightSprite = IN_RightSprite;

	GameObject::SetSprite(pFrontSprite, PLAYER_FRONT_FRAMECHANGE_INTERVAL);

	return true;
}

void GamePlayer :: ClearPlayerShot()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pPlayerShot[i][j] = NULL;
		}
	}
}

void GamePlayer :: SetPlayerShot(int IN_No, int IN_Power, GamePlayerShot * IN_PlayerShot)
{
	pPlayerShot[IN_No][IN_Power] = IN_PlayerShot;
}

void GamePlayer :: SetPlayerHeatBox(GamePlayerHeatBox * IN_GamePlayerHeatBox)
{
	pPlayerHeatBox = IN_GamePlayerHeatBox;
}

bool GamePlayer :: SetPower(int IN_Power)
{
	if (IN_Power <= iCurrentPower && pPlayerShot[IN_Power] != NULL)
	{
		iCurrentPower = IN_Power;
		return true;
	}

	return false;
}

void GamePlayer :: ChangeState(PlayerStatus IN_PlayerStatus)
{
	iCurrentStatus = IN_PlayerStatus;

	switch (iCurrentStatus)
	{
	case PLAYERSTATUS_NONE:
		GetSprite()->SetAlpha(SDL_ALPHA_OPAQUE);
		break;
	case PLAYERSTATUS_SHIELD:
		iCurrentShieldTime = 0;
		bShield = false;
		break;

	case PLAYERSTATUS_EXPLOSION:
		break;
	}
}

GamePlayerShot * GamePlayer :: GetPlayerShot(int IN_No)
{
	return pPlayerShot[IN_No][iCurrentPower];
}

bool GamePlayer :: Draw(bool IN_AutoNextFrame)
{
	if ( iGravity == 0)
	{
		if (iOldGravity != 0)
		{
			GameObject::SetSprite(pFrontSprite, PLAYER_FRONT_FRAMECHANGE_INTERVAL);
		}
		return GameObject::Draw(IN_AutoNextFrame);
	}
	else if (iGravity < 0)
	{
		if (iOldGravity >= 0)
		{
			GameObject::SetSprite(pLeftSprite);
		}
		
		int iNewFrame = abs(iGravity) - 1;

		if (iNewFrame >= pLeftSprite->GetMaxFrame())
		{
			iNewFrame = pLeftSprite->GetMaxFrame() - 1;
		}

		iCurrentFrame = iNewFrame;
		return GameObject::Draw(false);
	}
	else
	{
		if (iOldGravity <= 0)
		{
			GameObject::SetSprite(pRightSprite);
		}
		int iNewFrame = iGravity;

		if (iNewFrame >= pRightSprite->GetMaxFrame())
		{
			iNewFrame = pRightSprite->GetMaxFrame() - 1;
		}

		iCurrentFrame = iNewFrame;

		return GameObject::Draw(false);
	}

	return false;
}

bool GamePlayer :: SetAlphaAll(Uint8 IN_Alpha)
{
	if (pFrontSprite == NULL || pLeftSprite == NULL || pRightSprite == NULL)
	{
		return false;
	}

	return (pFrontSprite->SetAlpha(IN_Alpha) & pLeftSprite->SetAlpha(IN_Alpha) & pRightSprite->SetAlpha(IN_Alpha));
}

void GamePlayer :: InitGravity()
{
	iOldGravity = 0;
	iGravity = 0;
	GameObject::SetSprite(pFrontSprite, PLAYER_FRONT_FRAMECHANGE_INTERVAL);
}