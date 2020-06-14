#include "Barrage_Stage2Field.h"

void InitZakouAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iSubFrameCount = &IN_iParameters[2];
	int * iDesiredSubFrameCount = &IN_iParameters[3];
	int * iShotCount = &IN_iParameters[4];
	int * iDesiredShotCount = &IN_iParameters[5];

	*iDesiredFrameCount = IN_iParam0;
	*iFrameCount = *iDesiredFrameCount;
	*iDesiredSubFrameCount = IN_iParam1;
	*iSubFrameCount = *iDesiredSubFrameCount;
	*iDesiredShotCount = IN_iParam2;
	*iShotCount = 0;

}
void ZakouAttack0(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iSubFrameCount = &IN_iParameters[2];
	int * iDesiredSubFrameCount = &IN_iParameters[3];
	int * iShotCount = &IN_iParameters[4];
	int * iDesiredShotCount = &IN_iParameters[5];

	auto Shot = [&]
	{
		for (int i = 0; i < 5; i++)
		{
			AddBullet(BULLET_TYPE0, 4,
				IN_Object->GetCenterX() - (double)(Spr_BulletType0.GetWidth()) + rand() % (Spr_BulletType0.GetWidth() * 2), 
				IN_Object->GetCenterY() - (double)(Spr_BulletType0.GetWidth()) + rand() % (Spr_BulletType0.GetHeight() * 2),
				GetAngle(IN_Object, &Player), 0, 2.0 + (double)(rand()%10) / 10.0, 0);
		}
	};

	if (*iFrameCount == *iDesiredFrameCount)
	{
		if ( *iSubFrameCount == *iDesiredSubFrameCount)
		{

			if (*iShotCount == *iDesiredShotCount)
			{
				*iShotCount = 0;
				*iFrameCount = 0;
			}
			else
			{
				Shot();

				(*iShotCount)++;

			}

			*iSubFrameCount = 0;
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

void InitZakouAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iSubFrameCount = &IN_iParameters[4];
	int * iDesiredSubFrameCount = &IN_iParameters[5];
	int * iShotCount = &IN_iParameters[6];
	int * iDesiredShotCount = &IN_iParameters[7];
	int * iTargetAngle = &IN_iParameters[8];

	*iDesiredFrameCount = IN_iParam0;
	*iFrameCount = *iDesiredFrameCount;
	*iBulletSubType = IN_iParam1;	//-1ÀÌ¸é ·£´ý
	*iBulletSpeed = IN_iParam2;	// X10
	*iDesiredSubFrameCount = IN_iParam3;
	*iSubFrameCount = *iDesiredSubFrameCount;
	*iDesiredShotCount = IN_iParam4;
	*iShotCount = *iDesiredShotCount;
	*iTargetAngle = 0;	//X10

	if (*iBulletSubType == -1)
	{
		*iBulletSubType = rand()%16;
	}

}
void ZakouAttack1(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iSubFrameCount = &IN_iParameters[4];
	int * iDesiredSubFrameCount = &IN_iParameters[5];
	int * iShotCount = &IN_iParameters[6];
	int * iDesiredShotCount = &IN_iParameters[7];
	int * iTargetAngle = &IN_iParameters[8];

	auto Shot = [&]
	{
		double fSpeed = (double)(*iBulletSpeed) / 10.0;
		double fAngle = (double)(*iTargetAngle) / 10.0;
		AddBullet(BULLET_TYPE2, *iBulletSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, fSpeed, 0.0);


		//printf ("%d, %f\n", *iShotCount, fSpeed);
	};

	if (*iFrameCount == *iDesiredFrameCount)
	{
		if ( *iSubFrameCount == *iDesiredSubFrameCount)
		{

			if (*iShotCount == *iDesiredShotCount)
			{
				IN_Object->bMovable = true;
				*iShotCount = 0;
				*iFrameCount = 0;
			}
			else
			{
				if (*iShotCount == 0)
				{
					IN_Object->bMovable = false;
					*iTargetAngle = (int)(GetAngle(IN_Object, &Player) * 10.0);
				}

				Shot();
				(*iShotCount)++;
			}

			*iSubFrameCount = 0;
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

void InitZakouAttack2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredCount = &IN_iParameters[1];
	int * iCurrentShotCount = &IN_iParameters[2];
	int * iQuantity = &IN_iParameters[3];

	*iDesiredCount = IN_iParam0;
	*iFrameCount = *iDesiredCount;
	*iCurrentShotCount = 0;
	*iQuantity = IN_iParam1;
}
void ZakouAttack2(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredCount = &IN_iParameters[1];
	int * iCurrentShotCount = &IN_iParameters[2];
	int * iQuantity = &IN_iParameters[3];

	if (IN_Object->bMovable == false)
	{
		if ( *iFrameCount == *iDesiredCount)
		{
			int iType = rand()%16;
			double fAngle = GetAngle(IN_Object->GetCenterX(), IN_Object->GetCenterY(), Player.GetCenterX(), Player.GetCenterY()) - 45.0 + (double)(rand()%90);
			double fSpeed = (double)(rand()%20) / 10.0 + 1.0;
			AddBullet(BULLET_TYPE5, iType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, fSpeed, 0.0);

			(*iCurrentShotCount)++;
			if (*iCurrentShotCount == *iQuantity)
			{
				*iCurrentShotCount = 0;
				*iFrameCount = 0;
			}
		}
		else
		{
			(*iFrameCount)++;
		}
	}

}

void InitZakouAttack3(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iSubFrameCount = &IN_iParameters[4];
	int * iDesiredSubFrameCount = &IN_iParameters[5];
	int * iShotCount = &IN_iParameters[6];
	int * iDesiredShotCount = &IN_iParameters[7];
	int * iTargetAngle = &IN_iParameters[8];

	*iDesiredFrameCount = IN_iParam0;
	*iFrameCount = *iDesiredFrameCount;
	*iBulletSubType = IN_iParam1;	//-1ÀÌ¸é ·£´ý
	*iBulletSpeed = IN_iParam2;	// X10
	*iDesiredSubFrameCount = IN_iParam3;
	*iSubFrameCount = *iDesiredSubFrameCount;
	*iDesiredShotCount = IN_iParam4;
	*iShotCount = *iDesiredShotCount;
	*iTargetAngle = 0;	//X10

	if (*iBulletSubType == -1)
	{
		*iBulletSubType = rand()%16;
	}

}
void ZakouAttack3(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iSubFrameCount = &IN_iParameters[4];
	int * iDesiredSubFrameCount = &IN_iParameters[5];
	int * iShotCount = &IN_iParameters[6];
	int * iDesiredShotCount = &IN_iParameters[7];
	int * iTargetAngle = &IN_iParameters[8];

	auto Shot = [&]
	{
		double fSpeed = (double)(*iBulletSpeed) / 10.0;
		double fAngle = (double)(*iTargetAngle) / 10.0;

		int iQuantity = 20;
		double fAngleAdd = 360.0 / (double)(iQuantity);

		for (int i = 0; i < iQuantity; i++)
		{
			AddBullet(BULLET_TYPE2, *iBulletSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle + fAngleAdd * (double)i, 0.0, fSpeed, 0.0);
		}

		fAngle = Angle360(fAngle + fAngleAdd / 2.0);
		*iTargetAngle = (int)(fAngle * 10.0);
	};

	if (*iFrameCount == *iDesiredFrameCount)
	{
		if ( *iSubFrameCount == *iDesiredSubFrameCount)
		{

			if (*iShotCount == *iDesiredShotCount)
			{
				IN_Object->bMovable = true;
				*iShotCount = 0;
				*iFrameCount = 0;
			}
			else
			{
				if (*iShotCount == 0)
				{
					IN_Object->bMovable = false;
					*iTargetAngle = (int)(GetAngle(IN_Object, &Player) * 10.0);
				}

				Shot();
				(*iShotCount)++;
			}

			*iSubFrameCount = 0;
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

void InitZakouAttack4(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iSubFrameCount = &IN_iParameters[4];
	int * iDesiredSubFrameCount = &IN_iParameters[5];
	int * iShotCount = &IN_iParameters[6];
	int * iDesiredShotCount = &IN_iParameters[7];
	int * iTargetAngle = &IN_iParameters[8];

	*iDesiredFrameCount = IN_iParam0;
	*iFrameCount = *iDesiredFrameCount;
	*iBulletSubType = IN_iParam1;	//-1ÀÌ¸é ·£´ý
	*iBulletSpeed = IN_iParam2;	// X10
	*iDesiredSubFrameCount = IN_iParam3;
	*iSubFrameCount = *iDesiredSubFrameCount;
	*iDesiredShotCount = IN_iParam4;
	*iShotCount = *iDesiredShotCount;
	*iTargetAngle = 0;	//X10

	if (*iBulletSubType == -1)
	{
		*iBulletSubType = rand()%16;
	}

}
void ZakouAttack4(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iSubFrameCount = &IN_iParameters[4];
	int * iDesiredSubFrameCount = &IN_iParameters[5];
	int * iShotCount = &IN_iParameters[6];
	int * iDesiredShotCount = &IN_iParameters[7];
	int * iTargetAngle = &IN_iParameters[8];

	auto Shot = [&]
	{
		double fSpeed = (double)(*iBulletSpeed) / 10.0;
		double fAngle = (double)(*iTargetAngle) / 10.0;
		AddBullet(BULLET_TYPE5, *iBulletSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle - 5.0, 0.0, fSpeed, 0.0);
		AddBullet(BULLET_TYPE5, *iBulletSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, fSpeed, 0.0);
		AddBullet(BULLET_TYPE5, *iBulletSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle + 5.0, 0.0, fSpeed, 0.0);

		//printf ("%d, %f\n", *iShotCount, fSpeed);
	};

	if (*iFrameCount == *iDesiredFrameCount)
	{
		if ( *iSubFrameCount == *iDesiredSubFrameCount)
		{

			if (*iShotCount == *iDesiredShotCount)
			{
				IN_Object->bMovable = true;
				*iShotCount = 0;
				*iFrameCount = 0;
			}
			else
			{
				if (*iShotCount == 0)
				{
					IN_Object->bMovable = false;
					*iTargetAngle = (int)(GetAngle(IN_Object, &Player) * 10.0);
				}

				Shot();
				(*iShotCount)++;
			}

			*iSubFrameCount = 0;
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

void InitZakouAttack5(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredCount = &IN_iParameters[1];
	int * iSubType = &IN_iParameters[2];
	int * iEdges = &IN_iParameters[3];
	int * iSpeed = &IN_iParameters[4];
	int * iTargetAngle = &IN_iParameters[5];
	int * iAngleAdd = &IN_iParameters[6];
	int * iInited = &IN_iParameters[7];


	*iDesiredCount = IN_iParam0;
	*iFrameCount = *iDesiredCount;
	*iSubType = IN_iParam1;
	*iEdges = IN_iParam2;
	*iSpeed = IN_iParam3;		//X10
	*iTargetAngle = 0;
	*iAngleAdd = IN_iParam4;		//X10
	*iInited = 0;

	if (*iSubType == -1)
	{
		*iSubType = rand() % 16;
	}

}
void ZakouAttack5(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredCount = &IN_iParameters[1];
	int * iSubType = &IN_iParameters[2];
	int * iEdges = &IN_iParameters[3];
	int * iSpeed = &IN_iParameters[4];
	int * iTargetAngle = &IN_iParameters[5];
	int * iAngleAdd = &IN_iParameters[6];
	int * iInited = &IN_iParameters[7];

	if ( *iFrameCount == *iDesiredCount)
	{
		if (*iInited == 0)
		{
			*iTargetAngle = (int)(GetAngle(IN_Object, &Player) * 10.0);
			*iInited = 1;
		}

		double fAngle = (double)(*iTargetAngle) / 10.0;
		double fAngleAdd = 360.0 / (double)(*iEdges);
		double fSpeed = (double)(*iSpeed) / 10.0;

		for (int i = 0; i < *iEdges; i++)
		{
			AddBullet(BULLET_TYPE3, *iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle + fAngleAdd * (double)i, 0.0, fSpeed, 0.0);
		}

		double fAngleAddNext = (double)(*iAngleAdd) / 10.0;
		fAngle = Angle360(fAngle + fAngleAddNext);
		*iTargetAngle = (int)(fAngle * 10.0);

		*iFrameCount = 0;

	}
	else
	{
		(*iFrameCount)++;
	}

}

void InitZakouAttack6(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredCount = &IN_iParameters[1];
	int * iSubType = &IN_iParameters[2];
	int * iSpeed = &IN_iParameters[3];
	int * iTargetAngle = &IN_iParameters[4];
	int * iInited = &IN_iParameters[5];


	*iDesiredCount = IN_iParam0;
	*iFrameCount = *iDesiredCount;
	*iSubType = IN_iParam1;
	*iSpeed = IN_iParam2;		//X10
	*iTargetAngle = 0;		//X10
	*iInited = 0;

}
void ZakouAttack6(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredCount = &IN_iParameters[1];
	int * iSubType = &IN_iParameters[2];
	int * iSpeed = &IN_iParameters[3];
	int * iTargetAngle = &IN_iParameters[4];
	int * iInited = &IN_iParameters[5];

	if ( *iFrameCount == *iDesiredCount)
	{
		if (*iInited == 0)
		{
			*iTargetAngle = (int)(GetAngle(IN_Object, &Player) * 10.0);
			*iInited = 1;
		}

		int MySubType;
		if (*iSubType == -1)
		{
			MySubType = rand() % 16;
		}
		else
		{
			MySubType = *iSubType;
		}

		double fAngle = (double)(*iTargetAngle) / 10.0 - 30.0 + (double)(rand() % 60);

		double fSpeed;

		if (*iSpeed == -1)
		{
			fSpeed = 1.5 + (double)(rand() % 30) / 10.0;				
		}
		else
		{
			fSpeed	= (double)(*iSpeed) / 10.0;

		}
		AddBullet(BULLET_TYPE1, MySubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, fSpeed, 0.0);


		*iFrameCount = 0;

	}
	else
	{
		(*iFrameCount)++;
	}

}

void InitZakouAttack7(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iSubFrameCount = &IN_iParameters[4];
	int * iDesiredSubFrameCount = &IN_iParameters[5];
	int * iShotCount = &IN_iParameters[6];
	int * iDesiredShotCount = &IN_iParameters[7];
	int * iTargetAngle = &IN_iParameters[8];

	*iDesiredFrameCount = IN_iParam0;
	*iFrameCount = *iDesiredFrameCount;
	*iBulletSubType = IN_iParam1;	//-1ÀÌ¸é ·£´ý
	*iBulletSpeed = IN_iParam2;	// X10
	*iDesiredSubFrameCount = IN_iParam3;
	*iSubFrameCount = *iDesiredSubFrameCount;
	*iDesiredShotCount = IN_iParam4;
	*iShotCount = *iDesiredShotCount;
	*iTargetAngle = 0;	//X10

	if (*iBulletSubType == -1)
	{
		*iBulletSubType = rand()%8;
	}

}
void ZakouAttack7(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iSubFrameCount = &IN_iParameters[4];
	int * iDesiredSubFrameCount = &IN_iParameters[5];
	int * iShotCount = &IN_iParameters[6];
	int * iDesiredShotCount = &IN_iParameters[7];
	int * iTargetAngle = &IN_iParameters[8];

	auto Shot = [&]
	{
		double fSpeed = (double)(*iBulletSpeed) / 10.0;
		double fAngle = (double)(*iTargetAngle) / 10.0;

		int iQuantity = 20;
		double fAngleAdd = 360.0 / (double)(iQuantity);

		for (int i = 0; i < iQuantity; i++)
		{
			AddBullet(BULLET_TYPE16, *iBulletSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle + fAngleAdd * (double)i, 0.0, fSpeed, 0.0);
			MakeMicroThread("ZakouAttack7MicroThread0", 50, 13, 0, 0, 0);
		}

		fAngle = Angle360(fAngle + fAngleAdd / 2.0);
		*iTargetAngle = (int)(fAngle * 10.0);
	};

	if (*iFrameCount == *iDesiredFrameCount)
	{
		if ( *iSubFrameCount == *iDesiredSubFrameCount)
		{

			if (*iShotCount == *iDesiredShotCount)
			{
				IN_Object->bMovable = true;
				*iShotCount = 0;
				*iFrameCount = 0;
			}
			else
			{
				if (*iShotCount == 0)
				{
					IN_Object->bMovable = false;
					*iTargetAngle = (int)(GetAngle(IN_Object, &Player) * 10.0);
				}

				Shot();
				(*iShotCount)++;
			}

			*iSubFrameCount = 0;
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


void InitZakouAttack8(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iDesiredShotCount = &IN_iParameters[4];

	*iDesiredFrameCount = IN_iParam0;
	*iFrameCount = *iDesiredFrameCount;
	*iBulletSubType = IN_iParam1;	//-1ÀÌ¸é ·£´ý
	*iBulletSpeed = IN_iParam2;	// X10
	*iDesiredShotCount = IN_iParam3;

}
void ZakouAttack8(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iDesiredShotCount = &IN_iParameters[4];

	auto Shot = [&]
	{
		double fSpeed = (double)(*iBulletSpeed) / 10.0;

		int iQuantity = *iDesiredShotCount;
		double fAngleAdd = 360.0 / (double)(iQuantity);

		for (int i = 0; i < iQuantity; i++)
		{
			int iSubType;
			if ( *iBulletSubType == -1)
			{
				iSubType = rand() % 8;
			}
			else
			{
				iSubType = *iBulletSubType;
			}
			AddBullet(BULLET_TYPE7, iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngleAdd * (double)i, 0.0, fSpeed, 0.0);
			MakeMicroThread("ZakouAttack8MicroThread0", 30, 0, 0, 0, 0);
		}

	};

	if (IN_Object->bMovable == true)
	{
		if (*iFrameCount == *iDesiredFrameCount)
		{
			Shot();
			*iFrameCount = 0;
		}
		else
		{
			(*iFrameCount)++;
		}
	}

}

void InitZakouAttack9(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];

	*iDesiredFrameCount = IN_iParam0;
	*iFrameCount = *iDesiredFrameCount;
	*iBulletSubType = IN_iParam1;	//-1ÀÌ¸é ·£´ý
	*iBulletSpeed = IN_iParam2;	// X10

}
void ZakouAttack9(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];

	auto Shot = [&]
	{
		double fSpeed = (double)(*iBulletSpeed) / 10.0;
		int iSubType;
		if ( *iBulletSubType == -1)
		{
			iSubType = rand() % 16;
		}
		else
		{
			iSubType = *iBulletSubType;
		}
		AddBullet(BULLET_TYPE0, iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), GetAngle(IN_Object, &Player), 0.0, fSpeed, 0.0);
	};

	if (IN_Object->bMovable == true)
	{
		if (*iFrameCount == *iDesiredFrameCount)
		{
			Shot();
			*iFrameCount = 0;
		}
		else
		{
			(*iFrameCount)++;
		}
	}

}


void InitZakouAttack10(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iDesiredShotCount = &IN_iParameters[4];
	int * iEnableMovingShot = &IN_iParameters[5];

	*iDesiredFrameCount = IN_iParam0;
	*iFrameCount = *iDesiredFrameCount;
	*iBulletSubType = IN_iParam1;	//-1ÀÌ¸é ·£´ý
	*iBulletSpeed = IN_iParam2;		//X10
	*iDesiredShotCount = IN_iParam3;
	*iEnableMovingShot = IN_iParam4;

}
void ZakouAttack10(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredFrameCount = &IN_iParameters[1];
	int * iBulletSubType = &IN_iParameters[2];
	int * iBulletSpeed = &IN_iParameters[3];
	int * iDesiredShotCount = &IN_iParameters[4];
	int * iEnableMovingShot = &IN_iParameters[5];

	auto Shot = [&]
	{
		double fSpeed = (double)(*iBulletSpeed) / 10.0;

		int iQuantity = *iDesiredShotCount;

		for (int i = 0; i < iQuantity; i++)
		{
			double fAngle = (double)(rand()%360);
			int iSubType;
			if ( *iBulletSubType == -1)
			{
				iSubType = rand() % 8;
			}
			else
			{
				iSubType = *iBulletSubType;
			}
			AddBullet(BULLET_TYPE10, iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, fSpeed, 0.0);
		}

	};

	if (IN_Object->bMovable == false || *iEnableMovingShot == 1)
	{
		if (*iFrameCount == *iDesiredFrameCount)
		{
			Shot();
			*iFrameCount = 0;
		}
		else
		{
			(*iFrameCount)++;
		}
	}

}


void InitZakouAttack7MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iDesiredBulletSpeed = &IN_iParameters[2];
	int * iDone = &IN_iParameters[3];

	*iFrameCount = 0;
	*iFrameDesiredCount = IN_iParam0;
	*iDesiredBulletSpeed = IN_iParam1;
	*iDone = 0;

}

void ZakouAttack7MicroThread0(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iDesiredBulletSpeed = &IN_iParameters[2];
	int * iDone = &IN_iParameters[3];

	if (*iDone == 0)
	{
		if ( *iFrameCount >= *iFrameDesiredCount)
		{
			double fSpeed = (*iDesiredBulletSpeed) / 10.0;
			IN_Object->speed = fSpeed;
			*iDone = 1;
		}
		else
		{
			(*iFrameCount)++;
		}
	}

}

void InitZakouAttack8MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iDone = &IN_iParameters[2];

	*iFrameCount = 0;
	*iFrameDesiredCount = IN_iParam0;
	*iDone = 0;

}

void ZakouAttack8MicroThread0(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iFrameDesiredCount = &IN_iParameters[1];
	int * iDone = &IN_iParameters[2];

	if (*iDone == 0)
	{
		if ( *iFrameCount >= *iFrameDesiredCount)
		{
			IN_Object->SetAngle(GetAngle(IN_Object, &Player));
			*iDone = 1;
		}
		else
		{
			(*iFrameCount)++;
		}
	}

}
