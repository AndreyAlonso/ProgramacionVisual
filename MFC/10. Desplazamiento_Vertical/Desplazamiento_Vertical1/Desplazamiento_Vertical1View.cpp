// Desplazamiento_Vertical1View.cpp : implementation of the CDesplazamiento_Vertical1View class
//

#include "stdafx.h"
#include "Desplazamiento_Vertical1.h"

#include "Desplazamiento_Vertical1Doc.h"
#include "Desplazamiento_Vertical1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1View

IMPLEMENT_DYNCREATE(CDesplazamiento_Vertical1View, CScrollView)

BEGIN_MESSAGE_MAP(CDesplazamiento_Vertical1View, CScrollView)
	//{{AFX_MSG_MAP(CDesplazamiento_Vertical1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1View construction/destruction

CDesplazamiento_Vertical1View::CDesplazamiento_Vertical1View()
{
	// TODO: add construction code here

}

CDesplazamiento_Vertical1View::~CDesplazamiento_Vertical1View()
{
}

BOOL CDesplazamiento_Vertical1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1View drawing

void CDesplazamiento_Vertical1View::OnDraw(CDC* pDC)
{
	CDesplazamiento_Vertical1Doc* pDoc = GetDocument();
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

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1View diagnostics

#ifdef _DEBUG
void CDesplazamiento_Vertical1View::AssertValid() const
{
	CView::AssertValid();
}

void CDesplazamiento_Vertical1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDesplazamiento_Vertical1Doc* CDesplazamiento_Vertical1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDesplazamiento_Vertical1Doc)));
	return (CDesplazamiento_Vertical1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1View message handlers

void CDesplazamiento_Vertical1View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx  = 100;
	sizeTotal.cy  = 1000 * 20; 
	SetScrollSizes(MM_TEXT, sizeTotal);
	
}
