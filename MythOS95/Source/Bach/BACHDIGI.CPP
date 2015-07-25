//���������������������������������������������������������������������������
//
//                        ����������                       ����        
//     ��Ŀ                ���     ���                     ����        
//     �  �       ��Ŀ     ���     ���   ����      �����    ��� ���    
//     �  � ��Ŀ  �  �     �����������  �  ���    ���   ��  ��������   
//     �  � �  �  �  �     ���     ���  �������  ���        ���   ���  
//    O� O� �  �  �  �     ���     ��� ���  ���  ���    ��  ���   ���  
//          �  � O� O�    �����������   ��������  �������  ����� ����� 
//         O� O�  
//                            C++ Music, Sound, and Effects Library
//                                Microsoft Windows '95 Version
//
//           Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// Created by Dan Higdon & Chuck Walbourn
//
// bachdigi.cpp
//
// Digital interface object core implementation.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <stdlib.h>
#include <string.h>

#include "bach.hpp"

#include <xfile.hpp>

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// BachDigital - Constructor                                                �
//���������������������������������������������������������������������������
BachDigital::BachDigital (dword drate):
    BachDigitalInterface(),
    driverRate  (drate),
    dsPrimary   (0),
    dSound      (0)
{
    assert (drate != 0);

//�� Setup default values
    memset (smpPtr, 0, sizeof (smpPtr));
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - Destructor                                                 �
//���������������������������������������������������������������������������
BachDigital::~BachDigital()
{
    close ();
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - init                                                       �
//                                                                          �
// Initializes the digital driver.                                          �
//���������������������������������������������������������������������������
bach_err_codes BachDigital::init (HWND hWnd, DWORD coop_level)
{
//�� Create Direct Sound Object
    if (DirectSoundCreate (NULL, &dSound, NULL) != DS_OK)
        return errorn = BACH_ERR_DSCONNECTFAIL;

    assert (dSound != 0);

//�� Let Direct Sound know how much control we need
    if (dSound->SetCooperativeLevel (hWnd, coop_level) != DS_OK)
    {
        dSound->Release();
        dSound = 0;
        return errorn = BACH_ERR_SETCOOPFAIL;
    }

//�� Create Primary Direct Sound Buffer
    if (coop_level != DSSCL_NORMAL)
    {
        DSBUFFERDESC    bd;
        memset (&bd, 0, sizeof (bd));
        bd.dwSize = sizeof (bd);
        bd.dwFlags = DSBCAPS_PRIMARYBUFFER;

        if (dSound->CreateSoundBuffer (&bd, &dsPrimary, NULL) != DS_OK)
        {
            dSound->Release();
            dSound = 0;
            return errorn = BACH_ERR_DSPRICREATFAIL;
        }

        assert (dsPrimary != 0);

    //�� Set the primary buffer format and other parameters
        WAVEFORMATEX        fmt;
        fmt.wFormatTag      = WAVE_FORMAT_PCM;
        fmt.nChannels       = 2;
        fmt.nSamplesPerSec  = driverRate;
        fmt.nBlockAlign     = 4;
        fmt.nAvgBytesPerSec = driverRate * fmt.nBlockAlign;
        fmt.wBitsPerSample  = 16;
        fmt.cbSize          = 0;

        dsPrimary->SetFormat (&fmt);
        dsPrimary->SetFrequency (driverRate);
        dsPrimary->SetVolume (BACH_DIGI_DEFAULT_VOLUME);
        dsPrimary->SetPan (BACH_DIGI_DEFAULT_PAN);

    //�� Begin primary buffer play
        dsPrimary->Play (0, 0, DSBPLAY_LOOPING);
    }

    return errorn = BACH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - close                                                      �
//���������������������������������������������������������������������������
void BachDigital::close()
{
//�� Release all channels
    for (byte i = 0; i < BACH_DIGI_CHANNELS; i++)
    {
        if (smpPtr[i] != 0)
            release (i);
    }

//�� Release Direct Sound Primary Buffer and Object
    if (dsPrimary)
    {
        dsPrimary->Stop();
        dsPrimary->Release();
        dsPrimary = 0;
    }

    if (dSound)
    {
        dSound->Release();
        dSound = 0;
    }
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - setup                                                      �
//                                                                          �
// Setups up a digital sample for playback.  Either takes a filename or     �
// a BachSample object.  The input 'chan' is -1 by default, which indicates �
// to use the first available channel.  The channel used is returned or -1  �
// if an error occurs.                                                      �
//���������������������������������������������������������������������������
byte BachDigital::setup (BachSample *s, byte chan)
{
//�� Safeguard
    assert (dSound);
    assert (s && s->length && s->rate);

//��� Find empty channel
    if (chan == byte (-1))
    {
        assert (BACH_DIGI_CHANNELS > 0);
        for (chan = 0; smpPtr[chan] != 0; chan++)
        {
            if (chan + 1 == BACH_DIGI_CHANNELS)
            {
                errorn = BACH_ERR_ALLCHANNELSBUSY;
                return byte (-1);
            }
        }
    }
    else
        chan = byte (int (chan) % BACH_DIGI_CHANNELS);

//��� Release any previous sample
    release (chan);

//��� Setup sample
    smpPtr[chan] = s;

    return chan;
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - release                                                    �
//                                                                          �
// Releases a sample on the given channel.                                  �
//���������������������������������������������������������������������������
void BachDigital::release (byte chan)
{
    BachSample **ptr = &smpPtr[chan % BACH_DIGI_CHANNELS];

    if (*ptr != 0)
    {
        (*ptr)->stop ();
        *ptr = 0;
    }
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - play                                                       �
//                                                                          �
// Begins play of a sample on the given channel.                            �
//���������������������������������������������������������������������������
void BachDigital::play (byte chan, ulong loop)
{
    assert (dSound);

    smpPtr[chan % BACH_DIGI_CHANNELS]->play (loop);
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - stop                                                       �
//                                                                          �
// Ends the play of a sample on the given channel.                          �
//���������������������������������������������������������������������������
void BachDigital::stop (byte chan)
{
    assert (dSound);

    smpPtr[chan % BACH_DIGI_CHANNELS]->stop();
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - pause                                                      �
//                                                                          �
// Pauses the play of a sample on the given channel.                        �
//���������������������������������������������������������������������������
void BachDigital::pause(byte chan)
{
    assert (dSound);
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - resume                                                     �
//                                                                          �
// Resumes a paused sample on the given channel.                            �
//���������������������������������������������������������������������������
void BachDigital::resume(byte chan)
{
    assert (dSound);
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - status                                                     �
//                                                                          �
// Returns status word for digital object.                                  �
//���������������������������������������������������������������������������
dword BachDigital::status(byte chan)
{
    dword flags=0;


    return flags;
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - set_volume                                                 �
//                                                                          �
// Sets the current play volume for the specified channel.                  �
//���������������������������������������������������������������������������
byte BachDigital::set_volume(byte chan, byte vol)
{
    smpPtr[chan % BACH_DIGI_CHANNELS]->set_volume (vol);

    return 0;
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - get_volume                                                 �
//                                                                          �
// Returns the chanel's volume.                                             �
//���������������������������������������������������������������������������
byte BachDigital::get_volume(byte chan)
{
    return byte (smpPtr[chan % BACH_DIGI_CHANNELS]->get_volume ());
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - set_pan                                                    �
//                                                                          �
// Sets the pan location for the given channel.                             �
//���������������������������������������������������������������������������
byte BachDigital::set_pan(byte chan, byte pan)
{
    smpPtr[chan % BACH_DIGI_CHANNELS]->set_pan (pan);
    return 0;
}


//�������������������������������������������������������������������������Ŀ
// BachDigital - get_pan                                                    �
//                                                                          �
// Returns the given channel's pan location.                                �
//���������������������������������������������������������������������������
byte BachDigital::get_pan(byte chan)
{
    return byte (smpPtr[chan % BACH_DIGI_CHANNELS]->get_pan ());
}


//��� End of module - bachdigi.cpp ���
