#include "GamePlayerShot.h"

void GamePlayerShot ::InitPlayerShot()
{
	iDamage = 2;	//�׽�Ʈ��.
	iDamageToBoss = 1;
	bIsBomber = false;

	pPlayerShotInit = NULL;
	pPlayerShotFunc = NULL;

	for (int i = 0; i < 10; i++)
	{
		iPlayerShotParameters[i] = 0;
	}

	HomingTargetIter = vHomingTarget.end();	//std iterator���� null�� end�� ��������.. �ʴ´�. �׳� �ʱⰪ ���� ������ ����.
																//�߰�/������ �Ͼ�� end()���� ��ȿȭ��.
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
	//���� ������!!!!!!!!!!!!
	//��� �������� �ϳ��ϳ� ��������� �Ѵ�(���� ����)
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