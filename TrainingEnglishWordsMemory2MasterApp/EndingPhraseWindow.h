#pragma once

// EndingPhraseWindow dialog

class EndingPhraseWindow : public CDialog
{
	DECLARE_DYNAMIC(EndingPhraseWindow)

public:
	EndingPhraseWindow(CString &endingPhrase, CWnd* pParent = nullptr);   // standard constructor
	virtual ~EndingPhraseWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENDING_PHRASE_FILE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString& refEndingPhrase;
	CString Field;
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	virtual void OnCancel();
};
