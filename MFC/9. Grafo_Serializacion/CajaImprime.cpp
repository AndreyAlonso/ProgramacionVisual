// CajaImprime.cpp : implementation file
//

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"
#include "CajaImprime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCajaImprime dialog


CCajaImprime::CCajaImprime(CWnd* pParent /*=NULL*/)
	: CDialog(CCajaImprime::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCajaImprime)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCajaImprime::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCajaImprime)
	DDX_Control(pDX, IDC_LIST1, m_Grafo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCajaImprime, CDialog)
	//{{AFX_MSG_MAP(CCajaImprime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCajaImprime message handlers

BOOL CCajaImprime::OnInitDialog() 
{
	CDialog::OnInitDialog();
	i;
	/*
	// Esquina 0,0 --------- Adhoc
	m_Grafo.InsertColumn(0,"P / R", LVCFMT_LEFT,80,-1);

	// Número de Relaciones o Aristas.
	m_Grafo.InsertColumn(1,"Relación_1", LVCFMT_LEFT,80,-1);
	m_Grafo.InsertColumn(2,"Relación_2", LVCFMT_LEFT,80,-1);
	m_Grafo.InsertColumn(3,"Relación_3", LVCFMT_LEFT,80,-1);

	// Renglon
	// Número de Noodos Principales.
	m_Grafo.InsertItem(0,"A");
	m_Grafo.InsertItem(1,"B");
	m_Grafo.InsertItem(2,"C");

	// Columna
	// Pesos de las Relaciones.
	m_Grafo.SetItemText(0,1,"A_10");
	m_Grafo.SetItemText(0,2,"B_20");
	m_Grafo.SetItemText(0,3,"C_30");

	m_Grafo.SetItemText(1,1,"A_NULL");
	m_Grafo.SetItemText(1,3,"C_15");
	m_Grafo.SetItemText(1,2,"B_20");

	m_Grafo.SetItemText(2,1,"A_NULL");
	m_Grafo.SetItemText(2,2,"B_25");
	m_Grafo.SetItemText(2,3,"C_NULL"); */
   /**********************************************************************************/
	//Generación en la Corrida
	CNodoP *np;
	CNodoR *nr;
	char name = 'A';
	CString peso;


	maxNP = gDlg.GetCount(); //Numero de nodos principales
	//maxNR = calculaRelacione();
	// Esquina 0,0 --------- Adhoc
	m_Grafo.InsertColumn(0,"P / R", LVCFMT_LEFT,80,-1);

	//Numero de Relaciones o Aristas
	for(i = 0; i <= maxNP; i++)
	{
		m_Grafo.InsertColumn(i+1,(CString)name,LVCFMT_LEFT, 60, -1);
		m_Grafo.InsertItem(i+1,(CString)name++);
	}

    //Numero de Nodos Principales.
	for(i = 0; i <= maxNR; i++)
	{
		m_Grafo.InsertItem(i, (CString)name++);

	}
	i = 0;
	j = 1; 
	//Llenado del control
	name = 'A';
	posP = gDlg.GetHeadPosition();
	while(posP)
	{
		np = (CNodoP*)gDlg.GetNext(posP);
		posR = np->abajo.GetHeadPosition();
		while(posR)
		{
			j = 1;
			name = 'A';
			nr = (CNodoR*)np->abajo.GetNext(posR);
			peso.Format("%d", nr->peso);
			while(nr->arriba->nombre != name){
				j++;
				name++;

			}
			if(nr->arriba->nombre == name)
				m_Grafo.SetItemText(i, j,peso);	
			else
				m_Grafo.SetItemText(i, j,"NULL"); 
		}
		i++;
	
		name = 'A';
	}
	
	return TRUE; 
}

/* Dice mi mamá que siempre NO!!!
int CCajaImprime::calculaRelacion()
{
	int contRel = 0, max = 0;
	posP = gDlg.GetHeadPosition();
	while(posP)
	{
		np = (CNodoP*)gDlg.GetNext(posP);
		max = np->abajo.GetCount();
		if(max > contRel) 
			contRel = max;
	}
	return contRel;
}
*/