#pragma once
#include "../MemoryLeakChecker.h"
#include <string>
#include "../GameCore/CommonUtil.h"

typedef void (*BarrageFunctionInit)(GameObject *, int, int, int, int, int, int*);
typedef void (*BarrageFunction) (GameObject *, int*);
class GameBarrage
{
private:
	void InitBarrage();
public:
	GameBarrage();
	GameBarrage(std::string IN_Name, BarrageFunctionInit IN_Init, BarrageFunction IN_Function);
	GameBarrage(GameBarrage * IN_pBarrage);
	std::string Name;
	BarrageFunctionInit pInit;
	BarrageFunction pFunction;
	int iBarrageParameters[10];
};
