#if !defined(AFX_EJEMPLO_H__82B0B690_AA7F_4C53_B05A_13DFF2D98BE7__INCLUDED_)
#define AFX_EJEMPLO_H__82B0B690_AA7F_4C53_B05A_13DFF2D98BE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ejemplo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEjemplo dialog

class CEjemplo : public CDialog
{
// Construction
public:
	CEjemplo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEjemplo)
	enum { IDD = _UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEjemplo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEjemplo)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EJEMPLO_H__82B0B690_AA7F_4C53_B05A_13DFF2D98BE7__INCLUDED_)
