#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_GameUtil.h"
#include "../GameCore/Angle360.h"

//�ﰢ��
void InitStage2BossAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack0(GameObject * IN_Object, int * IN_iParameters);

//ȸ�� + �Ѹ�� ����ũ�� ������
void InitStage2BossAttack0MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack0MicroThread0(GameObject * IN_Object, int * IN_iParameters);

//������
void InitStage2BossAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack1(GameObject * IN_Object, int * IN_iParameters);

//ȸ�� + �ٱ��� ���ڷ��̼� + ���� ����ź ����ũ�� ������
void InitStage2BossAttack1MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack1MicroThread0(GameObject * IN_Object, int * IN_iParameters);

//�ɸ��
void InitStage2BossAttack2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack2(GameObject * IN_Object, int * IN_iParameters);

//��ȥ������ ��°� ���ڸ������ ħź�� �������� ��
void InitStage2BossAttack3(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack3(GameObject * IN_Object, int * IN_iParameters);

void InitStage2BossAttack3_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack3_1(GameObject * IN_Object, int * IN_iParameters);

void InitStage2BossAttack4(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack4(GameObject * IN_Object, int * IN_iParameters);

//
void InitStage2BossAttack4_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack4_1(GameObject * IN_Object, int * IN_iParameters);

//������ ��ġ�� �� ����, < �Ǵ� >�ڷ� ����
void InitStage2BossAttack4MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttack4MicroThread0(GameObject * IN_Object, int * IN_iParameters);

//Final Attack
void InitStage2BossAttackFinal(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttackFinal(GameObject * IN_Object, int * IN_iParameters);

void InitStage2BossAttackFinalMicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttackFinalMicroThread0(GameObject * IN_Object, int * IN_iParameters);

void InitStage2BossAttackFinal_1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void Stage2BossAttackFinal_1(GameObject * IN_Object, int * IN_iParameters);