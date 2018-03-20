// ShorCutView.h : interface of the CShorCutView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHORCUTVIEW_H__0E83D096_75AE_4AF4_9351_99CFFEF20480__INCLUDED_)
#define AFX_SHORCUTVIEW_H__0E83D096_75AE_4AF4_9351_99CFFEF20480__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShorCutView : public CView
{
protected: // create from serialization only
	CShorCutView();
	DECLARE_DYNCREATE(CShorCutView)

// Attributes
public:
	CShorCutDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShorCutView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	HCURSOR cursor;
	BOOL bandFinal;
	CPoint pt2;
	CPoint pt1;
	CPen* penNew;
	CPen* penOld;
	BOOL band;
	int posx2;
	int posx1;
//	CBRUSH* pluma1;
//	CBRUSH* pluma2;

	LPCRECT rect1, rect2;
	HDC hdc;


	virtual ~CShorCutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShorCutView)
	afx_msg void OnPinta();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShorCutView.cpp
inline CShorCutDoc* CShorCutView::GetDocument()
   { return (CShorCutDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORCUTVIEW_H__0E83D096_75AE_4AF4_9351_99CFFEF20480__INCLUDED_)
