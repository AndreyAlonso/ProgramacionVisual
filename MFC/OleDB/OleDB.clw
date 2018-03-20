; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OleDB.h"
LastPage=0

ClassCount=9
Class1=COleDBApp
Class2=COleDBDoc
Class3=COleDBView
Class4=CMainFrame
Class6=COleDBSet
Class9=CAboutDlg

ResourceCount=10
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource7=IDD_OLEDB_FORM
Resource8=IDR_MAINFRAME (Spanish (Modern))
Resource9=IDD_ABOUTBOX (Spanish (Modern))
Resource10=IDD_OLEDB_FORM (Spanish (Modern))

[CLS:COleDBApp]
Type=0
HeaderFile=OleDB.h
ImplementationFile=OleDB.cpp
Filter=N

[CLS:COleDBDoc]
Type=0
HeaderFile=OleDBDoc.h
ImplementationFile=OleDBDoc.cpp
Filter=N

[CLS:COleDBView]
Type=0
HeaderFile=OleDBView.h
ImplementationFile=OleDBView.cpp
Filter=D


[CLS:COleDBSet]
Type=0
HeaderFile=OleDBSet.h
ImplementationFile=OleDBSet.cpp
Filter=N

[DB:COleDBSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[Id], 4, 4
Column2=[Campo1], 12, 510
Column3=[Nombre], 12, 510
Column4=[Campo3], 4, 4
Column5=[Campo4], 4, 4
Column6=[Campo2], 12, 510


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=OleDB.cpp
ImplementationFile=OleDB.cpp
Filter=D

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
Command11=ID_RECORD_FIRST
Command12=ID_RECORD_PREV
Command13=ID_RECORD_NEXT
Command14=ID_RECORD_LAST
Command15=ID_VIEW_TOOLBAR
CommandCount=17
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT

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

[DLG:IDD_OLEDB_FORM]
Type=1
Class=COleDBView

[DLG:IDD_OLEDB_FORM (Spanish (Modern))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

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
Command8=ID_RECORD_FIRST
Command9=ID_RECORD_PREV
Command10=ID_RECORD_NEXT
Command11=ID_RECORD_LAST
Command12=ID_APP_ABOUT
CommandCount=12

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
Command11=ID_RECORD_FIRST
Command12=ID_RECORD_PREV
Command13=ID_RECORD_NEXT
Command14=ID_RECORD_LAST
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
CommandCount=17

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
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

