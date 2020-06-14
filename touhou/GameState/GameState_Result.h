#pragma once
#include "../MemoryLeakChecker.h"
#include "../GameCore/Declarations.h"
#include "../GameCore/CommonUtil.h"
#include "../GameState/GameState_Game.h"

#define RESULTTIME 60

#define UI_RESULT_TITLE_X 74
#define UI_RESULT_TITLE_Y 103

#define UI_RESULT_ITEMS_X 74
#define UI_RESULT_ITEMS_Y 149

void InitResult();

void DrawResult();