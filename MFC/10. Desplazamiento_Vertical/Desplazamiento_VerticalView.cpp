// Desplazamiento_VerticalView.cpp : implementation of the CDesplazamiento_VerticalView class
//

#include "stdafx.h"
#include "Desplazamiento_Vertical.h"

#include "Desplazamiento_VerticalDoc.h"
#include "Desplazamiento_VerticalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalView

IMPLEMENT_DYNCREATE(CDesplazamiento_VerticalView, CScrollView)

BEGIN_MESSAGE_MAP(CDesplazamiento_VerticalView, CScrollView)
	//{{AFX_MSG_MAP(CDesplazamiento_VerticalView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalView construction/destruction

CDesplazamiento_VerticalView::CDesplazamiento_VerticalView()
{
	// TODO: add construction code here

}

CDesplazamiento_VerticalView::~CDesplazamiento_VerticalView()
{
}

BOOL CDesplazamiento_VerticalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalView drawing

void CDesplazamiento_VerticalView::OnDraw(CDC* pDC)
{
	CDesplazamiento_VerticalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	int i,y=0;
	CString cad;
	for(i = 0; i < MAXREN; i++){
		cad.Format("%d", i);
		pDC->TextOut(100,y,cad);
		y+=20;
	}


}

void CDesplazamiento_VerticalView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx  = 1;
	sizeTotal.cy  = 1000*20; 
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalView diagnostics

#ifdef _DEBUG
void CDesplazamiento_VerticalView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDesplazamiento_VerticalView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDesplazamiento_VerticalDoc* CDesplazamiento_VerticalView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDesplazamiento_VerticalDoc)));
	return (CDesplazamiento_VerticalDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalView message handlers
