//////////////////////////////////////////////////////////////////////////
//
// GameState_Game - 'GameState' 중 'Game' 상태의 처리를 담당한다.
// (실질적인 본 게임화면)
//
//////////////////////////////////////////////////////////////////////////

#pragma once
#include "../MemoryLeakChecker.h"
#include "../GameCore/Declarations.h"
#include "../GameCore/CommonUtil.h"
#include "../PlayerShotFunctions/PlayerShot_Reimu.h"
#include "../PlayerShotFunctions/PlayerShot_Marisa.h"
#include "../BomberFunctions/Bomber_Reimu.h"
#include "../BomberFunctions/Bomber_Marisa.h"
#include "../BomberFunctions/Bomber_Reisen.h"
#include "GameState_GameUtil.h"
#include "../GameStage/Game_Stage1.h"
#include "../GameStage/Game_Stage2.h"
#include "Sample.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define UI_FPS_X 580
#define UI_FPS_Y 470

#define UI_WINDOW_LEFT_X 0
#define UI_WINDOW_LEFT_Y 0
#define UI_WINDOW_LEFT_WIDTH 30
#define UI_WINDOW_LEFT_HEIGHT 480
#define UI_WINDOW_RIGHT_X 415
#define UI_WINDOW_RIGHT_Y 0
#define UI_WINDOW_RIGHT_WIDTH 225
#define UI_WINDOW_RIGHT_HEIGHT 480
#define UI_WINDOW_TOP_X 30
#define UI_WINDOW_TOP_Y 0
#define UI_WINDOW_TOP_WIDTH 385
#define UI_WINDOW_TOP_HEIGHT 14
#define UI_WINDOW_BOTTOM_X 30
#define UI_WINDOW_BOTTOM_Y 464
#define UI_WINDOW_BOTTOM_WIDTH 385
#define UI_WINDOW_BOTTOM_HEIGHT 16

#define UI_DARKSCREEN_X UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH
#define UI_DARKSCREEN_Y UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT

#define UI_SPELLCOUNT_X 36
#define UI_SPELLCOUNT_Y 35

#define UI_BOSSHP_X 64
#define UI_BOSSHP_Y 19

#define UI_SPELL_COUNTDOWN_X 385
#define UI_SPELL_COUNTDOWN_Y 16

#define UI_SPELL_CHARANAME_X 36
#define UI_SPELL_CHARANAME_Y 22

#define UI_SPELL_SPELLNAME_X_RIGHT 399
#define UI_SPELL_SPELLNAME_Y 33

#define UI_HISCORE_X 495
#define UI_HISCORE_Y 42

#define UI_PLAYERSCORE_X 495
#define UI_PLAYERSCORE_Y 65

#define UI_PLAYERGRAZE_X 495
#define UI_PLAYERGRAZE_Y 260

#define UI_PLAYERLIFE_X 515
#define UI_PLAYERLIFE_Y 100

#define UI_PLAYERBOMBER_X 515
#define UI_PLAYERBOMBER_Y 138

extern bool bPause;
extern bool bPause_Query;
extern bool bPause_Query_YesNo;

typedef enum PAUSEMENU_STATUS
{
	PAUSEMENU_RETURN = 0,
	PAUSEMENU_EXIT,
	PAUSEMENU_RETRY
};

typedef enum GAMEOVERMENU_STATUS
{
	GAMEOVERMENU_CONTINUE = 0,
	GAMEOVERMENU_EXIT,
	GAMEOVERMENU_RETRY
};

#define UI_PAUSEMENU_TITLE_X 46
#define UI_PAUSEMENU_TITLE_Y 224

#define UI_PAUSEMENU_ITEMS_X 73
#define UI_PAUSEMENU_ITEMS_Y 275

#define UI_PAUSEMENU_QUESTION_X 74
#define UI_PAUSEMENU_QUESTION_Y 291

#define UI_PAUSEMENU_YES_X 74
#define UI_PAUSEMENU_YES_Y 332

#define ITEM_GET_BORDER_LINE_Y 144

#define DISPLAY_BGM_NAME_SPAN_X 15
#define DISPLAY_BGM_NAME_SPAN_Y 15
#define DISPLAY_BGM_NAME_DURATION 180

extern bool bNowDisplayBGMName;
extern int iCurrentBGMDisplayTime;

extern int iCurrentPauseMenuStatus;
extern int iCurrentGameOverMenuStatus;


extern ShooterSprite PrintedBossName;
extern ShooterSprite PrintedSpellName;
extern ShooterSprite PrintedBGMName;

void InitGame(PlayerCharaType IN_CharaType);
void InitPlayerBomber();
void PreTreat_Game();
void Input_Game();

void GameState_Game();

void GoToMainMenu();

void GiveUpAndRetry();

//포트레이트 출력
void DrawPortrait(ShooterSprite * IN_Sprite, double IN_x, double IN_Y, int * IN_CurrentFrame, int IN_DesiredFrame);

//보스 HP 출력
void DrawBossHP();

void NextStage();
void StartCurrentStage();

void StopMusicAllinOne();
void FreeMusicAllInOne();
void PauseMusicAllInOne();
void ResumeMusicAllInOne();

void ShowBGMName(std::string IN_BGMName);