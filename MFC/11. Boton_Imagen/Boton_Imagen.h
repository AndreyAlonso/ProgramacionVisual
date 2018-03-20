// Boton_Imagen.h : main header file for the BOTON_IMAGEN application
//

#if !defined(AFX_BOTON_IMAGEN_H__E7395099_A16B_4ADE_AA65_EE78F822DE68__INCLUDED_)
#define AFX_BOTON_IMAGEN_H__E7395099_A16B_4ADE_AA65_EE78F822DE68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBoton_ImagenApp:
// See Boton_Imagen.cpp for the implementation of this class
//

class CBoton_ImagenApp : public CWinApp
{
public:
	CBoton_ImagenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBoton_ImagenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBoton_ImagenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOTON_IMAGEN_H__E7395099_A16B_4ADE_AA65_EE78F822DE68__INCLUDED_)
