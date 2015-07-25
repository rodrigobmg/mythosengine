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
//����������Copyright�(c)�1994,�1995�by�Charybdis�Enterprises,�Inc.����������
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
// escamera.hpp
//
//     The EschCamera object provides the viewing parameters for rendering
//     the object database.  EschCameras can be linked into lists, as
//     well as loaded from files.
//
//���������������������������������������������������������������������������

#ifndef __ESCAMERA_HPP
#define __ESCAMERA_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <portable.h>
#include <felix.hpp>
#include <vangogh.hpp>
#include <xfile.hpp>

#include "esmath.hpp"
#include "escontxt.hpp"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

class EschLight;

//�������������������������������������������������������������������������Ŀ
// EschCamera - Viewpoint within world space.                               �
//���������������������������������������������������������������������������
class EschCamera {

protected:
    EschCamera  *inext;                     // Linked-list pointers
    EschCamera  *iprev;

    //���������������������������������������������������������������������Ŀ
    // Internal render function which is overlayed by derived EschCameras.  �
    // This function will assume that the currently active context contains �
    // the required data for drawing.                                       �
    //�����������������������������������������������������������������������
    virtual void rend(void);

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members (should be changed only by utility functions).   �
    //�����������������������������������������������������������������������
    EschFrameRef    eye;                    // Eye <=> World transformation
    EschVector      top;                    // Top of head vector
    dword           flags;                  // Camera flags
    VngoVport       *vport;                 // VanGogh viewport for output
    Flx16           xscalar;                // 2D scale factor in X
    Flx16           yscalar;                // 2D scale factor in Y
    Flx16           xsize;                  // Projection-plane size in X
    Flx16           ysize;                  // Projection-plane size in Y
    Flx16           aspect_ratio;           // Aspect ratio (Y:X)
    Flx16           factor;                 // User scale factor
    Flx16           hither;                 // Distance to near clip plane
    Flx16           yon;                    // Distance to far clip plane
    Flx16           fov;                    // Field of view (degrees)
    dword           bcolor;                 // Background color for clear
    Flx16           radius_factor;          // Extent radius factor
    Flx16           z_factor;               // scale to appropriate z range.
    char            name[ESCH_MAX_NAME];    // Camera name

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschCamera(VngoVport *vport=0);
    EschCamera(const char *fname, const char *cname=0);
    // EschCamera(EschCamera *cam) { *this = *cam; }

    virtual ~EschCamera();

    //���������������������������������������������������������������������Ŀ
    // Operations on cameras.                                               �
    //�����������������������������������������������������������������������
    virtual void attach(VngoVport *vp);

    virtual void sibling(EschCamera *myprev);
    virtual void remove(void);

    EschCamera *next(void) { return inext; }
    EschCamera *prev(void) { return iprev; }

    virtual EschCamera *find(const char *cname);

    //���������������������������������������������������������������������Ŀ
    // Renders the view starting with the olist as the parent EschDrawable. �
    //�����������������������������������������������������������������������
    void render(void)
    {
        EschContext ec(EschCurrent);
        ec.camera = this;
        ec.push();
        rend();
        ec.pop();
    }
    void render(EschDrawable *olist)
    {
        EschContext ec(EschCurrent);
        ec.eschs = olist;
        ec.camera = this;
        ec.push();
        rend();
        ec.pop();
    }
    void render(EschLight *llist)
    {
        EschContext ec(EschCurrent);
        ec.camera = this;
        ec.lights = llist;
        ec.push();
        rend();
        ec.pop();
    }
    void render(EschDrawable *olist, EschLight *llist)
    {
        EschContext ec(EschCurrent);
        ec.eschs = olist;
        ec.lights = llist;
        ec.camera = this;
        ec.push();
        rend();
        ec.pop();
    }

    virtual void reset(void);

    //���������������������������������������������������������������������Ŀ
    // Utility functions for changing the camera's status and information.  �
    //�����������������������������������������������������������������������
    void set_top(const EschVector *t)
    {
        top=*t;
        top.normalize();
        compute_eye();
    }

    void set_top(const Flx16 ii, const Flx16 ij, const Flx16 ik)
    {
        top.i=ii;
        top.j=ij;
        top.k=ik;
        top.normalize();
        compute_eye();
    }

    void set_dir(const EschVector *d)
    {
        eye.dir=*d;
        eye.dir.normalize();
        compute_eye();
    }
    void set_dir(const Flx16 ii, const Flx16 ij, const Flx16 ik)
    {
        eye.dir.i=ii;
        eye.dir.j=ij;
        eye.dir.k=ik;
        eye.dir.normalize();
        compute_eye();
    }
 
    void set_vects(const EschVector *t,const EschVector *d);
    void set_vects(const Flx16 ti, const Flx16 tj, const Flx16 tk,
                   const Flx16 di, const Flx16 dj, const Flx16 dk)
    {
        EschVector t, d;

        t.i = ti;
        t.j = tj;
        t.k = tk;

        d.i = di;
        d.j = dj;
        d.k = dk;

        set_vects(&t,&d);
    }
 
    void get_position(EschPoint *pt) const
    {
        pt->x.flx = eye.orient.mtx[ESCH_MTX_J].flx;
        pt->y.flx = eye.orient.mtx[ESCH_MTX_K].flx;
        pt->z.flx = eye.orient.mtx[ESCH_MTX_L].flx;
    }
 
    void set_position(const EschPoint *pt) { eye.set_position(pt); }
    void set_position(const Flx16 ix, const Flx16 iy, const Flx16 iz)
        { eye.set_position(ix,iy,iz); }

    void set_lookat(const EschPoint  *pt);
    void set_lookat(const Flx16 ix, const Flx16 iy, const Flx16 iz)
    {
        EschPoint p;

        p.x = ix;
        p.y = iy;
        p.z = iz;

        set_lookat(&p);
    }
 
    void rotatex(const Flx16 degrees);
    void rotatey(const Flx16 degrees);
    void rotatez(const Flx16 degrees);
 
    void pitch(const Flx16 degrees);
    void yaw(const Flx16 degrees);
    void roll(const Flx16 degrees);
 
    void translate(const EschVector *v) { eye.translate(v->i,v->j,v->k); }
    void translate(const Flx16 ii, const Flx16 ij, const Flx16 ik)
                                        { eye.translate(ii,ij,ik); }
 
    void move(const EschVector *v) { eye.move(v->i,v->j,v->k); }
    void move(const Flx16 ii, const Flx16 ij, const Flx16 ik)
                                        { eye.move(ii,ij,ik); }
 
    void orthogonalize(void);

    void set_factor(const Flx16 f)
    {
        factor=f;
        compute_scalar();
        compute_eye();
    }
 
    void zoom(const Flx16 f)
    {
        factor=factor * f;
        compute_scalar();
        compute_eye();
    }
 
    void set_fov(const Flx16 f)
    {
        fov=f;
        compute_scalar();
    }

    void set_hither(const Flx16 h)
    {
        hither=h;
        compute_scalar();
    }
 
    void set_yon(const Flx16 y) 
    { 
       yon=y; 
       compute_z_factor();
    }
 
    void set_bcolor(const dword c=0)
    {
        bcolor=c;
    }
 
    void set_flags(const dword f) { flags=f; }
 
    //���������������������������������������������������������������������Ŀ
    // Compute functions to calculate viewing constants.                    �
    //�����������������������������������������������������������������������
    void compute_z_factor(void);
    void compute_scalar(void);
    void compute_eye(void);
 
    //���������������������������������������������������������������������Ŀ
    // I/O routines.                                                        �
    //�����������������������������������������������������������������������
    virtual esch_error_codes load(const char *fname, const char *cname=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *cname=0);
};


//�������������������������������������������������������������������������Ŀ
// EschCameraEx - Extended camera object.                                   �
//���������������������������������������������������������������������������
class EschCameraEx : public EschCamera {

protected:
    //���������������������������������������������������������������������Ŀ
    // Internal render function                                             �
    //�����������������������������������������������������������������������
    virtual void rend(void);

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members (should be changed only by utility functions).   �
    //�����������������������������������������������������������������������
    short           bg_offx;                // Bitmap Background window offset
    short           bg_offy;
    short           bg_w;                   // Bitmap Background size
    short           bg_h;
    XFBitmap        *bg_bitmap;             // Bitmap background
    dword           hz_near;                // Hazing near distance (scaled)
    dword           hz_far;                 // Hazing far distance (scaled)
    dword           hz_factor;              // Scale factor for Z to shade range
    VngoHazePal8    *hz_pal;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschCameraEx(VngoVport *vport=0);
    EschCameraEx(const char *fname, const char *cname=0);

    virtual ~EschCameraEx();

    //���������������������������������������������������������������������Ŀ
    // Utility functions for changing the camera's status and information.  �
    //�����������������������������������������������������������������������
    void set_bg_offset(short x, short y);
    void set_bg_size(short w, short h);
    void set_bg_bitmap(XFBitmap *bm, int owns=1);

#if 0
    void set_hz_palette(VngoHazePal8 *hp, int owns=0);
    void set_hz_range(Flx16 n, Flx16 f);
#endif
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - escamera.hpp ���
