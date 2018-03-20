
#if !defined(AFX_LISTA_NUM_H__147A2019_E37F_4487_BF98_1F09598E0B01__INCLUDED_)
#define AFX_LISTA_NUM_H__147A2019_E37F_4487_BF98_1F09598E0B01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

typedef struct reg NP;
typedef struct reg1 NR;


struct reg{
    char nombre;
	NP *sig; //Nodo Principal
	NR *abajo; //Nodo Relacion
	HWND hCombo;
};

struct reg1{
	int num;
	NR *sig;
	NP *arriba;
};


#endif // !defined(AFX_LISTA_NUM_H__147A2019_E37F_4487_BF98_1F09598E0B01__INCLUDED_)
