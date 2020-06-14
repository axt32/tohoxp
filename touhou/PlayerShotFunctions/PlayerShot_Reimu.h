#pragma once

#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_GameUtil.h"
#include "../GameCore/Angle360.h"

void PlayerShot_Reimu_Sub_Init(GamePlayerShot * IN_GamePlayerShot, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4);
void PlayerShot_Reimu_Sub (GamePlayerShot * IN_GamePlayerShot);

void PlayerShot_Reimu_Rapier_Init(GamePlayerShot * IN_GamePlayerShot, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4);
void PlayerShot_Reimu_Rapier_Func(GamePlayerShot * IN_GamePlayerShot);

void PlayerShot_Reimu_Bomber_Init(GamePlayerShot * IN_GamePlayerShot, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4);
void PlayerShot_Reimu_Bomber_Func(GamePlayerShot * IN_GamePlayerShot);