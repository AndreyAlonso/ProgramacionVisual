#if !defined(AFX_CAJAINTER_H__5C9C40E7_C07F_4343_83FB_F13E48B93FFD__INCLUDED_)
#define AFX_CAJAINTER_H__5C9C40E7_C07F_4343_83FB_F13E48B93FFD__INCLUDED_

#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CajaInter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCajaInter dialog

class CCajaInter : public CDialog
{
// Construction
public:
	CSet setC;
	BOOL band;
	CSet setB;
	CSet setA;
	POSITION pos;
	CSet setInter;
	CSet setDlg;
	CCajaInter(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCajaInter)
	enum { IDD = IDD_INTER };
	CComboBox	m_ConjuntoC;
	CComboBox	m_ConjuntoB;
	CComboBox	m_ConjuntoA;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCajaInter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCajaInter)
	afx_msg void OnInter();
	virtual BOOL OnInitDialog();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAJAINTER_H__5C9C40E7_C07F_4343_83FB_F13E48B93FFD__INCLUDED_)
