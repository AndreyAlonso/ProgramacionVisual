// OleDBSet.h : interface of the COleDBSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBSET_H__C313C3FD_A460_494B_ABEC_A55649A0A58A__INCLUDED_)
#define AFX_OLEDBSET_H__C313C3FD_A460_494B_ABEC_A55649A0A58A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COleDBSet : public CRecordset
{
public:
	COleDBSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COleDBSet)

// Field/Param Data
	//{{AFX_FIELD(COleDBSet, CRecordset)
	long	m_Id;
	CString	m_Campo1;
	CString	m_Nombre;
	long	m_Campo3;
	long	m_Campo4;
	CString	m_Campo2;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDBSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBSET_H__C313C3FD_A460_494B_ABEC_A55649A0A58A__INCLUDED_)

