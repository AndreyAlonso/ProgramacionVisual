// ConjuntosView.h : interface of the CConjuntosView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONJUNTOSVIEW_H__706D4A15_2837_45E0_84B4_34BC7B7D1288__INCLUDED_)
#define AFX_CONJUNTOSVIEW_H__706D4A15_2837_45E0_84B4_34BC7B7D1288__INCLUDED_

#include "CajaComplemento.h"	// Added by ClassView
#include "Set.h"	// Added by ClassView
#include "NodoP.h"	// Added by ClassView
#include "CajaUnion.h"	// Added by ClassView
#include "CajaInter.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CConjuntosView : public CView
{
protected: // create from serialization only
	CConjuntosView();
	DECLARE_DYNCREATE(CConjuntosView)

// Attributes
public:
	CConjuntosDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConjuntosView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void imprimeConjunto(CDC *pDC);
	int opcion;
	CCajaInter dlgInterseccion;
	BOOL band;
	CCajaUnion dlgUnion;
	CCajaComplemento dlgComplemento;
	CSet set;

	virtual ~CConjuntosView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CConjuntosView)
	afx_msg void OnAsignacion();
	afx_msg void OnUnion();
	afx_msg void OnCrear();
	afx_msg void OnInter();
	afx_msg void OnComplemento();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ConjuntosView.cpp
inline CConjuntosDoc* CConjuntosView::GetDocument()
   { return (CConjuntosDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONJUNTOSVIEW_H__706D4A15_2837_45E0_84B4_34BC7B7D1288__INCLUDED_)
