// OleDBView.cpp : implementation of the COleDBView class
//

#include "stdafx.h"
#include "OleDB.h"

#include "OleDBSet.h"
#include "OleDBDoc.h"
#include "OleDBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleDBView

IMPLEMENT_DYNCREATE(COleDBView, CRecordView)

BEGIN_MESSAGE_MAP(COleDBView, CRecordView)
	//{{AFX_MSG_MAP(COleDBView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COleDBView construction/destruction

COleDBView::COleDBView()
	: CRecordView(COleDBView::IDD)
{
	//{{AFX_DATA_INIT(COleDBView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COleDBView::~COleDBView()
{
}

void COleDBView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COleDBView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL COleDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void COleDBView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_oleDBSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// COleDBView diagnostics

#ifdef _DEBUG
void COleDBView::AssertValid() const
{
	CRecordView::AssertValid();
}

void COleDBView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

COleDBDoc* COleDBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COleDBDoc)));
	return (COleDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COleDBView database support
CRecordset* COleDBView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// COleDBView message handlers
