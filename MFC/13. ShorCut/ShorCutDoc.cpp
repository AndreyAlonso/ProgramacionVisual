// ShorCutDoc.cpp : implementation of the CShorCutDoc class
//

#include "stdafx.h"
#include "ShorCut.h"

#include "ShorCutDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShorCutDoc

IMPLEMENT_DYNCREATE(CShorCutDoc, CDocument)

BEGIN_MESSAGE_MAP(CShorCutDoc, CDocument)
	//{{AFX_MSG_MAP(CShorCutDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShorCutDoc construction/destruction

CShorCutDoc::CShorCutDoc()
{
	// TODO: add one-time construction code here

}

CShorCutDoc::~CShorCutDoc()
{
}

BOOL CShorCutDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShorCutDoc serialization

void CShorCutDoc::Serialize(CArchive& ar)
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
// CShorCutDoc diagnostics

#ifdef _DEBUG
void CShorCutDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShorCutDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShorCutDoc commands
