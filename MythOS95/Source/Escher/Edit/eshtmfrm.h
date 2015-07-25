//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        *** Escher Terrain Editor ***
//
// Chuck Walbourn
//
// eshtmfrm.h
//
// Main window frame class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class TerrMainFrame : public CFrameWnd
{
protected: // create from serialization only
	TerrMainFrame();
	DECLARE_DYNCREATE(TerrMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrMainFrame)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~TerrMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(TerrMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTerrProperties();
	afx_msg void OnTerrImport();
	afx_msg void OnSurfPalette();
	afx_msg void OnSurfImport();
	afx_msg void OnFileExport();
	afx_msg void OnSurfDefineTexture();
	afx_msg void OnSurfEditTexture();
	afx_msg void OnSurfDeleteTexture();
	afx_msg void OnAppHelp();
	afx_msg void OnSurfSaveTextures();
	afx_msg void OnUpdateSurfSaveTextures(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSurfDeleteTexture(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSurfEditTexture(CCmdUI* pCmdUI);
	afx_msg void OnSurfLoadTextures();
	afx_msg void OnSurfDefineColor();
	afx_msg void OnSurfDeleteColor();
	afx_msg void OnUpdateSurfDeleteColor(CCmdUI* pCmdUI);
	afx_msg void OnSurfEditColor();
	afx_msg void OnUpdateSurfEditColor(CCmdUI* pCmdUI);
	afx_msg void OnSurfLoadColors();
	afx_msg void OnSurfSaveColors();
	afx_msg void OnUpdateSurfSaveColors(CCmdUI* pCmdUI);
	afx_msg void OnTerrSetBaseElevation();
	afx_msg void OnSurfRemoveUnusedTxts();
	afx_msg void OnUpdateSurfRemoveUnusedTxts(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//葦� eof - eshtmfrm.h 憶�

