// Mesa.cpp : implementation file
//

#include "stdafx.h"
#include "BD1.h"
#include "Mesa.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMesa

IMPLEMENT_DYNAMIC(CMesa, CRecordset)

CMesa::CMesa(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMesa)
	m_Id = 0;
	m_Numero = _T("");
	m_Nombre = _T("");
	m_clave = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CMesa::GetDefaultConnect()
{
	return _T("ODBC;DSN=MY_ACCESS");
}

CString CMesa::GetDefaultSQL()
{
	return _T("[Tabla]");
}

void CMesa::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMesa)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[Numero]"), m_Numero);
	RFX_Text(pFX, _T("[Nombre]"), m_Nombre);
	RFX_Text(pFX, _T("[clave]"), m_clave);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMesa diagnostics

#ifdef _DEBUG
void CMesa::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMesa::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
