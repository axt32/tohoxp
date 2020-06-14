//////////////////////////////////////////////////////////////////////////
//
// GameUtil - 게임 속 오브젝트들의 생성과 소멸, 처리에 관한 함수를 담고있다.
//
//////////////////////////////////////////////////////////////////////////

#pragma once
#include "../MemoryLeakChecker.h"
#include "GameState_Game.h"
#include "../GameCore/CommonUtil.h"
#include <vector>
#include <stdlib.h>

//해당 적군의 커맨드 리스트 중에서 조건에 일치하는 커맨드를 찾아 반환한다.
bool FindCommand(GameEnemy * IN_Enemy, std::string IN_TypeString, int IN_Frame, std::vector<EnemyCommand *>::iterator * OUT_Iter);

//주어진 프로토콜대로 적군을 입력한다. (Center 값)
void AddEnemy(std::string IN_Protocol);

//입력된 적군의 프로토콜을 분석한다.
void ParseProtocol(GameEnemy * IN_EnemyBullet, std::string IN_Protocol);

//해당 적군의 특정한 커맨드 하나를 지운다.
void DeleteCommand(GameEnemy * IN_Enemy, std::vector<EnemyCommand *>::iterator IN_Iter);

//예비 목록(적군이 언제 출현할지에 대한 정보)에서 정보를 추출하여 ObjectVector에 넣는다.
void MakeEnemyFromPreVector();

//내부용 함수. 위치를 계산한다.
bool ProcessPos(GameObject * IN_Object);

//보스의 효과 출력
void DrawBossEffect();

//객체 처리
void ProcessPlayer();
void ProcessEnemy();
void ProcessBullet();
void ProcessExplosion();
void ProcessPlayerShot();
void ProcessItem();

//탄막함수 호출. (ProcessEnemy와 ProcessBullet내부에서 쓰이는 함수)
void ProcessBarrage(GameEnemyBullet * IN_Object);

//스펠카드 시작
void StartSpell();

//보스 스펠카드
void ProcessSpell();

//스펠 클리어
bool SpellClear(GameBoss * IN_Boss);

//입력한 값대로 총알을 쏜다. (Center 값)
bool AddBullet(ENEMYBULLET_TYPE IN_Type, int IN_SubType, double IN_x, double IN_y, double IN_angle, double IN_addangle, double IN_speed, double IN_acc, bool IN_IgnorePlayerSpell = false);

//마지막에 만들어진 총알을 반환한다.
GameBullet * GetLastBullet();

//입력한 값대로 플레이어 총알 발사 (Center 값)
bool AddPlayerShot(GamePlayerShot * IN_PlayerShot, double IN_Far_X, double IN_Far_Y, double IN_angle, bool IN_Muteki = false);
bool AddPlayerShot(GamePlayerShot * IN_PlayerShot, double IN_Far_X, double IN_Far_Y, double IN_angle, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, bool IN_Muteki = false);
//보스에 명령을 부여한다.
bool MakeBossBarrage(std::string IN_TypeString, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4);

//가장 최근에 만들어진 총알에 명령을 부여한다.
bool MakeMicroThread(std::string IN_TypeString, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4);

//지정된 총알에 명령을 부여한다.
bool MakeMicroThread(GameBullet * IN_Bullet, std::string IN_TypeString, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4);

//오브젝트를 지운다.
void DeleteObject(GameObject * IN_Object);

//모든 적군과 총알을 없앤다.
void DeleteAllObjects();

void DestroyAllEnemy();
void DestroyAllBullet(bool bDeleteAll = true);

void DeleteAllPlayerShot();

//탄막을 등록한다.
void RegisterBarrage(std::string IN_Name, BarrageFunctionInit IN_Init, BarrageFunction IN_Function);

//탄막을 찾아 반환한다.
bool FindBarrage(std::string IN_TypeString, std::vector<GameBarrage *>::iterator * OUT_Iter);

//모든 탄막을 지운다.
void DeleteAllBarrage();
void DeleteAllBarrage(GameEnemy * IN_Object);

//스펠카드 등록
void RegisterSpell(GameBoss * IN_Boss, std::string IN_Name, int IN_HP, SpellInit IN_SpellInit, SpellFunction IN_SpellFunction, int IN_LimitTime, bool IN_Invincible = false, bool IN_Countable = true);

//플레이어 위치 초기화
void MovePlayerToPrimaryLocation(GamePlayer * IN_Player);

//플레이어 샷
bool PlayerShotStart(GamePlayer * IN_Player);

//플레이어 봄버 (스펠카드)
bool PlayerBomberStart(GamePlayer * IN_Player);

void KillPlayer();

//폭발 효과
void MakeExplosion(GameObject * IN_Object, bool IN_Type, double IN_Far_X = 0.0, double IN_Far_Y = 0.0);

//두 물체간의 충돌을 체크한다.
bool CollisionCheck(GameObject * Obj1, GameObject * Obj2);

//두 물체간의 그레이즈 여부를 확인.
bool GrazeCheck(GameObject * Obj1, GameObject * Obj2);

//물체가 게임화면 밖에 있는지 체크한다.
bool OutsideCheck(GameObject * IN_Object);

//물체가 게임화면 안에 있는지 체크한다.
bool InsideCheck(GameObject * IN_Object);

//플레이어의 점수를 추가
void AddScore(int IN_Score);

void PlayEnemyDamagedSound();
void PlayEnemyDeadSound();