//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                        樛樛樛樛樛                       樛樛
//     敖朕                栩�     栩�                     渟栩
//     �  �       敖朕     栩�     栩�   樛樛      樛樛�    栩� 樛�
//     �  � 敖朕  �  �     栩桀樛樂栩�  �  渟�    栩�   炳  栩栩桎栩
//     �  � �  �  �  �     栩�     栩�  樂栩栩�  栩�        栩�   栩�
//    O� O� �  �  �  �     栩�     栩� 渟�  栩�  栩�    樂  栩�   栩�
//          �  � O� O�    樂栩樛樂栩�   栩栩毯桀  炳桀樂�  樂栩� 樂栩�
//         O� O�
//                            C++ Music, Sound, and Effects Library
//                               Microsoft Windows 95/98/NT Version
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
// Created by Dan Higdon & Chuck Walbourn
//
// bachdigi.hpp
//
// BachSample - Base sample container class
//
// BachStaticSample - Static sample container class
//
// BachSample3D - 3D static sample container class
//
// BachFileSample - Sample that plays from a file
//
// BachDigital - Digital sound source class
//
// BachDigital3D - Digital 3D sound source class
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __BACHDIGI_HPP
#define __BACHDIGI_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <dsound.h>

//陳� Charybdis headers
#include <debug.h>
#include <portable.h>
#include <ivory.hpp>
#include <xfile.hpp>

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Bach Library Includes                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#include "bachdefs.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class BachDigital;
class BachDigital3D;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭 Sample Classes 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachSample - Base class for digital samples                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BachSample
{
protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected data members                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    IDirectSound        *dsound;            // DSound instanace
    IDirectSoundBuffer  *sbuffer;           // DSound buffer

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Internal routines                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    enum { db_table_size=128 };

    static short db_table[db_table_size];
    static short db_table_find(int i);

    virtual bach_err_codes createbuffer(WAVEFORMATEX *wfmt)=0;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members.                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    dword           flags;                  // Sample flags
    bach_digi_fmt   fmt;                    // Sample format
    ulong           rate;                   // Sample rate
    void            *app_data;              // Application data

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructor                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BachSample (BachDigital *digi);
    BachSample (BachSample const &b);

    virtual ~BachSample();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BachSample &operator = (BachSample const &that);

    //陳� Free all associated data
    virtual void release ();

    //陳� Play controls
    virtual bach_err_codes play (int loop = 0)=0;
    virtual bach_err_codes stop ()=0;
    virtual bach_err_codes pause()=0;
    virtual bach_err_codes resume()=0;
    virtual dword status() const=0;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_app_data(void *p) { app_data = p; }

    void set_flags(dword f) { flags = f; }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - Static sample class                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BachStaticSample : public BachSample
{
protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Internal routines                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual bach_err_codes createbuffer(WAVEFORMATEX *wfmt);
    bach_err_codes restore();

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members.                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    ulong           length;                 // Sample length
    IvoryHandle     handle;                 // Sample data

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructor                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BachStaticSample (BachDigital *digi);
    virtual ~BachStaticSample();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Base class interface
    virtual void release ();
    virtual bach_err_codes play (int loop = 0);
    virtual bach_err_codes stop ();
    virtual bach_err_codes pause();
    virtual bach_err_codes resume();
    virtual dword status() const;

    //陳� Additional controls for static samples
    bach_err_codes set_volume (long vol);
    long get_volume () const;

    bach_err_codes set_pan (long heading);
    long get_pan () const;

    bach_err_codes set_playrate (ulong r);
    ulong get_playrate() const;

    bach_err_codes set_position (ulong p);
    ulong get_position() const;

    //陳� Create sample from data buffer
    bach_err_codes create(void *p, ulong l,
                          bach_digi_fmt f=BACH_DIGI_MONO_8,
                          ulong r=BACH_DIGI_DRIVERRATE);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    ulong get_playtime () const;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // I/O routines.                                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Load sample from disk
    bach_err_codes load_raw(const char *fname,
                            bach_digi_fmt f=BACH_DIGI_MONO_8,
                            ulong r=BACH_SMP_DEFAULTRATE);
    bach_err_codes load_raw(XFile &xf,
                            bach_digi_fmt f=BACH_DIGI_MONO_8,
                            ulong r=BACH_SMP_DEFAULTRATE);

    bach_err_codes load_wav(const char *fname);
    bach_err_codes load_wav(XFParseIFF &iff);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachSample3D - 3D static sample class                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BachSample3D : public BachStaticSample
{
protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Internal routines                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual bach_err_codes createbuffer(WAVEFORMATEX *wfmt);

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members.                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    IDirectSound3DListener  *listener;       // DSound listener interface
    IDirectSound3DBuffer    *sbuffer3d;      // DSound buffer 3D interface

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructor                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BachSample3D (BachDigital3D *digi);
    BachSample3D (BachSample3D const &b);
    virtual ~BachSample3D();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BachSample3D &operator = (BachSample3D const &that);

    //陳� Base class interface
    virtual void release ();

    //陳� 3D controls
    bach_err_codes set(DS3DBUFFER &settings, int recalc=1);

    bach_err_codes set_mode(DWORD mode=DS3DMODE_NORMAL, int recalc=1);

    bach_err_codes set_cone(ulong ia, ulong oa, int recalc=1);
    bach_err_codes set_cone_orient(float i, float j, float k, int recalc=1);
    bach_err_codes set_cone_volume(long vol, int recalc=1);

    bach_err_codes set_min_distance(float dist, int recalc=1);
    bach_err_codes set_max_distance(float dist, int recalc=1);

    bach_err_codes set_position(float x, float y, float z, int recalc=1);
    bach_err_codes set_velocity(float i, float j, float k, int recalc=1);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void get(DS3DBUFFER &settings) const;

    DWORD get_mode() const;

    void get_cone(ulong &ia, ulong &oa) const;
    void get_cone_orient(float &i, float &j, float &k) const;
    long get_cone_volume() const;

    float get_min_distance() const;
    float get_max_distance() const;

    void get_position(float &x, float &y, float &z) const;
    void get_velocity(float &i, float &j, float &k) const;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachFileSample - File streamed sample class                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BachFileSample : BachSample
{
protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected data members                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    IDirectSoundBuffer  *sbuffer_next;      // DSound buffer

    HANDLE              thread_handle;
    CRITICAL_SECTION    critical_section;

    enum
    {
        START   = 0,
        STOP    = 1,
        MAX
    };
    HANDLE              thread_event[MAX];

    ulong               buffer_size;

    XFile               *xfile;
    ulong               playrate;
    ulong               start;
    ulong               offset;
    ulong               length;

    XFile               *xfile_next;
    bach_digi_fmt       fmt_next;
    ulong               rate_next;
    ulong               playrate_next;
    ulong               start_next;
    ulong               length_next;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Internal routines                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual bach_err_codes createbuffer(WAVEFORMATEX *wfmt);
    static DWORD WINAPI thread_proc (LPVOID);

    // We cannot allow copying because of the critical section
    BachFileSample (BachFileSample const &);
    BachFileSample &operator= (BachFileSample const &);

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructor                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BachFileSample (class BachDigital *digi, ulong bsize = 16384);
    virtual ~BachFileSample ();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Base class interface
    virtual void release();
    virtual bach_err_codes play (int loop = 0);
    virtual bach_err_codes stop ();
    virtual bach_err_codes pause();
    virtual bach_err_codes resume();
    virtual dword status() const;

    //陳� Initializes class
    bach_err_codes init();

    //陳� Prepares files for streaming
    bach_err_codes ready_raw (const char *fname,
                              bach_digi_fmt f=BACH_DIGI_MONO_8,
                              ulong r=BACH_SMP_DEFAULTRATE);
    bach_err_codes ready_raw (XFile *xf,
                              bach_digi_fmt f=BACH_DIGI_MONO_8,
                              ulong r=BACH_SMP_DEFAULTRATE, ulong l=0,
                              int owns=1);

    bach_err_codes ready_wav (const char *fname);
    bach_err_codes ready_wav (XFile *xf, XFParseIFF *iff, int owns=0);

    //陳� Skip to next, if any
    bach_err_codes next();
};



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭 Digitial Class 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachDigital - Digital output object.                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BachDigital
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members.                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    dword               flags;              // System flags
    IDirectSound        *dsound;            // DirectSound instance
    IDirectSoundBuffer  *primary;           // DirectSound playback buffer
    ulong               driverRate;         // Driver playback rate
    bach_digi_fmt       driverFmt;          // Driver playback format

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructor                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BachDigital(ulong drate=BACH_DIGI_DRIVERRATE,
                bach_digi_fmt fmt=BACH_DIGI_STEREO_16);
    virtual ~BachDigital();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual bach_err_codes init (HWND hWnd, DWORD coop_level = DSSCL_PRIORITY, int cont_play=1);
    virtual void close ();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    bach_err_codes get_caps(DSCAPS &caps) const;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachDigital3D - Digital 3D output object.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BachDigital3D : public BachDigital
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members.                                                 �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    IDirectSound3DListener  *listener;      // DS listener interface

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructor                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BachDigital3D(ulong drate=BACH_DIGI_DRIVERRATE,
                  bach_digi_fmt fmt=BACH_DIGI_STEREO_16);
    virtual ~BachDigital3D();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual bach_err_codes init (HWND hWnd, DWORD coop_level = DSSCL_PRIORITY, int cont_play=1);
    virtual void close ();

    //陳� 3D listener controls
    bach_err_codes set(DS3DLISTENER &settings, int recalc=1);
    bach_err_codes set_distance(float factor, int recalc=1);
    bach_err_codes set_doppler(float factor, int recalc=1);
    bach_err_codes set_rolloff(float factor, int recalc=1);

    bach_err_codes set_orient(float fi, float fj, float fk,
                                float ti, float tj, float tk, int recalc=1);
    bach_err_codes set_position(float x, float y, float z, int recalc=1);
    bach_err_codes set_velocity(float i, float j, float k, int recalc=1);

    bach_err_codes recalc();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void get(DS3DLISTENER &settings) const;

    float get_distance() const;
    float get_doppler() const;
    float get_rolloff() const;

    void get_orient(float &fi, float &fj, float &fk, float &ti, float &tj, float &tk) const;
    void get_position(float &x, float &y, float &z) const;
    void get_velocity(float &i, float &j, float &k) const;
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - bachdigi.hpp 憶�
