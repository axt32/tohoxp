#pragma once
#include "../MemoryLeakChecker.h"
#include "../GameState/GameState_Game.h"
#include "../BarrageFunctions/Barrage_Stage2Field.h"
#include "../BarrageFunctions/Barrage_Stage2Boss.h"

extern int iHangonchou_CurrentAngle;

void InitGameStage2();
void InitStage2Boss();
void InitStage2Event();

void Stage2BossSpell0Init();
void Stage2BossSpell0();

void Stage2BossSpell1Init();
void Stage2BossSpell1();

void Stage2BossSpell2Init();
void Stage2BossSpell2();

void Stage2BossSpell3Init();
void Stage2BossSpell3();

void Stage2BossSpell4Init();
void Stage2BossSpell4();

void Stage2BossFinalSpellInit();
void Stage2BossFinalSpell();

void InitStage2Event_After_Boss();