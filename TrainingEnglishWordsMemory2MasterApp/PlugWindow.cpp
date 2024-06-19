// PlugWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "PlugWindow.h"
#include "afxdialogex.h"


// PlugWindow dialog

IMPLEMENT_DYNAMIC(PlugWindow, CDialog)

PlugWindow::PlugWindow(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

PlugWindow::~PlugWindow()
{
}

void PlugWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PlugWindow, CDialog)
END_MESSAGE_MAP()


// PlugWindow message handlers
