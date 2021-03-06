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
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        *** Escher Terrain Editor ***
//
// Created by Chuck Walbourn
//
// eshtdlgt.h
//
// Terrain Editor Texture Dialog Classes
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define CREATE_ASK_FILE     100
#define CREATE_ASK_COLOR    200

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class TerrEditDoc;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭� Texture View Dialog 旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TextureViewDlg                                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class TextureViewDlg : public CDialog
{
// Construction
public:
        TextureViewDlg(CWnd* pParent = NULL);   // standard constructor
    ~TextureViewDlg();

// Dialog Data
    LPBITMAPINFO    bmi;
    BYTE            *gmap;
    HPALETTE        hpal;

        //{{AFX_DATA(TextureViewDlg)
        enum { IDD = IDD_TXTVIEW };
        CStatic m_bitmap;
        UINT    m_height;
        UINT    m_width;
        //}}AFX_DATA

// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(TextureViewDlg)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
    int x, y;

        // Generated message map functions
        //{{AFX_MSG(TextureViewDlg)
        afx_msg void OnPaint();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭 Texture Create Dialogs 旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// CreateTextureAskDlg                                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class CreateTextureAskDlg : public CDialog
{
// Construction
public:
        CreateTextureAskDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
        //{{AFX_DATA(CreateTextureAskDlg)
        enum { IDD = IDD_TXTCREATE_ASK };
                // NOTE: the ClassWizard will add data members here
        //}}AFX_DATA


// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CreateTextureAskDlg)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:

        // Generated message map functions
        //{{AFX_MSG(CreateTextureAskDlg)
        afx_msg void OnCreateFromColor();
        afx_msg void OnCreateFromFile();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// CreateTextureDlg                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class CreateTextureDlg : public CDialog
{
// Construction
public:
        CreateTextureDlg(CWnd* pParent = NULL);   // standard constructor
    ~CreateTextureDlg();

    XFBitmap bm;

    LPBITMAPINFO    bmi;
    BYTE            *gmap;
    HPALETTE        hpal;
    dword           m_color;
    dword           colors[4];          // region colors
    CString         dib_fname;
    CString         bg_dib_fname;
    BOOL            bg_is_dib;
    CRect           reg[4];

    BOOL setup_dib();
    void release_dib();
        void setup(TerrEditDoc *pd);
    BOOL check_bitmap_size(const char *fname);

// Dialog Data
        //{{AFX_DATA(CreateTextureDlg)
        enum { IDD = IDD_TXTCREATE_NEW };
        CStatic m_bitmap;
        UINT    m_height;
        UINT    m_width;
        //}}AFX_DATA


// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CreateTextureDlg)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
    int x, y;
    TerrEditDoc *pDoc;
    void do_image_background(XFBitmap *bm, XFBitmap *bg_bm, int w, int h);
//    void do_image_background(XFBitmap *bm);
    void draw_selection_boxes(CPaintDC *pdc);

        // Generated message map functions
        //{{AFX_MSG(CreateTextureDlg)
        afx_msg void OnPaint();
        afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
        afx_msg void OnLoadBgTexture();
        afx_msg void OnSaveAs();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// CreateTextureFromColorDlg                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class CreateTextureFromColorDlg : public CDialog
{
// Construction
public:
        CreateTextureFromColorDlg(CWnd* pParent = NULL);   // standard constructor
    ~CreateTextureFromColorDlg();
    LPBITMAPINFO    bmi;
    BYTE            *gmap;
    HPALETTE        hpal;
    dword           m_color;
    dword           colors[4];          // region colors
    CString         dib_fname;
    CString         m_fname;
    int             m_size;
    XFBitmap        *bm;
    CRect           reg[4];

    void setup_dib();
    void release_dib();
        void setup(TerrEditDoc *pd);


// Dialog Data
        //{{AFX_DATA(CreateTextureFromColorDlg)
        enum { IDD = IDD_CLRCREATE_NEWTXT };
        CComboBox       m_listbox;
        CStatic m_bitmap;
        UINT    m_height;
        UINT    m_width;
        //}}AFX_DATA


// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CreateTextureFromColorDlg)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
    int x, y;
    TerrEditDoc *pDoc;
    void do_image_smoothing(XFBitmap *bm);
    BOOL create_bitmap_from_DIB(XFBitmap *bm, BYTE *gptr, int w, int h, int bpp);
    void draw_selection_boxes(CPaintDC *pdc);


        // Generated message map functions
        //{{AFX_MSG(CreateTextureFromColorDlg)
        afx_msg void OnPaint();
        afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
        afx_msg void OnSaveColorToFile();
        afx_msg void OnSelectSize();
        afx_msg void OnSolidColor();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭 Texture Properties 旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TxtPropGenPage                                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class TxtPropGenPage : public CPropertyPage
{
        DECLARE_DYNCREATE(TxtPropGenPage)

// Construction
public:
        TxtPropGenPage();
        ~TxtPropGenPage();

    dword   colors[4];          // region colors

    dword   m_color;

    void setup(TerrEditDoc *pd, int i=-1);

// Dialog Data
        //{{AFX_DATA(TxtPropGenPage)
        enum { IDD = IDD_TXTPROP_GEN };
        CString m_name;
        CString m_fname;
        //}}AFX_DATA

// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(TxtPropGenPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
    int iNDex;
    TerrEditDoc *pDoc;

        // Generated message map functions
        //{{AFX_MSG(TxtPropGenPage)
        afx_msg void OnBrowse();
        afx_msg void OnView();
        afx_msg void OnColor();
        afx_msg void OnCreateNewTexture();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TxtPropSFlagsPage                                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class TxtPropSFlagsPage : public CPropertyPage
{
        DECLARE_DYNCREATE(TxtPropSFlagsPage)

// Construction
public:
        TxtPropSFlagsPage();
        ~TxtPropSFlagsPage();

    int     m_isnew;

    void setup(TerrEditDoc *pd, int i=-1);

// Dialog Data
        //{{AFX_DATA(TxtPropSFlagsPage)
        enum { IDD = IDD_TXTPROP_SFLAGS };
        CButton m_resetCtl;
        BOOL    m_flipu;
        BOOL    m_flipv;
        int             m_tile;
        BOOL    m_notile;
        BOOL    m_highonly;
        BOOL    m_app0;
        BOOL    m_app1;
        BOOL    m_app2;
        BOOL    m_app3;
        //}}AFX_DATA

// Overrides
        // ClassWizard generate virtual function overrides
        //{{AFX_VIRTUAL(TxtPropSFlagsPage)
        protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL

// Implementation
protected:
    int iNDex;
    TerrEditDoc *pDoc;

        // SFlagserated message map functions
        //{{AFX_MSG(TxtPropSFlagsPage)
        afx_msg void OnResetUsage();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()

};

//葦� eof - eshtdlgt.h 憶�
