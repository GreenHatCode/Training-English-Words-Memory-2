#pragma once


// PlugWindow dialog

class PlugWindow : public CDialog
{
	DECLARE_DYNAMIC(PlugWindow)

public:
	PlugWindow(CWnd* pParent = nullptr);   // standard constructor
	virtual ~PlugWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
