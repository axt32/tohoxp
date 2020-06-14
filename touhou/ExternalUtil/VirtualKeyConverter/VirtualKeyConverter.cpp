#include "VirtualKeyConverter.h"

std::string VKeyToKeyName(int IN_VKey)
{
	switch ( IN_VKey )
	{
	case VK_ESCAPE:
		return "ESC";
	case VK_F1:
		return "F1";
	case VK_F2:
		return "F2";
	case VK_F3:
		return "F3";
	case VK_F4:
		return "F4";
	case VK_F5:
		return "F5";
	case VK_F6:
		return "F6";
	case VK_F7:
		return "F7";
	case VK_F8:
		return "F8";
	case VK_F9:
		return "F9";
	case VK_F10:
		return "F10";
	case VK_F11:
		return "F11";
	case VK_F12:
		return "F12";
	case VK_OEM_3:	// ~
		return "~";
	case VK_OEM_MINUS:
		return "-";
	case VK_OEM_PLUS:
		return "+";
	case VK_BACK:
		return "BACKSPACE";
	case VK_TAB:
		return "TAB";
	case VK_OEM_4:		// [{
		return "[";
	case VK_OEM_6:		// ]}
		return "]";
	case VK_OEM_5:		// \|
		return "\\";
	case VK_CAPITAL:	//캡스락
		return "CAPSLOCK";
	case VK_OEM_1:		// ;:
		return ";";
	case VK_OEM_7:		// '"
		return "'";
	case VK_RETURN:
		return "RETURN";
	case VK_LSHIFT:
		return "LSHIFT";
	case VK_OEM_COMMA:		//,<
		return ",";
	case VK_OEM_PERIOD:		//.>
		return ".";
	case VK_OEM_2:		// /?
		return "/";
	case VK_RSHIFT:
		return "RSHIFT";
	case VK_LCONTROL:
		return "LCONTROL";
	case VK_LMENU:
		return "LALT";
	case VK_HANJA:
		return "HANJA";
	case VK_SPACE:
		return "SPACE";
	case VK_HANGUL:
		return "HANGUL";
	case VK_RMENU:
		return "RALT";
	case VK_RCONTROL:
		return "RCONTROL";
	case VK_HOME:
		return "HOME";
	case VK_END:
		return "END";
	case VK_INSERT:
		return "INSERT";
	case VK_PRIOR:
		return "PAGEUP";
	case VK_DELETE:
		return "DELETE";
	case VK_NEXT:
		return "PAGEDOWN";
	case VK_UP:
		return "UP";
	case VK_LEFT:
		return "LEFT";
	case VK_DOWN:
		return "DOWN";
	case VK_RIGHT:
		return "RIGHT";
	case VK_SNAPSHOT:
		return "PSCREEN";
	case VK_SCROLL:
		return "SCROLLLOCK";
	case VK_PAUSE:
		return "PAUSE";
	case VK_NUMLOCK:
		return "NUMLOCK";
	case VK_DIVIDE:
		return "NUMPAD/";
	case VK_MULTIPLY:
		return "NUMPAD*";
	case VK_SUBTRACT:
		return "NUMPAD-";
	case VK_ADD:
		return "NUMPAD+";
	case VK_DECIMAL:
		return "NUMPAD.";
	case VK_NUMPAD0:
		return "NUMPAD0";
	case VK_NUMPAD1:
		return "NUMPAD1";
	case VK_NUMPAD2:
		return "NUMPAD2";
	case VK_NUMPAD3:
		return "NUMPAD3";
	case VK_NUMPAD4:
		return "NUMPAD4";
	case VK_NUMPAD5:
		return "NUMPAD5";
	case VK_NUMPAD6:
		return "NUMPAD6";
	case VK_NUMPAD7:
		return "NUMPAD7";
	case VK_NUMPAD8:
		return "NUMPAD8";
	case VK_NUMPAD9:
		return "NUMPAD9";
	case VK_LWIN:
		return "LWIN";
	case VK_RWIN:
		return "RWIN";
	case VK_APPS:		//마우스 오른쪽 메뉴 키 
		return "RCLICKMENU";
	default:

		//숫자
		for (int i = 0x30; i <= 0x39; i++)
		{
			if (IN_VKey == i)
			{
				char temp[5];
				sprintf_s(temp, "%c", ('0' + i - 0x30));
				return (std::string)(temp);	
			}
		}

		//알파벳
		for (int i = 0x41; i <= 0x5A; i++)
		{
			if (IN_VKey == i)
			{
				char temp[5];
				sprintf_s(temp, "%c", ('A' + i - 0x41));
				return (std::string)(temp);
			}
		}
	}

	return "failed";

}

int KeyNameToVKey(std::string IN_KeyName)
{
	if ( IN_KeyName == "ESC")
		return VK_ESCAPE;
	else if ( IN_KeyName == "F1" )
		return VK_F1;
	else if ( IN_KeyName == "F2" )
		return VK_F2;
 	else if ( IN_KeyName == "F3" )
		return VK_F3;
	else if ( IN_KeyName == "F4" )
		return VK_F4;
	else if ( IN_KeyName == "F5" )
		return VK_F5;
	else if ( IN_KeyName == "F6" )
		return VK_F6;
	else if ( IN_KeyName == "F7" )
		return VK_F7;
	else if ( IN_KeyName == "F8" )
		return VK_F8;
	else if ( IN_KeyName == "F9" )
		return VK_F9;
	else if ( IN_KeyName == "F10" )
		return VK_F10;
	else if ( IN_KeyName == "F11" )
		return VK_F11;
	else if ( IN_KeyName == "F12" )
		return VK_F12;
	else if ( IN_KeyName == "~" )
		return VK_OEM_3;
	else if ( IN_KeyName == "-" )
		return VK_OEM_MINUS;
	else if ( IN_KeyName == "+" )
		return VK_OEM_PLUS;
	else if ( IN_KeyName == "BACKSPACE" )
		return VK_BACK;
	else if ( IN_KeyName == "TAB" )
		return VK_TAB;
	else if ( IN_KeyName == "[" )
		return VK_OEM_4;
	else if ( IN_KeyName == "]" )
		return VK_OEM_6;
	else if ( IN_KeyName == "\\" )
		return VK_OEM_5;
	else if ( IN_KeyName == "CAPSLOCK" )
		return VK_CAPITAL;
	else if ( IN_KeyName == ";" )
		return VK_OEM_1;
	else if ( IN_KeyName == "'" )
		return VK_OEM_7;
	else if ( IN_KeyName == "RETURN" )
		return VK_RETURN;
	else if ( IN_KeyName == "LSHIFT" )
		return VK_LSHIFT;
	else if ( IN_KeyName == "," )
		return VK_OEM_COMMA;
	else if ( IN_KeyName == "." )
		return VK_OEM_PERIOD;
	else if ( IN_KeyName == "/" )
		return VK_OEM_2;
	else if ( IN_KeyName == "RSHIFT" )
		return VK_RSHIFT;
	else if ( IN_KeyName == "LCONTROL" )
		return VK_LCONTROL;
	else if ( IN_KeyName == "LALT" )
		return VK_LMENU;
	else if ( IN_KeyName == "HANJA" )
		return VK_HANJA;
	else if ( IN_KeyName == "SPACE" )
		return VK_SPACE;
	else if ( IN_KeyName == "HANGUL" )
		return VK_HANGUL;
	else if ( IN_KeyName == "RALT" )
		return VK_RMENU;
	else if ( IN_KeyName == "RCONTROL" )
		return VK_RCONTROL;
	else if ( IN_KeyName == "HOME" )
		return VK_HOME;
	else if ( IN_KeyName == "END" )
		return VK_END;
	else if ( IN_KeyName == "INSERT" )
		return VK_INSERT;
	else if ( IN_KeyName == "PAGEUP" )
		return VK_PRIOR;
	else if ( IN_KeyName == "DELETE" )
		return VK_DELETE;
	else if ( IN_KeyName == "PAGEDOWN" )
		return VK_NEXT;
	else if ( IN_KeyName == "UP" )
		return VK_UP;
	else if ( IN_KeyName == "LEFT" )
		return VK_LEFT;
	else if ( IN_KeyName == "DOWN" )
		return VK_DOWN;
	else if ( IN_KeyName == "RIGHT" )
		return VK_RIGHT;
	else if ( IN_KeyName == "PSCREEN" )
		return VK_SNAPSHOT;
	else if ( IN_KeyName == "SCROLLLOCK" )
		return VK_SCROLL;
	else if ( IN_KeyName == "PAUSE" )
		return VK_PAUSE;
	else if ( IN_KeyName == "NUMLOCK" )
		return VK_NUMLOCK;
	else if ( IN_KeyName == "NUMPAD/" )
		return VK_DIVIDE;
	else if ( IN_KeyName == "NUMPAD*" )
		return VK_MULTIPLY;
	else if ( IN_KeyName == "NUMPAD-" )
		return VK_SUBTRACT;
	else if ( IN_KeyName == "NUMPAD+" )
		return VK_ADD;
	else if ( IN_KeyName == "NUMPAD." )
		return VK_DECIMAL;
	else if ( IN_KeyName == "NUMPAD0" )
		return VK_NUMPAD0;
	else if ( IN_KeyName == "NUMPAD1" )
		return VK_NUMPAD1;
	else if ( IN_KeyName == "NUMPAD2" )
		return VK_NUMPAD2;
	else if ( IN_KeyName == "NUMPAD3" )
		return VK_NUMPAD3;
	else if ( IN_KeyName == "NUMPAD4" )
		return VK_NUMPAD4;
	else if ( IN_KeyName == "NUMPAD5" )
		return VK_NUMPAD5;
	else if ( IN_KeyName == "NUMPAD6" )
		return VK_NUMPAD6;
	else if ( IN_KeyName == "NUMPAD7" )
		return VK_NUMPAD7;
	else if ( IN_KeyName == "NUMPAD8" )
		return VK_NUMPAD8;
	else if ( IN_KeyName == "NUMPAD9" )
		return VK_NUMPAD9;
	else if ( IN_KeyName == "LWIN" )
		return VK_LWIN;
	else if ( IN_KeyName == "RWIN" )
		return VK_RWIN;
	else if ( IN_KeyName == "RCLICKMENU")
		return VK_APPS;

	//숫자
	for (int i = 0x30; i <= 0x39; i++)
	{
		if (IN_KeyName.c_str()[0] == i)
		{
			return 0x30 + (i - 0x30);
		}
	}

	//알파벳
	for (int i = 0x41; i <= 0x5A; i++)
	{
		if (IN_KeyName.c_str()[0] == i)
		{
			return 0x41 + (i - 0x41);
		}
	}


	return 0;
}

bool CheckValidKeyName(std::string IN_KeyName)
{
	if ( IN_KeyName == "ESC" 
	|| IN_KeyName == "F1"
	|| IN_KeyName == "F2"
	|| IN_KeyName == "F3"
	|| IN_KeyName == "F4"
	|| IN_KeyName == "F5"
	|| IN_KeyName == "F6"
	|| IN_KeyName == "F7"
	|| IN_KeyName == "F8"
	|| IN_KeyName == "F9"
	|| IN_KeyName == "F10"
	|| IN_KeyName == "F11"
	|| IN_KeyName == "F12"
	|| IN_KeyName == "~"
	|| IN_KeyName == "-"
	|| IN_KeyName == "+"
	|| IN_KeyName == "BACKSPACE"
	|| IN_KeyName == "TAB"
	|| IN_KeyName == "["
	|| IN_KeyName == "]"
	|| IN_KeyName == "\\"
	|| IN_KeyName == "CAPSLOCK"
	|| IN_KeyName == ";"
	|| IN_KeyName == "'"
	|| IN_KeyName == "RETURN"
	|| IN_KeyName == "LSHIFT"
	|| IN_KeyName == ","
	|| IN_KeyName == "."
	|| IN_KeyName == "/"
	|| IN_KeyName == "RSHIFT"
	|| IN_KeyName == "LCONTROL"
	|| IN_KeyName == "LALT"
	|| IN_KeyName == "HANJA"
	|| IN_KeyName == "SPACE"
	|| IN_KeyName == "HANGUL"
	|| IN_KeyName == "RALT"
	|| IN_KeyName == "RCONTROL"
	|| IN_KeyName == "HOME"
	|| IN_KeyName == "END"
	|| IN_KeyName == "INSERT"
	|| IN_KeyName == "PAGEUP"
	|| IN_KeyName == "DELETE"
	|| IN_KeyName == "PAGEDOWN"
	|| IN_KeyName == "UP"
	|| IN_KeyName == "LEFT"
	|| IN_KeyName == "DOWN"
	|| IN_KeyName == "RIGHT"
	|| IN_KeyName == "PSCREEN"
	|| IN_KeyName == "SCROLLLOCK"
	|| IN_KeyName == "PAUSE"
	|| IN_KeyName == "NUMLOCK"
	|| IN_KeyName == "NUMPAD/"
	|| IN_KeyName == "NUMPAD*"
	|| IN_KeyName == "NUMPAD-"
	|| IN_KeyName == "NUMPAD+"
	|| IN_KeyName == "NUMPAD."
	|| IN_KeyName == "NUMPAD0"
	|| IN_KeyName == "NUMPAD1"
	|| IN_KeyName == "NUMPAD2"
	|| IN_KeyName == "NUMPAD3"
	|| IN_KeyName == "NUMPAD4"
	|| IN_KeyName == "NUMPAD5"
	|| IN_KeyName == "NUMPAD6"
	|| IN_KeyName == "NUMPAD7"
	|| IN_KeyName == "NUMPAD8"
	|| IN_KeyName == "NUMPAD9"
	|| IN_KeyName == "LWIN"
	|| IN_KeyName == "RWIN"
	|| IN_KeyName == "RCLICKMENU") 
	{
		return true;
	}

	//숫자
	for (int i = 0x30; i <= 0x39; i++)
	{
		if (IN_KeyName.c_str()[0] == i)
		{
			return true;
		}
	}

	//알파벳
	for (int i = 0x41; i <= 0x5A; i++)
	{
		if (IN_KeyName.c_str()[0] == i)
		{
			return true;
		}
	}

	return false;

}