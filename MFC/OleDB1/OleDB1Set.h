// OleDB1Set.h : interface of the COleDB1Set class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDB1SET_H__048C0D04_F5D1_48B6_A7C0_D75038D1C8A2__INCLUDED_)
#define AFX_OLEDB1SET_H__048C0D04_F5D1_48B6_A7C0_D75038D1C8A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMSysACEs
{
public:
	CMSysACEs()
	{
		memset( (void*)this, 0, sizeof(*this) );
	};



BEGIN_COLUMN_MAP(CMSysACEs)

END_COLUMN_MAP()

};

class COleDB1Set : public CCommand<CAccessor<CMSysACEs> >
{
public:

	HRESULT Open()
	{
		CDataSource db;
		CSession	session;
		HRESULT		hr;

		CDBPropSet	dbinit(DBPROPSET_DBINIT);
		dbinit.AddProperty(DBPROP_AUTH_CACHE_AUTHINFO, true);
		dbinit.AddProperty(DBPROP_AUTH_ENCRYPT_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_MASK_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_PASSWORD, "");
		dbinit.AddProperty(DBPROP_AUTH_USERID, "Admin");
		dbinit.AddProperty(DBPROP_INIT_DATASOURCE, "C:\\Users\\Usuario\\Desktop\\Hector Andrey Hernandez Alonso\\MFC\\OleDB1\\db1.mdb");
		dbinit.AddProperty(DBPROP_INIT_MODE, (long)16);
		dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)4);
		dbinit.AddProperty(DBPROP_INIT_PROVIDERSTRING, "");
		dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, true);

		hr = db.OpenWithServiceComponents("Microsoft.Jet.OLEDB.4.0", &dbinit);
		if (FAILED(hr))
			return hr;

		hr = session.Open(db);
		if (FAILED(hr))
			return hr;

		CDBPropSet	propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
		propset.AddProperty(DBPROP_IRowsetScroll, true);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE );

		hr = CCommand<CAccessor<CMSysACEs> >::Open(session, "SELECT * FROM MSysACEs", &propset);
		if (FAILED(hr))
			return hr;

		return MoveNext();
	}

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDB1SET_H__048C0D04_F5D1_48B6_A7C0_D75038D1C8A2__INCLUDED_)

