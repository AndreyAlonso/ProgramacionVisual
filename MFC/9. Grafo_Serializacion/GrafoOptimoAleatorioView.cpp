// GrafoOptimoAleatorioView.cpp : implementation of the CGrafoOptimoAleatorioView class
//

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"

#include "GrafoOptimoAleatorioDoc.h"
#include "GrafoOptimoAleatorioView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView

IMPLEMENT_DYNCREATE(CGrafoOptimoAleatorioView, CView)

BEGIN_MESSAGE_MAP(CGrafoOptimoAleatorioView, CView)
	//{{AFX_MSG_MAP(CGrafoOptimoAleatorioView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE( IDM_CREAR, IDM_LIST,OnOptimo )


END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView construction/destruction

CGrafoOptimoAleatorioView::CGrafoOptimoAleatorioView()
{
	// TODO: add construction code here
	opcion = 0;
	band = FALSE;

	name = 'A';
	srand((unsigned)time(NULL));
	

}

CGrafoOptimoAleatorioView::~CGrafoOptimoAleatorioView()
{
}

BOOL CGrafoOptimoAleatorioView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView drawing

void CGrafoOptimoAleatorioView::OnDraw(CDC* pDC)
{
	CGrafoOptimoAleatorioDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);


	// TODO: add draw code for native data here
		if(band){
		switch(opcion){
			case 0:
			pDoc->numeros = rand()%3+5;
			pDoc->creaGrafo(numeros);	
			break;
			case 1:
				ImprimirGrafo(pDC);
			break;
		}
	}


}

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView diagnostics

#ifdef _DEBUG
void CGrafoOptimoAleatorioView::AssertValid() const
{
	CView::AssertValid();
}

void CGrafoOptimoAleatorioView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGrafoOptimoAleatorioDoc* CGrafoOptimoAleatorioView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGrafoOptimoAleatorioDoc)));
	return (CGrafoOptimoAleatorioDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGrafoOptimoAleatorioView message handlers



void CGrafoOptimoAleatorioView::Inserta(CNodoP *np, CNodoR *nr){
	np->abajo.AddTail(nr);
}

void CGrafoOptimoAleatorioView::Inserta(CNodoP *c1){
		g.AddTail(c1);
}
void CGrafoOptimoAleatorioView::OnOptimo( UINT nID ){
    int nButton = nID - IDM_CREAR;
    ASSERT( nButton >= 0 && nButton < 3 );

	switch(nButton)
	{
		case 0:
			band = TRUE;
			Invalidate();
		break;
		case 1:
			Invalidate();
			band = TRUE;
		break;
		case 2:
			band = TRUE;
			Invalidate();
			dlgCaja.gDlg.AddHead(&g);
			dlgCaja.DoModal();
		break;
	}
	opcion = nButton;
    
}


void CGrafoOptimoAleatorioView::CreaGrafo(int n)
{

}

void CGrafoOptimoAleatorioView::ImprimirGrafo(CDC *pDC)
{

		CNodoP* cp;
	CNodoR* cr;
	POSITION posP, posR;
	posP = g.GetHeadPosition();
	int x, y;
	x = 100;
	y = 100;
	char cad1[5] = {'\0'};
	char cad2[6] = {'\0'};
	char cad3[2] = {'\0'};
	
	while(posP)
	{
		cad1[0] = '\0';
		cad1[1] = '\0';
		cp = (CNodoP*)g.GetNext(posP);
		//Imprimir nombre
		cad1[0] =+ cp->nombre;	
		strcat(cad1,":");
		posR = cp->abajo.GetHeadPosition();
		x = 110;
	//	cad2[0] = '\0';
		
		while(posR)
		{	
			for(int i = 0; i <= 5; i++)
				cad2[i] = '\0';
	
			cr = (CNodoR*)cp->abajo.GetNext(posR);
			//Imprimir Peso
			cad2[0] += '|';
			itoa(cr->peso, cad3, 10);
			strcat(cad2,cad3);
			cad2[3] =+ cr->arriba->nombre;
			cad2[4] =+ '|';
			//cad2[5] =+ '>';
			pDC->TextOut(x+=60,y,cad2,5);			
		}
		x = 100;
		pDC->TextOut(x,y,cad1);
		
		y +=13;
		
		
	}

}
