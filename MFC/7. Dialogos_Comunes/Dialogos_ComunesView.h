// Dialogos_ComunesView.h : interface of the CDialogos_ComunesView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIALOGOS_COMUNESVIEW_H__D95DA83A_E66F_4828_8437_F475FE5C782D__INCLUDED_)
#define AFX_DIALOGOS_COMUNESVIEW_H__D95DA83A_E66F_4828_8437_F475FE5C782D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDialogos_ComunesView : public CView
{
protected: // create from serialization only
	CDialogos_ComunesView();
	DECLARE_DYNCREATE(CDialogos_ComunesView)

// Attributes
public:
	CDialogos_ComunesDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogos_ComunesView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	UINT m_ID;
	int opcion;
	CFontDialog dlgFont;
	CFont* cf;
	CFont fuente;
	CFontDialog font;
	CFileDialog *file;
	BOOL band;
	COLORREF color;
	CColorDialog dlgColor;
	virtual ~CDialogos_ComunesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDialogos_ComunesView)
	afx_msg void OnUpdatePrueba(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg void OnComunes( UINT nID );       ///NUEVO
//	afx_msg void OnUpdatePrueba(CCmdUI *pCmdUI );
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Dialogos_ComunesView.cpp
inline CDialogos_ComunesDoc* CDialogos_ComunesView::GetDocument()
   { return (CDialogos_ComunesDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGOS_COMUNESVIEW_H__D95DA83A_E66F_4828_8437_F475FE5C782D__INCLUDED_)
