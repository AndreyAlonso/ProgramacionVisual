// Coordenadas_MouseDoc.cpp : implementation of the CCoordenadas_MouseDoc class
//

#include "stdafx.h"
#include "Coordenadas_Mouse.h"

#include "Coordenadas_MouseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseDoc

IMPLEMENT_DYNCREATE(CCoordenadas_MouseDoc, CDocument)

BEGIN_MESSAGE_MAP(CCoordenadas_MouseDoc, CDocument)
	//{{AFX_MSG_MAP(CCoordenadas_MouseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseDoc construction/destruction

CCoordenadas_MouseDoc::CCoordenadas_MouseDoc()
{
	// TODO: add one-time construction code here

}

CCoordenadas_MouseDoc::~CCoordenadas_MouseDoc()
{
}

BOOL CCoordenadas_MouseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseDoc serialization

void CCoordenadas_MouseDoc::Serialize(CArchive& ar)
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
// CCoordenadas_MouseDoc diagnostics

#ifdef _DEBUG
void CCoordenadas_MouseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCoordenadas_MouseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCoordenadas_MouseDoc commands
