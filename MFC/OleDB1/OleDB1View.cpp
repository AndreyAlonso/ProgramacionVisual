// OleDB1View.cpp : implementation of the COleDB1View class
//

#include "stdafx.h"
#include "OleDB1.h"

#include "OleDB1Set.h"
#include "OleDB1Doc.h"
#include "OleDB1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleDB1View

IMPLEMENT_DYNCREATE(COleDB1View, COleDBRecordView)

BEGIN_MESSAGE_MAP(COleDB1View, COleDBRecordView)
	//{{AFX_MSG_MAP(COleDB1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COleDB1View construction/destruction

COleDB1View::COleDB1View()
	: COleDBRecordView(COleDB1View::IDD)
{
	//{{AFX_DATA_INIT(COleDB1View)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COleDB1View::~COleDB1View()
{
}

void COleDB1View::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COleDB1View)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL COleDB1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return COleDBRecordView::PreCreateWindow(cs);
}

void COleDB1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_oleDB1Set;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->Open();
		if (hr != S_OK)
		{
			AfxMessageBox(_T("Record set failed to open."), MB_OK);
			// Disable the Next and Previous record commands,
			// since attempting to change the current record without an
			// open RecordSet will cause a crash.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}				
	}
	COleDBRecordView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// COleDB1View diagnostics

#ifdef _DEBUG
void COleDB1View::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void COleDB1View::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

COleDB1Doc* COleDB1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COleDB1Doc)));
	return (COleDB1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COleDB1View database support
CRowset* COleDB1View::OnGetRowset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// COleDB1View message handlers
