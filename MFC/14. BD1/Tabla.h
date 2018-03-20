#if !defined(AFX_TABLA_H__42E8446E_D327_41E1_9610_96D31CC72DBA__INCLUDED_)
#define AFX_TABLA_H__42E8446E_D327_41E1_9610_96D31CC72DBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tabla.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabla recordset

class CTabla : public CRecordset
{
public:
	CTabla(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTabla)

// Field/Param Data
	//{{AFX_FIELD(CTabla, CRecordset)
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabla)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLA_H__42E8446E_D327_41E1_9610_96D31CC72DBA__INCLUDED_)
