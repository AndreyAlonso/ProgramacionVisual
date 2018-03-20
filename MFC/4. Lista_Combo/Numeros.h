#if !defined(AFX_NUMEROS_H__63D81367_9755_446F_BE55_C649326DEC65__INCLUDED_)
#define AFX_NUMEROS_H__63D81367_9755_446F_BE55_C649326DEC65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Numeros.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumeros dialog

class CNumeros : public CDialog
{
// Construction
public:
	CObList lista_Combo;
	CString combo;
	CNumeros(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNumeros)
	enum { IDD = IDD_LISTA };
	CComboBox	m_Combo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumeros)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNumeros)
	afx_msg void OnAccion();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMEROS_H__63D81367_9755_446F_BE55_C649326DEC65__INCLUDED_)
