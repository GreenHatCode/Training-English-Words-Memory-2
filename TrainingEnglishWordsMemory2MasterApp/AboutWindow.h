#pragma once
#include <string>
#include "TextType.h"


// AboutWindow dialog

class AboutWindow : public CDialog
{
	DECLARE_DYNAMIC(AboutWindow)

public:
	AboutWindow(TextType text ,CWnd* pParent = nullptr);   // standard constructor
	virtual ~AboutWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	CString TextField; // outputs str in sample edit box
	TextType windowTextType = TextType::NoType; //determines which text from about.txt will be outputed (about authors or about app)
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
