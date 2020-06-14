//////////////////////////////////////////////////////////////////////////
//
// GameState_Gameover_Score - 게임의 점수판 출력 및 점수판 관리 기능을 포함하고 있다.
//
//////////////////////////////////////////////////////////////////////////

#pragma once
#include "../MemoryLeakChecker.h"
#include "../GameCore/Declarations.h"
#include "../GameCore/CommonUtil.h"
#include "../GameState/GameState_Game.h"
#include "../GameState/GameState_ScoreBoard.h"

#define GAMEOVER_SCORE_TITLE_X 120
#define GAMEOVER_SCORE_TITLE_Y 65

#define GAMEOVER_SCORE_TABLE_COLUMN0_X 43
#define GAMEOVER_SCORE_TABLE_COLUMN0_Y 97

#define GAMEOVER_SCORE_TABLE_COLUMN1_X 76
#define GAMEOVER_SCORE_TABLE_COLUMN1_Y 97

#define GAMEOVER_SCORE_TABLE_COLUMN2_X 182
#define GAMEOVER_SCORE_TABLE_COLUMN2_Y 97

#define GAMEOVER_SCORE_TABLE_COLUMN3_X 317
#define GAMEOVER_SCORE_TABLE_COLUMN3_Y 97

#define SCOREBOARD_STATUS_CHARTABLE_X 113
#define SCOREBOARD_STATUS_CHARTABLE_Y 298

void InitGameOver_Score();
void DrawGameOver_Score();