// Ejemplo.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Ejemplo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEjemplo dialog


CEjemplo::CEjemplo(CWnd* pParent /*=NULL*/)
	: CDialog(CEjemplo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEjemplo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEjemplo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEjemplo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEjemplo, CDialog)
	//{{AFX_MSG_MAP(CEjemplo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEjemplo message handlers
