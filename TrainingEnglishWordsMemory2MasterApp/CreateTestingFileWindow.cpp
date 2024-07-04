// CreateTestingFileWindow.cpp : implementation file
//

#include "pch.h"
#include "TrainingEnglishWordsMemory2MasterApp.h"
#include "CreateTestingFileWindow.h"
#include "afxdialogex.h"
#include "TestingFile.h"
#include "TimeWindow.h"
#include "WarningWindow.h"
#include <iostream>


// CreateTestingFileWindow dialog

IMPLEMENT_DYNAMIC(CreateTestingFileWindow, CDialog)

CreateTestingFileWindow::CreateTestingFileWindow(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CREATE_TESTING_FILE_DIALOG, pParent)
	, MainField(_T(""))
{

}

CreateTestingFileWindow::~CreateTestingFileWindow()
{
}

void CreateTestingFileWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MAIN_FIELD, MainField);
}


BEGIN_MESSAGE_MAP(CreateTestingFileWindow, CDialog)
	ON_COMMAND(ID_TRANSLATION_DIRECTION_DIRECT, &CreateTestingFileWindow::OnTranslationDirectionDirect)
	ON_COMMAND(ID_TRANSLATION_DIRECTION_REVERSE, &CreateTestingFileWindow::OnTranslationDirectionReverse)
	ON_COMMAND(ID_FILESETTINGS_TIME, &CreateTestingFileWindow::OnFilesettingsTime)
	ON_COMMAND(ID_WORDORDER_DIRECT, &CreateTestingFileWindow::OnWordorderDirect)
	ON_COMMAND(ID_WORDORDER_REVERSE, &CreateTestingFileWindow::OnWordorderReverse)
	ON_COMMAND(ID_WORDORDER_RANDOM, &CreateTestingFileWindow::OnWordorderRandom)
	ON_COMMAND(ID_FILESETTINGS_NAVIGATIONBUTTONS, &CreateTestingFileWindow::OnFilesettingsNavigationbuttons)
	ON_COMMAND(ID_NEW_TRAININGFILE, &CreateTestingFileWindow::OnNewTrainingfile)
	ON_COMMAND(ID_NEW_TESTINGFILE, &CreateTestingFileWindow::OnNewTestingfile)
	ON_COMMAND(ID_FILE_OPEN32775, &CreateTestingFileWindow::OnFileOpen32775)
	ON_COMMAND(ID_FILE_SAVE32777, &CreateTestingFileWindow::OnFileSave32777)
	ON_COMMAND(ID_FILE_EXIT, &CreateTestingFileWindow::OnFileExit)
END_MESSAGE_MAP()


BOOL CreateTestingFileWindow::OnInitDialog()
{
	CDialog::OnInitDialog();

	setlocale(LC_ALL, "rus");

	//set up default values
	CMenu* currMenu = GetMenu();
	if (currMenu != NULL)
	{
		file.setTranslationDirection(TranslationDirection::LeftRight);
		currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_DIRECT, MF_CHECKED);

		file.setTimeForTest(0, 0, 0);

		file.setWordOrder(WordOrder::Direct);
		currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_CHECKED);
		currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_UNCHECKED);
		currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_UNCHECKED);

		file.setNavigationButtons(NavigationButtons::ON);
		currMenu->CheckMenuItem(ID_FILESETTINGS_NAVIGATIONBUTTONS, MF_CHECKED);
	}
	else AfxMessageBox(L"Unable to set menu in oninitdialog.");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


// CreateTestingFileWindow message handlers


void CreateTestingFileWindow::OnTranslationDirectionDirect()
{
	// set translation direction to left and set this button as checked
	// set right direction button as unchecked

	file.setTranslationDirection(TranslationDirection::LeftRight);
	CMenu* currMenu = GetMenu();
	if (currMenu != NULL)
	{
		currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_DIRECT, MF_CHECKED);
		currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_REVERSE, MF_UNCHECKED);
	}
	else AfxMessageBox(L"Unable to set button <translation direction reverse>.");
}


void CreateTestingFileWindow::OnTranslationDirectionReverse()
{
	// set translation direction to right and set this button as checked
	// set left direction button as unchecked
	
	file.setTranslationDirection(TranslationDirection::RightLeft);
	CMenu* currMenu = GetMenu();
	if (currMenu != NULL)
	{
		currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_DIRECT, MF_UNCHECKED);
		currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_REVERSE, MF_CHECKED);
	}
	else AfxMessageBox(L"Unable to set button <translation direction reverse>.");
}


void CreateTestingFileWindow::OnFilesettingsTime()
{
	// load TimeWindow and gets time from it
	Time timeBuffer = file.getTimeForTest();
	TimeWindow newWindow(timeBuffer);
	newWindow.DoModal();
	file.setTimeForTest(timeBuffer.getHours(), timeBuffer.getMinutes(), timeBuffer.getSeconds());
}


void CreateTestingFileWindow::OnWordorderDirect()
{
	// set wordorder to direct
	// set this button as checked
	file.setWordOrder(WordOrder::Direct);
	CMenu* currMenu = GetMenu();
	if (currMenu != NULL)
	{
		currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_CHECKED);
		currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_UNCHECKED);
		currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_UNCHECKED);
	}
	else AfxMessageBox(L"Unable to set button <word order direct>.");
}


void CreateTestingFileWindow::OnWordorderReverse()
{
	// set wordorder to reverse
	// set this button as checked
	file.setWordOrder(WordOrder::Reverse);
	CMenu* currMenu = GetMenu();
	if (currMenu != NULL)
	{
		currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_UNCHECKED);
		currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_CHECKED);
		currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_UNCHECKED);
	}
	else AfxMessageBox(L"Unable to set button <word order reverse>.");
}


void CreateTestingFileWindow::OnWordorderRandom()
{
	// set wordorder to random
	// set this button as checked
	file.setWordOrder(WordOrder::Random);
	CMenu* currMenu = GetMenu();
	if (currMenu != NULL)
	{
		currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_UNCHECKED);
		currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_UNCHECKED);
		currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_CHECKED);
	}
	else AfxMessageBox(L"Unable to set button <word order random>.");
}


void CreateTestingFileWindow::OnFilesettingsNavigationbuttons()
{
	// swithces variable navButtons and button <Navigation buttons> to ON or OFF
	// and checked and unchecked

	if (file.getNavigationButtons() == NavigationButtons::ON)
	{
		file.setNavigationButtons(NavigationButtons::OFF);
		CMenu* currMenu = GetMenu();
		if (currMenu != NULL)currMenu->CheckMenuItem(ID_FILESETTINGS_NAVIGATIONBUTTONS, MF_UNCHECKED);
		else AfxMessageBox(L"Unable to set button <Navigation buttons> to unchecked.");
	}
	else
	{
		file.setNavigationButtons(NavigationButtons::ON);
		CMenu* currMenu = GetMenu();
		if (currMenu != NULL)currMenu->CheckMenuItem(ID_FILESETTINGS_NAVIGATIONBUTTONS, MF_CHECKED);
		else AfxMessageBox(L"Unable to set button <Navigation buttons> to checked.");
	}

}


void CreateTestingFileWindow::OnNewTrainingfile()
{
	//should close this window and open create training file window
	AfxMessageBox(L"Will be added in future versions.");
}


void CreateTestingFileWindow::OnNewTestingfile()
{
	// removes traces of work on the previous file

	file.setAllDataToDefault();

	//updating menu
	CMenu* currMenu = GetMenu();
	if (currMenu != NULL)
	{
		switch (file.getTranslationDirection())
		{
		case TranslationDirection::LeftRight:
			currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_DIRECT, MF_CHECKED);
			currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_REVERSE, MF_UNCHECKED);
			break;
		case TranslationDirection::RightLeft:
			currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_REVERSE, MF_CHECKED);
			currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_DIRECT, MF_UNCHECKED);
			break;
		default:
			AfxMessageBox(L"OnNewTestingfile error, no such TranslateDirection value.");
			break;
		}

		switch (file.getWordOrder())
		{
		case WordOrder::Direct:
			currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_CHECKED);
			currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_UNCHECKED);
			currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_UNCHECKED);
			break;
		case WordOrder::Reverse:
			currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_UNCHECKED);
			currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_CHECKED);
			currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_UNCHECKED);
			break;
		case WordOrder::Random:
			currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_UNCHECKED);
			currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_UNCHECKED);
			currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_CHECKED);
			break;
		default:
			AfxMessageBox(L"OnNewTestingfile error, no such WordOrder value.");
			break;
		}

		switch (file.getNavigationButtons())
		{
		case NavigationButtons::ON:
			currMenu->CheckMenuItem(ID_FILESETTINGS_NAVIGATIONBUTTONS, MF_CHECKED);
			break;
		case NavigationButtons::OFF:
			currMenu->CheckMenuItem(ID_FILESETTINGS_NAVIGATIONBUTTONS, MF_UNCHECKED);
			break;
		default:
			AfxMessageBox(L"OnNewTestingfile error, no such NavigationButtons value.");
			break;
		}
	}
	else AfxMessageBox(L"Unable to update menu in OnNewTestingfile.");

	UpdateData(true);
	MainField = file.getData();
	UpdateData(false);
}


void CreateTestingFileWindow::OnFileOpen32775()
{
	//file extentions that can be opened
	LPCTSTR pszFilter =
		_T("TEWMTEST (*.tewmtest)|*.tewmtest|"); //pointer to the string

	CFileDialog dlgFile(TRUE, _T("TEWMTEST"), NULL,
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
			bool fg4 = false;

			//reading data from file
			CString buf, ms;
			while (inf.ReadString(buf))
			{
				//getting file settings
				if (buf.Find(L"TranslationDirection:") != -1)
				{
					//check and set TranslationDirection
					CString str = buf.Right(buf.GetLength() - 21);
					switch (str.GetAt(0))
					{
					case 'L':
						file.setTranslationDirection(TranslationDirection::LeftRight);
						break;
					case 'R':
						file.setTranslationDirection(TranslationDirection::RightLeft);
						break;
					default:
						AfxMessageBox(L"get TranslationDirection, no such TranslateDirection value.");
						break;
					}
					fg1 = true;
				}
				else if (buf.Find(L"WordOrder:") != -1)
				{
					//check and set WordOrder
					CString str = buf.Right(buf.GetLength() - 10);
					switch (str.GetAt(str.GetLength()-1))
					{
					case 't':
						file.setWordOrder(WordOrder::Direct);
						break;
					case 'e':
						file.setWordOrder(WordOrder::Reverse);
						break;
					case 'm':
						file.setWordOrder(WordOrder::Random);
						break;
					default:
						AfxMessageBox(L"get WordOrder, no such WordOrder value.");
						break;
					}
					fg2 = true;
				}
				else if (buf.Find(L"NavigationButtons:") != -1)
				{
					//check and set NavigationButtons
					CString str = buf.Right(buf.GetLength() - 18);
					switch (str.GetAt(str.GetLength()-1))
					{
					case 'N':
						file.setNavigationButtons(NavigationButtons::ON);
						break;
					case 'F':
						file.setNavigationButtons(NavigationButtons::OFF);
						break;
					default:
						AfxMessageBox(L"get NavigationButtons, no such NavigationButtons value.");
						break;
					}
					fg3 = true;
				}
				else if (buf.Find(L"TimeForTest:") != -1)
				{
					//check and set TimeForTest
					CString str = buf.Right(buf.GetLength() - 12);
					CString strHours, strMinutes, strSeconds;

					//getting string equivalent of time 
					for (int i = 0; i < str.GetLength(); i++)
					{
						if (str[i] == 'H')
							for (int k = i + 1; isalpha(str[k]) == 0 && k < str.GetLength(); k++, i++)
								strHours += str[k];
						if (str[i] == 'M')
							for (int k = i + 1; isalpha(str[k]) == 0 && k < str.GetLength(); k++, i++)
								strMinutes += str[k];
						if (str[i] == 'S')
							for (int k = i + 1; isalpha(str[k]) == 0 && k < str.GetLength(); k++, i++)
								strSeconds += str[k];
					}

					//converting cstring nums 
					unsigned int hours = _ttoi(strHours);
					unsigned int minutes = _ttoi(strMinutes);
					unsigned int seconds = _ttoi(strSeconds);

					file.setTimeForTest(hours, minutes, seconds);
					fg4 = true;
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
			if (!(fg1 && fg2 && fg3 && fg4))
			{
				//check if all data is read
				//if any data 
				if (!fg1)AfxMessageBox(L"Error reading resource file. Not enough data. No TranslationDirection.");
				if (!fg2)AfxMessageBox(L"Error reading resource file. Not enough data. No WordOrder.");
				if (!fg3)AfxMessageBox(L"Error reading resource file. Not enough data. No NavigationButtons.");
				if (!fg3)AfxMessageBox(L"Error reading resource file. Not enough data. No TimeForTest.");
			}

			ms.Replace('|', ' ');
			file.setData(ms);

			//outputing data on the dialog window
			UpdateData(true);
			MainField = ms;
			UpdateData(false);

			//updating menu
			CMenu* currMenu = GetMenu();
			switch (file.getTranslationDirection())
			{
			case TranslationDirection::LeftRight:
				currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_DIRECT, MF_CHECKED);
				currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_REVERSE, MF_UNCHECKED);
				break;
			case TranslationDirection::RightLeft:
				currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_REVERSE, MF_CHECKED);
				currMenu->CheckMenuItem(ID_TRANSLATION_DIRECTION_DIRECT, MF_UNCHECKED);
				break;
			default:
				AfxMessageBox(L"OnFileOpen32775 error, no such TranslateDirection value.");
				break;
			}

			switch (file.getWordOrder())
			{
			case WordOrder::Direct:
				currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_CHECKED);
				currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_UNCHECKED);
				currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_UNCHECKED);
				break;
			case WordOrder::Reverse:
				currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_UNCHECKED);
				currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_CHECKED);
				currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_UNCHECKED);
				break;
			case WordOrder::Random:
				currMenu->CheckMenuItem(ID_WORDORDER_DIRECT, MF_UNCHECKED);
				currMenu->CheckMenuItem(ID_WORDORDER_REVERSE, MF_UNCHECKED);
				currMenu->CheckMenuItem(ID_WORDORDER_RANDOM, MF_CHECKED);
				break;
			default:
				AfxMessageBox(L"OnFileOpen32775 error, no such WordOrder value.");
				break;
			}

			switch (file.getNavigationButtons())
			{
			case NavigationButtons::ON:
				currMenu->CheckMenuItem(ID_FILESETTINGS_NAVIGATIONBUTTONS, MF_CHECKED);
				break;
			case NavigationButtons::OFF:
				currMenu->CheckMenuItem(ID_FILESETTINGS_NAVIGATIONBUTTONS, MF_UNCHECKED);
				break;
			default:
				AfxMessageBox(L"OnFileOpen32775 error, no such NavigationButtons value.");
				break;
			}
		}
		catch (CFileException* pe)
		{
			CString error;
			error.Format(_T("File could not be opened, cause = %d\n"),
				pe->m_cause);
			AfxMessageBox(error);
			pe->Delete();
		}
	}
}


void CreateTestingFileWindow::OnFileSave32777()
{
	//saving function
	// TODO: add accelerator to launch this function by pressing Ctrl+s

	if ((file.getFilePathName()).IsEmpty())
	{
		//saving data in new file that created using windows explorer
		LPCTSTR pszFilter =
			_T("TEWMTEST (*.tewmtest)|*.tewmtest|"); //pointer to the string

		CFileDialog dlgFile(FALSE, _T("TEWMTEST"), _T("unnamed.tewmtest"),
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
				if (dlgFile.GetFileExt() == _T("tewmtest"))
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

		CStdioFile otf(L"temp.tewmtest", CFile::modeCreate | CFile::modeWrite);
		otf.WriteString(file.getDataToSave());
		otf.Flush();
		otf.Close();
		remove(charFilePathName);
		if (rename("temp.tewmtest", charFilePathName))AfxMessageBox(L"File could not be saved, problem with rename function.");
	}
}


void CreateTestingFileWindow::OnFileExit()
{
	//checks only data field in file

	//exits from file editing dialog
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


void CreateTestingFileWindow::OnCancel()
{
	this->OnFileExit();
}
