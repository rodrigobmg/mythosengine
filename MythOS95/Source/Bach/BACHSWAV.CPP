//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                        樛樛樛樛樛                       樛樛
//     敖朕                栩�     栩�                     渟栩
//     �  �       敖朕     栩�     栩�   樛樛      樛樛�    栩� 樛�
//     �  � 敖朕  �  �     栩桀樛樂栩�  �  渟�    栩�   炳  栩栩桎栩
//     �  � �  �  �  �     栩�     栩�  樂栩栩�  栩�        栩�   栩�
//    O� O� �  �  �  �     栩�     栩� 渟�  栩�  栩�    樂  栩�   栩�
//          �  � O� O�    樂栩樛樂栩�   栩栩毯桀  炳桀樂�  樂栩� 樂栩�
//         O� O�
//                            C++ Music, Sound, and Effects Library
//                               Microsoft Windows 95/98/NT Version
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
// Created by Dan Higdon & Chuck Walbourn
//
// bachsraw.cpp
//
// Bach static sample load of .RAW files
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "bach.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - load_wav
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::load_wav(const char *fname)
{
    if (!fname)
        return BACH_ERR_INVALIDPARAMS;

    XFParseIFF  iff(XF_IFF_RIFF);

    if (iff.open (fname, XF_OPEN_DENYWRITE | XF_OPEN_READ) != 0)
        return BACH_ERR_FILENOTFOUND;

    if (iff.seekform (iff.makeid ('W','A','V','E')) != 0)
        return BACH_ERR_NOTSUPPORTED;

    return load_wav (iff);
}

bach_err_codes BachStaticSample::load_wav(XFParseIFF &iff)
{
    WAVEFORMATEX    wfmt;

    assertMyth("BachStaticSample::load_wav needs DirectSound instance",
               dsound != 0);

    release();

//陳� Find and load the WAVE form
    if ( iff.chunkid != iff.makeid('R','I','F','F') != 0
         || iff.formid != iff.makeid('W','A','V','E')  != 0
         || iff.enterform() != 0)
        return BACH_ERR_FILEERROR;

//陳� Find the header chunk
    if ( iff.seekchunk (iff.makeid ('f','m','t',' ')) != 0
         || iff.chunkSize != sizeof (PCMWAVEFORMAT)
         || iff.read (&wfmt) != 0)
    {
        iff.leaveform();
        return BACH_ERR_FILEERROR;
    }

    if (wfmt.wFormatTag != WAVE_FORMAT_PCM
        || (wfmt.wBitsPerSample != 8
            && wfmt.wBitsPerSample != 16)
        || (wfmt.nChannels != 1
            && wfmt.nChannels != 2))
    {
        iff.leaveform();
        return BACH_ERR_NOTSUPPORTED;
    }

//陳� Find the sample data
    if (iff.seekchunk (iff.makeid ('d','a','t','a')) != 0)
    {
        iff.leaveform();
        return BACH_ERR_FILEERROR;
    }

//陳� Setup

    // Record the length of this chunk
    length = iff.chunkSize;

    // Allocate a handle to hold the data
    handle = ivory_halloc (length);
    if (!handle)
        return BACH_ERR_OUTOFMEMORY;

    flags |= BACH_SMP_OWNSDATA;

    void *ptr = ivory_hlock (handle);
    if (!ptr)
    {
        release();
        return BACH_ERR_LOCKFAILED;
    }

//陳� Read the data into the local buffer
    if (iff.read (ptr) != XF_ERR_NONE)
        return BACH_ERR_FILEERROR;

//陳� Setup sound buffer
    bach_err_codes err = createbuffer(&wfmt);
    if (err)
    {
        release();
        return err;
    }

    assertMyth("BachStaticSample::load_wav expected valid sound buffer",
               sbuffer != 0);

//陳� Copy data
    DWORD   len;
    void    *dsptr;

    if (sbuffer->Lock (0, length, &dsptr, &len, NULL, 0, 0) != DS_OK)
    {
        release();
        return BACH_ERR_DSLOCKFAILED;
    }

    memcpy (dsptr,ptr, len);
    sbuffer->Unlock (dsptr, len, NULL, 0);

    ivory_hunlock (handle);

//陳� Extract some format information
    rate = wfmt.nSamplesPerSec;

    if (wfmt.wBitsPerSample == 8)
        fmt = (wfmt.nChannels == 1)
              ? BACH_DIGI_MONO_8 : BACH_DIGI_STEREO_8;
    else
        fmt = (wfmt.nChannels == 1)
              ? BACH_DIGI_MONO_16 : BACH_DIGI_STEREO_16;

///陳� Cleanup and exit
    iff.leaveform();

    return BACH_ERR_NONE;
}

//葦� End of module - bachswav.cpp 憶�
