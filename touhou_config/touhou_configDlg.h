
// touhou_configDlg.h : ��� ����
//

#pragma once
#include <string>
#include "ExternalUtil/INIManager/INIManager.h"
#include "ExternalUtil/VirtualKeyConverter/VirtualKeyConverter.h"

// Ctouhou_configDlg ��ȭ ����
class Ctouhou_configDlg : public CDialogEx
{
// �����Դϴ�.
public:
	Ctouhou_configDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TOUHOU_CONFIG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;
	INIManager MyINIManager;
	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	CEdit m_EditLeftKey;
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL DestroyWindow();

	HHOOK m_Hook;
	void LoadKeyConfig(std::string sCategory, int nID, std::string sDefaultText);
	void SaveKeyConfig (std::string sCategory, int nID);
	void LoadVolumeConfig(std::string sCategory, int nID, int sDefaultValue);
	void SaveVolumeConfig (std::string sCategory, int nID);
	afx_msg void OnBnClickedButtonKeyDefault();
	afx_msg void OnBnClickedButtonDisplaysoundDefault();
};

LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam);