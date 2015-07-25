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
//�����������Copyright�(c)�1994-1998�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
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
// Created by Tim Little & Chuck Walbourn & Paul Masters
//
//                       *** IPAS Mesh Data Exporter ***
//
// uikey.c
//
// Contains the user-interface for the keyframe export.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <debug.h>

#include "xfdefs.h"

#include "pxp.h"
#include "dialog.h"

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

void about();

//��� Feel functions
static void feel_ok(Dialog *d, int mouse);
static void feel_cancel(Dialog *d, int mouse);
static void feel_about(Dialog *d, int mouse);
static void feel_target(Dialog *d, int mouse);

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

long key_loop;
long key_ping;
long key_flags;
char key_ctyp[80];

static int loop_done;
static int do_export;

//�������������������������������������������������������������������������Ŀ
// Make sure that 'empty' strings in .3DE file are filled with dummy values,�
// otherwise the compiler makes them all point to the same string, assuming �
// it is static.  This is wrong and results in editables pointing to the    �
// string.                                                                  �
//���������������������������������������������������������������������������
#include "eschkeyf.3de"

static FeelSub EschKeyFlags_feel[] =
{
    OK,         feel_ok,
    CANCEL,     feel_cancel,
    -1, FNULL
};

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// do_light                                                                 �
//                                                                          �
// Do lights's dialog.                                                      �
//���������������������������������������������������������������������������
void do_key_flags()
{
    static int  inited = 0;
    Editable    *e;

    char        file[16];
    char        path[128];
    char        buff[128];

    if (!inited)
    {
        // initialize dialog with Editable
        init_dialog(KeyFlags, EschKeyFlags_edit, NULL);
        inited = 1;
    }

    do_export=loop_done=0;

    // ready dialog with Editable and feelers active
    ready_dialog(KeyFlags, EschKeyFlags_edit, NULL, EschKeyFlags_feel, NULL,
                NULL, NULL);


    sprintf (buff, "WALKING_FOR");
    init_editable(&KeyFlags[KFLGCTYP], buff);

    while (!loop_done)
    {
        center_dialog(KeyFlags);
        save_under_dialog(KeyFlags);
        draw_dialog(KeyFlags);
        do_dialog(KeyFlags, -1);
    }

    if (do_export)
    {
        // Set flag data
        if (KeyFlags[KFLGLOOP].radio)
        {
            key_flags = 1;
        }
        if (KeyFlags[KFLGPING].radio)
        {
            key_flags |= 2;
        }
        if (KeyFlags[KFLGCHAN].radio)
        {
            key_flags |= 4;
            e=(Editable *)KeyFlags[KFLGCTYP].text;
            strcpy(key_ctyp, e->string);
        }
        if (KeyFlags[KFLGSWP1].radio)
        {
            key_flags |= 8;
        }
        if (KeyFlags[KFLGSWP2].radio)
        {
            key_flags |= 16;
        }
    }
}


//�������������������������������������������������������������������������Ŀ
//                            ��� static ���                                �
// Feel functions                                                           �
//���������������������������������������������������������������������������
static void feel_ok(Dialog *d, int mouse)
{
    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();
    do_export=1;
    loop_done=1;
}

static void feel_cancel(Dialog *d, int mouse)
{
    int status;

    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();

    loop_done=1;
    do_export=0;
}

//��� End of module - uikey.c ���

