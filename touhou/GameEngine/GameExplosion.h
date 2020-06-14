#pragma once
#include "../MemoryLeakChecker.h"
#include "GameObject.h"

class GameExplosion : public GameObject
{
private:
	void InitExplosion();
public:
	bool bStarted;
	bool bPlayerExplosion;
	GameExplosion();
	GameExplosion(ShooterSprite * IN_Sprite, int IN_FrameChangeInterval);
};