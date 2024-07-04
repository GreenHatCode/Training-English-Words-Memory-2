#pragma once


// NamesOfTranslationDirectionsWindow dialog

class NamesOfTranslationDirectionsWindow : public CDialog
{
	DECLARE_DYNAMIC(NamesOfTranslationDirectionsWindow)

public:
	NamesOfTranslationDirectionsWindow(CString& left, CString& right, CWnd* pParent = nullptr);   // standard constructor
	virtual ~NamesOfTranslationDirectionsWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NAMES_OF_TRANSLATION_DIRECTIONS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString LeftField; //by default "Direct"
	CString RightField; //by default "Reverse"
	CString& refLeftField;
	CString& refRightField;
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
};
