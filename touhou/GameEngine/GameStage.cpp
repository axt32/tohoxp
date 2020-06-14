#include "GameStage.h"

void GameStage :: InitGameStage()
{
	iScrollType = SCROLLTYPE_NONE;
	fPos = 0;
	fPosX = 0;
	fPosY = 0;
	fSpeedX = 0;
}

void GameStage :: Roll(double IN_TimeFactor)
{
	int iWidth = GetSprite()->GetSurfaceWidth();
	int iHeight = GetSprite()->GetSurfaceHeight();

	if (iScrollType == SCROLLTYPE_VERTICAL)
	{
		fPos = fPos + speed * IN_TimeFactor;

		if (fPos <= -(double)(iHeight))		//fPos가 음수
		{
			fPos = (double)(iHeight) + fPos;
		}
		else if (abs(fPos) >= (double)(GetSprite()->GetSurfaceHeight()))		//fPos가 양수
		{
			fPos = (double)(iHeight) - fPos;
		}
	}
	else if (iScrollType == SCROLLTYPE_DIAGONAL)
	{
 		fPosX = fPosX + fSpeedX * IN_TimeFactor;
 		fPosY = fPosY + speed * IN_TimeFactor;

		if ((fPosX) >= (double)(iGameLeft + iWidth))
		{
			fPosX = fPosX - (double)iWidth;
		}
		
		if ((fPosY) >= (double)(iGameTop + iHeight))
		{
			fPosY = fPosY - (double)iHeight;
		}
	}

}

bool GameStage :: Draw()
{
	bool bResult = true;

	int iWidth = GetSprite()->GetSurfaceWidth();
	int iHeight = GetSprite()->GetSurfaceHeight();

	if (iScrollType == SCROLLTYPE_NONE)
	{
		bResult = bResult & GameObject::Draw();
	}
	else if (iScrollType == SCROLLTYPE_VERTICAL)
	{
		double OldY = y;
		double TopY = y + fPos;
		double BottomY;

		if (speed > 0)
		{
			BottomY = TopY - (double)(iHeight);
		}
		else
		{
			BottomY = TopY + (double)(iHeight);
		}

		y = TopY;
		bResult = GameObject::Draw();

		y = BottomY;
		bResult = bResult & GameObject::Draw();

		y = OldY;
	}
	else if (iScrollType == SCROLLTYPE_DIAGONAL)
	{
		if (fPosY > (double)iGameTop)
		{
			y = fPosY - (double)iHeight;
		}
		else
		{
			y = fPosY;
		}

		while (true)
		{
			if (y >= (double)iGameBottom)
			{
				break;
			}

			if (fPosX > (double)iGameLeft)
			{
				x = fPosX - (double)iWidth;
			}
			else
			{
				x = fPosX;
			}

 			while ( true )
 			{

				if ( x >= (double)iGameRight)
				{
					break;
				}

				//출력
				bResult = bResult & GameObject::Draw();

				x = x + (double) (iWidth);
			}

			y = y + (double)(iHeight);
		}
		
	}

	return bResult;
}
GameStage :: GameStage() : GameObject(TYPE_STAGE)
{
	InitGameStage();
}
GameStage :: GameStage(ShooterSprite * IN_Sprite) : GameObject(TYPE_STAGE, IN_Sprite, false, false)
{
	InitGameStage();
}
GameStage :: ~GameStage()
{

}