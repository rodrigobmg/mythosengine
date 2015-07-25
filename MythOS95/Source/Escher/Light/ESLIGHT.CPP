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
// eslight.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially the color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// The base light object is an ambient light, shining equally in all
// areas of 3-space.
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
//                                 Data
//
//���������������������������������������������������������������������������

extern char EschNoName[];

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschLight - Constructor                                                  �
//                                                                          �
// Initializes the light object with low itensity and setup as an ambient   �
// light.                                                                   �
//���������������������������������������������������������������������������
EschLight::EschLight(const char *fname, const char *lname) :
    inext(0),
    iprev(0),
    ltyp(ESCH_LGTT_AMBIENT),
    intensity(16),
    flags(0)
{
    strcpy(name,EschNoName);

    if (fname)
    {
        load(fname,lname);
    }
}

EschLight::EschLight(const EschLight &l) :
    inext(0),
    iprev(0),
    _intensity(l._intensity),
    _hintensity(l._hintensity),
    ltyp(l.ltyp),
    intensity(l.intensity),
    na(l.na),
    flags(l.flags)
{
    strncpy(name,l.name,ESCH_MAX_NAME);
}


//�������������������������������������������������������������������������Ŀ
// EschLight - Destructor                                                   �
//                                                                          �
// Unlinks the light from the linked list.                                  �
//���������������������������������������������������������������������������
EschLight::~EschLight()
{
    remove();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschLight - operator =                                                   �
//                                                                          �
// Copies data from another light.                                          �
//���������������������������������������������������������������������������
const EschLight &EschLight::operator = (const EschLight &l)
{
    if (this != &l)
    {
        _intensity = l._intensity;
        _hintensity = l._hintensity;
        intensity = l.intensity;
        na = l.na;
        flags = l.flags;
        strncpy(name,l.name,ESCH_MAX_NAME);
    }
    return *this;
}


//�������������������������������������������������������������������������Ŀ
// EschLight - sibling                                                      �
//                                                                          �
// Makes the camera a sibling of the 'myprev.' object.  This assumes that   �
// the object is not currently attached to anything.                        �
//���������������������������������������������������������������������������
void EschLight::sibling(EschLight *myprev)
{
    assertMyth("EschLight::sibling must have myprev",
               myprev);

    assertMyth("EschLight::sibling requires that object not already be in a list",
               inext == 0 && iprev == 0);

    iprev=myprev;
    inext=myprev->inext;

    myprev->inext = this;
    if (inext)
        inext->iprev = this;
}


//�������������������������������������������������������������������������Ŀ
// EschLight - remove                                                       �
//                                                                          �
// Remove light from light list.                                            �
//���������������������������������������������������������������������������
void EschLight::remove()
{
    if (iprev)
    {
        iprev->inext = inext;
    }

    if (inext)
    {
        inext->iprev=iprev;
    }

    inext=0;
    iprev=0;
}


//�������������������������������������������������������������������������Ŀ
// EschLight - find                                                         �
//                                                                          �
// Searches the siblings of the given camaera and returns the Light object  �
// with the given name, or 0 if not found.                                  �
//���������������������������������������������������������������������������
EschLight *EschLight::find(const char *lname) const
{
    if (!lname)
        return 0;

    if (!strncmp(lname,name,ESCH_MAX_NAME))
        return (EschLight*)this;

    if (!inext)
        return 0;

    return inext->find(lname);
}


//�������������������������������������������������������������������������Ŀ
// EschLight - setup                                                        �
//                                                                          �
// Performs the setup of the light on an object by object basis.            �
//���������������������������������������������������������������������������
void EschLight::setup(const EschFrameRef *fr)
{
//��� Compute internal intensity scales from intensity and 
//��� current palette's midpoint value.

    assertMyth("EschLight::setup needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL && EschCurrent->camera->vport != NULL);

    assertMyth("EschLight::setup needs current context's camera to have a palette",
               EschCurrent->camera->vport->vbuff.pal);

    int mp = EschCurrent->camera->vport->vbuff.pal->shd_pal->mid_point;

    _hintensity = (Flx16)((intensity * VNGO_SHADE_FULL) / 255);
    _intensity = (Flx16)((intensity * mp) / 255);

//��� Chain for true multiple lights
    if (inext)
        inext->setup(fr);
}


//�������������������������������������������������������������������������Ŀ
// EschLight - shine                                                        �
//                                                                          �
// Sets the shade level in the Van Gogh point based on the intesity of the  �
// light and the given vertex information.                                  �
//                                                                          �
// Ambient light simply sets a lower bound on the shade value.              �
//���������������������������������������������������������������������������
void EschLight::shine(const EschVertex *v, VngoPoint *vpt, int revnrml) const
{
    if (!(flags & ESCH_LGT_OFF))
    {
        long i = (long) _intensity;
        if (vpt->shade < i)
            vpt->shade = i;
    }

//��� Chain for true multiple lights
    if (inext)
        inext->shine(v,vpt,revnrml);
}


//�������������������������������������������������������������������������Ŀ
// EschLight - hishine                                                      �
//                                                                          �
// Sets the shade level, allowing specular highlights to overdrive the      �
// color based on the intensity of the light and the given vertex info.     �
//                                                                          �
// Ambient light simply sets a lower bound on the shade value and uses      �
// the standard intensity, since specular hightlights should occurr due to  �
// ambient diffuse light.                                                   �
//���������������������������������������������������������������������������
void EschLight::hishine(const EschVertex *v, VngoPoint *vpt, int revnrml) const
{
    if (!(flags & ESCH_LGT_OFF))
    {
        long i = (long) _intensity;
        if (vpt->shade < i)
            vpt->shade = i;
    }

//��� Chain for true multiple lights
    if (inext)
        inext->hishine(v,vpt,revnrml);
}



//���������������������������������������������������������������������������
//�����������������������������  I/O Routines  ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschLight - load                                                         �
//                                                                          �
// Loads the position and other data of the ambient light from an IFF file. �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'lname' is given and the name doesn't match that in the     �
// chunk, an error is returned.                                             �
//���������������������������������������������������������������������������
esch_error_codes EschLight::load(const char *fname, const char *lname)
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

        if (iff.chunkid == iff.makeid('E','A','M','B'))
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

esch_error_codes EschLight::load(XFParseIFF *iff, const char *lname)
{
    EschFileLightAmbi   amb;

    assertMyth("EschLight::load requries iff pointer",
               iff);

//�� Verify correct chunk name and size
    if (iff->chunkid != iff->makeid('E','A','M','B'))
        return ESCH_ERR_NOTFOUND;

    if (iff->chunkSize != sizeof(EschFileLightAmbi))
        return ESCH_ERR_INVALIDDATA;

//�� Read chunk and verify name, if given.
    if (iff->read(&amb))
        return ESCH_ERR_FILEERROR;

    if (lname && strcmp(lname,amb.name))
        return ESCH_ERR_NOTFOUND;

//�� Found, so setup Ambient Light

    strcpy(name,amb.name);
    flags = amb.flags;

    VngoColor24bit  c(amb.color);
    set_intensity( max( max(c.r, c.g), c.b ) );

//�� Return ok
    return ESCH_ERR_NONE;
}

//��� End of module - eslight.cpp ���
