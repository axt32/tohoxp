#pragma once
#include "../MemoryLeakChecker.h"
#include "GameObject.h"
#include "GamePlayerShot.h"
#include "GamePlayerHeatBox.h"

typedef enum PlayerCharaType
{
	PLAYERCHARA_REIMU,
	PLAYERCHARA_MARISA,
	PLAYERCHARA_REISEN
} PlayerCharaType;

typedef enum PlayerStatus
{
	PLAYERSTATUS_NONE,
	PLAYERSTATUS_SHIELD,
	PLAYERSTATUS_EXPLOSION
} PlayerStatus;

#define PLAYER_SHIELD_DURATION 120
#define DEFAULT_PLAYER_SHOT_COOLTIME 3
#define DEFAULT_PLAYER_SHOT_QUANTITY 3
#define DEFAULT_PLAYER_SHOT_SUBCOOLTIME 3

#define PLAYER_MAX_GRAVITY 10
#define PLAYER_FRONT_FRAMECHANGE_INTERVAL 10
#define PLAYER_GRAVITY_FRAMECHANGE_INTERVAL 3

class GameObject;
class GamePlayer;
typedef void (*PlayerBomberInit)(GamePlayer *, int, int, int, int, int);
typedef void (*PlayerBomber) (GamePlayer *);


class GamePlayer : public GameObject
{
private:
	GamePlayerShot * pPlayerShot[3][5];

	ShooterSprite * pFrontSprite;
	ShooterSprite * pLeftSprite;
	ShooterSprite * pRightSprite;

public:

	PlayerCharaType iPlayerCharaType;

	int life;
	int bomber;

	int iPlayerShotCoolTime;
	int iPlayerShotQuantity;
	int iPlayerShotSubCoolTime;

	int iShotCurrentWaitTime;
	int iShotCurrentWaitSubTime;
	bool bCoupleShot;
	int iCurrentPower;
	int iScore;
	int iGrazeCount;
	bool bShift;
	int iGravity;
	int iOldGravity;
	int iCurrentGravityFrameTime;
	PlayerStatus iCurrentStatus;
	int iCurrentShieldTime;
	int iCurrentExplosionTime;
	bool bShield;

	bool bNowShooting;
	int iShotCount;

	bool bNowBomber;
	PlayerBomberInit pPlayerBomberInit;
	PlayerBomber pPlayerBomber;
	int iBomberParameters[10];
	int iCurrentBomberPortraitTime;

	ShooterSprite * pBomberPortrait;

	bool bNowBomberPortrait;

	double fConstNormalSpeed;
	double fConstSlowSpeed;

	int iSmallScoreItemCount;
	int iBigScoreItemCount;
	bool bNoMiss;

	GamePlayerHeatBox * pPlayerHeatBox;

	GamePlayer();
	GamePlayer(ShooterSprite * IN_Sprite);
	void InitPlayer();
	bool SetSprite(ShooterSprite * IN_FrontSprite, ShooterSprite * IN_LeftSprite, ShooterSprite * IN_RightSprite);
	void ClearPlayerShot();
	void SetPlayerShot(int IN_No, int IN_Power, GamePlayerShot * IN_PlayerShot);
	void SetPlayerHeatBox(GamePlayerHeatBox * IN_GamePlayerHeatBox);
	bool SetPower(int IN_Power);
	void ChangeState(PlayerStatus IN_PlayerStatus);
	GamePlayerShot * GetPlayerShot(int IN_No);

	bool Draw(bool IN_AutoNextFrame);
	bool SetAlphaAll(Uint8 IN_Alpha);

	void InitGravity();
};

