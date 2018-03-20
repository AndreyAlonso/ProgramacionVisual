// NodoR.h: interface for the CNodoR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODOR_H__389F6873_B1B2_4B5B_A07B_20D472885FF2__INCLUDED_)
#define AFX_NODOR_H__389F6873_B1B2_4B5B_A07B_20D472885FF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NodoR.h"
#include "NodoP.h"

class CNodoR : public CObject  
{
public:
	DECLARE_SERIAL( CNodoR )

	CNodoP* arriba;
	int peso;
	CNodoR(int p);
	CNodoR();
	virtual void Serialize(CArchive &ar);
	virtual ~CNodoR();

};

#endif // !defined(AFX_NODOR_H__389F6873_B1B2_4B5B_A07B_20D472885FF2__INCLUDED_)
