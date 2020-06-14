#include "Sample.h"

void InitSample()
{
	//테스트
	RegisterBarrage("Sample", (BarrageFunctionInit)&InitSampleBarrage, (BarrageFunction)&SampleBarrage);
	RegisterBarrage("Sample2", (BarrageFunctionInit)&InitSampleBarrage2, (BarrageFunction)&SampleBarrage2);
	RegisterBarrage("Sample3", (BarrageFunctionInit)&InitSampleBarrage3, (BarrageFunction)&SampleBarrage3);

	RegisterBarrage("FourWingsFan", (BarrageFunctionInit)&InitFourWingsFan, (BarrageFunction)&FourWingsFan);
	RegisterBarrage("SixWingsAst", (BarrageFunctionInit)&InitSixWingsAst, (BarrageFunction)&SixWingsAst);

	//테스트 끝

//	AddEnemy("0:Type:2@0:Locate:123:124@120:Follow@120:Speed:1@2000:GoTo:0:0@0:BarrageName:0:0:0:Sample@1500:DetachBarrage");
//	AddEnemy("0:Type:2@0:Locate:361:124@120:Follow@120:Speed:1@2000:GoTo:0:0@0:BarrageName:0:0:0:Sample@1500:DetachBarrage");

	AddEnemy("0:Type:1@0:HP:200@0:Locate:218:200@0:BarrageName:0:0:0:0:0:SixWingsAst@0:BarrageName:0:0:0:0:0:Sample");
//	AddEnemy("0:Type:1@0:HP:100@0:Locate:123:124@120:GoTo:361:180@120:Speed:1.5");
//	AddEnemy("0:Type:2@0:HP:200@0:Locate:361:124@120:GoTo:123:333@120:Speed:1.5@0:BarrageName:0:0:0:Sample2");
//	AddEnemy("0:Type:3@0:HP:100@0:Locate:222:222@0:BarrageName:0:0:0:Sample3");
//	AddEnemy("0:Type:3@0:HP:100@0:Speed:1.0@0:Follow:0@0:BarrageName:0:0:0:Sample3@0:Locate:0:0");

//	AddEnemy("0:Type:3@0:HP:100@0:Speed:1.0@0:Locate:0:0@0:GoTo:999:999");


	//for (int i = 0; i < 30; i++)
	//{
	//	AddEnemy("0:Type:3@0:HP:100@0:Locate:99:99");
	//}
}

void InitSampleBarrage(int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	IN_iParameters[0] = iGameFrame;
	IN_iParameters[1] = 0;
	srand(time(NULL));
}

void SampleBarrage(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iOldTime = &IN_iParameters[0];
	int * iCurrentAngle1 = &IN_iParameters[1];

	if (iGameFrame - *iOldTime >= 50)
	{

		if (*iCurrentAngle1 == 360)
		{
			*iCurrentAngle1 = 0;
		}

		*iCurrentAngle1 = *iCurrentAngle1 + 3;
		
		for (int i = *iCurrentAngle1; i < *iCurrentAngle1 + 360; i = i + 10)
		{
			double fSpeed = (rand()%4) / 10.0 + 1.0;

			int iType = BULLET_TYPE0 + rand()%19;
			int iSubType = 0;

			iType = BULLET_TYPE3;

			if (iType == BULLET_TYPE18)
			{
				iSubType = rand()%4;
			}
			else if (iType == BULLET_TYPE6 || iType == BULLET_TYPE7 || iType == BULLET_TYPE8 || iType == BULLET_TYPE9 ||
				iType == BULLET_TYPE12 || iType == BULLET_TYPE15)
			{
				iSubType = rand()%8;
			}
			else if (iType == BULLET_TYPE11)
			{
				iSubType = rand()%10;
			}
			else
			{
				iSubType = rand()%16;
			}


			
			AddBullet((ENEMYBULLET_TYPE)(iType), (ENEMYBULLET_TYPE)(iSubType), IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)i, 0.0, fSpeed, 0.0);

		}

		//int iType = BULLET_TYPE0 + rand()%5;
		//double fSpeed = (rand()%40) / 10.0 + 1.0;
		//*iCurrentAngle1 = GetAngle(IN_iParam0, IN_iParam1, Player.GetCenterX(), Player.GetCenterY()) - 30.0 + rand()%60;

		//AddBullet((ENEMYBULLET_TYPE)(iType), rand()%16, IN_iParam0, IN_iParam1, *iCurrentAngle1, 0.0, fSpeed, 0.0);


	*iOldTime = iGameFrame;		

	}
}

void InitSampleBarrage2(int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	IN_iParameters[0] = iGameFrame;
	IN_iParameters[1] = 0;
		IN_iParameters[2] = 0;
	srand(time(NULL));
}

void SampleBarrage2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iOldTime = &IN_iParameters[0];
	int * iCurrentAngle1 = &IN_iParameters[1];
	int * iCurrentAngle2 = &IN_iParameters[2];

	if (iGameFrame - *iOldTime >= 30)
	{

		//시계
		if (*iCurrentAngle1 == 0)
		{
			*iCurrentAngle1 = 360;
		}
		*iCurrentAngle1 = *iCurrentAngle1 - 10;

		//반시계
		if (*iCurrentAngle2 == 360)
		{
			*iCurrentAngle2 = 0;
		}
		*iCurrentAngle2 = *iCurrentAngle2 + 10;

		double fSpeed = (rand()%3) / 10.0 + 0.1;
//		double fSpeed = 1.0;
		int iType = BULLET_TYPE0 + rand()%5;
		AddBullet((ENEMYBULLET_TYPE)(iType), rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)*iCurrentAngle1, -1.0, fSpeed, 0.05);

		fSpeed = (rand()%3) / 10.0 + 0.1;
		//fSpeed = 1.0;
		iType = BULLET_TYPE0 + rand()%5;
		AddBullet((ENEMYBULLET_TYPE)(iType), rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), (double)*iCurrentAngle2, +1.0, fSpeed, 0.05);
		*iOldTime = iGameFrame;		

	}
}

void InitSampleBarrage3(int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	IN_iParameters[0] = iGameFrame;
	IN_iParameters[1] = 0;
	srand(time(NULL));
}

void SampleBarrage3(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iOldTime = &IN_iParameters[0];

	if (iGameFrame - *iOldTime >= 30)
	{
		double fSpeed = 1.0;
		int iType = BULLET_TYPE4;
		double fAngle = GetAngle((double)IN_iParam0 / 10.0, (double)IN_iParam1 / 10.0, Player.GetCenterX(), Player.GetCenterY());

		AddBullet((ENEMYBULLET_TYPE) BULLET_TYPE3, rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0.0, fSpeed, 0.04);

		*iOldTime = iGameFrame;		

	}
}