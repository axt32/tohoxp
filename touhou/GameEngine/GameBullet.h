#pragma once
#include "../MemoryLeakChecker.h"
#include "GameEnemyBullet.h"


class GameBullet : public GameEnemyBullet
{
private:
	void InitGameBullet();
public:
	GameBullet();
	GameBullet(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, bool IN_Movable = true);
	GameBullet(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable = true);
	~GameBullet();
};