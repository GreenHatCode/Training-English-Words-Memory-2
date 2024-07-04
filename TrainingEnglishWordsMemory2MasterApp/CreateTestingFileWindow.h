#pragma once
#include "TestingFile.h"

// CreateTestingFileWindow dialog

class CreateTestingFileWindow : public CDialog
{
	DECLARE_DYNAMIC(CreateTestingFileWindow)

public:
	CreateTestingFileWindow(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CreateTestingFileWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CREATE_TESTING_FILE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString MainField;
	TestingFile file;
public:
	afx_msg void OnTranslationDirectionDirect();
	afx_msg void OnTranslationDirectionReverse();
	afx_msg void OnFilesettingsTime();
	afx_msg void OnWordorderDirect();
	afx_msg void OnWordorderReverse();
	afx_msg void OnWordorderRandom();
	afx_msg void OnFilesettingsNavigationbuttons();
	virtual BOOL OnInitDialog();
	afx_msg void OnNewTrainingfile();
	afx_msg void OnNewTestingfile();
	afx_msg void OnFileOpen32775();
	afx_msg void OnFileSave32777();
	afx_msg void OnFileExit();
	virtual void OnCancel();
};
