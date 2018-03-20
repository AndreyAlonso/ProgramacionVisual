// Desplazamiento_Vertical.h : main header file for the DESPLAZAMIENTO_VERTICAL application
//

#if !defined(AFX_DESPLAZAMIENTO_VERTICAL_H__36CD8618_4D5C_4922_8E68_8897CAFF063F__INCLUDED_)
#define AFX_DESPLAZAMIENTO_VERTICAL_H__36CD8618_4D5C_4922_8E68_8897CAFF063F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalApp:
// See Desplazamiento_Vertical.cpp for the implementation of this class
//

class CDesplazamiento_VerticalApp : public CWinApp
{
public:
	CDesplazamiento_VerticalApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesplazamiento_VerticalApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDesplazamiento_VerticalApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPLAZAMIENTO_VERTICAL_H__36CD8618_4D5C_4922_8E68_8897CAFF063F__INCLUDED_)
