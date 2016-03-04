; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFfView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ff.h"
LastPage=0

ClassCount=8
Class1=CFfApp
Class2=CFfDoc
Class3=CFfView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CTipDlg
Class7=Tip
Resource3=IDD_TIP_DIALOG
Class8=Tip2
Resource4=IDD_DIALOG1

[CLS:CFfApp]
Type=0
HeaderFile=Ff.h
ImplementationFile=Ff.cpp
Filter=N

[CLS:CFfDoc]
Type=0
HeaderFile=FfDoc.h
ImplementationFile=FfDoc.cpp
Filter=N

[CLS:CFfView]
Type=0
HeaderFile=FfView.h
ImplementationFile=FfView.cpp
Filter=C
LastObject=CFfView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Ff.cpp
ImplementationFile=Ff.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_GAME_START
Command2=ID_GAME_PAUSE
Command3=ID_GAME_OVER
Command4=ID_GAME_RESTART
Command5=ID_APP_EXIT
Command6=ID_LEVEL_NO1
Command7=ID_LEVEL_NO2
Command8=ID_LEVEL_HIGH
Command9=ID_FILE_MUSIC
Command10=ID_APP_ABOUT
CommandCount=10

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_GAME_START
Command2=ID_GAME_PAUSE
Command3=ID_GAME_OVER
Command4=ID_GAME_RESTART
Command5=ID_LEVEL_NO1
Command6=ID_LEVEL_NO2
Command7=ID_LEVEL_HIGH
Command8=ID_APP_ABOUT
Command9=ID_FILE_MUSIC
CommandCount=9

[DLG:IDD_TIP_DIALOG]
Type=1
Class=CTipDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352

[CLS:CTipDlg]
Type=0
HeaderFile=TipDlg.h
ImplementationFile=TipDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CTipDlg

[CLS:Tip]
Type=0
HeaderFile=Tip.h
ImplementationFile=Tip.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT

[DLG:IDD_DIALOG1]
Type=1
Class=Tip2
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177283
Control3=IDC_STATIC,static,1342308480
Control4=IDC_STATIC,static,1342308352

[CLS:Tip2]
Type=0
HeaderFile=Tip2.h
ImplementationFile=Tip2.cpp
BaseClass=CDialog
Filter=D

