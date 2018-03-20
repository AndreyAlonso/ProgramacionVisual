// PreEx1_Tipico_Pizarron.cpp : Defines the entry point for the application.
//
/*************************************************************************
 * Nombre:			Hector Andrey Hernandez Alonso
 * Fecha:			31 de Agosto del 2017 - 04 de Septiembre del 2017
 * Proyecto:		Pizarron Tipico.
 * Funcionalidad:	Simulacion de un pizarron de clase.
 * Metodos:			FloodFill.			
 * Handles:
 * Mensajes:	
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
COLORREF colorPluma = RGB(0, 153, 76);
BOOL bandFinal = FALSE;
int penWidth = 1;
int borrador = 0;



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
	LoadString(hInstance, IDC_PREEX1_TIPICO_PIZARRON, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_PREEX1_TIPICO_PIZARRON);

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
	wcex.style			= CS_HREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_PREEX1_TIPICO_PIZARRON);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= CreateSolidBrush(RGB(0,153,76));
	wcex.lpszMenuName	= (LPCSTR)IDC_PREEX1_TIPICO_PIZARRON;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, "Board", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	static int xPos1, yPos1, xPos2, yPos2;
	static BOOL band = FALSE;
	HPEN penNew, penOld;
	HBRUSH colorBorrador;
	RECT rt;
	
	GetClientRect(hWnd, &rt);


	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				break;
				//Opcion Pizarron -------------------------------------------------------------
				case IDM_CHALK:
					colorPluma = RGB(255, 255, 255);
					borrador = 0;
					penWidth = 1;
				break;
				case IDM_BORRADOR:
					
					borrador = 1;
				break;
				case IDM_Clear:
					InvalidateRect(hWnd, &rt, TRUE); 
				break;
				//Ancho de la Pluma------------------------------------------------------------
				case IDM_P1:
					penWidth = 1;
				break;
				case IDM_P2:
					penWidth = 2;
				break;
				case IDM_P3:
					penWidth = 3;
				break;
				case IDM_P4:
					penWidth = 4;
				break;
				case IDM_P5:
					penWidth = 5;
				break;
				//Color de la PLuma -----------------------------------
				case IDM_BLUE:
					colorPluma = RGB(102, 178, 255);
				break;
				case IDM_YELLOW:
					colorPluma = RGB(255, 255, 153);
				break;
				case IDM_PINK:
					colorPluma = RGB(255, 204, 204);
				break;
				case IDM_GREEN:
					colorPluma = RGB(102, 255, 178);
				break;
				case IDM_WHITE:
					colorPluma = RGB(255, 255, 255);
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
			if(borrador == 1)
			{
				penWidth = 30;	
				colorBorrador = CreateSolidBrush(RGB(0, 153, 76));
				SelectObject(hdc,colorBorrador);
				FloodFill(hdc, xPos1, yPos1, RGB(0, 153, 76));	
				
			}	
			
			if(band)
			{
				SetROP2(hdc, R2_COPYPEN);
				penNew = CreatePen(PS_SOLID, penWidth, colorPluma);
				penOld = (HPEN)SelectObject(hdc, penNew);
				MoveToEx(hdc,xPos1, yPos1,NULL);
				LineTo(hdc, xPos2, yPos2);
				LineTo(hdc, xPos2, yPos2);
		    	xPos1 = xPos2;
				yPos1 = yPos2;
				penNew = CreatePen(PS_SOLID, penWidth, colorPluma);
				SelectObject(hdc,penOld);
				SelectObject(hdc,colorBorrador);
				Sleep(20);
				penNew = CreatePen(PS_SOLID,penWidth,colorPluma);
				
			
			}
			else
			{
				if(bandFinal)
				{
					SetROP2(hdc, R2_COPYPEN);
					penNew = CreatePen(PS_SOLID, penWidth, colorPluma);
					penOld = (HPEN)SelectObject(hdc, penNew);
					MoveToEx(hdc,xPos1, yPos1,NULL);
					LineTo(hdc, xPos2, yPos2);
					LineTo(hdc, xPos2, yPos2);
					xPos1 = xPos2;
					yPos1 = yPos2;	
					penNew = CreatePen(PS_SOLID, penWidth, colorPluma);
					SelectObject(hdc,penOld);
					SelectObject(hdc,colorBorrador);
					Sleep(20);
					penNew = CreatePen(PS_SOLID,penWidth,colorPluma);
				}
				SelectObject(hdc,penOld);

			}
			bandFinal = FALSE;

		
			EndPaint(hWnd, &ps);
		break;
		case WM_LBUTTONDOWN:
			if(borrador == 1)
				{
					colorPluma = RGB(51, 25, 0);
					if(penWidth > 1 && penWidth <= 5)
					{
						colorPluma = RGB(0, 153, 76);
					}

				}
			
			xPos1 = LOWORD(lParam); 
			yPos1 = HIWORD(lParam); 
		break;
		case WM_MOUSEMOVE:
			if(MK_LBUTTON & wParam)
			{
				xPos2 = LOWORD(lParam); 
				yPos2 = HIWORD(lParam);
				band = TRUE;
				InvalidateRect(hWnd, &rt, FALSE); 
			}
		break;
		
		case WM_LBUTTONUP:
				if(borrador == 1)
				{
					colorPluma = RGB(0, 153, 76);	
					
				}
				xPos2 = LOWORD(lParam); 
				yPos2 = HIWORD(lParam); 
				band = FALSE;
				bandFinal = TRUE;	
				InvalidateRect(hWnd, &rt, FALSE);	
		break;
	
		case WM_DESTROY:
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
