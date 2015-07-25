//���������������������������������������������������������������������������
//           __ ,                                                      
//            ,-| ~           ,               ,,                      
//           ('||/__,        ||               ||                  _   
//          (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\ 
//          (( |||==| || ||  ||   || \\ || || || || || \\  ||   || || 
//           ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || || 
//            -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-| 
//                                                               /  \ 
//                                                              '----`
//                     Text Output and Font Management System
//                          Microsoft Windows '95 Version
//
//               Copyright (c) 1995 by Charybdis Enterprises, Inc.
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
// Created by Chuck Walbourn
//
// gbrgoutc.cpp
//
// Contains the character output routine.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <assert.h>

#include <gutenbrg.hpp>

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern "C" GBergIData   *GBergInstance;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// gberg_outc                                                               �
//                                                                          �
// Outputs a single character to the given x,y location using the currently �
// active font.                                                             �
//���������������������������������������������������������������������������
void gberg_outc(VngoVport *vp, long x, long y, char c)
{
    GBergFontInfo   *fnt;
    VngoRect        r;
    VngoTexture     txt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    assertMyth("gberg_outc assumes viewport is given",vp);

    fnt=GBergInstance->font_active;

    assertMyth("gberg_outc needs a valid (and locked) active font",
               fnt && fnt->ptr);

//�� Draw character
    r.x = x;
    r.y = y;
    r.dx = txt.width = fnt->width;
    r.dy = txt.height = fnt->height;

    switch (fnt->type) {
        case GBERG_FNT_MONOFIXED:

            //�� Monochrome fixed

            txt.tex = (byte *)((byte *)fnt->ptr + (c*fnt->bpc));

            vp->image_trans_mono(&r,&txt,GBergInstance->fcol,GBergInstance->bcol);
            break;
    }
}

//��� End of module - gbrgoutc.cpp ���
