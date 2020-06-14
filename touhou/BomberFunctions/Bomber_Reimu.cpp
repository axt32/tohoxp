#include "Bomber_Reimu.h"

void Bomber_Reimu_Init(GamePlayer *IN_GamePlayer, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{
	int * iShotCount = &(IN_GamePlayer->iBomberParameters[0]);
	int * iShotDesiredCount = &(IN_GamePlayer->iBomberParameters[1]);
	int * iAngleVelocity = &(IN_GamePlayer->iBomberParameters[2]);
	int * iFrameCount = &(IN_GamePlayer->iBomberParameters[3]);
	int * iDesiredFrameCount = &(IN_GamePlayer->iBomberParameters[4]);
	int * iBulletMoveDesiredFrameCount = &(IN_GamePlayer->iBomberParameters[5]);
	int * iMaxRadius = &(IN_GamePlayer->iBomberParameters[6]);
	int * iReverse = &(IN_GamePlayer->iBomberParameters[7]);
	int * iDone = &(IN_GamePlayer->iBomberParameters[8]);

	*iShotDesiredCount = IN_iParam0;
	*iShotCount = 0;
	*iAngleVelocity = IN_iParam1;		//X10
	*iDesiredFrameCount = IN_iParam2;	
	*iFrameCount = *iDesiredFrameCount;
	*iBulletMoveDesiredFrameCount = IN_iParam3;
	*iMaxRadius = IN_iParam4;
	*iReverse = 0;
	*iDone = 0;

}

void Bomber_Reimu	(GamePlayer * IN_GamePlayer)
{
	int * iShotCount = &(IN_GamePlayer->iBomberParameters[0]);
	int * iShotDesiredCount = &(IN_GamePlayer->iBomberParameters[1]);
	int * iAngleVelocity = &(IN_GamePlayer->iBomberParameters[2]);
	int * iFrameCount = &(IN_GamePlayer->iBomberParameters[3]);
	int * iDesiredFrameCount = &(IN_GamePlayer->iBomberParameters[4]);
	int * iBulletMoveDesiredFrameCount = &(IN_GamePlayer->iBomberParameters[5]);
	int * iMaxRadius = &(IN_GamePlayer->iBomberParameters[6]);
	int * iReverse = &(IN_GamePlayer->iBomberParameters[7]);
	int * iDone = &(IN_GamePlayer->iBomberParameters[8]);

	if (*iDone == 0)
	{
		if (*iFrameCount >= *iDesiredFrameCount - 1)
		{
			int iMultiply = 1;
			if (*iReverse == 1)
			{
				iMultiply = -1;
			}

			int iModifiedAngleVelocity = *iAngleVelocity * (iMultiply);
			int iQuantity = 10;
			for (int i = 0; i < iQuantity; i++)
			{
				int iAngle = (int)((double)i * (360.0 / (double)iQuantity)) * 10.0 * iMultiply;
				AddPlayerShot(&PlayerShot_Reimu_Bomber, 0.0, 0.0, 0.0, iModifiedAngleVelocity, iAngle, *iBulletMoveDesiredFrameCount, *iMaxRadius, i, false);
				//마이크로 스레드 함수 내에서 자체적으로 x, y값을 조작할 경우, bMovable을 false로 해두어
				//ProcessPos함수에서 한번, 마이크로스레드에서 한번, 좌표 연산이 중복되지 않게 해야한다.
				(*(GamePlayerShotVector.end() - 1))->bMovable = false;
				
			}

			if (*iReverse == 0)
			{
				*iReverse = 1;
			}
			else
			{
				*iReverse = 0;
			}

			(*iShotCount)++;

			if (*iShotCount >= *iShotDesiredCount)
			{
				*iDone = 1;
			}
			else
			{
				*iFrameCount = 0;
			}

		}
		else
		{
			(*iFrameCount)++;
		}
	}
	else
	{
		std::vector<GamePlayerShot *>::iterator Iter = GamePlayerShotVector.begin();

		bool bBomberFound = false;
		if (GamePlayerShotVector.size() > 0)
		{
			while ( true )
			{
				if ( Iter == GamePlayerShotVector.end())
				{
					break;
				}

				if ( (*Iter)->iPlayerShotType == PLAYERSHOT_TYPE_REIMU_BOMBER)
				{
					bBomberFound = true;
					break;
				}

				Iter++;

			}
		}

		if (bBomberFound == false)
		{
			IN_GamePlayer->bNowBomber = false;
			return;
		}
	}
}