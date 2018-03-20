#if !defined(AFX_CAJACOMPLEMENTO_H__47BB31B4_2302_45A2_8B06_4BFB30C221FC__INCLUDED_)
#define AFX_CAJACOMPLEMENTO_H__47BB31B4_2302_45A2_8B06_4BFB30C221FC__INCLUDED_

#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CajaComplemento.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCajaComplemento dialog

class CCajaComplemento : public CDialog
{
// Construction
public:
	CSet setComple;
	CNodoP* np;
	CString cad;
	CSet setDlg;
	POSITION pos;
	CCajaComplemento(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCajaComplemento)
	enum { IDD = IDD_COMPLEMENTO };
	CComboBox	m_Combo;
	CComboBox	m_Combo2;
	CString	m_Combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCajaComplemento)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCajaComplemento)
	virtual BOOL OnInitDialog();
	afx_msg void OnComplemento();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAJACOMPLEMENTO_H__47BB31B4_2302_45A2_8B06_4BFB30C221FC__INCLUDED_)
