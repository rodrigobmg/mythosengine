//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
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
// Created by Tim Little & Chuck Walbourn
//
// eslatten.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// An EschAttenLight shines in all directions equally, but has a specific
// location in 3-space, and has a fall-off for distance from the light
// source.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"
#include "esfile.hpp"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define max(a,b)  (((a) > (b)) ? (a) : (b))

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschAttenLight - Constructor                                             �
//                                                                          �
// Initializes the light object with full intesity and sets type.           �
//���������������������������������������������������������������������������
EschAttenLight::EschAttenLight(const char *fname, const char *lname) :
    EschPointLight(),
    inner(0),
    outer(0x1000)
{
    ltyp = ESCH_LGTT_ATTEN;
    flags |= ESCH_LGT_ATTEN;

    if (fname)
    {
        load(fname,lname);
    }
};

EschAttenLight::EschAttenLight(const EschPoint *pnt, Flx16 i, Flx16 o) :
    EschPointLight(pnt),
    inner(i),
    outer(o)
{
    ltyp = ESCH_LGTT_ATTEN;
    flags |= ESCH_LGT_ATTEN;
};

EschAttenLight::EschAttenLight(Flx16 ix, Flx16 iy, Flx16 iz, Flx16 i, Flx16 o) : 
    EschPointLight(ix,iy,iz),
    inner(i),
    outer(o)
{
    ltyp = ESCH_LGTT_ATTEN;
    flags |= ESCH_LGT_ATTEN;
};



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschAttenLight - setup                                                   �
//                                                                          �
// Performs the setup of the light on an object by object basis.            �
//���������������������������������������������������������������������������
void EschAttenLight::setup(const EschFrameRef *fr)
{
    if (fr
        && EschCurrent
        && EschCurrent->camera
        && EschCurrent->camera->flags & ESCH_CAM_MODELSPACE)
    {
        pos.transform(&fr->iorient,&tpos);
        tinner = inner / fr->scalef;
        touter = outer / fr->scalef;
    }
    else
    {
        tpos = pos;
        tinner = inner;
        touter = outer;
    }
    if (tinner > touter)
        tinner = touter;

    EschLight::setup(fr);

    arate=harate=0;
    if ((outer-inner).flx > 0)
    {
        arate = _intensity / (outer - inner);
        harate = _hintensity / (outer - inner);
    }
}


//�������������������������������������������������������������������������Ŀ
// EschAttenLight - shine                                                   �
//                                                                          �
// Sets the shade level in the Van Gogh point based on the intesity of the  �
// light and the given vertex information.                                  �
//                                                                          �
// The point light source computes a direction vector relative to the       �
// vertex and then computes a dot product.  The distance is used to         �
// attenuate the intensity.                                                 �
//���������������������������������������������������������������������������
void EschAttenLight::shine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
{
    if (!(flags & ESCH_LGT_OFF))
    {
        // Compute point source lighting vector
        EschVector vtx(tpos.x - v->x,
                       tpos.y - v->y,
                       tpos.z - v->z);

        Flx16 mag = vtx.magnitude();

        // Check for point beyond outer range before
        // continuing
        if (mag.flx < outer.flx)
        {
            // Complete normalization
            if (mag.flx > 0)
            {
                vtx.i /= mag;
                vtx.j /= mag;
                vtx.k /= mag;
            }

            // Compute dot product
            Flx16 dot = v->normal DOT vtx;

            if (dot.flx < 0)
            {
                dot.flx = (revnrml) ? -dot.flx : 0;
            }
        
            if (dot.flx > (1<<16))
                dot.flx = (1<<16);

            // Compute intensity output (including attenuation)
            Flx16 inten = _intensity;

            if ((flags & ESCH_LGT_ATTEN) && (mag.flx > inner.flx))
            {
                inten -= (mag - inner) * arate;
            }

            // Compute final shade value
            long i = (dot.flx * (inten.flx >> 16)) >> 16;
            if (vpt->shade < i)
                vpt->shade = i;
        }
    }

//��� Chain for true multiple lights
    if (inext)
        inext->shine(v,vpt,revnrml);
}


//�������������������������������������������������������������������������Ŀ
// EschAttenLight - hishine                                                 �
//                                                                          �
// Sets the shade level, allowing specular highlights to overdrive the      �
// color based on the intensity of the light and the given vertex info.     �
//                                                                          �
// The point light source computes a direction vector relative to the       �
// vertex and then computes a dot product.  The distance is used to         �
// attenuate the intensity.                                                 �
//���������������������������������������������������������������������������
void EschAttenLight::hishine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
{                                                           
    if (!(flags & ESCH_LGT_OFF))
    {
        // Compute point source lighting vector
        EschVector vtx(tpos.x - v->x,
                       tpos.y - v->y,
                       tpos.z - v->z);

        Flx16 mag = vtx.magnitude();

        // Check for point beyond outer range before
        // continuing
        if (mag.flx < outer.flx)
        {
            // Complete normalization
            if (mag.flx > 0)
            {
                vtx.i /= mag;
                vtx.j /= mag;
                vtx.k /= mag;
            }

            // Compute dot product
            Flx16 dot = v->normal DOT vtx;

            if (dot.flx < 0)
            {
                dot.flx = (revnrml) ? -dot.flx : 0;
            }
        
            if (dot.flx > (1<<16))
                dot.flx = (1<<16);

            // Compute intensity output (including attenuation)
            Flx16 inten = _hintensity;

            if ((flags & ESCH_LGT_ATTEN) && (mag.flx > inner.flx))
            {
                inten -= (mag - inner) * harate;
            }

            // Compute final shade value
            long i = (dot.flx * (inten.flx >> 16)) >> 16;
            if (vpt->shade < i)
                vpt->shade = i;
        }
    }

//��� Chain for true multiple lights
    if (inext)
        inext->hishine(v,vpt,revnrml);
}



//���������������������������������������������������������������������������
//�����������������������������  I/O Routines  ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschAttenLight - load                                                    �
//                                                                          �
// Loads the position and other data of the attenuated light from an IFF    �
// file.                                                                    �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'lname' is given and the name doesn't match that in the     �
// chunk, an error is returned.                                             �
//���������������������������������������������������������������������������
esch_error_codes EschAttenLight::load(const char *fname, const char *lname)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//�� Open file
    if (iff.open(fname,XF_OPEN_READ))
        return ESCH_ERR_FILEERROR;

//�� Loop until a header with the correct name is found
    err=ESCH_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
        }

        if (iff.chunkid == iff.makeid('E','A','T','N'))
        {
            err=load(&iff,lname);
            if (!err
                || err != ESCH_ERR_NOTFOUND)
                break;
        }

        // Must scan inside any ESEN Scene forms.
        else if (iff.chunkid == iff.makeid('F','O','R','M')
                 && iff.formid == iff.makeid('E','S','E','N'))
        {
            iff.enterform();
        }
    }

//�� Return ok
    iff.close();
    return err;
}

esch_error_codes EschAttenLight::load(XFParseIFF *iff, const char *lname)
{
    EschFileLightAtten  atn;

    assertMyth("EschAttenLight::load requries iff pointer",
               iff);

//�� Verify correct chunk name and size
    if (iff->chunkid != iff->makeid('E','A','T','N'))
        return ESCH_ERR_NOTFOUND;

    if (iff->chunkSize != sizeof(EschFileLightAtten))
        return ESCH_ERR_INVALIDDATA;

//�� Read chunk and verify name, if given.
    if (iff->read(&atn))
        return ESCH_ERR_FILEERROR;

    if (lname && strcmp(lname,atn.name))
        return ESCH_ERR_NOTFOUND;

//�� Found, so setup Atten Light

    strcpy(name,atn.name);
    flags = atn.flags;

    VngoColor24bit  c(atn.color);
    set_intensity( max( max(c.r, c.g), c.b ) );

    set_position( atn.x, atn.y, atn.z );

    set_inner( atn.inner );
    set_outer( atn.outer );

//�� Return ok
    return ESCH_ERR_NONE;
}

//��� End of module - eslatten.cpp ���
