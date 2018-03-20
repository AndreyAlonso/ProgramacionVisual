; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CConjuntosView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Conjuntos.h"
LastPage=0

ClassCount=8
Class1=CConjuntosApp
Class2=CConjuntosDoc
Class3=CConjuntosView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_COMPLEMENTO
Resource4=IDR_TOOLBAR1
Class6=CCajaComplemento
Resource5=IDD_ABOUTBOX (Spanish (Modern))
Resource6=IDR_MENU1
Class7=CCajaInter
Class8=CCajaUnion
Resource7=IDD_INTER
Resource8=IDD_UNION
Resource9=IDR_MAINFRAME (Spanish (Modern))

[CLS:CConjuntosApp]
Type=0
HeaderFile=Conjuntos.h
ImplementationFile=Conjuntos.cpp
Filter=N

[CLS:CConjuntosDoc]
Type=0
HeaderFile=ConjuntosDoc.h
ImplementationFile=ConjuntosDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CConjuntosView]
Type=0
HeaderFile=ConjuntosView.h
ImplementationFile=ConjuntosView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDM_CREAR


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Conjuntos.cpp
ImplementationFile=Conjuntos.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
CommandCount=13
Command4=ID_EDIT_UNDO
Command13=ID_PREV_PANE


[TB:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME (Spanish (Modern))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_ABOUTBOX (Spanish (Modern))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COMPLEMENTO]
Type=1
Class=CCajaComplemento
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1344339969
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COMBO2,combobox,1344339969
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_COMPLEMENTO,button,1342242816

[CLS:CCajaComplemento]
Type=0
HeaderFile=CajaComplemento.h
ImplementationFile=CajaComplemento.cpp
BaseClass=CDialog
Filter=C
LastObject=IDC_COMBO2
VirtualFilter=dWC

[DLG:IDD_UNION]
Type=1
Class=CCajaUnion
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_COMBO1,combobox,1344340225
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO2,combobox,1344340225
Control7=IDC_STATIC,static,1342308352
Control8=IDC_UNION,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_COMBO3,combobox,1344340225
Control11=IDC_STATIC,static,1342308352

[DLG:IDD_INTER]
Type=1
Class=CCajaInter
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_COMBO1,combobox,1344340225
Control5=IDC_COMBO2,combobox,1344340225
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_INTER,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_COMBO3,combobox,1344340225
Control11=IDC_STATIC,static,1342308352
Control12=IDC_BUTTON2,button,1342242816

[CLS:CCajaInter]
Type=0
HeaderFile=CajaInter.h
ImplementationFile=CajaInter.cpp
BaseClass=CDialog
Filter=D
LastObject=IDM_ASIGNACION
VirtualFilter=dWC

[CLS:CCajaUnion]
Type=0
HeaderFile=CajaUnion.h
ImplementationFile=CajaUnion.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO3
VirtualFilter=dWC

[MNU:IDR_MENU1]
Type=1
Class=CConjuntosView
Command1=IDM_CREAR
Command2=IDM_ASIGNACION
Command3=IDM_UNION
Command4=IDM_INTERSECCION
CommandCount=4

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=IDM_CREAR
Command2=IDM_ASIGNACION
Command3=IDM_UNION
Command4=IDM_INTERSECCION
CommandCount=4

