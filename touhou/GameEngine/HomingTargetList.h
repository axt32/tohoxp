#pragma once
#include "../MemoryLeakChecker.h"

#include <list>

typedef struct HomingTarget
{
	double Target_X;		//Corner 값
	double Target_Y;		//Corner 값
	int iPlayerShotReferenceCount;		//시작점 (PlayerShot 등)
	bool bEnemyAlive;		//표적 (Enemy 등)

	HomingTarget ();
	HomingTarget (double IN_Target_X, double IN_Target_Y);
} HomingTarget;

extern std::list <HomingTarget *> vHomingTarget;

bool CheckGarbageHomingTarget(std::list<HomingTarget *>::iterator * IN_Iter);

void ClearHomingTargetList();