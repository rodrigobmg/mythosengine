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
//                                Microsoft Windows '95 Version
//
//           Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Dan Higdon & Chuck Walbourn
//
// bachwseq.hpp
//
// Contains the Wave Sequencer
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __BACHWSEQ_HPP
#define __BACHWSEQ_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//             
//                                Includes
//                                
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Sound System Library Includes                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳� Standard headers
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>

//陳� Charybdis headers
#include <debug.h>
#include <portable.h>
#include <ivory.hpp>

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Bach Library Includes                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#include "bachdefs.hpp"
#include "bachdigi.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - plays a series of waves in order.                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BachWaveSequencer
{
    // For storing the samples to sequence
    struct Link
    {
        BachSample  *const sample;
        Link        *next;

        Link (BachSample *_sample, Link *_next = 0):
            sample (_sample), next (_next) { }
    };

    HANDLE              thread_handle;
    DWORD               thread_id;
    CRITICAL_SECTION    critical_section;

    Link                *sequence;
    UINT                hTimer;

    void                arm_timer ();
    static DWORD CALLBACK thread_proc (LPVOID);

    virtual Link        *_next ();

    // We cannot allow copying because of the critical section
    BachWaveSequencer (BachWaveSequencer const &);
    BachWaveSequencer &operator= (BachWaveSequencer const &);

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructor                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    BachWaveSequencer ();
    virtual ~BachWaveSequencer ();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual Link *next ();

    //陳� Sample management
    virtual bach_err_codes add (BachSample *const);
    virtual void clear (BOOL stop_current = TRUE);

    //陳� Information about the sequence
    virtual BachSample *const playing ();
    virtual ulong latency ();

    //陳� Play controls
    virtual bach_err_codes play();
    virtual bach_err_codes stop();
};


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - bachwseq.hpp 憶�
