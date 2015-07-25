//���������������������������������������������������������������������������
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
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
// xfiread.cpp
//
// XFParseINI -
//
// Reading involves scanning the memory-copy of the buffer for the
// item in the active section, if any.  Once found, the line is parsed
// to determine the variables setting.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <stdlib.h>
#include <string.h>

#include <assert.h>

#include "xfile.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// XFParseINI - read                                                        �
//                                                                          �
// Reads a variable                                                         �
//                                                                          �
// Returns 0 if ok, error number otherwise.                                 �
//���������������������������������������������������������������������������
xf_error_codes XFParseINI::read(const char *item, char *value)
{
    char    *ptr;
    char    *cpy;
    ulong   count;

    *value=0;

//��� Setup start of search  ���
    ptr = start();
    if (!ptr && *sectname)
    {
        return errorn;
    }

//��� Scan buffer for variable ���
    if ((ptr=find(ptr,item))==0)
    {
        errorn=XF_ERR_ITEM_NOT_FOUND;
        return errorn;
    }

//��� Found item, search for '=' ���
    for(; *ptr && *ptr != '='; ptr++);
    if (*ptr)
    {
//��� Found '=', so copy ���
        ptr++;
        for(cpy=value, count=XF_MAX_INIVALUE-1;
            *ptr && *ptr != '\n' && *ptr != ';' && (count > 0);)
        {
            if (*ptr != '\r')
            {
                *(cpy++) = *ptr;
                count--;
            }
            ptr++;
        }
        *cpy=0;
    }

    return XF_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// XFParseINI - read                                                        �
//                                                                          �
// Reads a block of variables                                               �
//                                                                          �
// Returns 0 if ok, error number otherwise.                                 �
//���������������������������������������������������������������������������
xf_error_codes XFParseINI::read(const char **item, char **value)
{
    int i;

    for(i=0; item[i] && *item[i]; i++)
    {
        if (read(item[i],value[i]))
            return error();
    }

    return XF_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// XFParseINI - read                                                        �
//                                                                          �
// Reads a variable assuming it is an integer                               �
//                                                                          �
// Returns value, 0 on error or invalid integer.                            �
//���������������������������������������������������������������������������
int XFParseINI::read(const char *item)
{
    char value[XF_MAX_INIVALUE];

    if (read(item,value))
        return 0;

    return atoi(value);
}

//��� End of module - xfiread.cpp ���
