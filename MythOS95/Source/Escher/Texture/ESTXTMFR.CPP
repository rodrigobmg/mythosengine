//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
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
// Created by Tim Little & Chuck Walbourn
//
// estxtmfr.cpp
//
// EschMultiFrameTexture is an animated bitmap texture with 2 or more frames.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"
#include "esfile.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern char EschNoName[];

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMultiFrameTexture - Constructor                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschMultiFrameTexture::EschMultiFrameTexture() :
    EschTexture(),
    index(0),
    handle(0),
    time(0),
    interval(0),
    rate(0)
{
    ttyp = ESCH_TXTT_MFRAME;
    max=0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMultiFrameTexture - Destructor                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschMultiFrameTexture::~EschMultiFrameTexture()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMultiFrameTexture - release                                          �
//                                                                          �
// Removes the texture data from memory.                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMultiFrameTexture::release()
{
    if (flags & ESCH_TXT_LOCKED)
        unlock();

    if (flags & ESCH_TXT_SHARED)
    {
        if (handle)
            cache_release(handle);
        name=EschNoName;
    }
    else if (flags & ESCH_TXT_OWNSDATA)
    {
        if (handle)
        {
            VngoTexture *p = (VngoTexture*)ivory_hlock(handle);
            if (p)
            {
                for(ushort i = 0; i < max; i++, p++)
                {
                    p->VngoTexture::~VngoTexture();
                }
                ivory_hunlock(handle);
            }
            ivory_hfree(&handle);
        }
        if (name && name != EschNoName)
            delete [] name;
        name=EschNoName;
    }
    handle=0;
    index=max=0;

    EschTexture::release();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMultiFrameTexture - lock                                             �
//                                                                          �
// Locks the texture, making the 'ptr' member a valid pointer to a Van Gogh �
// texture object.                                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMultiFrameTexture::lock()
{
    assertMyth("EschMultiFrameTexture::lock needs a valid handle",
               handle);

    if (flags & ESCH_TXT_LOCKED)
        return;

    VngoTexture *data = (VngoTexture*) ivory_hlock(handle);

    assertMyth("EschMultiFrameTexture::lock couldn't lock memory",
               data);

    if (!data)
        return;

    flags |= ESCH_TXT_LOCKED;

    assertMyth("EschMultiFrameTexture::lock expects index less than max",
               index < max);

    ptr = &data[index];

    assert(base == max * sizeof(VngoTexture));
    assert(size == (ulong)(ptr->width*ptr->height));

    ptr->tex = (byte*)data + base + size*index;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMultiFrameTexture - unlock                                           �
//                                                                          �
// Unlocks the texture, invalidating the 'ptr' member.                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMultiFrameTexture::unlock()
{
    if (flags & ESCH_TXT_LOCKED)
    {
        assertMyth("EschMultiFrameTexture::unlock expects ptr to be non-zero",
                   ptr);

        ivory_hunlock(handle);

        flags &= ~ESCH_TXT_LOCKED;

        ptr=0;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMultiFrameTexture - animate                                          �
//                                                                          �
// Advances the texture to the next frame in the sequence.                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMultiFrameTexture::animate()
{
    if (flags & ESCH_MFTXT_TIMEBASED)
    {
        assertMyth("EschMultiFrameTexture::animate needs valid rate/interval",
                   interval >= 0 && rate > 0);

        time += interval;
        while (time > rate)
        {
            time -= rate;
            index++;
        }
    }
    else
    {
        index++;
    }
    index %= max;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMultiFrameTexture - create                                           �
//                                                                          �
// Creates a texture from an array of (appropriate) XFile bitmaps.          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschMultiFrameTexture::create(ushort n, XFBitmap *bms,
                                               int trans, VngoPal *pal)
{
    ushort  i;

//陳� Verify valid input
    if (n < 2 || !bms)
        return ESCH_ERR_INVALIDPARMS;

    for(i=0; i < n; i++)
    {
        const XFBitmap *bm = &bms[i];

        switch (bm->width)
        {
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
                break;
            default:
                return ESCH_ERR_INVALIDSIZE;
        }

        switch (bm->height)
        {
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
                break;
            default:
                return ESCH_ERR_INVALIDSIZE;
        }

        if (i)
        {
            if (bm->width != bms[0].width
                || bm->height != bms[0].height)
                return ESCH_ERR_INVALIDSIZE;
        }
    }

//陳� Prepare texture
    release();

    max = n;
    set_size(bms[0].width,bms[0].height);

//陳� Allocate memory
    handle = ivory_halloc( base + size*n );
    if (!handle)
        return ESCH_ERR_NOMEMORY;

    VngoTexture *data = (VngoTexture*)ivory_hlock(handle);
    if (!data)
    {
        ivory_hfree(&handle);
        return ESCH_ERR_LOCKFAILED;
    }

    memset(data, 0, base + size*n);

    flags = ESCH_TXT_LOCKED | ESCH_TXT_OWNSDATA;
    if (trans)
        flags |= ESCH_TXT_TRANSP;

//陳� Create texture from input
    for(i=0; i < n; i++)
    {
        ptr = &data[i];
        XFBitmap *bm = &bms[i];

        ptr->VngoTexture::VngoTexture(bm->width,
                                      bm->height,
                                      (byte*)data + base + size*i,
                                      VNGO_TEXTURE_8BIT
                                      | ((trans) ? VNGO_TEXTURE_TRANSPARENT : 0),
                                      pal);

        int locked=0;
        if (bm->pal || bm->data)
        {
            locked=1;
        }
        else
        {
            if (bm->lock() || !bm->data)
                return ESCH_ERR_LOCKFAILED;
        }

        if (ptr->convert(bm,pal) != VNGO_NO_ERROR)
            return ESCH_ERR_NOTSUPPORTED;

        if (!locked)
            bm->unlock();
    }

//陳� Return OK
    unlock();

    return ESCH_ERR_NONE;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMultiFrameTexture - load                                             �
//                                                                          �
// Loads the data for the texture from an IFF file.                         �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'tname' is given and the name doesn't match that in the     �
// form, an error is returned.                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschMultiFrameTexture::load(const char *fname,
                                             const char *tname,
                                             dword ctrlfl, VngoPal *pal)
{
    return EschTexture::load(fname,tname,ctrlfl,pal);
}

esch_error_codes EschMultiFrameTexture::load(XFParseIFF *iff,
                                             const char *tname,
                                             dword ctrlfl,
                                             VngoPal *pal)
{
    assertMyth("EschMultiFrameTexture::load needs iff pointer",
               iff);

    release();

//陳 Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('E','M','T','1'))
        return ESCH_ERR_NOTFOUND;

//陳 Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('M','H','D','R'))
        || iff->chunkSize != sizeof(EschFileMtlMHDR))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

    EschFileMtlMHDR header;

    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

    if (tname && strncmp(tname,header.name,ESCH_MAX_NAME))
    {
        iff->leaveform();
        return ESCH_ERR_NOTFOUND;
    }

//陳 Verify header
    if (header.nframes < 2
        || (header.compress != ESCH_MTL_COMPRESS_NONE
            && header.compress != ESCH_MTL_COMPRESS_RLE))
    {
        iff->leaveform();
        return ESCH_ERR_NOTSUPPORTED;
    }

//陳 Found, so load
    flags = (header.flags & ~(ESCH_TXT_LOCKED
                              | ESCH_TXT_OWNSDATA
                              | ESCH_TXT_SHARED
                              | ESCH_TXT_TRANSP));

    switch (header.type)
    {
        case ESCH_MTL_TYPE_8BIT:
        case ESCH_MTL_TYPE_8BIT_TRANSP:
            break;
        case ESCH_MTL_TYPE_15BIT:
        case ESCH_MTL_TYPE_15BIT_TRANSP:
        case ESCH_MTL_TYPE_24BIT:
        case ESCH_MTL_TYPE_32BIT:
            if (!pal)
            {
                iff->leaveform();
                return ESCH_ERR_INVALIDPARMS;
            }
            break;
        default:
            iff->leaveform();
            return ESCH_ERR_NOTSUPPORTED;
    }

    switch (header.type)
    {
        case ESCH_MTL_TYPE_8BIT_TRANSP:
        case ESCH_MTL_TYPE_15BIT_TRANSP:
        case ESCH_MTL_TYPE_32BIT:
            flags |= ESCH_TXT_OWNSDATA | ESCH_TXT_TRANSP;
            break;
        default:
            flags |= ESCH_TXT_OWNSDATA;
            break;
    }

    max = header.nframes;

    set_size(header.xsize,header.ysize);

//陳 Allocate memory
    handle = ivory_halloc( base + size*header.nframes );
    if (!handle)
    {
        iff->leaveform();
        return ESCH_ERR_NOMEMORY;
    }

    VngoTexture *data = (VngoTexture*)ivory_hlock(handle);
    if (!data)
    {
        ivory_hfree(&handle);
        iff->leaveform();
        return ESCH_ERR_LOCKFAILED;
    }

    memset(data, 0, base + size*header.nframes);

    flags |= ESCH_TXT_LOCKED;

//陳 Handle TC Bitmap return, if requested
    XFBitmap *bms=0;
    if ((ctrlfl & ESCH_TXTLD_TCBITMAP)
        && header.type != ESCH_MTL_TYPE_8BIT
        && header.type != ESCH_MTL_TYPE_8BIT_TRANSP)
    {
        if (app_data)
        {
            iff->leaveform();
            return ESCH_ERR_INVALIDPARMS;
        }

        bms = new XFBitmap[header.nframes];
        if (!bms)
        {
            iff->leaveform();
            return ESCH_ERR_NOMEMORY;
        }

        app_data = bms;
    }

//陳� Create texture from body chunks
    for(ushort i=0; i < header.nframes; i++)
    {
        ptr = &data[i];

        dword tflags = VNGO_TEXTURE_8BIT;

        switch (header.type)
        {
            case ESCH_MTL_TYPE_8BIT_TRANSP:
            case ESCH_MTL_TYPE_15BIT_TRANSP:
            case ESCH_MTL_TYPE_32BIT:
                tflags |= VNGO_TEXTURE_TRANSPARENT;
                break;
        }

        ptr->VngoTexture::VngoTexture(header.xsize,
                                      header.ysize,
                                      (byte*)data + base + size*i,
                                      tflags,pal);

        if (iff->seekchunk(iff->makeid('B','O','D','Y'))
            || !iff->chunkSize)
        {
            iff->leaveform();
            return ESCH_ERR_INVALIDDATA;
        }

        esch_error_codes err=load_body(iff,header,pal,(bms) ? &bms[i] : 0);
        if (err)
        {
            iff->leaveform();
            return err;
        }
    }

    unlock();

//陳� Handle sharing
    if (ctrlfl & ESCH_TXTLD_SHARE)
    {
        if (!cache_register(header.name, handle,
                            ESCH_TXTT_MFRAME, header.flags,
                            header.xsize, header.ysize, max,
                            &name,1))
        {
            flags &= ~ESCH_TXT_OWNSDATA;
            flags |= ESCH_TXT_SHARED;
        }
    }

//陳� If owns data, need space for name
    if (flags & ESCH_TXT_OWNSDATA)
    {
        name = new char[ESCH_MAX_NAME];
        if (!name)
        {
            iff->leaveform();
            return ESCH_ERR_NOMEMORY;
        }
        strncpy(name,header.name,ESCH_MAX_NAME);
    }

//陳� Return OK
    iff->leaveform();
    return ESCH_ERR_NONE;
}

//葦� End of module - estxtmfr.cpp 憶�

