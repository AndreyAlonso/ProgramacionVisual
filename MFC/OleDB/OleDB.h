// OleDB.h : main header file for the OLEDB application
//

#if !defined(AFX_OLEDB_H__55396BA0_F616_4DB8_8EAA_1ADA340B5608__INCLUDED_)
#define AFX_OLEDB_H__55396BA0_F616_4DB8_8EAA_1ADA340B5608__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COleDBApp:
// See OleDB.cpp for the implementation of this class
//

class COleDBApp : public CWinApp
{
public:
	COleDBApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDBApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COleDBApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDB_H__55396BA0_F616_4DB8_8EAA_1ADA340B5608__INCLUDED_)
