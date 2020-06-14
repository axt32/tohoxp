#include "GameEnemyBullet.h"

void GameEnemyBullet :: InitGameEnemyBullet(ENEMYBULLET_TYPE IN_Type)
{

	iEnemyBulletType = IN_Type;
	pvBarrage.reserve(8);
}

 GameEnemyBullet :: GameEnemyBullet() : GameObject(TYPE_ENEMYBULLET)
{
	InitGameEnemyBullet((ENEMYBULLET_TYPE)0);
}	

/* void GameEnemyBullet :: AddEnemyCommand(std::string IN_Type, char IN_param1, char IN_param2, char IN_param3, char IN_param4)
{
	EnemyCommand Vec;
	Vec.type = IN_Type;
	Vec.param0 = IN_param1;
	Vec.param1 = IN_param2;
	Vec.param2 = IN_param3;
	Vec.param3 = IN_param4;
	EnemyCommandVector.push_back(Vec);
}		*/

GameEnemyBullet :: GameEnemyBullet(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, bool IN_Movable) : GameObject(TYPE_ENEMYBULLET, IN_Sprite, IN_Rotate, IN_Movable)
{
	InitGameEnemyBullet(IN_Type);
}
GameEnemyBullet :: GameEnemyBullet(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable) : GameObject(TYPE_ENEMYBULLET, IN_Sprite, IN_FrameChangeInterval, IN_AutoNextFrame, IN_CurrentFrame, IN_Rotate, IN_Movable)
{
	InitGameEnemyBullet(IN_Type);
}
GameEnemyBullet :: ~GameEnemyBullet()
{
	for (std::vector<GameBarrage * >::iterator Iter = pvBarrage.begin(); Iter != pvBarrage.end(); Iter++)
	{
		delete (*Iter);
	}
	
	pvBarrage.clear();
}