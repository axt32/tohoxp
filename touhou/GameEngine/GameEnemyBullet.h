#pragma once
#include "../MemoryLeakChecker.h"
#include "GameObject.h"
#include "GameBarrage.h"
#include <vector>

typedef enum	ENEMYBULLET_TYPE
{
	ENEMYBULLET_TYPE_NONE = 0,
	ENEMY_TYPE0,
	ENEMY_TYPE1,
	ENEMY_TYPE2,
	ENEMY_TYPE3,
	ENEMY_TYPE4,
	ENEMY_TYPE5,
	ENEMY_BOSS,
	BULLET_TYPE0,
	BULLET_TYPE1,
	BULLET_TYPE2,
	BULLET_TYPE3,
	BULLET_TYPE4,
	BULLET_TYPE5,
	BULLET_TYPE6,
	BULLET_TYPE7,
	BULLET_TYPE8,
	BULLET_TYPE9,
	BULLET_TYPE10,
	BULLET_TYPE11,
	BULLET_TYPE12,
	BULLET_TYPE13,
	BULLET_TYPE14,
	BULLET_TYPE15,
	BULLET_TYPE16,
	BULLET_TYPE17,
	BULLET_TYPE18,

} ENEMYBULLET_TYPE;

class GameEnemyBullet : public GameObject
{
private:
	void InitGameEnemyBullet(ENEMYBULLET_TYPE IN_Type);

public:
	int iEnemyBulletType;


	std::vector<GameBarrage *> pvBarrage;

//	void AddEnemyCommand(std::string IN_Type, char IN_param1, char IN_param2, char IN_param3, char IN_param4);
	GameEnemyBullet();
	~GameEnemyBullet();
	GameEnemyBullet(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, bool IN_Movable = true);
	GameEnemyBullet(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable = true);
};