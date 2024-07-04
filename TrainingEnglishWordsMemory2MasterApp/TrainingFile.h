#pragma once
class TrainingFile
{
public:
	void setEndingPhrase(CString& value);
	void setLeftTrainslationDirectionName(CString& value);
	void setRightTrainslationDirectionName(CString& value);
	void setData(CString& value);
	void setFilePathName(CString& value);
	void setFileName(CString& value);
	void setAllDataToDefault();
	CString getEndingPhrase();
	CString getLeftTrainslationDirectionName();
	CString getRightTrainslationDirectionName();
	CString getData();
	CString getDataToSave();
	CString getFilePathName();
	CString getFileName();
private:
	CString endingPhrase = L"undefined";
	CString data = L""; //word pairs to train translation
	CString leftTrainslationDirectionName = L"Direct";
	CString rightTrainslationDirectionName = L"Reverse";
	CString filePath = L""; //path of the last saved file
	CString fileName = L""; //name of the last saved file
};

