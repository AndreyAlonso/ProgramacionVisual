// ConjuntosDoc.cpp : implementation of the CConjuntosDoc class
//

#include "stdafx.h"
#include "Conjuntos.h"

#include "ConjuntosDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc

IMPLEMENT_DYNCREATE(CConjuntosDoc, CDocument)

BEGIN_MESSAGE_MAP(CConjuntosDoc, CDocument)
	//{{AFX_MSG_MAP(CConjuntosDoc)
	ON_COMMAND(IDM_CREAR, OnCrear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc construction/destruction

CConjuntosDoc::CConjuntosDoc()
{
	// TODO: add one-time construction code here
	

}

CConjuntosDoc::~CConjuntosDoc()
{
}

BOOL CConjuntosDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc serialization

void CConjuntosDoc::Serialize(CArchive& ar)
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
// CConjuntosDoc diagnostics

#ifdef _DEBUG
void CConjuntosDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CConjuntosDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CConjuntosDoc commands

void CConjuntosDoc::OnCrear() 
{
	// TODO: Add your command handler code here
//	set.creaLista(5);
	
	
}
