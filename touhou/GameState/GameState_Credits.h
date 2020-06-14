#pragma once

#include "../MemoryLeakChecker.h"
#include "../GameCore/Declarations.h"
#include "../GameCore/CommonUtil.h"
#include "../GameState/GameState_Game.h"

extern int iCurrentGameCreditItem;

extern int iCurrentGameCreditLastItemRemainTime;

extern std::vector<GameObject *> vGameCreditItems;

extern std::vector<ShooterSprite * > vSpr_GameCreditItems;

#define CREDIT_MAX_ITEMS 8
#define CREDIT_ITEMS_SPEED 1.0
#define CREDIT_ITEMS_SPAN 100

#define CREDIT_ITEMS_LAST_ITEM_REMAIN_TIME 300

extern void InitGameCredits();
extern void MakeCreditItem();
extern void Input_GameCredits();
extern void Draw_GameCredits();
extern void ExitGameCredits();
extern void UnloadGameCredits();
extern void UnloadGameCreditsSprite();