//���������������������������������������������������������������������������
//
//                                /\    /\ 
//                               /  \  /  \ 
//                              /    \/    \ 
//                             /  /\    /\  \ 
//                            /  /  \  /  Y T H O S
//                           /  /    \/    \  \ 
//                          /  /            \  \ 
//                         /__/              \__\ 
//
//                      Microsoft Windows '95 Version
//
//            Copyright (c) 1994,1995 by Charybdis Enterprises, Inc.
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
// Created by Chuck Walbourn
//
// mythos.cpp
//
// The Mythos Collection provides many diverse tools for development of
// entertainment software.  This module contains the MythosSystem class for
// coordinated use of the various Mythos components.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <ivory.h>
#include <bozo.h>

#include "mythos.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// MythosSystem - constructor                                               �
//                                                                          �
// Initializes the various Mythos components in the proper sequence.        �
//���������������������������������������������������������������������������
MythosSystem::MythosSystem(ulong ivory_size,
                           ivory_init_codes ivory_opt) :
    Ivory(ivory_size,ivory_opt), Bozo(), Max(), Chronos(), 
    Escher(), Gutenberg()
{
};


//�������������������������������������������������������������������������Ŀ
// MythosSystem - destructor                                                �
//                                                                          �
// Shuts down the various Mythos components in the proper sequence.         �
//���������������������������������������������������������������������������
MythosSystem::~MythosSystem()
{
//��� Uninit Chronos
    Chronos.term();
};


//�������������������������������������������������������������������������Ŀ
// MythosSystem - init                                                      �
//                                                                          �
// Initializes the libraries with explicit initialization.                  �
//���������������������������������������������������������������������������
int MythosSystem::init(ulong esch_arena_size, IvorySubAlloc *bozo_alloc)
{
    int err;

//��� Init Chronos
    Chronos.init();
    
//��� Init Bozo
    if (bozo_alloc)
        Bozo.set_allocator(bozo_alloc);

//��� Init Escher
    err=Escher.init(esch_arena_size);

    return err;
}

//��� End of module - mythos.cpp ���
