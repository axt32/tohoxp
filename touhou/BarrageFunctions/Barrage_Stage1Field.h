#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_GameUtil.h"
#include "../GameCore/Angle360.h"

//환형발사
void InitStage1ZakouAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1ZakouAttack0(GameObject * IN_Object, int * IN_iParameters);

//일정한 시격으로 플레이어를 향해 조준한 뒤 TYPE3 총알을 하나 발사합니다.
void InitStage1ZakouAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage1ZakouAttack1(GameObject * IN_Object, int * IN_iParameters);