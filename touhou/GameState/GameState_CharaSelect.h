#pragma once
#include "../MemoryLeakChecker.h"
#include "../GameCore/Declarations.h"
#include "../GameCore/CommonUtil.h"
#include "GameState_MainMenu.h"
#include "GameState_Game.h"

#define UI_CHARASELECT_TITLE_X 56
#define UI_CHARASELECT_TITLE_Y 15
#define UI_CHARASELECT_PORTRAIT_X 0
#define UI_CHARASELECT_PORTRAIT_Y 65
#define UI_CHARASELECT_DESCRIPTION_X 375
#define UI_CHARASELECT_DESCRIPTION_Y 275

#define UI_CHARASELECT_PORTRAIT_SHOWANIMATION_DURATION  30
#define UI_CHARASELECT_DESCRIPTION_SHOWANIMATION_DURATION 30 

extern int iCharaSelect_CurrentCharacter;

extern int iCharaSelect_Portrait_CurrentTime;
extern int iCharaSelect_Description_CurrentTime;

void Input_CharaSelect();

void Init_CharaSelect();
void Draw_CharaSelect();