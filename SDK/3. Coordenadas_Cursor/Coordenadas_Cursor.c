/*******************************************************************************
 * Nombre: Hector Andrey Hernandez Alonso
 * Fecha: 17 de Agosto del 2017
 * Proyecto: Coordenadas Mouse.
 * Funcionalidad: Obtiene las coordenadas del cursor del mouse y se imprimen en 
 * el area cliente.
 * Metodos:	InvalidateRect, itoa, strcat
 * Handles: 
 * Mensajes: 
 * Tipos:
 * Estructuras:
 ********************************************************************************/

#include <windows.h>
#include <stdio.h>
#include <string.h>

//Prototipos
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE hInstance;

//Declaraciones globales
char szProgName[] = "Mi programa";
char szProgMenu[] = "Mimenu";
BOOL band = FALSE;
int xPos, yPos;

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

	hWnd = CreateWindow(szProgName, "Coordenada_Cursor",
						WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
						(HWND)NULL, (HMENU)NULL, (HANDLE)hInst,(LPSTR)NULL);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
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
	char cad1[3], cad2[3];
	char string[50];
	int aux;
	
	GetClientRect(hWnd,&rt);
	
	switch(messg)
	{
		case WM_PAINT:     //Window Message
			if(band){		
				hdc = BeginPaint(hWnd, &ps); // TAREA CLASE: xPos = 123, yPos = 245
				strcpy(string, "xPos = ");
				itoa(xPos,cad1, 10);//Convertir entero a cadenas
				strcat(string, cad1);
				strcat(string, ", yPos = ");
				itoa(yPos,cad2, 10);
				strcat(string, cad2);
				aux = strlen(string);
				TextOut(hdc, xPos,yPos, string,aux);
				EndPaint(hWnd, &ps);
			}  // TAREA MAÑANA: usar strlen, strcat, strcpy
			
		break;
		
		case WM_LBUTTONDOWN:
			// Para que no se pierda la informacion xPos y yPos deben ser estaticos o globales
			xPos = LOWORD(lParam);  // Posicion Horizontal del Cursor
			yPos = HIWORD(lParam);  // Posicion Vertical del Cursor
			band = TRUE;
			InvalidateRect(hWnd,  &rt, TRUE);
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
