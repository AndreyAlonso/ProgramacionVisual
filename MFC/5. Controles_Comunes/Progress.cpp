// Progress.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Progress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDT_TIMER 1


/////////////////////////////////////////////////////////////////////////////
// CProgress dialog


CProgress::CProgress(CWnd* pParent /*=NULL*/)
	: CDialog(CProgress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProgress)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	band_accion = FALSE;

}


void CProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProgress)
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
	DDX_Control(pDX, IDC_PROGRESS2, m_Progress2);
	DDX_Control(pDX, IDC_PROGRESS3, m_Progress3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProgress, CDialog)
	//{{AFX_MSG_MAP(CProgress)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_ACCION, OnAccion)
	ON_BN_CLICKED(IDOK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgress message handlers

BOOL CProgress::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetTimer(IDT_TIMER,20,NULL);
	m_Progress.SetPos(100);
	m_Progress.SetStep(-1);
	
	m_Progress2.SetPos(100);
	m_Progress2.SetStep(-1);
	
	m_Progress3.SetPos(0);
	m_Progress3.SetStep(1);
	
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProgress::OnTimer(UINT nIDEvent) 
{
	int paso = 100, paso2 = 100, paso3 = 0;
	CString cad1, cad2, cad3;
	cad1.Format("%d", paso);
	cad2.Format("%d", paso2);
	cad3.Format("%d", paso3);
	SetDlgItemText(IDC_EDIT1,cad1);
	SetDlgItemText(IDC_EDIT2,cad2);
	SetDlgItemText(IDC_EDIT3,cad3);
	if(nIDEvent & band_accion)
	{
		paso = m_Progress.StepIt();	
		paso3 = m_Progress3.StepIt();
		m_Progress3.SetRange(0,200);
		cad1.Format("%d", paso);
		SetDlgItemText(IDC_EDIT1,cad1);
		cad2.Format("%d", 100);
		SetDlgItemText(IDC_EDIT2,cad2);
		cad3.Format("%d", paso3);
		SetDlgItemText(IDC_EDIT3,cad3);
		if(paso <= 0){
			m_Progress.SetPos(0);
			m_Progress.SetStep(0);
			
			if(paso == 0 )
			{
				paso2 = m_Progress2.StepIt();			
				cad2.Format("%d", paso2);
				SetDlgItemText(IDC_EDIT2,cad2);
				if(paso2 <= 0)
				{
					m_Progress2.SetPos(paso2--);
					m_Progress2.SetStep(paso2--);
					m_Progress2.OffsetPos(0);
					m_Progress3.OffsetPos(200);

				}
				
			}
		
		}
		
	


	}
	
	CDialog::OnTimer(nIDEvent);
	
}





void CProgress::OnAccion() 
{
	band_accion = TRUE;	
}

void CProgress::OnOk() 
{
	// TODO: Add your control notification handler code here
	CProgress::OnCancel();
	band_accion = FALSE;
	CProgress::OnInitDialog();
	
	
}
