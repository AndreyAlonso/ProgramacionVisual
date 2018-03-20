/*************************************************************************
 * Nombre:			Héctor Andrey Hernández Alonso
 * Fecha:			27 de Septiembre del 2017
 * Proyecto:		Cascaron_MFC Clases
 * Funcionalidad:	Uso de la ventana y del mouse en MFC.
 * Metodos:								
 * Clases:			CFrameWnd, CClientDC.
 * Mensajes:		
 * Tipos:			BEGIN_MESSAGE_MAP
 * Estructuras: 
 ************************************************************************/
#include <afxwin.h>

int x = 100,y = 100;
BOOL band = FALSE;

class CCascaron_Frame: public CFrameWnd
{
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT);
	DECLARE_MESSAGE_MAP();
};

BEGIN_MESSAGE_MAP(CCascaron_Frame, CFrameWnd) //Clase Marco
	ON_WM_CHAR()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

void CCascaron_Frame ::OnPaint()
{
	CPaintDC dc(this);
	if(band){
		dc.TextOut(x,y, "Hola Mundo");
	}
}

void CCascaron_Frame :: OnLButtonDown(UINT u ,CPoint p)
{	
	CClientDC pDC(this);
	x = p.x;
	y = p.y;
	band = TRUE;
	Invalidate(); // Parametros por default
}


void CCascaron_Frame :: OnChar(UINT nChar)
{
	CDC *pDC = GetDC();
	switch(nChar)
	{
		case '\r':
			x = 100;
			y += 20;
		break;
		default:
			
			pDC->TextOut(x+=8,y,nChar);
	}
	
}


class CCascaron_MFC: public CWinApp //Clase Aplicacion
{
	 virtual BOOL InitInstance()
	 {
		 //AfxMessageBox("Hola MFC");
		 CCascaron_Frame *pMarco = new CCascaron_Frame;
		 pMarco->Create(NULL,(CString)"Cascaron MFC");
		 //Asignacion del puntero a la variable miembro de la clase Wnd.
		 m_pMainWnd = pMarco;
		 m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
		 return TRUE;
	 }

};

CCascaron_MFC theApp;