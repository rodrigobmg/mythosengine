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
// zgrtri8.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//#include <assert.h>
#include <string.h>

#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

extern "C" void scan_zgradient_edge(VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2);
extern "C" void draw_zgrhlines(VngoTriangle *tri);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern long RedDitherMatrix[4][4];
extern long GreenDitherMatrix[4][4];
extern long BlueDitherMatrix[4][4];

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
//  void vngo_triangle8(VngoVbuffer *vb,VngoPoint2 *pts,dword color)
//      This routine draws a flat shaded triangle, making the assumption
//      that it has already been clipped.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳

extern "C" void vngo_zgrtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,dword color)
{
    long            mid_y;
    int             high_pt_idx = 0;
    int             low_pt_idx = 2;
    int             mid_pt_idx = 1;
    VngoTriangle    tri;
    VngoPoint2      *edge1 = vb->edge1;
    VngoPoint2      *edge2 = vb->edge2;

    calc_order(high_pt_idx,mid_pt_idx,low_pt_idx,pts);

    VngoPoint2 *high_pt = &pts[high_pt_idx];
    VngoPoint2 *mid_pt = &pts[mid_pt_idx];
    VngoPoint2 *low_pt = &pts[low_pt_idx];

    long    dy1 = ((low_pt->y + 0x8000) >> 16) - ((high_pt->y + 0x8000) >> 16);
    long    dy2 = ((mid_pt->y + 0x8000) >> 16) - ((high_pt->y + 0x8000) >> 16);

    if (dy1 == 0)
    {   // the triangle is completely flat if this is true.
        return;
    }

    if (dy1 > dy2)
    {
        mid_y = dy2;
    }
    else
    {
        mid_y = dy2 - 1;
    }

    tri.start_y = (high_pt->y + 0x8000) >> 16;
    tri.color = pts[0].clr;
    tri.sptr  = vb->scrn_ptr + vb->ytable[tri.start_y];
    tri.zptr  = (word*)(long(vb->zbuff_ptr) + vb->ztable[tri.start_y]);

    scan_zgradient_edge(edge1,high_pt,low_pt);

    scan_zgradient_edge(edge2,high_pt,mid_pt);

    scan_zgradient_edge(&edge2[dy2],mid_pt,low_pt);

    tri.vbuff = vb;
    tri.pitch = vb->pitch;
    tri.zpitch = vb->zpitch;
    tri.height = dy1;

    long mid_dx = ((edge2[mid_y].x + 0x8000) >> 16) - ((edge1[mid_y].x + 0x8000) >> 16);

    if (mid_dx >= 0)
    {
        tri.left_edge = edge1;
        tri.right_edge = edge2;
        if (mid_dx)
        {
            tri.zstep_dx1 = (long(edge2[mid_y].z) - long(edge1[mid_y].z)) / mid_dx;
            tri.sstep_dx1 = (long(edge2[mid_y].shade) - long(edge1[mid_y].shade)) / mid_dx;
            tri.ustep_dx1 = (long(edge2[mid_y].u) - long(edge1[mid_y].u)) / mid_dx;
            tri.vstep_dx1 = (long(edge2[mid_y].v) - long(edge1[mid_y].v)) / mid_dx;
        }
        else
        {
            tri.zstep_dx1 = 0;
            tri.sstep_dx1 = 0;
            tri.ustep_dx1 = 0;
            tri.vstep_dx1 = 0;
        }
    }
    else
    {
        tri.left_edge = edge2;
        tri.right_edge = edge1;

        tri.zstep_dx1 = (long(edge1[mid_y].z) - long(edge2[mid_y].z)) / -mid_dx;
        tri.sstep_dx1 = (long(edge1[mid_y].shade) - long(edge2[mid_y].shade)) / -mid_dx;
        tri.ustep_dx1 = (long(edge1[mid_y].u) - long(edge2[mid_y].u)) / -mid_dx;
        tri.vstep_dx1 = (long(edge1[mid_y].v) - long(edge2[mid_y].v)) / -mid_dx;
    }
    draw_zgrhlines(&tri);
}

extern "C" void scan_zgradient_edge(VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2)
{
    Flx16 xstep;
    Flx16 zstep;
    Flx16 sstepR;
    Flx16 sstepG;
    Flx16 sstepB;
    VngoColor24bit  c1;
    VngoColor24bit  c2;

    c1.r = byte((p1->clr) & 0xff);
    c1.g = byte((p1->clr >> 8) & 0xff);
    c1.b = byte((p1->clr >> 16) & 0xff);

    c2.r = byte((p2->clr) & 0xff);
    c2.g = byte((p2->clr >> 8) & 0xff);
    c2.b = byte((p2->clr >> 16) & 0xff);

    Flx16 dy = Flx16(p2->y - p1->y ,0);
    long  count = ((p2->y + 0x8000) >> 16) - ((p1->y + 0x8000) >> 16);
    if (count)
    {
        Flx16 dz = Flx16(long(ulong(p2->z) >> 1),0) - Flx16(long(ulong(p1->z) >> 1),0);
        Flx16 dx = Flx16(p2->x - p1->x,0);
        Flx16 dsR = Flx16(c2.r) - Flx16(c1.r);
        Flx16 dsG = Flx16(c2.g) - Flx16(c1.g);
        Flx16 dsB = Flx16(c2.b) - Flx16(c1.b);

        if (dy.flx < 0x10000)
        {
            xstep = dx;
            zstep = dz;
            sstepR = dsR;
            sstepG = dsG;
            sstepB = dsB;
        }
        else
        {
            xstep = dx / dy;
            zstep = dz / dy;
            sstepR = dsR / dy;
            sstepG = dsG / dy;
            sstepB = dsB / dy;
        }
        Flx16 wx = Flx16(p1->x,0);
        Flx16 wz = Flx16(long(ulong(p1->z) >> 1), 0);
        Flx16 wsR = Flx16(c1.r);
        Flx16 wsG = Flx16(c1.g);
        Flx16 wsB = Flx16(c1.b);

        count++;
        while (count--)
        {
            edge->x = wx.flx;
            edge->z = wz.flx;
            edge->shade = wsR.flx;
            edge->u = wsG.flx;
            edge->v = wsB.flx;

            edge++;
            wx += xstep;
            wz += zstep;
            wsR += sstepR;
            wsG += sstepG;
            wsB += sstepB;
        }
    }
}



extern "C" void draw_zgrhlines(VngoTriangle *tri)
{
    VngoVbuffer     *vb = tri->vbuff;
    VngoPal8        *tp = (VngoPal8*)vb->pal;
    byte            *lut = tp->convert.cvt2_8.colorconvert;

    long            count = tri->height;
    long            pitch = tri->pitch;
    long            zpitch = tri->zpitch >> 1;
    long            zstep_dx1 = tri->zstep_dx1;
    long            Rstep_dx1 = tri->sstep_dx1;
    long            Gstep_dx1 = tri->ustep_dx1;
    long            Bstep_dx1 = tri->vstep_dx1;

    byte            *scrn = (byte*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;

    long start_y = tri->start_y;
    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long tR = edge1->shade;
        long tG = edge1->u;
        long tB = edge1->v;
        long tx = (edge1->x + 0x8000) >> 16;
        byte *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        int dx = ((edge2->x + 0x8000) >> 16);

        long *dmatrixR = &RedDitherMatrix[(start_y+y)&3][0];
        long *dmatrixG = &GreenDitherMatrix[(start_y+y)&3][0];
        long *dmatrixB = &BlueDitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x <= dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {
                *zptr = wz;

                int ltx = x & 3;
                int val = 0;
                int tval = tB + dmatrixB[ltx];
                if (tval > 0xff0000)
                    val = word(0x1f << 10);
                else if (tval >= 0)
                    val = word(tval >> 9) & (0x1f << 10);

                tval = tG + dmatrixG[ltx];
                if (tval > 0xff0000)
                    val |= word(0x1f << 5);
                else if (tval >= 0)
                    val |= word(tval >> 14) & (0x1f << 5);


                tval = tR + dmatrixR[ltx];
                if (tval > 0xff0000)
                    val |= word(0x1f);
                else if (tval >= 0)
                    val |= word((tval >> 19) & 0x1f);

                *ptr = lut[val];
            }
            ptr++;
            zptr++;
            tz += zstep_dx1;
            tR += Rstep_dx1;
            tG += Gstep_dx1;
            tB += Bstep_dx1;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}

//葦� End of module - ztri8.cpp 憶�
