//���������������������������������������������������������������������������
//                oooooooooo.                                 
//                `888'   `Y8b                                
//                 888     888  .ooooo.    oooooooo  .ooooo.  
//                 888oooo888' d88' `88b  d'""7d8P  d88' `88b 
//                 888    `88b 888   888    .d8P'   888   888 
//                 888    .88P 888   888  .d8P'  .P 888   888 
//                o888bood8P'  `Y8bod8P' d8888888P  `Y8bod8P' 
//                           _                       
//                          /_\     |    _  _ | _ ._ 
//                         /   \  \_||_|(_|(_||(/_|  
//                                       _| _|       
//                       Microsoft Windows '95 Version
//
//            Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
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
// Bozo TASK
//
//      This module contains the high-level tasking routines and data
//  structures.  It provides routines for creating and terminating tasks.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ivory.h"
#include "bzqueue.h"
#include "bztask.h"


//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                               Routines
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

// The current task
bz_task *Task;

static IvorySubAlloc    *taskspace;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
//  API for creating (but not scheduling) a new task.                       �
//���������������������������������������������������������������������������
bz_task *bz_create (void (*entry) (void *), int stack_size, void *params)
{
    bz_task *t;
    
    if (taskspace)
        t = (bz_task *)ivory_sub_alloc (taskspace, sizeof (bz_task) + stack_size);
    else
        t = (bz_task *)ivory_alloc (sizeof (bz_task) + stack_size);

    if (t != NULL)
    {
        // The stack lives right beyond the context.
        char *stack = (char *)(t + 1);

        // Initialize the task state parameters
        t->creation_parameters = params;
        t->tls = NULL;

        // Initialize the task pointers.
        t->next  = NULL;
        t->queue = NULL;

        // Initialize the context
        bz_corout (&t->context, entry, stack, stack_size, bz_return, params);
    }

    return t;
}


//�������������������������������������������������������������������������Ŀ
//  API for creating and scheduling a new coroutine                         �
//���������������������������������������������������������������������������
bz_task *bz_spawn (void (*entry) (void *), int stack_size, void *params)
{
    bz_task *t = bz_create (entry, stack_size, params);

    // Add the created task to the ready queue.
    if (t != NULL) 
        bzqueue_enter (&ReadyQ, t);

    return t;
}


//�������������������������������������������������������������������������Ŀ
//  Terminate the current coroutine and unschedule it.                      �
//���������������������������������������������������������������������������
void bz_return (void)
{
    // If we're the last, get out.  Otherwise, switch to the next one.
    if (bzqueue_empty (&ReadyQ))
        exit (0);
    else
    {
        bz_task *t = Task;

        // Free the context (stack is optionally on the end of this block)
        // Kinda a hack here, since we're technically executing on a stack
        // that has already been freed!
        Task = bzqueue_leave (&ReadyQ);
        bz_term (t);
        bz_swap (NULL, &Task->context);
    }
}


//�������������������������������������������������������������������������Ŀ
//  Terminate the specified task.  It is assumed not to be the current one. �
//���������������������������������������������������������������������������
void bz_term (bz_task *t)
{
    // This function is not legal for the current task -- use bz_return().
    assert (Task != t);

    // Make sure that this task isn't in any queues.
    // (It shouldn't be, but you never really know, do you?)
    if (t->queue)
        bzqueue_remove (t->queue, t);

    // Free the context (stack is optionally on the end of this block)
    if (taskspace)
        ivory_sub_free (taskspace, &t);
    else
        ivory_free (&t);
}


//�������������������������������������������������������������������������Ŀ
//  Establishes MAIN as the first and only task.                            �
//  Returns the task handle of MAIN as the result.                          �
//���������������������������������������������������������������������������
bz_task *bz_init_task (IvorySubAlloc *_taskspace)
{
    bz_task *t = (bz_task *)ivory_alloc (sizeof (bz_task));

    // Remember the allocator
    taskspace = _taskspace;

    if (t != NULL)
    {
        // Initialize the task state parameters
        t->creation_parameters = 0;
        t->tls   = NULL;
        t->queue = NULL;
        t->next  = NULL;

        Task = t;
    }

    return t;
}


//�������������������������������������������������������������������������Ŀ
//  Set the allocator used by Bozo to allocate the stack space for          �
//  each individual task and stack.                                         �
//���������������������������������������������������������������������������
void bz_set_allocator (IvorySubAlloc *_taskspace)
{
    taskspace = _taskspace;
}


//�������������������������������������������������������������������������Ŀ
//  Get the creation parameters of the current task (the caller).           �
//���������������������������������������������������������������������������
void *bz_get_params (void)
{
    return Task->creation_parameters;
}

//�������������������������������������������������������������������������Ŀ
//  Get the task's instance data pointer.  Unique for each task.            �
//���������������������������������������������������������������������������
void *bz_get_tls (void)
{
    return Task->tls;
}

//�������������������������������������������������������������������������Ŀ
//  Set the task's instance data pointer.  Unique for each task.            �
//���������������������������������������������������������������������������
void bz_set_tls (void *tls)
{
    Task->tls = tls;
}


//��� End of file - bztask.c ���