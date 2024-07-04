
// TrainingEnglishWordsMemory2MasterAppDlg.h : header file
//

#pragma once


// CTrainingEnglishWordsMemory2MasterAppDlg dialog
class CTrainingEnglishWordsMemory2MasterAppDlg : public CDialog
{
// Construction
public:
	CTrainingEnglishWordsMemory2MasterAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAININGENGLISHWORDSMEMORY2MASTERAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnAboutQuickguide();
	afx_msg void OnAboutAboutprogram();
	afx_msg void OnAboutAuthors();
};
