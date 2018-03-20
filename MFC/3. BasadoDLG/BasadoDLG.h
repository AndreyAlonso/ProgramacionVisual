// BasadoDLG.h : main header file for the BASADODLG application
//

#if !defined(AFX_BASADODLG_H__901FCE4A_D933_4AAE_B94C_8CAAFF61CD96__INCLUDED_)
#define AFX_BASADODLG_H__901FCE4A_D933_4AAE_B94C_8CAAFF61CD96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBasadoDLGApp:
// See BasadoDLG.cpp for the implementation of this class
//

class CBasadoDLGApp : public CWinApp
{
public:
	CBasadoDLGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasadoDLGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBasadoDLGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASADODLG_H__901FCE4A_D933_4AAE_B94C_8CAAFF61CD96__INCLUDED_)
