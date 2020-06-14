#include "PlayerShot_Reimu.h"

void PlayerShot_Reimu_Sub_Init(GamePlayerShot * IN_GamePlayerShot, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{
	int * iInited = &(IN_GamePlayerShot->iPlayerShotParameters[0]);
	int * iPermitDuplication = &(IN_GamePlayerShot->iPlayerShotParameters[1]);
	int * iSensingAngle = &(IN_GamePlayerShot->iPlayerShotParameters[2]);
	int * iHasDest = &(IN_GamePlayerShot->iPlayerShotParameters[3]);

	double fAngle = (double)IN_iParam0 / 10.0;
	int iMinMove = IN_iParam1;
	IN_GamePlayerShot->bPermitOutside = false;

	*iInited = 0;
	*iPermitDuplication = IN_iParam2;
	*iSensingAngle = IN_iParam3;		//X10

	*iHasDest = IN_iParam4;

	if ( *iHasDest == 1)
	{
		IN_GamePlayerShot->bGoTo = true;
		IN_GamePlayerShot->fDest_X = IN_GamePlayerShot->x + GetXbyCos(GetRadian(fAngle), iMinMove);
		IN_GamePlayerShot->fDest_Y = IN_GamePlayerShot->y + GetYbySin(GetRadian(fAngle), iMinMove);
		IN_GamePlayerShot->SetAngle( GetAngle(IN_GamePlayerShot->x, IN_GamePlayerShot->y, IN_GamePlayerShot->fDest_X, IN_GamePlayerShot->fDest_Y));

	}
	else if ( *iHasDest == 0)
	{
		IN_GamePlayerShot->bGoTo = false;
	}
}

void PlayerShot_Reimu_Sub (GamePlayerShot * IN_GamePlayerShot)
{
	int * iInited = &(IN_GamePlayerShot->iPlayerShotParameters[0]);
	int * iPermitDuplication = &(IN_GamePlayerShot->iPlayerShotParameters[1]);
	int * iSensingAngle = &(IN_GamePlayerShot->iPlayerShotParameters[2]);
	int * iHasDest = &(IN_GamePlayerShot->iPlayerShotParameters[3]);

	auto Homing = [&] ()
	{
		IN_GamePlayerShot->SetAngle(GetAngle(IN_GamePlayerShot->x, IN_GamePlayerShot->y,
												(*(IN_GamePlayerShot->HomingTargetIter))->Target_X, (*(IN_GamePlayerShot->HomingTargetIter))->Target_Y));
	};

	double fMinDist = 9999.0;
	GameEnemy * pEnemyOfMinDist = NULL;

	auto Check = [&] (GameEnemy * IN_Enemy)
	{
		double fSensingAngle = (double)(*iSensingAngle) / 10.0;

		//레이무 호밍샷이 너무 사기가 되는것을 방지하기 위해, 플레이어샷 자신보다 위에 있는 물체이면서, 일정 각도 안에 들어가는 적군에 대해서만 유도를 하도록 했다.
		//(단, 전멸폭탄은 자신보다 위에 있는 물체라는 조건을 제외함)
		if ( OutsideCheck(IN_Enemy) == false 
			&& (IN_GamePlayerShot->iPlayerShotType == PLAYERSHOT_TYPE_REIMU_BOMBER || IN_Enemy->y < IN_GamePlayerShot->y)
			&& abs(IN_GamePlayerShot->GetAngle() - GetAngle(IN_GamePlayerShot, IN_Enemy)) <= fSensingAngle)
		{
			if ( (IN_Enemy != NULL && IN_Enemy == pBoss) || 
				*iPermitDuplication == 1 || IN_Enemy->bUsingHomingTargetIter == false)
			{
				double fDist = GetDistance(IN_GamePlayerShot, IN_Enemy);
				if (fDist < fMinDist)
				{
					fMinDist = fDist;
					pEnemyOfMinDist = IN_Enemy;
				}
			}
		}
	};

	auto FindEnemy = [&]
	{
		if (*iHasDest == 0 || IN_GamePlayerShot->bGoTo == false)
		{
			fMinDist = 9999.0;
			pEnemyOfMinDist = NULL;
			if (*iHasDest == 1)
			{
				IN_GamePlayerShot->SetAngle(90.0);
			}

			//가장 가까운 곳을 향해 목적지를 정함

			if (pBoss != NULL)
			{
				if ( pBoss->SpellVector[pBoss->iCurrentSpell]->bInvincible == false )
				{
					Check(pBoss);
				}
			}
			else
			{
				if (GameEnemyVector.size() > 0)
				{
					std::vector<GameEnemy *>::iterator Iter = GameEnemyVector.begin();
					while ( true )
					{
						if (Iter == GameEnemyVector.end())
						{
							break;
						}

						Check( *Iter );

						Iter++;
					}
				}
			}

			if (pEnemyOfMinDist != NULL)
			{
				if (pEnemyOfMinDist->bUsingHomingTargetIter == false)
				{
					HomingTarget * pHomingTarget = 
// 						new HomingTarget(pEnemyOfMinDist->x + (double)(pEnemyOfMinDist->GetSprite()->GetWidth()) / 2.0,
// 						pEnemyOfMinDist->y + (double)(pEnemyOfMinDist->GetSprite()->GetHeight()) / 2.0);
 						new HomingTarget(pEnemyOfMinDist->x + 5.0, pEnemyOfMinDist->y + 5.0);


					vHomingTarget.push_back(pHomingTarget);
					IN_GamePlayerShot->HomingTargetIter = (--vHomingTarget.end());
					pEnemyOfMinDist->HomingTargetIter = (--vHomingTarget.end());

					IN_GamePlayerShot->bUsingHomingTargetIter = true;
					pEnemyOfMinDist->bUsingHomingTargetIter = true;

				}													
				else
				{
					IN_GamePlayerShot->HomingTargetIter = pEnemyOfMinDist->HomingTargetIter;
					( (*(IN_GamePlayerShot->HomingTargetIter))->iPlayerShotReferenceCount)++;
					IN_GamePlayerShot->bUsingHomingTargetIter = true;
				}
				Homing();
			}
			else
			{
				//				IN_GamePlayerShot->SetAngle(90.0);
			}

			IN_GamePlayerShot->bMovable = true;

			*iInited = 1;
		}
	};

	//유도 대상을 한번만 정하고, 바꾸지 않는다. (의도된 효과)
	if (*iInited == 0)
	{
		FindEnemy();
	}
	else
	{
		if ( IN_GamePlayerShot->bUsingHomingTargetIter == true)
		{
 			if ((*(IN_GamePlayerShot->HomingTargetIter))->bEnemyAlive == true)
			{
				Homing();
			}
			else
			{
				//레이무 폭탄일 경우, 없애야할 적군이 먼저 사라졌다면 재추적.
				((*(IN_GamePlayerShot->HomingTargetIter))->iPlayerShotReferenceCount)--;
				IN_GamePlayerShot->bUsingHomingTargetIter = false;
				CheckGarbageHomingTarget( & ((IN_GamePlayerShot)->HomingTargetIter) );

				FindEnemy();
			}
		}
		else
		{
			//레이무 폭탄의 경우, 이전에 적군을 못찾더라도 재추적
			if (IN_GamePlayerShot->iPlayerShotType == PLAYERSHOT_TYPE_REIMU_BOMBER)
			{
				FindEnemy();
			}
		}
	}

}

void PlayerShot_Reimu_Rapier_Init(GamePlayerShot * IN_GamePlayerShot, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{
	PlayerShot_Reimu_Sub_Init(IN_GamePlayerShot, IN_iParam0, IN_iParam1, IN_iParam2, IN_iParam3, IN_iParam4);
}
void PlayerShot_Reimu_Rapier_Func(GamePlayerShot * IN_GamePlayerShot)
{
	PlayerShot_Reimu_Sub(IN_GamePlayerShot);
}

void PlayerShot_Reimu_Bomber_Init(GamePlayerShot * IN_GamePlayerShot, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{
	int * iAngleVelocity = &(IN_GamePlayerShot->iPlayerShotParameters[0]);
	int * iCurrentAngle = &(IN_GamePlayerShot->iPlayerShotParameters[1]);
	int * iCurrentFrameCount = &(IN_GamePlayerShot->iPlayerShotParameters[2]);
	int * iDesiredFrameCount = &(IN_GamePlayerShot->iPlayerShotParameters[3]);
	int * iCurrentRadius = &(IN_GamePlayerShot->iPlayerShotParameters[4]);
	int * iMaxRadius = &(IN_GamePlayerShot->iPlayerShotParameters[5]);
	int * iNum = &(IN_GamePlayerShot->iPlayerShotParameters[6]);
	int * iMaxRadiusCompleted = &(IN_GamePlayerShot->iPlayerShotParameters[7]);
	
	*iAngleVelocity = IN_iParam0;	//X10
	*iCurrentAngle = IN_iParam1;	//X10
	*iDesiredFrameCount = IN_iParam2;
	*iCurrentFrameCount = *iDesiredFrameCount;
	*iCurrentRadius = 0;
	*iMaxRadius = IN_iParam3;
	*iNum = IN_iParam4;
	*iMaxRadiusCompleted = 0;

	IN_GamePlayerShot->bMovable = false;

}

void PlayerShot_Reimu_Bomber_Func(GamePlayerShot * IN_GamePlayerShot)
{

	int * iAngleVelocity = &(IN_GamePlayerShot->iPlayerShotParameters[0]);
	int * iCurrentAngle = &(IN_GamePlayerShot->iPlayerShotParameters[1]);
	int * iCurrentFrameCount = &(IN_GamePlayerShot->iPlayerShotParameters[2]);
	int * iDesiredFrameCount = &(IN_GamePlayerShot->iPlayerShotParameters[3]);
	int * iCurrentRadius = &(IN_GamePlayerShot->iPlayerShotParameters[4]);
	int * iMaxRadius = &(IN_GamePlayerShot->iPlayerShotParameters[5]);
	int * iNum = &(IN_GamePlayerShot->iPlayerShotParameters[6]);
	int * iMaxRadiusCompleted = &(IN_GamePlayerShot->iPlayerShotParameters[7]);


	if ( *iCurrentRadius < *iMaxRadius)
	{
		if (*iCurrentFrameCount >= *iDesiredFrameCount - 1)
		{
			double fAngleVelocity = (double)(*iAngleVelocity) / 10.0;
			double fCurrentAngle = (double)(*iCurrentAngle) / 10.0;

			IN_GamePlayerShot->x = Player.GetCenterX() + GetXbyCos(GetRadian(fCurrentAngle), *iCurrentRadius)
				- (double)(IN_GamePlayerShot->GetSprite()->GetWidth()) / 2.0;
			IN_GamePlayerShot->y = Player.GetCenterY() + GetYbySin(GetRadian(fCurrentAngle), *iCurrentRadius)
				- (double)(IN_GamePlayerShot->GetSprite()->GetHeight()) / 2.0;

			IN_GamePlayerShot->SetAngle(fCurrentAngle);

			fCurrentAngle = Angle360( fCurrentAngle + fAngleVelocity);
			*iCurrentAngle = (int)(fCurrentAngle * 10.0);

			(*iCurrentRadius)++;
			*iCurrentFrameCount = 0;
		}
		else
		{
			(*iCurrentFrameCount)++;
		}
	}
	else
	{
		if (*iMaxRadiusCompleted == 0)
		{
			IN_GamePlayerShot->bMovable = true;
			IN_GamePlayerShot->speed = 6.0;
			IN_GamePlayerShot->acc = 0.1;

			PlayerShot_Reimu_Sub_Init(IN_GamePlayerShot, 0, 0, 0, 3600, 0);

			*iMaxRadiusCompleted = 1;
		}
		else
		{
			PlayerShot_Reimu_Sub(IN_GamePlayerShot);
		}

// 		if (GameEnemyVector.size() > 0)
// 		{
// 			std::vector<GameEnemy *>::iterator Iter = GameEnemyVector.begin();
// 			while ( true )
// 			{
// 				if ( Iter == GameEnemyVector.end() )
// 				{
// 					break;
// 				}
// 
// 				if ( InsideCheck ( *Iter ) == true)
// 				{
// 					if ( abs ( (*Iter)->GetAngle() - GetAngle (IN_GamePlayerShot, *Iter)) <= 10.0)
// 					{
// 						IN_GamePlayerShot->SetAngle(GetAngle(IN_GamePlayerShot->x, IN_GamePlayerShot->y,
// 							(*Iter)->x + (double)((*Iter)->GetSprite()->GetWidth()) / 2.0,
// 							(*Iter)->y + (double)((*Iter)->GetSprite()->GetHeight()) / 2.0));
// 						break;
// 					}
// 				}
// 
// 				Iter++;
// 			}
// 		}
	}


}