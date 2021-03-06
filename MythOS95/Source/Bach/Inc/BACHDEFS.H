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
// bachdefs.h
//
// Contains defines and constants for the Bach library.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __BACHDEFS_H
#define __BACHDEFS_H    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Bach error codes                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
typedef enum bach_err_codes
{
    BACH_ERR_NONE                       =0,     // No error
    BACH_ERR_INVALIDPARAMS              =1,     // Invalid parameters
    BACH_ERR_NOTSUPPORTED               =2,     // Not supported
    BACH_ERR_OUTOFMEMORY                =3,     // Out of memory
    BACH_ERR_LOCKFAILED                 =4,     // Memory lock failed
    BACH_ERR_UNINITIALIZED              =5,     // Not initialized
    BACH_ERR_BUSY                       =6,     // Busy
    BACH_ERR_ALREADYOPEN                =7,     // Already open

    BACH_ERR_FILENOTFOUND               =10,    // File not found
    BACH_ERR_FILEERROR                  =11,    // File error occurred
    BACH_ERR_NOTFOUND                   =12,    // Data not found

    BACH_ERR_THREADFAILED               =20,    // Failed to create thread
    BACH_ERR_EVENTFAILED                =21,    // Failed to create event

    BACH_ERR_DSCONNECTFAIL              =100,   // DirectSound connect failed
    BACH_ERR_DSPRICREATFAIL             =101,   // Failed to create primary DS buffer
    BACH_ERR_DSSECCREATFAIL             =102,   // Failed to create secondary DS buffer
    BACH_ERR_DSSETCOOPFAIL              =103,   // Failed to set cooperative level
    BACH_ERR_DSFORMATFAILED             =104,   // Failed set format
    BACH_ERR_DSLOCKFAILED               =105,   // Failed lock of sound buffer
    BACH_ERR_DSBUFFERLOST               =106,   // Failed to restore sound buffer
    BACH_ERR_DSFAILED                   =107,   // Failed operatation

    BACH_ERR_DMCONNECTFAIL              =200,   // DirectMusic connect failed
    BACH_ERR_DMFAILED                   =201,   // Failed operation

    BACH_ERR_MCIFAILED                  =300,   // MCI failed
    BACH_ERR_MCIDEVOPEN                 =301,   // MCI device open
    BACH_ERR_MCIOUTOFRANGE              =302,   // MCI out of range
} bach_err_codes;


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Sample defines                                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

#define BACH_SMP_DEFAULTRATE            11025   // Default sample rate

//陳 Flags
#define BACH_SMP_LOOP                   0x1     // Sample is looped

#define BACH_SMP_3D                     0x100   // Sample is a 3D buffer
#define BACH_SMP_3DMUTEATMAX            0x200   // Sample should mute at max distance
#define BACH_SMP_3DVOLUMECTRL           0x400   // Sample should allow volume control
#define BACH_SMP_3DFREQCTRL             0x800   // Sample should allow frequency control

#define BACH_SMP_OWNSDATA               0x1000  // Sample data owned by instance

#define BACH_SMP_OVERRUN                0x10000 // Stream buffer too small

#define BACH_SMP_APP0                   0x1000000   // Application bits
#define BACH_SMP_APP1                   0x2000000
#define BACH_SMP_APP2                   0x4000000
#define BACH_SMP_APP3                   0x8000000
#define BACH_SMP_APP4                   0x10000000
#define BACH_SMP_APP5                   0x20000000
#define BACH_SMP_APP6                   0x40000000
#define BACH_SMP_APP7                   0x80000000

//陳 Status flags
#define BACH_SMPSTAT_PLAYING            0x1     // Sample is playing
#define BACH_SMPSTAT_LOOPING            0x2     // Sample is looping


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Digital interface defines                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳 General constants
#define BACH_DIGI_DRIVERRATE            11025   // Default driver rate

//陳 Flags
#define BACH_DIGI_PRIMARY_INITIALIZED   0x1
#define BACH_DIGI_3D                    0x100   // 3D primary buffer

//陳 Data format types
typedef enum bach_digi_fmt
{
    BACH_DIGI_MONO_8                    =0,     // Mono 8-bit
    BACH_DIGI_MONO_16                   =1,     // Mono 16-bit
    BACH_DIGI_STEREO_8                  =2,     // Stereo 8-bit
    BACH_DIGI_STEREO_16                 =3      // Stereo 16-bit
} bach_digi_fmt;


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Sample sequencer defines                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

#define BACH_SSEQ_OWNSSAMPLES           0x1000  // Samples owned by instance


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// CD audio controller defines                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

#define BACH_CD_STOPONCLOSE             0x1     // Stop playback on close
#define BACH_CD_WAITONSTOP              0x2     // Wait for completion on stop
#define BACH_CD_WAITONPAUSE             0x4     // Wait for completion on pause
#define BACH_CD_WAITONRESUME            0x8     // Wait for completion on resume
#define BACH_CD_WAITONEJECT             0x10    // Wait for completion on eject
#define BACH_CD_WAITONRETRACT           0x20    // Wait for completion on retract
#define BACH_CD_WAITONSEEK              0x40    // Wait for completion on seek

//陳 Status flags
#define BACH_CDSTAT_PLAYING             0x1     // CD is playing
#define BACH_CDSTAT_PAUSED              0x2     // CD is paused
#define BACH_CDSTAT_DOOROPEN            0x4     // CD door is open (ejected)
#define BACH_CDSTAT_NOTREADY            0x8     // CD is not ready

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Music sequence defines                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳 Status flags
#define BACH_SEQSTAT_PLAYING            0x1     // Music is playing

#endif

//葦� End of header - bachdefs.h 憶�
