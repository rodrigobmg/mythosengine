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
// esgeom.hpp
//
// Contains the EschGeometry, derived, and support classes for drawing 3D
// objects.
//
// EschGeometry is the abstract base class for the 3D objects which includes
// the tree connections, frame of reference, extents, and various object
// operations.
//
// EschFace is the container type for triangular face data.
//
// EschMesh is the container type for polygonal mesh data used by the
// EschMeshDraw class.
//
// EschMeshDraw is the drawable type which displays polygonal mesh objects.
// It includes the EschGeometry interface.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESGEOM_HPP
#define __ESGEOM_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <xfile.hpp>

#include "esdefs.h"
#include "esdraw.hpp"
#include "esexts.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschGeometry - Abstract base class for 3D drawable objects.              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschGeometry : public EschDrawable {

protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected data members                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschGeometry    *iparent;               // Geometry tree pointers
    EschGeometry    *ichild;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschFrameRef    local;                  // Local to parent frame-of-ref
    EschFrameRef    world;                  // Local to world frame-of-ref

    EschSphereExtents   *sphere;            // Object extents
    EschSphereExtents   exts;               // Extents inclusive of children

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschGeometry();
    EschGeometry(const EschGeometry &g);

    virtual ~EschGeometry();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Accessor functions                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschGeometry *next() const { return (EschGeometry*)inext; }
    EschGeometry *prev() const { return (EschGeometry*)iprev; }
    EschGeometry *parent() const { return iparent; }
    EschGeometry *child() const { return ichild; }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschGeometry &operator = (const EschGeometry &geom);

    virtual void draw();

    virtual void sibling(EschDrawable *myprev);
    virtual void sibling(EschGeometry *myprev, dword update=ESCH_UPD_ALL);
    virtual void adopt(EschGeometry *myparent, dword update=ESCH_UPD_ALL);
    virtual void remove(int delchild=0, dword update=ESCH_UPD_ALL);

    virtual EschDrawable *find(const char *dname) const;

    virtual int get_extents(EschSphereExtents *sp) const;

    virtual float ray(const EschPoint *pt, const EschVector *v, int coarse=0) const;

    virtual int hit(const EschPoint *pt, const float r, int coarse=0) const;

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

    virtual void animate();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void draw_extents(dword clr) const
    {
        exts.draw(&world,clr);
    }

    void get_position(EschPoint *pt) const
    {
        local.get_position(pt);
    }

    void set_position(const EschPoint *pt, dword update=ESCH_UPD_ALL)
    {
        local.set_position(pt,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void set_position(const float ix, const float iy, const float iz, dword update=ESCH_UPD_ALL)
    {
        local.set_position(ix,iy,iz,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void set_top(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.set_top(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void set_top(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        local.set_top(ii,ij,ik,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void set_direction(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.set_direction(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void set_direction(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        local.set_direction(ii,ij,ik,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void rotatex(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotatex(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void rotatey(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotatey(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void rotatez(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotatez(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void rotate(const EschVector *v, const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotate(v,degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void pitch(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.pitch(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void roll(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.roll(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void yaw(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.yaw(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void translate(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        local.translate(idx,idy,idz,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void translate(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.translate(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void move(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        local.move(idx,idy,idz,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void move(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.move(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void scale(const float is, dword update=ESCH_UPD_ALL)
    {
        local.scale(is,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void orthogonalize(dword update=ESCH_UPD_ALL)
    {
        local.orthogonalize(update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void orthogonalize_top(dword update=ESCH_UPD_ALL)
    {
        local.orthogonalize_top(update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void orthogonalize_right(dword update=ESCH_UPD_ALL)
    {
        local.orthogonalize_right(update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void reset(dword update=ESCH_UPD_ALL)
    {
        local.reset();
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Compute functions                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void compute_world(dword update=ESCH_UPD_ALL);
    void compute_extents(int partialfix=0, int doparent=1);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschFace - Support object contains the definition of a triangular face   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschFace {

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    dword           flags;                  // Face flags
    word            a;                      // Triangle verticies.
    word            b;
    word            c;
    word            txt;                    // Texture index (0 for none).
    float           u[3];                   // Texture map coords.
    float           v[3];
    dword           color;                  // Base-color
    EschVector      normal;                 // Face normal.
    byte            self_illum;             // Self-illumination value (0=off)
    byte            alpha_a;                // Triangle alpha values
    byte            alpha_b;
    byte            alpha_c;
    void            *app_data;              // Application data pointer

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschFace() : app_data(0) {}
    EschFace(dword _f, word _a, word _b, word _c, word _txt,
             float _u0, float _u1, float _u2,
             float _v0, float _v1, float _v2,
             dword _clr, float _i, float _j, float _k,
             byte _si=0,
             byte _aa=255, byte _ab=255, byte _ac=255, void *_app=0) :
        flags(_f),
        a(_a), b(_b), c(_c),
        txt(_txt),
        color(_clr),
        normal(_i,_j,_k),
        self_illum(_si),
        alpha_a(_aa),
        alpha_b(_ab),
        alpha_c(_ac),
        app_data(_app)
    {
        u[0] = _u0;
        u[1] = _u1;
        u[2] = _u2;
        v[0] = _v0;
        v[1] = _v1;
        v[2] = _v2;
    }

    ~EschFace() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_flags(const dword f) { flags = f; }
    void set_flags(const dword m, const int on)
    {
        if (on)
            flags |= m;
        else
            flags &= ~m;
    }

    void set_app_data(void *p) { app_data = p; }

    long get_alpha() const { return alpha_a; }
    void set_alpha(long alpha) { alpha_a = (byte)alpha; }
};


class EschTexture;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMesh - Container object for a mesh of triangular faces.              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschMesh {

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    ulong           ref_count;              // Reference count for attachments

    dword           flags;
    char            name[ESCH_MAX_NAME];

    EschSphereExtents   sphere;             // Object extents.
    EschBoxExtents      box;

    ulong           nverts;                 // Vertex data.
    IvoryHandle     v;

    ulong           nfaces;                 // Face data.
    IvoryHandle     f;

    ulong           tmax;                   // Original texture data.
    EschTexture     **txt;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschMesh();
    EschMesh(const char *fname, const char *oname=0,
             VngoPal *pal=0, EschMatrix *m=0, char *pn=0,
             dword ctrlfl=ESCH_MSHLD_ALL);
    EschMesh(const EschMesh &msh);

    virtual ~EschMesh();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschMesh &operator = (const EschMesh &msh);

    virtual esch_error_codes release();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_flags(const dword f) { flags = f; }
    void set_flags(const dword m, const int on)
    {
        if (on)
            flags |= m;
        else
            flags &= ~m;
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // I/O Routines.                                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual esch_error_codes load(const char *fname, const char *oname=0,
                                  VngoPal *pal=0, EschMatrix *m=0, char *pn=0,
                                  dword ctrlfl=ESCH_MSHLD_ALL);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname=0,
                                  VngoPal *pal=0, EschMatrix *m=0, char *pn=0,
                                  dword ctrlfl=ESCH_MSHLD_ALL);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMeshDraw - Drawing instance attached to a mesh object.               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschMeshDraw : public EschGeometry {

    static EschMeshDraw *clone_helper(EschMeshDraw *_parent,
                                      const EschMeshDraw *_refmsh, int dupmf);

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschMesh        *mesh;                  // Attached EschMesh object

    ulong           tmax;                   // Instance texture data.
    EschTexture     **txt;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschMeshDraw(EschMesh *mdata=0);
    EschMeshDraw(const char *fname, const char *oname=0,
                 VngoPal *pal=0, EschMesh *msh=0, char *pn=0,
                 dword ctrlfl=ESCH_MSHLD_ALL);
    EschMeshDraw(const EschMeshDraw &msdh);

    virtual ~EschMeshDraw();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschMeshDraw &operator = (const EschMeshDraw &mshd);

    virtual void draw();

    virtual float ray(const EschPoint *pt, const EschVector *v, int coarse=0) const;

    virtual int hit(const EschPoint *pt, const float r, int coarse=0) const;

    virtual void animate();

    // Attaches/detatches an EschMesh object to the mesh
    esch_error_codes attach(EschMesh *mdata, dword update=ESCH_UPD_ALL);
    void detach();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void draw_extents(dword clr, int box=0) const
    {
        if (box)
        {
#ifdef assertMyth
            assertMyth("EschMeshDraw::draw_extents assumes attached mesh",
                       mesh != 0 && mesh->ref_count);
#endif
            if (mesh)
                mesh->box.draw(&world,clr);
        }
        else
            exts.draw(&world,clr);
    }

    EschMeshDraw *clone(int dupmf=1) const { return clone_helper(0, this, dupmf); }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // I/O Routines.                                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual esch_error_codes load(const char *fname, const char *oname=0,
                                  VngoPal *pal=0, EschMesh *msh=0, char *pn=0,
                                  dword ctrlfl=ESCH_MSHLD_ALL);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname=0,
                                  VngoPal *pal=0, EschMesh *msh=0, char *pn=0,
                                  dword ctrlfl=ESCH_MSHLD_ALL);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - esgeom.hpp 憶�

