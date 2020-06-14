#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_GameUtil.h"
#include "../GameCore/Angle360.h"

//보스 공격

//人모양을 만들으며 공격함 + 유도 공격
void InitStage1BossAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1BossAttack0(GameObject * IN_Object, int * IN_iParameters);

//육각형->별모양 공격 (from th13)
void InitStage1BossAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1BossAttack1(GameObject * IN_Object, int * IN_iParameters);

void InitStage1BossAttack2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1BossAttack2(GameObject * IN_Object, int * IN_iParameters);

void InitStage1BossAttack2_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1BossAttack2_1(GameObject * IN_Object, int * IN_iParameters);

void InitStage1BossAttack1MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1BossAttack1MicroThread0(GameObject * IN_Object, int * IN_iParameters);

void InitStage1BossAttack1MicroThread1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1BossAttack1MicroThread1(GameObject * IN_Object, int * IN_iParameters);

void InitStage1BossAttack1MicroThread2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1BossAttack1MicroThread2(GameObject * IN_Object, int * IN_iParameters);

void InitStage1BossAttack2MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1BossAttack2MicroThread0(GameObject * IN_Object, int * IN_iParameters);

