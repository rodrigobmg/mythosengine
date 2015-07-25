//���������������������������������������������������������������������������
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994,1995 by Charybdis Enterprises, Inc.
//                              All Rights Reserved.
//                        Microsoft Windows '95 Version
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
// xfram.cpp
//
//      Contains the code for the RAM file object, which performs file
//      operations into a memory block.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <assert.h>
#include <string.h>

#include <ivory.hpp>
#include "xfbase.hpp"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define XF_BUFFINIT 4096

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// Constructor for the RAM file object.                                     �
//���������������������������������������������������������������������������
XFileRAM::XFileRAM()
{
    handle=0;
};


//�������������������������������������������������������������������������Ŀ
// Destructor for the RAM file object.                                      �
//���������������������������������������������������������������������������
XFileRAM::~XFileRAM()
{
//��� Close the file handle, if open ���
   if (sFlags & XF_STATUS_OPEN)
       close();
};


//�������������������������������������������������������������������������Ŀ
//                         ��� Protected ���                                �
// XFileRAM - expand                                                        �
//                                                                          �
// Expands the memory buffer to ensure it has at least the required about   �
// of space.                                                                �
//���������������������������������������������������������������������������
xf_error_codes XFileRAM::expand(ulong nsize)
{
    ulong       ns;
    byte        *ptr;
    byte        *data;
    IvoryHandle nhandle;

//�� Safeguard
    assertMyth("XFileRAM::expand assumes a handle already exists",
               handle);

    if (nsize <= buffSize)
        return XF_ERR_NONE;

    // Determine new buffer size
    for(ns=buffSize; ns < nsize; ns += XF_BUFFINIT);

//�� Expand buffer

    // Allocate and lock new buffer
    nhandle = ivory_halloc(ns);
    if (!nhandle)
    {
        errorn=XF_ERR_NOMEMORY;
        return errorn;
    }
    ptr = (byte*) ivory_hlock(nhandle);
    if (!ptr) {
        ivory_hfree(&nhandle);
        errorn=XF_ERR_LOCKFAILED;
        return errorn;
    }

    // Copy current data and clear remainder of new buffer
    data = (byte*) ivory_hlock(handle);
    if (!data) {
        ivory_hfree(&nhandle);
        errorn=XF_ERR_LOCKFAILED;
        return errorn;
    }
    memcpy(ptr,data,buffSize);
    memset(&ptr[buffSize],0,ns-buffSize);

    // Clean up and exit
    ivory_hunlock(nhandle);
    ivory_hfree(&handle);

    handle = nhandle;
    buffSize = ns;

    return XF_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// XFileRAM - open                                                          �
//                                                                          �
// Opens file buffer for object.  Returns 0 if ok, error number otherwise.  �
//���������������������������������������������������������������������������
xf_error_codes XFileRAM::open(const char *name, dword flags)
{
    byte    *data;

    flags |= XF_OPEN_READ | XF_OPEN_WRITE | XF_OPEN_CREATE;

//�� Safeguard
    if (sFlags & XF_STATUS_OPEN)
    {
        return XF_ERR_ALREADYOPEN;
    }
    assertMyth("XFileRAM::open assumes the handle is 0 for a closed file",
               !handle);

//�� Allocate and clear memory block
    handle = ivory_halloc(XF_BUFFINIT);
    if (!handle)
    {
        errorn=XF_ERR_NOMEMORY;
        return errorn;
    }

    data = (byte*) ivory_hlock(handle);
    if (!data) {
        errorn=XF_ERR_LOCKFAILED;
        ivory_hfree(&handle);
        return errorn;
    }
    memset(data,0,XF_BUFFINIT);
    ivory_hunlock(handle);

//�� Setup as empty file
    position=fileSize=0;

    buffSize=XF_BUFFINIT;

    strcpy(fName,name);

    sFlags |= XF_STATUS_OPEN | XF_STATUS_READ | XF_STATUS_WRITE;

    return XF_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// XFileRAM - close                                                         �
//                                                                          �
// Closes a file buffer for object.  Returns 0 if ok, error number otherwise�
//���������������������������������������������������������������������������
xf_error_codes XFileRAM::close(void)
{
//�� Safeguard
    if (!(sFlags & XF_STATUS_OPEN))
        return XF_ERR_NOTOPEN;

//�� Free memory block
    if (handle)
    {
        ivory_hfree(&handle);
    }

    sFlags=0;

    return XF_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// XFileRAM - read                                                          �
//                                                                          �
// Read a block of the given size from the open file.                       �
// Returns number of bytes read or 0 if error.                              �
//���������������������������������������������������������������������������
ulong XFileRAM::read(void *ptr, ulong size)
{
    ulong   ns;
    byte    *data;

//�� Safeguard
    if (!(sFlags & XF_STATUS_OPEN))
        return XF_ERR_NOTOPEN;

    assertMyth("XFileRAM::read assumes a valid handle",
               handle);

//�� Copy data
    // Lock memory buffer
    data = (byte*) ivory_hlock(handle);
    if (!data) {
        errorn=XF_ERR_LOCKFAILED;
        return 0;
    }

    // Check for EOF condition
    if (position >= fileSize)
        return 0;

    // Copy up to EOF or size bytes
    ns = (size > fileSize-position) ? fileSize-position : size;

    assertMyth("XFileRAM::read assumes fileSize and position are valid",
               position + ns <= buffSize);
    memcpy(ptr,&data[position],ns);

    position += ns;

    assertMyth("XFileRAM::read assumes position is valid",
               position <= fileSize);

    ivory_hunlock(handle);

    return ns;
}


//�������������������������������������������������������������������������Ŀ
// XFileRAM - write                                                         �
//                                                                          �
// Write a block of the given size to the open file.                        �
// Returns number of bytes written or 0 if error.                           �
//���������������������������������������������������������������������������
ulong XFileRAM::write(const void *ptr, ulong size)
{
    xf_error_codes  err;
    byte            *data;

//�� Safeguard
    if (!(sFlags & XF_STATUS_OPEN))
        return XF_ERR_NOTOPEN;
    
    assertMyth("XFileRAM::write assumes a valid handle",
               handle);

//�� Secure enough memory for write

    // Ensure there is enough space in file
    if (size+position > buffSize)
    {
        err = expand(size+position);
        if (err)
        {
            errorn=err;
            return 0;
        }
    }

    // Lock memory buffer
    data = (byte*) ivory_hlock(handle);
    if (!data) {
        errorn=XF_ERR_LOCKFAILED;
        return 0;
    }

//�� Copy data
    assertMyth("XFileRAM::write assumes buffSize and position are valid",
               position + size <= buffSize);
    memcpy(&data[position],ptr,size);

    position += size;
    if (position > fileSize)
        fileSize = position;
    assertMyth("XFileRAM::write assumes buffSize and position are valid",
               position <= buffSize);

    ivory_hunlock(handle);

    return size;
}


//�������������������������������������������������������������������������Ŀ
// XFileRAM - seek                                                          �
//                                                                          �
// Seeks to an offset in the file (0=set, 1=current, 2=end)                 �
// Returns -1 if error, offset within file otherwise.                       �
//���������������������������������������������������������������������������
ulong XFileRAM::seek(long offset, int mode)
{
    ulong np;

//�� Safeguard
    if (!(sFlags & XF_STATUS_OPEN))
    {
        errorn=XF_ERR_NOTOPEN;
        return (ulong)-1;
    }

    assertMyth("XFileRAM::seek assumes a valid handle",
               handle);

//�� Compute new position
    switch (mode)
    {
        case 0:
            np = offset;
            break;
        case 1:
            np = position + offset;
            break;
        case 2:
            np = fileSize - offset;
            break;
        default:
            errorn=XF_ERR_SEEKERROR;
            return (ulong)-1;
    }

    if (np > fileSize)
    {
        errorn=XF_ERR_SEEKERROR;
        return (ulong)-1;
    }

    position = np;

    assertMyth("XFileRAM::seek assumes fileSize and position are valid",
               position <= fileSize);

    return position;
}


//�������������������������������������������������������������������������Ŀ
// XFileRAM - setsize                                                       �
//                                                                          �
// Extends or truncates the file to the given size.  Returns new size or    �
// -1 on error.                                                             �
//���������������������������������������������������������������������������
ulong XFileRAM::setsize(ulong size)
{
    xf_error_codes  err;

//�� Safeguard
    if (!(sFlags & XF_STATUS_OPEN))
        return XF_ERR_NOTOPEN;

    assertMyth("XFileRAM::setsize assumes a valid handle",
               handle);

    // Ensure there is enough space in file buffer
    if (size > buffSize)
    {
        err = expand(size);
        if (err)
        {
            errorn=err;
            return (ulong)-1;
        }
    }

//�� Set file file size
    fileSize = size;
    if (position > fileSize)
        position = fileSize;

    return fileSize;
}

//��� End of module - xfram.cpp ���