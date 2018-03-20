// Spin.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Spin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpin dialog


CSpin::CSpin(CWnd* pParent /*=NULL*/)
	: CDialog(CSpin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpin)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSpin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpin)
	DDX_Control(pDX, IDC_SPIN1, m_Spin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpin, CDialog)
	//{{AFX_MSG_MAP(CSpin)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpin message handlers

BOOL CSpin::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_Spin.SetRange(0,100);
	m_Spin.SetPos(0);
	SetDlgItemInt(IDC_EDIT1,0);
	m_Spin.SetBuddy(GetDlgItem(IDC_EDIT1));
	
	return TRUE;  
}


void CSpin::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int i = 0;
	
	SetDlgItemInt(IDC_EDIT1,nPos);
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
