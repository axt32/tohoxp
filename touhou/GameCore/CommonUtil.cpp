#include "CommonUtil.h"

void Shooter_DrawText(ShooterSprite * IN_Font, std::string IN_Text, double IN_x, double IN_y, int IN_RightAlignment)
{
	const char * pString = IN_Text.c_str();
	int iLength = IN_Text.length();

	int iX = (int)IN_x;
	int iY = (int)IN_y;

	int iWidth = IN_Font->GetWidth();
	int iHeight = IN_Font->GetHeight();


	if (IN_RightAlignment > 0)
	{
		iX = IN_x + iWidth * (IN_RightAlignment - iLength);
	}

	for (int i = 0; i < iLength; i++)
	{
		if (pString[i] >= 48 && pString[i] <= 57)		//0부터 9
		{
			IN_Font->DrawSprite( iX + iWidth * i, iY, pString[i] - 48);	
		}
		else if (pString[i] >= 65 && pString[i] <= 90)		//A부터 Z
		{
			IN_Font->DrawSprite( iX + iWidth * i, iY, pString[i] - 65 + 10);	
		}
		else if (pString[i] >= 97 && pString[i] <= 122)	//a부터 z
		{
			IN_Font->DrawSprite( iX + iWidth * i, iY, pString[i] - 97 + 10 + 26);	
		}
		else if (pString[i] >= 33 && pString[i] <= 47)		//!부터 /
		{
			IN_Font->DrawSprite(iX + iWidth * i, iY, pString[i] - 33 + 10 + 26 + 26);
		}
		else if (pString[i] >= 58 && pString[i] <= 64)		//:부터 @
		{
			IN_Font->DrawSprite(iX + iWidth * i, iY, pString[i] - 58 + 10 + 26 + 26 + 15);
		}
		else if (pString[i] >= 91 && pString[i] <= 95)		//[부터 _
		{
			IN_Font->DrawSprite(iX + iWidth * i, iY, pString[i] - 91 + 10 + 26 + 26 + 15 + 7);
		}
		else if (pString[i] >= 123 && pString[i] <= 126)	//{부터 ~
		{
			IN_Font->DrawSprite(iX + iWidth * i, iY, pString[i] - 123 + 10 + 26 + 26 + 15 + 7 + 5);
		}
		//공백 등의 기타 문자는 생략됨.
	}
}


double GetRadian(double IN_angle)
{
	return (fabs( IN_angle - 360.0 ) * (PI / 180.0));
//	return IN_angle * PI / 180;
}
double GetXbyCos(double IN_radian, double IN_x)
{

	return (IN_x * cos(IN_radian));

}

double GetYbySin(double IN_radian, double IN_y)
{

	return (IN_y * sin(IN_radian));

}

double GetAngle(GameObject * Obj1, GameObject * Obj2)
{
	//return GetAngle(Obj1->x + ( (double)(Obj1->GetSprite()->GetWidth()) / 2.0), Obj1->y + ( (double)(Obj1->GetSprite()->GetHeight() / 2.0)), Obj2->x + ( (double)(Obj2->GetSprite()->GetWidth() / 2.0)), Obj2->y + ( (double)(Obj2->GetSprite()->GetHeight() / 2.0)));
	return GetAngle(Obj1->x, Obj1->y, Obj2->x, Obj2->y);

}
double GetAngle(double IN_x1, double IN_y1, double IN_x2, double IN_y2)
{
	//double angle;
	//angle = atan2 (IN_y2 - IN_y1, IN_x2 - IN_x1) * 180.0 / PI;

	//if (IN_x1 == IN_x2 && IN_y1 > IN_y2)
	//	angle = 90.0;
	//else if (IN_x1 == IN_x2 && IN_y2 > IN_y1)
	//	angle = 270.0;
	//else if (IN_x2 > IN_x1 && IN_y2 > IN_y1)
	//	angle = 360.0 -angle;
	//else if (IN_x2 > IN_x1 && IN_y1 > IN_y2)
	//	angle = -angle;
	//else if (IN_x1 > IN_x2 && IN_y1 > IN_y2)
	//	angle =  -angle;
	//else if (IN_x1 > IN_x2 && IN_y2 > IN_y1)
	//	angle = 360 - angle;


	double angle;
	angle = atan2 ( -(IN_y2 - IN_y1), IN_x2 - IN_x1) * 180.0 / PI;

	if (angle < 0)
	{
		angle += 360.0;
	}

	return angle;
}

double GetDistance(double IN_x1, double IN_y1, double IN_x2, double IN_y2)
{
	double distance;
	distance = sqrt( pow((IN_x1 - IN_x2), 2) + pow((IN_y1 - IN_y2), 2) );

	return distance;
}

double GetDistance(GameObject * Obj1, GameObject * Obj2)
{
	return GetDistance(Obj1->x, Obj1->y, Obj2->x, Obj2->y);
}

bool Bezier3(double IN_x1, double IN_y1, 
	double IN_x2, double IN_y2, 
	double IN_x3, double IN_y3, 
	double mu,
	double * OUT_x, double * OUT_y)
{
	if ( !(mu >= 0.0 && mu <= 1.0))
	{
		return false;
	}
	
	double mum1, mum12, mu2;
	
	mu2 = mu * mu;
	mum1 = 1 - mu;
	mum12 = mum1 * mum1;
	*OUT_x = IN_x1 * mum12 + 2.0 * IN_x2 * mum1 * mu + IN_x3 * mu2;
	*OUT_y = IN_y1 * mum12 + 2.0 * IN_y2 * mum1 * mu + IN_y3 * mu2;

	return true;
}