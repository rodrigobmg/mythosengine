//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                                /\    /\
//                               /  \  /  \
//                              /    \/    \
//                             /  /\    /\  \
//                            /  /  \  /  Y T H O S
//                           /  /    \/    \  \
//                          /  /            \  \
//                         /__/              \__\
//
//                  Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
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
//                              3D VIEWER EXAMPLE
//
// Created by Chuck Walbourn
//
// main.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <mythos.hpp>
#include "viewer.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define MYTHOS_MEM_SIZE             4*1024*1024
#define MYTHOS_ESCHER_ARENA_SIZE    256*1024
#define MYTHOS_ESCHER_SORT_SIZE     64*1024

typedef enum _screen_type
{

    SCREEN_DIB      =0,
    SCREEN_DDRAW    =1,
    SCREEN_D3D      =2,
    SCREEN_3DFX     =3,
    SCREEN_CL3D     =4,

} screen_type;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

BOOL PumpWindows();
STATIC BOOL InitApplication (HINSTANCE, int, int, int);
LRESULT CALLBACK ClientWndProc (HWND, UINT, WPARAM, LPARAM);

extern void ProcessEvents();
extern void Render();

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳� Global Windows data
HINSTANCE       hInst;
HWND            hWndClient;
const char      szAppName[]     = "Viewer";

//陳� Global data
MythosSystem        *MythOS     = 0;
MaxDevices          *Devs       = 0;
VngoScreenManager   *Screen     = 0;
VngoVport           *Vport      = 0;
VngoPal             *Palette    = 0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// WinMain
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int APIENTRY WinMain (HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR     lpCmdLine,
                      int       nCmdShow)
{
    ushort      width  = 640;
    ushort      height = 480;
    int         bpp = 16;
    screen_type scrndevice = SCREEN_DIB;
    dword       scrnflags = 0;
    float       gamma = 1.0f;
    BOOL        use_dinput = FALSE;
    char        palname[256];

    strcpy(palname,"DEFAULT.PAL");

//陳� Process INI
    {
        XFParseINI ini;

        if (!ini.open("VIEWER.INI",XF_OPEN_READ))
        {
            char buff[256];

            //陳� Screen parameters
            if (!ini.section("Screen"))
            {
                if (!ini.read("FullScreen",buff))
                {
                    strlwr(buff);
                    if (strstr(buff,"yes"))
                        scrnflags |= VNGO_SET_RESOLUTION;
                }

                if (!ini.read("Device",buff))
                {
                    strlwr(buff);
                    if (strstr(buff,"ddraw"))
                        scrndevice = SCREEN_DDRAW;
                    else if (strstr(buff,"d3d"))
                        scrndevice = SCREEN_D3D;
                    else
                        scrndevice = SCREEN_DIB;
                }

                if (!ini.read("Resolution",buff))
                {
                    strlwr(buff);
                    if (strstr(buff,"320x240x8"))
                    {
                        width = 320;
                        height = 240;
                        bpp = 8;
                    }
                    else if (strstr(buff,"640x480x8"))
                    {
                        width = 640;
                        height = 480;
                        bpp = 8;
                    }
                    else if (strstr(buff,"640x480x15"))
                    {
                        width = 640;
                        height = 480;
                        bpp = 15;
                    }
                    else if (strstr(buff,"640x480x16"))
                    {
                        width = 640;
                        height = 480;
                        bpp = 16;
                    }
                }

                if (!ini.read("Palette",buff))
                    strncpy(palname,buff,sizeof(palname));

                if (!ini.read("Gamma",buff))
                {
                    gamma = float(atof(buff));
                    if (gamma < 0.5f)
                        gamma = 0.5f;
                    else if (gamma > 2.0f)
                        gamma = 2.0f;
                }
            }

            //陳� Startup parameters
            if (!ini.section("Startup"))
            {
                if (!ini.read("DirectInput",buff))
                {
                    strlwr(buff);
                    if (strstr(buff,"yes"))
                        use_dinput = TRUE;
                }
            }
        }
    }

//陳� Initialize Windows

    //陳� If we are already running, this routine will reactivate the older
    //陳� application and return failure.
    if (!InitApplication (hInstance, nCmdShow, width, height))
        return 1;

//陳� Initializes MythOS

    //陳� Initialize the MythOS system
    MythOS = new MythosSystem (MYTHOS_MEM_SIZE);
    if (!MythOS)
        return 1;

    //陳� Create the devices
    if (use_dinput)
    {
        Devs = new MaxDevicesDirectX (hWndClient);

        if (!Devs)
            return 1;

        if (!Devs->is_mouse_present() || !Devs->is_keyboard_present())
        {
            delete Devs;
            Devs = new MaxDevicesWin32 (hWndClient);
        }
    }
    else
        Devs = new MaxDevicesWin32 (hWndClient);

    if (!Devs)
        return 1;

    //陳� Finish MythOS initialization
    if (MythOS->init (MYTHOS_ESCHER_ARENA_SIZE, MYTHOS_ESCHER_SORT_SIZE, 0))
        return 1;

    MythOS->Vangogh.set_gamma(gamma);

//陳� Install Fonts
    if (gberg_install_font("ARIAL-15.IFF", 0))
        return 1;

//陳� Setup palette and screen manager

    for(;;)
    {
        if (Palette)
        {
            delete Palette;
            Palette = 0;
        }
        if (Screen)
        {
            delete Screen;
            Screen = 0;
        }

        //陳� Create palette

        switch (bpp)
        {
            case 8:
                Palette = new VngoPal8;
                break;
            case 15:
                Palette = new VngoPal15;
                break;
            case 16:
                Palette = new VngoPal16;
                break;
        }

        if (!Palette
            || Palette->init(0,palname))
            return 1;

        //陳� Create screen manager

        switch (scrndevice)
        {
            case SCREEN_DIB:
                Screen = new VngoDIB(hWndClient);
                break;
            case SCREEN_DDRAW:
                Screen = new VngoDirectDraw(hWndClient);
                break;
            case SCREEN_D3D:
                Screen = new VngoDirect3D(hWndClient);
                scrnflags |= VNGO_3DDEVICE | VNGO_ALLOC_ZBUFFER;
                break;
        }

        if (!Screen
            || Screen->get_initstate())
            return 1;

        VNGError err = Screen->set_mode (width, height, (bpp == 8) ? 8 : 16,
                                         Palette, scrnflags);
        if (err == VNGO_NO_ERROR)
            break;
        else if (err == VNGO_NEEDS_PAL8)
            bpp = 8;
        else if (err == VNGO_NEEDS_PAL15)
            bpp = 15;
        else if (err == VNGO_NEEDS_PAL16)
            bpp = 16;
        else
            return 1;
    }

//陳� Create viewport

    switch (scrndevice)
    {
        case SCREEN_DIB:
            if (bpp == 8)
            {
                Vport = new VngoVportDB8(width,height,
                                         ((VngoDIB*)Screen)->gmap,0,Palette,
                                         VNGO_ZBUFFER_DEV);
            }
            else
            {
                Vport = new VngoVportDB16(width,height,
                                          ((VngoDIB*)Screen)->gmap,0,Palette,
                                          VNGO_ZBUFFER_DEV);
            }
            break;
        case SCREEN_DDRAW:
            if (bpp == 8)
            {
                Vport = new VngoVportDD8(((VngoDirectDraw*)Screen)->SurfaceManager,
                                         0, Palette,
                                         VNGO_ZBUFFER_DEV);
            }
            else
            {
                Vport = new VngoVportDD16(((VngoDirectDraw*)Screen)->SurfaceManager,
                                          0, Palette,
                                          VNGO_ZBUFFER_DEV);
            }
            break;
        case SCREEN_D3D:
            {
                VngoRect rct(0,0,width,height);
                Vport = new VngoVportD3D(rct, Palette,
                                         VNGO_ZBUFFER_DEV, Screen);
            }
            break;
    }

    if (!Vport)
        return 1;

    gberg_color(Palette->get_index(VngoColor24bit(255,255,255)),
                VNGO_TRANSPARENT);

//陳� Create viewer application instance
    Viewer *view = new Viewer;
    if (!view
        || !view->create())
        return 1;

//陳� Main Loop
    while (PumpWindows())
    {
        Devs->update();
        view->process_events();
        view->render();
        Screen->flip();
    }

//陳� Destroy viewer application
    delete view;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Termination
    if (Vport)
    {
        delete Vport;
        Vport=0;
    }

    if (Palette)
    {
        delete Palette;
        Palette=0;
    }

    if (Screen)
    {
        delete Screen;
        Screen=0;
    }

    if (Devs)
    {
        delete Devs;
        Devs=0;
    }

    if (MythOS)
    {
        delete MythOS;
        MythOS=0;
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PumpWindows
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL PumpWindows()
{
    if (Devs)
        Devs->wm_clear();

    MSG msg;
    while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
    {
        if (GetMessage (&msg, 0, 0, 0) == 0)
            return FALSE;

        TranslateMessage (&msg);
        DispatchMessage (&msg);
    }

    return TRUE;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭 Windows Initialization Functions 旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// InitApplication
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL InitApplication (HINSTANCE hInstance, int nCmdShow, int w, int h)
{
//陳� Win32 will always set hPrevInstance to NULL, so lets check
//陳� things a little closer. This is because we only want a single
//陳� version of this app to run at a time
    HWND hwnd = FindWindow (szAppName, NULL);
    if (hwnd != 0)
    {
        // We found another version of ourself. Lets defer to it:
        if (IsIconic (hwnd))
            ShowWindow (hwnd, SW_RESTORE);
        SetForegroundWindow (hwnd);
        return FALSE;
    }

//陳� Register the client window's class
    WNDCLASSEX  wc;

    // Fill in window class structure with parameters that describe
    // the main window.
    wc.cbSize        = sizeof (WNDCLASSEX);
    wc.style         = CS_OWNDC;
    wc.lpfnWndProc   = (WNDPROC)ClientWndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon (hInstance, szAppName);
    wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject (BLACK_BRUSH);
    wc.lpszClassName = szAppName;
    wc.lpszMenuName  = 0;

    // This will load the small icon image from the icon resource
    wc.hIconSm = (HICON__*)LoadImage (hInstance,
                                      szAppName,
                                      IMAGE_ICON,
                                      GetSystemMetrics(SM_CXSMICON),
                                      GetSystemMetrics(SM_CYSMICON),
                                      LR_DEFAULTCOLOR);

    if (!RegisterClassEx (&wc))
        return FALSE;

    // Save the instance handle in static variable, which will be used in
    // many subsequence calls from this application to Windows.
    hInst = hInstance;

    hWndClient = CreateWindowEx (0,
                                szAppName, szAppName,
                                WS_VISIBLE | WS_POPUP,
                                0, 0, w, h,
                                NULL, NULL, hInstance, NULL);

    if (hWndClient == 0)
        return FALSE;

    ShowWindow (hWndClient, nCmdShow);
    UpdateWindow (hWndClient);
    SetFocus (hWndClient);

    return TRUE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ClientWndProc
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
LRESULT CALLBACK ClientWndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Keyboard Events
        case WM_SYSKEYDOWN:
            if (Devs && Devs->theKeyboard)
                Devs->theKeyboard->wm_keydown (wParam);
            return DefWindowProc (hWnd, message, wParam, lParam);

        case WM_KEYDOWN:
            if (Devs && Devs->theKeyboard)
                Devs->theKeyboard->wm_keydown (wParam);
            return 0;

        case WM_SYSKEYUP:
        case WM_KEYUP:
            if (Devs && Devs->theKeyboard)
                Devs->theKeyboard->wm_keyup (wParam);
            return 0;

        case WM_SETFOCUS:
            if (Devs)
                Devs->init();
            return 0;

        case WM_KILLFOCUS:
            if (Devs)
                Devs->uninit();
            return 0;

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Application Events
        case WM_CREATE:
            return 0;

        case WM_ACTIVATEAPP:
            return 0;

        case WM_CLOSE:
            DestroyWindow(hWndClient);
            return 0;

        case WM_DESTROY:
            PostQuitMessage (0);
            return 0;

        default:
            return DefWindowProc (hWnd, message, wParam, lParam);
    }
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭 MythOS Assert Display 旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// _charybdis_assert
//
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void _charybdis_assert (char *msg, char *exp, char *f, unsigned ln)
{
    int     i;
    char    title[32];
    char    buff[988];

    wsprintf (buff,"Assertion Failed\t\t\t\t\t\n"
                   "Expr:\t%s\n"
                   "File:\t%s\t\tLine %d",exp,f,ln);
    if (msg)
    {
        strcat (buff, "\nComment:\n");
        strcat (buff, msg);
    }
    strcat (buff,"\n\n\tOK to continue, Cancel to exit");

    strcpy (title, szAppName);
    strcat (title, " Debug Message");

    i = MessageBox (IsWindow (hWndClient) ? hWndClient : NULL,
                    buff,
                    title,
                    MB_OKCANCEL | MB_DEFBUTTON2 | MB_APPLMODAL | MB_ICONSTOP);

    if (i == IDCANCEL)
        ExitProcess (1);
}

//葦� eof - main.cpp 憶�
