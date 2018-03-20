// OleDB1Doc.h : interface of the COleDB1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDB1DOC_H__D8EA51ED_8D79_47C0_9DBE_27DC804D45F0__INCLUDED_)
#define AFX_OLEDB1DOC_H__D8EA51ED_8D79_47C0_9DBE_27DC804D45F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OleDB1Set.h"


class COleDB1Doc : public CDocument
{
protected: // create from serialization only
	COleDB1Doc();
	DECLARE_DYNCREATE(COleDB1Doc)

// Attributes
public:
	COleDB1Set m_oleDB1Set;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDB1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COleDB1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COleDB1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDB1DOC_H__D8EA51ED_8D79_47C0_9DBE_27DC804D45F0__INCLUDED_)
