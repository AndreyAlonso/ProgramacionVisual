// Tabla.cpp : implementation file
//

#include "stdafx.h"
#include "BD1.h"
#include "Tabla.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabla

IMPLEMENT_DYNAMIC(CTabla, CRecordset)

CTabla::CTabla(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTabla)
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CTabla::GetDefaultConnect()
{
	return _T("ODBC;DSN=MY_ACCESS");
}

CString CTabla::GetDefaultSQL()
{
	return _T("");
}

void CTabla::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTabla)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTabla diagnostics

#ifdef _DEBUG
void CTabla::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTabla::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
