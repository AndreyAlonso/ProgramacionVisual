// OleDBDoc.h : interface of the COleDBDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBDOC_H__E45F8EB0_9043_4CF3_AA66_E7FB94EC6840__INCLUDED_)
#define AFX_OLEDBDOC_H__E45F8EB0_9043_4CF3_AA66_E7FB94EC6840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OleDBSet.h"


class COleDBDoc : public CDocument
{
protected: // create from serialization only
	COleDBDoc();
	DECLARE_DYNCREATE(COleDBDoc)

// Attributes
public:
	COleDBSet m_oleDBSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDBDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COleDBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COleDBDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBDOC_H__E45F8EB0_9043_4CF3_AA66_E7FB94EC6840__INCLUDED_)
