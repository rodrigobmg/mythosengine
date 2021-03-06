//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//           __ ,
//            ,-| ~           ,               ,,
//           ('||/__,        ||               ||                  _
//          (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\
//          (( |||==| || ||  ||   || \\ || || || || || \\  ||   || ||
//           ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || ||
//            -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-|
//                                                               /  \
//                                                              '----`
//                     Text Output and Font Management System
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                              *** Utilities ***
//
// Created by Chuck Walbourn
//
// gstring.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

#include "debug.h"
#include "xfile.hpp"

#include "gstring.h"

#include "gbrgfile.hpp"

using namespace std;


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define INIT_WORK_SIZE     32768

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

STATIC void cleanup(void);
STATIC void print_help(int full);

void print_error(XFParseIFF &xp, char *s=0);
void print_error(XFile &xp, char *s=0);

extern void compile(void);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern "C" FILE *yyin;

STATIC char Util_name[]
       = "葦 Gutenberg String Utility - 1995-9 by D. Higdon, T. Little, C. Walbourn 碓\n"
         "                            Subject to the terms of the MIT License " __DATE__ "\n";

XFParseIFF      IFF;
XFileDOS        header;

byte            *Work=0;
ulong           WorkSize=0;

dword           Flags=0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// main                                                                     �
//                                                                          �
// Entry point for the GSTRING utility.                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int main(int argc, char *argv[])
{
    int         i;
    char        *ifn, *ofn, *hfn;

    char        path[XF_MAX_PATH];
    char        hpath[XF_MAX_PATH];

    char        drive[XF_MAX_DRIVE];
    char        dir[XF_MAX_DIR];
    char        fname[XF_MAX_FNAME];
    char        ext[XF_MAX_EXT];

//陳� Handle no filename for source file...
    if (argc < 2)
    {
        print_help(0);
        return 1;
    }

//陳� Process arguments
    for(i=1, ifn=0, ofn=0, hfn=0; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {
                case '?':
                    print_help(1);
                    return 0;

                case 'q':
                case 'Q':
                    Flags |= FLAGS_QUIET;
                    break;

                case 'h':
                case 'H':
                    Flags |= FLAGS_MAKE_H;
                    break;

                case 'r':
                case 'R':
                    Flags |= FLAGS_RELEASE;
                    break;

                case 'o':
                case 'O':
                    switch (argv[i][2])
                    {
                        case 'i':   // IFF file name
                        case 'I':
                            if (++i > argc)
                            {
                                cout << "-oi requires a filname afterwards\n";
                                print_help(0);
                                return 1;
                            }
                            ofn = argv[i];
                            strlwr (ofn);
                            break;

                        case 'h':   // HPP file name
                        case 'H':
                            if (++i > argc)
                            {
                                cout << "-oh requires a filname afterwards\n";
                                print_help(0);
                                return 1;
                            }
                            hfn = argv[i];
                            strlwr (hfn);
                            break;

                        default:
                            cout << "Unknown option " << argv[i] << " ignored\n";
                            break;
                    }
                    break;

                default:
                    cout << "Unknown option " << argv[i] << " ignored\n";
                    break;
            }
        }
        else if (!ifn)
        {
            ifn=argv[i];
            strlwr(ifn);
        }
    }

    if (!ifn)
    {
        print_help(0);
        return 1;
    }

//陳� Check to see if source .cst file exists
    if (!xf_exist(ifn)) {
        cout << Util_name;
        cout << "臼� " << ifn << " does not exist\n";
        return 1;
    }

//陳� Open source file
    if ((yyin=fopen(ifn,"r"))==NULL) {
        cout << Util_name;
        cout << "臼� Could not open " << ifn << "\n";
        return 1;
    }

//陳� Setup output IFF filename (uses input name if none given)
    if (ofn) {
        strcpy(path,ofn);
    }
    else {
        strcpy(path,ifn);
    }
    ofn=path;

    // Forces .IFF extention onto whatever output file is being used
    xf_splitpath(path,drive,dir,fname,ext);
    strcpy(ext,".iff");
    xf_makepath(path,drive,dir,fname,ext);

//陳� Setup output HPP filename (uses input name if none given)
    if (hfn) {
        strcpy(hpath,hfn);
    }
    else {
        strcpy(hpath,ifn);
    }
    hfn=hpath;

    // Forces .IFF extention onto whatever output file is being used
    xf_splitpath(hpath,drive,dir,fname,ext);
    strcpy(ext,(Flags & FLAGS_MAKE_H) ? ".h" : ".hpp");
    xf_makepath(hpath,drive,dir,fname,ext);

//陳� Output title and source/output file stats.
    if (!(Flags & FLAGS_QUIET))
    {
        cout << Util_name;
        cout << "   Source: " << ifn;
        cout << "  Output: " << ofn;
        cout << "  Header: " << hfn << endl;

        if (Flags & FLAGS_RELEASE)
        {
            cout << "  葦� Release version 憶�\n";
        }
    }

//陳� Kill target file...
    xf_remove(ofn);

//陳� Open output file
    if (IFF.create(ofn,0))
    {
        print_error(IFF,"Failed to open output file");
    }

//陳� Open output header file
    if (header.create (hfn, 0))
        print_error (header, "Failed to open output file");

//陳� Parse input
    else
    {

        atexit(cleanup);

        Work = new byte[INIT_WORK_SIZE];
        WorkSize=INIT_WORK_SIZE;

        if (!Work) {
            cout << "臼� Couldn't allocate " << WorkSize << " bytes\n";
            exit(1);
        }

        compile();
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Cleanup function.                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void cleanup(void)
{
    if (Work)
    {
        delete [] Work;
        Work=0;
    }

    IFF.close();
    header.close ();
    fclose(yyin);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// print_help                                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void print_help(int full)
{
    cout << Util_name;
    cout << "   Usage: gstring [-q] [-h] [-r] <filename.cst>\n"
            "                  [-oi <filename.iff>] [-oh <filename.hpp/.h>]\n";
    if (full)
    {
        cout << "           -q = Operate quietly.\n";
        cout << "           -h = Make H instead of HPP file.\n";
        cout << "           -r = Make release version (omit author and description).\n";
        cout << "          -oi = Specifies alternate .IFF file name.\n";
        cout << "          -oh = Specifies alternate .HPP/.H file name.\n";
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// print_error                                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void print_error(XFParseIFF &xp, char *s)
{
    cout << "臼� ";

    if (s)
    {
        cout << s << ", ";
    }

    switch (xp.error())
    {
        case XF_ERR_NOTIFF:
            cout << "not an IFF file error";
            break;
        case XF_ERR_CHUCKNOTFOUND:
            cout << "chunk not found error";
            break;
        case XF_ERR_FORMNOTFOUND:
            cout << "form not found error";
            break;
        case XF_ERR_UNEXPECTEDEOF:
            cout << "unexpected end-of-file error";
            break;
        case XF_ERR_INVALIDFORFORM:
            cout << "invalid operation for FORM error";
            break;
        case XF_ERR_INVALIDFORCHUNK:
            cout << "invalid operation for chunk error";
            break;
        case XF_ERR_INVALIDID:
            cout << "invalid identifier error";
            break;
        case XF_ERR_TRUNCATEDCHUNK:
            cout << "truncated chunk error";
            break;
        case XF_ERR_WRITENOTALLOWED:
            cout << "write not allowed error";
            break;
        case XF_ERR_MAXDEPTHREACHED:
            cout << "maximum supported depth reached error";
            break;
        default:
            cout << "error " << (int)xp.error();
            break;
    }

    cout << "\n";
}

void print_error (XFile &xp, char *s)
{
    cout << "臼� ";

    if (s)
        cout << s << ", ";

    switch (xp.error())
    {
        case XF_ERR_NOTIFF:
            cout << "not an IFF file error";
            break;
        case XF_ERR_CHUCKNOTFOUND:
            cout << "chunk not found error";
            break;
        case XF_ERR_FORMNOTFOUND:
            cout << "form not found error";
            break;
        case XF_ERR_UNEXPECTEDEOF:
            cout << "unexpected end-of-file error";
            break;
        case XF_ERR_INVALIDFORFORM:
            cout << "invalid operation for FORM error";
            break;
        case XF_ERR_INVALIDFORCHUNK:
            cout << "invalid operation for chunk error";
            break;
        case XF_ERR_INVALIDID:
            cout << "invalid identifier error";
            break;
        case XF_ERR_TRUNCATEDCHUNK:
            cout << "truncated chunk error";
            break;
        case XF_ERR_WRITENOTALLOWED:
            cout << "write not allowed error";
            break;
        case XF_ERR_MAXDEPTHREACHED:
            cout << "maximum supported depth reached error";
            break;
        default:
            cout << "error " << (int)xp.error();
            break;
    }

    cout << "\n";
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// expand_work                                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void expand_work(ulong target)
{
   byte    *tmp;
   ulong   tsize;

   tsize=WorkSize;
   while (target > tsize) {
       tsize *= 2;
   }

   if (tsize > WorkSize) {

       tmp=new byte[tsize];
       if (!tmp) {
           cout << "臼� Cannot expand work buffer to " << tsize << " bytes";
           exit(1);
       }

       memcpy(tmp,Work,WorkSize);
       delete [] Work;
       Work = tmp;
       WorkSize = tsize;
   }
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// _charybdis_assert
//
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void _charybdis_assert(char *msg, char *exp, char *f, unsigned ln)
{
    cout.flush();
    printf("\n\n臼� Assertion Failed 臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼\n"
           "Expr:\t%s\n"
           "File:\t%s\t\tLine %d\n",exp,f,ln);
    if (msg)
    {
        printf("Comment:\n%s\n",msg);
    }

    exit(1);
}

//葦� End of module - gstring.cpp 憶�

