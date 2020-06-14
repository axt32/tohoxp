#pragma once
#include "../MemoryLeakChecker.h"
#include "GameObject.h"
#include "HomingTargetList.h"

typedef enum	PLAYERSHOT_TYPE
{
	PLAYERSHOT_TYPE_NONE = 0,
	PLAYERSHOT_TYPE_REIMU_0,
	PLAYERSHOT_TYPE_REIMU_SUB_0,
	PLAYERSHOT_TYPE_REIMU_RAPIER_0,
	PLAYERSHOT_TYPE_REIMU_BOMBER,
	PLAYERSHOT_TYPE_MARISA_0,
	PLAYERSHOT_TYPE_MARISA_RAPIER_0,
	PLAYERSHOT_TYPE_MARISA_BOMBER,
	PLAYERSHOT_TYPE_REISEN_0,
	PLAYERSHOT_TYPE_REISEN_1,
	PLAYERSHOT_TYPE_REISEN_2,
	PLAYERSHOT_TYPE_REISEN_BOMBER
} PLAYERSHOT_TYPE;

class GamePlayerShot;
typedef void (*PlayerShotInit)(GamePlayerShot *, int, int, int, int, int);
typedef void (*PlayerShotFunc) (GamePlayerShot *);

class GamePlayerShot : public GameObject
{
private:
	void InitPlayerShot();
public:
	
	int iPlayerShotType;
	int iDamage;
	int iDamageToBoss;
	bool bIsBomber;
	
	PlayerShotInit pPlayerShotInit;
	PlayerShotFunc pPlayerShotFunc;
	int iPlayerShotParameters[10];

	bool bUsingHomingTargetIter;
	std::list<HomingTarget *>::iterator HomingTargetIter;

	bool bPassBullet;

	bool bFollowToPlayerMoving;

	GamePlayerShot();
	GamePlayerShot(PLAYERSHOT_TYPE IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, int IN_damage, CollisionModel IN_CollisionModel, double IN_CollisionRadius, bool IN_IsBomber = false);
	GamePlayerShot(GamePlayerShot& IN_PlayerShot);
	~GamePlayerShot();
};