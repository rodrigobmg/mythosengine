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
// global.hpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __GLOBAL_HPP
#define __GLOBAL_HPP    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

// NOTE: the including file must define any Windows control defines

#include <windows.h>
#include <stdio.h>

#include "portable.h"
#include "debug.h"

#include <chronos.hpp>
#include <ivory.hpp>
#include <max.hpp>
#include <vangogh.hpp>
#include <gutenbrg.hpp>

#include "escher.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#if defined (WIN32)
        #define IS_WIN32 TRUE
#else
        #define IS_WIN32 FALSE
#endif
#define IS_NT      IS_WIN32 && (BOOL)(GetVersion() < 0x80000000)
#define IS_WIN32S  IS_WIN32 && (BOOL)(!(IS_NT) && (LOBYTE(LOWORD(GetVersion()))<4))
#define IS_CHICAGO (BOOL)(!(IS_NT) && !(IS_WIN32S)) && IS_WIN32

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class EscherTest
{
protected:
    TCHAR   szFileName[MAX_PATH];

    MaxDevices      *devs;
    MaxEventSource  *evt;           // Source of our events
    MaxEventListOneshot oneshot;    // Track events for single_events
    MaxEventListToggle  toggles;
    MaxEventList    events;         // Most current event set
    MaxEventList    single_events;  // Most current event set, momentary
    MaxEventList    toggle_events;

    void draw_extents(EschMeshDraw *ptr);

public:     // Construction/Destruction
//    enum { MAP_XSIZE = 320, MAP_YSIZE = 240 };
//    enum { MAP_XSIZE = 640, MAP_YSIZE = 480 };
    enum { MAP_XSIZE = 284, MAP_YSIZE = 256 };
//    enum { MAP_XSIZE = 144, MAP_YSIZE = 128 };
//    enum { MAP_XSIZE = 400, MAP_YSIZE = 400};

    BITMAPINFO      *bmi;
    BYTE            *gmap;
    VngoVport       *gvp;
    VngoPal         *mypal;
    HPALETTE        hpal;
    HDC             hdc;

    VngoScreenManager  *screen;
    int             map_xsize;
    int             map_ysize;

    EscherTest (MaxDevices *);
    ~EscherTest ();

    BOOL    active;

    BOOL    show_fps;
    BOOL    pick_test;
    BOOL    collide_test;
    BOOL    use_new_terrain;
    float   mbox_size;
    long    alpha;

    // key-frame animation data
    BOOL    keyframe_animation;
    float   anim_time;
    float   anim_step_time;
    float   anim_current_step;
    int     anim_current_frame;
    int     anim_chain_count;
    float   anim_max_compress;
    EschKeyframeDraw *anim_root;
    float   scale;

    // particle system data
    int     part_count;
    float   part_speed;
    float   part_life;
    int     part_linear;
    int     part_alpha;
    float   part_rotrate;
    float   part_rotrate_low;
    float   part_rotrate_high;

    EschCameraEx            *cam;
    EschLight               *light;
    EschDrawable            *draws;
    EschScene               *scene;
    EschTerrain             *terrain;
    EschParticleGenerator   *prtgen;
    EschStarfield           *starfield;
    EschPlosion             *explosion;
    EschMeshDraw            *curmesh;
    EschFireTexture         *fire;
    EschPartition           *partn;
    EschSprite              *sprite;
    EschMetabox             *metabox;
    EschPlaneDraw           *plane;
    EschMultiFrameTexture   *mtxt;
    EschTerrainTreeTop      *trees;
    int                     drawexts;
    int                     drawpartn;
    dword                   exts_color;
    float                   RotateDegrees;
    float                   ScriptRotateDegrees;

    XFBitmap                *backgrnd;

    Chronometer             fps_clock;
    long                    frames;
    long                    total_frames;
    long                    total_time;

    Chronometer             clock;
    Chronometer             anim_clock;

    BOOL SetupFireTest();
    BOOL SetupPartitionTest(const char *buff);
    BOOL SetupMultiTest(const char *name);
    BOOL SetupSprite(const char *name);

    BOOL LoadScene(char *fn, dword in_type=ESCH_SCENELD_ALL);
    BOOL LoadTreeTops(const char *buff);
    BOOL LoadTerrain(char *fn);
    BOOL SetupParticleSystem(const char *name);
    BOOL SetupStarfield(BOOL fixed, BOOL brights);
    BOOL SetupExplosion(const char *buff);
    BOOL SetupMetabox(const char *buff);
    BOOL SetupPlane(const char *buff);
    BOOL SetupAnimation(const char *buff);
    void update_keys(float interval);

    void Animate();

    void Begin();
    void End(char *buff);

            // Per-Frame Members
    virtual BOOL    PumpWindows ();
    virtual void    LoadEvents (LPCSTR lpszFile);
    virtual void    GetEvents ();
    virtual void    ProcessEvents();
    virtual void    Render();
    virtual void    Display();

    int MessageBox(LPCSTR lpText, UINT nType);
};


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Prototypes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                 Data
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

extern HINSTANCE   hInst;         // current instance
extern HWND        hWndClient;    // Main window handle
extern const char  szAppName[];
extern EscherTest   *game;


#endif

//葦� End of header - global.hpp 憶�

