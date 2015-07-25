;���������������������������������������������������������������������������
;
;        ����������������������
;         ��                ��
;          ��              ��
;           ��        ������  �   � ���Ŀ ���Ŀ �   � ���Ŀ  ���Ŀ
;            ��       �  ��   �   � �   � �   � �   � �   �  �
;             ���� � �����    �   � �   � �   � �\  � �   �  �
;              ��� ������     ���Ĵ ����� �   � �\\ � �   �  ���Ŀ
;               ����� ��      �   � �\    �   � � \\� �   �      �
;               ��    ��      �   � � \   �   � �  \� �   �      �
;              �� � � ������  �   � �  \  ����� �   � �����  �����
;             ��   � �  ��
;            �� �������  ��
;           �� �������������            Timer Library
;          ������������������
;         ��������������������
;        ����������������������
;
;
;                      Microsoft Windows '95 Version
;
;           Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
;                           All Rights Reserved.
;
;���������������������������������������������������������������������������
;
;           *** Charybdis Enterprises, Inc. Company Confidential ***
;
;  This file and all associated files are the company proprietary property
;        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
;
; CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
; TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
; IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
; AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
; INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
;
;���������������������������������������������������������������������������
;
; chrrdtsc.asm
;
;     This file contains the chronos_rdtsc routine
;
;���������������������������������������������������������������������������

.486p

        OPTION SCOPED                   ; Enable local labels.

;���������������������������������������������������������������������������
;
;                                Includes
;
;���������������������������������������������������������������������������

include macros.inc

;���������������������������������������������������������������������������
;
;                                 Data
;
;���������������������������������������������������������������������������

       ASSUME  ds:_DATA
_DATA  SEGMENT PARA PUBLIC USE32 'DATA'
_DATA  ENDS

;���������������������������������������������������������������������������
;
;                                 Code
;
;���������������������������������������������������������������������������

EXTRN   __fltused:NEAR

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'
;�������������������������������������������������������������������������Ŀ
; chronos_rdtsc();                                                         �
;���������������������������������������������������������������������������
START_PROC      chronos_rdtsc, C
        sub     esp,0000008H
        db      0fH, 31H
        mov     dword ptr [esp+0],eax
        mov     dword ptr [esp+4],edx
        fild    qword ptr [esp+0]
        add     esp,000000008H
        ret
END_PROC        chronos_rdtsc

_text   ends
        end

;��� End of module - chrrdtsc.asm ���