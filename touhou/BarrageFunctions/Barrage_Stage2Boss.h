#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_GameUtil.h"
#include "../GameCore/Angle360.h"

//삼각형
void InitStage2BossAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack0(GameObject * IN_Object, int * IN_iParameters);

//회전 + 人모양 마이크로 스레드
void InitStage2BossAttack0MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack0MicroThread0(GameObject * IN_Object, int * IN_iParameters);

//오각형
void InitStage2BossAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack1(GameObject * IN_Object, int * IN_iParameters);

//회전 + 바깥쪽 데코레이션 + 안쪽 조준탄 마이크로 스레드
void InitStage2BossAttack1MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack1MicroThread0(GameObject * IN_Object, int * IN_iParameters);

//꽃모양
void InitStage2BossAttack2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack2(GameObject * IN_Object, int * IN_iParameters);

//반혼접에서 쏘는거 십자모양으로 침탄을 돌려가며 쏨
void InitStage2BossAttack3(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack3(GameObject * IN_Object, int * IN_iParameters);

void InitStage2BossAttack3_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack3_1(GameObject * IN_Object, int * IN_iParameters);

void InitStage2BossAttack4(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack4(GameObject * IN_Object, int * IN_iParameters);

//
void InitStage2BossAttack4_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack4_1(GameObject * IN_Object, int * IN_iParameters);

//정해진 위치로 간 다음, < 또는 >자로 공격
void InitStage2BossAttack4MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack4MicroThread0(GameObject * IN_Object, int * IN_iParameters);

//Final Attack
void InitStage2BossAttackFinal(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttackFinal(GameObject * IN_Object, int * IN_iParameters);

void InitStage2BossAttackFinalMicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttackFinalMicroThread0(GameObject * IN_Object, int * IN_iParameters);

void InitStage2BossAttackFinal_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttackFinal_1(GameObject * IN_Object, int * IN_iParameters);