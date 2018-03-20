/*************************************************************************
 * Nombre:			Hector Andrey Hernandez Alonso
 * Fecha:			26 de Septiembre del 2017
 * Proyecto:		Cascaron MFC
 * Funcionalidad:   Muestra de una ventana de mensaje.
 * Metodos:						
 * Clases:			CWinApp.
 * Mensajes:		AfxMessageBox.	
 * Tipos:			
 * Estructuras: 
 ************************************************************************/
#include <afxwin.h>

 class CCascaron_MFC: public CWinApp
 {
	 virtual BOOL InitInstance()
	 {
		 AfxMessageBox("Hola MFC");
		 return TRUE;
	 }

 };
CCascaron_MFC theApp;
