// EndingPhraseWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "EndingPhraseWindow.h"
#include "afxdialogex.h"


// EndingPhraseWindow dialog

IMPLEMENT_DYNAMIC(EndingPhraseWindow, CDialog)

EndingPhraseWindow::EndingPhraseWindow(CString& endingPhrase, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ENDING_PHRASE_FILE_DIALOG, pParent), refEndingPhrase(endingPhrase)
{
	//used initializer for reftype
}

EndingPhraseWindow::~EndingPhraseWindow()
{
}

void EndingPhraseWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MAIN_FIELD, Field);
}


BEGIN_MESSAGE_MAP(EndingPhraseWindow, CDialog)
END_MESSAGE_MAP()


// EndingPhraseWindow message handlers


BOOL EndingPhraseWindow::OnInitDialog()
{
	CDialog::OnInitDialog();

	UpdateData(true);
	Field = refEndingPhrase;
	UpdateData(false);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void EndingPhraseWindow::OnOK()
{
	//saving data by pressing ENTER key
	UpdateData(true);
	refEndingPhrase = Field;
	UpdateData(false);
	CDialog::OnOK();
}


void EndingPhraseWindow::OnCancel()
{
	//saving data when cancel button has been pressed
	UpdateData(true);
	refEndingPhrase = Field;
	UpdateData(false);
	CDialog::OnCancel();
}
