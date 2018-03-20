// Coordenadas_MouseView.cpp : implementation of the CCoordenadas_MouseView class
//

#include "stdafx.h"
#include "Coordenadas_Mouse.h"

#include "Coordenadas_MouseDoc.h"
#include "Coordenadas_MouseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView

IMPLEMENT_DYNCREATE(CCoordenadas_MouseView, CView)

BEGIN_MESSAGE_MAP(CCoordenadas_MouseView, CView)
	//{{AFX_MSG_MAP(CCoordenadas_MouseView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView construction/destruction

CCoordenadas_MouseView::CCoordenadas_MouseView()
{
	// TODO: add construction code here

}

CCoordenadas_MouseView::~CCoordenadas_MouseView()
{
}

BOOL CCoordenadas_MouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView drawing

void CCoordenadas_MouseView::OnDraw(CDC* pDC)
{
	CCoordenadas_MouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
Invalidate();
	CPaintDC dc(this);
	if(band){
	
		dc.TextOut(x,y, cad1);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView diagnostics

#ifdef _DEBUG
void CCoordenadas_MouseView::AssertValid() const
{
	CView::AssertValid();
}

void CCoordenadas_MouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCoordenadas_MouseDoc* CCoordenadas_MouseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCoordenadas_MouseDoc)));
	return (CCoordenadas_MouseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseView message handlers

void CCoordenadas_MouseView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CClientDC pDC(this);
	x = point.x;
	y = point.y;
	strcpy(cad1, "x = ");
	itoa(x,cad2,10);
	strcat(cad1,cad2);
	strcat(cad1, ", y = " );
	itoa(y, cad2,10);
	strcat(cad1,cad2);

	Invalidate(); // Parametros por default
	band = TRUE;
	
	CView::OnLButtonDown(nFlags, point);
}



