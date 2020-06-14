#include "GameItem.h"

void GameItem :: InitItem(ITEM_TYPE IN_Type)
{	
	iItemType = IN_Type;
	OldSpeed = 0;
	FastSpeed = 0.0;
	bAutoFollow = false;
	AddCollision(0, 0, COLLISIONMODEL_WHOLE);
}

GameItem :: GameItem() : GameObject()
{
	InitItem(ITEM_NONE);
}

GameItem :: GameItem(ShooterSprite * IN_Sprite, ITEM_TYPE IN_Type, int IN_FrameChangeInterval) : GameObject(TYPE_ITEM, IN_Sprite, IN_FrameChangeInterval, true, 0, false, true)
{
	InitItem(IN_Type);
}