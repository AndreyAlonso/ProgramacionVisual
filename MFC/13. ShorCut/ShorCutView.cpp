// ShorCutView.cpp : implementation of the CShorCutView class
//

#include "stdafx.h"
#include "ShorCut.h"

#include "ShorCutDoc.h"
#include "ShorCutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShorCutView

IMPLEMENT_DYNCREATE(CShorCutView, CView)

BEGIN_MESSAGE_MAP(CShorCutView, CView)
	//{{AFX_MSG_MAP(CShorCutView)
	ON_COMMAND(IDM_PINTA, OnPinta)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_CONTEXTMENU()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShorCutView construction/destruction

CShorCutView::CShorCutView()
{
	// TODO: add construction code here
	band = FALSE;
	bandFinal = FALSE;
	

}

CShorCutView::~CShorCutView()
{
	penNew->DeleteObject();
}

BOOL CShorCutView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShorCutView drawing

void CShorCutView::OnDraw(CDC* pDC)
{
	CShorCutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->SetROP2(R2_NOTXORPEN);	

	penNew = new CPen();
	penNew->CreatePen(PS_SOLID,5,RGB(100,100,100));
	penOld = pDC->SelectObject(penNew);
	if(band)
	{
		pDC->MoveTo(pt1);
		pDC->LineTo(pt2);
		Sleep(20);
		pDC->MoveTo(pt1);
		pDC->LineTo(pt2);
		pDC->SelectObject(penOld);
		penNew->DeleteObject();
	}
	else{
		if(bandFinal){
			pDC->MoveTo(pt1);
			pDC->LineTo(pt2);
			pDC->SelectObject(penOld);
			penNew->DeleteObject();
		}
	}
	penNew->DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CShorCutView diagnostics

#ifdef _DEBUG
void CShorCutView::AssertValid() const
{
	CView::AssertValid();
}

void CShorCutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShorCutDoc* CShorCutView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShorCutDoc)));
	return (CShorCutDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShorCutView message handlers

void CShorCutView::OnPinta() 
{
	// TODO: Add your command handler code here
	band = TRUE;
	Invalidate(FALSE);
	
}

void CShorCutView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//	posx1 = point.x;
//	posx2 = point.y;
//	band = TRUE;
//	Invalidate(TRUE);
	pt1 = point;

//	cursor = SetCursor(IDC_CROSS);
	
	CView::OnLButtonDown(nFlags, point);
}

void CShorCutView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(nFlags){
		
		::AfxGetApp()->LoadCursor(IDC_CROSS);
		pt2 = point;
		band = TRUE;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}

void CShorCutView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMenu *menu;
	menu = new CMenu();
	menu->LoadMenu(IDR_MENU1);
	menu->GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTBUTTON || TPM_LEFTBUTTON, point.x, point.y, this);
//	menu->TrackPopupMenu(TPM_RIGHTBUTTON || TPM_LEFTBUTTON, point.x, point.y, this);
	menu->DestroyMenu();

	
}

void CShorCutView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	band = FALSE;
	bandFinal = TRUE;
	Invalidate(FALSE);

	
	CView::OnLButtonUp(nFlags, point);
}
