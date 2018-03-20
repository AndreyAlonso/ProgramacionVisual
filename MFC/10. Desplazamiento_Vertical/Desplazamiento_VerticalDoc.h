// Desplazamiento_VerticalDoc.h : interface of the CDesplazamiento_VerticalDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESPLAZAMIENTO_VERTICALDOC_H__CA5C4380_2DF7_40D0_AEF2_F4159544FA7E__INCLUDED_)
#define AFX_DESPLAZAMIENTO_VERTICALDOC_H__CA5C4380_2DF7_40D0_AEF2_F4159544FA7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDesplazamiento_VerticalDoc : public CDocument
{
protected: // create from serialization only
	CDesplazamiento_VerticalDoc();
	DECLARE_DYNCREATE(CDesplazamiento_VerticalDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesplazamiento_VerticalDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDesplazamiento_VerticalDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDesplazamiento_VerticalDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESPLAZAMIENTO_VERTICALDOC_H__CA5C4380_2DF7_40D0_AEF2_F4159544FA7E__INCLUDED_)
