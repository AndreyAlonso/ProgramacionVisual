// GrafoOptimoAleatorioDoc.h : interface of the CGrafoOptimoAleatorioDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAFOOPTIMOALEATORIODOC_H__5B20B052_CA1D_4328_AF4E_59992BA1309D__INCLUDED_)
#define AFX_GRAFOOPTIMOALEATORIODOC_H__5B20B052_CA1D_4328_AF4E_59992BA1309D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NodoP.h" 
#include "NodoR.h"  
#include <time.h>

class CGrafoOptimoAleatorioDoc : public CDocument
{
protected: // create from serialization only
	CGrafoOptimoAleatorioDoc();
	DECLARE_DYNCREATE(CGrafoOptimoAleatorioDoc)

// Attributes
public:
		CNodoR* nr;	
		CNodoP* np;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrafoOptimoAleatorioDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CObList g;
	void Inserta(CNodoP *np);
	void Inserta(CNodoP *np, CNodoR *nr);
	int quieres;
	int num;
	int numeros;
	char name;
	void creaGrafo(int n);
	virtual ~CGrafoOptimoAleatorioDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGrafoOptimoAleatorioDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAFOOPTIMOALEATORIODOC_H__5B20B052_CA1D_4328_AF4E_59992BA1309D__INCLUDED_)
