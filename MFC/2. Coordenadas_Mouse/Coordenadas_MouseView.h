/****************************************************************************************************
 * Nombre:			Héctor Andrey Hernández Alonso
 * Fecha:			02 de Octubre del 2017
 * Proyecto:		Coordenadas_Mouse
 * Funcionalidad:	Muestra las coordenadas al dar click izquierdo.
 * Metodos:				
 * Handles:
 * Mensajes:
 * Tipos:		
 * Estructuras: 
 ***************************************************************************************************/

// Coordenadas_MouseView.h : interface of the CCoordenadas_MouseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDENADAS_MOUSEVIEW_H__881C3639_E725_4094_82EC_4567B8DEDA1F__INCLUDED_)
#define AFX_COORDENADAS_MOUSEVIEW_H__881C3639_E725_4094_82EC_4567B8DEDA1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCoordenadas_MouseView : public CView
{
protected: // create from serialization only
	CCoordenadas_MouseView();
	DECLARE_DYNCREATE(CCoordenadas_MouseView)

// Attributes
public:
	CCoordenadas_MouseDoc* GetDocument();
	BOOL band;
	int x,y;
	char cad1[50], cad2[50];

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordenadas_MouseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void OnPaint();
	virtual ~CCoordenadas_MouseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCoordenadas_MouseView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Coordenadas_MouseView.cpp
inline CCoordenadas_MouseDoc* CCoordenadas_MouseView::GetDocument()
   { return (CCoordenadas_MouseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDENADAS_MOUSEVIEW_H__881C3639_E725_4094_82EC_4567B8DEDA1F__INCLUDED_)
