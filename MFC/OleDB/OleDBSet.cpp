// OleDBSet.cpp : implementation of the COleDBSet class
//

#include "stdafx.h"
#include "OleDB.h"
#include "OleDBSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COleDBSet implementation

IMPLEMENT_DYNAMIC(COleDBSet, CRecordset)

COleDBSet::COleDBSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(COleDBSet)
	m_Id = 0;
	m_Campo1 = _T("");
	m_Nombre = _T("");
	m_Campo3 = 0;
	m_Campo4 = 0;
	m_Campo2 = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}

CString COleDBSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=MY_ACCESS");
}

CString COleDBSet::GetDefaultSQL()
{
	return _T("[Tabla1]");
}

void COleDBSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(COleDBSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[Campo1]"), m_Campo1);
	RFX_Text(pFX, _T("[Nombre]"), m_Nombre);
	RFX_Long(pFX, _T("[Campo3]"), m_Campo3);
	RFX_Long(pFX, _T("[Campo4]"), m_Campo4);
	RFX_Text(pFX, _T("[Campo2]"), m_Campo2);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// COleDBSet diagnostics

#ifdef _DEBUG
void COleDBSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void COleDBSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
