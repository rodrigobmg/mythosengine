//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//������������������旭旭旭�����旭旭旭姻���旭�����旭姻旭旭旭旭旭��������������
//�����������������葦姻���姻�葦姻���葦���葦姻���葦姻葦姻���������������������
//����������������碓甥���甥�碓甥����臼��碓碓���碓甥碓甥����������������������
//���������������渦臼葦渦��渦臼葦渦臼��渦臼姻�憶甥渦臼葦渦�������������������
//��������������渦甥������憶�����渦甥�渦甥�悔渦甥渦甥������������������������
//�������������憶悔������憶悔���憶悔�憶悔��臆渦�憶悔�������������������������
//������������臆悔������臆悔���臆悔�臆悔���臆悔臆臆臆臆臆��������������������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1996-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
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
// Created by Sean Gallagher
//
// pntxtscr.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define WIN32_LEAN_AND_MEAN
#include <stdlib.h>
#include <assert.h>

#include <pane.hpp>

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneTextScroll - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
PaneTextScroll::PaneTextScroll(VngoVport *gvp, const char *f_type) :
    text (0),
    gvport (0)
{
    if (gvp)
        gvport = gvp;

    memset(font_type, 0, sizeof(char)*GBERG_MAX_NAME);
    if (f_type)
        strcpy(font_type, f_type);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneTextScroll - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
PaneTextScroll::~PaneTextScroll()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneTextScroll - init
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL PaneTextScroll::init(char *txt)
{
    release();

    if (!gvport)
        return FALSE;

    cur_line=0;

    vrc.x = 0;
    vrc.y = 0;
    vrc.dx = gvport->vbuff.width;
    vrc.dy = gvport->vbuff.height;

    fg=bg=0;

//陳� Get string size
    if (!txt)
        return FALSE;
    string_len = strlen(txt);

    if (!string_len)
        return FALSE;

//陳� Get the font height and width
    GBergFontInfo fi;
    if (gberg_info_font(font_type, &fi))
        return FALSE;

//陳� activate the selected font
    gberg_select_font(font_type);

    font_height = fi.height;
    font_width = fi.width;

//    max_chars_per_line = (ulong)(vrc.dx / font_width);
//    max_chars_per_line = (ulong)(vrc.dx / gberg_widthc('M'));
    visible_lines = (ulong)(vrc.dy / font_height);

//陳� Count lines
    num_lines = count_lines(txt);

    if (visible_lines > num_lines)
        visible_lines = num_lines;

//陳� Create into work buffer
    text = new char [string_len+(4*num_lines)];        // extra padding
    if (!text)
        return FALSE;

    memset(text, 0, sizeof(BYTE) * (string_len+(4*num_lines)));

//陳� Parse string into work buffer
    if (!parse_string(txt))
        return FALSE;

    return TRUE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneTextScroll - release
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void PaneTextScroll::release()
{
    if (text)
    {
        delete [] text;
        text=0;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                               旭� Private 旭�
// PaneTextScroll - count_lines
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong PaneTextScroll::count_lines(char *sp)
{
    long chardx = 0;
    long text_x = 0;
    ulong line_ctr = 1;
    long cons_linefeeds = 0;

    long  line_width = vrc.dx;

    BOOL in_word = FALSE;
    char *begin_word;
    begin_word = sp;

    while (*sp)
    {
        chardx = gberg_widthc(*sp);
        if (*sp == ' ')
            in_word = FALSE;
        else if (*sp == '\t')       // tabs
        {
            int space_width = gberg_widthc(' ');
            int skip = text_x % space_width;
            skip = space_width - skip;
            text_x += skip;
        }
        else if (*sp == '\n')       // newlines
        {
            sp++;
            in_word = FALSE;
            line_ctr++;
            text_x = 0;
            cons_linefeeds++;
            continue;
        }
        else if (*sp == '-')
        {
            begin_word = sp+1;

            in_word = TRUE;
        }
        else
        {
            cons_linefeeds = 0;

            if (!in_word)
                begin_word = sp;

            in_word = TRUE;
        }

        if (text_x + chardx > line_width)
        {
            if (in_word)
                sp = begin_word;
            else
                sp++;

            in_word = FALSE;
            line_ctr++;
            text_x = 0;
        }
        else
        {
            text_x += chardx;
            ++sp;
        }
    }

    // remove trailing linefeeds from linectr
    if (cons_linefeeds)
        line_ctr -= cons_linefeeds;

    return line_ctr;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                               旭� Private 旭�
// PaneTextScroll - parse_string
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL PaneTextScroll::parse_string(char *sp)
{
    ulong num_chars = 0;
    int line_ctr = 0;

    BOOL in_word = FALSE;
    char *begin_word;
    begin_word = sp;
    char *tptr = text;

    long  line_width = vrc.dx;

    long chardx = 0;
    long text_x = 0;
    long spacedx = 0;

    char *out_string = new char[1024];
    if (!out_string)
        return FALSE;

    memset(out_string, 0, sizeof(char)*(1024));

    while (*sp)
    {
        chardx = gberg_widthc(*sp);
        num_chars++;
        if (*sp == ' ')
            in_word = FALSE;
        else if (*sp == '\t')           // tabs
        {
            int space_width = gberg_widthc(' ');
            int skip = text_x % space_width;
            skip = space_width - skip;

            if (text_x + skip <= line_width)
            {
                for (int j=0; j < skip; j++)
                {
                    out_string[num_chars-1] = ' ';
                    num_chars++;
                }
                text_x += skip;
                sp++;
            }
            else
            {
                sp++;
                in_word = FALSE;
                line_ctr++;
                text_x = 0;
                strcpy(tptr, out_string);
                int nc = strlen(out_string);
                tptr += nc + 1;
                memset(out_string, 0, sizeof(char)*(num_chars+1));
                num_chars = 0;
                continue;
            }
        }
        else if (*sp == '\n')           // newlines
        {
            sp++;

            if (text_x == 0)
                strcpy(out_string, "  ");

            in_word = FALSE;
            line_ctr++;
            text_x = 0;
            strcpy(tptr, out_string);
            int nc = strlen(out_string);
            tptr += nc + 1;
            memset(out_string, 0, sizeof(char)*(num_chars+1));
            num_chars = 0;
            continue;
        }
        else if (*sp == '-')
        {
            begin_word = sp+1;

            in_word = TRUE;
        }
        else
        {
            if (!in_word)
                begin_word = sp;

            in_word = TRUE;
        }

        if (text_x + chardx > line_width)
        {
            if (in_word)
            {
                int diff = sp - begin_word + 1;
                sp = begin_word;
                char *dptr = &(out_string[num_chars - diff]);
                for (int j=0; j < diff; j++)
                    *(dptr++) = '\0';
            }
            else
                sp++;

            in_word = FALSE;
            line_ctr++;
            text_x = 0;
            strcpy(tptr, out_string);
            int nc = strlen(out_string);
            tptr += nc + 1;
            memset(out_string, 0, sizeof(char)*(num_chars+1));
            num_chars = 0;
        }
        else
        {
            out_string[num_chars-1] = *sp;
            text_x += chardx;
            ++sp;
        }
    }

    if (*out_string)
    {
        char buff[3];
        buff[0] = ' ';
        buff[1] = 3;
        buff[2] = 0;

        strcat(out_string, buff);
        strcpy(tptr, out_string);
        int nc = strlen(out_string);
        tptr += nc + 1;
    }

    delete [] out_string;

    return TRUE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneTextScroll - render
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void PaneTextScroll::render()
{
    // if we don't have a vport,  there's no real reason to hang around
    if (!gvport || !text)
        return;

    int was_locked = gvport->lock();

    if (bg != VNGO_TRANSPARENT)
        gvport->reset(bg);

    GBergText gt(gvport);
    gberg_select_font(font_type);
    gberg_color(fg,bg);

    char *tptr = text;
    int x = 0;

#if 0
    // add the code to show only the visible ones here.....
    tptr += cur_line * (max_chars_per_line + 1);
#else
    // skip to the first visible line
    for (ushort i=0; i < cur_line; i++)
    {
        // skip past the chars on this line
        while (*tptr != 0)
            tptr++;

        // skip past the trailing zeros
        while (*tptr == 0)
            tptr++;
    }
#endif

    BOOL break_flag = FALSE;

    ushort y = 0;
    // show only the visible rows
    while (*tptr != 3 && y < cur_line + visible_lines)
    {
        gt.curx = x;
        gt.cury = y*font_height;
        gt.outc(*tptr);

        x += gberg_widthc(*tptr);

        tptr++;

        if (*tptr == 0)
        {
            while (*tptr == 0)
                tptr++;
            x = 0;
            y++;
        }
    }

    if (!was_locked)
        gvport->unlock();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneTextScroll - scroll
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void PaneTextScroll::scroll(direction_t dir)
{
    if (!gvport)
        return;

    switch(dir)
    {
        case UP:
            if (cur_line > 0)
                cur_line--;
            else
                cur_line = 0;
            break;

        case DOWN:
            if (num_lines > visible_lines)
            {
                cur_line++;

                if (cur_line > num_lines - visible_lines)
                    cur_line = num_lines - visible_lines;
            }

            break;

        case PAGEUP:
            if (cur_line > visible_lines-1)
                cur_line -= (visible_lines-1);
            else
                cur_line = 0;
            break;

        case PAGEDN:
            if (num_lines > visible_lines)
            {
                cur_line += (visible_lines-1);

                if (cur_line > num_lines - visible_lines)
                    cur_line = num_lines - visible_lines;
            }
            break;

        default:
            break;
    }

    render();
}

//葦� eof - pntxtscr.cpp 憶�
