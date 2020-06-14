//	SERIA : the SDL Wrapper (Sprite Engine with Refined Interface for Amusement)
//  (C) 2014 AXT Software.
//  http://www.axtsoft.co.kr/

#pragma once
#include "../MemoryLeakChecker.h"
#include "../SDL/include/SDL.h"
#include <string>

class ShooterObject
{
private:
	void * pObject;
	bool bLoaded;
public:
	ShooterObject();
	bool SetObject(void * IN_Object);
	void * GetObject();
	void SetLoaded(bool IN_Flag);
	bool GetLoaded();
};