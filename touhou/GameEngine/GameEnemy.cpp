#include "GameEnemy.h"
void GameEnemy :: InitGameEnemy()
{
	iType = TYPE_ENEMY;
	bFollow = false;
	iMaxHP = 0;
	iHP = 0;
	bDecele = false;
	fDeceleDist = 0.0;
	iCurrentState = ENEMYSTATE_NONE;
	iHitState_CurrentTime = 0;

	pOriginalSurface = NULL;
	pExtraSurface1 = NULL;
	pExtraSurface2 = NULL;

	HomingTargetIter = vHomingTarget.end();
	bUsingHomingTargetIter = false;

}

GameEnemy :: GameEnemy() : GameEnemyBullet()
{
	InitGameEnemy();
}

//다운캐스팅
GameEnemy :: GameEnemy(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, bool IN_Movable) : GameEnemyBullet(IN_Type, IN_Sprite, IN_Rotate, IN_Movable)
{
	InitGameEnemy();
}

GameEnemy :: GameEnemy(ENEMYBULLET_TYPE IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable) : GameEnemyBullet(IN_Type, IN_Sprite, IN_FrameChangeInterval, IN_AutoNextFrame, IN_CurrentFrame, IN_Rotate, IN_Movable)
{
	InitGameEnemy();
}

GameEnemy :: ~GameEnemy()
{
	if (EnemyCommandVector.size() > 0)
	{
		for (std::vector<EnemyCommand *>::iterator Iter = EnemyCommandVector.begin(); Iter != EnemyCommandVector.end(); Iter++)
		{
			//동적할당 해제
			delete (*Iter);
		}
		EnemyCommandVector.clear();
	}	

}

void GameEnemy :: SetExtraSurface(ShooterSprite * IN_ExtraSurface1, ShooterSprite * IN_ExtraSurface2)
{
	pOriginalSurface = GetSprite()->GetSurface();
	pExtraSurface1 = IN_ExtraSurface1->GetSurface();
	pExtraSurface2 = IN_ExtraSurface2->GetSurface();

}

void GameEnemy :: ChangeState(EnemyState IN_State)
{
	iCurrentState = IN_State;
	iHitState_CurrentTime = 0;

	switch (iCurrentState)
	{
	case ENEMYSTATE_NONE:
//		GetSprite()->SetAlpha(SDL_ALPHA_OPAQUE);
//		GetSprite()->SetSurface(pOriginalSurface);
		break;
	case ENEMYSTATE_HIT:
//		GetSprite()->SetAlpha(100);
//		GetSprite()->SetSurface(pExtraSurface1);
		break;
	case ENEMYSTATE_LOWHP:

		//GetSprite()->SetSurface(pExtraSurface2);
		break;

	}
}