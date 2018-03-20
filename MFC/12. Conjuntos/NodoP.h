// NodoP.h: interface for the CNodoP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODOP_H__E3C1F172_C295_4E74_9EBF_5B392BEE7248__INCLUDED_)
#define AFX_NODOP_H__E3C1F172_C295_4E74_9EBF_5B392BEE7248__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNodoP : public CObject  
{
public:
	int numero;
	CNodoP();
	CNodoP(int n);
	virtual ~CNodoP();

};

#endif // !defined(AFX_NODOP_H__E3C1F172_C295_4E74_9EBF_5B392BEE7248__INCLUDED_)
