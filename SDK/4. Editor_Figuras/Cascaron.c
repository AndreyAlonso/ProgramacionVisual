/*******************************************************************************
 * Nombre: Hector Andrey Hernandez Alonso
 * Fecha: 17 de Agosto del 2017
 * Proyecto: Editor de Figuras.
 * Funcionalidad: Se agregan archivos de recursos.  Resource MENU
 * Metodos:	Rectangle, Ellipse, RoundRect, MoveToEx, LineTo, LOWORD.
 * Handles: 
 * Mensajes: WM_COMMAND
 * Tipos:
 * Estructuras:
 ********************************************************************************/

#include <windows.h>
#include "Cascaron.h"

//Prototipos
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE hInstance;

//Declaraciones globales
char szProgName[] = "Mi programa";
char szProgMenu[] = "Mi_Menu";
BOOL band = TRUE;
int figura = 0;



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS wcApp;
	HACCEL hAccel;


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

	hWnd = CreateWindow(szProgName, "Editor de Figuras",
						WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
						(HWND)NULL, (HMENU)NULL, (HANDLE)hInst,(LPSTR)NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	hAccel = LoadAccelerators(hInst, "MiAccel");
	
	// Ciclo de Mensajes
	while(GetMessage(&lpMsg, 0, 0, 0)){

		if(!TranslateAccelerator(hWnd, hAccel, &lpMsg))
		{
			TranslateMessage(&lpMsg);
			DispatchMessage(&lpMsg);
		}

	}
	return(lpMsg.wParam);


}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam){

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rt;
	int wID;

	GetClientRect(hWnd,&rt);
	switch(messg)
	{
		case WM_COMMAND:
			wID = LOWORD(wParam);// item, control, or accelerator identifier 

			switch(wID)
			{
				case IDM_RECTANGLE:
					figura = 1;
				break;

				case IDM_ELLIPSE:
					figura = 2;
				break;

				case IDM_ROUNDRECT:
					figura = 3;
				break;

				case IDM_LINE:
					figura = 4;
				break;

				case IDM_FREEHAND:
					figura = 5;
				break;
			}
			InvalidateRect(hWnd, &rt, FALSE);
		break;
		

		case WM_PAINT:     //Window Message
	
			if(band){
				hdc = BeginPaint(hWnd, &ps);
				

				
				switch(figura)
				{
									

					case 1:
						Rectangle(hdc,100, 100, 200, 200);
					break;

					case 2:
						Ellipse(hdc,100, 100, 200, 200);
					
					break;

					case 3:
						RoundRect(hdc,100, 100, 200, 200, 30, 30);
					break;

					case 4:
						MoveToEx(hdc,100, 100, NULL);   // Line
						LineTo(hdc, 200, 200);
					break;

					case 5:
						// En construccion
						

					break;

				}
				EndPaint(hWnd, &ps);
			}
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
