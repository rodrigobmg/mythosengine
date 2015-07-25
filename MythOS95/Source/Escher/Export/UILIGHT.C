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
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
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
// Created by Tim Little & Chuck Walbourn
//
//                       *** IPAS Mesh Data Exporter ***
//
// uilight.c
//
// Contains the user-interface for the light export.
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
static void feel_about(Dialog *d, int mouse);

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern int lights_flag;

static int loop_done;

//�������������������������������������������������������������������������Ŀ
// Make sure that 'empty' strings in .3DE file are filled with dummy values,�
// otherwise the compiler makes them all point to the same string, assuming �
// it is static.  This is wrong and results in editables pointing to the    �
// string.                                                                  �
//���������������������������������������������������������������������������
#include "eschlgt.3de"

static FeelSub EschLgt_feel[] =
{
    OK,         feel_ok,
    ABOUT,      feel_about,
    -1, FNULL
};

int lgt_omnias=1;                           // 1=fast points
                                            // 2=true points
int lgt_spotas=1;                           // 1=fast spots
                                            // 2=true spots
                                            // 3=vectors

int lgt_ambient=1;                          // 1=yes, 0=no

int lgt_atten=1;                            // 1=yes, 0=no

static RadSub EschLgt_rad[] =
{
    NO, feel_radio, &lights_flag, 0,
    YES, feel_radio, &lights_flag, 1,

    OMNIFAST, feel_radio, &lgt_omnias, 1,
    OMNIPNT, feel_radio, &lgt_omnias, 2,

    SPOTFAST, feel_radio, &lgt_spotas, 1,
    SPOTSPOT, feel_radio, &lgt_spotas, 2,
    SPOTVEC, feel_radio, &lgt_spotas, 3,

    -1, FNULL, NULL, -1
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
void do_light()
{
    static int  inited = 0;

    if (!inited)
    {
        init_dialog(EschLgt, NULL, NULL);
        inited = 1;
    }

    loop_done=0;

    ready_dialog(EschLgt, NULL, NULL, EschLgt_feel, EschLgt_rad,
                NULL, NULL);

    EschLgt[AMBIENT].radio = (lgt_ambient) ? 1 : 0;
    EschLgt[ATTEN].radio = (lgt_atten) ? 1 : 0;

    while (!loop_done) 
    {
        center_dialog(EschLgt);
        save_under_dialog(EschLgt);
        draw_dialog(EschLgt);
        do_dialog(EschLgt, -1);
    }

    lgt_ambient = (EschLgt[AMBIENT].radio) ? 1 : 0;
    lgt_atten = (EschLgt[ATTEN].radio) ? 1 : 0;
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

    loop_done=1;
}

static void feel_about(Dialog *d, int mouse)
{
    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();
    about();
}

//��� End of module - uilight.c ���