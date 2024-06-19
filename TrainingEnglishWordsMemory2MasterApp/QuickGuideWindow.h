#pragma once


// QuickGuideWindow dialog

class QuickGuideWindow : public CDialog
{
	DECLARE_DYNAMIC(QuickGuideWindow)

public:
	QuickGuideWindow(CWnd* pParent = nullptr);   // standard constructor
	virtual ~QuickGuideWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUICK_GUIDE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	virtual BOOL OnInitDialog();
	void SetBitmapByNum(int n);
private:
	CStatic Pic; //outputs image
	int ImageNum = 0;
	int MaxImageNum = 1;
};
