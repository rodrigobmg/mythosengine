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
// esmisc.hpp
//
// Contains miscellaneous classes for use with Escher.
//
// EschStarfield is a space 'starfield' drawable.
//
// EschFireTexture is an animated procedural texture for flame.
//
// EschPlosion is a 'fire-tree' drawable which uses the EschFireTexture
// to create an explosion.
//
// EschMetabox is a 'manually' built cube which can be adjusted to produce
// a variety of solids.
//
// EschLevelOfDetail is a helper drawable for handling multiple levels of
// detail.
//
//���������������������������������������������������������������������������

#ifndef __ESMISC_HPP
#define __ESMISC_HPP    1

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

#include "esdraw.hpp"
#include "estxture.hpp"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschStarfield - Space 'starfield' drawable.                              �
//���������������������������������������������������������������������������
class EschStarfield : public EschDrawable
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    ulong       count;
    EschPoint   *stars;
    dword       *brightness;
    dword       color;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschStarfield() :
        EschDrawable(ESCH_DRWT_STARFIELD),
        stars(0),
        brightness(0) {}

    virtual ~EschStarfield();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    const EschStarfield &operator = (const EschStarfield &sf);

    virtual void draw();

    virtual void release();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    void set_color(dword c) { color=c; }

    esch_error_codes create_stars(ulong c, int dobrights=1);
};


//�������������������������������������������������������������������������Ŀ
// EschFireTexture - Procedural fire texture.                               �
//���������������������������������������������������������������������������
class EschFireTexture : public EschProceduralTexture
{
    //���������������������������������������������������������������������Ŀ
    // Private data members.                                                �
    //�����������������������������������������������������������������������
    int     u_shift;
    int     decay;
    int     more_fire;
    int     fb_control;
    int     taper;
    byte    *flame_bytes;
    byte    *flames;

    //���������������������������������������������������������������������Ŀ
    // Private color translation tables.                                    �
    //�����������������������������������������������������������������������
    byte    *write_lut;

    //���������������������������������������������������������������������Ŀ
    // Private utility functions.                                           �
    //�����������������������������������������������������������������������
    esch_error_codes setup_local_tables();

    void smooth_baseline();
    byte get (int u, int v) { return (flames[(v << u_shift)+u]); }
    void put (int u, int v, int intensity)
    {
        int t = (v << u_shift) + u;
        flames[t] = intensity;
        txt.tex[t] = write_lut[intensity];
    }

    void make_lut(VngoPal *vpal);
    VngoColor24bit to_RGB(Flx16 h, Flx16 s, Flx16 i);

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschFireTexture();
    EschFireTexture(ushort w, ushort h, VngoPal *pal, int dogen=1);

    virtual ~EschFireTexture();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void release();
    virtual esch_error_codes init(ushort w, ushort h, VngoPal *pal,
                                  int dogen=1);
    virtual void generate();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    void increase(int amount=2) 
    {
        if (more_fire + amount < 20)
           more_fire += amount;
        else
           more_fire = 20;
    }
    void decrease(int amount=2) 
    {
        if (more_fire - amount > -20)
           more_fire -= amount;
        else
           more_fire = -20;
    }

    void ignite();
    void douse(int smooth_it=1);
    void fireball(int start_fireball=1);
};


//�������������������������������������������������������������������������Ŀ
// EschPlosion - A explosion effect drawable.                               �
//���������������������������������������������������������������������������
class EschPlosion : public EschDrawable
{
protected:
    EschFrameRef    world;
    EschTexture     *fire;
    Flx16           step;
    Flx16           fv;
    long            alpha_level;

    void check_workspace();

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    Flx16   width;
    Flx16   height;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschPlosion() : EschDrawable(ESCH_DRWT_EXPLOSION), fire(0), fv(0.90),
                    alpha_level(255)                  { check_workspace(); }
    EschPlosion(Flx16 w, Flx16 h, EschFireTexture *f);

    virtual ~EschPlosion() {}

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void draw();
    virtual void animate();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    void get_position(EschPoint *p) const
    {
        world.get_position(p);
    }

    void set_position(Flx16 ix, Flx16 iy, Flx16 iz, dword update=ESCH_UPD_ALL)
    {
        world.set_position(ix, iy, iz, update);
    }
    void set_position(const EschPoint *pnt, dword update=ESCH_UPD_ALL)
    {
        world.set_position(pnt->x, pnt->y, pnt->z, update);
    }

    void set_top(Flx16 ii, Flx16 ij, Flx16 ik, dword update=ESCH_UPD_ALL);
    void set_top(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        set_top(v->i, v->j, v->k, update);
    }

    void set_direction(Flx16 ii, Flx16 ij, Flx16 ik, dword update=ESCH_UPD_ALL);
    void set_direction(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        set_direction(v->i, v->j, v->k, update);
    }

    void set_size(Flx16 w, Flx16 h)
    {
        width=w;
        height=h;
    }

    void set_fire(EschTexture *f) { fire=f; }

    void set_step(Flx16 i) { step=i; }

    void reset() { fv=Flx16(0.90); }

    void set_alpha(long alpha) { alpha_level = alpha; }
    long get_alpha() const { return alpha_level; }
};


//�������������������������������������������������������������������������Ŀ
// EschMetabox - A controllable box drawable.                               �
//���������������������������������������������������������������������������
class EschMetabox : public EschDrawable
{
protected:
    long            alpha_level;

    void check_workspace();

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    EschFrameRef    world;
    EschPoint       corner[8];
    dword           color[6];
    EschTexture     *txt[6];
    Flx16           u[4];
    Flx16           v[4];

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschMetabox();
    virtual ~EschMetabox();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    const EschMetabox &operator = (const EschMetabox &that);

    virtual void draw();
    virtual void animate();
    virtual void release();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    void get_position(EschPoint *p) const
    {
        world.get_position(p);
    }

    void set_position(Flx16 ix, Flx16 iy, Flx16 iz, dword update=ESCH_UPD_ALL)
    {
        world.set_position(ix, iy, iz, update);
    }
    void set_position(const EschPoint *pnt, dword update=ESCH_UPD_ALL)
    {
        world.set_position(pnt->x, pnt->y, pnt->z, update);
    }

    void set_top(Flx16 ii, Flx16 ij, Flx16 ik, dword update=ESCH_UPD_ALL);
    void set_top(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        set_top(v->i, v->j, v->k, update);
    }

    void set_direction(Flx16 ii, Flx16 ij, Flx16 ik, dword update=ESCH_UPD_ALL);
    void set_direction(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        set_direction(v->i, v->j, v->k, update);
    }

    void set_color(dword clr, int face = -1);
    void set_texture(EschTexture *t, int face = -1);
    void set_texture_uv(Flx16 u1, Flx16 v1,
                        Flx16 u2, Flx16 v2,
                        Flx16 u3, Flx16 v3,
                        Flx16 u4, Flx16 v4)
    {
        u[0] = u1;  u[1] = u2;  u[2] = u3;  u[3] = u4;
        v[0] = v1;  v[1] = v2;  v[2] = v3;  v[3] = v4;
    }

    void create_cube(Flx16 size);

    void set_alpha(long alpha) { alpha_level = alpha; }
    long get_alpha() const { return alpha_level; }
};


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - Level of detail drawable.                            �
//���������������������������������������������������������������������������
class EschLevelOfDetail : public EschDrawable
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    ushort          nlevels;
    ushort          current;
    ushort          change;
    ushort          na;
    dword           color;
    EschGeometry    *geom[ESCH_LOD_MAX_LEVELS];
    static Flx16    dist[ESCH_LOD_MAX_LEVELS];

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschLevelOfDetail();

    virtual ~EschLevelOfDetail();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    const EschLevelOfDetail &operator = (const EschLevelOfDetail &that);

    virtual EschDrawable *find(const char *dname) const;

    virtual void draw();

    virtual int get_extents(EschSphereExtents *sp) const;

    virtual Flx16 ray(const EschPoint *pt, const EschVector *v, int coarse=0) const;

    virtual int hit(const EschPoint *pt, const Flx16 r, int coarse=0) const;

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

    virtual void animate();

    virtual void release();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    int add(EschGeometry *g);

    void set_nlevels(ushort n) { nlevels=n; }
    void set_current(ushort n) { current=n; }

    void set_color(dword c) { color=c; }

    static void set_dist(ushort lvl, Flx16 d);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - esmisc.hpp ���
