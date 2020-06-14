#include "ShooterRect.h"

ShooterRect :: ShooterRect()
{
	MyRect.x = 0;
	MyRect.y = 0;
	MyRect.w = 0;
	MyRect.h = 0;
}

ShooterRect :: ShooterRect(int IN_x, int IN_y)
{
	MyRect.x = IN_x;
	MyRect.y = IN_y;
}
ShooterRect :: ShooterRect(int IN_x, int IN_y, int IN_w, int IN_h)
{
	MyRect.x = IN_x;
	MyRect.y = IN_y;
	MyRect.w = IN_w;
	MyRect.h = IN_h;
}

void ShooterRect :: Set_X(int IN_x)
{
	MyRect.x = IN_x;
}
void ShooterRect :: Set_Y(int IN_y)
{
	MyRect.y = IN_y;
}
void ShooterRect :: Set_W(int IN_w)
{
	MyRect.w = IN_w;
}
void ShooterRect :: Set_H(int IN_h)
{
	MyRect.h = IN_h;
}
int ShooterRect :: Get_X()
{
	return MyRect.x;
}
int ShooterRect :: Get_Y()
{
	return MyRect.y;
}
int ShooterRect :: Get_W()
{
	return MyRect.w;
}
int ShooterRect :: Get_H()
{
	return MyRect.h;
}

SDL_Rect * ShooterRect :: GetRect()
{
	return &MyRect;
}
bool ShooterRect :: CheckSame(ShooterRect * IN_Rect)
{
	return ( (IN_Rect->Get_X() == MyRect.x) & (IN_Rect->Get_Y() == MyRect.y) 
		& (IN_Rect->Get_W() == MyRect.w) & (IN_Rect->Get_H() == MyRect.h) );
		
}
void ShooterRect :: Duplicate(ShooterRect * OUT_Rect)
{
	OUT_Rect->Set_X(Get_X());
	OUT_Rect->Set_Y(Get_Y());
	OUT_Rect->Set_W(Get_W());
	OUT_Rect->Set_H(Get_H());
}