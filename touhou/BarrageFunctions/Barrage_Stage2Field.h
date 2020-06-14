#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_GameUtil.h"
#include "../GameCore/Angle360.h"

//플레이어 방향을 기준으로 총알을 랜덤하게 발사합니다.
void InitZakouAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack0(GameObject * IN_Object, int * IN_iParameters);

//조준한 뒤 일직선으로 원하는만큼의 갯수의 총알을 발사.
void InitZakouAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack1(GameObject * IN_Object, int * IN_iParameters);

//플레이어 방향을 기준으로 원하는만큼의 총알을 랜덤하게 발사.
void InitZakouAttack2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack2(GameObject * IN_Object, int * IN_iParameters);

//환형으로 총알을 발사합니다.
void InitZakouAttack3(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack3(GameObject * IN_Object, int * IN_iParameters);

//조준한 뒤 일직선 + 좌, 우으로 원하는만큼의 갯수의 총알을 뿜음.
void InitZakouAttack4(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack4(GameObject * IN_Object, int * IN_iParameters);

//원하는 각도대로 나눠서 총알을 발사.
void InitZakouAttack5(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack5(GameObject * IN_Object, int * IN_iParameters);

//플레이어를 기준으로 랜덤한 각으로, 원하는 총알, 원하는 스피드로 발사.
void InitZakouAttack6(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack6(GameObject * IN_Object, int * IN_iParameters);

//환형으로 총알을 발사합니다. (처음에 빠르게 쏜 뒤, 일정시간 이후 속도를 늦춤) (ZakouAttack3과 거의 같음)
void InitZakouAttack7(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack7(GameObject * IN_Object, int * IN_iParameters);

//칼을 환형으로 발사한 뒤, 일정시간 이후 플레이어를 향해 조준합니다.
void InitZakouAttack8(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack8(GameObject * IN_Object, int * IN_iParameters);

//일정한 시격으로 플레이어를 향해 조준한 뒤 TYPE0 총알을 하나 발사합니다.
void InitZakouAttack9(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack9(GameObject * IN_Object, int * IN_iParameters);

//작은 총알을 무작위로 발사합니다.
void InitZakouAttack10(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack10(GameObject * IN_Object, int * IN_iParameters);

void InitZakouAttack7MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack7MicroThread0(GameObject * IN_Object, int * IN_iParameters);

void InitZakouAttack8MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack8MicroThread0(GameObject * IN_Object, int * IN_iParameters);

