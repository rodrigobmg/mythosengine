//���������������������������������������������������������������������������
//
//                        ����������                       ����        
//     ��Ŀ                ���     ���                     ����        
//     �  �       ��Ŀ     ���     ���   ����      �����    ��� ���    
//     �  � ��Ŀ  �  �     �����������  �  ���    ���   ��  ��������   
//     �  � �  �  �  �     ���     ���  �������  ���        ���   ���  
//    O� O� �  �  �  �     ���     ��� ���  ���  ���    ��  ���   ���  
//          �  � O� O�    �����������   ��������  �������  ����� ����� 
//         O� O�  
//                            C++ Music, Sound, and Effects Library
//                               Microsoft Windows 95/NT Version
//
//           Copyright (c) 1995-1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// Created by Dan Higdon & Chuck Walbourn
//
// bachdefs.h
//
// Contains defines and constants for the Bach library.
// 
//���������������������������������������������������������������������������

#ifndef __BACHDEFS_H
#define __BACHDEFS_H    1

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// Bach error codes                                                         �
//���������������������������������������������������������������������������
typedef enum bach_err_codes
{
    BACH_ERR_NONE                       =0,     // No error
    BACH_ERR_INVALIDPARAMS              =1,     // Invalid parameters
    BACH_ERR_NOTSUPPORTED               =2,     // Not supported
    BACH_ERR_OUTOFMEMORY                =3,     // Out of memory
    BACH_ERR_LOCKFAILED                 =4,     // Memory lock failed
    BACH_ERR_UNINITIALIZED              =5,     // Not initialized
    BACH_ERR_BUSY                       =6,     // Busy

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
} bach_err_codes;


//�������������������������������������������������������������������������Ŀ
// Sample defines                                                           �
//���������������������������������������������������������������������������

#define BACH_SMP_DEFAULTRATE            11025   // Default sample rate

//�� Flags
#define BACH_SMP_LOOP                   0x1     // Sample is looped
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

//�� Status flags
#define BACH_SMPSTAT_PLAYING            0x1     // Sample is playing
#define BACH_SMPSTAT_LOOPING            0x2     // Sample is looping


//�������������������������������������������������������������������������Ŀ
// Digital interface defines                                                �
//���������������������������������������������������������������������������

//�� General constants
#define BACH_DIGI_DRIVERRATE            11025   // Default driver rate

//�� Data format types
typedef enum bach_digi_fmt 
{
    BACH_DIGI_MONO_8                    =0,     // Mono 8-bit
    BACH_DIGI_MONO_16                   =1,     // Mono 16-bit
    BACH_DIGI_STEREO_8                  =2,     // Stereo 8-bit
    BACH_DIGI_STEREO_16                 =3      // Stereo 16-bit
} bach_digi_fmt;


//�������������������������������������������������������������������������Ŀ
// Sample sequnecer defines                                                 �
//���������������������������������������������������������������������������

#define BACH_SSEQ_OWNSSAMPLES           0x1000  // Samples owned by instance

#endif

//��� End of header - bachdefs.h ���
