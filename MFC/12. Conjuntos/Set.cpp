// Set.cpp: implementation of the CSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Conjuntos.h"
#include "Set.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSet::CSet()
{
	srand((unsigned) time(NULL));
}

CSet::~CSet()
{

}

CSet& CSet::operator = (CSet &s)
{
	this->AddHead(&s);
	return *this;

}

CSet& CSet::operator!()
{
	int i;
	CString cad;
	CSet *aux = new CSet;
	CNodoP* temp;
	pos = this->GetHeadPosition();
	np = (CNodoP*)this->GetTail();

	i = 0;
	while(pos)
	{
		np = (CNodoP*)this->GetNext(pos);
		while(i != np->numero)
		{
			temp = new CNodoP(i);
			aux->AddTail(temp);
			i++;

		}
		i++;
		
	}
	return *aux;

}



void CSet::creaLista(int i)
{
	CNodoP *nodo;
    int num, numeros;
    POSITION pos1;
    
    numeros = rand()%5+3;
    while(i--){
        pos1 = this->GetHeadPosition();
        num = rand()%9+1;
        nodo = new CNodoP(num);
        if(this->GetCount() >= 2)
		{
            while(pos1 && ((CNodoP*)this->GetAt(pos1))->numero < num)
			{
                this->GetNext(pos1);
            }
            if(!pos1)
			{
                this->AddTail((CObject*)nodo);
            }
            else
			{
				if(((CNodoP*)this->GetAt(pos1))->numero < num)
                this->InsertBefore(pos1, (CObject*)nodo);
            }
        }
        else
		{
            if(this->GetCount() == 1)
			{
                if(((CNodoP*)this->GetHead())->numero < num)
				{
                    this->InsertAfter(pos1, (CObject*)nodo);
                }
                else
				{
					if(((CNodoP*)this->GetHead())->numero > num)
						this->InsertBefore(pos1, (CObject*)nodo);

					if(((CNodoP*)this->GetHead())->numero == num)
						continue;
                }
            }
            else
			{
                this->AddHead((CObject*)nodo);
            }
        }
    }
}
		

CSet& CSet::operator ^(CSet &s)
{

	POSITION pos, pos2;
	CNodoP *temp;
	CNodoP *aux;
	CSet *nuevo = new CSet;
	int i;

	pos = this->GetHeadPosition();
	np = (CNodoP*)this->GetHead();

	aux = (CNodoP*)s.GetHead();
	pos2 = s.GetHeadPosition();

	while(pos || pos2)
	{
		if(aux->numero == np->numero)
			{
				i = np->numero;
				temp = new CNodoP(i);
				nuevo->AddHead(temp);
			//	if(this->GetNext(pos) != NULL && s.GetNext(pos2) != NULL){
					np  = (CNodoP*)this->GetNext(pos);
					aux = (CNodoP*)s.GetNext(pos2);
			//	}
		}
		
		else if(aux->numero > np->numero)
		{
			np  = (CNodoP*)this->GetNext(pos);

			if(aux->numero == np->numero)
			{
				i = np->numero;
				temp = new CNodoP(i);
				nuevo->AddHead(temp);
				if(pos){
					np  = (CNodoP*)this->GetNext(pos);
				}
			}
		}
		else if(aux->numero < np->numero)
		{
			aux = (CNodoP*)s.GetNext(pos2);
			if(aux->numero == np->numero)
			{
				i = np->numero;
				temp = new CNodoP(i);
				nuevo->AddHead(temp);
				if(pos2){
					aux = (CNodoP*)s.GetNext(pos2);
				}
			}
		}
		
	}

	return *nuevo;
	
}

CSet& CSet::operator +(CSet &s)
{
	return s;
}
