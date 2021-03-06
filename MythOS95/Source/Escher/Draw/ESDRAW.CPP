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
// esdraw.cpp
//
// The EschDrawable class provides the basic functionality and interface
// for all drawable objects.  Since it is an abstract class, more
// functionality must be derived before the object may be used.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <float.h>

#include "escher.hpp"

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
// EschDrawable - Constructor                                               �
//                                                                          �
// Initializes the drawable to have no flags, siblings, and 'NoName'.  The  �
// constructing object should pass a type identifier to this constructor.   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschDrawable::EschDrawable(word t) :
    inext(0),
    iprev(0),
    dtyp(t),
    limits(ESCH_CAM_SHADE_WIRE
           | ESCH_CAM_SHADE_SOLID
           | ESCH_CAM_SHADE_FLAT
           | ESCH_CAM_SHADE_SMOOTH
           | ESCH_CAM_SHADE_SPECULAR
           | ESCH_CAM_BACKCULL
           | ESCH_CAM_TEXTURED
           | ESCH_CAM_PERSPECTIVE
           | ESCH_CAM_ALPHA
           | ESCH_CAM_SHOW_ALL_LINES),
    flags(0),
    name(EschNoName),
    partn_data(0),
    app_data(0)
{
}

EschDrawable::EschDrawable(const EschDrawable &drw) :
    inext(0),
    iprev(0),
    dtyp(drw.dtyp),
    limits(drw.limits),
    flags(drw.flags & ~ESCH_DRW_OWNSDATA),
    name(drw.name),
    partn_data(0),
    app_data(drw.app_data)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - Destructor                                                �
//                                                                          �
// Ensures the drawable is removed from any list it resides in.             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschDrawable::~EschDrawable()
{
    remove();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - operator =                                                �
//                                                                          �
// Copies the data from another drawable.                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
const EschDrawable &EschDrawable::operator = (const EschDrawable &drw)
{
    if (this != &drw)
    {
        limits = drw.limits;
        flags = drw.flags & ~ESCH_DRW_OWNSDATA;
        name = drw.name;
        app_data = drw.app_data;
    }
    return *this;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - sibling                                                   �
//                                                                          �
// Makes the drawable a sibling of the 'myprev.' object.  This assumes that �
// the object is not currently attached to anything.                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschDrawable::sibling(EschDrawable *myprev)
{
    assertMyth("EschDrawable::sibling must have myprev",
               myprev);

    assertMyth("EschDrawable::sibling requires that object not already be in a list",
               inext == 0 && iprev == 0);

    iprev=myprev;
    inext=myprev->inext;

    myprev->inext = this;
    if (inext)
        inext->iprev = this;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - remove                                                    �
//                                                                          �
// Removes the drawable from the list.                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschDrawable::remove()
{
   if (iprev)
   {
       iprev->inext = inext;
   }

   if (inext)
   {
       inext->iprev = iprev;
   }

   iprev=0;
   inext=0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - find                                                      �
//                                                                          �
// Searches the siblings of the given drawable and returns the Drawable     �
// with the given name, or 0 if not found.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschDrawable *EschDrawable::find(const char *dname) const
{
    if (!dname)
        return 0;

    if (!strncmp(dname,name,ESCH_MAX_NAME))
        return (EschDrawable*)this;

    if (!inext)
        return 0;

    return inext->find(dname);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - get_extents                                               �
//                                                                          �
// Returns the extent of the drawable in world coordinates and 0, or -1 if  �
// the drawable doesn't support extents.                                    �
//                                                                          �
// The base drawable doesn't support this operation.                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschDrawable::get_extents(EschSphereExtents *sp) const
{
    return -1;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - ray                                                       �
//                                                                          �
// Performs a ray intersection test with the object (or its extents),       �
// returning the distance along the ray for the intersection.               �
// It returns a zero if it missed the object, a positive distance along the �
// ray if it hit, or -1 if the intersection is not supported.               �
//                                                                          �
// The base drawable does a ray/sphere intersection if the drawable         �
// supports get_extents.                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
float EschDrawable::ray(const EschPoint *pt, const EschVector *v, int coarse) const
{
    assertMyth("EschDrawable::ray needs point and vector",
               pt != 0 && v != 0);

    EschSphereExtents   sphere;

    if (get_extents(&sphere) != 0)
        return float(-1);

    return sphere.ray(pt,v);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - hit                                                       �
//                                                                          �
// Performs a sphere intersection test with the object (or its extents),    �
// returning 1 if it hit, 0 if it missed, -1 if not supported.              �
//                                                                          �
// The base drawable does a sphere hit test if the drawable supports        �
// get_extents.                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschDrawable::hit(const EschPoint *pt, const float r, int coarse) const
{
    assertMyth("EschDrawable::hit needs point and radius",
               pt != 0 && r >= 0);

    EschSphereExtents   sphere;

    if (get_extents(&sphere) != 0)
        return -1;

    return sphere.hit(pt,r);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - pick                                                      �
//                                                                          �
// Tests the object against other objects using the parameters in the       �
// communication structure, for picking selection.                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschDrawable::pick(EschPicking *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Setup structure, if needed
    if (!(data->flags & ESCH_PICK_NOSETUP))
    {
        data->count = 0;
        data->result = 0;

        if (!(data->flags & ESCH_PICK_ILIST))
            data->ilist = (EschCurrent) ? EschCurrent->eschs : 0;
        if (!data->ilist)
            return ESCH_ERR_NEEDILIST;

        if (!(data->flags & ESCH_PICK_ARENA))
        {
            data->arena = (EschSysInstance) ? EschSysInstance->wspace : 0;
            if (data->arena)
                ivory_arena_clear(data->arena);
        }
        if (!data->arena)
            return ESCH_ERR_NEEDARENA;

        if (!(data->flags & ESCH_PICK_MAXCOUNT))
            data->maxcount = 1;
        if (data->maxcount < 1)
            return ESCH_ERR_INVALIDPARMS;

        if (data->flags & ESCH_PICK_VPORT)
        {
            if (!(data->flags & ESCH_PICK_CAMERA))
                data->camera = (EschCurrent) ? EschCurrent->camera : 0;

            EschCamera *cam = data->camera;
            if (!cam || !cam->vport)
                return ESCH_ERR_NEEDCAMERA;

            //陳� Start ray at camera's position
            cam->get_position(&data->start);

            //陳� Assume point is on projection-plane (1),
            //陳� reverse project, and transform form eye to world

            EschPoint point( (float(data->sx)
                              - float(cam->vport->vbuff.width >> 1))
                             / cam->xscalar,
                             (float(cam->vport->vbuff.height >> 1)
                              - float(data->sy)) / cam->yscalar,
                             1);
            point.transform(&cam->eye.orient);

            //陳� Form vector from point on projection-plane and
            //陳� start position
            data->direction.i = point.x - data->start.x;
            data->direction.j = point.y - data->start.y;
            data->direction.k = point.z - data->start.z;
            data->direction.normalize();
        }
        else if (!(data->flags & ESCH_PICK_WORLD))
            return ESCH_ERR_INVALIDPARMS;
    }

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Walk list
    if (!(data->flags & ESCH_PICK_NOWALK))
    {
        esch_error_codes    err=ESCH_ERR_NONE;

        // Save communication structure for caller
        dword oflags = data->flags & (ESCH_PICK_TESTSELF
                                      | ESCH_PICK_NOSETUP);

        // Inform other routines they don't need to do setup or walk...
        data->flags |= ESCH_PICK_NOWALK
                       | ESCH_PICK_NOSETUP
                       | ESCH_PICK_TESTSELF;

        for(EschDrawable *ptr = data->ilist; ptr != 0; ptr=ptr->next())
        {
            if (!(ptr->flags & ESCH_DRW_SKIPTEST))
            {
                err = ptr->pick(data);
                if (err)
                    break;
            }
        }

        // Restore communication structure for caller
        data->flags &= ~(ESCH_PICK_NOWALK
                         | ESCH_PICK_TESTSELF
                         | ESCH_PICK_NOSETUP);
        data->flags |= oflags;

        return err;
    }

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Test
    if (data->flags & ESCH_PICK_TESTSELF)
    {
        float dist = ray(&data->start,
                         &data->direction,
                         (data->flags & ESCH_PICK_COARSE) ? 1 : 0);

        if (dist <= 0)
            return ESCH_ERR_NONE;

        if (data->flags & ESCH_PICK_MAXDIST
            && dist > data->maxdist)
            return ESCH_ERR_NONE;

        EschDrawList *ptr, *prev, *nptr;

        //陳陳 If at maxcount, then remove last item and take space if
        //陳陳 this is closer
        if (data->count >= data->maxcount)
        {
            for(prev=0, ptr=data->result; ptr != 0; prev=ptr, ptr = ptr->next)
            {
                if (!ptr->next)
                    break;
            }

            assert(ptr != 0 && data->maxcount > 0);

            if (ptr->dist <= dist)
                return ESCH_ERR_NONE;

            if (!prev)
                data->result = ptr->next;
            else
                prev->next = 0;

            nptr = ptr;
        }
        //陳陳 Otherwise allocate new list entry
        {
            assert(data->arena != 0);

            nptr = (EschDrawList*) ivory_arena_alloc(data->arena,
                                                        sizeof(EschDrawList));
            if (!nptr)
                return ESCH_ERR_NOMEMORY;
            data->count++;
        }
        nptr->dist = dist;
        nptr->item = (EschDrawable*)this;
        nptr->next = 0;

        //陳陳 Scan list, if any, for correct sort position
        for(prev=0, ptr=data->result; ptr != 0; prev=ptr, ptr = ptr->next)
        {
            if (ptr->dist > dist)
                break;
        }

        //陳陳 Insert into list
        nptr->next = ptr;
        if (!prev)
            data->result = nptr;
        else
        {
            nptr->next = prev->next;
            prev->next = nptr;
        }
    }

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - collide                                                   �
//                                                                          �
// Tests the object against other objects using the parameters in the       �
// communication structure, for collision.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschDrawable::collide(EschCollision *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Setup structure, if needed
    if (!(data->flags & ESCH_CLSN_NOSETUP))
    {
        data->count = 0;
        data->result = 0;
        data->orig = 0;

        if (!(data->flags & ESCH_CLSN_ILIST))
            data->ilist = (EschCurrent) ? EschCurrent->eschs : 0;
        if (!data->ilist)
            return ESCH_ERR_NEEDILIST;

        if (!(data->flags & ESCH_CLSN_ARENA))
        {
            data->arena = (EschSysInstance) ? EschSysInstance->wspace : 0;
            if (data->arena)
                ivory_arena_clear(data->arena);
        }
        if (!data->arena)
            return ESCH_ERR_NEEDARENA;

        if (!(data->flags & ESCH_CLSN_MAXCOUNT))
            data->maxcount = 1;
        if (data->maxcount < 1)
            return ESCH_ERR_INVALIDPARMS;

        if (!(data->flags & ESCH_CLSN_SPHERE))
        {
            if (get_extents(&data->sphere) != 0)
                return ESCH_ERR_NOTSUPPORTED;

            data->orig = (EschDrawable*)this;
        }
    }

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Walk list
    if (!(data->flags & ESCH_CLSN_NOWALK))
    {
        esch_error_codes    err=ESCH_ERR_NONE;

        // Save communication structure for caller
        dword oflags = data->flags & (ESCH_CLSN_TESTSELF
                                      | ESCH_CLSN_NOSETUP);

        // Inform other routines they don't need to do setup or walk
        // and to test against 'this' since it is the 'target' for
        // the hit detection.

        data->flags |= ESCH_CLSN_NOWALK
                       | ESCH_CLSN_NOSETUP
                       | ESCH_CLSN_TESTSELF;

        for(EschDrawable *ptr = data->ilist; ptr != 0; ptr=ptr->next())
        {
            if (ptr != this && !(ptr->flags & ESCH_DRW_SKIPTEST))
            {
                err = ptr->collide(data);
                if (err)
                    break;
            }
        }

        // Restore communication structure for caller
        data->flags &= ~(ESCH_CLSN_NOWALK
                         | ESCH_CLSN_TESTSELF
                         | ESCH_CLSN_NOSETUP);
        data->flags |= oflags;

        return err;
    }

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Test
    if (data->flags & ESCH_CLSN_TESTSELF)
    {
        int h = hit(&data->sphere.center,
                    data->sphere.radius,
                    (data->flags & ESCH_CLSN_COARSE) ? 1 : 0);

        if (h != 1)
            return ESCH_ERR_NONE;

        //陳陳 If at maxcount, stop
        if (data->count >= data->maxcount)
        {
            return ESCH_ERR_NONE;
        }

        EschDrawList *ptr, *prev, *nptr;

        //陳陳 Otherwise allocate new list entry
        assert(data->arena != 0);

        nptr = (EschDrawList*) ivory_arena_alloc(data->arena,
                                                 sizeof(EschDrawList));
        if (!nptr)
            return ESCH_ERR_NOMEMORY;
        data->count++;

        nptr->item = (EschDrawable*)this;
        nptr->next = 0;

        //陳陳 Scan list insert at end of list
        for(prev=0, ptr=data->result; ptr != 0; prev=ptr, ptr = ptr->next);

        //陳陳 Insert into list
        if (!prev)
            data->result = nptr;
        else
            prev->next = nptr;
    }

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - animate                                                   �
//                                                                          �
// This call is used to inform the drawable to animate itself for the next  �
// frame.  This is called directly by the application when needed.          �
//                                                                          �
// The base drawable does nothing on this call.                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschDrawable::animate()
{
}

//葦� End of module - esdraw.cpp 憶�

