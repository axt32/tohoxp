#include "GameBullet.h"
void GameBullet :: InitGameBullet()
{
	iType = TYPE_BULLET;
}
GameBullet :: GameBullet() : GameEnemyBullet()
{
	InitGameBullet();
}
GameBullet :: GameBullet(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, bool IN_Movable) : GameEnemyBullet(IN_Type, IN_Sprite, IN_Rotate, IN_Movable)
{
	InitGameBullet();
}
GameBullet :: GameBullet(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable) : GameEnemyBullet(IN_Type, IN_Sprite, IN_FrameChangeInterval, IN_AutoNextFrame, IN_CurrentFrame, IN_Rotate, IN_Movable)
{
	InitGameBullet();
}
GameBullet :: ~GameBullet()
{

}