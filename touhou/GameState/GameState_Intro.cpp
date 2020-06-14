#include "GameState_Intro.h"

void Input_Intro()
{
	if (GameInput.GetInput(QUIT))
	{
		bRunning = false;
		return;
	}

}
void Draw_Intro()
{
	static int iIntroStatus = 0;
	static int iIntroTime = 0;

	if (iIntroStatus == 0)
	{
		// R = G = B이면 흰색~회색~흑색 으로 나온다.
		int iAlpha = SDL_ALPHA_TRANSPARENT + RoundInt((double)iIntroTime / ( (double)UI_INTROTIME / 3.0) * 255.0);
		if (iAlpha > 255)
		{
			iAlpha = 255;
		}

		Spr_UI_CompanyLogo.SetAlpha(  iAlpha );
		GameScreen.FillColor( iAlpha, iAlpha, iAlpha, 255 );


		
		iIntroTime++;
		if (iIntroTime > RoundInt((double)UI_INTROTIME / 3.0))
		{
			iIntroTime = 0;
			iIntroStatus = 1;
		}
	}
	else if (iIntroStatus == 1)
	{
		Spr_UI_CompanyLogo.SetAlpha(  255 );
		GameScreen.FillColor(255, 255, 255, 255 );

		iIntroTime++;
		if (iIntroTime > RoundInt((double)UI_INTROTIME / 3.0))
		{
			iIntroTime = 0;
			iIntroStatus = 2;
		}
	}
	else
	{
		int iAlpha = SDL_ALPHA_OPAQUE - RoundInt((double)iIntroTime / ( (double)UI_INTROTIME / 3.0) * 255.0);
		if (iAlpha < 0)
		{
			iAlpha = 0;
		}
		Spr_UI_CompanyLogo.SetAlpha(  iAlpha );
		GameScreen.FillColor( iAlpha, iAlpha, iAlpha, 255);

		iIntroTime++;
		if (iIntroTime > RoundInt((double)UI_INTROTIME / 3.0) )
		{
			Init_MainMenu();
		}
	}

	Spr_UI_CompanyLogo.DrawSpriteCenter(GAMEWIDTH / 2, GAMEHEIGHT / 2, 0);

}
