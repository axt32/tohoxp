#pragma once
#include "../MemoryLeakChecker.h"
#include "GameObject.h"

class GamePlayerHeatBox : public GameObject
{
private:
	void InitPlayerHeatBox();
public:
	GamePlayerHeatBox();
	GamePlayerHeatBox(ShooterSprite * IN_Sprite);
	~GamePlayerHeatBox();
};