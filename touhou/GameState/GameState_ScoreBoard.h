#pragma once

#include "../MemoryLeakChecker.h"
#include "../GameCore/Declarations.h"
#include "../GameCore/CommonUtil.h"
#include "../GameState/GameState_Game.h"

#include "../ExternalUtil/CSVManager/CSVManager.h"

#define SCOREBOARD_STATUS_TITLE_X 120
#define SCOREBOARD_STATUS_TITLE_Y 65

#define SCOREBOARD_TITLE_X 43
#define SCOREBOARD_TITLE_Y 43
		  
#define SCOREBOARD_STATUS_TABLE_COLUMN0_X 43
#define SCOREBOARD_STATUS_TABLE_COLUMN0_Y 97
		   
#define SCOREBOARD_STATUS_TABLE_COLUMN1_X (SCOREBOARD_STATUS_TABLE_COLUMN0_X + Spr_NumbersFont.GetWidth() * (2 + 1))
#define SCOREBOARD_STATUS_TABLE_COLUMN1_Y 97
		   
#define SCOREBOARD_STATUS_TABLE_COLUMN2_X (SCOREBOARD_STATUS_TABLE_COLUMN1_X + Spr_NumbersFont.GetWidth() * (6 + 1))
#define SCOREBOARD_STATUS_TABLE_COLUMN2_Y 97
		   
#define SCOREBOARD_STATUS_TABLE_COLUMN3_X (SCOREBOARD_STATUS_TABLE_COLUMN2_X + Spr_NumbersFont.GetWidth() * (8 + 1))
#define SCOREBOARD_STATUS_TABLE_COLUMN3_Y 97

#define SCOREBOARD_STATUS_TABLE_COLUMN4_X (SCOREBOARD_STATUS_TABLE_COLUMN3_X + Spr_NumbersFont.GetWidth() * (9 + 1))
#define SCOREBOARD_STATUS_TABLE_COLUMN4_Y 97

#define SCOREBOARD_STATUS_CHARTABLE_X 113
#define SCOREBOARD_STATUS_CHARTABLE_Y 298

#define SCOREBOARD_STATUS_CHARTABLE_Y_ADD 30

#define SCOREBOARD_STATUS_CHARTABLE_ROWS 8
#define SCOREBOARD_STATUS_CHARTABLE_COLUMNS 13

#define UI_EXTEND_APPEAR_REMAIN_TIME 120

struct Record
{
	std::string sName;
	std::string sChara;
	int iScore;
	std::string sDate;
	int iStage;
};

extern int iHiScore;

extern bool bOnceExtended;
extern int iExtendAppearRemainTime;

extern int iScoreBoard_Score_PosCol;
extern int iScoreBoard_Score_PosRow;

bool LoadRecord();
bool CheckRecord();
bool GoToFirst();
bool GetRecord(std::string * OUT_sName, std::string * OUT_sChara, int * OUT_iScore, std::string * OUT_sDate, int * OUT_iStage, bool * OUT_isPlayer = NULL);
bool ClearRecord();

bool InsertChar(int IN_Order);
bool DeleteOneChar();
bool InsertBlank();
bool isNameFull();
int OrderToAscii(int IN_Order);

bool SaveRecord();

void ScoreBoard_Left();
void ScoreBoard_Right();
void ScoreBoard_Up();
void ScoreBoard_Down();

bool Input_ScoreBoard();

void ScoreBoard_Cancel();

//출력부분
void Init_ScoreBoard_State(bool IN_InputScore);
void Draw_ScoreBoard_State();

void Input_RecordStatus();

void DrawCharTable(int IN_x, int IN_y);
