// convertShellCode.h : main header file for the CONVERTSHELLCODE application
//

#if !defined(AFX_CONVERTSHELLCODE_H__624CD30C_7967_42CF_B713_D81C1F8CBDA5__INCLUDED_)
#define AFX_CONVERTSHELLCODE_H__624CD30C_7967_42CF_B713_D81C1F8CBDA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CConvertShellCodeApp:
// See convertShellCode.cpp for the implementation of this class
//

class CConvertShellCodeApp : public CWinApp
{
public:
	CConvertShellCodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertShellCodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CConvertShellCodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTSHELLCODE_H__624CD30C_7967_42CF_B713_D81C1F8CBDA5__INCLUDED_)
