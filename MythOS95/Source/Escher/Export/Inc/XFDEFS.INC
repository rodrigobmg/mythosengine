;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
;
;           ^           **   **   **** ***** *    ****     ^      Take me to
;          (_)            * *     *      *   *    *       (_)    / your
;     ^                    *      **     *   *    **            ^  leader...
;    (_)       ^          * *     *      *   *    *            (_)
;             (_)       **   **   *    ***** **** ****
;
;    Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
; Created by Chuck Walbourn
;
; xfdefs.inc
;
;      This contains the public defines used by the XFile library.
;
;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
;
;                                Equates
;
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭

;--- Error values ---
XF_ERR_NONE                    EQU 0

XF_ERR_FUNCINVALID             EQU 01h      ;MS-DOS errors
XF_ERR_FILENOTFOUND            EQU 02h
XF_ERR_PATHNOTFOUND            EQU 03h
XF_ERR_NOHANDLES               EQU 04h
XF_ERR_ACCESSDENIED            EQU 05h
XF_ERR_INVALIDHANDLE           EQU 06h
XF_ERR_MCBDESTROYED            EQU 07h
XF_ERR_NOMEMORY                EQU 08h
XF_ERR_MCBINVALID              EQU 09h
XF_ERR_ENVINVALID              EQU 0ah
XF_ERR_FORMATINVALID           EQU 0bh
XF_ERR_ACCESSCODEINVALID       EQU 0ch
XF_ERR_DATAINVALID             EQU 0dh
XF_ERR_INVALIDDRIVE            EQU 0fh
XF_ERR_CANTREMOVECHDIR         EQU 010h
XF_ERR_NOTSAMEDEVICE           EQU 011h
XF_ERR_NOMOREFILES             EQU 012h
XF_ERR_WRITEPROTECTED          EQU 013h
XF_ERR_UNKNOWNUNIT             EQU 014h
XF_ERR_DRIVENOTREADY           EQU 015h
XF_ERR_UNKCOMMAND              EQU 016h
XF_ERR_CRCERROR                EQU 017h
XF_ERR_BADREQLEN               EQU 018h
XF_ERR_SEEKERROR               EQU 019h
XF_ERR_NONDOSDISK              EQU 01ah
XF_ERR_SECTORNOTFOUND          EQU 01bh
XF_ERR_OUTOFPAPER              EQU 01ch
XF_ERR_WRITEFAULT              EQU 01dh
XF_ERR_READFAULT               EQU 01eh
XF_ERR_GENERALFAILURE          EQU 01fh
XF_ERR_SHAREVIOLATION          EQU 020h
XF_ERR_LOCKVIOLATION           EQU 021h
XF_ERR_DISKCHANGEINVALID       EQU 022h
XF_ERR_FCBUNAVAIL              EQU 023h
XF_ERR_SHAREBUFFEROVERFLOW     EQU 024h
XF_ERR_CPMISMATCH              EQU 025h
XF_ERR_OUTOFINPUT              EQU 026h
XF_ERR_OUTOFDISKSPACE          EQU 027h
XF_ERR_NETREQNOTSUPPORTED      EQU 032h
XF_ERR_REMOTENOTLISTENING      EQU 033h
XF_ERR_DUPNAMEONNET            EQU 034h
XF_ERR_NETNAMENOTFOUND         EQU 035h
XF_ERR_NETBUSY                 EQU 036h
XF_ERR_NETDEVNOLONGEREXIST     EQU 037h
XF_ERR_NETCOMLIMITEXCEEDED     EQU 038h
XF_ERR_NETHWERROR              EQU 039h
XF_ERR_INVALIDNETRESPONSE      EQU 03ah
XF_ERR_UNEXPECTEDNETERROR      EQU 03bh
XF_ERR_INCOMPATREMOTEHW        EQU 03ch
XF_ERR_PRINTQUEUEFULL          EQU 03dh
XF_ERR_NOSPACEFORPRINT         EQU 03eh
XF_ERR_PRINTDELETED            EQU 03fh
XF_ERR_NETNAMEDELETED          EQU 040h
XF_ERR_NETACCESSDENIED         EQU 041h
XF_ERR_NETDEVTYPEINCORRECT     EQU 042h
XF_ERR_NETNAMENOTFOUND2        EQU 043h
XF_ERR_NETNAMELIMITEXCEEDED    EQU 044h
XF_ERR_NETSESSIONLIMITEXCEEDED EQU 045h
XF_ERR_TEMPORARYPAUSE          EQU 046h
XF_ERR_NETREQNOTACCEPTED       EQU 047h
XF_ERR_NETREDIRECTIONPAUSED    EQU 048h
XF_ERR_LANT_INVALIDVERSION     EQU 049h
XF_ERR_LANT_ACCOUNTEXPIRED     EQU 04ah
XF_ERR_LANT_PWEXPIRED          EQU 04bh
XF_ERR_LANT_LOGININVALID       EQU 04ch
XF_ERR_LANT_DISKLIMITEXCEEDED  EQU 04dh
XF_ERR_LANT_NOTLOGGEDIN        EQU 04eh
XF_ERR_FILEEXISTS              EQU 050h
XF_ERR_CANTMAKEDIRECTORY       EQU 052h
XF_ERR_FAILONINT24             EQU 053h
XF_ERR_TOOMANYREDIRECTIONS     EQU 054h
XF_ERR_DUPLICATEREDIRECTION    EQU 055h
XF_ERR_INVALIDPASSWORD         EQU 056h
XF_ERR_INVALIDPARAMETER        EQU 057h
XF_ERR_NETWRITEFAULT           EQU 058h
XF_ERR_NETFUNCNOTSUPPORTED     EQU 059h
XF_ERR_REQHWNOTFOUND           EQU 05ah

XF_ERR_EOF                     EQU 256      ;Low-level errors

XF_ERR_NOTOPEN                 EQU 512      ;XFile errors
XF_ERR_ALREADYOPEN             EQU 513
XF_ERR_LOCKFAILED              EQU 514

XF_ERR_ITEM_NOT_FOUND          EQU 1000     ;XFileINI errors
XF_ERR_SECTION_NOT_FOUND       EQU 1001

XF_ERR_NOTSUPPORTED            EQU 2000     ;XFileBitmap errors
XF_ERR_INVALIDHEADER           EQU 2001
XF_ERR_INVALIDPALETTE          EQU 2002
XF_ERR_INVALIDIMAGE            EQU 2003

XF_ERR_NOTIFF                  EQU 3000     ;XFileIFF errors
XF_ERR_CHUCKNOTFOUND           EQU 3001
XF_ERR_FORMNOTFOUND            EQU 3002
XF_ERR_UNEXPECTEDEOF           EQU 3003
XF_ERR_INVALIDFORFORM          EQU 3004
XF_ERR_INVALIDFORCHUNK         EQU 3005
XF_ERR_INVALIDID               EQU 3006
XF_ERR_TRUNCATEDCHUNK          EQU 3007
XF_ERR_WRITENOTALLOWED         EQU 3008
XF_ERR_MAXDEPTHREACHED         EQU 3009

;--- Flags for open/create ---

XF_OPEN_READ                   EQU 01h      ; Read-mode
XF_OPEN_WRITE                  EQU 02h      ; Write-mode
XF_OPEN_APPEND                 EQU 04h      ; Append to current file, if any
XF_OPEN_CREATE                 EQU 08h      ; Create new file and set to 0 length
XF_OPEN_EXCLUSIVE              EQU 010h     ; Fails if creating file already existing

XF_OPEN_KILL                   EQU 01000h   ; Kills on close (XFileDOS only)

XF_OPEN_READONLY               EQU 010000h  ; File attributes (server/open)
XF_OPEN_HIDDEN                 EQU 020000h  ; (low byte of high word)
XF_OPEN_SYSTEM                 EQU 040000h
XF_OPEN_ARCHIVE                EQU 0200000h
XF_OPEN_SHAREABLE              EQU 0400000h

XF_OPEN_DENYALL                EQU 010000000h; Share mode for open (high byte)
XF_OPEN_DENYWRITE              EQU 020000000h
XF_OPEN_DENYREAD               EQU 030000000h
XF_OPEN_DENYNONE               EQU 040000000h

XF_OPEN_PRIVATE                EQU 080000000h; Inheritance for open (high bit)


;--- Attributes

XF_ATTRIB_NORMAL               EQU 0h
XF_ATTRIB_READONLY             EQU 01h
XF_ATTRIB_HIDDEN               EQU 02h
XF_ATTRIB_SYSTEM               EQU 04h
XF_ATTRIB_LABEL                EQU 08h
XF_ATTRIB_DIRECTORY            EQU 010h
XF_ATTRIB_ARCHIVE              EQU 020h
XF_ATTRIB_SHAREABLE            EQU 0100h


;--- Values for status ---

XF_STATUS_READ                 EQU 01h      ; Readable
XF_STATUS_WRITE                EQU 02h      ; Writable
XF_STATUS_OPEN                 EQU 04h      ; Open file
XF_STATUS_ISTMP                EQU 08h      ; Opened with xf_opentmp
XF_STATUS_KILL                 EQU 010h     ; Will delete file on close

XF_STATUS_DIRTY                EQU 010000h  ; Buffer needs flushing
XF_STATUS_LASTREAD             EQU 020000h  ; Last action was a read
XF_STATUS_LASTWRITE            EQU 040000h  ; Last action was a write

;--- File related maximums
XF_MAX_PATH                    EQU 144      ; maximum length of full pathname
XF_MAX_DRIVE                   EQU 3        ; maximum length of drive component
XF_MAX_DIR                     EQU 130      ; maximum length of path component
XF_MAX_FNAME                   EQU 9        ; maximum length of file name component
XF_MAX_EXT                     EQU 5        ; maximum length of extension component
XF_MAX_NAME                    EQU 13       ; maximum length of file name (with extension)

;葦� End of header - xfdefs.inc 憶�

