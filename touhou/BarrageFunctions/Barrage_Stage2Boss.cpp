#include "Barrage_Stage2Boss.h"

void InitStage2BossAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iRadius = &IN_iParameters[0];
	int * iAngle = &IN_iParameters[1];
	int * iDuration = &IN_iParameters[2];
	int * iSubType = &IN_iParameters[3];
	int * iReverse = &IN_iParameters[4];
	int * iDone = &IN_iParameters[5];

	*iRadius = IN_iParam0;		//X10
	*iAngle = IN_iParam1;		//X10
	*iDuration = IN_iParam2;	//Frame
	*iSubType = IN_iParam3;	//Bullet9에서의 SubType
	*iReverse = IN_iParam4;
	*iDone = 0;
	
}

void Stage2BossAttack0(GameObject * IN_Object, int * IN_iParameters)
{
	int * iRadius = &IN_iParameters[0];
	int * iAngle = &IN_iParameters[1];
	int * iDuration = &IN_iParameters[2];
	int * iSubType = &IN_iParameters[3];
	int * iReverse = &IN_iParameters[4];
	int * iDone = &IN_iParameters[5];

	if (*iDone == 1)
	{
		return;
	}

	double fRadius = (double)(*iRadius) / 10.0;
	double CenterX = IN_Object->GetCenterX();
	double CenterY = IN_Object->GetCenterY();
	double HalfWidth = (double)Spr_BulletType9.GetWidth() / 2.0;
	double HalfHeight = (double)Spr_BulletType9.GetHeight() / 2.0;
	double fSpeed = fRadius / (double)(*iDuration);	

	auto AngleDest = [&] (double IN_angle)
	{
		double fDestX = CenterX - HalfWidth + GetXbyCos(GetRadian(IN_angle), fRadius);
		double fDestY = CenterY - HalfHeight + GetYbySin(GetRadian(IN_angle), fRadius);
		double fAngle = GetAngle(CenterX - HalfWidth, CenterY - HalfHeight, fDestX, fDestY);
		AddBullet(BULLET_TYPE9, *iSubType, CenterX, CenterY, 0.0, 0.0, 0.0, 0.0, true);
		GetLastBullet()->bGoTo = true;	
		GetLastBullet()->fDest_X = fDestX;
		GetLastBullet()->fDest_Y = fDestY;
		GetLastBullet()->speed = GetDistance(CenterX - HalfWidth, CenterY - HalfHeight, fDestX, fDestY) / (double)(*iDuration);
		GetLastBullet()->SetAngle(fAngle);
		GetLastBullet()->bMuteki = true;
		MakeMicroThread("Stage2BossAttack0MicroThread0", (int)(GetLastBullet()->x * 10.0), (int)(GetLastBullet()->y * 10.0), (int)(fAngle * 10.0), 30, *iReverse);
	};

	double Angle0 = Angle360((double)(*iAngle) / 10.0);
	double Angle1 = Angle360(Angle0 + 120.0);
	double Angle2 = Angle360(Angle1 + 120.0);

	AngleDest(Angle0);
	AngleDest(Angle1);
	AngleDest(Angle2);

	*iDone = 1;

}

void InitStage2BossAttack0MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * OriginX = &IN_iParameters[0]; 
	int * OriginY = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];
	int * iAngle = &IN_iParameters[3];
	int * iReverse = &IN_iParameters[4];
	int * iRadius = &IN_iParameters[5];
	int * iInited = &IN_iParameters[6];
	int * iFrameCount = &IN_iParameters[7];
	int * iFrameDesiredCount = &IN_iParameters[8];

	*OriginX = IN_iParam0;		//X10
	*OriginY = IN_iParam1;		//X10
	*iCurrentAngle = IN_iParam2;	//X10
	*iAngle = IN_iParam3;	//X10
	*iReverse = IN_iParam4;
	*iRadius = 0;		//X10
	*iInited = 0;
	*iFrameCount = 8;
	*iFrameDesiredCount = 8;

	
}

void Stage2BossAttack0MicroThread0(GameObject * IN_Object, int * IN_iParameters)
{
	int * OriginX = &IN_iParameters[0]; 
	int * OriginY = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];
	int * iAngle = &IN_iParameters[3];
	int * iReverse = &IN_iParameters[4];
	int * iRadius = &IN_iParameters[5];
	int * iInited = &IN_iParameters[6];
	int * iFrameCount = &IN_iParameters[7];
	int * iFrameDesiredCount = &IN_iParameters[8];

	double fOriginX = (double)(*OriginX) / 10.0;
	double fOriginY = (double)(*OriginY) / 10.0;
	double fCurrentAngle = (double)(*iCurrentAngle) / 10.0;
	double fAngle = (double)(*iAngle) / 10.0;

	if ( ((GameBullet*)IN_Object)->bGoTo == false)
	{
		if ( *iInited == 0)
		{
			*iRadius = (int)(GetDistance(fOriginX, fOriginY, IN_Object->x, IN_Object->y) * 10.0);
			((GameBullet*)IN_Object)->bMovable = false;		//Bullet의 Pos를 수동으로 조절
			*iInited = 1;
		}

		if ( *iReverse == 0)
		{
			fCurrentAngle = Angle360(fCurrentAngle + fAngle);
		}
		else
		{
			fCurrentAngle = Angle360 (fCurrentAngle - fAngle);
		}

		double fRadius = (double)(*iRadius) / 10.0;

		IN_Object->x = fOriginX + GetXbyCos(GetRadian(fCurrentAngle), fRadius);
		IN_Object->y = fOriginY + GetYbySin(GetRadian(fCurrentAngle), fRadius);

	}

	//人자 모양으로 날려줌

	if ( *iFrameCount >= *iFrameDesiredCount)
	{
		if (*iReverse == 0)
		{
			AddBullet(BULLET_TYPE1, 2, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fCurrentAngle, 0.0, 2, 0.0);
			AddBullet(BULLET_TYPE1, 2, IN_Object->GetCenterX(), IN_Object->GetCenterY(), Angle360(fCurrentAngle + 120.0), 0.0, 2.0, 0.0);
			AddBullet(BULLET_TYPE1, 2, IN_Object->GetCenterX(), IN_Object->GetCenterY(), Angle360(fCurrentAngle + 240.0), 0.0, 2, 0.0);
 		}
		else
		{
			AddBullet(BULLET_TYPE1, 6, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fCurrentAngle, 0.0, 2, 0.0);
			AddBullet(BULLET_TYPE1, 6, IN_Object->GetCenterX(), IN_Object->GetCenterY(), Angle360(fCurrentAngle + 120.0), 0.0, 2.0, 0.0);
			AddBullet(BULLET_TYPE1, 6, IN_Object->GetCenterX(), IN_Object->GetCenterY(), Angle360(fCurrentAngle + 240.0), 0.0, 2.0, 0.0);
 		}

		*iFrameCount = 0;
	}
	else
	{
		(*iFrameCount)++;
	}

	*iCurrentAngle = (int)(fCurrentAngle * 10.0);

}

void InitStage2BossAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iRadius = &IN_iParameters[0];
	int * iAngle = &IN_iParameters[1];
	int * iDuration = &IN_iParameters[2];
	int * iSubType = &IN_iParameters[3];
	int * iReverse = &IN_iParameters[4];
	int * iDone = &IN_iParameters[5];

	*iRadius = IN_iParam0;		//X10
	*iAngle = IN_iParam1;		//X10
	*iDuration = IN_iParam2;	//Frame
	*iSubType = IN_iParam3;	//Bullet9에서의 SubType
	*iReverse = IN_iParam4;
	*iDone = 0;

}

void Stage2BossAttack1(GameObject * IN_Object, int * IN_iParameters)
{
	int * iRadius = &IN_iParameters[0];
	int * iAngle = &IN_iParameters[1];
	int * iDuration = &IN_iParameters[2];
	int * iSubType = &IN_iParameters[3];
	int * iReverse = &IN_iParameters[4];
	int * iDone = &IN_iParameters[5];

	if (*iDone == 1)
	{
		return;
	}

	double fRadius = (double)(*iRadius) / 10.0;
	double CenterX = IN_Object->GetCenterX();
	double CenterY = IN_Object->GetCenterY();
	double HalfWidth = (double)Spr_BulletType9.GetWidth() / 2.0;
	double HalfHeight = (double)Spr_BulletType9.GetHeight() / 2.0;
	double fSpeed = fRadius / (double)(*iDuration);	

	auto AngleDest = [&] (double IN_angle)
	{
		double fDestX = CenterX - HalfWidth + GetXbyCos(GetRadian(IN_angle), fRadius);
		double fDestY = CenterY - HalfHeight + GetYbySin(GetRadian(IN_angle), fRadius);
		double fAngle = GetAngle(CenterX - HalfWidth, CenterY - HalfHeight, fDestX, fDestY);
		AddBullet(BULLET_TYPE9, *iSubType, CenterX, CenterY, 0.0, 0.0, 0.0, 0.0, true);
		GetLastBullet()->bGoTo = true;	
		GetLastBullet()->fDest_X = fDestX;
		GetLastBullet()->fDest_Y = fDestY;
		GetLastBullet()->speed = GetDistance(CenterX - HalfWidth, CenterY - HalfHeight, fDestX, fDestY) / (double)(*iDuration);
		GetLastBullet()->SetAngle(fAngle);
		GetLastBullet()->bMuteki = true;
		MakeMicroThread("Stage2BossAttack1MicroThread0", (int)(GetLastBullet()->x * 10.0), (int)(GetLastBullet()->y * 10.0), (int)(fAngle * 10.0), 10, *iReverse);
	};

	double Angle0 = Angle360((double)(*iAngle) / 10.0);
	double Angle1 = Angle360(Angle0 + 72.0);
	double Angle2 = Angle360(Angle1 + 72.0);
	double Angle3 = Angle360(Angle2 + 72.0);
	double Angle4 = Angle360(Angle3 + 72.0);

	AngleDest(Angle0);
	AngleDest(Angle1);
	AngleDest(Angle2);
	AngleDest(Angle3);
	AngleDest(Angle4);

	*iDone = 1;

}



void InitStage2BossAttack1MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iOriginX = &IN_iParameters[0]; 
	int * iOriginY = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];
	int * iAngle = &IN_iParameters[3];
	int * iReverse = &IN_iParameters[4];
	int * iRadius = &IN_iParameters[5];
	int * iInited = &IN_iParameters[6];
	int * iFrameCount = &IN_iParameters[7];
	int * iFrameDesiredCount = &IN_iParameters[8];
	int * iFrameSubCount = &IN_iParameters[9];		//파라메터 슬롯 부족으로 SubDesiredCount는 DesiredCount를 활용한다.

	*iOriginX = IN_iParam0;		//X10
	*iOriginY = IN_iParam1;		//X10
	*iCurrentAngle = IN_iParam2;	//X10
	*iAngle = IN_iParam3;	//X10
	*iReverse = IN_iParam4;
	*iRadius = 0;		//X10
	*iInited = 0;
	*iFrameDesiredCount = 6;
	*iFrameCount = *iFrameDesiredCount - 1;
	*iFrameSubCount = 0;

}

void Stage2BossAttack1MicroThread0(GameObject * IN_Object, int * IN_iParameters)
{
	int * iOriginX = &IN_iParameters[0]; 
	int * iOriginY = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];
	int * iAngle = &IN_iParameters[3];
	int * iReverse = &IN_iParameters[4];
	int * iRadius = &IN_iParameters[5];
	int * iInited = &IN_iParameters[6];
	int * iFrameCount = &IN_iParameters[7];
	int * iFrameDesiredCount = &IN_iParameters[8];
	int * iFrameSubCount = &IN_iParameters[9];

	double fOriginX = (double)(*iOriginX) / 10.0;
	double fOriginY = (double)(*iOriginY) / 10.0;
	double fCurrentAngle = (double)(*iCurrentAngle) / 10.0;
	double fAngle = (double)(*iAngle) / 10.0;

	if ( ((GameBullet*)IN_Object)->bGoTo == false)
	{
		if ( *iInited == 0)
		{
			*iRadius = (int)(GetDistance(fOriginX, fOriginY, IN_Object->x, IN_Object->y) * 10.0);
			((GameBullet*)IN_Object)->bMovable = false;
			*iInited = 1;
		}

		if ( *iReverse == 0)
		{
			fCurrentAngle = Angle360(fCurrentAngle + fAngle);
		}
		else
		{
			fCurrentAngle = Angle360 (fCurrentAngle - fAngle);
		}

		double fRadius = (double)(*iRadius) / 10.0;

		IN_Object->x = fOriginX + GetXbyCos(GetRadian(fCurrentAngle), fRadius);
		IN_Object->y = fOriginY + GetYbySin(GetRadian(fCurrentAngle), fRadius);

		*iCurrentAngle = (int)(fCurrentAngle * 10.0);

	}

	//공격
	if ( *iFrameCount >= *iFrameDesiredCount - 1)
	{

		//공식 : 중점에서 꼭지점에 이르는 각도(fCurrentAngle) + 오각형의 내각의 절반(108 / 2 = 54)
		double fAngle = Angle360(fCurrentAngle + 54.0);
		AddBullet(BULLET_TYPE13, rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, 2.0, 0.0);

		*iFrameCount = 0;
	}
	else
	{
		(*iFrameCount)++;
	}

	//열발 쏠때마다 한발씩 플레이어를 향해 조준탄을 날림.
// 	if (*iReverse == 0)		//난이도 조절을 위해 시계방향을 도는 원에만 총알을 뿌림.
// 	{
// 		if (*iFrameSubCount >= (*iFrameDesiredCount) * 10)
// 		{
// 			AddBullet(BULLET_TYPE10, rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), GetAngle(IN_Object, &Player), 0.0, 1.0, 0.0);
// 
// 			*iFrameSubCount = 0;
// 		}
// 		else
// 		{
// 			(*iFrameSubCount)++;
// 		}
// 	}

}

void InitStage2BossAttack2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iAngle = &IN_iParameters[0];
	int * iSpeed = &IN_iParameters[1];
	int * iInterval = &IN_iParameters[2];
	int * iCurrentFrame = &IN_iParameters[3];
	int * iDensity = &IN_iParameters[4];
	int * iCurrentPos = &IN_iParameters[5];
	int * iSubType = &IN_iParameters[6];
	int * iDone = &IN_iParameters[7];
	int * iCompleteCount = &IN_iParameters[8];

	*iAngle = IN_iParam0;		//X10
	*iSpeed = IN_iParam1;		//X10
	*iInterval = IN_iParam2;		//Frame
	*iCurrentFrame = 0;
	*iDensity = IN_iParam3;
	*iCurrentPos = 0;
	*iSubType = IN_iParam4;	//Bullet2에서의 SubType
	*iDone = 0;
	*iCompleteCount = 0;

}

void Stage2BossAttack2(GameObject * IN_Object, int * IN_iParameters)
{
	int * iAngle = &IN_iParameters[0];
	int * iSpeed = &IN_iParameters[1];
	int * iInterval = &IN_iParameters[2];
	int * iCurrentFrame = &IN_iParameters[3];
	int * iDensity = &IN_iParameters[4];
	int * iCurrentPos = &IN_iParameters[5];
	int * iSubType = &IN_iParameters[6];
	int * iDone = &IN_iParameters[7];
	int * iCompleteCount = &IN_iParameters[8];

	double fAngle = (double)(*iAngle) / 10.0;
	double fSpeed = (double)(*iSpeed) / 10.0;


	if (*iDone == 0)
	{
		if ( ((GameBoss*)IN_Object)->bMovable == false)
		{
			if ( *iCurrentFrame >= *iInterval - 1)
			{
				*iCurrentFrame = 0;

				if (*iCurrentPos == 0)
				{
					int iTempSubtype = rand()%8;
					int iQuantity = 32;
					for (int i = 0; i < iQuantity; i++)
					{
						double fNewAngle = fAngle + (360.0 / (double)(iQuantity) * (double)i);
						AddBullet(BULLET_TYPE8, iTempSubtype, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fNewAngle, 0.0, fSpeed, 0.0);
					}
				}
				else if ( *iCurrentPos == 1)
				{
					for (int i = 0; i < 6; i++)
					{
						double fNewAngle = fAngle + (60.0 * (double)i);
						AddBullet(BULLET_TYPE2, *iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fNewAngle, 0.0, fSpeed, 0.0);
					}
				}
				else if ( *iCurrentPos == *iDensity - 2)
				{
					for (int i = 0; i < 6; i++)
					{
						double fNewAngle = fAngle + 30.0 + (60.0 * (double)i);
						AddBullet(BULLET_TYPE2, *iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fNewAngle, 0.0, fSpeed, 0.0);
					}
				}
				else
				{
					for (int i = 0; i < 6; i++)
					{
						double fNewAngleLeft = fAngle + (60.0 * (double)i) - (30.0 / (double)(*iDensity) * (double)(*iCurrentPos));
						double fNewAngleRight = fAngle + (60.0 * (double)i) + (30.0 / (double)(*iDensity) * (double)(*iCurrentPos));
						AddBullet(BULLET_TYPE2, *iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fNewAngleLeft, 0.0, fSpeed, 0.0);
						AddBullet(BULLET_TYPE2, *iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fNewAngleRight, 0.0, fSpeed, 0.0);
					}
				}

				(*iCurrentPos)++;

				if (*iCurrentPos == *iDensity - 1)
				{
				//꽃잎 그리기가 끝나면, 자신을 제거한다.
				// 			std::vector<GameBarrage *>::iterator Iter = ((GameBoss*)IN_Object)->pvBarrage.begin();
				// 			while ( true )
				// 			{
				// 				if ( Iter == ((GameBoss*)IN_Object)->pvBarrage.end())
				// 				{
				// 					return;
				// 					break;		//테스트
				// 				}
				// 
				// 				if ( (*Iter)->pFunction == (BarrageFunction)(&Stage2BossAttack2) )
				// 				{
				// 					delete (*Iter);
				// 					((GameBoss*)IN_Object)->pvBarrage.erase( Iter );
				// 					return;
				// 					
				// 					break;		//테스트
				// 				}
				// 
				// 			}

					*iCurrentPos = 0;	//테스트
					*iDone = 1;
					(*iCompleteCount)++;
				}

			}
			else
			{
				(*iCurrentFrame)++;
			}
		}
	}

	
}


void InitStage2BossAttack3(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iAngle = &IN_iParameters[0];
	int * iAngleAdd = &IN_iParameters[1];
	int * iSpeed = &IN_iParameters[2];
	int * iCurrentFrame = &IN_iParameters[3];
	int * iInterval = &IN_iParameters[4];
	int * iFarX = &IN_iParameters[5];

	*iAngle = IN_iParam0;		//X10
	*iAngleAdd = IN_iParam1;	//X10
	*iSpeed = IN_iParam2;		//X10
	*iInterval = IN_iParam3;		//X10
	*iCurrentFrame = *iInterval - 1;
	*iFarX = IN_iParam4;			//X10

}

void Stage2BossAttack3(GameObject * IN_Object, int * IN_iParameters)
{
	int * iAngle = &IN_iParameters[0];
	int * iAngleAdd = &IN_iParameters[1];
	int * iSpeed = &IN_iParameters[2];
	int * iCurrentFrame = &IN_iParameters[3];
	int * iInterval = &IN_iParameters[4];
	int * iFarX = &IN_iParameters[5];


	if ( *iCurrentFrame >= *iInterval - 1)
	{
		double fAngle = (double)(*iAngle) / 10.0;
		double fAddAngle = (double)(*iAngleAdd) / 10.0;
		double fSpeed = (double)(*iSpeed) / 10.0;
		double fAddX = (double)(*iFarX) / 10.0;

		int iQuantity = 16;

		for (int k = 0; k < iQuantity; k++)
		{
			AddBullet(BULLET_TYPE1, 0, IN_Object->GetCenterX() + fAddX, IN_Object->GetCenterY(), fAngle + (360.0 / ((double)iQuantity) * (double)k), 0.0, fSpeed, 0.0);
		}
	
		fAngle = Angle360(fAngle + fAddAngle);
		*iAngle = (int)(fAngle * 10.0);

		*iCurrentFrame = 0;
	}
	else
	{
		(*iCurrentFrame)++;
	}
}

void InitStage2BossAttack3_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iAngle = &IN_iParameters[0];
	int * iAngleAdd = &IN_iParameters[1];
	int * iSpeed = &IN_iParameters[2];
	int * iCurrentFrame = &IN_iParameters[3];
	int * iInterval = &IN_iParameters[4];
	int * iFarX = &IN_iParameters[5];

	*iAngle = IN_iParam0;		//X10
	*iAngleAdd = IN_iParam1;	//X10
	*iSpeed = IN_iParam2;		//X10
	*iInterval = IN_iParam3;		//X10
	*iCurrentFrame = *iInterval - 1;
	*iFarX = IN_iParam4;			//X10

}

void Stage2BossAttack3_1(GameObject * IN_Object, int * IN_iParameters)
{
	int * iAngle = &IN_iParameters[0];
	int * iAngleAdd = &IN_iParameters[1];
	int * iSpeed = &IN_iParameters[2];
	int * iCurrentFrame = &IN_iParameters[3];
	int * iInterval = &IN_iParameters[4];
	int * iFarX = &IN_iParameters[5];


	if ( *iCurrentFrame >= *iInterval - 1)
	{
		double fAngle = (double)(*iAngle) / 10.0;
		double fAddAngle = (double)(*iAngleAdd) / 10.0;
		double fSpeed = (double)(*iSpeed) / 10.0;
		double fAddX = (double)(*iFarX) / 10.0;

		int iQuantity = 3;

		for (int k = 0; k < iQuantity; k++)
		{
			AddBullet(BULLET_TYPE18, 2, IN_Object->GetCenterX() + fAddX, IN_Object->GetCenterY(), fAngle + (360.0 / ((double)iQuantity) * (double)k), 0.0, fSpeed, 0.0);
		}

		fAngle = Angle360(fAngle + fAddAngle);
		*iAngle = (int)(fAngle * 10.0);

		*iCurrentFrame = 0;
	}
	else
	{
		(*iCurrentFrame)++;
	}
}

void InitStage2BossAttack4(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iQuantity = &IN_iParameters[0];
	int * iShotInterval = &IN_iParameters[1];
	int * iSubInterval = &IN_iParameters[2];
	int * iMaxAngle = &IN_iParameters[3];
	int * iDone = &IN_iParameters[4];

	*iQuantity = IN_iParam0;
	*iShotInterval = IN_iParam1;
	*iSubInterval = IN_iParam2;
	*iMaxAngle = IN_iParam3;		//X10
	*iDone = 0;
	
}
void Stage2BossAttack4(GameObject * IN_Object, int * IN_iParameters)
{
	int * iQuantity = &IN_iParameters[0];
	int * iShotInterval = &IN_iParameters[1];
	int * iSubInterval = &IN_iParameters[2];
	int * iMaxAngle = &IN_iParameters[3];
	int * iDone = &IN_iParameters[4];

	if (*iDone == 1)
	{
		return;
	}

	auto MakeDestBullet = [&] (int IN_FarFromX, int IN_FarFromY)
	{
		AddBullet(BULLET_TYPE9, 7, pBoss->GetCenterX(), pBoss->GetCenterY(), 0.0, 0.0, 0.0, 0.0, true);
		GetLastBullet()->bMuteki = true;
		MakeMicroThread("Stage2BossAttack4MicroThread0", IN_FarFromX, IN_FarFromY, *iShotInterval, *iSubInterval, *iMaxAngle);
	};

	for (int i = 0; i < *iQuantity; i++)
	{
		MakeDestBullet(-1830, -300 + 700 * i);
		MakeDestBullet(1830, -300 + 700 * i);
	}

	*iDone = 1;
}

void InitStage2BossAttack4_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iCurrentFrame = &IN_iParameters[0];
	int * iShotInterval = &IN_iParameters[1];
	int * iQuantity = &IN_iParameters[2];
	int * iAngleRange = &IN_iParameters[3];

	*iShotInterval = IN_iParam0;
	*iCurrentFrame = (*iShotInterval) - 1;
	*iQuantity = IN_iParam1;
	*iAngleRange = IN_iParam2;		//X10

}

void Stage2BossAttack4_1(GameObject * IN_Object, int * IN_iParameters)
{
	int * iCurrentFrame = &IN_iParameters[0];
	int * iShotInterval = &IN_iParameters[1];
	int * iQuantity = &IN_iParameters[2];
	int * iAngleRange = &IN_iParameters[3];

	double fFullAngle = ((double)(*iAngleRange) / 10.0);
	double fHalfAngle = ((double)(*iAngleRange) / 10.0) / 2.0;

	if ( *iCurrentFrame >= (*iShotInterval) - 1 )
	{
		for (int i = 0; i < (*iQuantity); i++)
		{
//			double fAngle = GetAngle(IN_Object, &Player) - fHalfAngle + (double)(rand() % (*iAngleRange) ) / 10.0;
			double fAngle = Angle360(GetAngle(IN_Object, &Player) + (fFullAngle / (double)(*iQuantity) * (double)i));
//			double fSpeed = 2.0 + (double)(rand()%20) / 10.0;
			double fSpeed = 1.0;
			AddBullet(BULLET_TYPE18, 1, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0, fSpeed, 0);
		}
		*iCurrentFrame = 0;
	}
	else
	{
		(*iCurrentFrame)++;
	}
}

void InitStage2BossAttack4MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iCurrentFrame = &IN_iParameters[0];
	int * iShotInterval = &IN_iParameters[1];
	int * iLeftOrRight = &IN_iParameters[2];
	int * iCurrentSubCount = &IN_iParameters[3];
	int * iSubInterval = &IN_iParameters[4];
	int * iCurrentAngle = &IN_iParameters[5];
	int * iMaxAngle = &IN_iParameters[6];
	int * iMinAngle = &IN_iParameters[7];
	int * iAngleAdd = &IN_iParameters[8];
	int * iNowAngleAdding = &IN_iParameters[9];

	*iShotInterval = IN_iParam2;
	*iCurrentFrame = *iShotInterval - 1;

	if (IN_iParam0 < 0)		//LEFT
	{
		*iLeftOrRight = 0;
	}
	else		//RIGHT
	{
		*iLeftOrRight = 1;
	}

	*iSubInterval = IN_iParam3;
	*iCurrentSubCount = *iSubInterval - 1;

	*iMinAngle = 150;		//X10
	*iAngleAdd = 80;		//X10
	*iCurrentAngle = *iMinAngle;				//X10
	*iMaxAngle = IN_iParam4;		//X10
	*iNowAngleAdding = 1;

	IN_Object->bGoTo = true;
	IN_Object->bMovable = true;
	IN_Object->fDest_X = IN_Object->GetCenterX() - (double)(IN_Object->GetSprite()->GetWidth()) / 2.0 + (double)(IN_iParam0) / 10.0;
	IN_Object->fDest_Y = IN_Object->GetCenterY() - (double)(IN_Object->GetSprite()->GetHeight()) / 2.0 + (double)(IN_iParam1) / 10.0;
	IN_Object->speed = 3.0;
	IN_Object->SetAngle(GetAngle(IN_Object->x, IN_Object->y, IN_Object->fDest_X, IN_Object->fDest_Y));

}
void Stage2BossAttack4MicroThread0(GameObject * IN_Object, int * IN_iParameters)
{
	int * iCurrentFrame = &IN_iParameters[0];
	int * iShotInterval = &IN_iParameters[1];
	int * iLeftOrRight = &IN_iParameters[2];
	int * iCurrentSubCount = &IN_iParameters[3];
	int * iSubInterval = &IN_iParameters[4];
	int * iCurrentAngle = &IN_iParameters[5];
	int * iMaxAngle = &IN_iParameters[6];
	int * iMinAngle = &IN_iParameters[7];
	int * iAngleAdd = &IN_iParameters[8];
	int * iNowAngleAdding = &IN_iParameters[9];

	if (IN_Object->bMovable == false)
	{
		double fAngle = 0.0;
		double fAngle2 = (double)(*iCurrentAngle) / 10.0;
		if ( *iLeftOrRight == 0)		//LEFT
		{
			fAngle = 0.0;
		}
		else		//RIGHT
		{
			fAngle = 180.0;
		}

		if ( *iCurrentFrame >= *iShotInterval - 1)
		{
			int iSubType = 3;

			if ( *iLeftOrRight == 1)
			{
				iSubType = 5;
			}

			AddBullet(BULLET_TYPE1, iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle - fAngle2, 0.0, 2.0, 0.0);
			AddBullet(BULLET_TYPE1, iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle + fAngle2, 0.0, 2.0, 0.0);
			*iCurrentFrame = 0;

			if (*iCurrentSubCount >= *iSubInterval - 1)
			{	
				//AddBullet(BULLET_TYPE1, 0, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, 2.0, 0.0);

				if ( *iNowAngleAdding == 1)
				{
					(*iCurrentAngle) += (*iAngleAdd); 
					if ( *iCurrentAngle >= *iMaxAngle)
					{
						*iCurrentAngle = *iMaxAngle;
						*iNowAngleAdding = 0;
					}
				}
				else
				{
					(*iCurrentAngle) -= (*iAngleAdd);
					if ( *iCurrentAngle <= *iMinAngle)
					{
						*iCurrentAngle = *iMinAngle;
						*iNowAngleAdding = 1;
					}
				}
				*iCurrentSubCount = 0;
			}
			else
			{
				(*iCurrentSubCount)++;
			}
		}
		else
		{
			(*iCurrentFrame)++;
		}
	}

}

void InitStage2BossAttackFinal(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iBulletQuantity = &IN_iParameters[0];
	int * iBulletSpeed = &IN_iParameters[1];
	int * iBulletInterval = &IN_iParameters[2];

	*iBulletQuantity = IN_iParam0;
	*iBulletSpeed = IN_iParam1;		//X10
	*iBulletInterval = IN_iParam2;

	auto MakeDestBullet = [&] (int IN_X, int IN_Y)
	{
		AddBullet(BULLET_TYPE9, 7, pBoss->GetCenterX(), pBoss->GetCenterY(), 0.0, 0.0, 0.0, 0.0, true);
		GetLastBullet()->bMuteki = true;
		MakeMicroThread("Stage2BossAttackFinalMicroThread0", IN_X, IN_Y, *iBulletQuantity, *iBulletSpeed, *iBulletInterval);
	};

	MakeDestBullet ( (UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH) * 10, (UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT) * 10);
	MakeDestBullet ( (UI_WINDOW_RIGHT_X - Spr_BulletType9.GetWidth()) * 10, (UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT) * 10);
	MakeDestBullet ( (UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH) * 10, (UI_WINDOW_BOTTOM_Y - Spr_BulletType9.GetHeight()) * 10);
	MakeDestBullet ( (UI_WINDOW_RIGHT_X - Spr_BulletType9.GetWidth()) * 10, (UI_WINDOW_BOTTOM_Y - Spr_BulletType9.GetHeight()) * 10);

}

void Stage2BossAttackFinal(GameObject * IN_Object, int * IN_iParameters)
{

	
}

void InitStage2BossAttackFinalMicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iBulletQuantity = &IN_iParameters[0];
	int * iBulletSpeed = &IN_iParameters[1];
	int * iCurrentFrame = &IN_iParameters[2];
	int * iBulletInterval = &IN_iParameters[3];
	int * iFlag = &IN_iParameters[4];

	*iBulletQuantity = IN_iParam2;
	*iBulletSpeed = IN_iParam3;
	*iBulletInterval = IN_iParam4;
	*iCurrentFrame = (*iBulletInterval) - 1;
	*iFlag = 0;

	IN_Object->bGoTo = true;
	IN_Object->bMovable = true;
// 	IN_Object->fDest_X = IN_Object->GetCenterX() - (double)(IN_Object->GetSprite()->GetWidth()) / 2.0 + (double)(IN_iParam0) / 10.0;
// 	IN_Object->fDest_Y = IN_Object->GetCenterY() - (double)(IN_Object->GetSprite()->GetHeight()) / 2.0 + (double)(IN_iParam1) / 10.0;
	IN_Object->fDest_X = (double)(IN_iParam0) / 10.0;
	IN_Object->fDest_Y =  (double)(IN_iParam1) / 10.0;
	IN_Object->speed = 3.0;
	IN_Object->SetAngle(GetAngle(IN_Object->x, IN_Object->y, IN_Object->fDest_X, IN_Object->fDest_Y));

}

void Stage2BossAttackFinalMicroThread0(GameObject * IN_Object, int * IN_iParameters)
{
	int * iBulletQuantity = &IN_iParameters[0];
	int * iBulletSpeed = &IN_iParameters[1];
	int * iCurrentFrame = &IN_iParameters[2];
	int * iBulletInterval = &IN_iParameters[3];
	int * iFlag = &IN_iParameters[4];
	int * iCurrentAngle = &IN_iParameters[5];

	if (IN_Object->bMovable == false)
	{
		if (*iCurrentFrame >= (*iBulletInterval) - 1)
		{
			double fStartAngle = 0.0;
			int iSubType = 0;
			if (IN_Object->GetAngle() <= 90.0)	//우상단
			{
				fStartAngle = 180.0;
				iSubType = 1;
			}
			else if (IN_Object->GetAngle() <= 180.0)	//좌상단
			{
				fStartAngle = 270.0;
				iSubType = 3;
			}
			else if (IN_Object->GetAngle() <= 270.0)	//좌하단
			{
				fStartAngle = 0.0;
				iSubType = 5;
			}
			else if (IN_Object->GetAngle() < 360.0)		//우하단
			{
				fStartAngle = 90.0;
				iSubType = 6;
			}

			double fAngleKagera = 90.0 / (double)(*iBulletQuantity);
			double fAngleAdd = 0.0;

			if ( *iFlag == 0)
			{
				fAngleAdd = 0.0;
				*iFlag = 1;
			}
			else
			{
				fAngleAdd = fAngleKagera / 2.0;
				*iFlag = 0;
			}

			for (int i = 0; i <= *iBulletQuantity; i++)
			{
				AddBullet(BULLET_TYPE8, iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fStartAngle + (fAngleKagera * (double)i) + fAngleAdd, 0, 1.5, 0.0);
			}

			*iCurrentFrame = 0;
		}
		else
		{
			(*iCurrentFrame)++;
		}
	}
}

void InitStage2BossAttackFinal_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iQuantity = &IN_iParameters[0];
	int * iCurrentFrame = &IN_iParameters[1];
	int * iInterval = &IN_iParameters[2];
	int * iCurrentAngle = &IN_iParameters[3];

	*iQuantity = IN_iParam0;
	*iInterval = IN_iParam1;
	*iCurrentFrame = *iInterval - 1;
	*iCurrentAngle = (int)(GetAngle(IN_Object, &Player)) * 10;
}
void Stage2BossAttackFinal_1(GameObject * IN_Object, int * IN_iParameters)
{
	int * iQuantity = &IN_iParameters[0];
	int * iCurrentFrame = &IN_iParameters[1];
	int * iInterval = &IN_iParameters[2];
	int * iCurrentAngle = &IN_iParameters[3];

	if (IN_Object->bMovable == false)
	{
		if ( *iCurrentFrame >= *iInterval - 1)
		{
			double fAngle = (*iCurrentAngle) / 10.0;
			double fAngleKagera = 360.0 / (double)(*iQuantity);
			
			for (int i = 0; i < *iQuantity; i++)
			{
				AddBullet(BULLET_TYPE4, rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle + (fAngleKagera * (double)i) - 2.5, -0.1, 1.5, 0.0);
				AddBullet(BULLET_TYPE4, rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle + (fAngleKagera * (double)i), 0, 1.5, 0.0);
				AddBullet(BULLET_TYPE4, rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle + (fAngleKagera * (double)i) + 2.5, 0.1, 1.5, 0.0);
			}

			*iCurrentAngle = Angle360(*iCurrentAngle + 50);
			*iCurrentFrame = 0;
		}
		else
		{
			(*iCurrentFrame)++;
		}
	}
}