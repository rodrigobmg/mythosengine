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
// bachssmp.cpp
//
// Bach static sample implementation
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
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachStaticSample::BachStaticSample(BachDigital *digi) :
    BachSample(digi),
    length (0),
    handle (0)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachStaticSample::~BachStaticSample()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            旭 Protected 旭
// BachStaticSample - createbuffer
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::createbuffer(WAVEFORMATEX *wfmt)
{
    if (!dsound)
        return BACH_ERR_UNINITIALIZED;

    if (!wfmt)
        return BACH_ERR_INVALIDPARAMS;

    DSBUFFERDESC    bd;
    memset (&bd,0,sizeof (bd));

    bd.dwSize           = sizeof (DSBUFFERDESC);
    bd.dwFlags          = DSBCAPS_CTRLALL | DSBCAPS_STATIC;
    bd.dwBufferBytes    = length;
    bd.lpwfxFormat      = wfmt;

    if (dsound->CreateSoundBuffer (&bd, &sbuffer, NULL) != DS_OK)
    {
        return BACH_ERR_DSSECCREATFAIL;
    }

    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - release
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void BachStaticSample::release ()
{
    if (flags & BACH_SMP_OWNSDATA)
    {
        if (handle)
        {
            ivory_hfree (&handle);
        }
    }
    flags &= ~BACH_SMP_OWNSDATA;
    handle = 0;

    BachSample::release();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            旭 Protected 旭
// BachStaticSample - restore
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::restore()
{
    assertMyth("BachStaticSample::restore needs valid data",
               sbuffer != 0 && handle != 0 && length > 0);

    if (sbuffer->Restore() == DS_OK)
    {
        void *ptr = ivory_hlock (handle);
        if (!ptr)
            return BACH_ERR_LOCKFAILED;

        DWORD   len;
        void    *data;
        if (sbuffer->Lock (0, length, &data, &len,
                            NULL, 0, 0))
        {
            memcpy (data, ptr, len);
            sbuffer->Unlock (data, len, NULL, 0);

            ivory_hunlock(handle);
            return BACH_ERR_NONE;
        }
        else
        {
            ivory_hunlock(handle);
            return BACH_ERR_DSLOCKFAILED;
        }
    }

    return BACH_ERR_DSBUFFERLOST;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - play
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::play (int loop)
{
    if (!sbuffer || !handle)
        return BACH_ERR_UNINITIALIZED;

    for (;;)
    {
        if (loop)
            flags |= BACH_SMP_LOOP;
        else
            flags &= BACH_SMP_LOOP;

        HRESULT res = sbuffer->Play (0, 0, loop ? DSBPLAY_LOOPING : 0);
        switch (res)
        {
            case DS_OK:
                return BACH_ERR_NONE;

            case DSERR_BUFFERLOST:
                {
                    bach_err_codes err = restore();
                    if (err != BACH_ERR_NONE)
                        return err;
                }
                break;

            default:
                return BACH_ERR_DSFAILED;
        }
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - stop
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::stop ()
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer->Stop() != DS_OK)
        return BACH_ERR_DSFAILED;

    sbuffer->SetCurrentPosition(0);

    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - pause
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::pause()
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer->Stop() != DS_OK)
        return BACH_ERR_DSFAILED;

    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - resume
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::resume()
{
    if (!sbuffer || !handle)
        return BACH_ERR_UNINITIALIZED;

    for (;;)
    {
        HRESULT res = sbuffer->Play (0, 0,
                                     (flags & BACH_SMP_LOOP)
                                     ? DSBPLAY_LOOPING : 0);
        switch (res)
        {
            case DS_OK:
                return BACH_ERR_NONE;

            case DSERR_BUFFERLOST:
                {
                    bach_err_codes err = restore();
                    if (err != BACH_ERR_NONE)
                        return err;
                }
                break;

            default:
                return BACH_ERR_DSFAILED;
        }
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - status
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
dword BachStaticSample::status() const
{
    if (!sbuffer)
        return 0;

    DWORD dsstat;
    if (sbuffer->GetStatus(&dsstat) != DS_OK)
        return 0;

    dword status = 0;
    if (dsstat & DSBSTATUS_PLAYING)
    {
        status |= BACH_SMPSTAT_PLAYING;

        if (dsstat & DSBSTATUS_LOOPING)
            status |= BACH_SMPSTAT_LOOPING;
    }

    return status;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - set_volume
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::set_volume (long vol)
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if ((flags & BACH_SMP_3D) && !(flags & BACH_SMP_3DVOLUMECTRL))
        return BACH_ERR_NOTSUPPORTED;

//陳� Convert the volume to the 127 == full volume, 0 == no volume range
    if (vol < 0)
        vol = 0;
    else if (vol > 127)
        vol = 127;

//陳� Now, use the db_table to make this number into an attenuation value.
    if (sbuffer->SetVolume (-db_table[(db_table_size - 1) - vol]) != DS_OK)
        return BACH_ERR_DSFAILED;

    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - get_volume
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
long BachStaticSample::get_volume () const
{
    if (!sbuffer)
        return 0;

    if ((flags & BACH_SMP_3D) && !(flags & BACH_SMP_3DVOLUMECTRL))
        return 0;

    long res;
    if (sbuffer->GetVolume (&res) != DS_OK)
        return 0;

    return db_table_find (10000 + res);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - set_pan
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::set_pan (long heading)
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if (flags & BACH_SMP_3D)
        return BACH_ERR_NOTSUPPORTED;

//陳�  Ensure that the direction is the in -179..180 range
    while (heading > 180)
        heading -= 360;
    while (heading < -179)
        heading += 360;

//陳�  Since we are only stereo, wrap the heading into the forward field.
    if (heading > 90)
        heading = 180 - heading;
    else if (heading < -90)
        heading = -(180 + heading);

//陳�  Now, scale the number into DirectSound's range
    long pan = heading * (db_table_size-1) / 90;

//陳�  Set the pan appropriately
    if (pan < 0)
    {
        if (sbuffer->SetPan (-db_table[-pan]) != DS_OK)
            return BACH_ERR_DSFAILED;
    }
    else if (pan > 0)
    {
        if (sbuffer->SetPan (db_table[pan]) != DS_OK)
            return BACH_ERR_DSFAILED;
    }
    else
    {
        if (sbuffer->SetPan (0) != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - get_pan
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
long BachStaticSample::get_pan () const
{
    if (!sbuffer)
        return 0;

    if (flags & BACH_SMP_3D)
        return 0;

    long pan;
    if (sbuffer->GetPan (&pan) != DS_OK)
        return 0;

//陳� Convert into range
    if (pan < 0)
        pan = -db_table_find (-pan);
    else if (pan > 0)
        pan = db_table_find (pan);
    else
        pan = 0;

//陳� Scale into degrees
    return ((pan * 90) / (db_table_size - 1));
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - set_playrate
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::set_playrate (ulong r)
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if ((flags & BACH_SMP_3D) && !(flags & BACH_SMP_3DFREQCTRL))
        return BACH_ERR_NOTSUPPORTED;

    if (r != 0)
    {
        if (r < 100)
            r = 100;

        if (r > 100000)
            r = 100000;
    }

    if (sbuffer->SetFrequency (r) != DS_OK)
        return BACH_ERR_DSFAILED;

    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - get_playrate
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong BachStaticSample::get_playrate() const
{
    if (!sbuffer)
        return 0;

    if ((flags & BACH_SMP_3D) && !(flags & BACH_SMP_3DFREQCTRL))
        return 0;

    DWORD rate;
    if (sbuffer->GetFrequency (&rate) != DS_OK)
        return 0;

    return rate;
}



//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - set_position
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::set_position (ulong p)
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if (p > length)
        return BACH_ERR_INVALIDPARAMS;

    if (sbuffer->SetCurrentPosition(p) != DS_OK)
        return BACH_ERR_DSFAILED;

    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - get_position
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong BachStaticSample::get_position() const
{
    if (!sbuffer)
        return 0;

    DWORD pos;
    if (sbuffer->GetCurrentPosition(&pos,NULL) != DS_OK)
        return 0;

    return pos;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - create
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachStaticSample::create(void *p, ulong l, bach_digi_fmt f, ulong r)
{
    if (!p || l < 1 || r < 1)
        return BACH_ERR_INVALIDPARAMS;

    release();

//陳 Put a copy into handle memory
    handle = ivory_halloc (l);
    if (!handle)
        return BACH_ERR_OUTOFMEMORY;

    flags |= BACH_SMP_OWNSDATA;

    void *ptr = ivory_hlock (handle);
    if (!ptr)
    {
        release();
        return BACH_ERR_LOCKFAILED;
    }

    memcpy(ptr,p,l);

    ivory_hunlock (handle);

//陳 Setup format
    WAVEFORMATEX    wfmt;
    memset(&wfmt,0,sizeof(wfmt));

    switch (f)
    {
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Mono 8-bit
        case BACH_DIGI_MONO_8:
            wfmt.nChannels              = 1;
            wfmt.wBitsPerSample = 8;
                    wfmt.nBlockAlign    = 1;
            break;
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Mono 16-bit
        case BACH_DIGI_MONO_16:
            wfmt.nChannels              = 1;
            wfmt.wBitsPerSample = 16;
                    wfmt.nBlockAlign    = 2;
            break;
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Stereo 8-bit
        case BACH_DIGI_STEREO_8:
            wfmt.nChannels              = 2;
            wfmt.wBitsPerSample = 8;
                    wfmt.nBlockAlign    = 2;
            break;
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Stereo 16-bit
        case BACH_DIGI_STEREO_16:
            wfmt.nChannels              = 2;
            wfmt.wBitsPerSample = 16;
                    wfmt.nBlockAlign    = 4;
            break;
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Unknown
        default:
            release();
            return BACH_ERR_NOTSUPPORTED;
    }

    wfmt.wFormatTag      = WAVE_FORMAT_PCM;
    wfmt.nSamplesPerSec  = r;
    wfmt.cbSize                  = 0;
        wfmt.nAvgBytesPerSec = r * wfmt.nBlockAlign;

//陳� Setup sound buffer
    bach_err_codes err = createbuffer(&wfmt);
    if (err)
    {
        release();
        return err;
    }

    assertMyth("BachStaticSample::create expected valid sound buffer",
               sbuffer != 0);

//陳� Copy data
    DWORD   len;
    void    *dsptr;

    if (sbuffer->Lock (0, l, &dsptr, &len, NULL, 0, 0) != DS_OK)
    {
        release();
        return BACH_ERR_DSLOCKFAILED;
    }

    memcpy (dsptr, p, l);
    sbuffer->Unlock (dsptr, len, NULL, 0);

    return BACH_ERR_NONE;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachStaticSample - get_playtime
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong BachStaticSample::get_playtime () const
{
    assertMyth("BachStaticSample::get_playtime needs valid data",
               length > 0);

    if (rate < 1)
        return 0;

    ulong pos = 0;
    if (sbuffer)
    {
        if (sbuffer->GetCurrentPosition(&pos,NULL) != DS_OK)
            pos = 0;
    }

    if (pos > length)
        return 0;

    ulong sample_count = 0;

    switch (fmt)
    {
        case BACH_DIGI_MONO_8:
            sample_count = length - pos;
            break;

        case BACH_DIGI_MONO_16:
        case BACH_DIGI_STEREO_8:
            sample_count = (length - pos) / 2;
            break;

        case BACH_DIGI_STEREO_16:
            sample_count = (length - pos) / 4;
            break;

        default:
            // This assert will fail and give a clue to the reason.
            assertMyth("BachStaticSample::get_playtime needs valid format",
                        0);
            break;
    }

    return (sample_count * 1000) / rate;
}

//葦� End of module - bachssmp.cpp 憶�
