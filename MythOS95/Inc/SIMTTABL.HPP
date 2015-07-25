//���������������������������������������������������������������������������
//
//                              S I M   G I N E
//
//             __               ___   ______,-------
//           __==__,------------/|\--|      | .-.-.|    ___________
//         (|     |--------------|---|------| '-`-`|  _/___________\_
//         (|_____|      _       _   |   _  | 6000 | |               |
//          |__\\_|`-._/___\___/___\_|_/___\|      | |               |
//         __/ |===|--|_____|_|_____|_|___  |\_____|=|_______________|
//      |=|[_]==[_]    \ _ /   \ _ /   \ _ /          [_]   [_]   [_]
//���������������������������������������������������������������������������
//
//                     A Simluator Framework for MythOS(tm)
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1997-1998 by Charybdis Enterprises, Inc.
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
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//���������������������������������������������������������������������������
//
// SimTTabl.hpp
//
//  An event scheduler.  The time table calls back functions at a given
//  time.  This differs from a timer callback in that the time table only
//  guarantees that a function will be evaluated AFTER a specified time,
//  and then only if the time table is stepped.  Therefore, the time table
//  is suitable for scheduling occurences within a simulation.
//
//���������������������������������������������������������������������������

#ifndef __SIMTTABL_HPP
#define __SIMTTABL_HPP  1

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

typedef unsigned long ulong;

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimTimeTable - an event scheduler
//
//  SimTimeTable allows a program to schedule events to happen in the future.
//  This differs from Chronos' callbacks in that the SimTimeTable must be
//  stepped, and therefor only guarantees that the functions will be delayed
//  at least as long as requested.  Since the number of scheduled items
//  is expected to be large, the scheduler is efficient in time usage.
//���������������������������������������������������������������������������
class SimTimeTable
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public type definitions                                              �
    //�����������������������������������������������������������������������
    typedef void (*callback_t) (void *);

private:
    //���������������������������������������������������������������������Ŀ
    // Private data structures                                              �
    //�����������������������������������������������������������������������
    struct event
    {
        event       *next;
        clock_t     time;
        callback_t  fp;
        void        *prm;

        //�����������������������������������������������������������������Ŀ
        // Constructor/Destructors                                          �
        //�������������������������������������������������������������������
        event (clock_t _t, callback_t _fp, void *_p, event *_n = 0):
            next (_n), time (_t), fp (_fp), prm (_p)
        {
        }
    };

    //���������������������������������������������������������������������Ŀ
    // Private data members                                                 �
    //�����������������������������������������������������������������������
    event       *head;
    event       *tail;

    //��� Efficient allocation
    event       *free_list;
    event       *arena;
    int         arena_size;

public:

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimTimeTable (int size = 1024);
    ~SimTimeTable ();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    //��� Event interface
    void add_event (clock_t t, callback_t, void *);
    void add_event_rel (clock_t t, callback_t, void *);
    void rem_event (callback_t, void *, bool = true);

    //��� Process management (real-time and controlled time versions)
    void step ();
    void step (clock_t);

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
    bool more_events () const { return head != 0; }

    void size_alloc (int);
    void cleanup ();
};


#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of file - simttabl.hpp ���