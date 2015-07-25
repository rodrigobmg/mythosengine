//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                        _/_/_/           _/_/_/_/
//                      _/                _/
//                     _/  _/_/          _/_/_/
//                    _/    _/  A M E   _/      R A M  E
//                     _/_/_/          _/
//
// A Framework for Microsoft Windows '95 Entertainment Software Using MythOS
//
//          Copyright (c) 1995 - 1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved
//
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
// main.cpp
//
// This module contains the WinMain function which is the application
// entry point.  This should perform the highest level flow control and
// process any command line switches.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define WIN32_LEAN_AND_MEAN
#include <global.hpp>
#include <resource.h>

// Lander example header
#include <llander.hpp>

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

BOOL InitApplication (HINSTANCE, int, int, int);
void fatal_error(ulong id, char *file, int line);

STATIC int load_font(char *f);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳� Global Windows data
HINSTANCE       hInst;
HWND            hWndClient;
const char      szAppName[]     = "LunarLander";

//陳� Support file names
char            szMasterIFF[]   = "LLander.IFF";
char            szINI[]         = "LLander.INI";

//陳� Command Line Parse Results
dword           CmdFlags = 0;

//陳� Global data
MythosSystem    *MythOS = 0;
MaxDevices      *Devs   = 0;
GFScreen        *Screen = 0;
TurnerNetwork   *Net    = 0;
GameState       *Mode   = 0;

//陳� Game States

LanderTitle     *TitleMode  = 0;
LunarLander     *SimMode    = 0;
LanderLanded    *LandMode   = 0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// WinMain
//
// Primary Application Entry Point
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int APIENTRY WinMain (HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR     lpCmdLine,
                      int       nCmdShow)
{
    CmdFlags = CMDFLAGS_JOYSTICK | CMDFLAGS_DIBSWITCH;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Process INI
    {
        XFParseINI ini;
        if (!ini.open(szINI,XF_OPEN_READ))
        {
            char buff[256];

            //陳� StartUp parameters
            if (!ini.section("StartUp"))
            {
                if (!ini.read("DirectDraw",buff))
                {
                    strlwr(buff);
                    if (strstr(buff,"yes") || strstr(buff,"on"))
                        CmdFlags |= CMDFLAGS_DIRECTDRAW;
                }

                if (!ini.read("DIBModeSwitch",buff))
                {
                    strlwr(buff);
                    if (strstr(buff,"no") || strstr(buff,"off"))
                        CmdFlags &= ~CMDFLAGS_DIBSWITCH;
                }

                if (!ini.read("Joystick",buff))
                {
                    strlwr(buff);
                    if (strstr(buff,"no") || strstr(buff,"off"))
                        CmdFlags &= ~CMDFLAGS_JOYSTICK;
                }
            }
        }
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Parse Command Line
    char *c = lpCmdLine;
    for (;;)
    {
        for (;*c != 0 && *c == ' '; c++);       // Skip past whitespace

        if (*c == '-')
        {
            c++;

            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Direct Draw
            if (!strncmp(c,"dd",sizeof("dd")-1))
            {
                CmdFlags |= CMDFLAGS_DIRECTDRAW;
            }
            else if (!strncmp(c,"nodd",sizeof("nodd")-1))
            {
                CmdFlags &= ~CMDFLAGS_DIRECTDRAW;
            }
            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� DIB Mode Switch
            if (!strncmp(c,"dibswitch",sizeof("dibswitch")-1))
            {
                CmdFlags |= CMDFLAGS_DIBSWITCH;
            }
            else if (!strncmp(c,"nodibswitch",sizeof("nodibswitch")-1))
            {
                CmdFlags &= ~CMDFLAGS_DIBSWITCH;
            }
            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Joystick Control
            if (!strncmp(c,"joy",sizeof("joy")-1))
            {
                CmdFlags |= CMDFLAGS_JOYSTICK;
            }
            else if (!strncmp(c,"nojoy",sizeof("nojoy")-1))
            {
                CmdFlags &= ~CMDFLAGS_JOYSTICK;
            }
        }

        for (;*c != 0 && *c != ' '; c++);       // Skip over parameter

                                                // Check for end of command line
        if (!*c)
            break;
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Initialize

    //陳� Set up desired screen size
    int width  = 640;
    int height = 480;

    //陳� If we are already running, this routine will reactivate the older
    //陳� application and return failure.
        if (!InitApplication (hInstance, nCmdShow, width, height))
                return 1;

    //陳� Initialize the MythOS system
    MythOS = new MythosSystem (MYTHOS_MEM_SIZE);

    //陳� Create the devices, etc.
    Devs   = new MaxDevices;
    if (MythOS == 0 || Devs == 0)
    {
        fatal_error(IDS_ERR_NOMEMORY, __FILE__, __LINE__);
        return 1;
    }

    //陳� Create a stack space for Bozo (so tasks can call Win32 APIs)
    //陳� Notice that this MUST reside on the stack!
    char    bozo_stackspace[MYTHOS_TASK_STACK_SIZE];

    IvorySubAlloc *bozo_alloc = (IvorySubAlloc *)bozo_stackspace;
    ivory_sub_initialize (bozo_alloc, sizeof (bozo_stackspace));

    //陳� Finish MythOS initialization
    if (MythOS->init (MYTHOS_ESCHER_ARENA_SIZE, bozo_alloc))
    {
        fatal_error(IDS_ERR_MYTHOSFAIL, __FILE__, __LINE__);
        return 1;
    }

    //陳� Install Gutenberg Fonts
    if (load_font("9x15")
        || load_font("12x24"))
        return 1;

    //陳� Initialize the Screen object
    if (CmdFlags & CMDFLAGS_DIRECTDRAW)
        Screen = new GFScreenDD;
    else
        Screen = new GFScreenDIB((CmdFlags & CMDFLAGS_DIBSWITCH) ? TRUE : FALSE);

    if (Screen == 0 ||
        Screen->init (width, height) != 0 ||
        Screen->load_palette ("Default.VGP") != 0)
    {
        fatal_error(IDS_ERR_SCREENFAIL, __FILE__, __LINE__);
        return 1;
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Initialize Game Specifics
    TitleMode = new LanderTitle ();
    if (TitleMode == 0 ||
        TitleMode->init ("landevt") != 0)
    {
        fatal_error(IDS_ERR_GAMEINITFAIL, __FILE__, __LINE__);
        return 1;
    }

    SimMode = new LunarLander;
    if (SimMode == 0 ||
        SimMode->init ("landevt") != 0)
    {
        fatal_error(IDS_ERR_GAMEINITFAIL, __FILE__, __LINE__);
        return 1;
    }

    LandMode = new LanderLanded;
    if (LandMode == 0 ||
        LandMode->init ("landevt") != 0)
    {
        fatal_error(IDS_ERR_GAMEINITFAIL, __FILE__, __LINE__);
        return 1;
    }

    //陳� Start initial mode
    Mode = TitleMode;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Main Loop
    assertMyth ("WinMain needs a valid Start Mode", Mode != 0);
    Mode->activate();
    while (Mode->pump_windows ())
    {
        bz_yield(&ReadyQ, &ReadyQ);
        assertMyth ("WinMain needs a valid Mode", Mode != 0);

        Devs->update();
        Mode->process_events();
        Mode->render();
        Mode->display();
    }
    Mode->deactivate();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Termination
    delete TitleMode;
    delete SimMode;
    delete LandMode;

    delete Screen;
    delete Devs;
    delete MythOS;

        return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// load_font
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC int load_font(char *f)
{
    int err;

    err = gberg_install_font (szMasterIFF, f);

    if (err)
    {
        char    buff[1024];

        LoadString(hInst, IDS_ERR_LOADFONTFAIL, buff, sizeof(buff));
        MessageBox (hWndClient,
                    buff,
                    szAppName, MB_OK);
        return 1;
    }
    return 0;
}

//葦� eof - main.cpp 憶�
