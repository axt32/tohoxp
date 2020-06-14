#include "Barrage_Stage1Field.h"

void  InitStage1ZakouAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
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
void  Stage1ZakouAttack0(GameObject * IN_Object, int * IN_iParameters)
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

		int iQuantity = 5;
		double fAngleAdd = 360.0 / (double)(iQuantity);

		for (int i = 0; i < iQuantity; i++)
		{
			AddBullet(BULLET_TYPE1, *iBulletSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle + fAngleAdd * (double)i, 0.0, fSpeed, 0.0);
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




void InitStage1ZakouAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
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
void Stage1ZakouAttack1(GameObject * IN_Object, int * IN_iParameters)
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
		AddBullet(BULLET_TYPE3, iSubType, IN_Object->GetCenterX(), IN_Object->GetCenterY(), GetAngle(IN_Object, &Player), 0.0, fSpeed, 0.0);
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