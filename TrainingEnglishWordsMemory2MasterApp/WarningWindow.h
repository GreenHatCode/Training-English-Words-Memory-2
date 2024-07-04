#pragma once
#include "DoingType.h"
// WarningWindow dialog

class WarningWindow : public CDialog
{
	DECLARE_DYNAMIC(WarningWindow)

public:
	WarningWindow(CString filename, CWnd* pParent = nullptr);   // standard constructor
	virtual ~WarningWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WARNING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	virtual BOOL OnInitDialog();
	DoingType getUserAnswer();
private:
	CString Text;
	CString filename;
	DoingType userAnswer = DoingType::None; //whic button user pressed Save, Don't save or Cancel
};
