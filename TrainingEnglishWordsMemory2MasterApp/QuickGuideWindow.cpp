// QuickGuideWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "QuickGuideWindow.h"
#include "afxdialogex.h"


// QuickGuideWindow dialog

IMPLEMENT_DYNAMIC(QuickGuideWindow, CDialog)

QuickGuideWindow::QuickGuideWindow(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_QUICK_GUIDE_DIALOG, pParent)
{

}

QuickGuideWindow::~QuickGuideWindow()
{
}

void QuickGuideWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, Pic);
}


BEGIN_MESSAGE_MAP(QuickGuideWindow, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &QuickGuideWindow::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &QuickGuideWindow::OnBnClickedButton4)
END_MESSAGE_MAP()


// QuickGuideWindow message handlers


void QuickGuideWindow::OnBnClickedButton1()
{
	// button "Previous"
	if (ImageNum > 0)ImageNum--;
	else ImageNum = MaxImageNum;
	SetBitmapByNum(ImageNum);
}


void QuickGuideWindow::OnBnClickedButton4()
{
	// button "Next"
	if (ImageNum < MaxImageNum)ImageNum++;
	else ImageNum = 0;
	SetBitmapByNum(ImageNum);
}


BOOL QuickGuideWindow::OnInitDialog()
{
	CDialog::OnInitDialog();

	HBITMAP image = (HBITMAP)LoadImage(NULL, L"res\\tutorial0.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	Pic.SetBitmap(image);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void QuickGuideWindow::SetBitmapByNum(int n)
{
	//TODO: remake algorithm. it has to load all files from folder res in order: tutorial1, tutorial2... 
	//to add files in load queue, dev has to add them in folder res
	//add more pics

	HBITMAP image = (HBITMAP)LoadImage(NULL, L"res\\tutorial0.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	switch (n)
	{
	case 0:
		image = (HBITMAP)LoadImage(NULL, L"res\\tutorial0.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	case 1:
		image = (HBITMAP)LoadImage(NULL, L"res\\tutorial1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		break;
	default:
		AfxMessageBox(L"error. QuickGuideWindow.cpp");
		break;
	}
	
	Pic.SetBitmap(image);
}
