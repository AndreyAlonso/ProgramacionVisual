// Controles_ComunesView.h : interface of the CControles_ComunesView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLES_COMUNESVIEW_H__8764B131_5BA4_4747_8E2F_4DFB97A1F9A9__INCLUDED_)
#define AFX_CONTROLES_COMUNESVIEW_H__8764B131_5BA4_4747_8E2F_4DFB97A1F9A9__INCLUDED_

#include "Progress.h"	// Added by ClassView
#include "Dialg1.h"	// Added by ClassView
#include "Slider.h"	// Added by ClassView
#include "Spin.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CControles_ComunesView : public CView
{
protected: // create from serialization only
	CControles_ComunesView();
	DECLARE_DYNCREATE(CControles_ComunesView)

// Attributes
public:
	CControles_ComunesDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControles_ComunesView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	CSpin dlgSpin;
	CSlider dlgSlider;

	CProgress dlgProgress;
	virtual ~CControles_ComunesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CControles_ComunesView)
	afx_msg void OnProgress();
	afx_msg void OnSlider();
	afx_msg void OnSpin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Controles_ComunesView.cpp
inline CControles_ComunesDoc* CControles_ComunesView::GetDocument()
   { return (CControles_ComunesDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLES_COMUNESVIEW_H__8764B131_5BA4_4747_8E2F_4DFB97A1F9A9__INCLUDED_)
