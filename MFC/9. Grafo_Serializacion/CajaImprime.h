#if !defined(AFX_CAJAIMPRIME_H__3E02701F_DB78_4187_B288_10D098E98DD5__INCLUDED_)
#define AFX_CAJAIMPRIME_H__3E02701F_DB78_4187_B288_10D098E98DD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CajaImprime.h : header file
//
#include "NodoP.h"
#include "NodoR.h"

/////////////////////////////////////////////////////////////////////////////
// CCajaImprime dialog

class CCajaImprime : public CDialog
{
// Construction
public:
	int j;
	int calculaRelacion();
	int i;
	POSITION posP;
	POSITION posR;
	int maxNR;
	int maxNP;
	CObList gDlg;
	CCajaImprime(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCajaImprime)
	enum { IDD = IDD_IMPRIMIR };
	CListCtrl	m_Grafo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCajaImprime)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCajaImprime)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAJAIMPRIME_H__3E02701F_DB78_4187_B288_10D098E98DD5__INCLUDED_)
