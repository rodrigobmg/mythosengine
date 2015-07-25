; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=ToolView
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "eshtool.h"
LastPage=0

ClassCount=28
Class1=ScenePropGeneralPage
Class2=ScenePropMiscPage
Class3=CameraPropGeneralPage
Class4=CameraPropAppFlagsPage
Class5=CameraPropMiscPage
Class6=CameraPropExPage
Class7=LightPropGeneralPage
Class8=LightPropExtraPage
Class9=LightPropAppFlagsPage
Class10=MeshPropGeneralPage
Class11=MeshPropOrientPage
Class12=MeshPropExtPage
Class13=MeshPropAppFlagsPage
Class14=ToolDoc
Class15=ToolFrame
Class16=ToolApp
Class17=CAboutDlg
Class18=ToolTree
Class19=ToolView
Class20=ToolVPort

ResourceCount=23
Resource1=IDD_CAMPROP_GEN
Resource2=IDD_SNPROP_GEN
Resource3=IDD_LGTPROP_EXTRA
Resource4=IDD_TXTPROP_GEN
Resource5=IDD_TXTPROP_APPFLAGS
Resource6=IDD_CAMPROP_EX
Resource7=IDD_SNPROP_MISC
Resource8=IDD_MSHPROP_GEN
Resource9=IDD_MSHPROP_VERTS
Resource10=IDD_FPROP_APPFLAGS
Resource11=IDD_CAMPROP_APPFLAGS
Resource12=IDR_MAINFRAME
Resource13=IDD_MSHPROP_ORIENT
Resource14=IDD_ABOUTBOX
Resource15=IDD_MSHPROP_TXTS
Resource16=IDD_CAMPROP_MISC
Class21=MeshPropTexturePage
Resource17=IDD_FPROP_GEN
Class22=TexturePropGenPage
Class23=TexturePropAppFlagsPage
Resource18=IDD_MSHPROP_FACE
Class24=MeshPropVertsPage
Resource19=IDD_LGTPROP_APPFLAGS
Class25=MeshPropFacePage
Resource20=IDD_LGTPROP_GEN
Resource21=IDD_MSHPROP_APPFLAGS
Resource22=IDD_MSHPROP_EXT
Class26=FacePropGeneralPage
Class27=FacePropFlagsPage
Class28=FacePropAppFlagsPage
Resource23=IDD_FPROP_FLAGS

[CLS:ScenePropGeneralPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp

[CLS:ScenePropMiscPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp

[CLS:CameraPropGeneralPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp

[CLS:CameraPropAppFlagsPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp

[CLS:CameraPropMiscPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
LastObject=ID_STATIC

[CLS:CameraPropExPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
Filter=D
VirtualFilter=idWC
LastObject=CameraPropExPage

[CLS:LightPropGeneralPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
LastObject=IDC_LPROP_DARK
Filter=D
VirtualFilter=idWC

[CLS:LightPropExtraPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp

[CLS:LightPropAppFlagsPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp

[CLS:MeshPropGeneralPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp

[CLS:MeshPropOrientPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
LastObject=IDC_MPROP_MTXA

[CLS:MeshPropExtPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp

[CLS:MeshPropAppFlagsPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp

[CLS:ToolDoc]
Type=0
BaseClass=CDocument
HeaderFile=eshtdoc.h
ImplementationFile=eshtdoc.cpp

[CLS:ToolFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=eshtmfrm.h
ImplementationFile=eshtmfrm.cpp
Filter=T
VirtualFilter=fWC
LastObject=ID_FILE_FLOATING

[CLS:ToolApp]
Type=0
BaseClass=CWinApp
HeaderFile=eshtool.h
ImplementationFile=eshtool.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=eshtool.cpp
ImplementationFile=eshtool.cpp

[CLS:ToolTree]
Type=0
BaseClass=CTreeCtrl
HeaderFile=eshttree.h
ImplementationFile=eshttree.cpp

[CLS:ToolView]
Type=0
BaseClass=CView
HeaderFile=eshtview.h
ImplementationFile=eshtview.cpp
Filter=C
VirtualFilter=VWC
LastObject=ID_VIEW_RND_ALPHA

[CLS:ToolVPort]
Type=0
BaseClass=CWnd
HeaderFile=eshtvp.h
ImplementationFile=eshtvp.cpp

[DLG:IDD_SNPROP_GEN]
Type=1
Class=ScenePropGeneralPage
ControlCount=21
Control1=ID_STATIC,static,1342177282
Control2=IDC_SPROP_NAME,edit,1350631552
Control3=ID_STATIC,static,1342177282
Control4=IDC_SPROP_NCAMERAS,edit,1350568064
Control5=ID_STATIC,static,1342177282
Control6=IDC_SPROP_NMESHES,edit,1350568064
Control7=ID_STATIC,button,1342177287
Control8=ID_STATIC,static,1342177282
Control9=IDC_SPROP_NVLIGHTS,edit,1350568064
Control10=ID_STATIC,static,1342177282
Control11=IDC_SPROP_NFPLIGHTS,edit,1350568064
Control12=ID_STATIC,static,1342177282
Control13=IDC_SPROP_NFALIGHTS,edit,1350568064
Control14=ID_STATIC,static,1342177282
Control15=IDC_SPROP_NFSLIGHTS,edit,1350568064
Control16=ID_STATIC,static,1342177282
Control17=IDC_SPROP_NPLIGHTS,edit,1350568064
Control18=ID_STATIC,static,1342177282
Control19=IDC_SPROP_NALIGHTS,edit,1350568064
Control20=ID_STATIC,static,1342177282
Control21=IDC_SPROP_NSLIGHTS,edit,1350568064

[DLG:IDD_SNPROP_MISC]
Type=1
Class=ScenePropMiscPage
ControlCount=6
Control1=IDC_STATIC,static,1342308354
Control2=IDC_SPROP_DESC,edit,1350631552
Control3=IDC_STATIC,static,1342308354
Control4=IDC_SPROP_AUTH,edit,1350631552
Control5=IDC_STATIC,static,1342308354
Control6=IDC_SPROP_COPY,edit,1350631552

[DLG:IDD_CAMPROP_GEN]
Type=1
Class=CameraPropGeneralPage
ControlCount=22
Control1=ID_STATIC,static,1342308354
Control2=IDC_CPROP_NAME,edit,1350631552
Control3=ID_STATIC,static,1342308354
Control4=IDC_CPROP_XPOS,edit,1350631552
Control5=ID_STATIC,static,1342308352
Control6=IDC_CPROP_YPOS,edit,1350631552
Control7=ID_STATIC,static,1342308352
Control8=IDC_CPROP_ZPOS,edit,1350631552
Control9=ID_STATIC,static,1342308354
Control10=IDC_CPROP_ITOP,edit,1350631552
Control11=ID_STATIC,static,1342308352
Control12=IDC_CPROP_JTOP,edit,1350631552
Control13=ID_STATIC,static,1342308352
Control14=IDC_CPROP_KTOP,edit,1350631552
Control15=ID_STATIC,static,1342308354
Control16=IDC_CPROP_IDIR,edit,1350631552
Control17=ID_STATIC,static,1342308352
Control18=IDC_CPROP_JDIR,edit,1350631552
Control19=ID_STATIC,static,1342308352
Control20=IDC_CPROP_KDIR,edit,1350631552
Control21=ID_STATIC,static,1342308354
Control22=IDC_CPROP_FOV,edit,1350631552

[DLG:IDD_CAMPROP_APPFLAGS]
Type=1
Class=CameraPropAppFlagsPage
ControlCount=10
Control1=IDC_CPROP_FLAGS_APP0,button,1342242819
Control2=IDC_CPROP_FLAGS_APP1,button,1342242819
Control3=IDC_CPROP_FLAGS_APP2,button,1342242819
Control4=IDC_CPROP_FLAGS_APP3,button,1342242819
Control5=IDC_CPROP_FLAGS_APP4,button,1342242819
Control6=IDC_CPROP_FLAGS_APP5,button,1342242819
Control7=IDC_CPROP_FLAGS_APP6,button,1342242819
Control8=IDC_CPROP_FLAGS_APP7,button,1342242819
Control9=IDC_STATIC,static,1342308364
Control10=IDC_STATIC,static,1342308352

[DLG:IDD_CAMPROP_MISC]
Type=1
Class=CameraPropMiscPage
ControlCount=9
Control1=ID_STATIC,static,1342308354
Control2=IDC_CPROP_HITHER,edit,1350631552
Control3=ID_STATIC,static,1342308354
Control4=IDC_CPROP_YON,edit,1350631552
Control5=ID_STATIC,static,1342308354
Control6=IDC_CPROP_SCALEF,edit,1350631552
Control7=IDC_CPROP_BCOLR,button,1342242816
Control8=ID_STATIC,static,1342308352
Control9=ID_STATIC,static,1342308352

[DLG:IDD_CAMPROP_EX]
Type=1
Class=CameraPropExPage
ControlCount=12
Control1=IDC_STATIC,button,1342177287
Control2=IDC_CPROP_BMBACK,button,1342242819
Control3=IDC_CPROP_BITMAP,button,1342242816
Control4=IDC_STATIC,button,1342177287
Control5=IDC_CPROP_HAZE,button,1342242819
Control6=IDC_CPROP_HCOLR,button,1342242816
Control7=IDC_STATIC,static,1342308354
Control8=IDC_CPROP_STARTZ,edit,1350631552
Control9=IDC_STATIC,static,1342308354
Control10=IDC_CPROP_MIDZ,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352

[DLG:IDD_LGTPROP_GEN]
Type=1
Class=LightPropGeneralPage
ControlCount=17
Control1=ID_STATIC,static,1342308354
Control2=IDC_LPROP_NAME,edit,1350631552
Control3=ID_STATIC,static,1342308354
Control4=IDC_LPROP_TYPE,combobox,1344339971
Control5=ID_STATIC,static,1342308354
Control6=IDC_LPROP_INTENSITY,msctls_trackbar32,1342242840
Control7=IDC_LPROP_ON,button,1342242819
Control8=IDC_LPROP_DARK,button,1342242819
Control9=IDC_LPROP_ATTEN,button,1342242819
Control10=ID_STATIC,static,1342308354
Control11=ID_STATIC,static,1342308354
Control12=ID_STATIC,static,1342308352
Control13=IDC_LPROP_XI,edit,1350631552
Control14=ID_STATIC,static,1342308352
Control15=IDC_LPROP_YJ,edit,1350631552
Control16=ID_STATIC,static,1342308352
Control17=IDC_LPROP_ZK,edit,1350631552

[DLG:IDD_LGTPROP_EXTRA]
Type=1
Class=LightPropExtraPage
ControlCount=16
Control1=ID_STATIC,button,1342177287
Control2=ID_STATIC,static,1342308354
Control3=IDC_LPROP_INNER,edit,1350631552
Control4=ID_STATIC,static,1342308354
Control5=IDC_LPROP_OUTER,edit,1350631552
Control6=ID_STATIC,button,1342177287
Control7=ID_STATIC,static,1342308353
Control8=IDC_LPROP_XI,edit,1350631552
Control9=ID_STATIC,static,1342308353
Control10=IDC_LPROP_YJ,edit,1350631552
Control11=ID_STATIC,static,1342308353
Control12=IDC_LPROP_ZK,edit,1350631552
Control13=ID_STATIC,static,1342308354
Control14=IDC_LPROP_HOTSPOT,edit,1350631552
Control15=ID_STATIC,static,1342308354
Control16=IDC_LPROP_FALLOFF,edit,1350631552

[DLG:IDD_LGTPROP_APPFLAGS]
Type=1
Class=LightPropAppFlagsPage
ControlCount=10
Control1=IDC_LPROP_FLAGS_APP0,button,1342242819
Control2=IDC_LPROP_FLAGS_APP1,button,1342242819
Control3=IDC_LPROP_FLAGS_APP2,button,1342242819
Control4=IDC_LPROP_FLAGS_APP3,button,1342242819
Control5=IDC_LPROP_FLAGS_APP4,button,1342242819
Control6=IDC_LPROP_FLAGS_APP5,button,1342242819
Control7=IDC_LPROP_FLAGS_APP6,button,1342242819
Control8=IDC_LPROP_FLAGS_APP7,button,1342242819
Control9=IDC_STATIC,static,1342308364
Control10=IDC_STATIC,static,1342308352

[DLG:IDD_MSHPROP_GEN]
Type=1
Class=MeshPropGeneralPage
ControlCount=22
Control1=ID_STATIC,static,1342177282
Control2=IDC_MPROP_NAME,edit,1350631552
Control3=ID_STATIC,static,1342308354
Control4=IDC_MPROP_NFACES,edit,1350568064
Control5=ID_STATIC,static,1342308354
Control6=IDC_MPROP_NVERTS,edit,1350568064
Control7=ID_STATIC,static,1342308354
Control8=IDC_MPROP_XPOS,edit,1350631552
Control9=ID_STATIC,static,1342308352
Control10=IDC_MPROP_YPOS,edit,1350631552
Control11=ID_STATIC,static,1342308352
Control12=IDC_MPROP_ZPOS,edit,1350631552
Control13=ID_STATIC,button,1342177287
Control14=ID_STATIC,static,1342177282
Control15=IDC_MPROP_PARENT,edit,1350568064
Control16=ID_STATIC,static,1342177282
Control17=IDC_MPROP_CHILD,edit,1350568064
Control18=ID_STATIC,button,1342177287
Control19=IDC_MPROP_VISIBLE,button,1342242819
Control20=IDC_MPROP_CHKEXT,button,1342242819
Control21=ID_STATIC,static,1342308352
Control22=ID_STATIC,static,1342308352

[DLG:IDD_MSHPROP_ORIENT]
Type=1
Class=MeshPropOrientPage
ControlCount=20
Control1=IDC_STATIC,static,1342308354
Control2=IDC_MPROP_MTXA,edit,1350631552
Control3=IDC_STATIC,static,1342308354
Control4=IDC_MPROP_MTXB,edit,1350631552
Control5=IDC_STATIC,static,1342308354
Control6=IDC_MPROP_MTXC,edit,1350631552
Control7=IDC_STATIC,static,1342308354
Control8=IDC_MPROP_MTXD,edit,1350631552
Control9=IDC_STATIC,static,1342308354
Control10=IDC_MPROP_MTXE,edit,1350631552
Control11=IDC_STATIC,static,1342308354
Control12=IDC_MPROP_MTXF,edit,1350631552
Control13=IDC_STATIC,static,1342308354
Control14=IDC_MPROP_MTXG,edit,1350631552
Control15=IDC_STATIC,static,1342308354
Control16=IDC_MPROP_MTXH,edit,1350631552
Control17=IDC_STATIC,static,1342308354
Control18=IDC_MPROP_MTXI,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352

[DLG:IDD_MSHPROP_EXT]
Type=1
Class=MeshPropExtPage
ControlCount=23
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308354
Control3=IDC_MPROP_XCEN,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_MPROP_YCEN,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_MPROP_ZCEN,edit,1350631552
Control8=IDC_STATIC,static,1342308354
Control9=IDC_MPROP_RADIUS,edit,1350631552
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308354
Control12=IDC_MPROP_XMIN,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_MPROP_YMIN,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_MPROP_ZMIN,edit,1350631552
Control17=IDC_STATIC,static,1342308354
Control18=IDC_MPROP_XMAX,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_MPROP_YMAX,edit,1350631552
Control21=IDC_STATIC,static,1342308352
Control22=IDC_MPROP_ZMAX,edit,1350631552
Control23=IDC_STATIC,static,1342308352

[DLG:IDD_MSHPROP_APPFLAGS]
Type=1
Class=MeshPropAppFlagsPage
ControlCount=18
Control1=IDC_MPROP_FLAGS_APP0,button,1342242819
Control2=IDC_MPROP_FLAGS_APP1,button,1342242819
Control3=IDC_MPROP_FLAGS_APP2,button,1342242819
Control4=IDC_MPROP_FLAGS_APP3,button,1342242819
Control5=IDC_MPROP_FLAGS_APP4,button,1342242819
Control6=IDC_MPROP_FLAGS_APP5,button,1342242819
Control7=IDC_MPROP_FLAGS_APP6,button,1342242819
Control8=IDC_MPROP_FLAGS_APP7,button,1342242819
Control9=IDC_MPROP_FLAGS_APP8,button,1342242819
Control10=IDC_MPROP_FLAGS_APP9,button,1342242819
Control11=IDC_MPROP_FLAGS_APPA,button,1342242819
Control12=IDC_MPROP_FLAGS_APPB,button,1342242819
Control13=IDC_MPROP_FLAGS_APPC,button,1342242819
Control14=IDC_MPROP_FLAGS_APPD,button,1342242819
Control15=IDC_MPROP_FLAGS_APPE,button,1342242819
Control16=IDC_MPROP_FLAGS_APPF,button,1342242819
Control17=IDC_STATIC,static,1342308364
Control18=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342177294
Control3=IDC_ABOUT_VERSION,static,1342308363
Control4=IDC_STATIC,static,1342308363
Control5=IDOK,button,1342373889
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308353
Control8=IDC_STATIC,static,1342308353

[MNU:IDR_MAINFRAME]
Type=1
Class=ToolView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_IMPORT
Command6=ID_FILE_PALETTE
Command7=ID_FILE_SEND_MAIL
Command8=ID_FILE_COMPRESS
Command9=ID_FILE_TRUECOLOR
Command10=ID_FILE_FLOATING
Command11=ID_FILE_MRU_FILE1
Command12=ID_APP_EXIT
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_EDIT_DELETE
Command17=ID_EDIT_NEW_CAM
Command18=ID_EDIT_NEW_LIGHT
Command19=ID_EDIT_PROP
Command20=ID_VIEW_TOOLBAR
Command21=ID_VIEW_STATUS_BAR
Command22=ID_VIEW_REFRESH
Command23=ID_VIEW_RND_WIREFRAME
Command24=ID_VIEW_RND_SOLID
Command25=ID_VIEW_RND_FLAT
Command26=ID_VIEW_RND_SMOOTH
Command27=ID_VIEW_RND_SPECULAR
Command28=ID_VIEW_RND_ALL_LINES
Command29=ID_VIEW_RND_MSPACE
Command30=ID_VIEW_RND_BACKFACE
Command31=ID_VIEW_RND_TEXTURES
Command32=ID_VIEW_RND_PERSPECTIVE
Command33=ID_VIEW_RND_ALPHA
Command34=ID_VIEW_RND_SORT
Command35=ID_VIEW_SHOW_SPHEXTS
Command36=ID_VIEW_SHOW_BOXEXTS
Command37=ID_VIEW_ATTACHCAM
Command38=ID_VIEW_ROTXY
Command39=ID_VIEW_MOVEXY
Command40=ID_VIEW_ROTMOVEZ
Command41=ID_VIEW_AUTOOFF
Command42=ID_VIEW_AUTOROTX
Command43=ID_VIEW_AUTOROTY
Command44=ID_VIEW_AUTOROTZ
Command45=ID_VIEW_AUTOFAST
Command46=ID_VIEW_AUTOSLOW
Command47=ID_MESH_ROTIJ
Command48=ID_MESH_MOVEIJ
Command49=ID_MESH_ROTMOVEK
Command50=ID_LGT_ADJUSTXY
Command51=ID_LGT_ABRIGHT
Command52=ID_APP_HELP
Command53=ID_APP_ABOUT
CommandCount=53

[ACL:IDR_MAINFRAME]
Type=1
Class=ToolView
Command1=ID_APP_ABOUT
Command2=ID_VIEW_MOVEXY
Command3=ID_VIEW_ATTACHCAM
Command4=ID_EDIT_COPY
Command5=ID_LGT_ADJUSTXY
Command6=ID_LGT_ABRIGHT
Command7=ID_VIEW_AUTOROTX
Command8=ID_FILE_IMPORT
Command9=ID_VIEW_AUTOROTY
Command10=ID_VIEW_AUTOROTZ
Command11=ID_FILE_NEW
Command12=ID_FILE_OPEN
Command13=ID_FILE_PALETTE
Command14=ID_VIEW_ROTXY
Command15=ID_MESH_MOVEIJ
Command16=ID_FILE_SAVE
Command17=ID_EDIT_PASTE
Command18=ID_VIEW_AUTOFAST
Command19=ID_EDIT_UNDO
Command20=ID_EDIT_DELETE
Command21=ID_EDIT_CUT
Command22=ID_VIEW_RND_ALL_LINES
Command23=ID_APP_HELP
Command24=ID_VIEW_RND_PERSPECTIVE
Command25=ID_VIEW_RND_ALPHA
Command26=ID_VIEW_RND_SORT
Command27=ID_VIEW_RND_MSPACE
Command28=ID_VIEW_RND_BACKFACE
Command29=ID_VIEW_RND_WIREFRAME
Command30=ID_VIEW_RND_SOLID
Command31=ID_VIEW_RND_FLAT
Command32=ID_VIEW_RND_SMOOTH
Command33=ID_VIEW_RND_SPECULAR
Command34=ID_VIEW_RND_TEXTURES
Command35=ID_EDIT_COPY
Command36=ID_EDIT_PASTE
Command37=ID_VIEW_AUTOOFF
Command38=ID_EDIT_PROP
Command39=ID_VIEW_AUTOSLOW
Command40=ID_MESH_ROTIJ
Command41=ID_MESH_ROTMOVEK
Command42=ID_EDIT_CUT
Command43=ID_APP_EXIT
Command44=ID_VIEW_ROTMOVEZ
Command45=ID_VIEW_REFRESH
CommandCount=45

[DLG:IDD_MSHPROP_TXTS]
Type=1
Class=MeshPropTexturePage
ControlCount=2
Control1=IDC_MPROP_TXTLIST,listbox,1352728577
Control2=IDC_MPROP_TXTPROP,button,1342242816

[CLS:MeshPropTexturePage]
Type=0
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_MPROP_TXTLIST

[DLG:IDD_TXTPROP_GEN]
Type=1
Class=TexturePropGenPage
ControlCount=14
Control1=ID_STATIC,static,1342308354
Control2=IDC_TPROP_NAME,edit,1350631552
Control3=ID_STATIC,static,1342308354
Control4=IDC_TPROP_TYPE,combobox,1478492163
Control5=ID_STATIC,static,1342308354
Control6=IDC_TPROP_WIDTH,edit,1350568064
Control7=ID_STATIC,static,1342308354
Control8=IDC_TPROP_HEIGHT,edit,1350568064
Control9=ID_STATIC,static,1342308354
Control10=IDC_TPROP_NFRAMES,edit,1350568064
Control11=ID_STATIC,button,1342177287
Control12=IDC_TPROP_ANIMATE,button,1342242819
Control13=ID_STATIC,static,1342308352
Control14=ID_STATIC,static,1342308352

[DLG:IDD_TXTPROP_APPFLAGS]
Type=1
Class=TexturePropAppFlagsPage
ControlCount=10
Control1=IDC_LPROP_FLAGS_APP0,button,1342242819
Control2=IDC_LPROP_FLAGS_APP1,button,1342242819
Control3=IDC_LPROP_FLAGS_APP2,button,1342242819
Control4=IDC_LPROP_FLAGS_APP3,button,1342242819
Control5=IDC_LPROP_FLAGS_APP4,button,1342242819
Control6=IDC_LPROP_FLAGS_APP5,button,1342242819
Control7=IDC_LPROP_FLAGS_APP6,button,1342242819
Control8=IDC_LPROP_FLAGS_APP7,button,1342242819
Control9=IDC_STATIC,static,1342308364
Control10=IDC_STATIC,static,1342308352

[CLS:TexturePropGenPage]
Type=0
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC

[CLS:TexturePropAppFlagsPage]
Type=0
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC

[DLG:IDD_MSHPROP_VERTS]
Type=1
Class=MeshPropVertsPage
ControlCount=1
Control1=IDC_MPROP_VLIST,listbox,1352744961

[CLS:MeshPropVertsPage]
Type=0
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_MPROP_VLIST

[DLG:IDD_MSHPROP_FACE]
Type=1
Class=MeshPropFacePage
ControlCount=2
Control1=IDC_MPROP_FLIST,listbox,1352728577
Control2=IDC_MPROP_FPROP,button,1342242816

[CLS:MeshPropFacePage]
Type=0
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=ID_STATIC

[DLG:IDD_FPROP_APPFLAGS]
Type=1
Class=FacePropAppFlagsPage
ControlCount=6
Control1=IDC_FPROP_FLAGS_APP0,button,1342242819
Control2=IDC_FPROP_FLAGS_APP1,button,1342242819
Control3=IDC_FPROP_FLAGS_APP2,button,1342242819
Control4=IDC_FPROP_FLAGS_APP3,button,1342242819
Control5=IDC_STATIC,static,1342308364
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_FPROP_GEN]
Type=1
Class=FacePropGeneralPage
ControlCount=23
Control1=ID_STATIC,static,1342308354
Control2=IDC_FPROP_A,edit,1350568064
Control3=ID_STATIC,static,1342308354
Control4=IDC_FPROP_B,edit,1350568064
Control5=ID_STATIC,static,1342308354
Control6=IDC_FPROP_C,edit,1350568064
Control7=ID_STATIC,button,1342177287
Control8=IDC_FPROP_TXT,combobox,1344339971
Control9=ID_STATIC,static,1342308353
Control10=ID_STATIC,static,1342308353
Control11=IDC_FPROP_U0,edit,1350631552
Control12=IDC_FPROP_V0,edit,1350631552
Control13=IDC_FPROP_U1,edit,1350631552
Control14=IDC_FPROP_V1,edit,1350631552
Control15=IDC_FPROP_U2,edit,1350631552
Control16=IDC_FPROP_V2,edit,1350631552
Control17=ID_STATIC,button,1342177287
Control18=ID_STATIC,static,1342308354
Control19=IDC_FPROP_I,edit,1350631552
Control20=ID_STATIC,static,1342308354
Control21=IDC_FPROP_J,edit,1350631552
Control22=ID_STATIC,static,1342308354
Control23=IDC_FPROP_K,edit,1350631552

[DLG:IDD_FPROP_FLAGS]
Type=1
Class=FacePropFlagsPage
ControlCount=20
Control1=IDC_STATIC,button,1342177287
Control2=IDC_FPROP_WIRE,button,1342242819
Control3=IDC_FPROP_SOLID,button,1342242819
Control4=IDC_FPROP_FLAT,button,1342242819
Control5=IDC_FPROP_SMOOTH,button,1342242819
Control6=IDC_FPROP_SPECULAR,button,1342242819
Control7=IDC_FPROP_ABLINE,button,1342242819
Control8=IDC_FPROP_BCLINE,button,1342242819
Control9=IDC_FPROP_CALINE,button,1342242819
Control10=IDC_FPROP_1SIDED,button,1342242819
Control11=IDC_FPROP_APERSP,button,1342242819
Control12=IDC_STATIC,static,1342308354
Control13=IDC_FPROP_ALPHA,button,1342242819
Control14=IDC_FPROP_SELFILLUM,edit,1350631552
Control15=IDC_STATIC,static,1342308354
Control16=IDC_STATIC,static,1342308354
Control17=IDC_STATIC,static,1342308354
Control18=IDC_FPROP_ALPHAA,edit,1350631552
Control19=IDC_FPROP_ALPHAB,edit,1350631552
Control20=IDC_FPROP_ALPHAC,edit,1350631552

[CLS:FacePropGeneralPage]
Type=0
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_FPROP_TXT

[CLS:FacePropFlagsPage]
Type=0
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=FacePropFlagsPage

[CLS:FacePropAppFlagsPage]
Type=0
HeaderFile=eshtdlg.h
ImplementationFile=eshtdlg.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC

