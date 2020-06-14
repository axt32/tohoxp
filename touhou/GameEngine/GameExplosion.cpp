#include "GameExplosion.h"

void GameExplosion :: InitExplosion()
{
	bStarted = false;
	bPlayerExplosion = false;
}

GameExplosion :: GameExplosion() : GameObject()
{
	InitExplosion();
}

GameExplosion :: GameExplosion(ShooterSprite * IN_Sprite, int IN_FrameChangeInterval) : GameObject(TYPE_EXPLOSION, IN_Sprite, IN_FrameChangeInterval, true, 0, false, false)
{
	InitExplosion();
}