// Desplazamiento_Vertical1.h : main header file for the DESPLAZAMIENTO_VERTICAL1 application
//

#if !defined(AFX_DESPLAZAMIENTO_VERTICAL1_H__30375B49_66AA_4FA2_838A_E5F94731D333__INCLUDED_)
#define AFX_DESPLAZAMIENTO_VERTICAL1_H__30375B49_66AA_4FA2_838A_E5F94731D333__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1App:
// See Desplazamiento_Vertical1.cpp for the implementation of this class
//

class CDesplazamiento_Vertical1App : public CWinApp
{
public:
	CDesplazamiento_Vertical1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesplazamiento_Vertical1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDesplazamiento_Vertical1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPLAZAMIENTO_VERTICAL1_H__30375B49_66AA_4FA2_838A_E5F94731D333__INCLUDED_)
