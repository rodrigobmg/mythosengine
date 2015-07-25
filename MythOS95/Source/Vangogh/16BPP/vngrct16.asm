;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
;
;                                                           %__________%
;                                                          %/ . .  .   \%
;           Van Gogh 2D-Display Library                     |  . .  o. | 
;                                                           |. _  .   .|
;          Microsoft Windows '95 Version                    | / \   .  | 
;                                                           |_|_|_._._.|
;  Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
;              All rights reserved.                        %\__________/%
;                                                           %          %
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
; vngRCT16.ASM 
;
;      This module draws filled rectangles in all of their permutations.
;
;様様様様様様様様様様様様様様� Revision History 様様様様様様様様様様様様様様
;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�


.486p

        OPTION SCOPED                   ; Enable local labels.


;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                                Includes
;                                
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

include macros.inc
include vngdefs.inc
include vngstrct.inc

;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                                Equates
;
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                               Structures
;
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Data
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
        ASSUME  ds:_DATA
_DATA   SEGMENT PARA PUBLIC USE32 'DATA'
_DATA   ENDS

;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Code
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
;  vngo_rect16 (rectangle *,dword color);                                   
;      Expects color to be either an 8bit or 24bit color which it will use 
;      to fill the screen with.                                            
;                                                                          
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
START_PROC     vngo_rect16,	C CurScreen:DWORD, rectptr:DWORD, color:DWORD
        LOCAL   LX1             ; Top left x of the rect to fill.
        LOCAL   LDX             ; width of the rect to fill.
        LOCAL   LY1             ; Top left y of the rect to fill.
        LOCAL   LDY             ; height of the rect to fill.

        push    edi
        push    esi
        push    ebx

        mov     esi,CurScreen

        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_scrn_ptr
        mov     ebx,(VNGO_VBUFFER PTR [esi]).vb_pitch
        mov     ecx,rectptr
        mov     eax,(VNGO_RECT PTR [ecx]).rect_x
        mov     LX1,eax
        mov     eax,(VNGO_RECT PTR [ecx]).rect_dx
        mov     LDX,eax
        mov     eax,(VNGO_RECT PTR [ecx]).rect_dy
        mov     LDY,eax
        mov     eax,(VNGO_RECT PTR [ecx]).rect_y
        mov     LY1,eax
        mov     ecx,(VNGO_VBUFFER PTR [esi]).vb_ytable
        lea     eax,[ecx+eax*4]
        mov     eax,[eax]
        add     eax,LX1
        add     edi,eax
        mov     ecx,LDX

        mov     eax,color
	mov	edx,eax
	shl	eax,16
	or	eax,edx
        mov     edx,LDY
        mov     esi,ecx
        sub     ebx,esi
        sub     ebx,esi

y_loop:
        mov     ecx,esi
        shr     ecx,1
    rep stosd
    	jnc	@f
        stosw
@@:
        add     edi,ebx         ; go to the next scan line.
        dec     edx
        jg      y_loop

        pop	ebx
        pop	esi
        pop	edi
        ret
END_PROC       vngo_rect16

_text   ends
        end
;葦� End of module - vngRCT16.asm 憶�
