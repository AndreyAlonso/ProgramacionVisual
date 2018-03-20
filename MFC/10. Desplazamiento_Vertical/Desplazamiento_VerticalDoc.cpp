// Desplazamiento_VerticalDoc.cpp : implementation of the CDesplazamiento_VerticalDoc class
//

#include "stdafx.h"
#include "Desplazamiento_Vertical.h"

#include "Desplazamiento_VerticalDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalDoc

IMPLEMENT_DYNCREATE(CDesplazamiento_VerticalDoc, CDocument)

BEGIN_MESSAGE_MAP(CDesplazamiento_VerticalDoc, CDocument)
	//{{AFX_MSG_MAP(CDesplazamiento_VerticalDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalDoc construction/destruction

CDesplazamiento_VerticalDoc::CDesplazamiento_VerticalDoc()
{
	// TODO: add one-time construction code here

}

CDesplazamiento_VerticalDoc::~CDesplazamiento_VerticalDoc()
{
}

BOOL CDesplazamiento_VerticalDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalDoc serialization

void CDesplazamiento_VerticalDoc::Serialize(CArchive& ar)
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
// CDesplazamiento_VerticalDoc diagnostics

#ifdef _DEBUG
void CDesplazamiento_VerticalDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDesplazamiento_VerticalDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_VerticalDoc commands
