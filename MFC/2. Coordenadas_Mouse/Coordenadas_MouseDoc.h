// Coordenadas_MouseDoc.h : interface of the CCoordenadas_MouseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COORDENADAS_MOUSEDOC_H__B0371FA9_D762_4156_8BBA_DBE50FC7F129__INCLUDED_)
#define AFX_COORDENADAS_MOUSEDOC_H__B0371FA9_D762_4156_8BBA_DBE50FC7F129__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCoordenadas_MouseDoc : public CDocument
{
protected: // create from serialization only
	CCoordenadas_MouseDoc();
	DECLARE_DYNCREATE(CCoordenadas_MouseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordenadas_MouseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCoordenadas_MouseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCoordenadas_MouseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDENADAS_MOUSEDOC_H__B0371FA9_D762_4156_8BBA_DBE50FC7F129__INCLUDED_)
