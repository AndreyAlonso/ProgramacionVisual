// Dialg1.cpp : implementation file
//

#include "stdafx.h"
#include "Controles_Comunes.h"
#include "Dialg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialg1 dialog


CDialg1::CDialg1(CWnd* pParent /*=NULL*/)
	: CDialog(CDialg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialg1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialg1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialg1, CDialog)
	//{{AFX_MSG_MAP(CDialg1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialg1 message handlers
