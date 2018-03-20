// OleDB1Doc.cpp : implementation of the COleDB1Doc class
//

#include "stdafx.h"
#include "OleDB1.h"

#include "OleDB1Set.h"
#include "OleDB1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleDB1Doc

IMPLEMENT_DYNCREATE(COleDB1Doc, CDocument)

BEGIN_MESSAGE_MAP(COleDB1Doc, CDocument)
	//{{AFX_MSG_MAP(COleDB1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COleDB1Doc construction/destruction

COleDB1Doc::COleDB1Doc()
{
	// TODO: add one-time construction code here

}

COleDB1Doc::~COleDB1Doc()
{
}

BOOL COleDB1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COleDB1Doc serialization

void COleDB1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COleDB1Doc diagnostics

#ifdef _DEBUG
void COleDB1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void COleDB1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COleDB1Doc commands
