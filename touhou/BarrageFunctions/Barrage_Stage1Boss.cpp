#include "Barrage_Stage1Boss.h"

void InitStage1BossAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iSubFrameCount = &IN_iParameters[2];
	int * iSubFrameDesiredCount = &IN_iParameters[3];
	int * iLaunchCount = &IN_iParameters[4];
	int * iLaunchDesiredCount = &IN_iParameters[5];
	int * iCurrentAngle = &IN_iParameters[6];
	int * iAngleAdd = &IN_iParameters[7];

	*iFrameDesiredCount = 20;
	*iFrameCount = *iFrameDesiredCount;

	*iSubFrameDesiredCount = 4;
	*iSubFrameCount = *iSubFrameDesiredCount;

	*iLaunchDesiredCount = 15;
	*iLaunchCount = 0;

	*iCurrentAngle = 900;		//X10
	*iAngleAdd = 100;	//X10
	
}

void Stage1BossAttack0(GameObject * IN_Object, int * IN_iParameters)
{
	
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iSubFrameCount = &IN_iParameters[2];
	int * iSubFrameDesiredCount = &IN_iParameters[3];
	int * iLaunchCount = &IN_iParameters[4];
	int * iLaunchDesiredCount = &IN_iParameters[5];
	int * iCurrentAngle = &IN_iParameters[6];
	int * iAngleAdd = &IN_iParameters[7];

	if ( *iFrameCount >= *iFrameDesiredCount)
	{
		if (*iSubFrameCount >= *iSubFrameDesiredCount )
		{
			if ( *iLaunchCount < *iLaunchDesiredCount)
			{
				if ( *iLaunchCount == 0)
				{
					AddBullet(BULLET_TYPE18, rand()%4, IN_Object->GetCenterX(), IN_Object->GetCenterY(), GetAngle(IN_Object, &Player), 0, 2.0, 0.01);
					
					for (int i = 0; i < 5; i++)
					{
						AddBullet(BULLET_TYPE15, rand()%8, IN_Object->GetCenterX(), IN_Object->GetCenterY(), GetAngle(IN_Object, &Player) - 10.0 + (double)(rand()%20), 0, 2.0 + (double)(rand()%10) / 10.0, 0.0);
					}
				
				}
				
				AddBullet(BULLET_TYPE2, 7, IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)(*iCurrentAngle) / 10.0, 0.0, 3.0, 0.0);
				AddBullet(BULLET_TYPE2, 7, IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)(*iCurrentAngle) / 10.0 + 120.0, 0.0, 3.0, 0.00);
				AddBullet(BULLET_TYPE2, 7, IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)(*iCurrentAngle) / 10.0 + 240.0, 0.0, 3.0, 0.00);

				*iCurrentAngle = Angle360(*iCurrentAngle + *iAngleAdd);
				(*iLaunchCount)++;
				*iSubFrameCount = 0;
			}
			else
			{
				*iLaunchCount = 0;
				*iSubFrameCount = *iSubFrameDesiredCount;
				*iFrameCount = 0;
			}

		}
		else
		{
			(*iSubFrameCount)++;
		}

	}
	else
	{
		(*iFrameCount)++;
	}

}

void InitStage1BossAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iAddAngle = &IN_iParameters[2];
	int * iDone = &IN_iParameters[3];

	*iFrameDesiredCount = 60;
	*iFrameCount = *iFrameDesiredCount;
	*iAddAngle = IN_iParam0;
	*iDone = 0;

}

void Stage1BossAttack1(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iAddAngle = &IN_iParameters[2];
	int * iDone = &IN_iParameters[3];

	//육각형을 만든다.

	auto MakeHexagon = [&] (double IN_Length, int IN_Quantity, double IN_StartX, double IN_StartY, bool IN_ClockWise, double IN_AddAngle)
	{

		double fCurrentAngle;
		double fCurrentX;
		double fCurrentY;

		if (IN_ClockWise == true)
		{
			fCurrentAngle = Angle360(0.0 - IN_AddAngle);

			fCurrentX = IN_StartX + GetXbyCos(GetRadian(Angle360(120.0 - IN_AddAngle)), (IN_Length)) ;
			fCurrentY = IN_StartY + GetYbySin(GetRadian(Angle360(120.0 - IN_AddAngle)), (IN_Length)) ;
		}
		else
		{
			fCurrentAngle = Angle360(180.0 + IN_AddAngle);
			fCurrentX = IN_StartX + GetXbyCos(GetRadian(Angle360(60.0 + IN_AddAngle)), (IN_Length));
			fCurrentY = IN_StartY + GetYbySin(GetRadian(Angle360(60.0 + IN_AddAngle)), (IN_Length)) ;
		}

		//디버그용.
//		AddBullet(BULLET_TYPE0, 0, fCurrentX + (double)(Spr_BulletType0.GetWidth()) / 2.0 , fCurrentY + (double)(Spr_BulletType0.GetHeight()) / 2.0 , 0, 0, 0, 0);

		double fDensity = IN_Length / (double)IN_Quantity;

		int iDesiredTime = 60;

		int iColor = rand()%8;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < IN_Quantity; j++)
			{
				double fSpeed = GetDistance(IN_StartX - ((double)(Spr_BulletType0.GetWidth()) / 2.0), IN_StartY - ( (double)(Spr_BulletType0.GetHeight()) / 2.0), fCurrentX, fCurrentY) / (double)iDesiredTime; 

				AddBullet(BULLET_TYPE6, iColor, IN_StartX, IN_StartY, 
					GetAngle( IN_StartX - ((double)(Spr_BulletType0.GetWidth()) / 2.0), IN_StartY - ((double)(Spr_BulletType0.GetHeight()) / 2.0), fCurrentX, fCurrentY), 
					0, fSpeed, 0);
				(*(GameBulletVector.end() - 1))->fDest_X = fCurrentX;
				(*(GameBulletVector.end() - 1))->fDest_Y = fCurrentY;
				(*(GameBulletVector.end() - 1))->bGoTo = true;		

				fCurrentX = fCurrentX + GetXbyCos(GetRadian(fCurrentAngle), fDensity);
				fCurrentY = fCurrentY + GetYbySin(GetRadian(fCurrentAngle), fDensity);

				int iDelay = iDesiredTime;
				int iAngle = (int)(fCurrentAngle * 10.0);
				int iSpeed = 10 + j;

				MakeMicroThread("Stage1BossAttack1MicroThread0", iDelay, iAngle, iSpeed, 0, 0);

			}

			if (IN_ClockWise == true)
			{
				fCurrentAngle = Angle360(fCurrentAngle - 60.0);
			}
			else
			{
				fCurrentAngle = Angle360(fCurrentAngle + 60.0);

			}

		}
	};

//	if ( *iFrameCount >= *iFrameDesiredCount)
	if (*iDone == 0)
	{
		Sound_Kira.Play(false, NULL, fVolume_SE);

// 		MakeHexagon(100.0, 3, IN_Object->GetCenterX() - (double)(Spr_BulletType0.GetWidth()) / 2.0, IN_Object->GetCenterY() - (double)(Spr_BulletType0.GetHeight()) / 2.0, true, (double)(*iAddAngle) / 10.0 - 30.0);
// 		MakeHexagon(100.0, 3, IN_Object->GetCenterX() - (double)(Spr_BulletType0.GetWidth()) / 2.0, IN_Object->GetCenterY() - (double)(Spr_BulletType0.GetHeight()) / 2.0, true, (double)(*iAddAngle) / 10.0 - 30.0);
// 		MakeHexagon(100.0, 3, IN_Object->GetCenterX() - (double)(Spr_BulletType0.GetWidth()) / 2.0, IN_Object->GetCenterY() - (double)(Spr_BulletType0.GetHeight()) / 2.0, true, (double)(*iAddAngle) / 10.0 - 20.0);
// 		MakeHexagon(100.0, 3, IN_Object->GetCenterX() - (double)(Spr_BulletType0.GetWidth()) / 2.0, IN_Object->GetCenterY() - (double)(Spr_BulletType0.GetHeight()) / 2.0, true, (double)(*iAddAngle) / 10.0 - 10);
// 		MakeHexagon(100.0, 3, IN_Object->GetCenterX() - (double)(Spr_BulletType0.GetWidth()) / 2.0, IN_Object->GetCenterY() - (double)(Spr_BulletType0.GetHeight()) / 2.0, true, (double)(*iAddAngle) / 10.0);
// 		MakeHexagon(100.0, 3, IN_Object->GetCenterX() - (double)(Spr_BulletType0.GetWidth()) / 2.0, IN_Object->GetCenterY() - (double)(Spr_BulletType0.GetHeight()) / 2.0, true, (double)(*iAddAngle) / 10.0 + 10.0);
// 		MakeHexagon(100.0, 3, IN_Object->GetCenterX() - (double)(Spr_BulletType0.GetWidth()) / 2.0, IN_Object->GetCenterY() - (double)(Spr_BulletType0.GetHeight()) / 2.0, true, (double)(*iAddAngle) / 10.0 + 20.0);
// 		MakeHexagon(100.0, 3, IN_Object->GetCenterX() - (double)(Spr_BulletType0.GetWidth()) / 2.0, IN_Object->GetCenterY() - (double)(Spr_BulletType0.GetHeight()) / 2.0, true, (double)(*iAddAngle) / 10.0 + 30.0);
		//MakeHexagon(40.0, 5, IN_Object->GetCenterX() - 150, IN_Object->GetCenterY(), true,  (double)(*iAddAngle) / 10.0 + 15.0);
		//MakeHexagon(40.0, 5, IN_Object->GetCenterX() - 150, IN_Object->GetCenterY(), false,  (double)(*iAddAngle) / 10.0 + 15.0);
		//MakeHexagon(40.0, 5, IN_Object->GetCenterX() + 150, IN_Object->GetCenterY(), true,  (double)(*iAddAngle) / 10.0 + 15.0);
		//MakeHexagon(40.0, 5, IN_Object->GetCenterX() + 150, IN_Object->GetCenterY(), false,  (double)(*iAddAngle) / 10.0 + 15.0);

		*iDone = 1;
		//*iFrameCount = 0;

		iGameFrame = 0;
		iOldGameFrame = 0;
		iOldGameFrame_EnemyDamaged = 0;
		iOldGameFrame_EnemyDead = 0;
	}
//	else
	{
	//	(*iFrameCount)++;
	}

}

void InitStage1BossAttack2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];

	*iFrameCount = IN_iParam0;
	*iFrameDesiredCount = IN_iParam1;
	*iCurrentAngle = 1200;
}

void Stage1BossAttack2(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];

	if ( ((GameBoss*)IN_Object)->bMuteki == true)
	{
		return;
	}

	if ( *iFrameCount >= *iFrameDesiredCount)
	{
		double fAngle = (double)(*iCurrentAngle) / 10.0;

		AddBullet (BULLET_TYPE5, 3, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, 2.0, 0.0);
		MakeMicroThread("Stage1BossAttack2MicroThread0", 0, 30, 0, 0, 0);

		*iCurrentAngle = Angle360(*iCurrentAngle - 150);

		*iFrameCount = 0;
	}
	else
	{
		(*iFrameCount)++;
	}

}

void InitStage1BossAttack2_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];

	*iFrameCount = IN_iParam0;
	*iFrameDesiredCount = IN_iParam1;
	*iCurrentAngle = 0;
}
void Stage1BossAttack2_1(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];

	if ( ((GameBoss*)IN_Object)->bMuteki == true)
	{
		return;
	}

	if ( *iFrameCount >= *iFrameDesiredCount)
	{
		double fAngle = (double)(*iCurrentAngle) / 10.0;

		int iQuantity = 15;
		double fAddAngle = (double)360 / (double)iQuantity;

		for (int i = 0; i < iQuantity; i++)
		{
			double fAngle = (double)((*iCurrentAngle) / 10) + (fAddAngle * (double)i);
			AddBullet (BULLET_TYPE6, 0, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, 2.3, 0.0);
		}

		*iCurrentAngle = Angle360(*iCurrentAngle + (int)(fAddAngle / 2.0) * 10);

		*iFrameCount = 0;
	}
	else
	{
		(*iFrameCount)++;
	}
}


void InitStage1BossAttack1MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iDone = &IN_iParameters[2];
	int * iAngle = &IN_iParameters[3];
	int * iSpeed = &IN_iParameters[4];

	*iFrameDesiredCount = IN_iParam0;
	*iFrameCount = 0;
	*iDone = 0;

	*iAngle = IN_iParam1;
	*iSpeed = IN_iParam2;
}

void Stage1BossAttack1MicroThread0(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iDone = &IN_iParameters[2];
	int * iAngle = &IN_iParameters[3];
	int * iSpeed = &IN_iParameters[4];

	if (*iDone == 0)
	{
		if (*iFrameCount >= *iFrameDesiredCount)
		{
			IN_Object->SetAngle ( (double)(*iAngle) / 10.0 );
			IN_Object->speed = (double)(*iSpeed) / 10.0;
			IN_Object->acc = 0.1;
			IN_Object->bMovable = true;
			*iDone = 1;
		}
		else
		{
			(*iFrameCount)++;
		}
	}

}

void InitStage1BossAttack1MicroThread1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iAngle = &IN_iParameters[2];
	int * iSpeed = &IN_iParameters[3];
	int * iSubAttackAddAngle = &IN_iParameters[4];

	*iFrameCount = IN_iParam0;
	*iFrameDesiredCount = IN_iParam1;
	*iAngle = IN_iParam2;
	*iSpeed = IN_iParam3;
	*iSubAttackAddAngle = IN_iParam4;
}
void Stage1BossAttack1MicroThread1(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iAngle = &IN_iParameters[2];
	int * iSpeed = &IN_iParameters[3];
	int * iSubAttackAddAngle = &IN_iParameters[4];

	if ( ((GameBullet*)IN_Object)->bGoTo == true)
	{
		return;
	}

	if (*iFrameCount >= *iFrameDesiredCount)
	{
		AddBullet(BULLET_TYPE17, 2, IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)(*iAngle) / 10.0, 0.0, (double)(*iSpeed) / 10.0, 0.0);
		AddBullet(BULLET_TYPE17, 8, IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)(*iAngle) / 10.0 + 180.0, 0.0, (double)(*iSpeed) / 10.0, 0.0);
		AddBullet(BULLET_TYPE17, 2, IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)(*iAngle) / 10.0 + 90, 0.0, (double)(*iSpeed) / 10.0, 0.0);
		AddBullet(BULLET_TYPE17, 8, IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)(*iAngle) / 10.0 + 270.0, 0.0, (double)(*iSpeed) / 10.0, 0.0);

		(*iAngle) += (*iSubAttackAddAngle);
		*iAngle = Angle360(*iAngle);
		*iFrameCount = 0;
	}
	else
	{
		(*iFrameCount)++;
	}
}

void InitStage1BossAttack1MicroThread2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * OriginX = &IN_iParameters[0]; 
	int * OriginY = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];
	int * iAngle = &IN_iParameters[3];
	int * iRadius = &IN_iParameters[4];
	int * iInited = &IN_iParameters[5];

	*OriginX = IN_iParam0;
	*OriginY = IN_iParam1;
	*iCurrentAngle = IN_iParam2;
	*iAngle = IN_iParam3;
	*iInited = 0;

}
void Stage1BossAttack1MicroThread2(GameObject * IN_Object, int * IN_iParameters)
{
	int * OriginX = &IN_iParameters[0]; 
	int * OriginY = &IN_iParameters[1];
	int * iCurrentAngle = &IN_iParameters[2];
	int * iAngle = &IN_iParameters[3];
	int * iRadius = &IN_iParameters[4];
	int * iInited = &IN_iParameters[5];

	double fOriginX = (double)(*OriginX) / 10.0;
	double fOriginY = (double)(*OriginY) / 10.0;
	double fCurrentAngle = (double)(*iCurrentAngle) / 10.0;
	double fAngle = (double)(*iAngle) / 10.0;

	if ( ((GameBullet*)IN_Object)->bGoTo == false)
	{
		if ( *iInited == 0)
		{
			*iRadius = (int)(GetDistance(fOriginX, fOriginY, IN_Object->x, IN_Object->y) * 10.0);
			*iInited = 1;
			((GameBullet*)IN_Object)->bMovable = false;
		}

		fCurrentAngle = Angle360 (fCurrentAngle - fAngle);
		
		double fRadius = (double)(*iRadius) / 10.0;

		IN_Object->x = fOriginX + GetXbyCos(GetRadian(fCurrentAngle), fRadius);
		IN_Object->y = fOriginY + GetYbySin(GetRadian(fCurrentAngle), fRadius);

		*iCurrentAngle = (int)(fCurrentAngle * 10.0);

	}

}



void InitStage1BossAttack2MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iDone = &IN_iParameters[2];

	*iFrameCount = IN_iParam0;
	*iFrameDesiredCount = IN_iParam1;

	*iDone = 0;
}
void Stage1BossAttack2MicroThread0(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iDone = &IN_iParameters[2];

	if ( *iFrameCount >= *iFrameDesiredCount)
	{
		if (*iDone == 0)
		{
			IN_Object->speed = 2.0;
			IN_Object->acc = 0.04;
//			IN_Object->addangle = -0.5;
			*iDone = 1;
		}
	}
	else
	{
		(*iFrameCount)++;
	}


}