/*******************************************************************************
 * Nombre: Hector Andrey Hernandez Alonso
 * Fecha: 17 de Agosto del 2017
 * Proyecto: Cascaron.
 * Funcionalidad: Minima, ventana de la aplicacion.
 * Metodos: LoadCursor, GetStockObject, RegisterClass, CreateWindow, ShowWindow, UpadeteWindow, GetMessage, TranslateMessage, DispatchMessage
 * BeginPaint, GetClientRect, SetTextColor, TextOut, EndPaint, PostQuitMessage,			
 * Handles: HINSTANCE, HWND.
 * Mensajes: WM_PAINT, WM_DESTROY.
 * Tipos:LRESULT, CALLBACK, UINT,WPARAM, WINAPI, LPSTR, HDC.
 * Estructuras: MSG, WNDCLASS, PAINTSTRUCT, RECT, RGB.
 ********************************************************************************/

#include <windows.h>

//Prototipos
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE hInstance;

//Declaraciones globales
char szProgName[] = "Mi programa";
char szProgMenu[] = "Mimenu";
BOOL band = FALSE;


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS wcApp;

	hInstance = hInst;

	wcApp.lpszClassName = szProgName;
	wcApp.hInstance = hInst;
	wcApp.lpfnWndProc = WndProc;
	wcApp.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcApp.hIcon = 0;
	wcApp.lpszMenuName = szProgMenu;
	wcApp.hbrBackground = GetStockObject(WHITE_BRUSH);
	wcApp.style= CS_HREDRAW|CS_VREDRAW;
	wcApp.cbClsExtra = 0;
	wcApp.cbWndExtra = 0;
	
	//Registro de Clase
	if(!RegisterClass(&wcApp))
		return 0;

	hWnd = CreateWindow(szProgName, "Cascaron",
						WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
						(HWND)NULL, (HMENU)NULL, (HANDLE)hInst,(LPSTR)NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	
	while(GetMessage(&lpMsg, 0, 0, 0)){
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);

	}
	return(lpMsg.wParam);


}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam){

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rt;

	switch(messg)
	{
		case WM_PAINT:     //Window Message
			
				hdc = BeginPaint(hWnd, &ps);
				GetClientRect(hWnd,&rt);
				SetTextColor(hdc, RGB(0, 0, 0));  //---------------------------------------> Paleta de Colores
			 	TextOut(hdc,(rt.right/2)-(10/2)*8, rt.bottom/2, "Hola Mundo", 10);
				EndPaint(hWnd, &ps);
			
		break;
		
		

		case WM_DESTROY:
				PostQuitMessage(0);
		break;

		default:
				return(DefWindowProc(hWnd, messg, wParam, lParam));
		break;


	}

	return 0;
}
