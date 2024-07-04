// NamesOfTranslationDirectionsWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "NamesOfTranslationDirectionsWindow.h"
#include "afxdialogex.h"


// NamesOfTranslationDirectionsWindow dialog

IMPLEMENT_DYNAMIC(NamesOfTranslationDirectionsWindow, CDialog)

NamesOfTranslationDirectionsWindow::NamesOfTranslationDirectionsWindow(CString& left, CString& right, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_NAMES_OF_TRANSLATION_DIRECTIONS_DIALOG, pParent)
	, LeftField(_T(""))
	, RightField(_T(""))
	, refLeftField(left)
	, refRightField(right)
{

}

NamesOfTranslationDirectionsWindow::~NamesOfTranslationDirectionsWindow()
{
}

void NamesOfTranslationDirectionsWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LEFT_FIELD, LeftField);
	DDX_Text(pDX, IDC_RIGHT_FIELD, RightField);
}


BEGIN_MESSAGE_MAP(NamesOfTranslationDirectionsWindow, CDialog)
END_MESSAGE_MAP()


// NamesOfTranslationDirectionsWindow message handlers


BOOL NamesOfTranslationDirectionsWindow::OnInitDialog()
{
	CDialog::OnInitDialog();

	// load data
	UpdateData(true);
	LeftField = refLeftField;
	RightField = refRightField;
	UpdateData(false);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void NamesOfTranslationDirectionsWindow::OnOK()
{
	// closes window and save data when ENTER has been pressed
	UpdateData(true);
	refLeftField = LeftField;
	refRightField = RightField;
	UpdateData(false);
	CDialog::OnOK();
}


void NamesOfTranslationDirectionsWindow::OnCancel()
{
	// closes window and save data by clicking on cancel button
	UpdateData(true);
	refLeftField = LeftField;
	refRightField = RightField;
	UpdateData(false);
	CDialog::OnCancel();
}
