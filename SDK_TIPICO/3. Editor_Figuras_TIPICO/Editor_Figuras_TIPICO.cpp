// Editor_Figuras_TIPICO.cpp : Defines the entry point for the application.
//

/*************************************************************************
 * Nombre:			Hector Andrey Hernandez Alonso
 * Fecha:			24 de Agosto del 2017 - 31 de Agosto del 2017
 * Proyecto:		Editor Figuras TIPICO
 * Funcionalidad: 
 * Metodos:			SetROP2, CreatePen, CreateSolidBrush, CreateHatchBrush,
 *					MoveToEx, LineTo.					
 * Handles:
 * Mensajes:		HPEN, HBRUSH.
 * Tipos:			COLORREF.
 * Estructuras: 
 ************************************************************************/

#include "stdafx.h"
#include "resource.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text
int figura = 0;
int penStyle = PS_SOLID;
int penWidth = 1;
COLORREF colorPluma = RGB(0, 0, 0);
COLORREF colorFondo = RGB(255, 255, 255);
BOOL bandFinal = FALSE;
int brushStyle = HS_BDIAGONAL;
COLORREF colorBrocha = RGB(255, 255, 255);
int solido = 1;



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
	LoadString(hInstance, IDC_EDITOR_FIGURAS_TIPICO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_EDITOR_FIGURAS_TIPICO);

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
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_EDITOR_FIGURAS_TIPICO);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);     // Usar 1 como default
	wcex.lpszMenuName	= (LPCSTR)IDC_EDITOR_FIGURAS_TIPICO;
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


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	RECT rt;
	GetClientRect(hWnd, &rt);
	static int xPos2, yPos2, xPos1, yPos1;
	static BOOL band = FALSE;
	HPEN penNew, penOld;
	HBRUSH brushNew,brushOld;



	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				break;
			//~~~~~~~~~FIGURAS~~~~~~~~~~
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
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				break;
				//Colores Pluma
				case IDM_RED_P:
					colorPluma = RGB(255, 0, 0);
				break;
				case IDM_GREEN_P:
					colorPluma = RGB(0, 255, 0);
				break;
				case IDM_BLUE_P:
					colorPluma = RGB(0, 0, 255);
				break;
				case IDM_BLACK_P:
					colorPluma = RGB(0, 0, 0);
				break;
		//~~~~~~~~Ancho Linea~~~~~~~~~~~~~~~~~~~~
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
				//Pen Style
				case IDM_PS_SOLID:
					penStyle = PS_SOLID;
				break;
				case IDM_PS_DASH:
					penStyle = PS_DASH;
				break;
				case IDM_PS_DOT:
					penStyle = PS_DOT;
				break;
				case IDM_PS_DASHDOT:
					penStyle = PS_DASHDOT;
				break;
				case IDM_PS_NULL:
					penStyle = PS_NULL;
				break;
				case IDM_PS_INSIDEFRAME:
					penStyle = PS_INSIDEFRAME;
				break;
				case IDM_SOLIDO:
					solido = !solido;
				break;
				//Brush Style
				case IDM_HS_BDIAGONAL:
					brushStyle = HS_BDIAGONAL;
				break;
				case IDM_HS_CROSS:
					brushStyle = HS_CROSS;
				break;
				case IDM_HS_DIAGCROSS:
					brushStyle = HS_DIAGCROSS;
				break;
				case IDM_HS_FDIAGONAL:
					brushStyle = HS_FDIAGONAL;
				break;
				case IDM_HS_HORIZONTAL:
					brushStyle = HS_HORIZONTAL;
				break;
				case IDM_HS_VERTICAL:
					brushStyle = HS_VERTICAL;
				break;
				//Colores BROCHA
				case IDM_RED_B:
					colorBrocha = RGB(255, 0, 0);
				break;
				case IDM_GREEN_B:
					colorBrocha = RGB(0, 255, 0);
				break;
				case IDM_BLUE_B:
					colorBrocha = RGB(0, 0, 255);
				break;
				case IDM_BLACK_B:
					colorBrocha = RGB(0, 0, 0);
				break;
				case IDM_FUCSIA_B:
					colorBrocha = RGB(134, 116, 220);
				break;

				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
		break;

		case WM_PAINT:		
			hdc = BeginPaint(hWnd, &ps);
			if(band)
			{	
				SetROP2(hdc, R2_NOTXORPEN);
				penNew = CreatePen(penStyle, penWidth, colorPluma); //Pinta
				brushNew = CreateSolidBrush(colorBrocha);
				if(solido)
				{
					brushNew = CreateSolidBrush(colorBrocha);
				}
				else
				{
					brushNew = CreateHatchBrush(brushStyle, colorBrocha);
				}

				penOld = (HPEN)SelectObject(hdc, penNew);
				brushOld = (HBRUSH)SelectObject(hdc, brushNew);
				switch(figura)
				{				
					case 1: //Rectangle
						Rectangle(hdc,xPos1, yPos1, xPos2, yPos2);
					break;			
					case 2: //Ellipse
						Ellipse(hdc,xPos1, yPos1, xPos2, yPos2);
				    break;
					case 3://RoundRect
						RoundRect(hdc,xPos1, yPos1, xPos2, yPos2, 30, 30);
					break;
					case 4: //Line  --> Primero va MoveToEx y Despues LineTo						
						MoveToEx(hdc,xPos1, yPos1,NULL);
						LineTo(hdc, xPos2, yPos2);	
					break;
					case 5: //FreeHand
						MoveToEx(hdc,xPos1, yPos1,NULL);
						LineTo(hdc, xPos2, yPos2);
						LineTo(hdc, xPos2, yPos2);
						xPos1 = xPos2;
						yPos1 = yPos2;
						//SetPixel(hdc,xPos1,yPos1, colorPluma);
					break;
				}
				SelectObject(hdc,penOld);
				SelectObject(hdc, brushOld);
				Sleep(20);
				penNew = CreatePen(penStyle, penWidth, colorPluma); //Borra
				if(solido)
				{
					brushNew = CreateSolidBrush(colorBrocha);
				}
				else
				{
					brushNew = CreateHatchBrush(brushStyle, colorBrocha);
				}
			//	brushNew = CreateSolidBrush(colorBrocha);
				penOld = (HPEN)SelectObject(hdc, penNew);
				brushOld = (HBRUSH)SelectObject(hdc, brushNew);
				switch(figura)
				{				
					case 1: //Rectangle
						Rectangle(hdc,xPos1, yPos1, xPos2, yPos2);
					break;					
					case 2: //Ellipse
						Ellipse(hdc,xPos1, yPos1, xPos2, yPos2);
				    break;
					case 3://RoundRect
						RoundRect(hdc,xPos1, yPos1, xPos2, yPos2, 30, 30);
					break;
					case 4: //Line  --> Primero va MoveToEx y Despues LineTo						
						MoveToEx(hdc,xPos1, yPos1,NULL);
						LineTo(hdc, xPos2, yPos2);	
					break;
					case 5: //FreeHand
					//	MoveToEx(hdc,xPos1, yPos1,NULL);
					//	LineTo(hdc, xPos2, yPos2);
					//	LineTo(hdc, xPos2, yPos2);
					//	SetPixel(hdc,xPos1,yPos1, colorPluma);
					break;
				}
				SelectObject(hdc,penOld);
				SelectObject(hdc, brushOld);
			}
			else // Pinta por ultima vez
			{
				if(bandFinal)
				{
						penNew = CreatePen(penStyle, penWidth, colorPluma); //Pinta
						brushNew = CreateSolidBrush(colorBrocha);
						if(solido)
						{
							brushNew = CreateSolidBrush(colorBrocha);
						}
						else
						{
							brushNew = CreateHatchBrush(brushStyle, colorBrocha);
						}
						penOld = (HPEN)SelectObject(hdc, penNew);
						brushOld = (HBRUSH)SelectObject(hdc, brushNew);
						switch(figura){				
								case 1: //Rectangle
									Rectangle(hdc,xPos1, yPos1, xPos2, yPos2);
								break;								
								case 2: //Ellipse
									Ellipse(hdc,xPos1, yPos1, xPos2, yPos2);
								break;
								case 3://RoundRect
									RoundRect(hdc,xPos1, yPos1, xPos2, yPos2, 30, 30);
								break;
								case 4: //Line  --> Primero va MoveToEx y Despues LineTo
									MoveToEx(hdc,xPos1, yPos1,NULL);
									LineTo(hdc, xPos2, yPos2);	
								break;
								case 5: //FreeHand
							//		MoveToEx(hdc,xPos1, yPos1,NULL);
							//		LineTo(hdc, xPos2, yPos2);	
							//		LineTo(hdc, xPos2, yPos2);
							//		SetPixel(hdc,xPos1,yPos1, colorPluma);
								break;
						}
						SelectObject(hdc,penOld);
					}
					bandFinal = FALSE;
				}
				EndPaint(hWnd, &ps);	
		break;
		case WM_LBUTTONDOWN:
			xPos1 = LOWORD(lParam); // Posicion Horizontal del Cursor
			yPos1 = HIWORD(lParam); // Posicion Vertical del Cursor
			//band = TRUE;
		//	InvalidateRect(hWnd, &rt, FALSE); // cleardevice()
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
				xPos2 = LOWORD(lParam); // Posicion Horizontal del Cursor
				yPos2 = HIWORD(lParam); // Posicion Vertical del Cursor
				band = FALSE;
				bandFinal = TRUE;
				InvalidateRect(hWnd, &rt, FALSE); // cleardevice()
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
