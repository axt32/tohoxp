
// touhou_config.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Ctouhou_configApp:
// �� Ŭ������ ������ ���ؼ��� touhou_config.cpp�� �����Ͻʽÿ�.
//

class Ctouhou_configApp : public CWinApp
{
public:
	Ctouhou_configApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern Ctouhou_configApp theApp;