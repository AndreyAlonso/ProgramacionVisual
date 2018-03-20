// Desplazamiento_Vertical1Doc.cpp : implementation of the CDesplazamiento_Vertical1Doc class
//

#include "stdafx.h"
#include "Desplazamiento_Vertical1.h"

#include "Desplazamiento_Vertical1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1Doc

IMPLEMENT_DYNCREATE(CDesplazamiento_Vertical1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDesplazamiento_Vertical1Doc, CDocument)
	//{{AFX_MSG_MAP(CDesplazamiento_Vertical1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1Doc construction/destruction

CDesplazamiento_Vertical1Doc::CDesplazamiento_Vertical1Doc()
{
	// TODO: add one-time construction code here

}

CDesplazamiento_Vertical1Doc::~CDesplazamiento_Vertical1Doc()
{
}

BOOL CDesplazamiento_Vertical1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1Doc serialization

void CDesplazamiento_Vertical1Doc::Serialize(CArchive& ar)
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
// CDesplazamiento_Vertical1Doc diagnostics

#ifdef _DEBUG
void CDesplazamiento_Vertical1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDesplazamiento_Vertical1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDesplazamiento_Vertical1Doc commands
