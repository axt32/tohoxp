#include "Bomber_Reisen.h"

void Bomber_Reisen_Init(GamePlayer *IN_GamePlayer, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{
	int * iFrameCount = &(IN_GamePlayer->iBomberParameters[0]);
	int * iDesiredFrameCount = &(IN_GamePlayer->iBomberParameters[1]);
	int * iCurrentShotCount = &(IN_GamePlayer->iBomberParameters[2]);
	int * iMaxShotCount = &(IN_GamePlayer->iBomberParameters[3]);
	
	*iFrameCount = IN_iParam0;
	*iDesiredFrameCount = IN_iParam1;
	*iCurrentShotCount = 0;
	*iMaxShotCount = IN_iParam2;

}

void Bomber_Reisen	(GamePlayer * IN_GamePlayer)
{
	int * iFrameCount = &(IN_GamePlayer->iBomberParameters[0]);
	int * iDesiredFrameCount = &(IN_GamePlayer->iBomberParameters[1]);
	int * iCurrentShotCount = &(IN_GamePlayer->iBomberParameters[2]);
	int * iMaxShotCount = &(IN_GamePlayer->iBomberParameters[3]);

	if ( *iFrameCount >= *iDesiredFrameCount)
	{

		//TODO
		AddPlayerShot(&PlayerShot_Reisen_Bomber, -10.0, -5.0, 90.0);
		AddPlayerShot(&PlayerShot_Reisen_Bomber, -5.0, -25.0, 90.0);
		AddPlayerShot(&PlayerShot_Reisen_Bomber, 0.0, -45.0, 90.0);
		AddPlayerShot(&PlayerShot_Reisen_Bomber, 5.0, -25.0, 90.0);
		AddPlayerShot(&PlayerShot_Reisen_Bomber, 10.0, -5.0, 90.0);

		*iFrameCount = 0;
		
		if ( *iCurrentShotCount >= *iMaxShotCount)
		{
			IN_GamePlayer->bNowBomber = false;
			return;
		}
		else
		{
			(*iCurrentShotCount)++;
		}
	}
	else
	{
		(*iFrameCount)++;
	}

}