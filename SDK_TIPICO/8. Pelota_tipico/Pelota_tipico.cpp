// Pelota_tipico.cpp : Defines the entry point for the application.
//

/*************************************************************************
 * Nombre:			Hector Andrey Hernandez Alonso
 * Fecha:			Pelota Tipico.
 * Funcionalidad:	Rebote de pelota.
 * Metodos:						
 * Handles:
 * Mensajes:				
 * Tipos:			
 * Estructuras: 
 ************************************************************************/

#include "stdafx.h"
#include "resource.h"


#define MAX_LOADSTRING 100
#define IDT_TIMER1 2
#define PASO 8

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text
BOOL band = FALSE;
// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_PELOTA_TIPICO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_PELOTA_TIPICO);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_PELOTA_TIPICO);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_PELOTA_TIPICO;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 300, 300, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	RECT rt;
	static int xPos = 100, yPos = 100;
	static int dir = 0;

	GetClientRect(hWnd, &rt);
	switch (message) 
	{
		case WM_CREATE:
			SetTimer(hWnd,IDT_TIMER1, 20, (TIMERPROC)NULL);
		break;
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				break;
				case IDM_RUN:
					band = TRUE;
				break;
				case IDM_STOP:
					band = FALSE;
					
				break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
		break;
		case WM_TIMER:
			if(band)
			{
				
				switch(dir)
				{
					/*case 0: //Derecha
						if(xPos+100 <= rt.right)
							xPos+=PASO;
						else
						{
							xPos = rt.right-100;
							dir = 1;
							Beep(200,20);
						}
					break;
					case 1: //Izquierda
						if(xPos >= rt.left)
							xPos-=PASO;
						else
						{
							xPos = 0;
							dir = 0;
						}
					break;
					*/
					case 0:
						if(xPos+100 <= rt.right){
							xPos+=PASO;	
						}
						else{
							xPos-=PASO;
							dir = 3;
						}
						if(yPos >= rt.top){
							yPos -= PASO;
						}
						else{
							yPos +=PASO;
							dir = 1;
						}
					break;
					case 1:
						if(xPos+100 <= rt.right){
							xPos+=PASO;
						}
						else{
							xPos-=PASO;
							dir = 2;
						}
						if(yPos+100 <= rt.bottom){
							yPos+=PASO;
						}
						else{
							yPos-=PASO;
							dir = 0;
						}
					break;
					case 2:
						if(xPos >= rt.left){
							xPos -= PASO;
						}
						else{
							xPos += PASO;
							dir = 1;

						}
						if(yPos+100 <= rt.bottom){
							yPos += PASO;
						}
						else{
							yPos -= PASO;
							dir = 3;
						}
					break;
					case 3:
						if(xPos >= rt.left){
							xPos-=PASO;
						}
						else{
							xPos+=PASO;
							dir = 0;
						}
						if(yPos >= rt.top){
							yPos -=PASO;
						}
						else{
							yPos += PASO;
							dir = 2;
						}
					break;
				}
				InvalidateRect(hWnd, &rt, TRUE);
			
			}
		break;

		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			if(band)
			{
				Ellipse(hdc,xPos,yPos,xPos+100,yPos+100);
			}
			else
			{
				Ellipse(hdc,100,100,200,200);
			}
			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
			EndPaint(hWnd, &ps);
		break;
		case WM_DESTROY:
			KillTimer(hWnd, IDT_TIMER1);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
