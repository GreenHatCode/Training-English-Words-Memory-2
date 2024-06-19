#pragma once


// FileEditorWindow dialog

class FileEditorWindow : public CDialog
{
	DECLARE_DYNAMIC(FileEditorWindow)

public:
	FileEditorWindow(CWnd* pParent = nullptr);   // standard constructor
	virtual ~FileEditorWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILE_EDITOR_WINDOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString MainField;
	afx_msg void OnUpdateNamesoftranslationdirectionsLeft(CCmdUI* pCmdUI);
};
