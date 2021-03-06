//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// Created by Chuck Walbourn
//
// gbrgoutc.cpp
//
// Contains the character output routine.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <assert.h>

#include <gutenbrg.hpp>

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern "C" GBergIData   *GBergInstance;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_outc                                                               �
//                                                                          �
// Outputs a single character to the given x,y location using the currently �
// active font.  It returns the character width unless vert is set which    �
// then causes the height to be returned.                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
long gberg_outc(VngoVport *vp, long x, long y, char c, BOOL vert)
{
    GBergFontInfo   *fnt;
    VngoRect        r;
    VngoTexture     txt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    assertMyth("gberg_outc assumes viewport is given",vp);

    fnt=GBergInstance->font_active;

    assertMyth("gberg_outc needs a valid (and locked) active font",
               fnt && fnt->ptr);

//陳 Draw character
    r.x = x;
    r.y = y;
    r.dy = txt.height = fnt->height;

    switch (fnt->type)
    {
        case GBERG_FNT_MONOFIXED:               //陳 Monochrome fixed
            if (c >= 0)
            {
                r.dx = txt.width = fnt->width;
                txt.flags = VNGO_TEXTURE_MONO;
                txt.tex = (byte *)((byte *)fnt->ptr + (c*fnt->bpc));

                int waslocked = vp->lock();
                vp->image_trans_mono(&r,&txt,GBergInstance->fcol,GBergInstance->bcol);
                if (!waslocked)
                    vp->unlock();
            }
            break;

        case GBERG_FNT_MONOFIXEDEX:             //陳 Monochrome fixed extended
            {
                r.dx = txt.width = fnt->width;

                txt.flags = VNGO_TEXTURE_MONO;
                txt.tex = (byte *)((byte *)fnt->ptr + ((byte)c*fnt->bpc));

                int waslocked = vp->lock();
                vp->image_trans_mono(&r,&txt,GBergInstance->fcol,GBergInstance->bcol);
                if (!waslocked)
                    vp->unlock();
            }
            break;

        case GBERG_FNT_MONOVARIABLE:            //陳 Monochrome variable
            if (c >= 0)
            {
                // First byte is character width
                byte *ptr = (byte *)((byte *)fnt->ptr + (c*fnt->bpc));

                r.dx = txt.width = *(ptr++);
                txt.flags = VNGO_TEXTURE_MONO;
                txt.tex = ptr;

                int waslocked = vp->lock();
                vp->image_trans_mono(&r,&txt,GBergInstance->fcol,GBergInstance->bcol);
                if (!waslocked)
                    vp->unlock();
            }
            break;

        case GBERG_FNT_MONOVARIABLEEX:          //陳 Monochrome variable extended
            {
                // First byte is character width
                byte *ptr = (byte *)((byte *)fnt->ptr + ((byte)c*fnt->bpc));

                r.dx = txt.width = *(ptr++);
                txt.flags = VNGO_TEXTURE_MONO;
                txt.tex = ptr;

                int waslocked = vp->lock();
                vp->image_trans_mono(&r,&txt,GBergInstance->fcol,GBergInstance->bcol);
                if (!waslocked)
                    vp->unlock();
            }
            break;
    }

    return (vert) ? r.dy : r.dx;
}

//葦� End of module - gbrgoutc.cpp 憶�

