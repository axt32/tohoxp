#pragma once
#include "../MemoryLeakChecker.h"
#include "../SDL/include/SDL.h"

class ShooterRect
{
private:
	SDL_Rect MyRect;
public:
	ShooterRect();
	ShooterRect(int IN_x, int IN_y);
	ShooterRect(int IN_x, int IN_y, int IN_w, int IN_h);
	void Set_X(int IN_x);
	void Set_Y(int IN_y);
	void Set_W(int IN_w);
	void Set_H(int IN_h);
	int Get_X();
	int Get_Y();
	int Get_W();
	int Get_H();
	SDL_Rect * GetRect();
	bool CheckSame(ShooterRect * IN_Rect);
	void Duplicate(ShooterRect * OUT_Rect);
};