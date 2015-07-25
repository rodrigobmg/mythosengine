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
// eslspot.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// An EschSpotLight shines in a given direction from a location in 3-space,
// with the intensity dropping off towords the edge of the cone defined
// for the spot.  It also supports distance attenuation.
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
// EschSpotLight - Constructor                                              �
//                                                                          �
// Initializes the light object with full intesity and sets type.           �
//���������������������������������������������������������������������������
EschSpotLight::EschSpotLight(const char *fname, const char *lname) :
    EschAttenLight(),
    dir(0,0,1),
    hotspot(44),
    falloff(45)
{
    ltyp = ESCH_LGTT_SPOT;

    if (fname)
    {
        load(fname,lname);
    }
};

EschSpotLight::EschSpotLight(const EschPoint *pnt,
                             const EschVector *d,
                             Flx16 h, Flx16 f, Flx16 i, Flx16 o) :
    EschAttenLight(pnt,i,o),
    dir(*d),
    hotspot(h),
    falloff(f)
{
    ltyp = ESCH_LGTT_SPOT;

    dir.normalize();
};

EschSpotLight::EschSpotLight(Flx16 ix, Flx16 iy, Flx16 iz,
                             Flx16 ii, Flx16 ij, Flx16 ik,
                             Flx16 h, Flx16 f, Flx16 i, Flx16 o) : 
    EschAttenLight(ix,iy,iz,i,o),
    dir(ii,ij,ik),
    hotspot(h),
    falloff(f)
{
    ltyp = ESCH_LGTT_SPOT;

    dir.normalize();
};



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschSpotLight - setup                                                    �
//                                                                          �
// Performs the setup of the light on an object by object basis.            �
//���������������������������������������������������������������������������
void EschSpotLight::setup(const EschFrameRef *fr)
{
    if (fr
        && EschCurrent
        && EschCurrent->camera
        && EschCurrent->camera->flags & ESCH_CAM_MODELSPACE)
    {
        pos.transform(&fr->iorient,&tpos);
        dir.transform(&fr->iorient,&tdir);
        tdir = -tdir;

        tinner = inner / fr->scalef;
        touter = outer / fr->scalef;
    }
    else
    {
        tpos = pos;
        tdir = -dir;

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

    hotcos = hotspot.cos();
    fallcos = falloff.cos();

    frate=hfrate=0;
    if ((hotcos-fallcos).flx > 0)
    {
        frate = _intensity / (hotcos-fallcos);
        hfrate = _hintensity / (hotcos-fallcos);
    }
}


//�������������������������������������������������������������������������Ŀ
// EschSpotLight - shine                                                    �
//                                                                          �
// Sets the shade level in the Van Gogh point based on the intesity of the  �
// light and the given vertex information.                                  �
//                                                                          �
// The point light source computes a direction vector relative to the       �
// vertex and then computes a dot product.  The distance and angle away from�
// the spot's direction is used to attenuate the intensity.                 �
//���������������������������������������������������������������������������
void EschSpotLight::shine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
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

            // Use dot product with light to determine fall-off
            Flx16 dotcone = vtx DOT tdir;

            // Check to see if we are inside fall-off cone
            if (dotcone.flx > fallcos.flx)
            {
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

                if (dotcone.flx < hotcos.flx)
                {
                    inten -= (hotcos - dotcone) * frate;
                }

                if ((flags & ESCH_LGT_ATTEN) && (mag.flx > inner.flx))
                {
                    inten -= (mag - inner) * arate;
                }

                if (inten > 0)
                {
                    // Compute final shade value
                    long i = (dot.flx * (inten.flx >> 16)) >> 16;
                    if (vpt->shade < i)
                        vpt->shade = i;
                }
            }
        }
    }

//��� Chain for true multiple lights
    if (inext)
        inext->shine(v,vpt,revnrml);
}


//�������������������������������������������������������������������������Ŀ
// EschSpotLight - hishine                                                  �
//                                                                          �
// Sets the shade level, allowing specular highlights to overdrive the      �
// color based on the intensity of the light and the given vertex info.     �
//                                                                          �
// The point light source computes a direction vector relative to the       �
// vertex and then computes a dot product.  The distance and angle away from�
// the spot's direction is used to attenuate the intensity.                 �
//���������������������������������������������������������������������������
void EschSpotLight::hishine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
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

            // Use dot product with light to determine fall-off
            Flx16 dotcone = vtx DOT tdir;

            // Check to see if we are inside fall-off cone
            if (dotcone.flx > fallcos.flx)
            {
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

                if (dotcone.flx < hotcos.flx)
                {
                    inten -= (hotcos - dotcone) * hfrate;
                }

                if ((flags & ESCH_LGT_ATTEN) && (mag.flx > inner.flx))
                {
                    inten -= (mag - inner) * harate;
                }

                if (inten > 0)
                {
                    // Compute final shade value
                    long i = (dot.flx * (inten.flx >> 16)) >> 16;
                    if (vpt->shade < i)
                        vpt->shade = i;
                }
            }
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
// EschSpotLight - load                                                     �
//                                                                          �
// Loads the position and other data of the attenuated light from an IFF    �
// file.                                                                    �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'lname' is given and the name doesn't match that in the     �
// chunk, an error is returned.                                             �
//���������������������������������������������������������������������������
esch_error_codes EschSpotLight::load(const char *fname, const char *lname)
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

        if (iff.chunkid == iff.makeid('E','S','P','T'))
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

esch_error_codes EschSpotLight::load(XFParseIFF *iff, const char *lname)
{
    EschFileLightSpot   spot;

    assertMyth("EschSpotLight::load requries iff pointer",
               iff);

//�� Verify correct chunk name and size
    if (iff->chunkid != iff->makeid('E','S','P','T'))
        return ESCH_ERR_NOTFOUND;

    if (iff->chunkSize != sizeof(EschFileLightSpot))
        return ESCH_ERR_INVALIDDATA;

//�� Read chunk and verify name, if given.
    if (iff->read(&spot))
        return ESCH_ERR_FILEERROR;

    if (lname && strcmp(lname,spot.name))
        return ESCH_ERR_NOTFOUND;

//�� Found, so setup Spot Light

    strcpy(name,spot.name);
    flags = spot.flags;

    VngoColor24bit  c(spot.color);
    set_intensity( max( max(c.r, c.g), c.b ) );

    set_position( spot.x, spot.y, spot.z );
    set_direction( spot.i, spot.j, spot.k );

    set_inner( spot.inner );
    set_outer( spot.outer );

    set_hotspot( spot.hotspot );
    set_falloff( spot.falloff );

//�� Return ok
    return ESCH_ERR_NONE;
}

//��� End of module - eslspot.cpp ���
