// OleDBDoc.cpp : implementation of the COleDBDoc class
//

#include "stdafx.h"
#include "OleDB.h"

#include "OleDBSet.h"
#include "OleDBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleDBDoc

IMPLEMENT_DYNCREATE(COleDBDoc, CDocument)

BEGIN_MESSAGE_MAP(COleDBDoc, CDocument)
	//{{AFX_MSG_MAP(COleDBDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COleDBDoc construction/destruction

COleDBDoc::COleDBDoc()
{
	// TODO: add one-time construction code here

}

COleDBDoc::~COleDBDoc()
{
}

BOOL COleDBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COleDBDoc serialization

void COleDBDoc::Serialize(CArchive& ar)
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
// COleDBDoc diagnostics

#ifdef _DEBUG
void COleDBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COleDBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COleDBDoc commands
