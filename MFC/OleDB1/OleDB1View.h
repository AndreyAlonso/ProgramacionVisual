// OleDB1View.h : interface of the COleDB1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDB1VIEW_H__371B905F_3BE6_4092_8934_64336AE76086__INCLUDED_)
#define AFX_OLEDB1VIEW_H__371B905F_3BE6_4092_8934_64336AE76086__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COleDB1Set;

class COleDB1View : public COleDBRecordView
{
protected: // create from serialization only
	COleDB1View();
	DECLARE_DYNCREATE(COleDB1View)

public:
	//{{AFX_DATA(COleDB1View)
	enum{ IDD = IDD_OLEDB1_FORM };
	COleDB1Set* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	COleDB1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COleDB1View)
	public:
	virtual CRowset* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COleDB1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COleDB1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OleDB1View.cpp
inline COleDB1Doc* COleDB1View::GetDocument()
   { return (COleDB1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDB1VIEW_H__371B905F_3BE6_4092_8934_64336AE76086__INCLUDED_)
