#include "PlayerShot_Marisa.h"

void PlayerShot_Marisa_Bomber_Init(GamePlayerShot * IN_GamePlayerShot, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{
	int * iFarY = &(IN_GamePlayerShot->iPlayerShotParameters[0]);
	int * iOldFrame = &(IN_GamePlayerShot->iPlayerShotParameters[1]);
	int * iAlphaAddOrSub = &(IN_GamePlayerShot->iPlayerShotParameters[2]);
	int * iCurrentAlphaTime = &(IN_GamePlayerShot->iPlayerShotParameters[3]);
	int * iAlphaDestTime= &(IN_GamePlayerShot->iPlayerShotParameters[4]); 
	int * iCurrentLoopCount = &(IN_GamePlayerShot->iPlayerShotParameters[5]);
	int * iDesiredLoopCount = &(IN_GamePlayerShot->iPlayerShotParameters[6]);

	*iFarY = IN_iParam0;
	*iOldFrame = 0;
	IN_GamePlayerShot->iDamageToBoss = IN_iParam1;
	*iAlphaAddOrSub = 0;	//0 : add, 1 : sub
	*iCurrentAlphaTime = 0;
	*iAlphaDestTime = 30;

	*iCurrentLoopCount = 0;
	*iDesiredLoopCount = 10;

}

void PlayerShot_Marisa_Bomber_Func(GamePlayerShot * IN_GamePlayerShot)
{
	int * iFarY = &(IN_GamePlayerShot->iPlayerShotParameters[0]);
	int * iOldFrame = &(IN_GamePlayerShot->iPlayerShotParameters[1]);
	int * iAlphaAddOrSub = &(IN_GamePlayerShot->iPlayerShotParameters[2]);
	int * iCurrentAlphaTime = &(IN_GamePlayerShot->iPlayerShotParameters[3]);
	int * iAlphaDestTime= &(IN_GamePlayerShot->iPlayerShotParameters[4]); 
	int * iCurrentLoopCount = &(IN_GamePlayerShot->iPlayerShotParameters[5]);
	int * iDesiredLoopCount = &(IN_GamePlayerShot->iPlayerShotParameters[6]);

	double fFarY = (double)(*iFarY) / 10.0;
	IN_GamePlayerShot->x = Player.GetCenterX() - (IN_GamePlayerShot->GetSprite()->GetWidth()) / 2.0;
	IN_GamePlayerShot->y = fFarY + Player.y - ( IN_GamePlayerShot->GetSprite()->GetHeight() );

	bool bAlphaSub = false;

	if ( *iAlphaAddOrSub == 0)
	{
		IN_GamePlayerShot->GetSprite()->SetAlpha( (double)(*iCurrentAlphaTime) / (double)(*iAlphaDestTime ) * (double)SDL_ALPHA_OPAQUE );
	}
	else
	{
		if ( ( (IN_GamePlayerShot->GetSprite()->GetMaxFrame()) * (*iDesiredLoopCount - *iCurrentLoopCount) - IN_GamePlayerShot->iCurrentFrame)
			* (IN_GamePlayerShot->iFrameChangeInterval) + IN_GamePlayerShot->iCurrentFrameTime <= *iAlphaDestTime)
		{
			bAlphaSub = true;
			IN_GamePlayerShot->GetSprite()->SetAlpha( SDL_ALPHA_OPAQUE - (double)(*iCurrentAlphaTime) / (double)(*iAlphaDestTime ) * (double)SDL_ALPHA_OPAQUE );
		}

	}

	if ( *iCurrentAlphaTime <= *iAlphaDestTime)
	{
		if (*iAlphaAddOrSub == 0 || (*iAlphaAddOrSub == 1 && bAlphaSub == true))
		{
			(*iCurrentAlphaTime)++;
		}
	}

	if ( *iCurrentAlphaTime > *iAlphaDestTime )
	{
		*iCurrentAlphaTime = 0;

		if ( *iAlphaAddOrSub == 0)
		{
			*iAlphaAddOrSub = 1;
		}
	}

	if (IN_GamePlayerShot->iCurrentFrame == 0)
	{
		if ( *iOldFrame == IN_GamePlayerShot->GetSprite()->GetMaxFrame() - 1)
		{
			(*iCurrentLoopCount)++;
			if (*iCurrentLoopCount >= *iDesiredLoopCount)
			{
				IN_GamePlayerShot->bSuicide = true;
				return;
			}
		}
	}

	*iOldFrame = IN_GamePlayerShot->iCurrentFrame;

}