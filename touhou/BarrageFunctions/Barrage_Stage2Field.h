#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_GameUtil.h"
#include "../GameCore/Angle360.h"

//�÷��̾� ������ �������� �Ѿ��� �����ϰ� �߻��մϴ�.
void InitZakouAttack0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack0(GameObject * IN_Object, int * IN_iParameters);

//������ �� ���������� ���ϴ¸�ŭ�� ������ �Ѿ��� �߻�.
void InitZakouAttack1(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack1(GameObject * IN_Object, int * IN_iParameters);

//�÷��̾� ������ �������� ���ϴ¸�ŭ�� �Ѿ��� �����ϰ� �߻�.
void InitZakouAttack2(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack2(GameObject * IN_Object, int * IN_iParameters);

//ȯ������ �Ѿ��� �߻��մϴ�.
void InitZakouAttack3(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack3(GameObject * IN_Object, int * IN_iParameters);

//������ �� ������ + ��, ������ ���ϴ¸�ŭ�� ������ �Ѿ��� ����.
void InitZakouAttack4(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack4(GameObject * IN_Object, int * IN_iParameters);

//���ϴ� ������� ������ �Ѿ��� �߻�.
void InitZakouAttack5(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack5(GameObject * IN_Object, int * IN_iParameters);

//�÷��̾ �������� ������ ������, ���ϴ� �Ѿ�, ���ϴ� ���ǵ�� �߻�.
void InitZakouAttack6(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack6(GameObject * IN_Object, int * IN_iParameters);

//ȯ������ �Ѿ��� �߻��մϴ�. (ó���� ������ �� ��, �����ð� ���� �ӵ��� ����) (ZakouAttack3�� ���� ����)
void InitZakouAttack7(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack7(GameObject * IN_Object, int * IN_iParameters);

//Į�� ȯ������ �߻��� ��, �����ð� ���� �÷��̾ ���� �����մϴ�.
void InitZakouAttack8(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack8(GameObject * IN_Object, int * IN_iParameters);

//������ �ð����� �÷��̾ ���� ������ �� TYPE0 �Ѿ��� �ϳ� �߻��մϴ�.
void InitZakouAttack9(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack9(GameObject * IN_Object, int * IN_iParameters);

//���� �Ѿ��� �������� �߻��մϴ�.
void InitZakouAttack10(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack10(GameObject * IN_Object, int * IN_iParameters);

void InitZakouAttack7MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack7MicroThread0(GameObject * IN_Object, int * IN_iParameters);

void InitZakouAttack8MicroThread0(GameObject * IN_Object, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, int * IN_iParameters);
void ZakouAttack8MicroThread0(GameObject * IN_Object, int * IN_iParameters);

