#include "GamePlayerHeatBox.h"

void GamePlayerHeatBox :: InitPlayerHeatBox()
{

}

GamePlayerHeatBox :: GamePlayerHeatBox() : GameObject(TYPE_PLAYERHEATBOX)
{
	InitPlayerHeatBox();
}
GamePlayerHeatBox :: GamePlayerHeatBox(ShooterSprite * IN_Sprite) : GameObject(TYPE_PLAYERHEATBOX, IN_Sprite, true, false)
{
	InitPlayerHeatBox();
}
GamePlayerHeatBox :: ~GamePlayerHeatBox()
{

}