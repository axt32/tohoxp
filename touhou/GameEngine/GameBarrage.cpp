#include "GameBarrage.h"

void GameBarrage :: InitBarrage()
{
	for (int i = 0; i < 10; i++)
	{
		iBarrageParameters[i] = 0;
	}
}

GameBarrage :: GameBarrage()
{
	InitBarrage();
}
GameBarrage :: GameBarrage(std::string IN_Name, BarrageFunctionInit IN_Init, BarrageFunction IN_Function)
{
	Name = IN_Name;
	pInit = IN_Init;
	pFunction = IN_Function;

	InitBarrage();
}
GameBarrage :: GameBarrage(GameBarrage * IN_pBarrage)
{

	Name = IN_pBarrage->Name;
	pInit = IN_pBarrage->pInit;
	pFunction = IN_pBarrage->pFunction;

	for (int i = 0; i < 10; i++)
	{
		iBarrageParameters[i] = IN_pBarrage->iBarrageParameters[i];
	}

}