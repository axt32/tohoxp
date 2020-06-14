
// touhou_configDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "touhou_config.h"
#include "touhou_configDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctouhou_configDlg 대화 상자


Ctouhou_configDlg * pDialog;

Ctouhou_configDlg::Ctouhou_configDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctouhou_configDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctouhou_configDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctouhou_configDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ctouhou_configDlg::OnBnClickedOk)
	ON_WM_KEYDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SYSKEYDOWN()
	ON_WM_SYSCHAR()
	ON_BN_CLICKED(IDC_BUTTON_KEY_DEFAULT, &Ctouhou_configDlg::OnBnClickedButtonKeyDefault)
	ON_BN_CLICKED(IDC_BUTTON_DISPLAYSOUND_DEFAULT, &Ctouhou_configDlg::OnBnClickedButtonDisplaysoundDefault)
END_MESSAGE_MAP()


// Ctouhou_configDlg 메시지 처리기

BOOL Ctouhou_configDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	MyINIManager.SetPath("config\\config.ini");
	std::string sFullScreen = MyINIManager.LoadFromINI("WindowStyle", "Fullscreen");
	if ( sFullScreen == "true" || sFullScreen == "")
	{
		((CButton*)GetDlgItem(IDC_RADIO_FULLSCREEN))->SetCheck(TRUE);
	}
	else	// "false" 또는 그 외
	{
		((CButton*)GetDlgItem(IDC_RADIO_WINDOW))->SetCheck(TRUE);
	}

	std::string sRenderer = MyINIManager.LoadFromINI("Renderer", "Renderer");
	if (sRenderer == "DirectX" || sRenderer == "")
	{
		((CButton*)GetDlgItem(IDC_RADIO_DIRECTX))->SetCheck(TRUE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO_OPENGL))->SetCheck(TRUE);
	}

	std::string sBGM_Use = MyINIManager.LoadFromINI("Sound", "BGM_Use");
	if (sBGM_Use == "" || sBGM_Use == "true")
	{
		((CButton*)GetDlgItem(IDC_CHECK_BGM))->SetCheck(TRUE);
	}

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BGM))->SetRange(0, 100);
	LoadVolumeConfig("BGM_Volume", IDC_SLIDER_BGM, 100);

	std::string sSE_Use = MyINIManager.LoadFromINI("Sound", "SE_Use");
	if (sSE_Use == "" || sSE_Use == "true")
	{
		((CButton*)GetDlgItem(IDC_CHECK_SE))->SetCheck(TRUE);
	}

	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SE))->SetRange(0, 100);
	LoadVolumeConfig("SE_Volume", IDC_SLIDER_SE, 75);

	LoadKeyConfig("Up", IDC_EDIT_UP, "UP");
	LoadKeyConfig("Down", IDC_EDIT_DOWN, "DOWN");
	LoadKeyConfig("Left", IDC_EDIT_LEFT, "LEFT");
	LoadKeyConfig("Right", IDC_EDIT_RIGHT, "RIGHT");
	LoadKeyConfig("ButtonA", IDC_EDIT_BUTTONA, "Z");
	LoadKeyConfig("ButtonB", IDC_EDIT_BUTTONB, "X");
	LoadKeyConfig("ButtonC", IDC_EDIT_BUTTONC, "LSHIFT");
	LoadKeyConfig("SKIP", IDC_EDIT_SKIP, "LCONTROL");

	//후킹 시작
	m_Hook = NULL;
	m_Hook = SetWindowsHookEx(WH_KEYBOARD_LL, GetMsgProc, theApp.m_hInstance, NULL);
	if (m_Hook == NULL)
	{
		//후킹에러
	}
	pDialog = this;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Ctouhou_configDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Ctouhou_configDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctouhou_configDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//test
	if (((CButton*)GetDlgItem(IDC_RADIO_FULLSCREEN))->GetCheck() == TRUE)
	{
		MyINIManager.SaveToINI("WindowStyle", "Fullscreen", "true");
	}
	else
	{
		MyINIManager.SaveToINI("WindowStyle", "Fullscreen", "false");
	}

	if (((CButton*)GetDlgItem(IDC_RADIO_DIRECTX))->GetCheck() == TRUE)
	{
		MyINIManager.SaveToINI("Renderer", "Renderer", "DirectX");
	}
	else
	{
		MyINIManager.SaveToINI("Renderer", "Renderer", "OpenGL");
	}

	if (((CButton*)GetDlgItem(IDC_CHECK_BGM))->GetCheck() == TRUE)
	{
		MyINIManager.SaveToINI("Sound", "BGM_Use", "true");
	}
	else
	{
		MyINIManager.SaveToINI("Sound", "BGM_Use", "false");
	}

	SaveVolumeConfig("BGM_Volume", IDC_SLIDER_BGM);

	if (((CButton*)GetDlgItem(IDC_CHECK_SE))->GetCheck() == TRUE)
	{
		MyINIManager.SaveToINI("Sound", "SE_Use", "true");
	}
	else
	{
		MyINIManager.SaveToINI("Sound", "SE_Use", "false");
	}

	SaveVolumeConfig("SE_Volume", IDC_SLIDER_SE);

	SaveKeyConfig("UP", IDC_EDIT_UP);
	SaveKeyConfig("DOWN", IDC_EDIT_DOWN);
	SaveKeyConfig("LEFT", IDC_EDIT_LEFT);
	SaveKeyConfig("RIGHT", IDC_EDIT_RIGHT);
	SaveKeyConfig("ButtonA", IDC_EDIT_BUTTONA);
	SaveKeyConfig("ButtonB", IDC_EDIT_BUTTONB);
	SaveKeyConfig("ButtonC", IDC_EDIT_BUTTONC);
	SaveKeyConfig("SKIP", IDC_EDIT_SKIP);

	CDialogEx::OnOK();
}


BOOL Ctouhou_configDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	WPARAM iKey = pMsg->wParam;
	switch (iKey)
	{
	case VK_ESCAPE:
	case VK_F1:
	case VK_RETURN:
	case VK_TAB:
	case VK_F10:
	case VK_SNAPSHOT:
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void Ctouhou_configDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Ctouhou_configDlg::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnSysKeyDown(nChar, nRepCnt, nFlags);
}


void Ctouhou_configDlg::OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnSysChar(nChar, nRepCnt, nFlags);
}

BOOL Ctouhou_configDlg::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (m_Hook != NULL)
	{
		UnhookWindowsHookEx(m_Hook);
	}

	return CDialogEx::DestroyWindow();
}

LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	int cID = pDialog->GetFocus()->GetDlgCtrlID();
	KBDLLHOOKSTRUCT * pKey = (KBDLLHOOKSTRUCT * )lParam;
	if (nCode < 0)
	{
		return CallNextHookEx(pDialog->m_Hook, nCode, wParam, lParam);
	}


	//RALT => 한영전환키, RCONTROL => 한자키로 인식됨
	//프로그램상의 오류가 아니라, 그냥 일반적인 상황에서 RALT, RCONTROL키를 테스트해봐도 동 결과 발생
	if (nCode == HC_ACTION)
	{
		switch ( cID )
		{
		case IDC_EDIT_UP:
		case IDC_EDIT_DOWN:
		case IDC_EDIT_LEFT:
		case IDC_EDIT_RIGHT:
		case IDC_EDIT_BUTTONA:
		case IDC_EDIT_BUTTONB:
		case IDC_EDIT_BUTTONC:
			if (GetAsyncKeyState (VK_LMENU))
			{
				SetDlgItemText(pDialog->m_hWnd, cID, VKeyToKeyName(VK_LMENU).c_str());
				return CallNextHookEx(pDialog->m_Hook, nCode, wParam, lParam);
			}
			break;
		default:
			break;
		}
	}

	if (wParam == WM_KEYDOWN)
	{
		std::string KeyString = "";

		KeyString = "";
		DWORD iKey = pKey->vkCode;

		//시스템 키는 입력받지 않습니다.
		if (iKey == VK_RETURN || iKey == VK_ESCAPE || iKey == VK_LWIN || iKey == VK_RWIN)
		{
			return CallNextHookEx(pDialog->m_Hook, nCode, wParam, lParam);
		}

		switch ( cID )
		{
		case IDC_EDIT_UP:
		case IDC_EDIT_DOWN:
		case IDC_EDIT_LEFT:
		case IDC_EDIT_RIGHT:
		case IDC_EDIT_BUTTONA:
		case IDC_EDIT_BUTTONB:
		case IDC_EDIT_BUTTONC:
		case IDC_EDIT_SKIP:
			SetDlgItemText(pDialog->m_hWnd, cID, VKeyToKeyName(iKey).c_str());
			break;
		default:
			break;
		}
	}

	return CallNextHookEx(pDialog->m_Hook, nCode, wParam, lParam);
}

void Ctouhou_configDlg :: LoadKeyConfig(std::string sCategory, int nID, std::string sDefaultText)
{
	std::string sTemp = MyINIManager.LoadFromINI("KeySetting", sCategory);

	if (CheckValidKeyName(sTemp))
	{
		SetDlgItemText(nID, sTemp.c_str());	
	}
	else
	{
		SetDlgItemText(nID, sDefaultText.c_str());
	}
}

void Ctouhou_configDlg :: SaveVolumeConfig (std::string sCategory, int nID)
{
	int iValue = ((CSliderCtrl*)GetDlgItem(nID))->GetPos();
	MyINIManager.SaveToINI("Sound", sCategory, std::to_string((_ULonglong)iValue));
};

void Ctouhou_configDlg :: LoadVolumeConfig(std::string sCategory, int nID, int sDefaultValue)
{
	std::string sTemp = MyINIManager.LoadFromINI("Sound", sCategory);
	
	int iValue = sDefaultValue;

	if (sTemp != "")
	{
		int iTempValue = atoi(sTemp.c_str());
		if ( iTempValue >= 0 && iTempValue <= 100)
		{
			iValue = iTempValue;
		}
	}

	((CSliderCtrl*)GetDlgItem(nID))->SetPos(iValue);
}

void Ctouhou_configDlg :: SaveKeyConfig (std::string sCategory, int nID)
{
	CString temp;
	GetDlgItemText(nID, temp);
	MyINIManager.SaveToINI("KeySetting", sCategory, (std::string)(temp));
};

void Ctouhou_configDlg::OnBnClickedButtonKeyDefault()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT_UP, "UP");
	SetDlgItemText(IDC_EDIT_DOWN, "DOWN");
	SetDlgItemText(IDC_EDIT_LEFT, "LEFT");
	SetDlgItemText(IDC_EDIT_RIGHT, "RIGHT");
	SetDlgItemText(IDC_EDIT_BUTTONA, "Z");
	SetDlgItemText(IDC_EDIT_BUTTONB, "X");
	SetDlgItemText(IDC_EDIT_BUTTONC, "LSHIFT");
	SetDlgItemText(IDC_EDIT_SKIP, "LCONTROL");

}


void Ctouhou_configDlg::OnBnClickedButtonDisplaysoundDefault()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CButton*)GetDlgItem(IDC_RADIO_FULLSCREEN))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO_WINDOW))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO_DIRECTX))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO_OPENGL))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_CHECK_BGM))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_CHECK_SE))->SetCheck(TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BGM))->SetPos(100);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SE))->SetPos(75);
}
