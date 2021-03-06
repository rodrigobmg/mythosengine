//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                              S I M   G I N E
//
//             __               ___   ______,-------
//           __==__,------------/|\--|      | .-.-.|    ___________
//         (|     |--------------|---|------| '-`-`|  _/___________\_
//         (|_____|      _       _   |   _  | 6000 | |               |
//          |__\\_|`-._/___\___/___\_|_/___\|      | |               |
//         __/ |===|--|_____|_|_____|_|___  |\_____|=|_______________|
//      |=|[_]==[_]    \ _ /   \ _ /   \ _ /          [_]   [_]   [_]
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                     A Simluator Framework for MythOS(tm)
//
//                     Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1997-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// Created by Dan Higdon and Chuck Walbourn
//
// simproc.cpp
//
// This module contains the window procedure for the client window.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "simgine.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimWndProc
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
LRESULT CALLBACK SimWndProc (HWND hWnd,
                             UINT message, WPARAM wParam, LPARAM lParam)
{
    static BOOL fScreenSaverActive;

    switch (message)
    {
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Mouse Events
        case WM_SETCURSOR:
            return 0;

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
            if (Devs && Devs->theKeyboard)
                Devs->theKeyboard->wm_keyup (wParam);

            return DefWindowProc (hWnd, message, wParam, lParam);

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
            fScreenSaverActive = FALSE;
            SystemParametersInfo (SPI_GETSCREENSAVEACTIVE, 0,&fScreenSaverActive, 0);

            // Now, turn off the screen saver (but not permanently)
            SystemParametersInfo (SPI_SETSCREENSAVEACTIVE, FALSE, NULL, 0);
            return 0;

        case WM_ACTIVATEAPP:
            if (wParam)
            {
                SystemParametersInfo (SPI_SETSCREENSAVEACTIVE, FALSE, NULL, 0);
                if (Screen)
                {
                    Screen->reinit();
                }
            }
            else
            {
                SystemParametersInfo (SPI_SETSCREENSAVEACTIVE, fScreenSaverActive, NULL, 0);
            }
            return 0;

        case WM_CLOSE:
            if (SimApp)
                SimApp->exit();
            return 0;

        case WM_DESTROY:
            PostQuitMessage (0);
            SystemParametersInfo (SPI_SETSCREENSAVEACTIVE, fScreenSaverActive, NULL, 0);
            return 0;

        default:
            return DefWindowProc (hWnd, message, wParam, lParam);
    }
}

//葦� End of module - simproc.cpp 憶�

