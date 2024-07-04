// WarningWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "WarningWindow.h"
#include "afxdialogex.h"
#include "DoingType.h"

// WarningWindow dialog

IMPLEMENT_DYNAMIC(WarningWindow, CDialog)

WarningWindow::WarningWindow(CString filename, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_WARNING_DIALOG, pParent)
	, Text(_T(""))
{
	this->filename = filename;
}

WarningWindow::~WarningWindow()
{
}

void WarningWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT, Text);
}


BEGIN_MESSAGE_MAP(WarningWindow, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &WarningWindow::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &WarningWindow::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &WarningWindow::OnBnClickedButton5)
END_MESSAGE_MAP()

BOOL WarningWindow::OnInitDialog()
{
	CDialog::OnInitDialog();

	UpdateData(true);
	Text = L"Do you want to save changes to the file\n " + filename;
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

DoingType WarningWindow::getUserAnswer()
{
	if (userAnswer != DoingType::None)return userAnswer;
	else
	{
		AfxMessageBox(L"WarningWindow class, userAnswer can't be returned with NONE value");
		return DoingType::None;
	}
}

// WarningWindow message handlers


void WarningWindow::OnBnClickedButton1()
{
	//save
	userAnswer = DoingType::Save;
	OnCancel();
}


void WarningWindow::OnBnClickedButton4()
{
	//don't save
	userAnswer = DoingType::NotSave;
	OnCancel();
}


void WarningWindow::OnBnClickedButton5()
{
	//cancel
	userAnswer = DoingType::Cancel;
	OnCancel();
}