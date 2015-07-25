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
// esgeom.hpp
//
//      Contains the EschGeometry objects for drawing 3D objects.
//
//      EschGeometry is the abstract base class for the 3D objects which
//      includes the tree connections, frame of reference, extents, and
//      various object operations.
//
//���������������������������������������������������������������������������

#ifndef __ESGEOM_HPP
#define __ESGEOM_HPP    1

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
#include <xfile.hpp>

#include "esdraw.hpp"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschExtents - Object extent class for 3D objects.                        �
//���������������������������������������������������������������������������
class EschExtents {

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    dword           flags;
    EschPoint       center;                 // Radial extents
    Flx16           radius;
    Flx16           mins[3];                // Box extents
    Flx16           maxs[3];

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschExtents() { flags=0; }
    // EschExtents(EschExtents *e) { *this=*e; }

    ~EschExtents() {}

    //���������������������������������������������������������������������Ŀ
    // Operations on extents objects.                                       �
    //�����������������������������������������������������������������������
    void draw(const EschFrameRef *fr, dword clr, int box=0) const;

    int hit(const EschPoint *pt, int box=0) const;
    int hit(const EschPoint *pt, const Flx16 r) const;
};

//�������������������������������������������������������������������������Ŀ
// EschGeometry - Abstract base class for 3D drawable objects.              �
//���������������������������������������������������������������������������
class EschGeometry : public EschDrawable {

protected:
    EschGeometry    *iparent;               // Geometry tree pointers.
    EschGeometry    *ichild;
    
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    EschFrameRef    local;
    EschFrameRef    world;

    EschExtents     exts;                   // Object extents.
    
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschGeometry() { iparent=ichild=0; };
    
    virtual ~EschGeometry();
    
    //���������������������������������������������������������������������Ŀ
    // Operations on geometry objects.                                      �
    //�����������������������������������������������������������������������
    virtual void draw(void);
    
    EschGeometry *next(void) { return (EschGeometry*)inext; }
    EschGeometry *prev(void) { return (EschGeometry*)iprev; }
    EschGeometry *parent(void) { return iparent; }
    EschGeometry *child(void) { return ichild; }
    
    virtual void sibling(EschGeometry *myprev);
    virtual void adopt(EschGeometry *myparent);
    virtual void remove(int delchild=0);

    virtual EschDrawable *find(const char *dname);

    int hit(const EschPoint *pt, int box=0) const
    {
        EschPoint   p;
        pt->transform(&world.iorient,&p);
        return exts.hit(&p,box);
    }
    int hit(const EschPoint *pt, const Flx16 r) const
    {
        EschPoint   p;
        pt->transform(&world.iorient,&p);
        return exts.hit(&p,flx_16div16(r,world.scalef));
    }
    void draw_extents(dword clr, int box=0) const { exts.draw(&world,clr,box); }

    //���������������������������������������������������������������������Ŀ
    // Utility functions for working with frame of reference.               �
    //�����������������������������������������������������������������������
    void get_position(EschPoint *pt) const
    {
        local.get_position(pt);
    }
    
    void set_position(const EschPoint *pt)
    {
        local.set_position(pt);
        compute_world();
    }
    void set_position(const Flx16 ix, const Flx16 iy, const Flx16 iz)
    {
        local.set_position(ix,iy,iz);
        compute_world();
    }
    
    void rotatex(const Flx16 degrees)
    {
        local.rotatex(degrees);
        compute_world();
    }
    void rotatey(const Flx16 degrees)
    {
        local.rotatey(degrees);
        compute_world();
    }
    void rotatez(const Flx16 degrees)
    {
        local.rotatez(degrees);
        compute_world();
    }
    
    void rotate(const EschVector *v, const Flx16 degrees)
    {
        local.rotate(v,degrees);
        compute_world();
    }
    
    void pitch(const Flx16 degrees)
    {
        local.pitch(degrees);
        compute_world();
    }
    void roll(const Flx16 degrees)
    {
        local.roll(degrees);
        compute_world();
    }
    void yaw(const Flx16 degrees)
    {
        local.yaw(degrees);
        compute_world();
    }
    
    void translate(const Flx16 idx, const Flx16 idy, const Flx16 idz)
    {
        local.translate(idx,idy,idz);
        compute_world();
    }
    void translate(const EschVector *v)
    {
        local.translate(v);
        compute_world();
    }
    
    void move(const Flx16 idx, const Flx16 idy, const Flx16 idz)
    {
        local.move(idx,idy,idz);
        compute_world();
    }
    void move(const EschVector *v)
    {
        local.move(v);
        compute_world();
    }
    
    void scale(const Flx16 is)
    {
        local.scale(is);
        compute_world();
    }
    
    void orthogonalize(void)
    {
        local.orthogonalize();
        compute_world();
    }

    void reset(void)
    {
        local.reset();
        compute_world();
    }
    
    //���������������������������������������������������������������������Ŀ
    // Compute function for updating world frame of reference.              �
    //�����������������������������������������������������������������������
    void compute_world(void);
};


//�������������������������������������������������������������������������Ŀ
// EschFace - Support object contains the definition of a triangular face   �
//���������������������������������������������������������������������������
class EschFace {

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    dword           flags;                  // Face flags
    word            a;                      // Triangle verticies.
    word            b;
    word            c;
    word            txt;                    // Texture index (0 for none).
    Flx16           u[3];                   // Texture map coords.
    Flx16           v[3];
    dword           color;                  // Base-color
    EschVector      normal;                 // Face normal.

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschFace() {}
    EschFace(dword _f, word _a, word _b, word _c, word _txt,
             Flx16 _u0, Flx16 _u1, Flx16 _u2,
             Flx16 _v0, Flx16 _v1, Flx16 _v2,
             dword _clr, Flx16 _i, Flx16 _j, Flx16 _k)
    {
        flags = _f;
        a = _a;
        b = _b;
        c = _c;
        txt = _txt;
        u[0] = _u0;
        u[1] = _u1;
        u[2] = _u2;
        v[0] = _v0;
        v[1] = _v1;
        v[2] = _v2;
        color = _clr;
        normal.i = _i;
        normal.j = _j;
        normal.k = _k;
    }
              

    ~EschFace() {}
};



//�������������������������������������������������������������������������Ŀ
// EschMesh - Container object for a mesh of triangular faces.              �
//���������������������������������������������������������������������������
class EschMesh {

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    ulong           ref_count;              // Reference count for attachments

    dword           flags;
    char            name[ESCH_MAX_NAME];

    EschExtents     exts;                   // Object extents.

    ulong           nverts;                 // Vertex data.
    IvoryHandle     v;

    ulong           nfaces;                 // Face data.
    IvoryHandle     f;

    ulong           tmax;                   // Original texture data.
    EschTexture     *txt;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschMesh(const char *fname=0, const char *oname=0,
             VngoPal *pal=0, EschMatrix *m=0, char *pn=0);

    virtual ~EschMesh();

    //���������������������������������������������������������������������Ŀ
    // Operations on mesh objects.                                          �
    //�����������������������������������������������������������������������
    esch_error_codes release(void);

    //���������������������������������������������������������������������Ŀ
    // I/O Routines.                                                        �
    //�����������������������������������������������������������������������
    virtual esch_error_codes load(const char *fname, const char *oname=0,
                                  VngoPal *pal=0, EschMatrix *m=0, char *pn=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname=0,
                                  VngoPal *pal=0, EschMatrix *m=0, char *pn=0);
};


//�������������������������������������������������������������������������Ŀ
// EschMeshDraw - Drawing instance attached to a mesh object.               �
//���������������������������������������������������������������������������
class EschMeshDraw : public EschGeometry {

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    EschMesh        *mesh;                  // Attached EschMesh object

    ulong           tmax;                   // Instance texture data.
    EschTexture     *txt;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschMeshDraw(EschMesh *mdata=0);
    EschMeshDraw(const char *fname, const char *oname=0,
                 VngoPal *pal=0, EschMesh *msh=0, char *pn=0);

    virtual ~EschMeshDraw();

    //���������������������������������������������������������������������Ŀ
    // Operations on MeshDraw objects.                                      �
    //�����������������������������������������������������������������������
    virtual void draw(void);
    
    // Attaches/detatches an EschMesh object to the mesh
    esch_error_codes attach(EschMesh *mdata);
    void detach(void);

    //���������������������������������������������������������������������Ŀ
    // Utilities functions for loading EschMeshDraw and associated EschMesh.�
    //�����������������������������������������������������������������������
    virtual esch_error_codes load(const char *fname, const char *oname=0,
                                  VngoPal *pal=0, EschMesh *msh=0, char *pn=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname=0,
                                  VngoPal *pal=0, EschMesh *msh=0, char *pn=0);
};

//���������������������������������������������������������������������������
//
//                               Prototypes
//
//���������������������������������������������������������������������������

extern "C" void esch_clipdraw_face(ulong ind, int doclip=1, VngoRect *drect=0,int dobfcul=0);
extern "C" void esch_clip_poly(VngoVbuffer *vport,VngoPoint *points, ulong *n_vertices);
extern "C" void esch_zclip_poly(Flx16 hither, Flx16 yon,VngoPoint *points, ulong *n_vertices);
extern "C" void esch_clip_x_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern "C" void esch_clip_y_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern "C" void esch_clip_z_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern "C" int esch_rotate_check(ulong count,VngoPoint *pts);

#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) esch_clipdraw_face;
#pragma aux (_ASMSTKCALL_) esch_clip_poly;
#pragma aux (_ASMSTKCALL_) esch_clip_x_line;
#pragma aux (_ASMSTKCALL_) esch_clip_y_line;
#pragma aux (_ASMSTKCALL_) esch_clip_z_line;
#pragma aux (_ASMSTKCALL_) esch_rotate_check;

#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - esgeom.hpp ���
