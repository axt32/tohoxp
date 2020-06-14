#pragma once
#include "../MemoryLeakChecker.h"
#include "GameObject.h"

typedef enum ITEM_TYPE
{
	ITEM_NONE = 0,
	ITEM_BOMBER,
	ITEM_EXTEND,
	ITEM_POWERUP_BIG,
	ITEM_POWERUP_SMALL,
	ITEM_SCORE_BIG,
	ITEM_SCORE_SMALL
} ITEM_TYPE;

class GameItem : public GameObject
{
private:
	void InitItem(ITEM_TYPE IN_Type);
public:
	int iItemType;
	double OldSpeed;
	double FastSpeed;

	bool bAutoFollow;
	GameItem();
	GameItem(ShooterSprite * IN_Sprite, ITEM_TYPE IN_Type, int IN_FrameChangeInterval);
};