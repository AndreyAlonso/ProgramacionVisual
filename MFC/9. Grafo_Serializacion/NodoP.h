// NodoP.h: interface for the CNodoP class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODOP_H__50E67167_E88B_424B_BD1D_47399C513C4F__INCLUDED_)
#define AFX_NODOP_H__50E67167_E88B_424B_BD1D_47399C513C4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNodoP : public CObject  
{
public:
	DECLARE_SERIAL( CNodoP )


	CObList abajo;
	char nombre;
	CNodoP(char n);
	CNodoP();
	virtual void Serialize(CArchive &ar);
	virtual ~CNodoP();

};

#endif // !defined(AFX_NODOP_H__50E67167_E88B_424B_BD1D_47399C513C4F__INCLUDED_)
