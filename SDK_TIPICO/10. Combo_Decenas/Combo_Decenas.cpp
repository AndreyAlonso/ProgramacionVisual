/*************************************************************************
 * Nombre:			Hector Andrey Hernandez Alonso
 * Fecha:			13 de septiembre - 24 de septiembre 2017
 * Proyecto:		Combo Decenas
 * Funcionalidad:	Lista de Listas en combos dinamicos.
 * Metodos:					
 * Handles:
 * Mensajes:				
 * Tipos:			
 * Estructuras: 
 ************************************************************************/


/************************************* Bibliotecas **************************************************/
#include "stdafx.h"
#include "resource.h"
#include "Combo_Decenas.h"


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define MAX_LOADSTRING 100

/************************************ Variables Globales ********************************/
HINSTANCE hInst;								
TCHAR szTitle[MAX_LOADSTRING];		
TCHAR szWindowClass[MAX_LOADSTRING];
NP *lista, *corre;
BOOL band = FALSE;
NR *nr;
NP *np, *_np;
HDC hdc;
int numCombos = 0;
RECT rtMarco;
int tamDLG;
RECT rtDlg;

HWND hCombo;
int ancho = 1024;
int alto = 600;


/********************************* Declaracion de Prototipos *************************/
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT				CALLBACK Combo(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


void Ini();
NP *Busca_Dec(int d);
void inserta_OrdenadoNP(NP *np);
void inserta_OrdenadoNR(NP *np, NR *nr);
void imprimeLista(HDC hdc);
NP *creaNodoNP(int n);
NR *creaNodoNR(int n);

/*******************************************************************************************/
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_COMBO_DECENAS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);


	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_COMBO_DECENAS);

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
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_COMBO_DECENAS);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_COMBO_DECENAS;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance;

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0,CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

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
	
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	RECT rt;
	int numeros, i, nn, d;
	int x = 100, y = 5;
	
	
	GetClientRect(hWnd, &rt);


	switch (message) 
	{
		case WM_CREATE:

		break;
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
		
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				break;
				case IDM_COMBOS:
				DialogBox(hInst, (LPCTSTR)IDD_COMBO, hWnd, (DLGPROC)Combo);
				break;
				case IDM_IMPRIME:
					hdc = GetDC(hWnd);
					imprimeLista(hdc);
					ReleaseDC(hWnd,hdc);
				break;
				case IDM_LL:
					srand((unsigned) time( NULL )); //Semilla del rand()
					Ini(); // Inicializa la lista 
				//	numeros = rand()%50 +rand()%25 + rand()%25;
				//	numeros = rand()%50 +rand()%25;
					numeros = rand()%50+1;
					numCombos = 0;
					InvalidateRect(hWnd,&rt,TRUE);
					for(i= 0; i < numeros; i++)
					{	
						nn = rand()%98+1;
						d = nn/10*10; // Obtiene la decena de un numero, ejemplo: 15 su decena es 10
						if( !(_np = Busca_Dec(d)) )
						{
							if(d == nn)
							{
								nn++;
							}
							np = creaNodoNP(d); // Inicializa y crea al nodo
							nr = creaNodoNR(nn);
							inserta_OrdenadoNR(np,nr);
							inserta_OrdenadoNP(np);	
							numCombos++;
						}
						else
						{
							nr = creaNodoNR(nn);
							inserta_OrdenadoNR(_np,nr);
							
						}
						
					}
				
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



LRESULT CALLBACK Combo(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	char cad[4];

	int x = 100;
	int tamCombo = 60, espCombo,i;
	NR *c2;
	NP *c1;
	int idCombo;
	int posCombo;


	
	

	switch (message)
	{
		
		case WM_INITDIALOG:
			
			GetWindowRect(hDlg, &rtMarco);
			GetClientRect(hDlg, &rtDlg);

			tamDLG = rtDlg.right+6;//t-(rtMarco.right-rtMarco.left); // Inicia en Cero
			
			c1 = lista;
		
			espCombo = (tamDLG - (tamCombo * numCombos))/(numCombos+1);
			for(i = 0; i < numCombos; i++)
			{
				
				
				posCombo = (i*tamCombo+espCombo*i)+espCombo;
				hCombo = CreateWindow( "COMBOBOX", 
										0, //Apuntador a el nombre de ventana
										CBS_SIMPLE |WS_CHILD |WS_VISIBLE|WS_VSCROLL, 
										posCombo,// Posicion Horizontal
										10,  // Posicion vertical
										tamCombo, //Ancho
										160, //Alto de la ventana
										hDlg, 
										(HMENU)IDC_NUEVO+i,
										hInst,
										NULL
									);
				
			
				c1->hCombo = hCombo;
				c1 = c1->sig;
			
				
			}
				
		//	UpdateWindow(hVentana);
		//		ShowWindow(hVentana, SW_SHOWNORMAL);

			
				
		
				
		break;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDC_ACCION:
					c1 = lista;
					
					while(c1)
					{
						itoa(c1->dec, cad, 10);
						idCombo = GetDlgCtrlID(c1->hCombo); 
						SetDlgItemText(hDlg,idCombo,(LPCTSTR)cad); // Para la decena en el Edit del Combo
						c2 = c1->abajo;
						while(c2)
						{
							itoa(c2->num, cad, 10);
							//Para el numero que va en la lista de Combo
							SendMessage(c1->hCombo, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)cad);
							c2 = c2->sig;		
						}
						c1 = c1->sig;						
					}
			
					
					
				
					
				//	SendDlgItemMessage(hDlg, IDC_NUEVO,CB_SETCURSEL,0,0);	
					
					
				break;
				case IDOK:		
				case IDCANCEL:
					numCombos = 0;
					InvalidateRect(hDlg,&rtMarco,TRUE);
					InvalidateRect(hDlg,&rtDlg,TRUE);
					
					EndDialog(hDlg, LOWORD(wParam));	
				break;
			}			
			//	return TRUE;
		break;
	}
    return FALSE;
}

/**************************************************************************************************/
NP * Busca_Dec(int d)
{
    NP *cc = lista;
    while(cc)
	{
		if(cc->dec != d){
			cc = cc->sig;
        }
        else{
            break;
        }
    }
    return cc;
}

void inserta_OrdenadoNP(NP *np)
{	NP *aux;
	if(!lista || lista->dec > np->dec){
		np->sig = lista;
		lista = np;
	}
	else{
		aux = lista;
		if(aux && aux->dec < np->dec)
		{
			while(aux->sig)
			{
				if(aux->sig->dec > np->dec)
				{
				   break;
                }
				aux = aux->sig;
			}
		}
		if(!(aux->sig))
		{
			np->sig = aux->sig;
			aux->sig = np;
		}
		else
		{
				np->sig = aux->sig;
				aux->sig = np;
		}
	}
}

void inserta_OrdenadoNR(NP *np, NR *nr)
{	
	NR *c2;
	
	if( !(np->abajo) || np->abajo->num > nr->num){ //>
		nr->sig = np->abajo;
		np->abajo = nr;
	}
	else{
		c2 = (NR*)(np->abajo);
		
		if(c2->num <= nr->num) {
			while(c2->sig)
			{
				if(c2->sig->num > nr->num)   // > 
				   break;
				else if(c2->num == nr->num)   // > 
				   c2 = c2->sig;
				
			

				c2 = c2->sig;
			}


			
		}
		if(!(c2->sig))
		{
			if(c2->num != nr->num){
				nr->sig = c2->sig;
				c2->sig = nr;
			}
		}
		else
		{
			if(c2->num != nr->num){
				nr->sig = c2->sig;
				c2->sig = nr;
			}
		}
		
		
	}
}

void imprimeLista(HDC hdc)
{
    NP *corre1 = lista;
    NR *corre2 = NULL;
    int x = 100, y = 100;
    char cad[5];
	char cad2[5];
    int tam;

    while(corre1)
	{
		//	Lista Principal
        itoa(corre1->dec, cad, 10);
        tam = strlen(cad);
        TextOut(hdc, x, y, cad, tam);
        corre2 = corre1->abajo;
        while(corre2)
		{
			//Lista Secundaria
           itoa(corre2->num, cad2, 10);
           tam = strlen(cad2);
           TextOut(hdc, x+=25, y , cad2, tam);
	
           corre2 = corre2->sig;
        }
        y += 20;
        x = 100;
        corre1 = corre1->sig;
    }
}

// Funcion  crea nodo principal
NP *creaNodoNP(int n)
{
    NP *nodo = new NP;
    nodo->dec = n;
    nodo->sig = NULL;
    nodo->abajo = NULL;
    return nodo;
}

// Funcion crea nodo relacion
NR *creaNodoNR(int n)
{

    NR *nodo = new NR;
    nodo->num = n;
    nodo->sig = NULL;
    return nodo;
}

