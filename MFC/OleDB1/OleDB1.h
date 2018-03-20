// OleDB1.h : main header file for the OLEDB1 application
//

#if !defined(AFX_OLEDB1_H__BE908409_5D7A_4266_BDA0_D58ECA344F79__INCLUDED_)
#define AFX_OLEDB1_H__BE908409_5D7A_4266_BDA0_D58ECA344F79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COleDB1App:
// See OleDB1.cpp for the implementation of this class
//

class COleDB1App : public CWinApp
{
public:
	COleDB1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDB1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COleDB1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDB1_H__BE908409_5D7A_4266_BDA0_D58ECA344F79__INCLUDED_)
