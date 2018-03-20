// Botones_Tipico.cpp : Defines the entry point for the application.
//

/*************************************************************************
 * Nombre:			Hector Andrey Hernandez Alonso
 * Fecha:			04 de Semptiembre del 2017
 * Proyecto:		Botones Tipico.
 * Funcionalidad:	Manipulacion de Atributos de los controles.
 * Metodos:			GetDlgItem, MoveWindow, EnableWindow, SetWindowPos,
 *					SendMessage.
 * Handles:
 * Mensajes:		BM_SETSTATE.		
 * Tipos:			
 * Estructuras: 
 ************************************************************************/
#include "stdafx.h"
#include "resource.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	Botones(HWND, UINT, WPARAM, LPARAM);


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
	LoadString(hInstance, IDC_BOTONES_TIPICO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_BOTONES_TIPICO);

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

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_BOTONES_TIPICO);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_BOTONES_TIPICO;
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
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

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



	GetClientRect(hWnd, &rt);
	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				  // DialogBox(hInst, (LPCTSTR)IDD_About, hWnd, (DLGPROC)About);
				break;
				case IDM_BOTONES:
					DialogBox(hInst, (LPCTSTR)IDD_BOTONES, hWnd, (DLGPROC)Botones);
				break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);

			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}
LRESULT CALLBACK Botones(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
//	char cad1[6], cad2[6];
	static HWND hNuevo, hBuild, hRebuild, hHide, hMove, hResize, hPush;
	static int Posx = 119, Posy = 73, ancho = 100, alto = 100;



	switch (message)
	{
		case WM_INITDIALOG:
			 hNuevo = CreateWindow("BUTTON", "Nuevo", WS_CHILD,//|WS_VISIBLE,
									Posx, Posy, ancho, alto, hDlg,(HMENU)IDC_NUEVO,
									hInst, NULL);

			hBuild   = GetDlgItem(hDlg, IDC_BUILD);
			hNuevo   = GetDlgItem(hDlg, IDC_NUEVO);
			hRebuild = GetDlgItem(hDlg, IDC_REBUILD);
			hHide    = GetDlgItem(hDlg, IDC_HIDE);
			hMove    = GetDlgItem(hDlg, IDC_MOVE);
			hResize  = GetDlgItem(hDlg, IDC_RESIZE);
			hPush	 = GetDlgItem(hDlg, IDC_PUSH);
			
		break;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDC_BUILD:
					ShowWindow(hNuevo, SW_SHOWNORMAL);
					ShowWindow(hBuild, SW_HIDE);
					ShowWindow(hHide, SW_SHOWNORMAL);
					ShowWindow(hMove, SW_SHOWNORMAL);
					ShowWindow(hResize, SW_SHOWNORMAL);
					ShowWindow(hPush, SW_SHOWNORMAL);	
					MoveWindow(hNuevo,Posx, Posy, ancho, alto , TRUE);
				break;
				case IDC_HIDE:
					ShowWindow(hNuevo, SW_HIDE);
					ShowWindow(hRebuild, SW_SHOWNORMAL);
					EnableWindow(hHide,FALSE);
				break;
				case IDC_REBUILD:
					ShowWindow(hNuevo, SW_SHOWNORMAL);
					ShowWindow(hRebuild, SW_HIDE);
					EnableWindow(hHide,TRUE);
					EnableWindow(hMove,TRUE);
					EnableWindow(hResize,TRUE);
					EnableWindow(hPush,TRUE);
					MoveWindow(hNuevo,Posx, Posy, ancho, alto , TRUE);
					SendMessage(hNuevo,BM_SETSTATE, 0, 0);	
				break;
				case IDC_MOVE:
					ShowWindow(hRebuild, SW_SHOWNORMAL);
					MoveWindow(hNuevo,Posx+150, Posy+60, ancho, alto , TRUE);
					EnableWindow(hMove,FALSE);
				break;
				case IDC_RESIZE: 
					SetWindowPos(hNuevo, HWND_NOTOPMOST, Posx-40, Posy-40, ancho+100, alto+100, SWP_NOZORDER);
					EnableWindow(hResize,FALSE);
					ShowWindow(hRebuild, SW_SHOWNORMAL);
				break;
				case IDC_PUSH:
					SendMessage(hNuevo,BM_SETSTATE, 1, 0);
					ShowWindow(hRebuild, SW_SHOWNORMAL);
					EnableWindow(hPush,FALSE);
				break;
				case IDOK:
				case IDCANCEL:
					EndDialog(hDlg, LOWORD(wParam));
				break;
			}			
			//	return TRUE;
		break;
	}
    return FALSE;
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