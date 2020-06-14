#pragma once
#include "../MemoryLeakChecker.h"
#include "GameObject.h"

typedef enum ScrollType
{
	SCROLLTYPE_NONE = 0,
	SCROLLTYPE_VERTICAL,
	SCROLLTYPE_DIAGONAL
} ScrollType;

class GameStage : public GameObject
{
private:
	void InitGameStage();
public:
	ScrollType iScrollType;

	//Game Size
	int iGameLeft;
	int iGameRight;
	int iGameTop;
	int iGameBottom;
	
	//Vertical
	double fPos;

	//Diagonal
	double fPosX;
	double fPosY;

	double fSpeedX;

	void Roll(double IN_TimeFactor);
	bool Draw();
	GameStage();
	GameStage(ShooterSprite * IN_Sprite);
	~GameStage();
};