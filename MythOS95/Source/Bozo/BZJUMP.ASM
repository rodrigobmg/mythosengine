;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
;                oooooooooo.                                 
;                `888'   `Y8b                                
;                 888     888  .ooooo.    oooooooo  .ooooo.  
;                 888oooo888' d88' `88b  d'""7d8P  d88' `88b 
;                 888    `88b 888   888    .d8P'   888   888 
;                 888    .88P 888   888  .d8P'  .P 888   888 
;                o888bood8P'  `Y8bod8P' d8888888P  `Y8bod8P' 
;                           _                       
;                          /_\     |    _  _ | _ ._ 
;                         /   \  \_||_|(_|(_||(/_|  
;                                       _| _|       
;                     Microsoft Windows 95/98/NT Version
;
;  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
; THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
; OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
; PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
; LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
; OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
;                        http://www.mythos-engine.org/
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
; Created by Dan Higdon
;
; BzJump
;
;      These are special versions of the setjmp() and longjmp() routines
; that only save the part of the context absolutely required by the
; Watcom compiler.  In this case, since we're non-preemptive, and only
; operate in FLAT model, they are: eip, esp, ebp, esi, edi, ebx
;
;       In this implemenation, we don't actually save eip, we save the
; return address of the bz_setjmp() call.  As it turns out, we can't
; rely on the stack to save that value, because everything from the
; return address "up" can be clobbered by the calling routine.
; However, we are guaranteed by the semantics of the setjmp() paradigm
; that values below this line are preserved.  So, we just save the
; return address, and place it back on the stack before the context
; switch.  I suppose I could save esp-4 and push the value back on,
; but I don't think there would be any performance advantage.
;
;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

.486p

;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                                Includes
;                                
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

include macros.inc


;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Code
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

_text   segment public PARA USE32 'CODE'

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;   Emulates the setjmp() function.                                        �
;       This only saves the registers that Watcom expects to be            �
;       preserved accross a call.  The segment registers are not saved,    �
;       which saves alot of time, but means we're stuck with flat model.   �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

START_PROC      bz_setjmp

        ;;;     Get the buffer address
        mov     eax,DWORD PTR[esp+4]

        ;;;     Save the return address (and allow eax to get updated)
        mov     ecx,[esp]

        ;;;     Now, save the registers
        mov     [eax+0],esi
        mov     [eax+4],edi
        mov     [eax+8],ebx
        mov     [eax+12],ebp
        mov     [eax+16],esp

        ;;;     save the return address previously fetched
        mov     [eax+20],ecx

        ;;;     Now, return the expected zero result
        xor     eax,eax
        ret

END_PROC        bz_setjmp

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;   bz_longjmp (dword *buffer)                                             �
;   Emulates the longjmp() function.                                       �
;       Restore the registers saved by bz_setjmp().                        �
;       In this case, we need to restore the return address as well,       �
;       since it is often clobbered by the task switch procedure.          �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

START_PROC      bz_longjmp

        mov     ecx,DWORD PTR[esp+4]
        assume  ecx:PTR DWORD

        ;;;     Restore the register contexts
        mov     esi,[ecx+0]
        mov     edi,[ecx+4]
        mov     ebx,[ecx+8]
        mov     ebp,[ecx+12]
        mov     esp,[ecx+16]

        ;;;     Restore the correct return address
        mov     eax,[ecx+20]
        mov     [esp],eax

        ;;;     Now that the stack is restored, we can return to the
        ;;;     old return address (saved already on the stack)
        mov     eax,1
        ret

END_PROC        bz_longjmp



;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;   bz_stackthunk (void *func, void *parm)                                 �
;   Call the function pointed to by param 1 with parm 2 loaded as          �
;   a register-calling convention parameter.                               �
;   This is used to permit register calling convention functions to        �
;   work in the Bozo initialization system.  See bzartn.c for details.     �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      bz_stackthunk
        pop     edx             ;get the return address
        pop     ecx             ;get the function pointer
        pop     eax             ;get parameter into the appropriate register
        push    edx             ;put the return address back on!
        jmp     ecx             ;leap into the routine!
END_PROC        bz_stackthunk

_text   ends
        end

;葦� End of module - bzjump.asm 憶�
