// Nodo.h: interface for the CNodo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODO_H__4306DE75_4903_4A1E_B59F_A45F5A655631__INCLUDED_)
#define AFX_NODO_H__4306DE75_4903_4A1E_B59F_A45F5A655631__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNodo : public CObject  
{
public:
	int numero;
	CNodo(int n);
	CNodo();
	virtual ~CNodo();

};

#endif // !defined(AFX_NODO_H__4306DE75_4903_4A1E_B59F_A45F5A655631__INCLUDED_)
