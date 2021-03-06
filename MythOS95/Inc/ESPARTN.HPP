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
// espartn.hpp
//
// Contains the code for the partitioning drawables which optimize
// performance of the drawables within the partitioning.
//
// EschPartition is the abstract base class for the partitioning mechanism.
//
// EschGridPartition is a basic partioning scheme that breaks space into
// a fixed number of uniform regions in the XZ plane.
//
// EschQuadTreeParititon is a 2D adaptive partitioning scheme that breaks
// space into hierarchial regions in the XZ plane.
//
// EschOctTreeParititon is a 3D adaptive partitioning scheme that breaks
// space into hierarchial regions.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESPARTN_HPP
#define __ESPARTN_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "esdraw.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Typedefs
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

typedef int (*EschTraverseCallback) (void *, EschDrawable *);

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPartitionList - Control structure used for making lists of drawables �
//                     within a partition without changing internal links.  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschPartitionList
{
    EschDrawable        *item;
    EschPartitionList   *prev;
    EschPartitionList   *next;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschPartitionList() {}
    EschPartitionList(EschDrawable *_item) :
        item(_item),
        prev(0),
        next(0) {}
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTraverse - Control structure for traversing a partitioning.          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschTraverse
{
    dword                   flags;      // Control flags
    EschTraverseCallback    func;       // Traverse function
    void                    *data;      // Data for traverse function
    EschPoint               pos;        // Start position
    EschVector              dir;        // Traverse direction
    float                   dist;       // Distance from start point
    IvoryArena              *arena;     // Arena for working space

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschTraverse() : flags(0) {}
    EschTraverse(EschPoint &p,
                 EschTraverseCallback f, void *df=0) :
        flags(0),
        func(f),
        data(df),
        pos(p) {}
    EschTraverse(EschPoint &p,
                 float d,
                 EschTraverseCallback f, void *df=0) :
        flags(ESCH_TRAV_DIST),
        func(f),
        data(df),
        pos(p),
        dist(d) {}
    EschTraverse(EschPoint &p,
                 EschVector &v,
                 EschTraverseCallback f, void *df=0) :
        flags(ESCH_TRAV_DIRECTION),
        func(f),
        data(df),
        pos(p),
        dir(v) {}
    EschTraverse(EschPoint &p,
                 EschVector &v, float d,
                 EschTraverseCallback f, void *df=0) :
        flags(ESCH_TRAV_DIRECTION | ESCH_TRAV_DIST),
        func(f),
        data(df),
        pos(p),
        dir(v),
        dist(d) {}
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschQuadTreeNode - Control structure used for quadtree implementation.   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschQuadTreeNode
{
    float               x1;             // World-space location of node
    float               z1;
    float               x2;
    float               z2;
    ushort              depth;          // Depth of node
    ushort              count;          // Count of number of drawables
    EschPartitionList   *draws;         // List of drawables within node
    EschQuadTreeNode    *parent;        // Parent node
    EschQuadTreeNode    *q[4];          // Pointers to quadrants

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschQuadTreeNode() {}
    EschQuadTreeNode(float _x1, float _z1, float _x2, float _z2,
                     EschQuadTreeNode *_parent=0,
                     ushort _depth=0) :
        x1(_x1), z1(_z1),
        x2(_x2), z2(_z2),
        depth(_depth), count(0), draws(0),
        parent(_parent) { memset(q,0,sizeof(q)); }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschQuadTreeStats - Structure for statistics of a quadtree.              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschQuadTreeStats
{
    ushort  hidepth;                    // Highest depth of tree
    ushort  hicount;                    // Highest count in a given node
    ulong   nodes;                      // Number of nodes in tree
    ulong   leaves;                     // Number of leaf nodes in tree
    ulong   items;                      // Number of items in partition
    ulong   items_nonleaf;              // Number of items in non-leaf nodes
    ulong   items_global;               // Number of items in global list
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschOctTreeNode - Control structure used for octtree implementation.     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschOctTreeNode
{
    float               x1;             // World-space location of node
    float               y1;
    float               z1;
    float               x2;
    float               y2;
    float               z2;
    ushort              depth;          // Depth of node
    ushort              count;          // Count of number of drawables
    EschPartitionList   *draws;         // List of drawables within node
    EschOctTreeNode     *parent;        // Parent node
    EschOctTreeNode     *q[8];          // Pointers to quadrants

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschOctTreeNode() {}
    EschOctTreeNode(float _x1, float _y1, float _z1,
                    float _x2, float _y2, float _z2,
                    EschOctTreeNode *_parent=0,
                    ushort _depth=0) :
        x1(_x1), y1(_y1), z1(_z1),
        x2(_x2), y2(_y2), z2(_z2),
        depth(_depth), count(0), draws(0),
        parent(_parent) { memset(q,0,sizeof(q)); }
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschOctTreeStats - Structure for statistics of an octtree.               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschOctTreeStats
{
    ushort  hidepth;                    // Highest depth of tree
    ushort  hicount;                    // Highest count in a given node
    ulong   nodes;                      // Number of nodes in tree
    ulong   leaves;                     // Number of leaf nodes in tree
    ulong   items;                      // Number of items in partition
    ulong   items_nonleaf;              // Number of items in non-leaf nodes
    ulong   items_global;               // Number of items in global list
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class EschBoxExtents;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPartition - Partitioning interface class.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschPartition : public EschDrawable
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschPartition() : EschDrawable(ESCH_DRWT_PARTITION) {}

    virtual ~EschPartition() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschPartition &operator = (const EschPartition &prtn)
    {
        if (this != &prtn)
        {
            release();
            EschDrawable::operator = (prtn);
            flags &= ~ESCH_PARTN_OWNSDRAWS;
        }
        return *this;
    }

    virtual void release()=0;

    virtual esch_error_codes insert(EschDrawable *drw)=0;
    virtual void remove(EschDrawable *drw)=0;

    virtual esch_error_codes traverse(EschTraverse *data) const=0;

    virtual esch_error_codes update(EschDrawable *drw=0)=0;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschGridPartition - 2D uniform regionalized partition.                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschGridPartition : public EschPartition
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    ushort              width;          // Width of grid
    ushort              depth;          // Depth of grid
    float               size;           // World size of each region
    ulong               sizeshift;      // Shift value for size
    EschPoint           origin;         // Origin of grid
    ulong               nregions;       // Number of regions (computed from width*depth)
    EschPartitionList   **regions;      // Region lists

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschGridPartition();
    EschGridPartition(ushort w, ushort d, float s, const EschPoint *o);

    virtual ~EschGridPartition();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual EschDrawable *find(const char *dname) const;

    virtual void draw();

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

    virtual void animate();

    virtual void release();

    virtual esch_error_codes insert(EschDrawable *drw);
    virtual void remove(EschDrawable *drw);

    virtual esch_error_codes traverse(EschTraverse *data) const;

    virtual esch_error_codes update(EschDrawable *drw=0);

    virtual esch_error_codes init(ushort w, ushort d, float s,
                                  const EschPoint *o);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void draw_grid(dword clr) const;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschQuadTreePartition - 2D adaptive partition.                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschQuadTreePartition : public EschPartition
{
protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Internal tree-walk functions.                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschDrawable *walk_find(EschQuadTreeNode *node, const char *dname) const;

    void walk_draw_dumb(EschQuadTreeNode *node);
    void walk_draw(EschQuadTreeNode *node, EschBoxExtents *exts);

    esch_error_codes walk_pick_dumb(EschQuadTreeNode *node, EschPicking *data) const;
    esch_error_codes walk_pick(EschQuadTreeNode *node, EschPicking *data) const;

    esch_error_codes walk_collide_dumb(EschQuadTreeNode *node, EschCollision *data) const;
    esch_error_codes walk_collide(EschQuadTreeNode *node, EschCollision *data) const;

    void walk_animate(EschQuadTreeNode *node);

    void walk_release(EschQuadTreeNode *node);

    esch_error_codes walk_insert(EschQuadTreeNode *node, EschDrawable *drw,
                                 EschSphereExtents &sphere, ushort depth=0);

    void walk_remove(EschQuadTreeNode *node);

    esch_error_codes walk_traverse_dumb(EschQuadTreeNode *node, EschTraverse *data) const;
    esch_error_codes walk_traverse_dir(EschQuadTreeNode *node, EschTraverse *data) const;
    esch_error_codes walk_traverse_area(EschQuadTreeNode *node, EschTraverse *data) const;

    esch_error_codes walk_update(EschQuadTreeNode *node);

    void walk_drawquadtree(EschQuadTreeNode *node,
                           EschCamera *cam, dword clr) const;

    void walk_stats(EschQuadTreeNode *node, EschQuadTreeStats *stats) const;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschQuadTreeNode    *root;          // Root of quadtree
    EschPartitionList   *global;        // Global list (draws outside of tree)
    ushort              maxdepth;       // Maximum tree depth
    ushort              maxcount;       // Max number of object in region

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschQuadTreePartition();
    EschQuadTreePartition(const EschPoint *o, float w, float d=0);

    virtual ~EschQuadTreePartition();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual EschDrawable *find(const char *dname) const;

    virtual void draw();

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

    virtual void animate();

    virtual void release();

    virtual esch_error_codes insert(EschDrawable *drw);
    virtual void remove(EschDrawable *drw);

    virtual esch_error_codes traverse(EschTraverse *data) const;

    virtual esch_error_codes update(EschDrawable *drw=0);

    virtual esch_error_codes init(const EschPoint *o, float w, float d=0);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void draw_quadtree(dword clr) const;

    void compute_stats(EschQuadTreeStats *stats) const;

    void set_maxdepth(ushort m) { maxdepth = m; }
    void set_maxcount(ushort m) { maxcount = m; }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschOctTreePartition -  3D adaptive partition.                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschOctTreePartition : public EschPartition
{
protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Internal tree-walk functions.                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschDrawable *walk_find(EschOctTreeNode *node, const char *dname) const;

    void walk_draw_dumb(EschOctTreeNode *node);
    void walk_draw(EschOctTreeNode *node, EschBoxExtents *exts);

    esch_error_codes walk_pick_dumb(EschOctTreeNode *node, EschPicking *data) const;
    esch_error_codes walk_pick(EschOctTreeNode *node, EschPicking *data) const;

    esch_error_codes walk_collide_dumb(EschOctTreeNode *node, EschCollision *data) const;
    esch_error_codes walk_collide(EschOctTreeNode *node, EschCollision *data) const;

    void walk_animate(EschOctTreeNode *node);

    void walk_release(EschOctTreeNode *node);

    esch_error_codes walk_insert(EschOctTreeNode *node, EschDrawable *drw,
                                 EschSphereExtents &sphere, ushort depth=0);

    void walk_remove(EschOctTreeNode *node);

    esch_error_codes walk_traverse_dumb(EschOctTreeNode *node, EschTraverse *data) const;
    esch_error_codes walk_traverse_dir(EschOctTreeNode *node, EschTraverse *data) const;
    esch_error_codes walk_traverse_area(EschOctTreeNode *node, EschTraverse *data) const;

    esch_error_codes walk_update(EschOctTreeNode *node);

    void walk_drawocttree(EschOctTreeNode *node,
                          EschCamera *cam, dword clr) const;

    void walk_stats(EschOctTreeNode *node, EschOctTreeStats *stats) const;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschOctTreeNode     *root;          // Root of quadtree
    EschPartitionList   *global;        // Global list (draws outside of tree)
    ushort              maxdepth;       // Maximum tree depth
    ushort              maxcount;       // Max number of object in region

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschOctTreePartition();
    EschOctTreePartition(const EschPoint *o,
                         float w, float h=0, float d=0);

    virtual ~EschOctTreePartition();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual EschDrawable *find(const char *dname) const;

    virtual void draw();

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

    virtual void animate();

    virtual void release();

    virtual esch_error_codes insert(EschDrawable *drw);
    virtual void remove(EschDrawable *drw);

    virtual esch_error_codes traverse(EschTraverse *data) const;

    virtual esch_error_codes update(EschDrawable *drw=0);

    virtual esch_error_codes init(const EschPoint *o,
                                  float w, float h=0, float d=0);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void draw_octtree(dword clr) const;

    void compute_stats(EschOctTreeStats *stats) const;

    void set_maxdepth(ushort m) { maxdepth = m; }
    void set_maxcount(ushort m) { maxcount = m; }
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - espartn.hpp 憶�

