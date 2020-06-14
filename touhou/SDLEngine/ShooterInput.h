#pragma once
#include "../MemoryLeakChecker.h"
#include "../SDL/include/SDL.h"
#include <string>
#include <windows.h>

#define MAXKEYCOUNT 256

typedef enum KEY
{
	//�̺�Ʈ
	KEY_NONE = -1,
	QUIT = 0,
	WINDOW_CLOSE,
	WINDOW_FOCUS_GAINED,
	WINDOW_FOCUS_LOST,

	//Ű
	KEY_ESCAPE,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,
	KEY_TILDE,
	KEY_MINUS,
	KEY_PLUS,
	KEY_BACKSPACE,
	KEY_TAB,
	KEY_LEFTBRACKET,
	KEY_RIGHTBRACKET,
	KEY_WON,
	KEY_CAPSLOCK,
	KEY_SEMICOLON,
	KEY_QUOTE,
	KEY_RETURN,
	KEY_LSHIFT,
	KEY_COMMA,
	KEY_PERIOD,
	KEY_SLASH,
	KEY_RSHIFT,
	KEY_LCONTROL,
	KEY_LALT,
	KEY_HANJA,
	KEY_SPACE,
	KEY_HANGUL,
	KEY_RALT,
	KEY_RCONTROL,
	KEY_HOME,
	KEY_END,
	KEY_INSERT,
	KEY_PAGEUP,
	KEY_DELETE,
	KEY_PAGEDOWN,
	KEY_UP,
	KEY_LEFT,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_PSCREEN,
	KEY_SCROLLLOCK,
	KEY_PAUSE,
	KEY_NUMLOCK,
	KEY_NUMPADDIVIDE,
	KEY_NUMPADMULTIPLY,
	KEY_NUMPADSUBTRACT,
	KEY_NUMPADADD,
	KEY_NUMPADDECIMAL,
	KEY_NUMPAD0,
	KEY_NUMPAD1,
	KEY_NUMPAD2,
	KEY_NUMPAD3,
	KEY_NUMPAD4,
	KEY_NUMPAD5,
	KEY_NUMPAD6,
	KEY_NUMPAD7,
	KEY_NUMPAD8,
	KEY_NUMPAD9,
	KEY_LWIN,
	KEY_RWIN,
	KEY_RCLICKMENU,
	KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
	KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M,
	KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z
} KEY;

class ShooterInput
{
private:
	bool PreviousKeyInput[MAXKEYCOUNT];
	bool KeyInput[MAXKEYCOUNT];
	bool bGotFocus;
	SDL_Event Event;
public:
	ShooterInput();
	static void InitInput();
	void FlushInput();
	void TakeInput();
	bool GetPreviousInput (KEY IN_Key);
	bool GetInput(KEY IN_Key);
	const SDL_Event * GetEvent();
};
