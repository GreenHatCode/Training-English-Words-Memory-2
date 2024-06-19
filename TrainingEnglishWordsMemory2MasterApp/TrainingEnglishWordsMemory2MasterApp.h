
// TrainingEnglishWordsMemory2MasterApp.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTrainingEnglishWordsMemory2MasterAppApp:
// See TrainingEnglishWordsMemory2MasterApp.cpp for the implementation of this class
//

class CTrainingEnglishWordsMemory2MasterAppApp : public CWinApp
{
public:
	CTrainingEnglishWordsMemory2MasterAppApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTrainingEnglishWordsMemory2MasterAppApp theApp;
