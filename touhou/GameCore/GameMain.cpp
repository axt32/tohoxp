#include "GameMain.h"

//CSVManager DeltaTimeWriter;

void LoadData()
{
	MyINIManager.SetPath("config\\config.ini");

	std::string sFullscreen = MyINIManager.LoadFromINI("WindowStyle", "Fullscreen");
	std::string sRenderer = MyINIManager.LoadFromINI("Renderer", "Renderer");
	std::string sBGM_Use = MyINIManager.LoadFromINI("Sound", "BGM_Use");
	std::string sSE_Use = MyINIManager.LoadFromINI("Sound", "SE_Use");

	auto KeyStringToShooterKey = [&] (std::string IN_KeyName) -> KEY
	{
		if ( IN_KeyName == "ESC")
			return KEY_ESCAPE;
		else if ( IN_KeyName == "F1" )
			return KEY_F1;
		else if ( IN_KeyName == "F2" )
			return KEY_F2;
		else if ( IN_KeyName == "F3" )
			return KEY_F3;
		else if ( IN_KeyName == "F4" )
			return KEY_F4;
		else if ( IN_KeyName == "F5" )
			return KEY_F5;
		else if ( IN_KeyName == "F6" )
			return KEY_F6;
		else if ( IN_KeyName == "F7" )
			return KEY_F7;
		else if ( IN_KeyName == "F8" )
			return KEY_F8;
		else if ( IN_KeyName == "F9" )
			return KEY_F9;
		else if ( IN_KeyName == "F10" )
			return KEY_F10;
		else if ( IN_KeyName == "F11" )
			return KEY_F11;
		else if ( IN_KeyName == "F12" )
			return KEY_F12;
		else if ( IN_KeyName == "~" )
			return KEY_TILDE;
		else if ( IN_KeyName == "-" )
			return KEY_MINUS;
		else if ( IN_KeyName == "+" )
			return KEY_PLUS;
		else if ( IN_KeyName == "BACKSPACE" )
			return KEY_BACKSPACE;
		else if ( IN_KeyName == "TAB" )
			return KEY_TAB;
		else if ( IN_KeyName == "[" )
			return KEY_LEFTBRACKET;
		else if ( IN_KeyName == "]" )
			return KEY_RIGHTBRACKET;
		else if ( IN_KeyName == "\\" )
			return KEY_WON;
		else if ( IN_KeyName == "CAPSLOCK" )
			return KEY_CAPSLOCK;
		else if ( IN_KeyName == ";" )
			return KEY_SEMICOLON;
		else if ( IN_KeyName == "'" )
			return KEY_QUOTE;
		else if ( IN_KeyName == "RETURN" )
			return KEY_RETURN;
		else if ( IN_KeyName == "LSHIFT" )
			return KEY_LSHIFT;
		else if ( IN_KeyName == "," )
			return KEY_COMMA;
		else if ( IN_KeyName == "." )
			return KEY_PERIOD;
		else if ( IN_KeyName == "/" )
			return KEY_SLASH;
		else if ( IN_KeyName == "RSHIFT" )
			return KEY_RSHIFT;
		else if ( IN_KeyName == "LCONTROL" )
			return KEY_LCONTROL;
		else if ( IN_KeyName == "LALT" )
			return KEY_LALT;
		else if ( IN_KeyName == "HANJA" )
			return KEY_HANJA;
		else if ( IN_KeyName == "SPACE" )
			return KEY_SPACE;
		else if ( IN_KeyName == "HANGUL" )
			return KEY_HANGUL;
		else if ( IN_KeyName == "RALT" )
			return KEY_RALT;
		else if ( IN_KeyName == "RCONTROL" )
			return KEY_RCONTROL;
		else if ( IN_KeyName == "HOME" )
			return KEY_HOME;
		else if ( IN_KeyName == "END" )
			return KEY_END;
		else if ( IN_KeyName == "INSERT" )
			return KEY_INSERT;
		else if ( IN_KeyName == "PAGEUP" )
			return KEY_PAGEUP;
		else if ( IN_KeyName == "DELETE" )
			return KEY_DELETE;
		else if ( IN_KeyName == "PAGEDOWN" )
			return KEY_PAGEDOWN;
		else if ( IN_KeyName == "UP" )
			return KEY_UP;
		else if ( IN_KeyName == "LEFT" )
			return KEY_LEFT;
		else if ( IN_KeyName == "DOWN" )
			return KEY_DOWN;
		else if ( IN_KeyName == "RIGHT" )
			return KEY_RIGHT;
		else if ( IN_KeyName == "PSCREEN" )
			return KEY_PSCREEN;
		else if ( IN_KeyName == "SCROLLLOCK" )
			return KEY_SCROLLLOCK;
		else if ( IN_KeyName == "PAUSE" )
			return KEY_PAUSE;
		else if ( IN_KeyName == "NUMLOCK" )
			return KEY_NUMLOCK;
		else if ( IN_KeyName == "NUMPAD/" )
			return KEY_NUMPADDIVIDE;
		else if ( IN_KeyName == "NUMPAD*" )
			return KEY_NUMPADMULTIPLY;
		else if ( IN_KeyName == "NUMPAD-" )
			return KEY_NUMPADSUBTRACT;
		else if ( IN_KeyName == "NUMPAD+" )
			return KEY_NUMPADADD;
		else if ( IN_KeyName == "NUMPAD." )
			return KEY_NUMPADDECIMAL;
		else if ( IN_KeyName == "NUMPAD0" )
			return KEY_NUMPAD0;
		else if ( IN_KeyName == "NUMPAD1" )
			return KEY_NUMPAD1;
		else if ( IN_KeyName == "NUMPAD2" )
			return KEY_NUMPAD2;
		else if ( IN_KeyName == "NUMPAD3" )
			return KEY_NUMPAD3;
		else if ( IN_KeyName == "NUMPAD4" )
			return KEY_NUMPAD4;
		else if ( IN_KeyName == "NUMPAD5" )
			return KEY_NUMPAD5;
		else if ( IN_KeyName == "NUMPAD6" )
			return KEY_NUMPAD6;
		else if ( IN_KeyName == "NUMPAD7" )
			return KEY_NUMPAD7;
		else if ( IN_KeyName == "NUMPAD8" )
			return KEY_NUMPAD8;
		else if ( IN_KeyName == "NUMPAD9" )
			return KEY_NUMPAD9;
		else if ( IN_KeyName == "LWIN" )
			return KEY_LWIN;
		else if ( IN_KeyName == "RWIN" )
			return KEY_RWIN;
		else if ( IN_KeyName == "RCLICKMENU")
			return KEY_RCLICKMENU;

		//숫자
		for (int i = 0x30; i <= 0x39; i++)
		{
			if (IN_KeyName.c_str()[0] == i)
			{
				return (KEY)(KEY_0 + (i - 0x30));
			}
		}

		//알파벳
		for (int i = 0x41; i <= 0x5A; i++)
		{
			if (IN_KeyName.c_str()[0] == i)
			{
				return (KEY)(KEY_A + (i - 0x41));
			}
		}

		return (KEY)(0);
	};

	auto LoadKeyConfig = [&] (std::string sCategory, KEY * OUT_Key, KEY iDefaultValue)
	{
		std::string sKey = MyINIManager.LoadFromINI("KeySetting", sCategory);
		if ( CheckValidKeyName(sKey) )
		{
			*OUT_Key = KeyStringToShooterKey(sKey);
		}
		else
		{
			*OUT_Key = iDefaultValue;
		}
	};

	auto LoadVolumeConfig = [&] (std::string sCategory, double * OUT_Value, double fDefaultValue)
	{
		std::string sVolume = MyINIManager.LoadFromINI("Sound", sCategory);
		*OUT_Value = fDefaultValue;
		if (sVolume != "")
		{
			int iTempValue = atoi(sVolume.c_str());
			if (iTempValue >= 0 && iTempValue <= 100)
			{
				*OUT_Value = (double)(iTempValue) / 100.0;
			}
		}
	};

	LoadKeyConfig("UP", &iKey_Up, KEY_UP);
	LoadKeyConfig("DOWN", &iKey_Down, KEY_DOWN);
	LoadKeyConfig("LEFT", &iKey_Left, KEY_LEFT);
	LoadKeyConfig("RIGHT", &iKey_Right, KEY_RIGHT);
	LoadKeyConfig("BUTTONA", &iKey_Attack, KEY_Z);
	LoadKeyConfig("BUTTONB", &iKey_Bomber, KEY_X);
	LoadKeyConfig("BUTTONC", &iKey_Slow, KEY_LSHIFT);
	LoadKeyConfig("SKIP", &iKey_Skip, KEY_LCONTROL);

	if (sBGM_Use == "true" || sBGM_Use == "")
	{
		bBGM_Use = true;
	}
	if (sSE_Use == "true" || sSE_Use == "")
	{
		bSE_Use = true;
	}

	LoadVolumeConfig("BGM_Volume", &fVolume_BGM, 1.0);
	LoadVolumeConfig("SE_Volume", &fVolume_SE, 0.75);

	bool bFullscreen = false;
	if (sFullscreen == "true" || sFullscreen == "")
	{
		bFullscreen = true;
	}

	SHOOTERSCREEN_RENDERER iRenderer;
	if (sRenderer == "DirectX" || sRenderer == "")
	{
		iRenderer = RENDERER_DIRECTX;
	}
	else
	{
		iRenderer = RENDERER_OPENGL;
	}
	//게임화면 생성
	printf ("Toho Explosion : Barrage Revolution Project Episode 4 (C) 2014 AXTSOFT\n");
	if (GameScreen.MakeScreen(GAMEWIDTH, GAMEHEIGHT, 32, bFullscreen, true, iRenderer) == false)
	{
		printf ("Screen Creation Failed. Exit Game.\n");
		return;
	}

	GameScreen.SetWindowCaption("Toho Explosion : Barrage Revolution Project Episode 4 (Ver. 1.00, 2014-01-01)");

	/* 게임에 쓰일 어두운 서페이스 만들기 */

	auto MakeDarkScreen = [&] (ShooterSprite * IN_Sprite, int IN_Width, int IN_Height, Uint8 IN_R, Uint8 IN_G, Uint8 IN_B)
	{
		SDL_Surface * pSurface;
		SDL_PixelFormat * pFormat = NULL;

		GameScreen.GetFormat(&pFormat);
		pSurface = SDL_CreateRGBSurface(0, IN_Width, IN_Height, 
			32, 0,  2 ^ 8, 2 ^ 16,  2 ^ 24);

		if ( !(IN_R == 0 && IN_G == 0 && IN_B == 0) )
		{
			//not working....
			Uint32 * pPixels = (Uint32*)(pSurface->pixels);
			Uint32 uWhiteColor = SDL_MapRGB(pSurface->format, IN_R, IN_G, IN_B);
			for (int i = 0; i < IN_Height; i++)
			{
				for (int j = 0; j < IN_Width; j++)
				{
					pPixels[i * IN_Width + j] = uWhiteColor;
				}
			}
		}

		IN_Sprite->SetSurface(pSurface, &GameScreen);
		IN_Sprite->SetWidth(IN_Width);
		IN_Sprite->SetHeight(IN_Height);
		IN_Sprite->SetAlpha(100);
	};

	MakeDarkScreen(&DarkScreen, UI_WINDOW_RIGHT_X - (UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH), UI_WINDOW_BOTTOM_Y - (UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT), 0, 0, 0);
	MakeDarkScreen(&DarkScreen_Record, 498, 226, 0, 0, 0);
	MakeDarkScreen(&DarkScreen_Result, 229, 238, 0, 0, 0);
	MakeDarkScreen(&DarkScreen_CompanyLogo, 640, 480, 255, 255, 255);

	/* 어두운 서페이스 끝 */

	ShooterSurface::InitPNG();
	
	//스프라이트 로딩. (컬러키는 알아서 잡아준다.)
	
	printf ("Loading Sprites.... \n");

	/* 로딩화면 출력 */
	Spr_UI_NowLoading.LoadSprite("data.rom", "spr/ui/mainmenu/nowloading.png", &GameScreen);
	GameScreen.FillColor();
	Spr_UI_NowLoading.DrawSprite(UI_NOWLOADING_X, UI_NOWLOADING_Y, 0);
	GameScreen.Flip();
	/* 로딩화면 끝 */

	Spr_UI_CompanyLogo.LoadSprite("data.rom", "spr/ui/companylogo/companylogo.png", &GameScreen, false);
	Spr_UI_MainMenu_Background.LoadSprite("data.rom", "spr/ui/mainmenu/background.png", &GameScreen, false);
	Spr_UI_MainMenu_Gamelogo.LoadSprite("data.rom", "spr/ui/mainmenu/gamelogo.png", &GameScreen, false);
	Spr_UI_MainMenu_Sortie.LoadSprite("data.rom", "spr/ui/mainmenu/menu_sortie.png", &GameScreen, false);
	Spr_UI_MainMenu_Sortie_Selected.LoadSprite("data.rom", "spr/ui/mainmenu/menu_sortie_selected.png", &GameScreen, false);
	Spr_UI_MainMenu_Record.LoadSprite("data.rom", "spr/ui/mainmenu/menu_record.png", &GameScreen, false);
	Spr_UI_MainMenu_Record_Selected.LoadSprite("data.rom", "spr/ui/mainmenu/menu_record_selected.png", &GameScreen, false);
	Spr_UI_MainMenu_Exit.LoadSprite("data.rom", "spr/ui/mainmenu/menu_exit.png", &GameScreen, false);
	Spr_UI_MainMenu_Exit_Selected.LoadSprite("data.rom", "spr/ui/mainmenu/menu_exit_selected.png", &GameScreen, false);
	Spr_UI_MainMenu_Copyright.LoadSprite("data.rom", "spr/ui/mainmenu/copyright.png", &GameScreen, false);
	
	//캐릭터 셀렉트 화면
	Spr_UI_CharaSelect_Title.LoadSprite("data.rom", "spr/ui/charaselect/charaselect_title.png", &GameScreen, false);
	Spr_UI_CharaSelect_Description_Reimu.LoadSprite("data.rom", "spr/ui/charaselect/description_reimu.png", &GameScreen, false);
	Spr_UI_CharaSelect_Description_Marisa.LoadSprite("data.rom", "spr/ui/charaselect/description_marisa.png", &GameScreen, false);
	Spr_UI_CharaSelect_Description_Reisen.LoadSprite("data.rom", "spr/ui/charaselect/description_sakuya.png", &GameScreen, false);

	//Spr_UI_Record_Background.LoadSprite("data.rom", "spr/ui/record/background.png", &GameScreen, false);
	Spr_UI_Record_Title.LoadSprite("data.rom", "spr/ui/record/record_title.png", &GameScreen, false);

	//플레이어
	Spr_Reimu_Front.LoadSprite("data.rom", "spr/player/reimu/player_front.png", &GameScreen, 28, 42, 4);
	Spr_Reimu_Left.LoadSprite("data.rom", "spr/player/reimu/player_left.png", &GameScreen, 28, 42, 7);
	Spr_Reimu_Right.LoadSprite("data.rom", "spr/player/reimu/player_right.png", &GameScreen, 28, 42, 7);

	Spr_Marisa_Front.LoadSprite("data.rom", "spr/player/marisa/player_front.png", &GameScreen, 23, 36, 4);
	Spr_Marisa_Left.LoadSprite("data.rom", "spr/player/marisa/player_left.png", &GameScreen, 27, 36, 8);
	Spr_Marisa_Right.LoadSprite("data.rom", "spr/player/marisa/player_right.png", &GameScreen, 27, 36, 8);

	Spr_Reisen_Front.LoadSprite("data.rom", "spr/player/sakuya/player_front.png", &GameScreen, 22, 44, 4);
	Spr_Reisen_Left.LoadSprite("data.rom", "spr/player/sakuya/player_left.png", &GameScreen, 24, 44, 7);
	Spr_Reisen_Right.LoadSprite("data.rom", "spr/player/sakuya/player_right.png", &GameScreen, 24, 44, 7);

	Spr_PlayerShot_Reimu_0.LoadSprite("data.rom", "spr/player/reimu/shot/shot0.png", &GameScreen, false);
	Spr_PlayerShot_Reimu_0_Sub.LoadSprite("data.rom", "spr/player/reimu/shot/shot0_sub.png", &GameScreen);
	Spr_PlayerShot_Reimu_Rapier_0.LoadSprite("data.rom", "spr/player/reimu/shot/rapier0.png", &GameScreen, false);

	Spr_PlayerShot_Reimu_Bomber.LoadSprite("data.rom", "spr/player/reimu/bomber/bomber.png", &GameScreen);

	Spr_PlayerShot_Marisa_0.LoadSprite("data.rom", "spr/player/marisa/shot/shot0.png", &GameScreen, false);
	Spr_PlayerShot_Marisa_Rapier_0.LoadSprite("data.rom", "spr/player/marisa/shot/rapier0.png", &GameScreen, false);

	Spr_PlayerShot_Marisa_Bomber.LoadSprite("data.rom", "spr/player/marisa/bomber/bomber.png", &GameScreen, 300, 431, 3, true, false, (Uint8)0, (Uint8)0, (Uint8)0);
	
	Spr_PlayerShot_Reisen_0.LoadSprite("data.rom", "spr/player/sakuya/shot/shot0.png", &GameScreen, 16, 26, 1);
// 	Spr_PlayerShot_Reisen_1.LoadSprite("data.rom", "spr/player/reisen/shot/shot1.bmp", &GameScreen, 19, 36, 4);
// 	Spr_PlayerShot_Reisen_2.LoadSprite("data.rom", "spr/player/reisen/shot/shot2.bmp", &GameScreen, 25, 48, 4);

	Spr_PlayerShot_Reisen_Bomber.LoadSprite("data.rom", "spr/player/sakuya/bomber/bomber.png", &GameScreen);

	//플레이어 히트박스
	Spr_PlayerHeatBox.LoadSprite("data.rom", "spr/player/heatbox.png", &GameScreen, 11, 11, 1);
	
	//총알
	Spr_BulletType0.LoadSprite("data.rom", "spr/bullet/type0.png", &GameScreen, 16, 16, 16, false);
	Spr_BulletType1.LoadSprite("data.rom", "spr/bullet/type1.png", &GameScreen, 16, 16, 16, false);
	Spr_BulletType2.LoadSprite("data.rom", "spr/bullet/type2.png", &GameScreen, 8, 15, 16, false);
	Spr_BulletType3.LoadSprite("data.rom", "spr/bullet/type3.png", &GameScreen, 8, 17, 16, false);
	Spr_BulletType4.LoadSprite("data.rom", "spr/bullet/type4.png", &GameScreen, 8, 16, 16, false);
	Spr_BulletType5.LoadSprite("data.rom", "spr/bullet/type5.png", &GameScreen, 12, 15, 16, false);
	Spr_BulletType6.LoadSprite("data.rom", "spr/bullet/type6.png", &GameScreen, 29, 28, 8, false);
	Spr_BulletType7.LoadSprite("data.rom", "spr/bullet/type7.png", &GameScreen, 16, 29, 8, false);
	Spr_BulletType8.LoadSprite("data.rom", "spr/bullet/type8.png", &GameScreen, 30, 25, 8, false);
	Spr_BulletType9.LoadSprite("data.rom", "spr/bullet/type9.png", &GameScreen, 25, 25, 8, false);
	Spr_BulletType10.LoadSprite("data.rom", "spr/bullet/type10.png", &GameScreen, 8, 8, 16, false);
	Spr_BulletType11.LoadSprite("data.rom", "spr/bullet/type11.png", &GameScreen, 12, 12, 10, false);
	Spr_BulletType12.LoadSprite("data.rom", "spr/bullet/type12.png", &GameScreen, 30, 28, 8, false);
	Spr_BulletType13.LoadSprite("data.rom", "spr/bullet/type13.png", &GameScreen, 16, 15, 16, false);
	Spr_BulletType14.LoadSprite("data.rom", "spr/bullet/type14.png", &GameScreen, 8, 16, 16, false);
	Spr_BulletType15.LoadSprite("data.rom", "spr/bullet/type15.png", &GameScreen, 14, 32, 8, false);
	Spr_BulletType16.LoadSprite("data.rom", "spr/bullet/type16.png", &GameScreen, 14, 28, 8, false);
	Spr_BulletType17.LoadSprite("data.rom", "spr/bullet/type17.png", &GameScreen, 12, 14, 16, false);
	Spr_BulletType18.LoadSprite("data.rom", "spr/bullet/type18.png", &GameScreen, 62, 62, 4, false);

	//적군
	Spr_EnemyType0.LoadSprite("data.rom",  "spr/enemy/type0.png", &GameScreen, 30, 29, 4, false);
	Spr_EnemyType1.LoadSprite("data.rom",  "spr/enemy/type1.png", &GameScreen, 30, 29, 4, false);
	Spr_EnemyType2.LoadSprite("data.rom",  "spr/enemy/type2.png", &GameScreen, 30, 29, 4, false);
	Spr_EnemyType3.LoadSprite("data.rom",  "spr/enemy/type3.png", &GameScreen, 30, 29, 4, false);
	Spr_EnemyType4.LoadSprite("data.rom",  "spr/enemy/type4.png", &GameScreen, 30, 26, 4, false);
	Spr_EnemyType5.LoadSprite("data.rom",  "spr/enemy/type5.png", &GameScreen, 30, 26, 4, false);

	//보스
	Spr_Boss_Stage1.LoadSprite("data.rom", "spr/boss/stage1/boss.png", &GameScreen, 48, 64, 5, false);
	Spr_Boss_Stage2.LoadSprite("data.rom", "spr/boss/stage2/boss.png",&GameScreen, 28, 74, 2, false);
	Spr_Boss_Stage2_Invincible.LoadSprite("data.rom", "spr/boss/stage2/boss_invincible.png", &GameScreen, false);
	Spr_Boss_Stage2_Border.LoadSprite("data.rom", "spr/boss/stage2/border.png", &GameScreen, false);
	Spr_Boss_Stage2_Hangonchou.LoadSprite("data.rom", "spr/boss/stage2/hangonchou.png", &GameScreen, false);
	Obj_Boss_Stage2_Border.SetSprite(&Spr_Boss_Stage2_Border);
	Obj_Boss_Stage2_Border.bSelfRotate = true;
	Obj_Boss_Stage2_Border.fCurrentSelfRotateAngle = 0.0;
	Obj_Boss_Stage2_Border.fSelfRotateAddAngle = 0.25;

	//스테이지
	Spr_Stage1.LoadSprite("data.rom", "spr/stage/stage1/field.png", &GameScreen, false);
	Spr_Stage1_Boss.LoadSprite("data.rom", "spr/stage/stage1/boss.png", &GameScreen, false);
	Spr_Stage2.LoadSprite("data.rom", "spr/stage/stage2/field.png", &GameScreen, false);
	Spr_Stage2_Boss.LoadSprite("data.rom", "spr/stage/stage2/boss.png", &GameScreen, false);
// 	Spr_Stage3.LoadSprite("data/spr/stage/stage3/field.bmp", &GameScreen, false);
// 	Spr_Stage4.LoadSprite("data/spr/stage/stage4/field.bmp", &GameScreen, false);
// 	Spr_Stage5.LoadSprite("data/spr/stage/stage5/field.bmp", &GameScreen, false);
// 	Spr_Stage6.LoadSprite("data/spr/stage/stage6/field.bmp", &GameScreen, false);

	//그래픽 폰트
	Spr_TinyFont.LoadSprite("data.rom", "spr/ui/font/tinyfont.png", &GameScreen, 8, 8, 93, false);
	Spr_NumbersFont.LoadSprite("data.rom", "spr/ui/font/numbers.png", &GameScreen, 14, 16, 0, false);
	Spr_NormalFont.LoadSprite("data.rom", "spr/ui/font/normalfont.png", &GameScreen, 14, 14, 0, false);
	Spr_NormalFont_Gray.LoadSprite("data.rom", "spr/ui/font/normalfont_gray.png", &GameScreen, 14, 14, 0, false);
	Spr_NormalFont_Selected.LoadSprite("data.rom", "spr/ui/font/normalfont_selected.png", &GameScreen, 14, 14, 0, false);
	Spr_NormalFont_Others.LoadSprite("data.rom", "spr/ui/font/normalfont_others.png", &GameScreen, 14, 14, 0, false);
	Spr_NormalFont_Others_Gray.LoadSprite("data.rom", "spr/ui/font/normalfont_others.png", &GameScreen, 14, 14, 0, false);
	Spr_NormalFont_Others_Selected.LoadSprite("data.rom", "spr/ui/font/normalfont_others_selected.png", &GameScreen, 14, 14, 0, false);

	Spr_PlayerLife.LoadSprite("data.rom", "spr/ui/in_game/playerlife.png", &GameScreen);
	Spr_PlayerBomber.LoadSprite("data.rom", "spr/ui/in_game/playerbomber.png", &GameScreen);
	Spr_SpellIndex.LoadSprite("data.rom", "spr/ui/in_game/spellindex.png", &GameScreen);

	//이벤트 창
	Spr_ScriptBox.LoadSprite("data.rom", "spr/ui/in_game/event/scriptbox.png", &GameScreen);
	
	//이벤트 창에서의 캐릭터
	Spr_Portrait_Reimu0.LoadSprite("data.rom", "spr/chara/reimu/reimu0.png", &GameScreen, false);
	Spr_Portrait_Marisa0.LoadSprite("data.rom", "spr/chara/marisa/marisa0.png", &GameScreen, false);
	Spr_Portrait_Reisen0.LoadSprite("data.rom", "spr/chara/sakuya/sakuya0.png", &GameScreen, false);
	Spr_Portrait_Youmu0.LoadSprite("data.rom", "spr/chara/youmu/youmu0.png", &GameScreen, false);
	Spr_Portrait_Yuuko0.LoadSprite("data.rom", "spr/chara/yuuko/yuuko0.png", &GameScreen, false);

	//풀사이즈 캐릭터 ("data.rom", 캐릭터 선택화면에서)
	Spr_FullPortrait_Reimu.LoadSprite("data.rom", "spr/chara/reimu/fullsize.png", &GameScreen, false);
	Spr_FullPortrait_Marisa.LoadSprite("data.rom", "spr/chara/marisa/fullsize.png", &GameScreen, false);
	Spr_FullPortrait_Reisen.LoadSprite("data.rom", "spr/chara/sakuya/fullsize.png", &GameScreen, false);

	//컷인
	Spr_CutIn_Reimu.LoadSprite("data.rom", "spr/chara/reimu/cut_in.png", &GameScreen, false);
	Spr_CutIn_Marisa.LoadSprite("data.rom", "spr/chara/marisa/cut_in.png", &GameScreen, false);
	Spr_CutIn_Reisen.LoadSprite("data.rom", "spr/chara/sakuya/cut_in.png", &GameScreen, false);
	Spr_CutIn_Youmu.LoadSprite("data.rom", "spr/chara/youmu/cut_in.png", &GameScreen);
	Spr_CutIn_Yuuko.LoadSprite("data.rom", "spr/chara/yuuko/cut_in.png", &GameScreen, false);

	//엔딩 크레딧 배경
	Spr_Credits_Background.LoadSprite("data.rom", "spr/credits/background.png", &GameScreen, false);

	//UI
	Spr_UI_Window_Left.LoadSprite("data.rom", "spr/ui/in_game/window_left.png", &GameScreen, UI_WINDOW_LEFT_WIDTH, UI_WINDOW_LEFT_HEIGHT, 1, false);
	Spr_UI_Window_Right.LoadSprite("data.rom", "spr/ui/in_game/window_right.png", &GameScreen, UI_WINDOW_RIGHT_WIDTH, UI_WINDOW_RIGHT_HEIGHT, 1, false);
	Spr_UI_Window_Top.LoadSprite("data.rom", "spr/ui/in_game/window_top.png", &GameScreen, UI_WINDOW_TOP_WIDTH, UI_WINDOW_TOP_HEIGHT, 1, false);
	Spr_UI_Window_Bottom.LoadSprite("data.rom", "spr/ui/in_game/window_bottom.png", &GameScreen, UI_WINDOW_BOTTOM_WIDTH, UI_WINDOW_BOTTOM_HEIGHT,1, false);

	//new PauseMenu
	Spr_UI_GameOverMenu_New_Continue.LoadSprite("data.rom", "spr/ui/in_game/gameovermenu_new_continue.png", &GameScreen, false);
	Spr_UI_GameOverMenu_New_Continue_Selected.LoadSprite("data.rom", "spr/ui/in_game/gameovermenu_new_continue_selected.png", &GameScreen, false);

	Spr_UI_PauseMenu_New_Yes.LoadSprite("data.rom", "spr/ui/in_game/new_yes.png", &GameScreen, false);
	Spr_UI_PauseMenu_New_Yes_Selected.LoadSprite("data.rom", "spr/ui/in_game/new_yes_selected.png", &GameScreen, false);

	Spr_UI_PauseMenu_New_No.LoadSprite("data.rom", "spr/ui/in_game/new_no.png", &GameScreen, false);
	Spr_UI_PauseMenu_New_No_Selected.LoadSprite("data.rom", "spr/ui/in_game/new_no_selected.png", &GameScreen, false);

	Spr_UI_PauseMenu_New_Question.LoadSprite("data.rom", "spr/ui/in_game/new_question.png", &GameScreen, false);

	Spr_UI_PauseMenu_New_Return.LoadSprite("data.rom", "spr/ui/in_game/pausemenu_new_return.png", &GameScreen, false);
	Spr_UI_PauseMenu_New_Return_Selected.LoadSprite("data.rom", "spr/ui/in_game/pausemenu_new_return_selected.png", &GameScreen, false);

	Spr_UI_PauseMenu_New_Exit.LoadSprite("data.rom", "spr/ui/in_game/pausemenu_new_exit.png", &GameScreen, false);
	Spr_UI_PauseMenu_New_Exit_Selected.LoadSprite("data.rom", "spr/ui/in_game/pausemenu_new_exit_selected.png", &GameScreen, false);

	Spr_UI_PauseMenu_New_Retry.LoadSprite("data.rom", "spr/ui/in_game/pausemenu_new_retry.png", &GameScreen, false);
	Spr_UI_PauseMenu_New_Retry_Selected.LoadSprite("data.rom", "spr/ui/in_game/pausemenu_new_retry_selected.png", &GameScreen, false);

	Spr_UI_PauseMenu_New_Title.LoadSprite("data.rom", "spr/ui/in_game/pausemenu_new_title.png", &GameScreen, false);
	
	Spr_UI_GameOverMenu_New_Title.LoadSprite("data.rom", "spr/ui/in_game/gameover_title.png", &GameScreen, false);
	//new PauseMenu end

	Spr_UI_Result_Reimu.LoadSprite("data.rom", "spr/ui/result/reimu/result.png", &GameScreen, false);
	Spr_UI_Result_Marisa.LoadSprite("data.rom", "spr/ui/result/marisa/result.png", &GameScreen, false);
	Spr_UI_Result_Reisen.LoadSprite("data.rom", "spr/ui/result/sakuya/result.png", &GameScreen, false);

	Spr_UI_EnemySpell.LoadSprite("data.rom", "spr/ui/in_game/enemyspell.png", &GameScreen, false);

	Spr_UI_Extend.LoadSprite("data.rom", "spr/ui/in_game/extend.png", &GameScreen, false);
	
	Player.bRotate = false;
	
	auto PlayerShotSetting = [] (GamePlayerShot * IN_PlayerShot, PLAYERSHOT_TYPE IN_Type, int IN_damage, CollisionModel IN_CollisionModel, double IN_CollisionRadius, double IN_speed, bool IN_IsBomber)
	{
		IN_PlayerShot->iPlayerShotType = IN_Type;
		IN_PlayerShot->iDamage = IN_damage;
		IN_PlayerShot->AddCollision(0.0, 0.0, IN_CollisionModel, IN_CollisionRadius);
		IN_PlayerShot->speed = IN_speed;
		IN_PlayerShot->bIsBomber = IN_IsBomber;
	};

	PlayerShot_Reimu_0.SetSprite(&Spr_PlayerShot_Reimu_0);
	PlayerShotSetting(&PlayerShot_Reimu_0, PLAYERSHOT_TYPE_REIMU_0, 3, COLLISIONMODEL_CIRCLE, 7.0, 10.0, false);
	PlayerShot_Reimu_Sub_0.SetSprite(&Spr_PlayerShot_Reimu_0_Sub);
	PlayerShotSetting(&PlayerShot_Reimu_Sub_0, PLAYERSHOT_TYPE_REIMU_SUB_0, 1, COLLISIONMODEL_CIRCLE, 7.0, 10.0, false);
	PlayerShot_Reimu_Sub_0.bRotate = false;
	PlayerShot_Reimu_Sub_0.pPlayerShotInit = (PlayerShotInit)(&PlayerShot_Reimu_Sub_Init);
	PlayerShot_Reimu_Sub_0.pPlayerShotFunc = (PlayerShotFunc)(&PlayerShot_Reimu_Sub);

	PlayerShot_Reimu_Rapier_0.SetSprite(&Spr_PlayerShot_Reimu_Rapier_0, DEFAULT_FRAMECHANGE_INTERVAL);
	PlayerShot_Reimu_Rapier_0.bRotate = true;
	PlayerShot_Reimu_Rapier_0.bSelfRotate = true;
	PlayerShot_Reimu_Rapier_0.bFollowToPlayerMoving = false;
	PlayerShot_Reimu_Rapier_0.fCurrentSelfRotateAngle = 90.0;
	PlayerShot_Reimu_Rapier_0.fSelfRotateAddAngle = 1.0;
	PlayerShotSetting(&PlayerShot_Reimu_Rapier_0, PLAYERSHOT_TYPE_REIMU_RAPIER_0, 12, COLLISIONMODEL_CIRCLE, 30.0, 10.0, false);
	PlayerShot_Reimu_Rapier_0.pPlayerShotInit = (PlayerShotInit)(&PlayerShot_Reimu_Rapier_Init);
	PlayerShot_Reimu_Rapier_0.pPlayerShotFunc = (PlayerShotFunc)(&PlayerShot_Reimu_Rapier_Func);

	PlayerShot_Reimu_Bomber.SetSprite(&Spr_PlayerShot_Reimu_Bomber);
	PlayerShotSetting(&PlayerShot_Reimu_Bomber, PLAYERSHOT_TYPE_REIMU_BOMBER, 9999, COLLISIONMODEL_CIRCLE, 30.0, 1.0, true);
	PlayerShot_Reimu_Bomber.bRotate = false;
	PlayerShot_Reimu_Bomber.bPassBullet = true;
	PlayerShot_Reimu_Bomber.iDamageToBoss = 5;
	PlayerShot_Reimu_Bomber.pPlayerShotInit = (PlayerShotInit)(&PlayerShot_Reimu_Bomber_Init);
	PlayerShot_Reimu_Bomber.pPlayerShotFunc = (PlayerShotFunc)(&PlayerShot_Reimu_Bomber_Func);

	PlayerShot_Marisa_0.SetSprite(&Spr_PlayerShot_Marisa_0);
	PlayerShotSetting(&PlayerShot_Marisa_0, PLAYERSHOT_TYPE_MARISA_0, 2, COLLISIONMODEL_CIRCLE, 7.0, 10.0, false);
	PlayerShot_Marisa_0.bRotate = false;
	PlayerShot_Marisa_0.bSelfRotate = false;
	PlayerShot_Marisa_0.fCurrentSelfRotateAngle = 90.0;
	PlayerShot_Marisa_0.fSelfRotateAddAngle = 1.0;

	PlayerShot_Marisa_Rapier_0.SetSprite(&Spr_PlayerShot_Marisa_Rapier_0);
	PlayerShotSetting(&PlayerShot_Marisa_Rapier_0, PLAYERSHOT_TYPE_MARISA_RAPIER_0, 10, COLLISIONMODEL_CIRCLE, 15.0, 10.0, false);

	PlayerShot_Marisa_Bomber.SetSprite(&Spr_PlayerShot_Marisa_Bomber, 5);
	PlayerShotSetting(&PlayerShot_Marisa_Bomber, PLAYERSHOT_TYPE_MARISA_BOMBER, 9999, COLLISIONMODEL_WHOLE, 0.0, 0.0, true);
	PlayerShot_Marisa_Bomber.speed = 0.0;
	PlayerShot_Marisa_Bomber.bRotate = false;
	PlayerShot_Marisa_Bomber.bAutoNextFrame = true;
	PlayerShot_Marisa_Bomber.iDamageToBoss = 1;
	PlayerShot_Marisa_Bomber.pPlayerShotInit = (PlayerShotInit)(&PlayerShot_Marisa_Bomber_Init);
	PlayerShot_Marisa_Bomber.pPlayerShotFunc = (PlayerShotFunc)(&PlayerShot_Marisa_Bomber_Func);

	PlayerShot_Reisen_0.SetSprite(&Spr_PlayerShot_Reisen_0, DEFAULT_FRAMECHANGE_INTERVAL);
	PlayerShotSetting(&PlayerShot_Reisen_0, PLAYERSHOT_TYPE_REISEN_0, 2.5, COLLISIONMODEL_CIRCLE, 8, 10.0, false);
// 	PlayerShot_Reisen_1.SetSprite(&Spr_PlayerShot_Reisen_1, DEFAULT_FRAMECHANGE_INTERVAL);
// 	PlayerShotSetting(&PlayerShot_Reisen_1, PLAYERSHOT_TYPE_REISEN_1, 1, COLLISIONMODEL_CIRCLE, 8, 10.0, false);
// 	PlayerShot_Reisen_2.SetSprite(&Spr_PlayerShot_Reisen_2, DEFAULT_FRAMECHANGE_INTERVAL);
// 	PlayerShotSetting(&PlayerShot_Reisen_2, PLAYERSHOT_TYPE_REISEN_2, 1, COLLISIONMODEL_CIRCLE, 11, 10.0, false);

	PlayerShot_Reisen_Bomber.SetSprite(&Spr_PlayerShot_Reisen_Bomber, DEFAULT_FRAMECHANGE_INTERVAL);
	PlayerShot_Reisen_Bomber.iDamageToBoss = 3;
	PlayerShot_Reisen_Bomber.bPassBullet = true;
	PlayerShotSetting(&PlayerShot_Reisen_Bomber, PLAYERSHOT_TYPE_REISEN_BOMBER, 9999, COLLISIONMODEL_CIRCLE, 7.0, 10.0, true);
	
	PlayerHeatBox.SetSprite(&Spr_PlayerHeatBox, DEFAULT_FRAMECHANGE_INTERVAL);
	Player.SetPlayerHeatBox(&PlayerHeatBox);

	Spr_Explosion_Big.LoadSprite("data.rom", "spr/explosion/explosion_big.png", &GameScreen, 64, 64, 11);
	Spr_Explosion_Small.LoadSprite("data.rom", "spr/explosion/explosion_small.png", &GameScreen, 20, 20, 6);

	Spr_BomberItem.LoadSprite("data.rom", "spr/item/bomberitem.png", &GameScreen, false);
	Spr_ExtendItem.LoadSprite("data.rom", "spr/item/extenditem.png", &GameScreen, false);
	Spr_PowerupItem_Big.LoadSprite("data.rom", "spr/item/powerup_big.png", &GameScreen, false);
	Spr_PowerupItem_Small.LoadSprite("data.rom", "spr/item/powerup_small.png", &GameScreen, false);
	Spr_ScoreItem_Big.LoadSprite("data.rom", "spr/item/scoreitem_big.png", &GameScreen, false);
	Spr_ScoreItem_Small.LoadSprite("data.rom", "spr/item/scoreitem_small.png", &GameScreen, false);

	Sur_BossHP.LoadSurface("data.rom", "spr/ui/in_game/bosshp.png", &GameScreen, false);

	Spr_BossCursor.LoadSprite("data.rom", "spr/ui/in_game/bosscursor.png", &GameScreen, false);

	//폰트
	ShooterFont::InitFont();
	printf ("Loading Font... \n");
	GameSmallSizeFont.LoadFont("data.rom", "font/UnDotum.ttf", &GameScreen, 10);
	GameNormalSizeFont.LoadFont("data.rom", "font/UnDotum.ttf", &GameScreen, 15);
	GameNormalSizeFont.SetFontStyle(FONT_BOLD);

	if (bBGM_Use | bSE_Use == true)
	{
		printf ("Initalizing Sound System...\n");
		MySoundManager.OpenAudio(32);
	}

	printf ("Loading Sounds...\n");
	if (bSE_Use == true)
	{
 		Sound_BossDead.LoadSound("data.rom", "sound/bossdead.wav", &MySoundManager);
 		Sound_Bullet.LoadSound("data.rom", "sound/bullet.wav", &MySoundManager);
 		Sound_EnemyDead.LoadSound("data.rom", "sound/enemydead.wav", &MySoundManager);
 		Sound_EnemyDamaged.LoadSound("data.rom", "sound/enemydamaged.wav", &MySoundManager);
 		Sound_Item.LoadSound("data.rom", "sound/item.wav", &MySoundManager);
 		Sound_PlayerDead.LoadSound("data.rom", "sound/playerdead.wav", &MySoundManager);
 		Sound_PowerUp.LoadSound("data.rom", "sound/powerup.wav", &MySoundManager);

		Sound_BossFatal.LoadSound("data.rom", "sound/bossfatal.wav", &MySoundManager);
		Sound_Cancel.LoadSound("data.rom", "sound/cancel.wav", &MySoundManager);
		Sound_Extend.LoadSound("data.rom", "sound/extend.wav", &MySoundManager);
		Sound_Graze.LoadSound("data.rom", "sound/graze.wav", &MySoundManager);
		Sound_Kira.LoadSound("data.rom", "sound/kira.wav", &MySoundManager);
		Sound_Laser.LoadSound("data.rom", "sound/laser.wav", &MySoundManager);
		Sound_Okay.LoadSound("data.rom", "sound/okay.wav", &MySoundManager);
		Sound_Pause.LoadSound("data.rom", "sound/pause.wav", &MySoundManager);
		Sound_Select.LoadSound("data.rom", "sound/select.wav", &MySoundManager);
		Sound_PlayerShot.LoadSound("data.rom", "sound/playershot.wav", &MySoundManager);
		Sound_StageClear.LoadSound("data.rom", "sound/stageclear.wav", &MySoundManager);
		Sound_SpellCard.LoadSound("data.rom", "sound/spellcard.wav", &MySoundManager);

		Sound_Timeout.LoadSound("data.rom", "sound/timeout.wav", &MySoundManager);

		Sound_MasterSpark.LoadSound("data.rom", "sound/masterspark.wav", &MySoundManager);
	}

	GameEnemyVector.reserve(512);
	GameBulletVector.reserve(512);
	GameExplosionVector.reserve(512);
	GamePlayerShotVector.reserve(512);
	GameItemVector.reserve(512);

	Stage.iGameLeft = UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + 1;
	Stage.iGameRight = UI_WINDOW_RIGHT_X - 1;
	Stage.iGameTop = UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT + 1;
	Stage.iGameBottom = UI_WINDOW_BOTTOM_Y - 1;

	//디버그용
// 	if (DeltaTimeWriter.OpenFile("deltatime.csv", IOTYPE_WRITE) == false)
// 	{
// 		printf ("failed.\n");
// 	}
// 	DeltaTimeWriter.WriteLine(3, (std::string)"Frame", (std::string)"FPS", (std::string)"DeltaTime");

}

void GameMain()
{
	static int iFrameCount = 0;

	static Uint32 iFrameOldTime;
	static Uint32 iAccumulatedTime = 0;

	bRunning = true;
	
//#define TESTMODE 1

	//배포용
// #ifndef TESTMODE
// 	iGameState = INTRO;
// #endif
	//배포용 끝

	//테스트용
#ifdef TESTMODE

	InitGameCredits();
	Player.iScore = 99999;

// 	#define TESTSTAGE 2
// 	#define TESTSPELL 0
// 
// 		iGameState = GAMESTATE_GAME;
// 		InitGame(PLAYERCHARA_REISEN);
// 		Player.life = 99;
// 		DeleteAllObjects();
// 		iCurrentStage = TESTSTAGE;
// 		StartCurrentStage();
// 
// 
// 	#ifdef TESTSPELL
// 		DeleteAllObjects();
// 
// 		if (iCurrentStage == 1)
// 		{
// 			InitStage1Boss();
// 			InitStage1Event();
// 		}
// 		else if (iCurrentStage == 2)
// 		{
// 			//테스트
// //			Music_Stage2Boss.Play(true, NULL, fVolume_BGM);
// 			InitStage2Boss();
// 			InitStage2Event();
// 		}
// 
// 		iGameState_Game_Status = GAMESTATE_GAME_EVENT;
// 		pBoss->iCurrentSpell = TESTSPELL;
// 
// 		StartSpell();
// 	#endif
#endif
	//테스트용 끝
	
	//여기서는 루프돌리는것만 담당한다.
	static int itest = 0;

	Uint32 LastTime = NULL;

	static _ULONGLONG TempCount = 0;

	ShooterInput::InitInput();
	while ( bRunning )
	{	
		Uint32 iDelta = SDL_GetTicks() - LastTime;
		//DeltaTimeWriter.WriteLine(3, (std::to_string)(TempCount), (std::to_string)((long double)(fFrameRate)), (std::to_string)((_ULONGLONG)(iDelta)));
		TempCount++;

		fTimeFactor = 1.0;

		iFrameOldTime = SDL_GetTicks();
		//프레임 처리
		GamePlay();

		//프레임 계산
		iFrameCount++;

		//테스트용.
		iFrameTime = 0;

		double fTempFrameRate = 999.0;
		Uint32 iTick;
		GameInput.TakeInput();

		MySoundManager.Update();

		LastTime = SDL_GetTicks();		//new

		iTick = SDL_GetTicks() ;
		iFrameTime = iTick - iFrameOldTime;
		iAccumulatedTime = iAccumulatedTime + iFrameTime;
		fFrameRate = (double)(iFrameCount)  / ((double)(iAccumulatedTime) / 1000.0);

		if (iAccumulatedTime >= 500)
		{
			iAccumulatedTime = 0;
			iFrameCount = 0;
		}

	}
}

void Unload()
{
	printf ("Unloading Resources.... Please Wait and Don't Close this Console!!\n");
	ShooterSurface::ExitPNG();
	ClearRecord();
	DeleteAllChara();
	DeleteAllScripts();
	UnloadGameCreditsSprite();
	SDL_Quit();
}