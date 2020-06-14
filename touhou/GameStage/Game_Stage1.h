#pragma once
#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_Game.h"
#include "../BarrageFunctions/Barrage_Stage1Field.h"
#include "../BarrageFunctions/Barrage_Stage2Field.h"
#include "../BarrageFunctions/Barrage_Stage1Boss.h"

void InitGameStage1();
void InitStage1Boss();
void InitStage1Event();

void Stage1BossSpell0Init();
void Stage1BossSpell0();

void Stage1BossSpell1Init();
void Stage1BossSpell1();

void Stage1BossSpell2Init();
void Stage1BossSpell2();

void InitStage1Event_After_Boss();