/*************************************************************************
 * Nombre:			Hector Andrey Hernandez Alonso
 * Fecha:			11 de septiembre - 24 de septiembre 2017
 * Funcionalidad:	Crea una lista y la inserta en un ComboBox.
 * Metodos:			SendMessage, SendDlgItemMessage, srand, rand		
 * Handles:
 * Mensajes:				
 * Tipos:			
 * Estructuras: 
 ************************************************************************/
//dec = numero * 10/100

#include "stdafx.h"
#include "resource.h"
#include "Lista_Num.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>



#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text
Nodo *lista, *nodo;
BOOL band = FALSE;
Nodo *corre;


// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void Ini();
Nodo* Crea_Nodo(int n);
void Crea_Lista(Nodo *n);
LRESULT CALLBACK Combo(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
void Inserta_OrdenadoNP(Nodo *np);

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
	LoadString(hInstance, IDC_LISTA_NUM, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);


	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_LISTA_NUM);

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
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_LISTA_NUM);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_LISTA_NUM;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}


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
	int numeros, i, nn;

	char cad[3];
	int x = 100, y = 5;

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
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				break;
				case IDM_COMBO:
					DialogBox(hInst, (LPCTSTR)IDD_COMBO, hWnd, (DLGPROC)Combo);
				break;
				case IDM_CREAR:
					srand( (unsigned)time( NULL ) ); //Semilla del rand()
					Ini();
					numeros = rand()%5+3;
					for(i= 0; i < numeros; i++)
					{
						nn = rand()%100;
						nodo = Crea_Nodo(nn);
						Crea_Lista(nodo);
					}
					band = TRUE;
					InvalidateRect(hWnd, &rt, TRUE);
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
			corre = lista;
			if(band)
			{
				while(corre)
				{
					itoa(corre->num, cad, 10);
					TextOut(hdc, x+=20, y, cad, 3);
					corre = corre->sig;
				}
			}
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


void Ini()
{
	lista = NULL;
}

Nodo* Crea_Nodo(int n)
{
	nodo = new Nodo;
	nodo->num = n;
	nodo->sig = NULL;
	return nodo;
}

void Crea_Lista(Nodo* n)
{
	n->sig = lista;
	lista = n;
		
}
LRESULT CALLBACK Combo(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	char cad[4];
	static HWND hCombo;

	switch (message)
	{
		case WM_INITDIALOG:
			hCombo = GetDlgItem(hDlg, IDC_COMBO1);
		break;
		case WM_COMMAND:	
			switch(LOWORD(wParam))
			{
				case IDC_ACCION:
				corre = lista;
				if(band)
				{
					while(corre)
					{
						itoa(corre->num, cad, 10);
						SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)cad);
						corre = corre->sig;
					}
					SendDlgItemMessage(hDlg, IDC_COMBO1,CB_SETCURSEL,1 ,0);
					}	
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


void Inserta_OrdenadoNP(Nodo *np)
{	
	Nodo *c1;

	if(!lista || lista->num < np->num)
	{
		np->sig = lista;
		lista = np;
	}
	else
	{
		c1 = lista;
		if(c1 && c1->num < np->num)
		{
			while(c1->sig)
			{
				if(c1->sig->num > np->num)
				   break;
				c1 = c1->sig;
			}
		}
		if(!(c1->sig))
		{
			np->sig = c1->sig;
			c1->sig = np;
		}
		else
		{
				np->sig = c1->sig;
				c1->sig = np;
		}
	}
}


