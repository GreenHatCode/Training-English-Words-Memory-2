
// TrainingEnglishWordsMemory2MasterAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "TrainingEnglishWordsMemory2MasterAppDlg.h"
#include "afxdialogex.h"

#include "AboutWindow.h"
#include "CreateTestingFileWindow.h"
#include "CreateTrainingFileWindow.h"
#include "TextType.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CTrainingEnglishWordsMemory2MasterAppDlg dialog



CTrainingEnglishWordsMemory2MasterAppDlg::CTrainingEnglishWordsMemory2MasterAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TRAININGENGLISHWORDSMEMORY2MASTERAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrainingEnglishWordsMemory2MasterAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTrainingEnglishWordsMemory2MasterAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CTrainingEnglishWordsMemory2MasterAppDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CTrainingEnglishWordsMemory2MasterAppDlg::OnBnClickedButton2)
	ON_COMMAND(ID_ABOUT_QUICKGUIDE, &CTrainingEnglishWordsMemory2MasterAppDlg::OnAboutQuickguide)
	ON_COMMAND(ID_ABOUT_ABOUTPROGRAM, &CTrainingEnglishWordsMemory2MasterAppDlg::OnAboutAboutprogram)
	ON_COMMAND(ID_ABOUT_AUTHORS, &CTrainingEnglishWordsMemory2MasterAppDlg::OnAboutAuthors)
END_MESSAGE_MAP()


// CTrainingEnglishWordsMemory2MasterAppDlg message handlers

BOOL CTrainingEnglishWordsMemory2MasterAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrainingEnglishWordsMemory2MasterAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrainingEnglishWordsMemory2MasterAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTrainingEnglishWordsMemory2MasterAppDlg::OnBnClickedButton3()
{
	//training file window
	CreateTrainingFileWindow newWindow;
	this->ShowWindow(SW_HIDE);
	newWindow.DoModal();
	this->ShowWindow(SW_SHOW);

}


void CTrainingEnglishWordsMemory2MasterAppDlg::OnBnClickedButton2()
{
	//create testing file window
	CreateTestingFileWindow newWindow;
	this->ShowWindow(SW_HIDE);
	newWindow.DoModal();
	this->ShowWindow(SW_SHOW);

}

void CTrainingEnglishWordsMemory2MasterAppDlg::OnAboutQuickguide()
{
	AfxMessageBox(L"Will be added in future verison. Watch the guide in folder \"QuickGuide\".");
}


void CTrainingEnglishWordsMemory2MasterAppDlg::OnAboutAboutprogram()
{
	AboutWindow newWindow(TextType::AboutApp);
	this->ShowWindow(SW_HIDE);
	newWindow.DoModal();
	this->ShowWindow(SW_SHOW);
}


void CTrainingEnglishWordsMemory2MasterAppDlg::OnAboutAuthors()
{
	AboutWindow newWindow(TextType::AboutAuthor);
	this->ShowWindow(SW_HIDE);
	newWindow.DoModal();
	this->ShowWindow(SW_SHOW);
}
