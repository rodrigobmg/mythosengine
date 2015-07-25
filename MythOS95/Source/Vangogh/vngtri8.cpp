//���������������������������������������������������������������������������
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
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
// vngtri.cpp
//
//     The Flat/Solid colored polygon code for the VanGogh Draw library.
//
//����������������������������� Revision History ����������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������
#include <assert.h>

#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

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



//�������������������������������������������������������������������������Ŀ
//  This section of code contains all of the code for solid color polygons. �
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
//  void vngo_dhline8 (long y, VngoTriangle *tri, VngoVport *vp);           �
//      This routine draws a horizontal line from (tri->long_x,y) to        �
//      (tri->short_x,y) in the color specified by tri->long_top->clr.      �
//���������������������������������������������������������������������������

STATIC void vngo_dhline8(long y, VngoTriangle *tri, VngoVport *vp)
{
    VngoPoint   pt;
    long        x1,x2,step,t;

    x1 = tri->long_x;
    x2 = tri->short_x;

    pt.x = x1;
    pt.y = y;
    pt.clr = tri->long_top->clr;
    pt.shade = tri->long_top->shade;
    if (x1 > x2)
    {
        step = -1;
        t = x1 - x2;
    }
    else
    {
        step = 1;
        t = x2-x1;
    }
    for (int i=0 ; i <= t ; i++)
    {
        vp->pixel(&pt);
        pt.x += step;
    }
}


//�������������������������������������������������������������������������Ŀ
//  void vngo_dzhline8 (long y, VngoTriangle *tri, VngoVport *vp);          �
//      This routine draws a horizontal line using a Z-buffer from          �
//      (tri->long_x,y) to (tri->short_x,y) in the color specified by       �
//      tri->long_top->clr.                                                 �
//���������������������������������������������������������������������������

STATIC void vngo_dzhline8(long y, VngoTriangle *tri, VngoVport *vp)
{
    VngoPoint   pt;
    long        x1,x2,step,t;

    x1 = (tri->long_x + 0x80000) >> 20;
    x2 = (tri->short_x + 0x80000) >> 20;

    if (x1 > x2)
    {
        step = -1;
        t = x1-x2;
    }
    else
    {
        step = 1;
        t = x2-x1;
    }

    byte        *sptr = vp->vbuff.scrn_ptr;;
    word        *zptr = (word *)vp->vbuff.zbuff_ptr;
    VngoShadePal8 *tp = (VngoShadePal8 *)vp->vbuff.pal->shd_pal;
    byte        color = (*tp)[tri->long_top->clr].shl[tri->long_top->shade >> 3];
    dword       poffset = vp->vbuff.ytable[y] + x1;
    dword       z = tri->long_z;

    for (int i=0;i <= t; i++)
    {
        if ((z >> 16) <= zptr[poffset])
        {
            sptr[poffset] = color;
            zptr[poffset] = (word)(z >> 16);

        }
        poffset += step;
        z += tri->z_step;
    }
}




//�������������������������������������������������������������������������Ŀ
//  void vngo_triangle8 (VngoVport *vp, VngoPoint *pts, dword color);       �
//      This routine draws a triangle that is presumed to be clipped.       �
//      It draws in a solid color specified in the pts[0].clr.              �
//���������������������������������������������������������������������������

STATIC void vngo_triangle8 (VngoVport *vp,VngoPoint *pts,dword color)
{
    VngoTriangle    tri;
    dword           stepped=0;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);

    long    dy;
    dy = tri.long_bottom->y - tri.long_top->y;
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_bottom->x,
                                          tri.long_top->x, dy);
    }
    else
    {
        // if the long edge is horizontal, then there is nothing to draw!
        return;
    }

    dy = tri.short_bottom->y - tri.short_top->y; 
    if (dy)
    {
        tri.short_x_step = vngo_calc_xstep(tri.short_bottom->x,
                                           tri.short_top->x, dy);
    }
    else
    {
        // if the short edge is horizontal, there is probably a problem,
        // but it is thoreticaly possible so we will deal with it for now.
        stepped = 1;
        dy = tri.long_bottom->y - tri.short_bottom->y;
        if (dy)
            tri.short_x_step = vngo_calc_xstep(tri.long_bottom->x,
                                               tri.short_bottom->x, dy);
        else
        {
            // if the second short leg is also zero, then the long leg should 
            // have already failed above.
            return;
        }
    }

    long            y;
    Flx16           sx,ex;

    y = tri.long_top->y;

    tri.long_x = tri.long_top->x << 20;
    tri.short_x = tri.short_top->x << 20;


    while (dy--)
    {
		if (y >= vp->vbuff.height)
		{
			return;
		}
        vngo_dhline8(y,&tri,vp);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
    }

    if(!stepped)
    {
        stepped = 1;
        dy = tri.long_bottom->y - tri.short_bottom->y;
        if (dy)
            tri.short_x_step = vngo_calc_xstep(tri.long_bottom->x,
                                               tri.short_bottom->x, dy);
        else
        {
            // if the second short leg is also zero, then the long leg should 
            // have already failed above.
            return;
        }
        tri.short_x = tri.short_bottom->x << 20;
    }

    while (dy--)
    {
		if (y >= vp->vbuff.height)
		{
			return;
		}
        vngo_dhline8(y,&tri,vp);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
    }

    return;
}


//�������������������������������������������������������������������������Ŀ
//  void vngo_ztriangle8 (VngoVport *vp, VngoPoint *pts, dword color);      �
//      This routine draws a Z-buffered triangle that is presumed to be     �
//      clipped.  It draws in a solid color specified in the pts[0].clr.    �
//���������������������������������������������������������������������������

STATIC void vngo_ztriangle8 (VngoVport *vp,VngoPoint *pts,dword color)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);

    dy = tri.long_bottom->y - tri.long_top->y + 1;
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_z_step = vngo_calc_zstep(tri.long_top->z, 
                                          tri.long_bottom->z,dy);
    }
    else
    {
        // if the long edge is horizontal, then there is nothing to draw!
        return;
    }

    dy = tri.short_bottom->y - tri.short_top->y + 1; 
    if (dy)
    {
        tri.short_x_step = vngo_calc_xstep(tri.short_top->x,
                                           tri.short_bottom->x, dy);
    }
    else
    {
        // if it has a flat top, it should have already been dealt with,
        // therefore if the short leg is horizontal, then the polygon is 
        // completely flat, and there is nothing to draw.
        return;
    }

    if (tri.short_top != tri.long_top)
    {
        // if the top of the short and long are not the same then the
        // triangle has a flat top!
        stepped = 1;
    }


    long            y = tri.long_top->y;

    //
    // Setup all of the starting edge values to be interpolated.
    //

    tri.long_x = tri.long_top->x << 20;
    tri.long_z = tri.long_top->z;
    tri.short_x = tri.short_top->x << 20;



    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t1,t2;
        t2 = tri.long_z_step;
        t2 *= dy;
        // the amount z gets changed over dy.
        t2 += tri.long_z;
        // t2 now has Z at the long edge ofsett dy lines from start.
        t1 = tri.short_bottom->z - t2;
        // t1 should now have the delta Z for the hline.

        t2 = tri.long_x_step * dy;
        t2 += tri.long_x + 0x80000;
        t2 = (tri.short_bottom->x << 20) - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
            t2 = -t2;

        t2 = t2 >> 20;
        t2++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t2;
    }
    else
    {
        long    t1,t3;
        t1 = tri.short_top->z - tri.long_z;
        t3 = tri.short_x - tri.long_x;

        if (t3 < 0)
            t3 = -t3;

        t3 = t3 >> 20;
        t3++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t3;
    }

    while (dy--)
    {
        vngo_dzhline8(y,&tri,vp);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_z += tri.long_z_step;
    }

    if(!stepped)
    {
        stepped = 1;
        dy = tri.long_bottom->y - tri.short_bottom->y + 1;
        if (dy)
        {
            tri.short_x_step = vngo_calc_xstep(tri.short_bottom->x,
                                               tri.long_bottom->x, dy);
        }
        else
        {
            // if the second short leg is also zero, then the long leg should 
            // have already failed above.
            return;
        }
        tri.short_x = tri.short_bottom->x << 20;
        tri.short_x += tri.short_x_step;

        while (--dy)
        {
            vngo_dzhline8(y,&tri,vp);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_z += tri.long_z_step;
        }
    }
    return;
}



//�������������������������������������������������������������������������Ŀ
//  vngo_poly8(VngoVbuffer *vb, int count, VngoPoint *pts);                 �
//      Draws an N sided convex polygon, by breaking it down into triangles �
//      if it is not already a triangle.  It draws in a solid color.        �
//���������������������������������������������������������������������������
void vngo_poly8 (VngoVport *vp,int count,VngoPoint *pts)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                    vngo_ztriangle8 (vp,tpts,pts[0].clr);
                else
                    vngo_triangle8 (vp,tpts,pts[0].clr);
            }
        }
        //
        // It would be nice to do some pixel and line degeneration here.
        //
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_ztriangle8 (vp,pts,pts[0].clr);
        else
            vngo_triangle8 (vp,pts,pts[0].clr);
    }
}






//��� End of module - vngtri.cpp ���