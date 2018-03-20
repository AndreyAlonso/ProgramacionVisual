#if !defined(AFX_CAJAUNION_H__6FC20C10_9770_4201_9F37_8A41241936F6__INCLUDED_)
#define AFX_CAJAUNION_H__6FC20C10_9770_4201_9F37_8A41241936F6__INCLUDED_

#include "Set.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CajaUnion.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCajaUnion dialog

class CCajaUnion : public CDialog
{
// Construction
public:
	CSet setDlgC;
	BOOL band;
	CSet setDlgB;
	CSet setDlgA;
	CCajaUnion(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCajaUnion)
	enum { IDD = IDD_UNION };
	CComboBox	m_Combo3;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCajaUnion)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCajaUnion)
	virtual BOOL OnInitDialog();	
	afx_msg void OnUnion();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAJAUNION_H__6FC20C10_9770_4201_9F37_8A41241936F6__INCLUDED_)
