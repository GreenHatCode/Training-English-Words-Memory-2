#pragma once
#include "TrainingFile.h"


// CreateTrainingFileWindow dialog

class CreateTrainingFileWindow : public CDialog
{
	DECLARE_DYNAMIC(CreateTrainingFileWindow)

public:
	CreateTrainingFileWindow(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CreateTrainingFileWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CREATE_TRAINING_FILE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	TrainingFile file;
	CString MainField;
public:
	afx_msg void OnFilesettingsEndingphrase();
	afx_msg void OnFilesettingsTranslationdirection();
	afx_msg void OnFileSave32777();
	afx_msg void OnFileOpen32775();
	virtual BOOL OnInitDialog();
	afx_msg void OnFileExit();
	afx_msg void OnNewTrainingfile();
	afx_msg void OnNewTestingfile();
	virtual void OnCancel();
};
