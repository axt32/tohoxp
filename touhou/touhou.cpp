// Touhou-like Style Vertical Shoot'em up Game
// Touhou Explosion - Tiny Cherry Blossom
// Seria (Sprite Engine with Reinforced Interface for Amusement) - (C) 2014. AXT SOFTWARE
// 슈팅게임제작 정보공유를 위해 배포합니다.
// 자유롭게 수정이 가능하며, 수정본의 배포도 가능합니다. (MIT License)
// 단, 수정본 배포 시 원작자 표기는 꼭 해주시기 바랍니다.
// 원본 또는 수정본으로 상업적인 사용은 불가능합니다.
// 본 게임에서 허락없이 사용하고있는 모든 그래픽 소스와 사운드 소스는 프로그래밍 학습 목적으로 사용하고 있습니다.
// 원 저작권자의 많은 양해 바랍니다.
// 본 게임에 쓰인 모든 그래픽 소스와 사운드 소스는 원제작자에게 있습니다.
// 2014 AXT Software.
// http://www.axtsoft.co.kr/
// http://www.axtsoft.co.kr/tohoxp

#include "MemoryLeakChecker.h"

#include "stdafx.h"
#include "GameCore/GameMain.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//콘솔창 숨기기
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