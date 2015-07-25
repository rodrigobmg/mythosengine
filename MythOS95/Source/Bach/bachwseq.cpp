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
// bachwseq.cpp
//
// Bach Wave Sequencer implementation
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//                                
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "bach.hpp"

#include <ivory.hpp>
#include <xfile.hpp>

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                                                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�


//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�


//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//臼臼臼臼臼臼臼臼臼臼臼臼臼�  BachSample  臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - constructor                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachWaveSequencer::BachWaveSequencer ():
    sequence (0)
{
    thread_handle = CreateThread (NULL, 4 * 1024, thread_proc, this,
                                  CREATE_SUSPENDED, &thread_id);

    if (thread_handle != NULL)
    {
        InitializeCriticalSection (&critical_section);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - destructor                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachWaveSequencer::~BachWaveSequencer ()
{
    // Make sure we're not in the thread
    EnterCriticalSection (&critical_section);

    // Get rid of our thread
    TerminateThread (thread_handle, 0);
    WaitForSingleObject (thread_handle, INFINITE);
    CloseHandle (thread_handle);

    // Clear out any queued samples
    clear (TRUE);

    // And now, the critical section
    DeleteCriticalSection (&critical_section);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - add                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachWaveSequencer::add (BachSample *const sample)
{
    bach_err_codes res = BACH_ERR_NONE;

    EnterCriticalSection (&critical_section);

    const BOOL resume = (sequence == 0);

    if (sample == 0)
        return BACH_ERR_UNINITIALIZED;

    Link *p = new Link (sample);

    if (p == 0)
        res = BACH_ERR_OUTOFMEMORY;
    else
    {
        if (sequence == 0)
            sequence = p;
        else
        {
            for (Link *s = sequence; s->next != 0; s = s->next)
                ;
            s->next = p;
        }

        // Make sure we start playing
//        play();
    }

    LeaveCriticalSection (&critical_section);

    if (resume)
        ResumeThread (thread_handle);

    return res;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - clear                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void BachWaveSequencer::clear (BOOL stop_current)
{
    EnterCriticalSection (&critical_section);

    if (sequence != 0)
    {
        if (stop_current)
        {
            // Stop the first one
            sequence->sample->stop();

            // Clean them all up
            while (sequence != 0)
            {
                Link *tp = sequence->next;
                delete sequence;
                sequence = tp;
            }
        }
        else
        {
            // Skip the first one (terminate the link chain)
            Link *p = sequence->next;
            sequence->next = 0;
            while (p != 0)
            {
                Link *tp = p->next;
                delete p;
                p = tp;
            }
        }
    }

    LeaveCriticalSection (&critical_section);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - next                                                 �
//  Advance forceably to the next wave file.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachWaveSequencer::Link *BachWaveSequencer::next ()
{
    EnterCriticalSection (&critical_section);
    Link *res = _next();
    LeaveCriticalSection (&critical_section);

    return res;
}

// This internal version doesn't attempt a critical section lock
BachWaveSequencer::Link *BachWaveSequencer::_next ()
{
    if (sequence)
    {
        Link *p = sequence;

        p->sample->stop();
        sequence = p->next;

        delete p;

        if (sequence)
        {
            sequence->sample->play();
        }
    }

    return sequence;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - playing                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachSample *const BachWaveSequencer::playing ()
{
#if 1
    return (sequence != 0) ? sequence->sample: 0;

#else
    BachSample *res = 0;

    EnterCriticalSection (&critical_section);

    if (sequence != 0 
        && (sequence->sample->get_flags() & BACH_SMP_PLAYING))
    {
        res = sequence->sample;
    }

    LeaveCriticalSection (&critical_section);
    return res;
#endif
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - latency                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong BachWaveSequencer::latency ()
{
    // return the delta of all of the remaining samples
    ulong   t = 0;

    EnterCriticalSection (&critical_section);
    Link *p = sequence;

    // Currently assumes not playing; will be different once playing!
    while (p)
    {
        t += p->sample->get_playtime ();
        p = p->next;
    }

    LeaveCriticalSection (&critical_section);
    return t;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - play                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachWaveSequencer::play ()
{
    EnterCriticalSection (&critical_section);

    if (sequence)
    {
//        sequence->sample->play();

        // Make sure our thread is ready to roll
        ResumeThread (thread_handle);
    }

    LeaveCriticalSection (&critical_section);
    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - stop                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachWaveSequencer::stop ()
{
    EnterCriticalSection (&critical_section);

    SuspendThread (thread_handle);

    // Clean up all pending sequences
    if (sequence != 0)
    {
        sequence->sample->stop();

        // Clean them all up
        while (sequence != 0)
        {
            Link *tp = sequence->next;
            delete sequence;
            sequence = tp;
        }
    }

    LeaveCriticalSection (&critical_section);
    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachWaveSequencer - timer_proc                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
DWORD CALLBACK BachWaveSequencer::thread_proc (LPVOID lpUser)
{
    BachWaveSequencer *that = (BachWaveSequencer *)lpUser;

    for (;;)
    {
        EnterCriticalSection (&that->critical_section);

        if (that->sequence != 0)
        {
            // Decide how long to sleep
            BachSample *psamp = that->sequence->sample;
            assert (psamp);
            ULONG sleep_time = psamp->get_playtime ();
            psamp->play();
            LeaveCriticalSection (&that->critical_section);
            Sleep (sleep_time);

            // Advance to the next sample
            that->next();
        }
        else
        {
            // We don't have a sequence, so just suspend until we're needed
            LeaveCriticalSection (&that->critical_section);
            SuspendThread (GetCurrentThread());
        }
    }

    // This thread expects to be killed manually
    return 0;
}

//葦� End of module - bachwseq.cpp 憶�
