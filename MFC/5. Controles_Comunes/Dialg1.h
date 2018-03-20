#if !defined(AFX_DIALG1_H__C727CA09_BB41_4DAB_BA41_E883DEF7EB6F__INCLUDED_)
#define AFX_DIALG1_H__C727CA09_BB41_4DAB_BA41_E883DEF7EB6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialg1 dialog

class CDialg1 : public CDialog
{
// Construction
public:
	CDialg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialg1)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialg1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALG1_H__C727CA09_BB41_4DAB_BA41_E883DEF7EB6F__INCLUDED_)
