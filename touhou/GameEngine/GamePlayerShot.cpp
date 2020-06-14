#include "GamePlayerShot.h"

void GamePlayerShot ::InitPlayerShot()
{
	iDamage = 2;	//테스트용.
	iDamageToBoss = 1;
	bIsBomber = false;

	pPlayerShotInit = NULL;
	pPlayerShotFunc = NULL;

	for (int i = 0; i < 10; i++)
	{
		iPlayerShotParameters[i] = 0;
	}

	HomingTargetIter = vHomingTarget.end();	//std iterator에는 null을 end로 갈음하지.. 않는다. 그냥 초기값 세팅 정도라 보자.
																//추가/삭제가 일어나면 end()값은 무효화됨.
	bUsingHomingTargetIter = false;

	bPassBullet = false;

	bFollowToPlayerMoving = true;
}


GamePlayerShot :: GamePlayerShot() : GameObject(TYPE_PLAYERSHOT)
{
	InitPlayerShot();
}

GamePlayerShot :: GamePlayerShot(PLAYERSHOT_TYPE IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, int IN_damage, CollisionModel IN_CollisionModel, double IN_CollisionRadius, bool IN_IsBomber) : GameObject ( TYPE_PLAYERSHOT, IN_Sprite, IN_Rotate, true)
{
	InitPlayerShot();
	iPlayerShotType = IN_Type;
	iDamage = IN_damage;
	bIsBomber = IN_IsBomber;
	AddCollision(0.0, 0.0, IN_CollisionModel, IN_CollisionRadius);
}

GamePlayerShot ::GamePlayerShot(GamePlayerShot& IN_PlayerShot) : GameObject(IN_PlayerShot)
{
	//복사 생성자!!!!!!!!!!!!
	//멤버 변수들을 하나하나 복사해줘야 한다(깊은 복사)
	iPlayerShotType = IN_PlayerShot.iPlayerShotType;
	iDamage = IN_PlayerShot.iDamage;
	iDamageToBoss = IN_PlayerShot.iDamageToBoss;
	bIsBomber = IN_PlayerShot.bIsBomber;

	pPlayerShotInit = IN_PlayerShot.pPlayerShotInit;
	pPlayerShotFunc = IN_PlayerShot.pPlayerShotFunc;

	for (int i = 0; i < 10; i++)
	{
		iPlayerShotParameters[i] = IN_PlayerShot.iPlayerShotParameters[i];
	}

	HomingTargetIter = IN_PlayerShot.HomingTargetIter;
	bUsingHomingTargetIter = IN_PlayerShot.bUsingHomingTargetIter;

	bPassBullet = IN_PlayerShot.bPassBullet;
}

GamePlayerShot :: ~GamePlayerShot()
{

}