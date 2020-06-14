#include "BarrageFunctions.h"

void MoveBoss(double IN_x, double IN_y)
{
	pBoss->speed = 2.0;
//	pBoss->acc = 0.2;
	pBoss->fDest_X = IN_x - (double)(pBoss->GetSprite()->GetWidth()) / 2.0 + (double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH;
	pBoss->fDest_Y = IN_y - (double)(pBoss->GetSprite()->GetHeight()) / 2.0 + (double)UI_WINDOW_TOP_Y + (double)UI_WINDOW_TOP_HEIGHT;
	pBoss->SetAngle(GetAngle(pBoss->x, pBoss->y, pBoss->fDest_X, pBoss->fDest_Y));
	pBoss->bGoTo = true;
	pBoss->bMovable = true;
}

void MoveBossToPrimaryLocation()
{
	MoveBoss((double)(UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + UI_WINDOW_RIGHT_X) / 2.0 - (double)(pBoss->GetSprite()->GetWidth()) / 2.0, 123.0);
}

void InitFourWingsFan(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iWing0 = &IN_iParameters[1];
	int * iWing1 = &IN_iParameters[2];
	int * iWing2 = &IN_iParameters[3];
	int * iWing3 = &IN_iParameters[4];
	int * iCurrentLaunchCount = &IN_iParameters[5];
	*iWing0 = 3500;
	*iWing1 = 800;
	*iWing2 = 1700;
	*iWing3 = 2600;
	*iCurrentLaunchCount = -10;

}
void FourWingsFan(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iWing0 = &IN_iParameters[1];
	int * iWing1 = &IN_iParameters[2];
	int * iWing2 = &IN_iParameters[3];
	int * iWing3 = &IN_iParameters[4];

	if (*iFrameCount == 10)
	{

		*iFrameCount = 0;

		int * iCurrentLaunchCount = &IN_iParameters[5];

		if (*iCurrentLaunchCount >= 0)
		{
			*iCurrentLaunchCount = 0;
			*iWing0 = Angle360(*iWing0 + 100);
			*iWing1 = Angle360(*iWing1 + 100);
			*iWing2 = Angle360(*iWing2 + 100);
			*iWing3 = Angle360(*iWing3 + 100);

		}
		else
		{
			*iCurrentLaunchCount = *iCurrentLaunchCount + 1;
		}

		auto Shot = [&] (int IN_Wing, int IN_SubType)
		{
			for (int i = 0; i <= 3; i++)
			{

				double fAngle = Angle360(((double)IN_Wing / (double)10.0) + ((double)3.3 * (double)i));

				double fRadian = GetRadian(fAngle);

				AddBullet(BULLET_TYPE17, IN_SubType, IN_Object->GetCenterX() + GetXbyCos(fRadian, 30.0), IN_Object->GetCenterY() + GetYbySin(fRadian, 30.0), fAngle, 0.0, 3.0, 0.0);

			}
		};

		Shot(*iWing0, 4);
		Shot(*iWing1, 8);
		Shot(*iWing2, 10);
		Shot(*iWing3, 13);

	}
	else
	{
		*iFrameCount = *iFrameCount + 1;
	}
}

void InitSixWingsAst(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredTime = &IN_iParameters[1];
	*iFrameCount = 4900;
	*iDesiredTime = 180;		//일단은 임시로.
}
void SixWingsAst(GameObject * IN_Object, int * IN_iParameters)
{
	int * iFrameCount = &IN_iParameters[0];
	int * iDesiredTime = &IN_iParameters[1];
	
	if (*iFrameCount == 5000)
	{

		double fRadius = 150.0;

		//일단 원부터
		for (int i = 0; i < 50; i++)
		{
			double fAngle = Angle360(((double) 360.0 / (double) 50) * i);
			double fRadian = GetRadian(fAngle);	
			//IN_Object->x, IN_Object->y 곱하기 나누기 10 해줘야한다. (일단 나중에 작업)
			double fDestX = IN_Object->x + GetXbyCos(fRadian, fRadius);
			double fDestY = IN_Object->y + GetYbySin(fRadian, fRadius);
			double fSpeed = GetDistance( IN_Object->x, IN_Object->y, fDestX, fDestY) / (double)(*iDesiredTime);
			AddBullet(BULLET_TYPE0, rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), fAngle, 0, fSpeed, 0);
			(*(GameBulletVector.end() - 1))->fDest_X = fDestX;
			(*(GameBulletVector.end() - 1))->fDest_Y = fDestY;
			(*(GameBulletVector.end() - 1))->bGoTo = true;
		}

		//삼각형 그리기
		double fAngle0 = Angle360( 90 );
		double fRadian0 = GetRadian(fAngle0);
		double fPointX0 = IN_Object->x + GetXbyCos(fRadian0, fRadius);
		double fPointY0 = IN_Object->y + GetYbySin(fRadian0, fRadius);

		double fAngle1 = Angle360( 330 );
		double fRadian1 = GetRadian(fAngle1);
		double fPointX1 = IN_Object->x + GetXbyCos(fRadian1, fRadius);
		double fPointY1 = IN_Object->y + GetYbySin(fRadian1, fRadius);	

		double fAngle2 = Angle360( 210 );
		double fRadian2 = GetRadian(fAngle2);
		double fPointX2 = IN_Object->x + GetXbyCos(fRadian2, fRadius);
		double fPointY2 = IN_Object->y + GetYbySin(fRadian2, fRadius);	


		double fAngle3 = Angle360( 30 );
		double fRadian3 = GetRadian(fAngle3);
		double fPointX3 = IN_Object->x + GetXbyCos(fRadian3, fRadius);
		double fPointY3 = IN_Object->y + GetYbySin(fRadian3, fRadius);

		double fAngle4 = Angle360( 150 );
		double fRadian4 = GetRadian(fAngle4);
		double fPointX4 = IN_Object->x + GetXbyCos(fRadian4, fRadius);
		double fPointY4 = IN_Object->y + GetYbySin(fRadian4, fRadius);	

		double fAngle5 = Angle360( 270 );
		double fRadian5 = GetRadian(fAngle5);
		double fPointX5 = IN_Object->x + GetXbyCos(fRadian5, fRadius);
		double fPointY5 = IN_Object->y + GetYbySin(fRadian5, fRadius);	


		double fEdgeLen = GetDistance(fPointX0, fPointY0, fPointX1, fPointY1);	
		double fEdgeDensity = fEdgeLen / 20;


		auto MakeEdge = [&] (double IN_fX0, double IN_fY0, double IN_fX1, double IN_fY1, int IN_iQuantity, int IN_iStartPlus, int IN_iEndMinus)
		{
			double fEdgeAngle = GetAngle(IN_fX0, IN_fY0, IN_fX1, IN_fY1);

			for (int i = 0 + IN_iStartPlus; i < IN_iQuantity - IN_iEndMinus; i++)
			{
				double fDestX = IN_fX0 + GetXbyCos(GetRadian(fEdgeAngle), fEdgeDensity * i);
				double fDestY = IN_fY0 + GetYbySin(GetRadian(fEdgeAngle), fEdgeDensity * i);

				double fSpeed = GetDistance(IN_Object->x, IN_Object->y, fDestX, fDestY) / (*iDesiredTime);

				AddBullet(BULLET_TYPE0, rand()%16, IN_Object->GetCenterX(), IN_Object->GetCenterY(), GetAngle( IN_Object->x - (double)(Spr_BulletType0.GetWidth()) / 2.0, IN_Object->y - (double)(Spr_BulletType0.GetHeight()) / 2.0, fDestX, fDestY), 0, fSpeed, 0);
				(*(GameBulletVector.end() - 1))->fDest_X = fDestX;
				(*(GameBulletVector.end() - 1))->fDest_Y = fDestY;
				(*(GameBulletVector.end() - 1))->bGoTo = true;				
			}
		};

		MakeEdge(fPointX0, fPointY0, fPointX1, fPointY1, 20, 0, 0);
		MakeEdge(fPointX1, fPointY1, fPointX2, fPointY2, 20, 1, 0);
		MakeEdge(fPointX2, fPointY2, fPointX0, fPointY0, 20, 1, -1);
		MakeEdge(fPointX3, fPointY3, fPointX4, fPointY4, 20, 0, 0);
		MakeEdge(fPointX4, fPointY4, fPointX5, fPointY5, 20, 1, 0);
		MakeEdge(fPointX5, fPointY5, fPointX3, fPointY3, 20, 1, -1);

		*iFrameCount = 0;
	}
	else
	{
		*iFrameCount = *iFrameCount + 1;
	}
}