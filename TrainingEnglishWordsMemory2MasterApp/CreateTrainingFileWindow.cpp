// CreateTrainingFileWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "CreateTrainingFileWindow.h"
#include "afxdialogex.h"
#include "EndingPhraseWindow.h"
#include "NamesOfTranslationDirectionsWindow.h"
#include <iostream>
#include "WarningWindow.h"
#include "DoingType.h"


// CreateTrainingFileWindow dialog

IMPLEMENT_DYNAMIC(CreateTrainingFileWindow, CDialog)

CreateTrainingFileWindow::CreateTrainingFileWindow(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CREATE_TRAINING_FILE_DIALOG, pParent)
	, MainField(_T(""))
{

}

CreateTrainingFileWindow::~CreateTrainingFileWindow()
{
}

void CreateTrainingFileWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, MainField);
}


BEGIN_MESSAGE_MAP(CreateTrainingFileWindow, CDialog)
	ON_COMMAND(ID_FILESETTINGS_ENDINGPHRASE, &CreateTrainingFileWindow::OnFilesettingsEndingphrase)
	ON_COMMAND(ID_FILESETTINGS_TRANSLATIONDIRECTION, &CreateTrainingFileWindow::OnFilesettingsTranslationdirection)
	ON_COMMAND(ID_FILE_SAVE32777, &CreateTrainingFileWindow::OnFileSave32777)
	ON_COMMAND(ID_FILE_OPEN32775, &CreateTrainingFileWindow::OnFileOpen32775)
	ON_COMMAND(ID_FILE_EXIT, &CreateTrainingFileWindow::OnFileExit)
	ON_COMMAND(ID_NEW_TRAININGFILE, &CreateTrainingFileWindow::OnNewTrainingfile)
	ON_COMMAND(ID_NEW_TESTINGFILE, &CreateTrainingFileWindow::OnNewTestingfile)
END_MESSAGE_MAP()

BOOL CreateTrainingFileWindow::OnInitDialog()
{
	CDialog::OnInitDialog();
	setlocale(LC_ALL, "rus");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CreateTrainingFileWindow::OnFilesettingsEndingphrase()
{
	//calls ending phrase window
	//and sets the ending phrase
	CString str = file.getEndingPhrase();
	EndingPhraseWindow newWindow(str);
	newWindow.DoModal();
	file.setEndingPhrase(str);
}


void CreateTrainingFileWindow::OnFilesettingsTranslationdirection()
{
	//calls names of translation direction window
	//and sets their names
	CString strLeft = file.getLeftTrainslationDirectionName();
	CString strRight = file.getRightTrainslationDirectionName();
	NamesOfTranslationDirectionsWindow newWindow(strLeft, strRight);
	newWindow.DoModal();
	file.setLeftTrainslationDirectionName(strLeft);
	file.setRightTrainslationDirectionName(strRight);
}


void CreateTrainingFileWindow::OnFileSave32777()
{
	//saving function
	// TODO: add accelerator to launch this function by pressing Ctrl+s

	if ((file.getFilePathName()).IsEmpty())
	{
		//saving data in new file that created using windows explorer
		LPCTSTR pszFilter =
			_T("TEWM (*.tewm)|*.tewm|"); //pointer to the string

		CFileDialog dlgFile(FALSE, _T("TEWM"), _T("unnamed.tewm"),
			OFN_OVERWRITEPROMPT, pszFilter, AfxGetMainWnd()); 
		//if we want to open 'save as' dialog, we need to put FALSE
		// if we want to open 'Open' dialog, we need to put TRUE

		if (IDOK == dlgFile.DoModal()) //launch the dialog
		{
			try
			{
				UpdateData(true);
				file.setData(MainField);
				UpdateData(false);

				CStdioFile otf(dlgFile.GetPathName(), CFile::modeCreate | CFile::modeWrite | CFile::typeText); //opening file to write
				if (dlgFile.GetFileExt() == _T("tewm"))
				{
					otf.WriteString(file.getDataToSave());
					otf.Flush();
				}
				file.setFilePathName(otf.GetFilePath());
				otf.Close();
			}
			catch (CFileException* pe)
			{
				CString error;
				error.Format(_T("File could not be saved, cause = %d\n"),
					pe->m_cause);
				AfxMessageBox(error);
				pe->Delete();
			}
		}
	}
	else
	{
		UpdateData(true);
		file.setData(MainField);
		UpdateData(false);

		//saving data in opened file
		char charFilePathName[256];
		strcpy_s(charFilePathName, CStringA(file.getFilePathName()).GetString());

		CStdioFile otf(L"temp.tewm", CFile::modeCreate | CFile::modeWrite);
		otf.WriteString(file.getDataToSave());
		otf.Flush();
		otf.Close();
		remove(charFilePathName);
		if (rename("temp.tewm", charFilePathName))AfxMessageBox(L"File could not be saved, problem with rename function.");
	}
}


void CreateTrainingFileWindow::OnFileOpen32775()
{
	//file extentions that can be opened
	LPCTSTR pszFilter =
		_T("TEWM (*.tewm)|*.tewm|"); //pointer to the string

	CFileDialog dlgFile(TRUE, _T("TEWM"), NULL,
		OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, pszFilter, AfxGetMainWnd());

	if (IDOK == dlgFile.DoModal()) //launch the dialog
	{
		try
		{
			CStdioFile inf(dlgFile.GetPathName(), CFile::modeRead); //opening file to read
			file.setFilePathName(dlgFile.GetPathName());
			file.setFileName(dlgFile.GetFileName());

			//getting file name
			this->SetWindowTextW(inf.GetFileName() + L" — Training English Words Memory 2 Master App");

			bool fg1 = false;
			bool fg2 = false;
			bool fg3 = false;

			//reading data from file
			CString buf, ms;
			while (inf.ReadString(buf))
			{
				//getting file settings
				//TODO: edit like in test files
				if (buf.Find(L"endingPhrase:") != -1)
				{
					file.setEndingPhrase(buf.Right(buf.GetLength() - 13));
					fg1 = true;
				}
				else if (buf.Find(L"leftTrainslationDirectionName:") != -1)
				{
					file.setLeftTrainslationDirectionName(buf.Right(buf.GetLength() - 30));
					fg2 = true;
				}
				else if (buf.Find(L"rightTrainslationDirectionName:") != -1)
				{
					file.setRightTrainslationDirectionName(buf.Right(buf.GetLength() - 31));
					fg3 = true;
				}
				else if (buf.Find(L"data:") != -1)continue;
				else
				{
					//getting data
					ms += buf;
					ms += "\r\n";
				}
			}
			inf.Close();
			if (!(fg1 && fg2 && fg3))
			{
				// TODO: improve reading process to check if all data is readed
				if(!fg1)AfxMessageBox(L"Error reading resource file. Not enough data. No ending phrase.");
				if (!fg2)AfxMessageBox(L"Error reading resource file. Not enough data. No leftTrainslationDirectionName.");
				if (!fg3)AfxMessageBox(L"Error reading resource file. Not enough data. No rightTrainslationDirectionName.");
			}


			ms.Replace('|', ' ');
			file.setData(ms);

			//outputing data on the dialog window
			UpdateData(true);
			MainField = ms;
			UpdateData(false);
		}
		catch (CFileException *pe)
		{
			CString error;
			error.Format(_T("File could not be opened, cause = %d\n"),
				pe->m_cause);
			AfxMessageBox(error);
			pe->Delete();
		}
	}
}

void CreateTrainingFileWindow::OnFileExit()
{
	// exits from file editing dialog
	
	CString lastDataVersion;
	UpdateData(true);
	lastDataVersion = MainField;
	UpdateData(false);

	//if user has unsaved data in MainField
	if (lastDataVersion != file.getData())
	{
		WarningWindow obj(file.getFileName());
		obj.DoModal();

		switch (obj.getUserAnswer())
		{
		case DoingType::Save:
			this->OnFileSave32777();
			CDialog::OnCancel();
			break;
		case DoingType::NotSave:
			CDialog::OnCancel();
			break;
		case DoingType::Cancel:
			return;
			break;
		}
	}
	else
	{
		CDialog::OnCancel();
	}
}

void CreateTrainingFileWindow::OnNewTrainingfile()
{
	// should create a new file, but in fact 
	// it simply removes traces of work on the previous file
	file.setAllDataToDefault();
	UpdateData(true);
	MainField = file.getData();
	UpdateData(false);
}


void CreateTrainingFileWindow::OnNewTestingfile()
{
	//should close this window and open create testing file window
	AfxMessageBox(L"Will be added in future versions.");
}


void CreateTrainingFileWindow::OnCancel()
{
	this->OnFileExit();
}
