//���������������������������������������������������������������������������
//
//                           Turner - Networking
//
//                Copyright (c) 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
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
// Turner Network Interface - UI module
//
// turnerui.cpp
//
//  This module provides a dialog user interface to initialize
//  a turner session.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <assert.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Turner.hpp"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                               Routines
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������


//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������


//���������������������������������������������������������������������������
// TurnerNetworkUI - Constructor
//���������������������������������������������������������������������������
TurnerNetworkUI::TurnerNetworkUI (HWND _hWnd, TurnerNetwork *_net):
    hWnd (_hWnd),
    net (_net)
{
}


//���������������������������������������������������������������������������
// TurnerNetworkUI - Destructor
//���������������������������������������������������������������������������
TurnerNetworkUI::~TurnerNetworkUI ()
{
}


//���������������������������������������������������������������������������
// TurnerNetworkUI - create_or_join
//���������������������������������������������������������������������������
int TurnerNetworkUI::create_or_join ()
{
    return DialogBoxParam (NULL, (LPCTSTR) IDD_MAXNETWORK_Q_CREATE, hWnd, 
                           (DLGPROC) DlgProcQCreate, (LPARAM)net);
}

//���������������������������������������������������������������������������
// TurnerNetworkUI - DlgProcQCreate
//  Dialog proc used by create_or_join
//���������������������������������������������������������������������������
BOOL CALLBACK TurnerNetworkUI::DlgProcQCreate (HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_COMMAND:
        switch (wParam)
        {
        case IDC_MAXNETWORK_CREATE:
            EndDialog(hDlg, 1);
            return TRUE;

        case IDC_MAXNETWORK_CONNECT:
            EndDialog(hDlg, 2);
            return TRUE;

        case IDCANCEL:
            EndDialog(hDlg, -1);
            return TRUE;
        }
        break;

    }
    return FALSE;
}


//���������������������������������������������������������������������������
// TurnerNetworkUI - GetProvider
//  Prompt the user for a connection provider, and initialize the
//  network object to use the one selected by the user.
//  Returns:    TRUE if a service selected
//              FALSE if no service selected
//���������������������������������������������������������������������������
int TurnerNetworkUI::get_provider ()
{
    return DialogBoxParam (NULL, (LPCTSTR)IDD_MAXNETWORK_CHOOSEPROVIDER, hWnd,
                           (DLGPROC)DlgProcChooseProvider, (LPARAM)net);
}



//���������������������������������������������������������������������������
// TurnerNetworkUI - static EnumSP
//  Used by DlgProcChooseProvider
//���������������������������������������������������������������������������
BOOL CALLBACK TurnerNetworkUI::EnumSP (LPGUID lpGuid, LPSTR lpDesc,
                                    DWORD dwMajorVersion, DWORD dwMinorVersion,
                                    LPVOID lpv)
{
    HWND hWnd = (HWND)lpv;

    LONG iIndex = SendMessage (hWnd, LB_ADDSTRING, 0, (LPARAM) lpDesc);
    if (iIndex != LB_ERR)
        SendMessage (hWnd, LB_SETITEMDATA, iIndex, (LPARAM) lpGuid);

    SetFocus (hWnd);
    SendMessage (hWnd, LB_SETCURSEL, 0, 0);
    return TRUE;
}



//���������������������������������������������������������������������������
// TurnerNetworkUI - static DlgProcChooseProvider
//  The dialog proc for get_provider
//���������������������������������������������������������������������������
BOOL CALLBACK TurnerNetworkUI::DlgProcChooseProvider (HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static  LONG iIndex;
    static  HWND hWndCtl;
    static  TurnerNetwork  *net;
    
    switch (msg)
    {
    case WM_INITDIALOG:

        // Remember this!
        net = (TurnerNetwork *)lParam;
        hWndCtl = GetDlgItem (hDlg, IDC_MAXNETWORK_LIST1);

        if (net == 0 || hWndCtl == 0)
        {
            EndDialog (hDlg, TRUE);
            return TRUE;
        }

        DirectPlayEnumerate (EnumSP, (LPVOID) hWndCtl);
        SetFocus (hWndCtl);
        SendMessage (hWndCtl, LB_SETCURSEL, 0, 0);
        return FALSE;

    case WM_COMMAND:
        switch (HIWORD (wParam))
        {
        case LBN_SELCHANGE:
            iIndex = SendMessage ((HWND) lParam, LB_GETCURSEL, 0, 0);
            hWndCtl = (HWND) lParam;
            return FALSE;

        case LBN_DBLCLK:
            iIndex = SendMessage ((HWND) lParam, LB_GETCURSEL, 0, 0);
            if (iIndex != LB_ERR)
            {
                net->select_provider ((LPGUID)SendMessage (hWndCtl, LB_GETITEMDATA, iIndex, 0));

                EndDialog (hDlg, TRUE);
                return TRUE;
            }
            break;

        case 0:
            switch (LOWORD(wParam))
            {
            case IDOK:
                if (iIndex != LB_ERR)
                {
                    LPGUID lpGuid = (LPGUID) SendMessage (hWndCtl, LB_GETITEMDATA, iIndex, 0);
                    if (lpGuid)
                    {
                        net->select_provider (lpGuid);
                        EndDialog (hDlg, TRUE);
                    }
                    else
                        EndDialog (hDlg, FALSE);

                    return TRUE;
                }
                break;

            case IDCANCEL:
                EndDialog (hDlg, FALSE);
                return TRUE;
            }
        }
    }
    return FALSE;
}


//���������������������������������������������������������������������������
// TurnerNetworkUI - select_session
//���������������������������������������������������������������������������
int TurnerNetworkUI::select_session ()
{
    assertMyth ("TurnerNetworkUI::select_session must be called after a service provider is chosen",
                net->pIDP != 0);

    return DialogBoxParam (NULL, (LPCTSTR) IDD_MAXNETWORK_SELSESSION, hWnd,
                           (DLGPROC) DlgProcSelSession, (LPARAM)net);
}


//���������������������������������������������������������������������������
// TurnerNetworkUI - static EnumSession
//  session enumeration proc used by DlgProcSelSession
//���������������������������������������������������������������������������
BOOL CALLBACK TurnerNetworkUI::EnumSession (LPDPSESSIONDESC lpDPGameDesc,
                                         LPVOID lpContext,
                                         LPDWORD lpdwTimeOut,
                                         DWORD dwFlags)
{
    LONG iIndex;
    HWND hWnd = (HWND) lpContext;

    if (dwFlags & DPESC_TIMEDOUT)
        return FALSE;       // don't try again

    iIndex = SendMessage (hWnd, LB_ADDSTRING, 0, (LPARAM) lpDPGameDesc->szSessionName);
    if (iIndex != LB_ERR)
        SendMessage (hWnd, LB_SETITEMDATA, iIndex, (LPARAM) lpDPGameDesc->dwSession);

    SetFocus (hWnd);
    SendMessage (hWnd, LB_SETCURSEL, 0, 0);
    return TRUE;
}


//���������������������������������������������������������������������������
// TurnerNetworkUI - DlgProcSelSession
//  Dialog proc used by select_session
//���������������������������������������������������������������������������
BOOL CALLBACK TurnerNetworkUI::DlgProcSelSession (HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static  TurnerNetwork  *net = 0;
    static  LONG        iIndex  = 0;
    static  HWND        hWndCtl = 0;

    DPSESSIONDESC dpDesc;

    switch (msg)
    {
    case WM_INITDIALOG:
        net = (TurnerNetwork *)lParam;
        hWndCtl = GetDlgItem (hDlg, IDC_MAXNETWORK_LIST1);
        if (net == NULL || hWndCtl == NULL)
        {
            EndDialog (hDlg, FALSE);
            return TRUE;
        }
        memset (&dpDesc, 0, sizeof (dpDesc));
        dpDesc.dwSize = sizeof (dpDesc);
        dpDesc.guidSession = net->session.guidSession;

        // enum sessions with 5 second timeout
        net->pIDP->EnumSessions (&dpDesc, (DWORD)5000, EnumSession, (LPVOID) hWndCtl, (DWORD)NULL);

        SetFocus (hWndCtl);
        return FALSE;

    case WM_COMMAND:
        switch (HIWORD (wParam))
        {
        case LBN_SELCHANGE:
            iIndex  = SendMessage ((HWND)lParam, LB_GETCURSEL, 0, 0);
            hWndCtl = (HWND)lParam;
            return FALSE;

        case 0:
            if (LOWORD(wParam) == IDCANCEL)
            {
                net->close ();
                EndDialog (hDlg, FALSE);
                return TRUE;
            }
            //
            // Fall Through.
            //
        case LBN_DBLCLK:
            if (HIWORD(wParam) == LBN_DBLCLK)
            {
                hWndCtl = (HWND)lParam;
                iIndex = SendMessage (hWndCtl, LB_GETCURSEL, 0, 0);
            }

            if (iIndex != LB_ERR)
            {
                DWORD session = SendMessage (hWndCtl, LB_GETITEMDATA, iIndex, 0);
                if (session == LB_ERR)
                {
                    net->close ();
                    EndDialog (hDlg, FALSE);
                    return TRUE;
                }

                HRESULT hr = net->connect_game (session);
                if (hr != DP_OK)
                {
                    net->close ();
                    EndDialog (hDlg, FALSE);
                    return TRUE;
                }

                // Successfully connected to a gaming session.
                EndDialog (hDlg, TRUE);
                return TRUE;
            }
        }
    }

    return FALSE;
}



//���������������������������������������������������������������������������
// TurnerNetworkUI - connect
//  Connect to a user-selected game.  Note that this member does not
//  create a player, which must be done by the calling application.
//���������������������������������������������������������������������������
BOOL TurnerNetworkUI::connect ()
{
    // Be sure we aren't already initialized.
    if (net->pIDP != NULL)
        return FALSE;

    if (!get_provider ())
        return FALSE;

    // Select whether to connect to a game or create a new one
    switch (create_or_join ())
    {
    case 1:             // Create
        return net->create_game () == DP_OK;

    case 2:             // Connect
        return select_session ();

    default:
        return FALSE;
    }
}



//��� End of module - turnerui.cpp ���
