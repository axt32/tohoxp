#include "Angle360.h"

double Angle360(double IN_angle)
{
	double angle;
	if (IN_angle >= 360.0)
	{
		angle = IN_angle - 360.0;
	}
	else if (IN_angle < 0)
	{
		angle = IN_angle + 360.0;
	}
	else
	{
		angle = IN_angle;
	}	

//	printf ("%f\n", angle);
	return angle;
}

int Angle360(int IN_angle)
{
	int angle;
	if (IN_angle >= 3600)
	{
		angle = IN_angle - 3600;
	}
	else if (IN_angle < 0)
	{
		angle = IN_angle + 3600;
	}
	else
	{
		angle = IN_angle;
	}		
  	return angle;

}

int RoundInt(double IN_value)
{
	return (int)(IN_value + 0.5);
}