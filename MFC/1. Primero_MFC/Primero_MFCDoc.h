// Primero_MFCDoc.h : interface of the CPrimero_MFCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRIMERO_MFCDOC_H__C605CC01_4E41_4C19_BACC_5662A40F8E6E__INCLUDED_)
#define AFX_PRIMERO_MFCDOC_H__C605CC01_4E41_4C19_BACC_5662A40F8E6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPrimero_MFCDoc : public CDocument
{
protected: // create from serialization only
	CPrimero_MFCDoc();
	DECLARE_DYNCREATE(CPrimero_MFCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrimero_MFCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrimero_MFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrimero_MFCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIMERO_MFCDOC_H__C605CC01_4E41_4C19_BACC_5662A40F8E6E__INCLUDED_)
