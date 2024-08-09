#include "pch.h"
#include "TrainingFile.h"

void TrainingFile::setEndingPhrase(CString& value)
{
	endingPhrase = value;
}

void TrainingFile::setLeftTrainslationDirectionName(CString& value)
{
	leftTrainslationDirectionName = value;
}

void TrainingFile::setRightTrainslationDirectionName(CString& value)
{
	rightTrainslationDirectionName = value;
}

void TrainingFile::setData(CString& value)
{
	data = value;
}

void TrainingFile::setFilePathName(CString& value)
{
	filePath = value;
}

void TrainingFile::setFileName(CString& value)
{
	fileName = value;
}

void TrainingFile::setAllDataToDefault()
{
	endingPhrase = L"undefined";
	data.Empty();
	leftTrainslationDirectionName = L"Direct";
	rightTrainslationDirectionName = L"Reverse";
	filePath.Empty();
}

CString TrainingFile::getEndingPhrase()
{
	return endingPhrase;
}

CString TrainingFile::getLeftTrainslationDirectionName()
{
	return leftTrainslationDirectionName;
}

CString TrainingFile::getRightTrainslationDirectionName()
{
	return rightTrainslationDirectionName;
}

CString TrainingFile::getData()
{
	return data;
}

CString TrainingFile::getDataToSave()
{
	CString dataToSave = L"";

	dataToSave += L"endingPhrase:";
	dataToSave += endingPhrase;
	dataToSave += "\n";
	dataToSave += L"leftTrainslationDirectionName:";
	dataToSave += leftTrainslationDirectionName;
	dataToSave += "\n";
	dataToSave += L"rightTrainslationDirectionName:";
	dataToSave += rightTrainslationDirectionName;
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

CString TrainingFile::getFilePathName()
{
	return filePath;
}

CString TrainingFile::getFileName()
{
	return fileName;
}
