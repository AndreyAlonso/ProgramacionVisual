// CajaComplemento.cpp : implementation file
//

#include "stdafx.h"
#include "Conjuntos.h"
#include "CajaComplemento.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCajaComplemento dialog


CCajaComplemento::CCajaComplemento(CWnd* pParent /*=NULL*/)
	: CDialog(CCajaComplemento::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCajaComplemento)
	m_Combo1 = _T("");
	//}}AFX_DATA_INIT
}


void CCajaComplemento::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCajaComplemento)
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_CBString(pDX, IDC_COMBO1, m_Combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCajaComplemento, CDialog)
	//{{AFX_MSG_MAP(CCajaComplemento)
	ON_BN_CLICKED(IDC_COMPLEMENTO, OnComplemento)
	ON_BN_CLICKED(IDOK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCajaComplemento message handlers

BOOL CCajaComplemento::OnInitDialog() 
{

	CDialog::OnInitDialog();
	pos = setDlg.GetHeadPosition();
	while(pos)
	{
		np = (CNodoP*)setDlg.GetNext(pos);
		if(cad != np->numero){
			cad.Format("%d", np->numero);			
			m_Combo.AddString(cad);
		}
	}
	m_Combo.SetCurSel(0);

	return TRUE;
}

void CCajaComplemento::OnComplemento() 
{

	setComple = !setDlg; /// sobrecarga de operadores
	
	pos = setComple.GetHeadPosition();
	while(pos)
	{
		np = (CNodoP*)setComple.GetNext(pos);
		if(cad != np->numero)
		{	
			cad.Format("%d", np->numero);
			m_Combo2.AddString(cad);
		}
		
	}
	m_Combo2.SetCurSel(0);
}

void CCajaComplemento::OnOk() 
{
	setDlg.RemoveAll();
	setComple.RemoveAll();
	np = NULL;
	free(np);
	CCajaComplemento::OnCancel();
	Invalidate();
}


