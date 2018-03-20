// Dialogos_ComunesView.cpp : implementation of the CDialogos_ComunesView class
//

#include "stdafx.h"
#include "Dialogos_Comunes.h"

#include "Dialogos_ComunesDoc.h"
#include "Dialogos_ComunesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//int x = 300;
int tam = 0;
int color = 0;

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView

IMPLEMENT_DYNCREATE(CDialogos_ComunesView, CView)

BEGIN_MESSAGE_MAP(CDialogos_ComunesView, CView)
	//{{AFX_MSG_MAP(CDialogos_ComunesView)
	ON_UPDATE_COMMAND_UI(IDM_PRUEBA, OnUpdatePrueba)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDM_FILE, IDM_COLOR, OnComunes)   //// M O D I F I C A R
	ON_COMMAND_RANGE(IDM_FILE, IDM_COLOR, OnUpdatePrueba)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView construction/destruction
static char BASED_CODE szFilter[] = "Archivos (*.cpp)|*.cpp|Archivos de Cabecera (*.h)|*.h|Archivos cpp y de Cabecera (*.cpp;*.h)|*.cpp;*.h; *.xls|Todos los Archivos (*.*)|*.*||";



CDialogos_ComunesView::CDialogos_ComunesView()
{

	file = new CFileDialog(FALSE,NULL, NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter, this);
	//font = CFontDialog(NULL,  CF_EFFECTS | CF_SCREENFONTS, NULL,NULL );
	
	band = FALSE;

}

CDialogos_ComunesView::~CDialogos_ComunesView()
{
}

BOOL CDialogos_ComunesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView drawing

void CDialogos_ComunesView::OnDraw(CDC* pDC)
{
	CDialogos_ComunesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//font.DoModal();
//	tam = font.GetSize();
//	color = font.GetColor();

	if(band)
	{
		switch(opcion)
		{
			case 0:
				pDC->FillSolidRect(100,100,100,100,color);
			break;
			case 1:
				//FileDialog
			break;
			case 2:
				pDC->SelectObject(cf);
				pDC->SetTextColor(color);
				pDC->TextOut(200,100, "Liberen a Willy");
			break;

		}
			
	}
	else
	{
		pDC->Rectangle(100,100,200,200);
	}
	

}

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView diagnostics

#ifdef _DEBUG
void CDialogos_ComunesView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogos_ComunesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogos_ComunesDoc* CDialogos_ComunesView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogos_ComunesDoc)));
	return (CDialogos_ComunesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogos_ComunesView message handlers


void CDialogos_ComunesView::OnComunes( UINT nID )
{
    int nButton = nID - IDM_FILE;
    ASSERT( nButton >= 0 && nButton < 3 );

	char* pszFileName = "Colores.txt";
	CFile myFile;
	CFileException fileException;
	int cont;
	int max;
	max = 0;
	cont = 0;
	LOGFONT lf;
    
	switch(nButton)
	{
		case 0: // Color

			//Leer---------------------------------------------------------------------------------------
			if ( !myFile.Open( pszFileName, CFile::modeRead ), &fileException ){
				TRACE( "No soy un inutil %s, error = %u\n", pszFileName, fileException.m_cause );
			}
			for(cont= 0; cont <= 16; cont++){
				myFile.Read( &dlgColor.m_cc.lpCustColors[cont], sizeof(dlgColor.m_cc.lpCustColors) );
			}
			if(dlgColor.DoModal() == IDOK){
				color = dlgColor.GetColor();
				band = TRUE;
				Invalidate();
			}
			myFile.Close();
		break;
		case 1: // File
			file->DoModal();
		break;
		case 2: // Font
			cf = new CFont();
		
			if(dlgFont.DoModal() == IDOK)
			{
				dlgFont.GetCurrentFont(&lf);
				cf->CreateFontIndirect(&lf);	// Acceder fuentes
				color = dlgFont.GetColor();
			}
			Invalidate();
			band = TRUE;
		break;
	}
	opcion = nButton;
	m_ID = nID;

	/*
		if(dlgColor.DoModal() == IDOK)
	{	

		//Guardar-------------------------------------------------------------------------------------
//		if ( !myFile.Open( pszFileName, CFile::modeCreate| CFile::modeReadWrite ), &fileException ){
//			TRACE( "No soy un inutil %s, error = %u\n", pszFileName, fileException.m_cause );
//		}
//		for(max = 0; max < 16; max++)
//		myFile.Write( &dlgColor.m_cc.lpCustColors[max], sizeof(dlgColor.m_cc.lpCustColors) );
	
	

}

	*/

}



void CDialogos_ComunesView::OnUpdatePrueba(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(pCmdUI->m_nID == m_ID);
	
}
