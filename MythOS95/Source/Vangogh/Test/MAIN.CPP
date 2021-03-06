//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
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
// Created by Tim Little
//
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
#include <stdlib.h>
#include "global.hpp"
#include "resource.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

STATIC int load_font(char *f);

// Imported from INIT.CPP
BOOL    InitApplication (HINSTANCE, int);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

HINSTANCE   hInst;
HWND        hWndClient;
const char  szAppName[] = "Van Gogh";
GameState   *game;

MaxDevices  *Devs=0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// MythOS provided functions
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" int mythos_atexit (register void (*__func) (void))
{
    return atexit (__func);
}

extern "C" void mythos_atexit_remove (register void (*__func) (void))
{
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// WinMain
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int APIENTRY WinMain (HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR     lpCmdLine,
                      int       nCmdShow)
{
    // Initialize game here.
    IvorySystem ivory (8*1024*1024);
    ChronosSystem   chronos;
    GBergSystem     gberg;

        // Perform initializations.
    // If we are already running, this routine will reactivate the older
    // application and return FALSE.
    if (!InitApplication (hInstance, nCmdShow))
        return FALSE;


    if (load_font("8X13.IFF"))
        return FALSE;

    gberg_select_font("8x13");

    Devs = new MaxDevicesWin32(hWndClient);
    if (!Devs)
        return FALSE;

    game = new GameState (Devs);
    game->LoadEvents ("gframe.iff");
    if (!game->active)
    {
        MessageBeep (0);
        MessageBox(hWndClient,
                   "Could not load event file",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    XFParseINI  ini;
    char        buff[128];

    ini.open(".\\VT.INI",XF_OPEN_READ);
    ini.section("Startup");

    if (!ini.read("PixTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->PixTest = TRUE;
        else
            game->PixTest = FALSE;
    }

    if (!ini.read("PolyTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->PolyTest = TRUE;
        else
            game->GPolyTest = FALSE;
    }

    if (!ini.read("GPolyTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->GPolyTest = TRUE;
        else
            game->GPolyTest = FALSE;
    }

    if (!ini.read("GRPolyTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->GRPolyTest = TRUE;
        else
            game->GRPolyTest = FALSE;
    }

    if (!ini.read("TPolyTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->TPolyTest = TRUE;
        else
            game->TPolyTest = FALSE;
    }

    if (!ini.read("GTPolyTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->GTPolyTest = TRUE;
        else
            game->GTPolyTest = FALSE;
    }

    if (!ini.read("TPolyTestPersp",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->TPolyTestPersp = TRUE;
        else
            game->TPolyTestPersp = FALSE;
    }

    if (!ini.read("GTPolyTestPersp",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->GTPolyTestPersp = TRUE;
        else
            game->GTPolyTestPersp = FALSE;
    }

    if (!ini.read("LineTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->LineTest = TRUE;
        else
            game->LineTest = FALSE;
    }

    if (!ini.read("GLineTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->GLineTest = TRUE;
        else
            game->GLineTest = FALSE;
    }


    if (!ini.read("ITransTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->ITransTest = TRUE;
        else
            game->ITransTest = FALSE;
    }

    if (!ini.read("BackGroundFill",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->BackGroundFill = TRUE;
        else
            game->BackGroundFill = FALSE;
    }


    if (!ini.read("Reset",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->Reset = TRUE;
        else
            game->Reset = FALSE;
    }

    if (!ini.read("ZBuffer",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            game->ZBuffer = TRUE;
        else
            game->ZBuffer = FALSE;
    }

    ini.close();

    // Acquire and dispatch messages until a WM_QUIT message is received.
    int count = 0;
    while (game->PumpWindows() && count < 500)
    {
        // Do per-frame processing here
        Devs->update ();
        game->GetEvents();
        game->ProcessEvents();
        game->Render();
        game->Display();
        count++;
    }

//    while (game->PumpWindows());

    // Clean up the game here
    // (destructors get most of it)
    delete game;

    delete Devs;
    Devs=0;

    return 0;

    // This shuts up the compiler
    lpCmdLine;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// load_font
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC int load_font(char *f)
{
    int err;

    err=gberg_install_font(f,0);
    if (err)
    {
        char    buff[128];
        sprintf(buff,"Failed to load font %s, error %d",f,(int)err);
        MessageBox(hWndClient,
                   buff,"Error",MB_OK);
        return 1;
    }
    return 0;
}

//葦� eof - main.cpp 憶�
