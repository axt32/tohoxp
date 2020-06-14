#pragma once
#include "../MemoryLeakChecker.h"
#include "../GameCore/Declarations.h"

#define GAME_UI_SCRIPTBOX_X 46
#define GAME_UI_SCRIPTBOX_Y 382


typedef struct Chara
{
	std::string Name;
	std::vector <ShooterSprite *> Images;
} Chara;

typedef struct Script
{
	std::string Chara0_Name;
	int Chara0_ImageNum;
	std::string Chara1_Name;
	int Chara1_ImageNum;
	int CurrentChara;
	std::string Speech;
} Script;

extern std::vector <Chara*> CharaVector;
extern std::vector <Script*> ScriptVector;

extern std::vector<Script*>::iterator ScriptIter;
extern Chara* pCurrentChara0;
extern Chara* pCurrentChara1;

extern ShooterSprite PrintedCharaName;
extern ShooterSprite PrintedTextLine0;
extern ShooterSprite PrintedTextLine1;

extern int iColor_Event_CharaName_R;
extern int iColor_Event_CharaName_G;
extern int iColor_Event_CharaName_B;

void RegisterChara(std::string IN_Name, int IN_ImageQuantity, ShooterSprite * IN_Image);
void DeleteAllChara();

void AddScript(std::string IN_Chara0, int IN_Chara0_ImageNum, std::string IN_Chara1, int IN_Chara1_ImageNum, int IN_CurrentChara, std::string IN_Speech);
void DeleteAllScripts();

void StartScript();
bool NextScript();
void PrintScript();
void DrawScript();
