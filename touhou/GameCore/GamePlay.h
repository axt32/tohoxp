#pragma once
#include "Declarations.h"
#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_Intro.h"
#include "../GameState/GameState_MainMenu.h"
#include "../GameState/GameState_CharaSelect.h"
#include "../GameState/GameState_Game.h"
#include "../GameState/GameState_Result.h"
#include "../GameState/GameState_ScoreBoard.h"
#include "../GameState/GameState_GameOver_Score.h"
#include "../GameState/GameState_Credits.h"

void PreTreat();
void ApplyKeyInput();
void GamePlay();
void DrawGame();
void DrawFPS();