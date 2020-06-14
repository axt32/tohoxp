#include "Declarations.h"


//게임 시스템
bool bRunning;
double fFrameRate = 0.0;
int iGameState;
int iGameFrame = 0;
int iOldGameFrame = 0;
int iOldGameFrame_EnemyDamaged = 0;
int iOldGameFrame_EnemyDead = 0;
Uint32 iFrameTime = 0;

int iCurrentStage = 1;	//1부터
GAMESTATE_GAME_STATUS iGameState_Game_Status;
GAMESTATE_GAME_PAUSETYPE iGameState_Game_PauseType;

extern bool bOnceDescreteInput = false;

double fTimeFactor = 0.0;

INIManager MyINIManager;

KEY iKey_Up;
KEY iKey_Down;
KEY iKey_Left;
KEY iKey_Right;
KEY iKey_Attack;
KEY iKey_Bomber;
KEY iKey_Slow;
KEY iKey_Skip;

bool bBGM_Use = false;
bool bSE_Use = false;

double fVolume_BGM = 1.0;
double fVolume_SE = 0.75;

//게임 스크린 및 인풋
ShooterScreen GameScreen;
ShooterSprite DarkScreen;
ShooterSprite DarkScreen_Record;
ShooterSprite DarkScreen_Result;
ShooterSprite DarkScreen_CompanyLogo;

ShooterInput GameInput;

//스프라이트
ShooterSprite Spr_Reimu_Front;
ShooterSprite Spr_Reimu_Left;
ShooterSprite Spr_Reimu_Right;

ShooterSprite Spr_Marisa_Front;
ShooterSprite Spr_Marisa_Left;
ShooterSprite Spr_Marisa_Right;

ShooterSprite Spr_Reisen_Front;
ShooterSprite Spr_Reisen_Left;
ShooterSprite Spr_Reisen_Right;

ShooterSprite Spr_PlayerShot_Reimu_0;
ShooterSprite Spr_PlayerShot_Reimu_0_Sub;
ShooterSprite Spr_PlayerShot_Reimu_Rapier_0;
ShooterSprite Spr_PlayerShot_Reimu_Bomber;

ShooterSprite Spr_PlayerShot_Marisa_0;
ShooterSprite Spr_PlayerShot_Marisa_Rapier_0;
ShooterSprite Spr_PlayerShot_Marisa_Bomber;

ShooterSprite Spr_PlayerShot_Reisen_0;
ShooterSprite Spr_PlayerShot_Reisen_1;
ShooterSprite Spr_PlayerShot_Reisen_2;

ShooterSprite Spr_PlayerShot_Reisen_Bomber;

ShooterSprite Spr_PlayerHeatBox;

ShooterSprite Spr_BulletType0;
ShooterSprite Spr_BulletType1;
ShooterSprite Spr_BulletType2;
ShooterSprite Spr_BulletType3;
ShooterSprite Spr_BulletType4;
ShooterSprite Spr_BulletType5;
ShooterSprite Spr_BulletType6;
ShooterSprite Spr_BulletType7;
ShooterSprite Spr_BulletType8;
ShooterSprite Spr_BulletType9;
ShooterSprite Spr_BulletType10;
ShooterSprite Spr_BulletType11;
ShooterSprite Spr_BulletType12;
ShooterSprite Spr_BulletType13;
ShooterSprite Spr_BulletType14;
ShooterSprite Spr_BulletType15;
ShooterSprite Spr_BulletType16;
ShooterSprite Spr_BulletType17;
ShooterSprite Spr_BulletType18;

ShooterSprite Spr_UI_NowLoading;

ShooterSprite Spr_UI_CompanyLogo;

ShooterSprite Spr_UI_MainMenu_Background;

ShooterSprite Spr_UI_MainMenu_Gamelogo;

ShooterSprite Spr_UI_MainMenu_Sortie;
ShooterSprite Spr_UI_MainMenu_Sortie_Selected;

ShooterSprite Spr_UI_MainMenu_Record;
ShooterSprite Spr_UI_MainMenu_Record_Selected;

ShooterSprite Spr_UI_MainMenu_Exit;
ShooterSprite Spr_UI_MainMenu_Exit_Selected;

ShooterSprite Spr_UI_MainMenu_Copyright;

ShooterSprite Spr_UI_CharaSelect_Title;
ShooterSprite Spr_UI_CharaSelect_Description_Reimu;
ShooterSprite Spr_UI_CharaSelect_Description_Marisa;
ShooterSprite Spr_UI_CharaSelect_Description_Reisen;

ShooterSprite Spr_UI_Record_Background;

ShooterSprite Spr_UI_Record_Title;

ShooterSprite Spr_UI_Window_Left;
ShooterSprite Spr_UI_Window_Right;
ShooterSprite Spr_UI_Window_Top;
ShooterSprite Spr_UI_Window_Bottom;

ShooterSprite Spr_UI_GameOverMenu_New_Continue;
ShooterSprite Spr_UI_GameOverMenu_New_Continue_Selected;

ShooterSprite Spr_UI_PauseMenu_New_Yes;
ShooterSprite Spr_UI_PauseMenu_New_Yes_Selected;

ShooterSprite Spr_UI_PauseMenu_New_No;
ShooterSprite Spr_UI_PauseMenu_New_No_Selected;

ShooterSprite Spr_UI_PauseMenu_New_Question;

ShooterSprite Spr_UI_PauseMenu_New_Return;
ShooterSprite Spr_UI_PauseMenu_New_Return_Selected;

ShooterSprite Spr_UI_PauseMenu_New_Exit;
ShooterSprite Spr_UI_PauseMenu_New_Exit_Selected;

ShooterSprite Spr_UI_PauseMenu_New_Retry;
ShooterSprite Spr_UI_PauseMenu_New_Retry_Selected;

ShooterSprite Spr_UI_PauseMenu_New_Title;

ShooterSprite Spr_UI_GameOverMenu_New_Title;

ShooterSprite Spr_UI_Result_Reimu;
ShooterSprite Spr_UI_Result_Marisa;
ShooterSprite Spr_UI_Result_Reisen;

ShooterSprite Spr_UI_EnemySpell;

ShooterSprite Spr_UI_Extend;

ShooterSprite Spr_EnemyType0;
ShooterSprite Spr_EnemyType0_A;
ShooterSprite Spr_EnemyType0_B;
ShooterSprite Spr_EnemyType1;
ShooterSprite Spr_EnemyType1_A;
ShooterSprite Spr_EnemyType1_B;
ShooterSprite Spr_EnemyType2;
ShooterSprite Spr_EnemyType2_A;
ShooterSprite Spr_EnemyType2_B;
ShooterSprite Spr_EnemyType3;
ShooterSprite Spr_EnemyType3_A;
ShooterSprite Spr_EnemyType3_B;
ShooterSprite Spr_EnemyType4;
ShooterSprite Spr_EnemyType4_A;
ShooterSprite Spr_EnemyType4_B;
ShooterSprite Spr_EnemyType5;
ShooterSprite Spr_EnemyType5_A;
ShooterSprite Spr_EnemyType5_B;

ShooterSprite Spr_Boss_Stage1;
ShooterSprite Spr_Boss_Stage1_A;
ShooterSprite Spr_Boss_Stage1_B;

ShooterSprite Spr_Boss_Stage2;
ShooterSprite Spr_Boss_Stage2_Invincible;
ShooterSprite Spr_Boss_Stage2_Border;
ShooterSprite Spr_Boss_Stage2_Hangonchou;

ShooterSprite Spr_Explosion_Big;
ShooterSprite Spr_Explosion_Small;

ShooterSprite Spr_BomberItem;
ShooterSprite Spr_ExtendItem;
ShooterSprite Spr_PowerupItem_Big;
ShooterSprite Spr_PowerupItem_Small;
ShooterSprite Spr_ScoreItem_Big;
ShooterSprite Spr_ScoreItem_Small;

//보스 체력게이지
ShooterSurface Sur_BossHP;

//보스 커서
ShooterSprite Spr_BossCursor;

//스테이지 배경
ShooterSprite Spr_Stage1;
ShooterSprite Spr_Stage1_Boss;
ShooterSprite Spr_Stage2;
ShooterSprite Spr_Stage2_Boss;
ShooterSprite Spr_Stage3;
ShooterSprite Spr_Stage4;
ShooterSprite Spr_Stage5;
ShooterSprite Spr_Stage6;

//폰트
ShooterFont GameSmallSizeFont;
ShooterFont GameNormalSizeFont;

//그래픽 폰트
ShooterSprite Spr_TinyFont;
ShooterSprite Spr_NumbersFont;
ShooterSprite Spr_NormalFont;
ShooterSprite Spr_NormalFont_Gray;
ShooterSprite Spr_NormalFont_Selected;
ShooterSprite Spr_NormalFont_Others;
ShooterSprite Spr_NormalFont_Others_Gray;
ShooterSprite Spr_NormalFont_Others_Selected;

//상태 아이콘
ShooterSprite Spr_PlayerLife;
ShooterSprite Spr_PlayerBomber;

ShooterSprite Spr_SpellIndex;

ShooterSprite Spr_ScriptBox;

//이벤트창에서의 캐릭터
ShooterSprite Spr_Portrait_Reimu0;
ShooterSprite Spr_Portrait_Marisa0;
ShooterSprite Spr_Portrait_Reisen0;
ShooterSprite Spr_Portrait_Youmu0;
ShooterSprite Spr_Portrait_Yuuko0;

//풀사이즈 캐릭터
ShooterSprite Spr_FullPortrait_Reimu;
ShooterSprite Spr_FullPortrait_Marisa;
ShooterSprite Spr_FullPortrait_Reisen;

//컷인
ShooterSprite Spr_CutIn_Reimu;
ShooterSprite Spr_CutIn_Marisa;
ShooterSprite Spr_CutIn_Reisen;
ShooterSprite Spr_CutIn_Youmu;
ShooterSprite Spr_CutIn_Yuuko;

//엔딩 크레딧 배경
ShooterSprite Spr_Credits_Background;

//사운드
ShooterSoundManager MySoundManager;
ShooterSound Sound_BossDead;
ShooterSound Sound_Bullet;
ShooterSound Sound_EnemyDead;
ShooterSound Sound_EnemyDamaged;
ShooterSound Sound_Item;
ShooterSound Sound_PlayerDead;
ShooterSound Sound_PowerUp;

ShooterSound Sound_BossFatal;
ShooterSound Sound_Cancel;
ShooterSound Sound_Extend;
ShooterSound Sound_Graze;
ShooterSound Sound_Kira;
ShooterSound Sound_Laser;
ShooterSound Sound_Okay;
ShooterSound Sound_Pause;
ShooterSound Sound_Select;
ShooterSound Sound_PlayerShot;
ShooterSound Sound_StageClear;
ShooterSound Sound_SpellCard;

ShooterSound Sound_Timeout;

ShooterSound Sound_MasterSpark;

//뮤직
ShooterSound Music_MainMenu;
ShooterSound Music_GameOver;
ShooterSound Music_Stage1Field;
ShooterSound Music_Stage1Boss;
ShooterSound Music_Stage2Field;
ShooterSound Music_Stage2Boss;
ShooterSound Music_Stage2Boss_Final;
ShooterSound Music_Credits;

//스테이지 (임시)
GameStage Stage;

//플레이어
GamePlayer Player;

GamePlayerShot PlayerShot_Reimu_0;
GamePlayerShot PlayerShot_Reimu_Sub_0;
GamePlayerShot PlayerShot_Reimu_Rapier_0;
GamePlayerShot PlayerShot_Reimu_Bomber;

GamePlayerShot PlayerShot_Marisa_0;
GamePlayerShot PlayerShot_Marisa_Rapier_0;

GamePlayerShot PlayerShot_Marisa_Bomber;

GamePlayerShot PlayerShot_Reisen_0;
GamePlayerShot PlayerShot_Reisen_1;
GamePlayerShot PlayerShot_Reisen_2;
GamePlayerShot PlayerShot_Reisen_Bomber;

GamePlayerHeatBox PlayerHeatBox;

//총알 및 적군
std::vector<GameEnemy*> GameEnemyVector;
std::vector<GameBullet*> GameBulletVector;
std::vector<GameExplosion*> GameExplosionVector;
std::vector<GamePlayerShot*> GamePlayerShotVector;
std::vector<GameItem*> GameItemVector;

GameObject Obj_Boss_Stage2_Border;

//적군 벡터 (예비)
std::vector<GameEnemy*> PreEnemyBulletVector;

//탄막
std::vector<GameBarrage*> BarrageVector;

//보스
GameBoss * pBoss = NULL;