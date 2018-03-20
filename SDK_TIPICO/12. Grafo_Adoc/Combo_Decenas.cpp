/*************************************************************************
 * Nombre:			Hector Andrey Hernandez Alonso
 * Fecha:			25 de Septiembre del 2017
 * Proyecto:		Grafos
 * Funcionalidad:	
 * Metodos:														
 * Handles:
 * Mensajes:	
 * Tipos:			
 * Estructuras: 
 ************************************************************************/

/****************************** Bibliotecas *****************************/
#include "stdafx.h"
#include "resource.h"
#include "Combo_Decenas.h"


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define MAX_LOADSTRING 100

/************************* Variables Globales ***************************/
HINSTANCE hInst;								
TCHAR szTitle[MAX_LOADSTRING];		
TCHAR szWindowClass[MAX_LOADSTRING];
NP *grafo, *corre;
BOOL band = FALSE;
NR *nr;
NP *np, *_np;
HDC hdc;
int numCombos = 0;
RECT rtMarco;
int tamDLG;
RECT rtDlg;



/********************************* Declaracion de Prototipos *************************/
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT				CALLBACK Combo(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


void Ini();
void insertaColaNP(NP *c2, NP *np);
//NP *Busca_Dec(int d);
void inserta_OrdenadoNP(NP *np);
void insertaColaNR(NP *c3, NR *nr);
void insertaColaNR(NR *c3, NR *nr);
void inserta_OrdenadoNR(NP *np, NR *nr);
void imprimeGrafo(HDC hdc);
NP *creaNodoNP(char n);
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
//	int numeros;
	//int i;
	static char name = 'A';
	int x = 100, y = 5;
	NP *c1, *c2;
	NR *c3;
	
	
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
		//			imprimeLista(hdc);
					ReleaseDC(hWnd,hdc);
				break;
				case IDM_LL:
					Ini();
					//Crea A y sus relaciones 
					np = creaNodoNP(name);
					c1 = c2 = np;
					nr = creaNodoNR(5);
					np->abajo = nr; //La primer relacion de A 
					nr->arriba = np;
					insertaColaNP(c2, np);
					//Crear B y ligarlo a A
					name++;
					c3 = nr;
					np = creaNodoNP(name);	
					nr = creaNodoNR(10);
					nr->arriba = np;
					insertaColaNR(c3, nr);
					c2->sig = np; //Se enlaza A con B 
					c2 = np;
					//Crear C y ligarlo a B
					name++;
					c3 = nr;
					np = creaNodoNP(name);	
					nr = creaNodoNR(20);
					nr->arriba = np;
					insertaColaNR(c3, nr);
					c2->sig = np; //Se enlaza B con C 
					c2 = np;

					// Relaciones de B: Regresa c2(A) y avanza c1(B)
					c2 = grafo; 
					c1 = c1->sig;
					nr = creaNodoNR(30);
					c2 = c2->sig;  //Avanza c2 hacia B y
					c2 = c2->sig; // despues a C porque es la unica relacion de B 
					nr->arriba = c2; // c2 está en C
					c1->abajo = nr; //La primer relacion
					// Relaciones de C: avanza c1(C) y regresa c2(A)
					c2 = grafo; 
					c1 = c1->sig;// Esta en C
					nr = creaNodoNR(40);
					c2 = c2->sig;  //Avanzo a B
					nr->arriba = c2; // c2 está en B
					c1->abajo = nr;

					band = TRUE;
					InvalidateRect(hWnd,&rt, TRUE);					
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
			if(band)
			{
				imprimeGrafo(hdc);
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
	grafo = NULL;
}



LRESULT CALLBACK Combo(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	char cad[4];
	static HWND hCombo;
	int x = 100;
//	int tamCombo = 60, espCombo,i;
	NR *c2;
	NP *c1;
	int idCombo;
//	int posCombo;

	switch (message)
	{
		case WM_INITDIALOG:
			
		break;
		case WM_COMMAND:	
			
			switch(LOWORD(wParam))
			{
				case IDC_ACCION:
					c1 = grafo;
					while(c1)
					{
						itoa(c1->nombre, cad, 10);
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
					numCombos = 0;
					InvalidateRect(hDlg,&rtMarco,TRUE);
				case IDCANCEL:
					EndDialog(hDlg, LOWORD(wParam));
				break;
			}			
			//	return TRUE;
		break;
	}
    return FALSE;
}

NP *creaNodoNP(char n)
{
    NP *nodo = new NP;
    nodo->nombre = n;
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
	nodo->arriba = NULL;

    return nodo;
}
void insertaColaNP(NP *c2, NP *np)
{
	
	if(!grafo){	//Verifica si el grafo esta vacio
		grafo = np;
	}
	else{
		c2->sig = grafo;
	}

}

void insertaColaNR(NR *c3, NR *nr)
{
	c3->sig = nr;
}

void imprimeGrafo(HDC hdc)
{
    NP *c1, *c2;
    NR *c3 = NULL;
    int x = 100, y = 100;
    char cad[5] = {'\0'};
	char cad1[5] = {'\0'};
    int tam1, tam2;

	c1 = c2 = grafo;
    while(c2)
	{
		cad[1] = '\0';
		cad1[1] ='\0';
		x = 100;
	
		//	Lista Vertices
		 cad[0] =+ (char)c2->nombre;
    //   itoa(c2->nombre, cad, 10);
		strcat(cad,": "); 
		tam1 = strlen(cad);
		x = x + tam1;
        TextOut(hdc, x, y, cad, tam1);
        c3 = c2->abajo;
		x = x+tam1*10;
        while(c3)
		{
			//Lista Aristas
           itoa(c3->num, cad, 10);
		   strcat(cad, "_");
		   //itoa(c3->arriba->nombre, cad1,10);
		   //strcat(cad, cad1);
		   strcat(cad, "_");
		   cad[3] =+ (char)c3->arriba->nombre;
		   
           strcat(cad, "->");   //A: 5_A-> 20_B->
		   tam2 = strlen(cad);
		   TextOut(hdc,x+=tam1*20, y , cad, tam2);
           c3 = c3->sig;
		 //  TextOut(hdc,x+=tam1*20,y,"NULL",tam2);
        }
		TextOut(hdc,x+=tam1*20,y,"NULL",tam2);
       y += 20;
       x = 100;

        c2 = c2->sig;
    }
	TextOut(hdc,x,y,"NULL", tam2);
	
}

/*void inserta_OrdenadoNP(NP *np)
{	int i = 0;
	NP *aux;
	if(!grafo || grafo->nombre > np->nombre){
		np->sig = grafo;
		grafo = np;
	}
	else{
		aux = grafo;
		if(aux && aux->nombre < np->nombre)
		{
			while(aux->sig)
			{
				if(aux->sig->nombre > np->nombre)
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
*/

/**************************************************************************************************/

/*
NP * Busca_Dec(int d)
{
    NP *cc = grafo;
    while(cc)
	{
		if(cc->nombre != d){
			cc = cc->sig;
        }
        else{
            break;
        }
    }
    return cc;
}



void inserta_OrdenadoNR(NP *np, NR *nr)
{	
	NR *c2;
	
	if( !(np->abajo) || np->nombre < nr->num)
	{
		nr->sig = np->abajo;
		np->abajo = nr;
	}
	else
	{
		c2 = (NR*)(np);
		if(c2->num < nr->num)
		{
			while(c2->sig)
			{
				if(c2->sig->num > nr->num)
				   break;
				c2 = c2->sig;
			}
		}
		if(!(c2->sig))
		{
			nr->sig = c2->sig;
			c2->sig = nr;
		}
		else
		{
			nr->sig = c2->sig;
			c2->sig = nr;
		}
	}
}



// Funcion  crea nodo principal


*/