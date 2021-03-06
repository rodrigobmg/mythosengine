//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
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
// Created by Tim Little & Chuck Walbourn
//
// esextsph.cpp
//
// EschSphereExtents is the container type for spherical extents.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSphereExtents - draw                                                 �
//                                                                          �
// Draws the spherical extents of the object.                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschSphereExtents::draw(const EschFrameRef *fr, dword clr) const
{
    long                x, y, rd;
    float               r;
    float               hither, yon;
    EschCamera          *cam;
    EschPoint           p;
    EschFrameRef        frame(0);

//陳� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschSphereExtents::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschSphereExtents::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//陳� Create local->world->eye transform (ignore inverse)
    if (fr)
        fr->orient.concat(&cam->eye.iorient,&frame.orient);
    else
        frame.orient = cam->eye.iorient;

//陳� Setup for compare
    yon = cam->yon;
    hither = cam->hither;

//陳� Transform center into view
    center.transform(&frame,&p);

//陳� Scale radius
    r = radius * fr->scalef * cam->radius_factor;

    assertMyth("EschSphereExtents::draw scaled to a negative radius",
               r >= 0);

//陳� Check for fully invisible against hither/yon
    if ( (p.z < hither)
         || (p.z > yon)
         || ((p.z + r) < hither)
         || ((p.z - r) > yon) )
        return;

//陳� Draw radial extent

    if (cam->flags & ESCH_CAM_ORTHO)
    {
        x = long(p.x * cam->xscalar)
            + (cam->vport->vbuff.width>>1);
        y = (cam->vport->vbuff.height>>1)
            - long(p.y * cam->yscalar);
        rd = long((p.x + r) * cam->xscalar)
             + (cam->vport->vbuff.width>>1) - x;
    }
    else
    {
        x = long((p.x * cam->xscalar) / p.z)
            + (cam->vport->vbuff.width>>1);
        y = (cam->vport->vbuff.height>>1)
            - long((p.y * cam->yscalar) / p.z);
        rd = long(((p.x + r) * cam->xscalar) / p.z)
             + (cam->vport->vbuff.width>>1) - x;
    }

    vngo_clip_circle(cam->vport,x,y,rd,clr);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSphereExtents - hit                                                  �
//                                                                          �
// Performs an intersection test input in the same coordinate system of the �
// extents.                                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschSphereExtents::hit(const EschPoint *pt) const
{
    assertMyth("EschSphereExtents::hit needs point",
               pt != 0);

    EschVector  p(pt->x - center.x,
                  pt->y - center.y,
                  pt->z - center.z);

//陳� Check for trivial reject
    float r = radius;
    float nr = - r;

    if (p.i > r
        || p.i < nr
        || p.k > r
        || p.k < nr
        || p.j > r
        || p.j < nr)
        return 0;

//陳� Check with true magnitude
    return  (((p.magnitude()) < r) ? 1 : 0);
}

int EschSphereExtents::hit(const EschPoint *pt, const float r) const
{
    assertMyth("EschSphereExtents::hit needs point and radius",
               pt != 0 && r >= 0);

    EschVector  p(pt->x - center.x,
                  pt->y - center.y,
                  pt->z - center.z);

//陳� Check for trivial reject
    float rs = radius + r;
    float nrs = - rs;

    if (p.i > rs
        || p.i < nrs
        || p.k > rs
        || p.k < nrs
        || p.j > rs
        || p.j < nrs)
        return 0;

//陳� Check with true magnitude
    return  (( (p.magnitude()) < rs )
             ? 1 : 0);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSphereExtents - ray                                                  �
//                                                                          �
// Computes the ray/sphere intersection of the ray starting at point and    �
// moving along the unit vector ray with the sphere defined by the center   �
// and the radius.                                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
float EschSphereExtents::ray(const EschPoint *pt, const EschVector *v) const
{
    EschVector tvect(center.x - pt->x,
                     center.y - pt->y,
                     center.z - pt->z);

    // tvect DOT v
    float dot = tvect.i*v->i
                + tvect.j*v->j
                + tvect.k*v->k;

    // (radius^2) - (tvect DOT tvect) + (dot * dot)
    float disc = (radius*radius) - (tvect.i*tvect.i
                                    + tvect.j*tvect.j
                                    + tvect.k*tvect.k) + (dot*dot);

    if (disc < 0)
        return 0;

    disc = esch_sqrt(disc);

    float t2 = dot+disc;
    if (t2 <= 0)
        return 0;

    float t1 = dot-disc;
    if (t1 <= 0)
        return t2;

    return t1;
}

//葦� End of module - esextsph.cpp 憶�

