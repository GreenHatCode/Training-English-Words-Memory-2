#include "pch.h"
#include "TestingFile.h"
#include "TranslationDirection.h"
#include "Time.h"
#include "WordOrder.h"
#include "NavigationButtons.h"

void TestingFile::setTranslationDirection(TranslationDirection value)
{
	trDir= value;
}

void TestingFile::setTimeForTest(unsigned int h, unsigned int m, unsigned int s)
{
	timeForTest.setHours(h);
	timeForTest.setMinutes(m);
	timeForTest.setSeconds(s);
}

void TestingFile::setWordOrder(WordOrder value)
{
	wordOrder = value;
}

void TestingFile::setNavigationButtons(NavigationButtons value)
{
	navButtons = value;
}

void TestingFile::setData(CString& value)
{
	data = value;
}

void TestingFile::setFilePathName(CString& value)
{
	filePath = value;
}

void TestingFile::setFileName(CString& value)
{
	fileName = value;
}

void TestingFile::setAllDataToDefault()
{
	trDir = TranslationDirection::LeftRight;
	setTimeForTest(0, 0, 0);
	wordOrder = WordOrder::Direct;
	navButtons = NavigationButtons::ON;
	data = L"";
	filePath = L"";
	fileName = L"";
}

TranslationDirection TestingFile::getTranslationDirection()
{
	return trDir;
}

Time TestingFile::getTimeForTest()
{
	return timeForTest;
}

WordOrder TestingFile::getWordOrder()
{
	return wordOrder;
}

NavigationButtons TestingFile::getNavigationButtons()
{
	return navButtons;
}

CString TestingFile::getData()
{
	return data;
}

CString TestingFile::getDataToSave()
{
	CString dataToSave = L"";

	dataToSave += L"TranslationDirection:";
	switch (trDir)
	{
	case TranslationDirection::LeftRight:
		dataToSave += "L"; //LeftRight
		break;
	case TranslationDirection::RightLeft:
		dataToSave += "R"; //RightLeft
		break;
	default:
		AfxMessageBox(L"getDataToSave error, no such TranslateDirection value.");
		return L"Error";
		break;
	}
	dataToSave += "\n";
	

	dataToSave += L"WordOrder:";
	switch (wordOrder)
	{
	case WordOrder::Direct:
		dataToSave += "t"; //Direct
		break;
	case WordOrder::Reverse:
		dataToSave += "e"; //Reverse
		break;
	case WordOrder::Random:
		dataToSave += "m"; //Random
		break;
	default:
		AfxMessageBox(L"getDataToSave error, no such WordOrder value.");
		return L"Error";
		break;
	}
	dataToSave += "\n";


	dataToSave += L"NavigationButtons:";
	switch (navButtons)
	{
	case NavigationButtons::ON:
		dataToSave += "N"; //ON
		break;
	case NavigationButtons::OFF:
		dataToSave += "F"; //OFF
		break;
	default:
		AfxMessageBox(L"getDataToSave error, no such NavigationButtons value.");
		return L"Error";
		break;
	}
	dataToSave += "\n";
	

	dataToSave += L"TimeForTest:";
	CString t;
	t.Format(L"H%iM%iS%i", timeForTest.getHours(), timeForTest.getMinutes(), timeForTest.getSeconds());
	dataToSave += t;
	dataToSave += "\n";

	dataToSave += L"data:\n";
	//placing separating symbol and deleting \r characters
	CString modifiedData; //stores data with | and without \r char
	CString englishAlphabet = L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < data.GetLength(); i++)
	{
		if (data[i] == char(32) && i < data.GetLength() - 1)
		{
			if (englishAlphabet.Find(data[i - 1]) >= 0 && englishAlphabet.Find(data[i + 1]) == -1)
			{
				//if value[i] separates english and another language word
				modifiedData += "|"; //replace this space on separating symbol
			}
			else if (englishAlphabet.Find(data[i + 1]) >= 0 && englishAlphabet.Find(data[i - 1]) == -1)
			{
				modifiedData += "|";
			}
			else modifiedData += data[i];
		}
		else modifiedData += data[i];
	}
	modifiedData.Remove('\r');
	
	dataToSave += modifiedData;
	return dataToSave;
}

CString TestingFile::getFilePathName()
{
	return filePath;
}

CString TestingFile::getFileName()
{
	return fileName;
}
