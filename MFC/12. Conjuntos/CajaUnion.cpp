// CajaUnion.cpp : implementation file
//

#include "stdafx.h"
#include "Conjuntos.h"
#include "CajaUnion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCajaUnion dialog


CCajaUnion::CCajaUnion(CWnd* pParent /*=NULL*/)
	: CDialog(CCajaUnion::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCajaUnion)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCajaUnion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCajaUnion)
	DDX_Control(pDX, IDC_COMBO3, m_Combo3);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCajaUnion, CDialog)
	//{{AFX_MSG_MAP(CCajaUnion)
	ON_BN_CLICKED(IDC_UNION, OnUnion)
	ON_BN_CLICKED(IDOK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCajaUnion message handlers



BOOL CCajaUnion::OnInitDialog() 
{
	CDialog::OnInitDialog();
	if(band)
	{
		POSITION posA;
 		POSITION posB;
 		CNodoP *np ,*npB;
		int anterior, anterior2;
 		CString cad,cadB;
 		posA = this->setDlgA.GetHeadPosition();
 		while(posA)
 		{
			
			np = (CNodoP*)setDlgA.GetNext(posA);
		//	if(anterior != np->numero)
		//	{
 				cad.Format("%d", np->numero);
 				m_Combo1.AddString(cad);
		//	}
			anterior = np->numero;
 		
			
		}
 		m_Combo1.SetCurSel(0);
		///////////////////////////////////////////////////////////////////////////////
 		posB = this->setDlgB.GetHeadPosition();
 		while(posB)
 		{
 			npB = (CNodoP*)setDlgB.GetNext(posB);
		//	if(anterior2 != npB->numero){
 				cadB.Format("%d", npB->numero);
 				m_Combo2.AddString(cadB);
		//	}
			anterior2 = npB->numero;

		}
 		m_Combo2.SetCurSel(0);
	}
	else{
	
		this->MessageBox("Hola");
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CCajaUnion::OnUnion() 
{
	CString cad;
	CNodoP* nuevo;
	CNodoP* anterior;
	POSITION pos;
	setDlgA = setDlgA + setDlgB;
	setDlgC = setDlgA;

	nuevo = (CNodoP*)setDlgC.GetHead();
	pos = this->setDlgC.GetHeadPosition();
	
	while(pos)
	{
		anterior = nuevo;
		nuevo = (CNodoP*)setDlgC.GetNext(pos);
		if(anterior->numero != nuevo->numero)
		{
			cad.Format("%d", anterior->numero);
			m_Combo3.AddString(cad);
		}
		
	}
	m_Combo3.SetCurSel(0);
	

	
	
}


void CCajaUnion::OnOk() 
{
	setDlgA.RemoveAll();
	setDlgB.RemoveAll();
	setDlgC.RemoveAll();
	CCajaUnion::OnCancel();
}
