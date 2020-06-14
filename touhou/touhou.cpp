// Touhou-like Style Vertical Shoot'em up Game
// Touhou Explosion - Tiny Cherry Blossom
// Seria (Sprite Engine with Reinforced Interface for Amusement) - (C) 2014. AXT SOFTWARE
// ���ð������� ���������� ���� �����մϴ�.
// �����Ӱ� ������ �����ϸ�, �������� ������ �����մϴ�. (MIT License)
// ��, ������ ���� �� ������ ǥ��� �� ���ֽñ� �ٶ��ϴ�.
// ���� �Ǵ� ���������� ������� ����� �Ұ����մϴ�.
// �� ���ӿ��� ������� ����ϰ��ִ� ��� �׷��� �ҽ��� ���� �ҽ��� ���α׷��� �н� �������� ����ϰ� �ֽ��ϴ�.
// �� ���۱����� ���� ���� �ٶ��ϴ�.
// �� ���ӿ� ���� ��� �׷��� �ҽ��� ���� �ҽ��� �������ڿ��� �ֽ��ϴ�.
// 2014 AXT Software.
// http://www.axtsoft.co.kr/
// http://www.axtsoft.co.kr/tohoxp

#include "MemoryLeakChecker.h"

#include "stdafx.h"
#include "GameCore/GameMain.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//�ܼ�â �����
#ifndef _DEBUG
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
#endif

#ifdef _DEBUG
	::_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(57574);
#endif
	LoadData();
	GameMain();
	Unload();

	return 0;
}