//샘플

#pragma once
#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_GameUtil.h"
#include "../GameCore/Angle360.h"

//보스를 이동시킵니다. (Center 값)
void MoveBoss(double IN_x, double IN_y);
void MoveBossToPrimaryLocation();

void InitFourWingsFan(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void FourWingsFan(GameObject * IN_Object, int * IN_iParameters);

void InitSixWingsAst(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void SixWingsAst(GameObject * IN_Object, int * IN_iParameters);