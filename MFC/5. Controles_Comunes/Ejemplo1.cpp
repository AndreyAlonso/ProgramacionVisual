// Ejemplo1.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Ejemplo1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEjemplo1 dialog


CEjemplo1::CEjemplo1(CWnd* pParent /*=NULL*/)
	: CDialog(CEjemplo1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEjemplo1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEjemplo1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEjemplo1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEjemplo1, CDialog)
	//{{AFX_MSG_MAP(CEjemplo1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEjemplo1 message handlers
