
// touhou_configDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "touhou_config.h"
#include "touhou_configDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctouhou_configDlg ��ȭ ����


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


// Ctouhou_configDlg �޽��� ó����

BOOL Ctouhou_configDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	MyINIManager.SetPath("config\\config.ini");
	std::string sFullScreen = MyINIManager.LoadFromINI("WindowStyle", "Fullscreen");
	if ( sFullScreen == "true" || sFullScreen == "")
	{
		((CButton*)GetDlgItem(IDC_RADIO_FULLSCREEN))->SetCheck(TRUE);
	}
	else	// "false" �Ǵ� �� ��
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

	//��ŷ ����
	m_Hook = NULL;
	m_Hook = SetWindowsHookEx(WH_KEYBOARD_LL, GetMsgProc, theApp.m_hInstance, NULL);
	if (m_Hook == NULL)
	{
		//��ŷ����
	}
	pDialog = this;

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Ctouhou_configDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Ctouhou_configDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctouhou_configDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void Ctouhou_configDlg::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialogEx::OnSysKeyDown(nChar, nRepCnt, nFlags);
}


void Ctouhou_configDlg::OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialogEx::OnSysChar(nChar, nRepCnt, nFlags);
}

BOOL Ctouhou_configDlg::DestroyWindow()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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


	//RALT => �ѿ���ȯŰ, RCONTROL => ����Ű�� �νĵ�
	//���α׷����� ������ �ƴ϶�, �׳� �Ϲ����� ��Ȳ���� RALT, RCONTROLŰ�� �׽�Ʈ�غ��� �� ��� �߻�
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

		//�ý��� Ű�� �Է¹��� �ʽ��ϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	((CButton*)GetDlgItem(IDC_RADIO_FULLSCREEN))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO_WINDOW))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO_DIRECTX))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO_OPENGL))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_CHECK_BGM))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_CHECK_SE))->SetCheck(TRUE);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BGM))->SetPos(100);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_SE))->SetPos(75);
}
