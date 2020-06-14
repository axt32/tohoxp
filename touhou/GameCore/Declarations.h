//////////////////////////////////////////////////////////////////////////
//
// Declarations - 게임에서 쓰이는 대부분의 선언들이 담겨있다.
//
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "../MemoryLeakChecker.h"
#include "../ExternalUtil/INIManager/INIManager.h"
#include "../SDLEngine/ShooterScreen.h"
#include "../SDLEngine/ShooterInput.h"
#include "../SDLEngine/ShooterFont.h"
#include "../SDLEngine/ShooterSoundManager.h"
#include "../SDLEngine/ShooterSound.h"
#include "../GameEngine/GamePlayer.h"
#include "../GameEngine/GameEnemyBullet.h"
#include "../GameEngine/GameEnemy.h"
#include "../GameEngine/GameBoss.h"
#include "../GameEngine/GameBullet.h"
#include "../GameEngine/GameExplosion.h"
#include "../GameEngine/GameItem.h"
#include "../GameEngine/GameBarrage.h"
#include "../GameEngine/GameStage.h"
#include "../GameCore/CommonUtil.h"
#include "../EventScene/EventScene.h"
#include <vector>
#include "GamePlay.h"
#include "../ExternalUtil/VirtualKeyConverter/VirtualKeyConverter.h"

//게임 시스템
extern bool bRunning;
extern double fFrameRate;
extern Uint32 iFrameTime;
extern int iGameFrame;
extern int iOldGameFrame;

extern int iOldGameFrame_EnemyDamaged;
extern int iOldGameFrame_EnemyDead;

extern double fTimeFactor;

extern INIManager MyINIManager;

extern KEY iKey_Up;
extern KEY iKey_Down;
extern KEY iKey_Left;
extern KEY iKey_Right;
extern KEY iKey_Attack;
extern KEY iKey_Bomber;
extern KEY iKey_Slow;
extern KEY iKey_Skip;

extern bool bBGM_Use;
extern bool bSE_Use;

extern double fVolume_BGM;
extern double fVolume_SE;

//extern FPSmanager MyFPS;

#define GAMEWIDTH 640
#define GAMEHEIGHT 480

#define DEFAULT_FRAMECHANGE_INTERVAL 3

#define BULLET_TOTAL_TYPES 19

typedef enum GAMESTATE
{
	INTRO = 0,
	MAINMENULOGO,
	MAINMENU,
	CHARASELECT,
	GAMESTATE_GAME,
	GAMECREDITS,
	RECORDSTATUS
} GAMESTATE;

typedef enum GAMESTATE_GAME_STATUS
{
	GAMESTATE_GAME_FIELD = 0,
	GAMESTATE_GAME_EVENT,
	GAMESTATE_GAME_BOSS,
	GAMESTATE_GAME_EVENT_AFTER_BOSS,
	GAMESTATE_GAME_RESULT
};

typedef enum GAMESTATE_GAME_PAUSETYPE
{
	PAUSE_PAUSEMENU = 0,
	PAUSE_GAMEOVERSCORE,
	PAUSE_GAMEOVERMENU,
};

#define UI_NOWLOADING_X 480
#define UI_NOWLOADING_Y 430

#define GAME_UI_SCRIPTBOX_WIDTH 352
#define GAME_UI_SCRIPTBOX_HEIGHT 48

extern int iCurrentStage;
extern GAMESTATE_GAME_STATUS iGameState_Game_Status;
extern GAMESTATE_GAME_PAUSETYPE iGameState_Game_PauseType;

extern bool bOnceDescreteInput;

extern int iGameState;

//게임 스크린 및 인풋
extern ShooterScreen GameScreen;
extern ShooterSprite DarkScreen;
extern ShooterSprite DarkScreen_Record;
extern ShooterSprite DarkScreen_Result;
extern ShooterSprite DarkScreen_CompanyLogo;

extern ShooterInput GameInput;

//스프라이트
extern ShooterSprite Spr_Reimu_Front;
extern ShooterSprite Spr_Reimu_Left;
extern ShooterSprite Spr_Reimu_Right;

extern ShooterSprite Spr_Marisa_Front;
extern ShooterSprite Spr_Marisa_Left;
extern ShooterSprite Spr_Marisa_Right;

extern ShooterSprite Spr_Reisen_Front;
extern ShooterSprite Spr_Reisen_Left;
extern ShooterSprite Spr_Reisen_Right;

extern ShooterSprite Spr_PlayerShot_Reimu_0;
extern ShooterSprite Spr_PlayerShot_Reimu_0_Sub;
extern ShooterSprite Spr_PlayerShot_Reimu_Rapier_0;
extern ShooterSprite Spr_PlayerShot_Reimu_Bomber;

extern ShooterSprite Spr_PlayerShot_Marisa_0;
extern ShooterSprite Spr_PlayerShot_Marisa_Rapier_0;
extern ShooterSprite Spr_PlayerShot_Marisa_Bomber;

extern ShooterSprite Spr_PlayerShot_Reisen_0;
extern ShooterSprite Spr_PlayerShot_Reisen_1;
extern ShooterSprite Spr_PlayerShot_Reisen_2;

extern ShooterSprite Spr_PlayerShot_Reisen_Bomber;

//플레이어 히트박스
extern ShooterSprite Spr_PlayerHeatBox;

extern ShooterSprite Spr_BulletType0;
extern ShooterSprite Spr_BulletType1;
extern ShooterSprite Spr_BulletType2;
extern ShooterSprite Spr_BulletType3;
extern ShooterSprite Spr_BulletType4;
extern ShooterSprite Spr_BulletType5;
extern ShooterSprite Spr_BulletType6;
extern ShooterSprite Spr_BulletType7;
extern ShooterSprite Spr_BulletType8;
extern ShooterSprite Spr_BulletType9;
extern ShooterSprite Spr_BulletType10;
extern ShooterSprite Spr_BulletType11;
extern ShooterSprite Spr_BulletType12;
extern ShooterSprite Spr_BulletType13;
extern ShooterSprite Spr_BulletType14;
extern ShooterSprite Spr_BulletType15;
extern ShooterSprite Spr_BulletType16;
extern ShooterSprite Spr_BulletType17;
extern ShooterSprite Spr_BulletType18;

extern ShooterSprite Spr_UI_NowLoading;

extern ShooterSprite Spr_UI_CompanyLogo;

extern ShooterSprite Spr_UI_MainMenu_Background;

extern ShooterSprite Spr_UI_MainMenu_Gamelogo;

extern ShooterSprite Spr_UI_MainMenu_Sortie;
extern ShooterSprite Spr_UI_MainMenu_Sortie_Selected;

extern ShooterSprite Spr_UI_MainMenu_Record;
extern ShooterSprite Spr_UI_MainMenu_Record_Selected;

extern ShooterSprite Spr_UI_MainMenu_Exit;
extern ShooterSprite Spr_UI_MainMenu_Exit_Selected;

extern ShooterSprite Spr_UI_MainMenu_Copyright;

extern ShooterSprite Spr_UI_CharaSelect_Title;
extern ShooterSprite Spr_UI_CharaSelect_Description_Reimu;
extern ShooterSprite Spr_UI_CharaSelect_Description_Marisa;
extern ShooterSprite Spr_UI_CharaSelect_Description_Reisen;

extern ShooterSprite Spr_UI_Record_Background;

extern ShooterSprite Spr_UI_Record_Title;

extern ShooterSprite Spr_UI_Window_Left;
extern ShooterSprite Spr_UI_Window_Right;
extern ShooterSprite Spr_UI_Window_Top;
extern ShooterSprite Spr_UI_Window_Bottom;

extern ShooterSprite Spr_UI_GameOverMenu_New_Continue;
extern ShooterSprite Spr_UI_GameOverMenu_New_Continue_Selected;

extern ShooterSprite Spr_UI_PauseMenu_New_Yes;
extern ShooterSprite Spr_UI_PauseMenu_New_Yes_Selected;

extern ShooterSprite Spr_UI_PauseMenu_New_No;
extern ShooterSprite Spr_UI_PauseMenu_New_No_Selected;

extern ShooterSprite Spr_UI_PauseMenu_New_Question;

extern ShooterSprite Spr_UI_PauseMenu_New_Return;
extern ShooterSprite Spr_UI_PauseMenu_New_Return_Selected;

extern ShooterSprite Spr_UI_PauseMenu_New_Exit;
extern ShooterSprite Spr_UI_PauseMenu_New_Exit_Selected;

extern ShooterSprite Spr_UI_PauseMenu_New_Retry;
extern ShooterSprite Spr_UI_PauseMenu_New_Retry_Selected;

extern ShooterSprite Spr_UI_PauseMenu_New_Title;

extern ShooterSprite Spr_UI_GameOverMenu_New_Title;

extern ShooterSprite Spr_UI_Result_Reimu;
extern ShooterSprite Spr_UI_Result_Marisa;
extern ShooterSprite Spr_UI_Result_Reisen;

extern ShooterSprite Spr_UI_EnemySpell;

extern ShooterSprite Spr_UI_Extend;

extern ShooterSprite Spr_EnemyType0;
extern ShooterSprite Spr_EnemyType0_A;
extern ShooterSprite Spr_EnemyType0_B;
extern ShooterSprite Spr_EnemyType1;
extern ShooterSprite Spr_EnemyType1_A;
extern ShooterSprite Spr_EnemyType1_B;
extern ShooterSprite Spr_EnemyType2;
extern ShooterSprite Spr_EnemyType2_A;
extern ShooterSprite Spr_EnemyType2_B;
extern ShooterSprite Spr_EnemyType3;
extern ShooterSprite Spr_EnemyType3_A;
extern ShooterSprite Spr_EnemyType3_B;
extern ShooterSprite Spr_EnemyType4;
extern ShooterSprite Spr_EnemyType4_A;
extern ShooterSprite Spr_EnemyType4_B;
extern ShooterSprite Spr_EnemyType5;
extern ShooterSprite Spr_EnemyType5_A;
extern ShooterSprite Spr_EnemyType5_B;

extern ShooterSprite Spr_Boss_Stage1;
extern ShooterSprite Spr_Boss_Stage1_A;
extern ShooterSprite Spr_Boss_Stage1_B;

extern ShooterSprite Spr_Boss_Stage2;
extern ShooterSprite Spr_Boss_Stage2_Invincible;
extern ShooterSprite Spr_Boss_Stage2_Border;
extern ShooterSprite Spr_Boss_Stage2_Hangonchou;

//폭발 효과
extern ShooterSprite Spr_Explosion_Big;
extern ShooterSprite Spr_Explosion_Small;

//아이템
extern ShooterSprite Spr_BomberItem;
extern ShooterSprite Spr_ExtendItem;
extern ShooterSprite Spr_PowerupItem_Big;
extern ShooterSprite Spr_PowerupItem_Small;
extern ShooterSprite Spr_ScoreItem_Big;
extern ShooterSprite Spr_ScoreItem_Small;

//보스 체력게이지
extern ShooterSurface Sur_BossHP;

//보스 커서
extern ShooterSprite Spr_BossCursor;

//스테이지 배경
extern ShooterSprite Spr_Stage1;
extern ShooterSprite Spr_Stage1_Boss;
extern ShooterSprite Spr_Stage2;
extern ShooterSprite Spr_Stage2_Boss;
extern ShooterSprite Spr_Stage3;
extern ShooterSprite Spr_Stage4;
extern ShooterSprite Spr_Stage5;
extern ShooterSprite Spr_Stage6;

//폰트
extern ShooterFont GameSmallSizeFont;
extern ShooterFont GameNormalSizeFont;

//그래픽 폰트
extern ShooterSprite Spr_TinyFont;
extern ShooterSprite Spr_NumbersFont;
extern ShooterSprite Spr_NormalFont;
extern ShooterSprite Spr_NormalFont_Gray;
extern ShooterSprite Spr_NormalFont_Selected;
extern ShooterSprite Spr_NormalFont_Others;
extern ShooterSprite Spr_NormalFont_Others_Gray;
extern ShooterSprite Spr_NormalFont_Others_Selected;

//상태 아이콘
extern ShooterSprite Spr_PlayerLife;
extern ShooterSprite Spr_PlayerBomber;

extern ShooterSprite Spr_SpellIndex;

//이벤트 창
extern ShooterSprite Spr_ScriptBox;

//이벤트창에서의 캐릭터
extern ShooterSprite Spr_Portrait_Reimu0;
extern ShooterSprite Spr_Portrait_Marisa0;
extern ShooterSprite Spr_Portrait_Reisen0;
extern ShooterSprite Spr_Portrait_Youmu0;
extern ShooterSprite Spr_Portrait_Yuuko0;

//풀사이즈 캐릭터
extern ShooterSprite Spr_FullPortrait_Reimu;
extern ShooterSprite Spr_FullPortrait_Marisa;
extern ShooterSprite Spr_FullPortrait_Reisen;

//컷인
extern ShooterSprite Spr_CutIn_Reimu;
extern ShooterSprite Spr_CutIn_Marisa;
extern ShooterSprite Spr_CutIn_Reisen;
extern ShooterSprite Spr_CutIn_Youmu;
extern ShooterSprite Spr_CutIn_Yuuko;

//엔딩 크레딧 배경
extern ShooterSprite Spr_Credits_Background;

//사운드
extern ShooterSoundManager MySoundManager;

extern ShooterSound Sound_BossDead;
extern ShooterSound Sound_Bullet;
extern ShooterSound Sound_EnemyDead;
extern ShooterSound Sound_EnemyDamaged;
extern ShooterSound Sound_Item;
extern ShooterSound Sound_PlayerDead;
extern ShooterSound Sound_PowerUp;

extern ShooterSound Sound_BossFatal;
extern ShooterSound Sound_Cancel;
extern ShooterSound Sound_Extend;
extern ShooterSound Sound_Graze;
extern ShooterSound Sound_Kira;
extern ShooterSound Sound_Laser;
extern ShooterSound Sound_Okay;
extern ShooterSound Sound_Pause;
extern ShooterSound Sound_Select;
extern ShooterSound Sound_PlayerShot;
extern ShooterSound Sound_StageClear;
extern ShooterSound Sound_SpellCard;

extern ShooterSound Sound_Timeout;

extern ShooterSound Sound_MasterSpark;

//뮤직
extern ShooterSound Music_MainMenu;
extern ShooterSound Music_GameOver;
extern ShooterSound Music_Stage1Field;
extern ShooterSound Music_Stage1Boss;
extern ShooterSound Music_Stage2Field;
extern ShooterSound Music_Stage2Boss;
extern ShooterSound Music_Stage2Boss_Final;
extern ShooterSound Music_Credits;


//스테이지 (임시)
extern GameStage Stage;

//플레이어
extern GamePlayer Player;

extern GamePlayerShot PlayerShot_Reimu_0;
extern GamePlayerShot PlayerShot_Reimu_Sub_0;

extern GamePlayerShot PlayerShot_Reimu_Rapier_0;

extern GamePlayerShot PlayerShot_Reimu_Bomber;

extern GamePlayerShot PlayerShot_Marisa_0;
extern GamePlayerShot PlayerShot_Marisa_Rapier_0;

extern GamePlayerShot PlayerShot_Marisa_Bomber;

extern GamePlayerShot PlayerShot_Reisen_0;
extern GamePlayerShot PlayerShot_Reisen_1;
extern GamePlayerShot PlayerShot_Reisen_2;

extern GamePlayerShot PlayerShot_Reisen_Bomber;

extern GamePlayerHeatBox PlayerHeatBox;

//총알 및 적군
extern std::vector<GameEnemy*> GameEnemyVector;
extern std::vector<GameBullet*> GameBulletVector;
extern std::vector<GameExplosion*> GameExplosionVector;
extern std::vector<GamePlayerShot*> GamePlayerShotVector;
extern std::vector<GameItem*> GameItemVector;

extern GameObject Obj_Boss_Stage2_Border;

//적군 벡터 (예비)
extern std::vector<GameEnemy*> PreEnemyBulletVector;

//탄막
extern std::vector<GameBarrage*> BarrageVector;

//보스
extern GameBoss * pBoss;