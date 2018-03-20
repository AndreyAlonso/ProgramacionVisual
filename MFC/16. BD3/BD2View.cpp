// BD2View.cpp : implementation of the CBD2View class
//

#include "stdafx.h"
#include "BD2.h"

#include "BD2Set.h"
#include "BD2Doc.h"
#include "BD2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBD2View

IMPLEMENT_DYNCREATE(CBD2View, CRecordView)

BEGIN_MESSAGE_MAP(CBD2View, CRecordView)
	//{{AFX_MSG_MAP(CBD2View)
	ON_COMMAND(ID_add_record, Onaddrecord)
	ON_COMMAND(ID_clear_record, Onclearrecord)
	ON_COMMAND(ID_del_record, Ondelrecord)
	ON_COMMAND(ID_update_record, Onupdaterecord)
	ON_UPDATE_COMMAND_UI(ID_del_record, OnUpdatedelrecord)
	ON_UPDATE_COMMAND_UI(ID_update_record, OnUpdateupdaterecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBD2View construction/destruction

CBD2View::CBD2View()
	: CRecordView(CBD2View::IDD)
{
	//{{AFX_DATA_INIT(CBD2View)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CBD2View::~CBD2View()
{
}

void CBD2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBD2View)
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_Numero, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_Nombre, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_clave, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CBD2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CBD2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_bD2Set;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CBD2View diagnostics

#ifdef _DEBUG
void CBD2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CBD2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CBD2Doc* CBD2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBD2Doc)));
	return (CBD2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBD2View database support
CRecordset* CBD2View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CBD2View message handlers

void CBD2View::Onaddrecord() 
{
	// TODO: Add your command handler code here

	m_pSet->MoveLast();
	m_pSet->AddNew();
	m_pSet->m_Numero = 10;
	m_pSet->m_Nombre = "Ingrese el Nombre";
	m_pSet->m_clave = 2043;
	m_pSet->Update();
	UpdateData(TRUE);

	
}

void CBD2View::Onclearrecord() 
{
	// TODO: Add your command handler code here
	m_pSet->SetFieldNull(NULL);
	UpdateData(TRUE);

	
}

void CBD2View::Ondelrecord() 
{
	// TODO: Add your command handler code here
	CRecordsetStatus status;
	try{
		m_pSet->Delete();
	}
	catch(CDBException* e){
		AfxMessageBox(e->m_strError);
		e->Delete();
		m_pSet->MoveFirst();
		UpdateData(FALSE);
	}
	m_pSet->GetStatus(status);
	if(status.m_lCurrentRecord == 0)
		m_pSet->MoveFirst();
	else
		m_pSet->MoveNext();
	UpdateData(FALSE);
}

void CBD2View::Onupdaterecord() 
{
	// TODO: Add your command handler code here

	m_pSet->Edit();
	UpdateData(TRUE);
	if(m_pSet->CanUpdate())
		m_pSet->Update();
	
}




void CBD2View::OnUpdatedelrecord(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_pSet->IsEOF());
	
}

void CBD2View::OnUpdateupdaterecord(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_pSet->IsEOF());
	
}
