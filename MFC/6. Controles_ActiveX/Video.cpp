// Video.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_ActiveX.h"
#include "Video.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideo dialog


CVideo::CVideo(CWnd* pParent /*=NULL*/)
	: CDialog(CVideo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVideo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CVideo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVideo)
	DDX_Control(pDX, IDC_OCX1, m_Video);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVideo, CDialog)
	//{{AFX_MSG_MAP(CVideo)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideo message handlers

void CVideo::OnPlay() 
{
	// TODO: Add your control notification handler code here
	boton.play();

	
	
}

BOOL CVideo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	boton = m_Video.GetControls();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CVideo::OnPause() 
{
	// TODO: Add your control notification handler code here
	boton.pause();
	
}

void CVideo::OnStop() 
{
	// TODO: Add your control notification handler code here
	boton.stop();
	
}

void CVideo::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
	
}
