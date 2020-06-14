#pragma once
#include "../MemoryLeakChecker.h"
#include "GameEnemyBullet.h"
#include "HomingTargetList.h"

typedef struct EnemyCommand
{
	int Frame;
	std::string type;
	int param0;
	int param1;
	int param2;
	int param3;
	int param4;
	std::string param5;
} EnemyCommand;

typedef enum EnemyState
{
	ENEMYSTATE_NONE,
	ENEMYSTATE_HIT,
	ENEMYSTATE_LOWHP
} EnemyState;

#define ENEMYSTATE_HIT_DURATION 3

class GameEnemy : public GameEnemyBullet
{
private:
	void InitGameEnemy();
	//추가 서페이스
	SDL_Surface * pOriginalSurface;
	SDL_Surface * pExtraSurface1;
	SDL_Surface * pExtraSurface2;
public:
	std::vector<EnemyCommand *> EnemyCommandVector;
	int iMaxHP;
	int iHP;
	EnemyState iCurrentState;
	bool bDecele;
	double fDeceleDist;
	int iHitState_CurrentTime;

	bool bUsingHomingTargetIter;
	std::list<HomingTarget *>::iterator HomingTargetIter;

	void SetExtraSurface(ShooterSprite * IN_ExtraSurface1, ShooterSprite * IN_ExtraSurface2);
	void ChangeState(EnemyState IN_State);

	GameEnemy();
	GameEnemy(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, bool IN_Movable = true);
	GameEnemy(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable = true);
	~GameEnemy();
};