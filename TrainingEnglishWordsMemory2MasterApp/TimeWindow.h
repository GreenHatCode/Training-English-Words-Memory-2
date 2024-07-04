#pragma once
#include "Time.h"


// TimeWindow dialog

class TimeWindow : public CDialog
{
	DECLARE_DYNAMIC(TimeWindow)

public:
	TimeWindow(Time &TimeForTest, CWnd* pParent = nullptr);   // standard constructor
	virtual ~TimeWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIME_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	Time &currTime;
	CSpinButtonCtrl SpinHoursButtonCtrl;
	CSpinButtonCtrl SpinMinutesButtonCtrl;
	CSpinButtonCtrl SpinSecondsButtonCtrl;
public:
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnDeltaposSpinSeconds(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinMinutes(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonReset();
};
