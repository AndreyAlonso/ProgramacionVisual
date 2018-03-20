// Desplazamiento_VerticalView.h : interface of the CDesplazamiento_VerticalView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESPLAZAMIENTO_VERTICALVIEW_H__4682D786_416C_43CA_86E6_A85B5F58C9CC__INCLUDED_)
#define AFX_DESPLAZAMIENTO_VERTICALVIEW_H__4682D786_416C_43CA_86E6_A85B5F58C9CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MAXREN 1000


class CDesplazamiento_VerticalView : public CScrollView
{
protected: // create from serialization only
	CDesplazamiento_VerticalView();
	DECLARE_DYNCREATE(CDesplazamiento_VerticalView)

// Attributes
public:
	CDesplazamiento_VerticalDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesplazamiento_VerticalView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDesplazamiento_VerticalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDesplazamiento_VerticalView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Desplazamiento_VerticalView.cpp
inline CDesplazamiento_VerticalDoc* CDesplazamiento_VerticalView::GetDocument()
   { return (CDesplazamiento_VerticalDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPLAZAMIENTO_VERTICALVIEW_H__4682D786_416C_43CA_86E6_A85B5F58C9CC__INCLUDED_)
