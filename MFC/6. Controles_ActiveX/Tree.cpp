// Tree.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_ActiveX.h"
#include "Tree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTree dialog


CTree::CTree(CWnd* pParent /*=NULL*/)
	: CDialog(CTree::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTree)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTree::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTree)
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTree, CDialog)
	//{{AFX_MSG_MAP(CTree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTree message handlers

BOOL CTree::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_Tree.SetTextColor(RGB(255,255,255));
	m_Tree.SetBkColor(RGB(0,0,0));
	HTREEITEM hSimpson = m_Tree.InsertItem("Abraham & Mona Simpson",0); 
	HTREEITEM hBouvier = m_Tree.InsertItem("Clancy & Jacqueline Bouvier", 0);
	m_Tree.InsertItem("Homero",hSimpson);
	m_Tree.InsertItem("Herbert",hSimpson);
	m_Tree.InsertItem("Marge", hBouvier);
	m_Tree.InsertItem("Patty", hBouvier);
	m_Tree.InsertItem("Selma", hBouvier);
	HTREEITEM hSimpson2 = m_Tree.InsertItem("Homero & Marge Simpson", hSimpson);
	m_Tree.InsertItem("Bart", hSimpson2);
	m_Tree.InsertItem("Lisa", hSimpson2);
	m_Tree.InsertItem("Maggie", hSimpson2);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



