// BD2.h : main header file for the BD2 application
//

#if !defined(AFX_BD2_H__858008BA_A03C_4818_A568_A5D433BB51E5__INCLUDED_)
#define AFX_BD2_H__858008BA_A03C_4818_A568_A5D433BB51E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBD2App:
// See BD2.cpp for the implementation of this class
//

class CBD2App : public CWinApp
{
public:
	CBD2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBD2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBD2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BD2_H__858008BA_A03C_4818_A568_A5D433BB51E5__INCLUDED_)
