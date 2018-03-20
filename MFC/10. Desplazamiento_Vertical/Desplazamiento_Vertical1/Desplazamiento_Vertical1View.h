// Desplazamiento_Vertical1View.h : interface of the CDesplazamiento_Vertical1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESPLAZAMIENTO_VERTICAL1VIEW_H__D13807C8_3239_48A3_8641_A1A6D1DA950F__INCLUDED_)
#define AFX_DESPLAZAMIENTO_VERTICAL1VIEW_H__D13807C8_3239_48A3_8641_A1A6D1DA950F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MAXREN 1000


class CDesplazamiento_Vertical1View : public CScrollView
{
protected: // create from serialization only
	CDesplazamiento_Vertical1View();
	DECLARE_DYNCREATE(CDesplazamiento_Vertical1View)

// Attributes
public:
	CDesplazamiento_Vertical1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesplazamiento_Vertical1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDesplazamiento_Vertical1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDesplazamiento_Vertical1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Desplazamiento_Vertical1View.cpp
inline CDesplazamiento_Vertical1Doc* CDesplazamiento_Vertical1View::GetDocument()
   { return (CDesplazamiento_Vertical1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPLAZAMIENTO_VERTICAL1VIEW_H__D13807C8_3239_48A3_8641_A1A6D1DA950F__INCLUDED_)
