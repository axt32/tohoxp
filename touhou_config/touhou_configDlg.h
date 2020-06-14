
// touhou_configDlg.h : 헤더 파일
//

#pragma once
#include <string>
#include "ExternalUtil/INIManager/INIManager.h"
#include "ExternalUtil/VirtualKeyConverter/VirtualKeyConverter.h"

// Ctouhou_configDlg 대화 상자
class Ctouhou_configDlg : public CDialogEx
{
// 생성입니다.
public:
	Ctouhou_configDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TOUHOU_CONFIG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	INIManager MyINIManager;
	// 생성된 메시지 맵 함수
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