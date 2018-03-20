// GrafoOptimoAleatorioView.h : interface of the CGrafoOptimoAleatorioView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAFOOPTIMOALEATORIOVIEW_H__32B3C6E1_E000_4190_AD1E_CB955BC7781A__INCLUDED_)
#define AFX_GRAFOOPTIMOALEATORIOVIEW_H__32B3C6E1_E000_4190_AD1E_CB955BC7781A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NodoP.h" 
#include "NodoR.h"  
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "CajaImprime.h"	// Added by ClassView
class CGrafoOptimoAleatorioView : public CView
{
protected: // create from serialization only
	CGrafoOptimoAleatorioView();
	DECLARE_DYNCREATE(CGrafoOptimoAleatorioView)

// Attributes
public:
	CGrafoOptimoAleatorioDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrafoOptimoAleatorioView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	CCajaImprime dlgCaja;
	void ImprimirGrafo(CDC *pDC);
	void CreaGrafo(int n);
	BOOL band2;
	int opcion;
	void Inserta(CNodoP *np);
	CNodoR* nr;
	void Inserta(CNodoP *np, CNodoR *nr);
	int quieres;
	char name;
	int numeros;
	int num;
	CNodoP* np;
	BOOL band;
	CObList g; // grafo 
	virtual ~CGrafoOptimoAleatorioView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGrafoOptimoAleatorioView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	afx_msg void OnOptimo( UINT nID );

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GrafoOptimoAleatorioView.cpp
inline CGrafoOptimoAleatorioDoc* CGrafoOptimoAleatorioView::GetDocument()
   { return (CGrafoOptimoAleatorioDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAFOOPTIMOALEATORIOVIEW_H__32B3C6E1_E000_4190_AD1E_CB955BC7781A__INCLUDED_)
