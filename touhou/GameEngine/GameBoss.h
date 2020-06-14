#include "../MemoryLeakChecker.h"
#include "GameEnemy.h"

#define MUTEKITIME 120
#define BOMBERPORTRAITTIME 120

typedef void (*SpellInit)(void);
typedef void (*SpellFunction)(void);

struct BossSpell
{
	std::string Name;
	int iHP;
	SpellInit pSpellInit;
	SpellFunction pSpellFunction;
	int iLimitTime;
	bool bInvincible;
	bool bCountable;
};

class GameBoss : public GameEnemy
{
private:

	void InitBoss(ShooterSprite * IN_Portrait = NULL);
public:
	//보스전용
	int iCurrentSpell;
	int iCurrentMutekiTime;
	int iRemainTime;
	int iRemainTime_FrameTime;

	ShooterSprite * pSpellPortrait;

	std::vector<BossSpell *> SpellVector;
	GameBoss();
	GameBoss(ShooterSprite * IN_Sprite, ShooterSprite * IN_Portrait);
	~GameBoss();
};