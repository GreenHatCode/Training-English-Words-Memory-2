#pragma once
#include "TranslationDirection.h"
#include "WordOrder.h"
#include "NavigationButtons.h"
#include "Time.h"
class TestingFile
{
public:
	void setTranslationDirection(TranslationDirection value);
	void setTimeForTest(unsigned int h = 0, unsigned int m = 0, unsigned int s = 0);
	void setWordOrder(WordOrder value);
	void setNavigationButtons(NavigationButtons value);
	void setData(CString& value);
	void setFilePathName(CString& value);
	void setFileName(CString& value);
	void setAllDataToDefault();
	TranslationDirection getTranslationDirection();
	Time getTimeForTest();
	WordOrder getWordOrder();
	NavigationButtons getNavigationButtons();
	CString getData();
	CString getDataToSave();
	CString getFilePathName();
	CString getFileName();
private:
	TranslationDirection trDir = TranslationDirection::None;
	WordOrder wordOrder = WordOrder::None;
	NavigationButtons navButtons = NavigationButtons::ON;
	Time timeForTest;
	CString data = L""; //word pairs to test translation
	CString filePath = L""; //path of the last saved file
	CString fileName = L""; //name of the last saved file
};

