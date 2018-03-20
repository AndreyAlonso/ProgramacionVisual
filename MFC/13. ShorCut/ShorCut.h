// ShorCut.h : main header file for the SHORCUT application
//

#if !defined(AFX_SHORCUT_H__673874F7_A186_4275_A029_6A0669A2F6A8__INCLUDED_)
#define AFX_SHORCUT_H__673874F7_A186_4275_A029_6A0669A2F6A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShorCutApp:
// See ShorCut.cpp for the implementation of this class
//

class CShorCutApp : public CWinApp
{
public:
	CShorCutApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShorCutApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShorCutApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORCUT_H__673874F7_A186_4275_A029_6A0669A2F6A8__INCLUDED_)
