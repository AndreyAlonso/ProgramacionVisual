// Controles_ActiveXView.cpp : implementation of the CControles_ActiveXView class
//

#include "stdafx.h"
#include "Controles_ActiveX.h"

#include "Controles_ActiveXDoc.h"
#include "Controles_ActiveXView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView

IMPLEMENT_DYNCREATE(CControles_ActiveXView, CView)

BEGIN_MESSAGE_MAP(CControles_ActiveXView, CView)
	//{{AFX_MSG_MAP(CControles_ActiveXView)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDM_VIDEO, IDM_TREE, OnControles)
//	ON_UPDATE_COMMAND__UI_RANGE(IDM_VIDEO, IDM_TREE, OnControlesUpdateX)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView construction/destruction

CControles_ActiveXView::CControles_ActiveXView()
{
	// TODO: add construction code here

}

CControles_ActiveXView::~CControles_ActiveXView()
{
}

BOOL CControles_ActiveXView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	band = FALSE;

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView drawing

void CControles_ActiveXView::OnDraw(CDC* pDC)
{
	CControles_ActiveXDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CString cad,cad2,cad3,final;

	// TODO: add draw code for native data here

	if(band){
		switch(opcion){

			case 1:
				switch(dlgCal.mes){
					case 1:
						cad = "Enero";
					break;
					case 2:
						cad = "Febrero";
					break;
					case 3:
						cad = "Marzo";
					break;
					case 4:
						cad = "Abril";
					break;
					case 5:
						cad = "Mayo";
					break;
					case 6:
						cad = "Junio";
					break;
					case 7:
						cad = "Julio";
					break;
					case 8:
						cad = "Agosto";
					break;
					case 9:
						cad = "Septiembre";
					break;
					case 10:
						cad = "Octubre";
					break;
					case 11:
						cad = "Noviembre";
					break;
					case 12:
						cad = "Diciembre";
					break;
				}
				cad2.Format("%d", dlgCal.dia);
				cad3.Format("%d", dlgCal.year);	
				final = cad2 + " de " +  cad + " del " + cad3; 
				pDC->TextOut(200,100,final);
			break;
		}
		
	}
	
	
}

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView diagnostics

#ifdef _DEBUG
void CControles_ActiveXView::AssertValid() const
{
	CView::AssertValid();
}

void CControles_ActiveXView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CControles_ActiveXDoc* CControles_ActiveXView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControles_ActiveXDoc)));
	return (CControles_ActiveXDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControles_ActiveXView message handlers

void CControles_ActiveXView::OnControles(UINT nID)
{
	int nButton = nID - IDM_VIDEO;
    ASSERT( nButton >= 0 && nButton < 3 );

	switch(nButton)
	{
		case 0:
			dlgVideo.DoModal();
			Invalidate();
			band = TRUE;
		break;
		case 1:
			dlgCal.DoModal();
			Invalidate();
			band = TRUE;
		break;
		case 2:
			dlgTree.DoModal();
			Invalidate();
			band = TRUE;
		break;

	}
	opcion = nButton;


}


//DEL void CControles_ActiveXView::OnUpdatePrueba(CCmdUI* pCmdUI) 
//DEL {
//DEL 	// TODO: Add your command update UI handler code here
//DEL 	
//DEL }

//void CControles_ActiveXView::OnUpdatePrueba(CCmdUI* pCmdUI)
//{
//	pCmdUI->Enable(FALSE);
//}