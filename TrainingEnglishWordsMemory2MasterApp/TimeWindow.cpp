// TimeWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "TimeWindow.h"
#include "afxdialogex.h"


// TimeWindow dialog

IMPLEMENT_DYNAMIC(TimeWindow, CDialog)

TimeWindow::TimeWindow(Time& TimeForTest, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TIME_DIALOG, pParent)
	, currTime(TimeForTest)
{
}

TimeWindow::~TimeWindow()
{
}

void TimeWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN_HOURS, SpinHoursButtonCtrl);
	DDX_Control(pDX, IDC_SPIN_MINUTES, SpinMinutesButtonCtrl);
	DDX_Control(pDX, IDC_SPIN_SECONDS, SpinSecondsButtonCtrl);
}


BEGIN_MESSAGE_MAP(TimeWindow, CDialog)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SECONDS, &TimeWindow::OnDeltaposSpinSeconds)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MINUTES, &TimeWindow::OnDeltaposSpinMinutes)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &TimeWindow::OnBnClickedButtonReset)
END_MESSAGE_MAP()


// TimeWindow message handlers


BOOL TimeWindow::OnInitDialog()
{
	CDialog::OnInitDialog();

	SpinHoursButtonCtrl.SetRange(0, 60);
	SpinHoursButtonCtrl.SetPos(currTime.getHours());
	SpinMinutesButtonCtrl.SetRange(0, 60);
	SpinMinutesButtonCtrl.SetPos(currTime.getMinutes());
	SpinSecondsButtonCtrl.SetRange(0, 60);
	SpinSecondsButtonCtrl.SetPos(currTime.getSeconds());

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void TimeWindow::OnCancel()
{
	// writes data in variable 'file' if window is closig
	currTime.setHours(SpinHoursButtonCtrl.GetPos());
	currTime.setMinutes(SpinMinutesButtonCtrl.GetPos());
	currTime.setSeconds(SpinSecondsButtonCtrl.GetPos());
	CDialog::OnCancel();
}


void TimeWindow::OnDeltaposSpinSeconds(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (SpinSecondsButtonCtrl.GetPos() == 60)
	{
		SpinSecondsButtonCtrl.SetPos(0);
		SpinMinutesButtonCtrl.SetPos(SpinMinutesButtonCtrl.GetPos() + 1);
	}
}


void TimeWindow::OnDeltaposSpinMinutes(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (SpinMinutesButtonCtrl.GetPos() == 60)
	{
		SpinMinutesButtonCtrl.SetPos(0);
		SpinHoursButtonCtrl.SetPos(SpinHoursButtonCtrl.GetPos() + 1);
	}
}


void TimeWindow::OnBnClickedButtonReset()
{
	SpinHoursButtonCtrl.SetPos(0);
	SpinMinutesButtonCtrl.SetPos(0);
	SpinSecondsButtonCtrl.SetPos(0);
}
