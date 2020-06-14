#include "ShooterInput.h"

ShooterInput :: ShooterInput()
{
	for (int i = 0 ; i < MAXKEYCOUNT; i++)
	{
		PreviousKeyInput[i] = false;
	}
	FlushInput();
	bGotFocus = false;
}

void ShooterInput :: InitInput()
{
	SDL_StartTextInput();
}

void ShooterInput :: FlushInput()
{
	for (int i = 0; i < MAXKEYCOUNT; i++)
	{
		PreviousKeyInput[i] = KeyInput[i];
	}

	for (int i = 0 ; i < MAXKEYCOUNT; i++)
	{
		KeyInput[i] = false;
	}
}

void ShooterInput :: TakeInput()
{
	
	Uint32 LastTime = SDL_GetTicks();
	while (SDL_PollEvent( &Event ))
	{
		switch (Event.type)
		{
		//시스템 이벤트
		case SDL_QUIT:
			KeyInput[QUIT] = true;
			break;
		case SDL_WINDOWEVENT:
			switch (Event.window.event) 
			{
			case SDL_WINDOWEVENT_CLOSE:
				{
					SDL_Window *window = SDL_GetWindowFromID(Event.window.windowID);
					if (window)
					{
						SDL_DestroyWindow(window);
					}
					KeyInput[WINDOW_CLOSE] = true;
				}
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				KeyInput[WINDOW_FOCUS_GAINED] = true;
				bGotFocus = true;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				KeyInput[WINDOW_FOCUS_LOST] = true;
				bGotFocus = false;
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				bool debug;
				debug = false;
				break;
			}
		}
	}

	//그냥 윈도우 API의 입력함수로 쓴다.
	//왠만해선 SDL에서 자체제공하는 인터페이스를 사용하려고했는데
	//SDL 2.0에서 이상하게 바뀌어서 예전처럼 입력처리가 안됨.. API를 써보니 성능차이도 없는것같고

	//0x8000 마스크를 쓰지 않는다. 그 이유는, 프레임 딜레이 도중에 받았던 입력을 처리하기 위함이다.
	//이를 위해서, 모드 전환시마다 키 입력을 Reset 해줘야 한다.
	//(예컨대 Pause 메뉴 화면중에 공격키를 입력한 상태로 Pause를 끄면 공격이 한번 나가기 때문이다.)

	if ( bGotFocus == true )
	{
		auto Check = [&] (int IN_KeyNum, KEY Result_Key)
		{
			if (GetAsyncKeyState(IN_KeyNum))
			{
				KeyInput[Result_Key] = true;
			}
		};

		Check(VK_ESCAPE, KEY_ESCAPE);
		Check(VK_F1, KEY_F1);
		Check(VK_F2, KEY_F2);
		Check(VK_F3, KEY_F3);
		Check(VK_F4, KEY_F4);
		Check(VK_F5, KEY_F5);
		Check(VK_F6, KEY_F6);
		Check(VK_F7, KEY_F7);
		Check(VK_F8, KEY_F8);
		Check(VK_F9, KEY_F9);
		Check(VK_F10, KEY_F10);
		Check(VK_F11, KEY_F11);
		Check(VK_F12, KEY_F12);
		Check(VK_OEM_3, KEY_TILDE);
		Check(VK_OEM_MINUS, KEY_MINUS);
		Check(VK_OEM_PLUS, KEY_PLUS);
		Check(VK_BACK, KEY_BACKSPACE);
		Check(VK_TAB, KEY_TAB);
		Check(VK_OEM_4, KEY_LEFTBRACKET);
		Check(VK_OEM_6, KEY_RIGHTBRACKET);
		Check(VK_OEM_5, KEY_WON);
		Check(VK_CAPITAL, KEY_CAPSLOCK);
		Check(VK_OEM_1, KEY_SEMICOLON);
		Check(VK_OEM_7, KEY_QUOTE);
		Check(VK_RETURN, KEY_RETURN);
		Check(VK_LSHIFT, KEY_LSHIFT);
		Check(VK_OEM_COMMA, KEY_COMMA);
		Check(VK_OEM_PERIOD, KEY_PERIOD);
		Check(VK_OEM_2, KEY_SLASH);
		Check(VK_RSHIFT, KEY_RSHIFT);
		Check(VK_LCONTROL, KEY_LCONTROL);
		Check(VK_LMENU, KEY_LALT);
		Check(VK_HANJA, KEY_HANJA);
		Check(VK_SPACE, KEY_SPACE);
		Check(VK_HANGUL, KEY_HANGUL);
		Check(VK_RMENU, KEY_RALT);
		Check(VK_RCONTROL, KEY_RCONTROL);
		Check(VK_HOME, KEY_HOME);
		Check(VK_END, KEY_END);
		Check(VK_INSERT, KEY_INSERT);
		Check(VK_PRIOR, KEY_PAGEUP);
		Check(VK_DELETE, KEY_DELETE);
		Check(VK_NEXT, KEY_PAGEDOWN);
		Check(VK_UP, KEY_UP);
		Check(VK_LEFT, KEY_LEFT);
		Check(VK_DOWN, KEY_DOWN);
		Check(VK_RIGHT, KEY_RIGHT);
		Check(VK_SNAPSHOT, KEY_PSCREEN);
		Check(VK_SCROLL, KEY_SCROLLLOCK);
		Check(VK_PAUSE, KEY_PAUSE);
		Check(VK_NUMLOCK, KEY_NUMLOCK);
		Check(VK_DIVIDE, KEY_NUMPADDIVIDE);
		Check(VK_MULTIPLY, KEY_NUMPADMULTIPLY);
		Check(VK_SUBTRACT, KEY_NUMPADSUBTRACT);
		Check(VK_ADD, KEY_NUMPADADD);
		Check(VK_DECIMAL, KEY_NUMPADDECIMAL);
		Check(VK_NUMPAD0, KEY_NUMPAD0);
		Check(VK_NUMPAD1, KEY_NUMPAD1);
		Check(VK_NUMPAD2, KEY_NUMPAD2);
		Check(VK_NUMPAD3, KEY_NUMPAD3);
		Check(VK_NUMPAD4, KEY_NUMPAD4);
		Check(VK_NUMPAD5, KEY_NUMPAD5);
		Check(VK_NUMPAD6, KEY_NUMPAD6);
		Check(VK_NUMPAD7, KEY_NUMPAD7);
		Check(VK_NUMPAD8, KEY_NUMPAD8);
		Check(VK_NUMPAD9, KEY_NUMPAD9);
		Check(VK_LWIN, KEY_LWIN);
		Check(VK_RWIN, KEY_RWIN);
		Check(VK_APPS, KEY_RCLICKMENU);

		//숫자 키 입력
		for (int i = 0x30; i <= 0x39; i++)
		{
			Check(i, (KEY)(i - 0x30 + KEY_0));
		}

		//알파벳 키 입력
		for (int i = 0x41; i <= 0x5A; i++)
		{
			Check(i, (KEY)(i - 0x41 + KEY_A));
		}
	}

}

bool ShooterInput :: GetPreviousInput (KEY IN_Key)
{
	return PreviousKeyInput[IN_Key];
}

bool ShooterInput :: GetInput(KEY IN_Key)
{
	return KeyInput[IN_Key];
}

const SDL_Event * ShooterInput :: GetEvent()
{
	return &Event;
}