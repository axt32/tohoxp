//////////////////////////////////////////////////////////////////////////
//
// GameUtil - ���� �� ������Ʈ���� ������ �Ҹ�, ó���� ���� �Լ��� ����ִ�.
//
//////////////////////////////////////////////////////////////////////////

#pragma once
#include "../MemoryLeakChecker.h"
#include "GameState_Game.h"
#include "../GameCore/CommonUtil.h"
#include <vector>
#include <stdlib.h>

//�ش� ������ Ŀ�ǵ� ����Ʈ �߿��� ���ǿ� ��ġ�ϴ� Ŀ�ǵ带 ã�� ��ȯ�Ѵ�.
bool FindCommand(GameEnemy * IN_Enemy, std::string IN_TypeString, int IN_Frame, std::vector<EnemyCommand *>::iterator * OUT_Iter);

//�־��� �������ݴ�� ������ �Է��Ѵ�. (Center ��)
void AddEnemy(std::string IN_Protocol);

//�Էµ� ������ ���������� �м��Ѵ�.
void ParseProtocol(GameEnemy * IN_EnemyBullet, std::string IN_Protocol);

//�ش� ������ Ư���� Ŀ�ǵ� �ϳ��� �����.
void DeleteCommand(GameEnemy * IN_Enemy, std::vector<EnemyCommand *>::iterator IN_Iter);

//���� ���(������ ���� ���������� ���� ����)���� ������ �����Ͽ� ObjectVector�� �ִ´�.
void MakeEnemyFromPreVector();

//���ο� �Լ�. ��ġ�� ����Ѵ�.
bool ProcessPos(GameObject * IN_Object);

//������ ȿ�� ���
void DrawBossEffect();

//��ü ó��
void ProcessPlayer();
void ProcessEnemy();
void ProcessBullet();
void ProcessExplosion();
void ProcessPlayerShot();
void ProcessItem();

//ź���Լ� ȣ��. (ProcessEnemy�� ProcessBullet���ο��� ���̴� �Լ�)
void ProcessBarrage(GameEnemyBullet * IN_Object);

//����ī�� ����
void StartSpell();

//���� ����ī��
void ProcessSpell();

//���� Ŭ����
bool SpellClear(GameBoss * IN_Boss);

//�Է��� ����� �Ѿ��� ���. (Center ��)
bool AddBullet(ENEMYBULLET_TYPE IN_Type, int IN_SubType, double IN_x, double IN_y, double IN_angle, double IN_addangle, double IN_speed, double IN_acc, bool IN_IgnorePlayerSpell = false);

//�������� ������� �Ѿ��� ��ȯ�Ѵ�.
GameBullet * GetLastBullet();

//�Է��� ����� �÷��̾� �Ѿ� �߻� (Center ��)
bool AddPlayerShot(GamePlayerShot * IN_PlayerShot, double IN_Far_X, double IN_Far_Y, double IN_angle, bool IN_Muteki = false);
bool AddPlayerShot(GamePlayerShot * IN_PlayerShot, double IN_Far_X, double IN_Far_Y, double IN_angle, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, bool IN_Muteki = false);
//������ ����� �ο��Ѵ�.
bool MakeBossBarrage(std::string IN_TypeString, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4);

//���� �ֱٿ� ������� �Ѿ˿� ����� �ο��Ѵ�.
bool MakeMicroThread(std::string IN_TypeString, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4);

//������ �Ѿ˿� ����� �ο��Ѵ�.
bool MakeMicroThread(GameBullet * IN_Bullet, std::string IN_TypeString, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4);

//������Ʈ�� �����.
void DeleteObject(GameObject * IN_Object);

//��� ������ �Ѿ��� ���ش�.
void DeleteAllObjects();

void DestroyAllEnemy();
void DestroyAllBullet(bool bDeleteAll = true);

void DeleteAllPlayerShot();

//ź���� ����Ѵ�.
void RegisterBarrage(std::string IN_Name, BarrageFunctionInit IN_Init, BarrageFunction IN_Function);

//ź���� ã�� ��ȯ�Ѵ�.
bool FindBarrage(std::string IN_TypeString, std::vector<GameBarrage *>::iterator * OUT_Iter);

//��� ź���� �����.
void DeleteAllBarrage();
void DeleteAllBarrage(GameEnemy * IN_Object);

//����ī�� ���
void RegisterSpell(GameBoss * IN_Boss, std::string IN_Name, int IN_HP, SpellInit IN_SpellInit, SpellFunction IN_SpellFunction, int IN_LimitTime, bool IN_Invincible = false, bool IN_Countable = true);

//�÷��̾� ��ġ �ʱ�ȭ
void MovePlayerToPrimaryLocation(GamePlayer * IN_Player);

//�÷��̾� ��
bool PlayerShotStart(GamePlayer * IN_Player);

//�÷��̾� ���� (����ī��)
bool PlayerBomberStart(GamePlayer * IN_Player);

void KillPlayer();

//���� ȿ��
void MakeExplosion(GameObject * IN_Object, bool IN_Type, double IN_Far_X = 0.0, double IN_Far_Y = 0.0);

//�� ��ü���� �浹�� üũ�Ѵ�.
bool CollisionCheck(GameObject * Obj1, GameObject * Obj2);

//�� ��ü���� �׷����� ���θ� Ȯ��.
bool GrazeCheck(GameObject * Obj1, GameObject * Obj2);

//��ü�� ����ȭ�� �ۿ� �ִ��� üũ�Ѵ�.
bool OutsideCheck(GameObject * IN_Object);

//��ü�� ����ȭ�� �ȿ� �ִ��� üũ�Ѵ�.
bool InsideCheck(GameObject * IN_Object);

//�÷��̾��� ������ �߰�
void AddScore(int IN_Score);

void PlayEnemyDamagedSound();
void PlayEnemyDeadSound();