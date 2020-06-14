#include "GameBoss.h"


void GameBoss :: InitBoss(ShooterSprite * IN_Portrait)
{
	iCurrentSpell = 0;
	//bMuteki = false;
	iCurrentMutekiTime = 0;
	iType = TYPE_BOSS;
	pSpellPortrait = NULL;
	iRemainTime = 0;
	iRemainTime_FrameTime = 0;
}

GameBoss :: GameBoss() : GameEnemy(ENEMY_BOSS, NULL, false, true)
{
	InitBoss();
}
GameBoss :: GameBoss(ShooterSprite * IN_Sprite, ShooterSprite * IN_Portrait) : GameEnemy(ENEMY_BOSS, IN_Sprite, false, true)
{
	InitBoss(IN_Portrait);
}
GameBoss :: ~GameBoss()
{
	if (SpellVector.size() > 0)
	{
		for (std::vector<BossSpell *>::iterator Iter = SpellVector.begin(); Iter != SpellVector.end(); Iter++)
		{
			delete (*Iter);
		}

		SpellVector.clear();
	}
}