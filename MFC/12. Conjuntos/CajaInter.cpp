// CajaInter.cpp : implementation file
//

#include "stdafx.h"
#include "Conjuntos.h"
#include "CajaInter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCajaInter dialog


CCajaInter::CCajaInter(CWnd* pParent /*=NULL*/)
	: CDialog(CCajaInter::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCajaInter)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	band = FALSE;
}


void CCajaInter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCajaInter)
	DDX_Control(pDX, IDC_COMBO3, m_ConjuntoC);
	DDX_Control(pDX, IDC_COMBO2, m_ConjuntoB);
	DDX_Control(pDX, IDC_COMBO1, m_ConjuntoA);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCajaInter, CDialog)
	//{{AFX_MSG_MAP(CCajaInter)
	ON_BN_CLICKED(IDC_INTER, OnInter)
	ON_BN_CLICKED(IDOK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCajaInter message handlers

void CCajaInter::OnInter() 
{
	setC = setA ^ setB;
	CString cad;
	CNodoP* nuevo;
	CNodoP* anterior;
	POSITION pos, posA,posB;
	nuevo = (CNodoP*)setC.GetHead();
	pos = this->setC.GetHeadPosition();
	while(pos)
	{
		nuevo = (CNodoP*)setC.GetNext(pos);
		cad.Format("%d", nuevo->numero);
		m_ConjuntoC.AddString(cad);	
	}
	m_ConjuntoC.SetCurSel(0);
}

BOOL CCajaInter::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if(band)
	{
		POSITION posA;
 		POSITION posB;
		CNodoP* anterior;
 		CNodoP *np ,*npB;
 		CString cad,cadB;
 		posA = this->setA.GetHeadPosition();
 		while(posA)
 		{
			anterior = np;
			np = (CNodoP*)setA.GetNext(posA);
			//if(anterior->numero != np->numero)
			//{
 			    cad.Format("%d", np->numero);
 				m_ConjuntoA.AddString(cad);
			//}
 		
			
		}
 		m_ConjuntoA.SetCurSel(0);
		///////////////////////////////////////////////////////////////////////////////
 		posB = this->setB.GetHeadPosition();
 		while(posB)
 		{
 			npB = (CNodoP*)setB.GetNext(posB);
			if(cadB != npB->numero){
 				cadB.Format("%d", npB->numero);
 				m_ConjuntoB.AddString(cadB);
			}
			else
				continue;
		}
 		m_ConjuntoB.SetCurSel(0);
	}
	else{
	
		this->MessageBox("Hola");
	}	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCajaInter::OnOk() 
{
	// TODO: Add your control notification handler code here
	setA.RemoveAll();
	setB.RemoveAll();
	setC.RemoveAll();
	CCajaInter::OnCancel();
	
}
