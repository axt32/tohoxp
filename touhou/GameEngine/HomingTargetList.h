#pragma once
#include "../MemoryLeakChecker.h"

#include <list>

typedef struct HomingTarget
{
	double Target_X;		//Corner ��
	double Target_Y;		//Corner ��
	int iPlayerShotReferenceCount;		//������ (PlayerShot ��)
	bool bEnemyAlive;		//ǥ�� (Enemy ��)

	HomingTarget ();
	HomingTarget (double IN_Target_X, double IN_Target_Y);
} HomingTarget;

extern std::list <HomingTarget *> vHomingTarget;

bool CheckGarbageHomingTarget(std::list<HomingTarget *>::iterator * IN_Iter);

void ClearHomingTargetList();