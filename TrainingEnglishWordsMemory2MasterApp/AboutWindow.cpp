// AboutWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "AboutWindow.h"
#include "afxdialogex.h"


// AboutWindow dialog

IMPLEMENT_DYNAMIC(AboutWindow, CDialog)

AboutWindow::AboutWindow(TextType text, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ABOUT_DIALOG, pParent)
	, TextField(_T(""))
{
	this->windowTextType = text;
}

AboutWindow::~AboutWindow()
{
}

void AboutWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, TextField);
}


BEGIN_MESSAGE_MAP(AboutWindow, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &AboutWindow::OnBnClickedButton1)
END_MESSAGE_MAP()


// AboutWindow message handlers


void AboutWindow::OnBnClickedButton1()
{
	//code with link on my github repozitory with this app
	system("explorer https://github.com/SashaZemC.html");
}


BOOL AboutWindow::OnInitDialog()
{
	CDialog::OnInitDialog();

	//loading text.
	CStdioFile inf;
	inf.Open(L"res\\about.txt", CFile::modeRead);
	CString buf, ms;
	bool fg1 = false;
	if (windowTextType == TextType::AboutAuthor)
	{
		SetWindowTextW(L"About Authors");
		while (inf.ReadString(buf))
		{
			if (buf == "AboutAuthorsEND")break;
			if (fg1)ms += buf;
			if (buf == "AboutAuthorsSTART") fg1 = true;

		}
		inf.Close();
	}
	else if (windowTextType == TextType::AboutApp)
	{
		SetWindowTextW(L"About Program");
		while (inf.ReadString(buf))
		{
			if (buf == "AboutProgramEND")break;
			if (fg1)ms += buf;
			if (buf == "AboutProgramSTART") fg1 = true;

		}
		inf.Close();
	}

	UpdateData(true);
	TextField = ms;
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}