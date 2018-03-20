// ConjuntosView.cpp : implementation of the CConjuntosView class
//

#include "stdafx.h"
#include "Conjuntos.h"

#include "ConjuntosDoc.h"
#include "ConjuntosView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView

IMPLEMENT_DYNCREATE(CConjuntosView, CView)

BEGIN_MESSAGE_MAP(CConjuntosView, CView)
	//{{AFX_MSG_MAP(CConjuntosView)
	ON_COMMAND(IDM_ASIGNACION, OnAsignacion)
	ON_COMMAND(IDM_UNION, OnUnion)
	ON_COMMAND(IDM_CREAR, OnCrear)
	ON_COMMAND(IDM_INTERSECCION, OnInter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView construction/destruction

CConjuntosView::CConjuntosView()
{
	// TODO: add construction code here
	band = FALSE;
	opcion = 0;
	

}

CConjuntosView::~CConjuntosView()
{
}

BOOL CConjuntosView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView drawing

void CConjuntosView::OnDraw(CDC* pDC)
{
	CConjuntosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	POSITION pos, posA, posB;
	CNodoP *np, *npB;
	CString cad, cadB;
	int x, y;
	x = y = 100;
	if(band){
		switch(opcion)
		{
			case 1: // Complemento
				pos = dlgComplemento.setDlg.GetHeadPosition();
				while(pos)
				{	
					np = (CNodoP*)dlgComplemento.setDlg.GetNext(pos);
					cad.Format("%d", np->numero);
					pDC->TextOut(x,y,cad);
					x+=15;


				}				
			break;
			case 2: // Union 
				x = 100;
				posA = dlgUnion.setDlgA.GetHeadPosition();
				while(posA)
				{
					np = (CNodoP*)dlgUnion.setDlgA.GetNext(posA);
					cad.Format("%d", np->numero);
					pDC->TextOut(x,y,cad);
					x+=15;
				}
				x = 100;
				y += 20;
				posB = dlgUnion.setDlgB.GetHeadPosition();
				while(posB)
				{
					npB = (CNodoP*)dlgUnion.setDlgB.GetNext(posB);
					cadB.Format("%d", npB->numero);
					pDC->TextOut(x,y,cadB);
					x+=15;
				}
			break;
			case 3: // Intersección
				x = 100;
				posA = dlgInterseccion.setA.GetHeadPosition();
				while(posA)
				{
					np = (CNodoP*)dlgInterseccion.setA.GetNext(posA);
					cad.Format("%d", np->numero);
					pDC->TextOut(x,y,cad);
					x+=15;
				}
				x = 100;
				y += 20;
				posB = dlgInterseccion.setB.GetHeadPosition();
				while(posB)
				{
					npB = (CNodoP*)dlgInterseccion.setB.GetNext(posB);
					cadB.Format("%d", npB->numero);
					pDC->TextOut(x,y,cadB);
					x+=15;
				}
			break;
		}
	}

}

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView diagnostics

#ifdef _DEBUG
void CConjuntosView::AssertValid() const
{
	CView::AssertValid();
}

void CConjuntosView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CConjuntosDoc* CConjuntosView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CConjuntosDoc)));
	return (CConjuntosDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CConjuntosView message handlers

void CConjuntosView::OnAsignacion() 
{
	// TODO: Add your command handler code here
	CConjuntosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(band){	
		dlgComplemento.setDlg.creaLista(5);
		Invalidate();
		opcion = 1;
 		dlgComplemento.DoModal();
 	}
 	
 }
 
 void CConjuntosView::OnComplemento() 
 {
 	CConjuntosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	dlgComplemento.setDlg = pDoc->set;
	//setDlg = !setDlg;
	//dlgComplemento.setDlg;
	//dlgComplemento.setComple =  OnInitDialog();		
}

void CConjuntosView::OnUnion() 
{
	if(band)
	{
		dlgUnion.setDlgA.creaLista(5);
		dlgUnion.setDlgB.creaLista(5);
		dlgUnion.band = TRUE;
		Invalidate();
		opcion = 2;
		dlgUnion.DoModal();
	}	
}

void CConjuntosView::OnCrear() 
{
	band = TRUE;
	Invalidate();
	
}


void CConjuntosView::OnInter() 
{
	if(band)
	{
		dlgInterseccion.setA.creaLista(10);
		dlgInterseccion.setB.creaLista(10);
		dlgInterseccion.band = TRUE;
		Invalidate();
		opcion = 3;
		dlgInterseccion.DoModal();
	}
}

void CConjuntosView::imprimeConjunto(CDC *pDC)
{

}
