// NodoP.cpp: implementation of the CNodoP class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GrafoOptimoAleatorio.h"
#include "NodoP.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL( CNodoP, CObject, 1)



CNodoP::CNodoP()
{

}

CNodoP::~CNodoP()
{

}

CNodoP::CNodoP(char n)
{
	nombre = n;
}
void CNodoP::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << nombre;
	}
	else
	{
		// TODO: add loading code here
		ar >> nombre;
	}
	//abajo.Serialize(ar);
}
