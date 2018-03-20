// ConjuntosDoc.h : interface of the CConjuntosDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONJUNTOSDOC_H__D8D43ECB_1D14_41FD_94F9_B0CCC9D2D709__INCLUDED_)
#define AFX_CONJUNTOSDOC_H__D8D43ECB_1D14_41FD_94F9_B0CCC9D2D709__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NodoP.h"
#include "Set.h"	// Added by ClassView


class CConjuntosDoc : public CDocument
{
protected: // create from serialization only
	CConjuntosDoc();
	DECLARE_DYNCREATE(CConjuntosDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConjuntosDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CSet setDlg;
	CSet set;
	CNodoP* np;
	virtual ~CConjuntosDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CConjuntosDoc)
	afx_msg void OnCrear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONJUNTOSDOC_H__D8D43ECB_1D14_41FD_94F9_B0CCC9D2D709__INCLUDED_)
