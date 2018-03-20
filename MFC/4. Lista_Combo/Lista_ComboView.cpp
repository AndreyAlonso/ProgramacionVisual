// Lista_ComboView.cpp : implementation of the CLista_ComboView class
//

#include "stdafx.h"
#include "Lista_Combo.h"

#include "Lista_ComboDoc.h"
#include "Lista_ComboView.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView

IMPLEMENT_DYNCREATE(CLista_ComboView, CView)

BEGIN_MESSAGE_MAP(CLista_ComboView, CView)
	//{{AFX_MSG_MAP(CLista_ComboView)
	ON_COMMAND(IDM_CREAR, OnCrear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView construction/destruction

CLista_ComboView::CLista_ComboView()
{
	// TODO: add construction code here
	band = FALSE;

}

CLista_ComboView::~CLista_ComboView()
{
	lista.RemoveAll();
}

BOOL CLista_ComboView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView drawing

void CLista_ComboView::OnDraw(CDC* pDC)
{
	CLista_ComboDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	POSITION pos;
	CString cad;
	int x = 100;


	if(band){
		pos = lista.GetHeadPosition();
		while(pos){
			nodo = (CNodo*)lista.GetNext(pos);
			cad.Format("%d",nodo->numero);
			pDC->TextOut(x+=20,100,cad);
		}
		
		
	}

}

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView diagnostics

#ifdef _DEBUG
void CLista_ComboView::AssertValid() const
{
	CView::AssertValid();
}

void CLista_ComboView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLista_ComboDoc* CLista_ComboView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLista_ComboDoc)));
	return (CLista_ComboDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLista_ComboView message handlers

void CLista_ComboView::OnCrear() 
{
	int num, numeros;
	int aux = 0;
	POSITION borra; 
	POSITION borra2;
	
	numeros = rand()%5 + 10;
	srand((unsigned)time(NULL));
	// Inserta Lista -------------------------------------------
	while(numeros--)
	{
		num = rand()%100;	
		nodo = new CNodo(num);
		if(nodo->numero != aux && nodo->numero > aux && nodo->numero < 99)
		{
		//	if(nodo->numero == aux)
				nodo->numero+=1;
			lista.AddHead(nodo);
				aux = num;
		
		
		}
	
	}
	dlgNumeros.lista_Combo.AddHead(&lista);
	

	// Elimina Lista -----------------------------------------------------------
	borra = dlgNumeros.lista_Combo.GetTailPosition();
	borra2 = lista.GetTailPosition();

	if(dlgNumeros.DoModal() == IDOK){
		while(borra && borra2){
			lista.RemoveTail();
			dlgNumeros.lista_Combo.RemoveTail();

			borra =  lista.GetTailPosition();
			borra2 = lista.GetTailPosition();
		}
		band = TRUE;
		
		Invalidate();

	}




}


