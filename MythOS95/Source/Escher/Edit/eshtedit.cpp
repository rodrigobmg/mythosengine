//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//����������Copyright�(c)�1994,�1995�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//���������������������������������������������������������������������������
//
//                        *** Escher Terrain Editor ***
//
// Chuck Walbourn
//
// eshtedit.cpp
//
// Terrain Editor main application class.
//
// The application class controls the overall application and flow of
// control.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "stdafx.h"
#include "eshtedit.h"

#include "eshtmfrm.h"
#include "eshtdoc.h"
#include "eshtview.h"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define VERSION "0.1"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//�������������������������������������������������������������������������Ŀ
// TerrEditApp                                                              �
//���������������������������������������������������������������������������

BEGIN_MESSAGE_MAP(TerrEditApp, CWinApp)
	//{{AFX_MSG_MAP(TerrEditApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

//�������������������������������������������������������������������������Ŀ
// Global Data                                                              �
//���������������������������������������������������������������������������
TerrEditApp     theApp;

MythosSystem    *MythOS=NULL;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//���������������� Application Initialization/Termination �������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// TerrEditApp - Constructor                                                �
//���������������������������������������������������������������������������
TerrEditApp::TerrEditApp()
{
}


//�������������������������������������������������������������������������Ŀ
// TerrEditApp - InitInstance                                               �
//���������������������������������������������������������������������������
BOOL TerrEditApp::InitInstance()
{
    MythOS = new MythosSystem();
    if (!MythOS)
        return FALSE;

    if (MythOS->init())
        return FALSE;

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
    
	Enable3dControls();

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(TerrEditDoc),
		RUNTIME_CLASS(TerrMainFrame),       // main SDI frame window
		RUNTIME_CLASS(TerrEditView));
	AddDocTemplate(pDocTemplate);

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes();

	// simple command line parsing
	if (m_lpCmdLine[0] == '\0')
	{
		// create a new (empty) document
		OnFileNew();
	}
	else
	{
		// open an existing document
		OpenDocumentFile(m_lpCmdLine);
	}

	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	return TRUE;
}


//�������������������������������������������������������������������������Ŀ
// TerrEditApp - ExitInstance                                               �
//���������������������������������������������������������������������������
int TerrEditApp::ExitInstance()
{
    if (MythOS)
    {
        delete MythOS;
        MythOS = NULL;
    }

    return CWinApp::ExitInstance();
}



//���������������������������������������������������������������������������
//����������������������������� About Dialog ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// CAboutDlg                                                                �
//                                                                          �
// 'About Terrain Editor...' dialog.                                        �
//���������������������������������������������������������������������������
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CStatic	m_verdate;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_ABOUT_VERSION, m_verdate);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_verdate.SetWindowText("Version " VERSION "     " __DATE__);
    }
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



//���������������������������������������������������������������������������
//������������������������� Main Application Handlers �����������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// TerrEditApp - OnAppAbout                                                 �
//                                                                          �
// Display about dialog.                                                    �
//���������������������������������������������������������������������������
void TerrEditApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}



//���������������������������������������������������������������������������
//������������������������� Charybdis Assert Routine ������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// _charybdis_assert
// 
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//���������������������������������������������������������������������������
extern "C" void _charybdis_assert(char *msg, char *exp, char *f, unsigned ln)
{
    int     i;
    char    title[28];
    char    buff[988];

    sprintf(buff,"Assertion Failed\t\t\t\t\t\n"
                 "Expr:\t%s\n"
                 "File:\t%s\t\tLine %d",exp,f,ln);
    if (msg)
    {
        strcat(buff,
               "\nComment:\n");
        strcat(buff,msg);
    }
    strcat(buff,"\n\n\tOK to continue, Cancel to exit");

    sprintf(title,"%s Debug Message",theApp.m_pszAppName);

    i=MessageBox( (AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                 buff,
                 title,
                 MB_OKCANCEL | MB_DEFBUTTON2 | MB_APPLMODAL | MB_ICONSTOP);

    if (i == IDCANCEL)
        ExitProcess(1);
}

//��� eof - eshtedit.cpp ���