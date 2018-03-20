/****************************************************************************************************
 * Nombre:			Héctor Andrey Hernández Alonso
 * Fecha:			02 de Octubre del 2017
 * Proyecto:		Examen 2 - Editor de Texto
 * Funcionalidad:	Uso de la Programación Orientada a Objetos en un editor de texto.
 * Metodos:				
 * Handles:
 * Mensajes:
 * Tipos:		
 * Estructuras: 
 ***************************************************************************************************/
#include <afxwin.h>

#define x1	10
#define y1	10
#define x2	300
#define y2	150
int x = 10,y = 10;
RECT window;

class CCascaron_Frame: public CFrameWnd
{
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnLButtonUP(UINT, CPoint);
	afx_msg void OnMouseMove(UINT, CPoint);
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
	window.bottom = y2;
	window.left = x1;
	window.top = y1;
	window.right = x2;
	dc.Rectangle(x1-2,y1-2,x2+10,y2+2);
}

void CCascaron_Frame :: OnLButtonDown(UINT u ,CPoint p)
{	
	CClientDC pDC(this);
//	x = p.x;
//	y = p.y;


}

void CCascaron_Frame :: OnChar(UINT nChar)
{

	CDC *pDC = GetDC();
	switch(nChar){
	// Space Bar
		case  32:
			x += 10;
		break;
	// Carriage Return
	    case '\r': 
			x = 10;
			y += 20;
		break;
	// Back Space
		case '\b': 
			pDC->Rectangle(x,y,x+12,y+15);
			pDC->FloodFill(x,y,RGB(255,255,255));
			if(x  >= window.left+20)
			{
				x = x - 13;
			}
			else if(x < window.left+20 && y >= window.top + y1)
			{
				y = y - 20;
				x = window.right-20;
			}
	
		break;
		default:
			if(x >= window.right-20)
			{
				x = 10;
				y +=20;
			}
			if(y >= window.bottom-10){
				InvalidateRect(&window,TRUE);
				x = 10;
				y = 10;	
				pDC->TextOut(x,y,nChar);
			}
			else
				pDC->TextOut(x+=13,y,nChar);
		
	}
}


class CCascaron_MFC: public CWinApp //Clase Aplicacion
{
	 virtual BOOL InitInstance(){
		 CCascaron_Frame *pMarco = new CCascaron_Frame;
		 pMarco->Create(NULL,(CString)"Examen 2 - Editor de Texto");
		 //Asignacion del puntero a la variable miembro de la clase Wnd.
		 m_pMainWnd = pMarco;
		 m_pMainWnd->ShowWindow(SW_SHOWNORMAL);	 
		 return TRUE;
	 }

};

CCascaron_MFC theApp;