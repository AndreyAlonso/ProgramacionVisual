#if !defined(AFX_MESA_H__735FCCD4_B931_46B1_B77D_EB79D06B3305__INCLUDED_)
#define AFX_MESA_H__735FCCD4_B931_46B1_B77D_EB79D06B3305__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mesa.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMesa recordset

class CMesa : public CRecordset
{
public:
	CMesa(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMesa)

// Field/Param Data
	//{{AFX_FIELD(CMesa, CRecordset)
	long	m_Id;
	CString	m_Numero;
	CString	m_Nombre;
	CString	m_clave;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMesa)
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

#endif // !defined(AFX_MESA_H__735FCCD4_B931_46B1_B77D_EB79D06B3305__INCLUDED_)
