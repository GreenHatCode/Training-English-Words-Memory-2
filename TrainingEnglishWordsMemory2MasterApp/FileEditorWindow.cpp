// FileEditorWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "FileEditorWindow.h"
#include "afxdialogex.h"


// FileEditorWindow dialog

IMPLEMENT_DYNAMIC(FileEditorWindow, CDialog)

FileEditorWindow::FileEditorWindow(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_FILE_EDITOR_WINDOW, pParent)
	, MainField(_T(""))
{
	//TODO: add a fg or something else to determine which window is opened for training file of for test files


}

FileEditorWindow::~FileEditorWindow()
{
}

void FileEditorWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MAIN_FIELD, MainField);
}


BEGIN_MESSAGE_MAP(FileEditorWindow, CDialog)
	ON_UPDATE_COMMAND_UI(ID_NAMESOFTRANSLATIONDIRECTIONS_LEFT, &FileEditorWindow::OnUpdateNamesoftranslationdirectionsLeft)
END_MESSAGE_MAP()


// FileEditorWindow message handlers



void FileEditorWindow::OnUpdateNamesoftranslationdirectionsLeft(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here

	pCmdUI->SetCheck(1);

	UpdateData(true);
	MainField = "success";
	UpdateData(false);
}
