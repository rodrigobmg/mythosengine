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
//��������������������� Microsoft Windows '95 Version �����������������������
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
// espntdrw.cpp
//
// Contains the code for the EschPointDraw class which is a colored point
// in 3-space.  The point is not lit.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern EschPoint EschTempPoint;
extern VngoPoint EschTempVPoint;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPointDraw - draw                                                     �
//                                                                          �
// Draws the given point using the current drawing context.                 �
//���������������������������������������������������������������������������
void EschPointDraw::draw()
{
    EschCamera          *cam;

//��� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschPointDraw::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschPointDraw::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//��� Transform into copy of point
    pos.transform(&cam->eye.iorient,&EschTempPoint);

//��� Clip against view volume

    // Near/far clipping
    if (EschTempPoint.z.flx > cam->yon.flx
        || EschTempPoint.z.flx < cam->hither.flx)
        return;

    // Left/right/top/bottom plane clipping
    Flx16 zx = flx_16mul16(EschTempPoint.z,cam->xsize);
    Flx16 zy = flx_16mul16(EschTempPoint.z,cam->ysize);

    if (EschTempPoint.x.flx < -zx.flx 
        || EschTempPoint.x.flx > zx.flx
        || EschTempPoint.y.flx < -zy.flx
        || EschTempPoint.y.flx > zy.flx)
        return;

    flags |= ESCH_DRW_VISIBLE;

//��� Project pixel
    EschTempVPoint.x = (flx_muldiv(EschTempPoint.x,
                                   cam->xscalar,
                                   EschTempPoint.z).flx
                        + (cam->vport->vbuff.width<<15)) >> 16;
    EschTempVPoint.y = ((cam->vport->vbuff.height<<15)
                        - flx_muldiv(EschTempPoint.y,
                                     cam->yscalar,
                                     EschTempPoint.z).flx) >> 16;
    EschTempVPoint.z = flx_16mul16(EschTempPoint.z,cam->z_factor).flx << 1;
    EschTempVPoint.clr = color;

    VngoVport *vport = cam->vport;

    assertMyth("EschPointDraw::draw needs palette in viewport",
               vport->vbuff.pal != 0);
    EschTempVPoint.shade = vport->vbuff.pal->shd_pal->mid_point;

//��� Draw pixel
    vport->pixel(&EschTempVPoint);
}

//��� End of module - espntdrw.cpp ���