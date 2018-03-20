// Set.h: interface for the CSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SET_H__572BCB77_269E_4446_AB82_E1F5463257F5__INCLUDED_)
#define AFX_SET_H__572BCB77_269E_4446_AB82_E1F5463257F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NodoP.h"
#include <time.h>

class CSet : public CObList  
{
public:
	
	POSITION pos;

	
	int num;
	CNodoP* np;
	void creaLista(int i);
	CSet& operator=(CSet &s); //Asignacion
	CSet& operator!();		//Complemento
	CSet& operator^(CSet &s); //Interseccion
	CSet& operator+(CSet &s);
	CSet();
	virtual ~CSet();

};

#endif // !defined(AFX_SET_H__572BCB77_269E_4446_AB82_E1F5463257F5__INCLUDED_)
