// BD1View.cpp : implementation of the CBD1View class
//

#include "stdafx.h"
#include "BD1.h"

#include "BD1Doc.h"
#include "BD1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBD1View

IMPLEMENT_DYNCREATE(CBD1View, CScrollView)

BEGIN_MESSAGE_MAP(CBD1View, CScrollView)
	//{{AFX_MSG_MAP(CBD1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBD1View construction/destruction

CBD1View::CBD1View()
{
	// TODO: add construction code here

}

CBD1View::~CBD1View()
{
}

BOOL CBD1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBD1View drawing

void CBD1View::OnDraw(CDC* pDC)
{
	CBD1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int alto = tm.tmHeight + tm.tmExternalLeading;
	CPoint p(0,0);
	CString str;
	if(mesa->IsBOF())
		return;
	mesa->MoveFirst();
	while(!mesa->IsBOF())
	{
		str.Format("%d", mesa->m_Id);
		pDC->TextOut(p.x, p.y,str);
		pDC->TextOut(p.x + 1000, p.y,mesa->m_Nombre);
		str.Format("%s", mesa->m_clave);
		pDC->TextOut(p.x + 3000, p.y,str);
		mesa->MoveNext();
		p.y -= alto;
	}


}

void CBD1View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal(8000, 10500);
	// TODO: calculate the total size of this view
//	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_HIENGLISH,sizeTotal);
	mesa = &GetDocument()->mesa;
	if(mesa->IsOpen())
		mesa->Close();
	mesa->m_strFilter = "[Tabla].[clave] = [Tabla1].[clave]";
	mesa->Open();
}

/////////////////////////////////////////////////////////////////////////////
// CBD1View diagnostics

#ifdef _DEBUG
void CBD1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBD1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBD1Doc* CBD1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBD1Doc)));
	return (CBD1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBD1View message handlers
