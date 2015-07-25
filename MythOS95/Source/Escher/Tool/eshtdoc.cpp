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
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                             *** Escher Tool ***
//
// Chuck Walbourn
//
// eshtdoc.cpp
//
// Escher Tool Document class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//             
//                                Includes
//                                
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "stdafx.h"
#include "eshtool.h"
#include "eshtdoc.h"

#include "esfile.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

struct hier_type
{
    char            pname[ESCH_MAX_NAME];
    EschMeshDraw    *m;
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class CXFile: public XFileDOS
{

public:
		CXFile (CFile *cf)
		{
			fHandle = (void *)cf->m_hFile;
			sFlags = XF_OPEN_READ | XF_OPEN_WRITE | XF_STATUS_OPEN;
		}

		~CXFile ()
		{
			fHandle = INVALID_HANDLE_VALUE;
		}
 
		// DON'T CALL THESE!  They are here to prevent the unwary caller from
		// hosing the file handes (owned by MFC, in this case).
    	xf_error_codes close ()
		{
			return XF_ERR_NONE;
		}

		xf_error_codes open (const char *fname, int mode)
		{
			return XF_ERR_NONE;
		}
};

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

IMPLEMENT_DYNCREATE(ToolDoc, CDocument)

BEGIN_MESSAGE_MAP(ToolDoc, CDocument)
	//{{AFX_MSG_MAP(ToolDoc)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭� Constructor/Destructor 旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc - Constructor                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ToolDoc::ToolDoc() :
    ncameras(0),
    cameras(0),
    nlights(0),
    lights(0),
    nmeshes(0),
    meshes(0),
    hpal(0),
    flags(COMPRESS)
{
    int     i;
    char    *c;
  
    GetModuleFileName(NULL, pfname, 256);

    for (i=strlen(pfname), c = &pfname[i-1]; i > 0; i--, c--)
    {
        if (*c == '\\')
        {
            strcpy(c+1,"DEFAULT.VGP");

            if (xf_exist(pfname))
                break;

            strcpy(c+1,"DEFAULT.PAL");

            if (xf_exist(pfname))
                break;
        }
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc - Destructor                                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ToolDoc::~ToolDoc()
{
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭� Diagnostics 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#ifdef _DEBUG
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc - AssertValid                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void ToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc - Dump                                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void ToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭� Operations 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc - DeleteContents                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void ToolDoc::DeleteContents() 
{
    memset(name,0,sizeof(name));
    memset(desc,0,sizeof(desc));
    memset(auth,0,sizeof(auth));
    memset(copy,0,sizeof(copy));
 
    for (EschLight *lptr=lights; lptr;)
    {
        EschLight   *t=lptr;
        lptr = lptr->next();
        delete t;
    }

    for (EschCameraEx *cptr=cameras; cptr;)
    {
        EschCameraEx  *t=cptr;
        cptr = (EschCameraEx*)cptr->next();
        delete t;
    }

    for (EschMeshDraw *mptr=meshes; mptr;)
    {
        EschMeshDraw    *t=mptr;
        mptr = (EschMeshDraw*) mptr->next();
        t->remove(1);
        delete t;
    }

    cameras=0;
    lights=0;
    meshes=0;
    ncameras=nlights=nmeshes=0;

    if (hpal)
    {
        DeleteObject(hpal);
        hpal=0;
    }

	CDocument::DeleteContents();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                             臼� Protected 臼�                            �
// ToolDoc - count_mesh                                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int ToolDoc::count_mesh(EschMeshDraw *msh)
{
    int i=0;

    for(; msh; msh = (EschMeshDraw*)msh->next(), i++)
    {
        if (msh->child())
            i += count_mesh((EschMeshDraw*)msh->child());
    }

    return i;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc - GetCounts                                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void ToolDoc::GetCounts(ulong *ncams,
                        ulong *nvlgts,
                        ushort *nfplgts, ushort *nfalgts, ushort *nfslgts,
                        ulong *nplgts, ushort *nalgts, ushort *nslgts,
                        ulong *nobjs)
{
    if (ncams)
    {
        *ncams=0;
        for(EschCameraEx *cam=cameras; cam; cam = (EschCameraEx*)cam->next())
            (*ncams)++;
    }

    if (nvlgts)  *nvlgts=0;
    if (nfplgts) *nfplgts=0;
    if (nfalgts) *nfalgts=0;
    if (nfslgts) *nfslgts=0;
    if (nplgts)  *nplgts=0;
    if (nalgts)  *nalgts=0;
    if (nslgts)  *nslgts=0;
    for(EschLight *lgt=lights; lgt; lgt = lgt->next())
    {
        if (lgt->get_type() == ESCH_LGTT_VECTOR && nvlgts)
            (*nvlgts)++;
        else if (lgt->get_type() == ESCH_LGTT_FPOINT && nfplgts)
            (*nfplgts)++;
        else if (lgt->get_type() == ESCH_LGTT_FATTEN && nfalgts)
            (*nfalgts)++;
        else if (lgt->get_type() == ESCH_LGTT_FSPOT && nfslgts)
            (*nfslgts)++;
        else if (lgt->get_type() == ESCH_LGTT_POINT && nplgts)
            (*nplgts)++;
        else if (lgt->get_type() == ESCH_LGTT_ATTEN && nalgts)
            (*nalgts)++;
        else if (lgt->get_type() == ESCH_LGTT_SPOT && nslgts)
            (*nslgts)++;
        // ambients are not counted... supposedly only one.
    }

    if (nobjs)
    {
        *nobjs = count_mesh(meshes);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                             臼� Protected 臼�                            �
// ToolDoc - serialize_store_mesh                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes ToolDoc::serialize_store_mesh(XFParseIFF *iff, EschMeshDraw *msh)
{
    int                 i;
    EschFileMeshHDR     header;

    for(; msh; msh = (EschMeshDraw*)msh->next())
    {
        if (!msh->mesh)
            continue;

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Create a EMSH form
        if (iff->newform(iff->makeid('E','M','S','H')))
        {
            return ESCH_ERR_FILEERROR;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Header
        memset(&header,0,sizeof(EschFileMeshHDR));

        strncpy(header.name,msh->mesh->name,ESCH_MAX_NAME);
        header.nverts=msh->mesh->nverts;
        header.nfaces=msh->mesh->nfaces;
        header.flags = msh->mesh->flags & ~ESCH_MSH_OWNSDATA;
        header.nmtls = (msh->mesh->txt) ? msh->mesh->tmax : 0;

        if (iff->write(iff->makeid('H','D','R',' '),
                       &header,sizeof(EschFileSceneHDR)))
        {
            iff->leaveform();
            return ESCH_ERR_FILEERROR;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Matrix
        if (iff->write(iff->makeid('M','T','R','X'),
                       &msh->local.orient.mtx,sizeof(EschMatrix)))
        {
            iff->leaveform();
            return ESCH_ERR_FILEERROR;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Hierarchy
        if (msh->parent())
        {
            EschFileMeshHIER hier;
            memset(&hier,0,sizeof(EschFileMeshHIER));
            strncpy(hier.parent,msh->parent()->name,ESCH_MAX_NAME);

            if (iff->write(iff->makeid('H','I','E','R'),
                           &hier,sizeof(EschFileMeshHIER)))
            {
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Extent
        {
            EschFileMeshEXNT    extent;
            memset(&extent,0,sizeof(EschFileMeshEXNT));

            extent.cenx.flx          = msh->mesh->sphere.center.x.flx;
            extent.ceny.flx          = msh->mesh->sphere.center.y.flx;
            extent.cenz.flx          = msh->mesh->sphere.center.z.flx;
            extent.extent_radius.flx = msh->mesh->sphere.radius.flx;
            extent.minx.flx          = msh->mesh->box.mins[0].flx;
            extent.miny.flx          = msh->mesh->box.mins[1].flx;
            extent.minz.flx          = msh->mesh->box.mins[2].flx;
            extent.maxx.flx          = msh->mesh->box.maxs[0].flx;
            extent.maxy.flx          = msh->mesh->box.maxs[1].flx;
            extent.maxz.flx          = msh->mesh->box.maxs[2].flx;
        
            if (iff->write(iff->makeid('E','X','N','T'),
                        &extent,sizeof(EschFileMeshEXNT)))
            {
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Material
        if (header.nmtls)
        {
            EschFileMeshMTL     *emtl;

            emtl = new EschFileMeshMTL[header.nmtls];
            if (!emtl)
            {
                iff->leaveform();
                return ESCH_ERR_NOMEMORY;
            }

            for(i=0; i < (int)header.nmtls; i++)
                strncpy(emtl[i].name,msh->mesh->txt[i]->name,ESCH_MAX_NAME);

            if (iff->write(iff->makeid('M','T','L',' '),
                           emtl,sizeof(EschFileMeshMTL)*header.nmtls))
            {
                iff->leaveform();
                delete [] emtl;
                return ESCH_ERR_FILEERROR;
            }

            delete [] emtl;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Verticies
        EschVertex *vptr = (EschVertex*)ivory_hlock(msh->mesh->v);
        if (!vptr)
        {
            iff->leaveform();
            return ESCH_ERR_LOCKFAILED;
        }

        if (iff->write(iff->makeid('V','E','R','T'),
                       vptr,msh->mesh->nverts * sizeof(EschVertex)))
        {
            iff->leaveform();
            ivory_hunlock(msh->mesh->v);
            return ESCH_ERR_FILEERROR;
        }

        ivory_hunlock(msh->mesh->v);

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Faces
        EschFace *fptr = (EschFace*)ivory_hlock(msh->mesh->f);
        if (!fptr)
        {
            iff->leaveform();
            return ESCH_ERR_LOCKFAILED;
        }

        // Convert face color to RGB
        for(i=0; i < (int)msh->mesh->nfaces; i++)
        {
            VngoColor24bit clr = palette.hw_pal.p[(byte)fptr[i].color];
            fptr[i].color = (clr.r | (clr.g << 8) | (clr.b << 16));
        }
        
        if (iff->write(iff->makeid('F','A','C','E'),
                       fptr,msh->mesh->nfaces * sizeof(EschFace)))
        {
            iff->leaveform();
            // Convert face color back to index
            for(i=0; i < (int)msh->mesh->nfaces; i++)
                fptr[i].color = (byte)palette.get_index((VngoColor24bit)fptr[i].color);
            ivory_hunlock(msh->mesh->f);
            return ESCH_ERR_FILEERROR;
        }

        // Convert face color back to index
        for(i=0; i < (int)msh->mesh->nfaces; i++)
            fptr[i].color = (byte)palette.get_index((VngoColor24bit)fptr[i].color);
        ivory_hunlock(msh->mesh->f);

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Texture Data
        if (header.nmtls)
        {
            for(i=0; i < (int)header.nmtls; i++)
            {
                EschFileMtlMHDR mheader;

                EschTexture *t=msh->mesh->txt[i];

                // Make sure it is frame 0.
                if (t->get_type() == ESCH_TXTT_MFRAME)
                    ((EschMultiFrameTexture*)t)->reset();

                // Must lock texture to output data
                t->lock();
                if (!t->ptr)
                {
                    iff->leaveform();
                    return ESCH_ERR_LOCKFAILED;
                }

                ASSERT(t->ptr->tex);

                // Determine if transparent
                BOOL transp=FALSE;
                byte *tptr=t->ptr->tex;
                for(int j=0; j < (t->ptr->width*t->ptr->height); j++)
                {
                    if (*(tptr++) == VNGO_TRANSPARENT_COLOR)
                    {
                        transp=TRUE;
                        break;
                    }
                }
               
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Create EMTL form
                if (iff->newform((t->get_type() == ESCH_TXTT_MFRAME)
                                 ? iff->makeid('E','M','T','1')
                                 : iff->makeid('E','M','T','L')))
                {
                    iff->leaveform();
                    t->unlock();
                    return ESCH_ERR_FILEERROR;
                }
        
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Header
                memset(&mheader,0,sizeof(EschFileMtlMHDR));

                strncpy(mheader.name,t->name,ESCH_MAX_NAME);

                strncpy(mheader.pname,"Default",16);

                mheader.nframes = (t->get_type() == ESCH_TXTT_MFRAME)
                                  ? ((EschMultiFrameTexture*)t)->max
                                  : 1;

                if (flags & TRUECOLOR)
                {
                    mheader.type = (transp)
                                   ? ESCH_MTL_TYPE_32BIT
                                   : ESCH_MTL_TYPE_24BIT;
                }
                else
                {
                    mheader.type = (transp)
                                   ? ESCH_MTL_TYPE_8BIT_TRANSP 
                                   : ESCH_MTL_TYPE_8BIT;
                }
                mheader.compress = (flags & COMPRESS)
                                   ? ESCH_MTL_COMPRESS_RLE
                                   : ESCH_MTL_COMPRESS_NONE;

                mheader.flags = t->flags & ~(ESCH_TXT_LOCKED
                                             | ESCH_TXT_OWNSDATA
                                             | ESCH_TXT_SHARED);

                mheader.xsize = t->ptr->width;
                mheader.ysize = t->ptr->height;

                ASSERT((mheader.xsize * mheader.ysize) > 0);

                if (iff->write(iff->makeid('M','H','D','R'),
                               &mheader,sizeof(EschFileMtlMHDR)))
                {
                    iff->leaveform();
                    t->unlock();
                    return ESCH_ERR_FILEERROR;
                }
                
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Body
                int bpp=1;
                if (flags & TRUECOLOR)
                    bpp = (transp) ? 4 : 3;

                tptr = t->ptr->tex;
                for(j=0; j < (int)mheader.nframes; j++)
                {
                    byte *body=tptr;

                    if (flags & TRUECOLOR)
                    {
                        body=new byte[mheader.xsize*mheader.ysize*bpp];
                        if (!body)
                        {
                            iff->leaveform();
                            t->unlock();
                            return ESCH_ERR_NOMEMORY;
                        }

                        byte *sptr=tptr;
                        byte *dptr=body;
                        for(int k=0; k < (int)(mheader.xsize*mheader.ysize); k++)
                        {
                            if (*sptr == VNGO_TRANSPARENT_COLOR)
                            {
                                assert(transp);
                                *(dptr++) = 0;
                                *(dptr++) = 0;
                                *(dptr++) = 0;
                                *(dptr++) = 0;
                            }
                            else
                            {
                                VngoColor24bit clr = palette.hw_pal.p[*sptr];
                                *(dptr++) = clr.r;
                                *(dptr++) = clr.g;
                                *(dptr++) = clr.b;

                                if (transp)
                                    *(dptr++) = 255;
                            }
                            sptr++;
                        }
                    }

                    byte *work = new byte[mheader.xsize*mheader.ysize*bpp];
                    if (!work)
                    {
                        if (flags & TRUECOLOR)
                            delete [] body;
                        iff->leaveform();
                        t->unlock();
                        return ESCH_ERR_NOMEMORY;
                    }

                    dword size=0;
                    if (flags & COMPRESS)
                    {
                        if (flags & TRUECOLOR)
                        {
                            if (transp)
                            {
                                size=XFParseXEB::compress_rle_32bpp(mheader.xsize,
                                                                    mheader.ysize,
                                                                    body,work);
                            }
                            else
                            {
                                size=XFParseXEB::compress_rle_24bpp(mheader.xsize,
                                                                    mheader.ysize,
                                                                    body,work);
                            }
                        }
                        else
                        {
                            size=XFParseXEB::compress_rle_8bpp(mheader.xsize,
                                                               mheader.ysize,
                                                               body,work);
                        }
                    }

                    if (size)
                    {
                        if (flags & TRUECOLOR)
                            delete [] body;

                        if (iff->write(iff->makeid('B','O','D','Y'),work,size))
                        {
                            iff->leaveform();
                            t->unlock();
                            return ESCH_ERR_FILEERROR;
                        }
                    }
                    else
                    {
                        delete [] work;
                        if (iff->write(iff->makeid('B','O','D','Y'), body,
                                       (ulong)(mheader.xsize*mheader.ysize*bpp)))
                        {
                            if (flags & TRUECOLOR)
                                delete [] body;
                            iff->leaveform();
                            t->unlock();
                            return ESCH_ERR_FILEERROR;
                        }

                        if (flags & TRUECOLOR)
                            delete [] body;
                    }

                    tptr += (mheader.xsize*mheader.ysize);
                }

                iff->leaveform();

                t->unlock();
            }
        }

        iff->leaveform();

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Store Children
        if (msh->child())
        {
            esch_error_codes err=serialize_store_mesh(iff,(EschMeshDraw*)msh->child());
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc - Serialize                                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void ToolDoc::Serialize(CArchive& ar)
{
    CXFile      f(ar.GetFile());
    XFParseIFF  iff(&f);

    iff.begin();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Saving
	if (ar.IsStoring())
	{
        esch_error_codes    err;
        EschFileSceneHDR    sdata;
        EschCameraEx        *cam;
        EschLight           *lgt;

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Create a ESEN form
        if (iff.newform(iff.makeid('E','S','E','N')))
        {
            err=ESCH_ERR_FILEERROR;
            goto save_error_exit;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Header
        memset(&sdata,0,sizeof(EschFileSceneHDR));
        strcpy(sdata.name,name);

        GetCounts(&sdata.ncameras,
                  &sdata.nvectorlights,
                  &sdata.nfpointlights,
                  &sdata.nfattenlights,
                  &sdata.nfspotlights,
                  &sdata.npointlights,
                  &sdata.nattenlights,
                  &sdata.nspotlights,
                  &sdata.nobjects);

        if (iff.write(iff.makeid('H','D','R',' '),
                      &sdata,sizeof(EschFileSceneHDR)))
        {
            err=ESCH_ERR_FILEERROR;
            goto save_error_exit;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Description
        if (*desc)
        {
            if (iff.write(iff.makeid('D','E','S','C'),
                          desc,strlen(desc)))
            {
                err=ESCH_ERR_FILEERROR;
                goto save_error_exit;
            }
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Author
        if (*auth)
        {
            if (iff.write(iff.makeid('A','U','T','H'),
                          auth,strlen(auth)))
            {
                err=ESCH_ERR_FILEERROR;
                goto save_error_exit;
            }
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Copyright
        if (*copy)
        {
            if (iff.write(iff.makeid('(','C',')',' '),
                          copy,strlen(copy)))
            {
                err=ESCH_ERR_FILEERROR;
                goto save_error_exit;
            }
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Cameras
        for(cam=cameras; cam; cam = (EschCameraEx*)cam->next())
        {
            EschFileCamera  cdata;
            memset(&cdata,0,sizeof(EschFileCamera));

            strncpy(cdata.name,cam->name,ESCH_MAX_NAME);
            cdata.flags = cam->flags & ~(ESCH_CAM_OWNSBITMAP
                                         | ESCH_CAM_OWNSHAZE);

            EschPoint  pos;
            cam->get_position(&pos);
            cdata.x.flx = pos.x.flx;
            cdata.y.flx = pos.y.flx;
            cdata.z.flx = pos.z.flx;

            cdata.fov.flx = cam->fov.flx;
            
            cdata.diri.flx = cam->eye.dir.i.flx;
            cdata.dirj.flx = cam->eye.dir.j.flx;
            cdata.dirk.flx = cam->eye.dir.k.flx;
            
            cdata.topi.flx = cam->top.i.flx;
            cdata.topj.flx = cam->top.j.flx;
            cdata.topk.flx = cam->top.k.flx;


            if (iff.write(iff.makeid('E','C','A','M'),
                          &cdata,sizeof(EschFileCamera)))
            {
                err=ESCH_ERR_FILEERROR;
                goto save_error_exit;
            }
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Lights
        for(lgt=lights; lgt; lgt = lgt->next())
        {
            if (lgt->get_type() == ESCH_LGTT_VECTOR)
            {
                EschFileLightVect   vec;
                memset(&vec,0,sizeof(EschFileLightVect));

                strncpy(vec.name,lgt->name,ESCH_MAX_NAME);
                vec.flags = lgt->flags;

                byte i = lgt->get_intensity();
                vec.color = i << 16 | i << 8 | i;

                vec.i.flx = ((EschVectorLight*)lgt)->dir.i.flx;
                vec.j.flx = ((EschVectorLight*)lgt)->dir.j.flx;
                vec.k.flx = ((EschVectorLight*)lgt)->dir.k.flx;

                if (iff.write(iff.makeid('E','V','E','C'),
                              &vec,sizeof(EschFileLightVect)))
                {
                    err=ESCH_ERR_FILEERROR;
                    goto save_error_exit;
                }
            }
            else if (lgt->get_type() == ESCH_LGTT_FPOINT
                     || lgt->get_type() == ESCH_LGTT_POINT)
            {
                EschFileLightPoint   pnt;
                memset(&pnt,0,sizeof(EschFileLightPoint));

                strncpy(pnt.name,lgt->name,ESCH_MAX_NAME);
                pnt.flags = lgt->flags;

                byte i = lgt->get_intensity();
                pnt.color = i << 16 | i << 8 | i;

                if (lgt->get_type() == ESCH_LGTT_FPOINT)
                {
                    pnt.x.flx = ((EschFastPointLight*)lgt)->pos.x.flx;
                    pnt.y.flx = ((EschFastPointLight*)lgt)->pos.y.flx;
                    pnt.z.flx = ((EschFastPointLight*)lgt)->pos.z.flx;
                }
                else
                {
                    pnt.x.flx = ((EschPointLight*)lgt)->pos.x.flx;
                    pnt.y.flx = ((EschPointLight*)lgt)->pos.y.flx;
                    pnt.z.flx = ((EschPointLight*)lgt)->pos.z.flx;
                }

                if (iff.write((lgt->get_type() == ESCH_LGTT_FPOINT)
                              ? iff.makeid('E','F','P','T')
                              : iff.makeid('E','P','N','T'),
                              &pnt,sizeof(EschFileLightPoint)))
                {
                    err=ESCH_ERR_FILEERROR;
                    goto save_error_exit;
                }
            }
            else if (lgt->get_type() == ESCH_LGTT_FATTEN
                     || lgt->get_type() == ESCH_LGTT_ATTEN)
            {
                EschFileLightAtten atn;
                memset(&atn,0,sizeof(EschFileLightAtten));

                strncpy(atn.name,lgt->name,ESCH_MAX_NAME);
                atn.flags = lgt->flags;

                byte i = lgt->get_intensity();
                atn.color = i << 16 | i << 8 | i;

                if (lgt->get_type() == ESCH_LGTT_FATTEN)
                {
                    atn.x.flx = ((EschFastAttenLight*)lgt)->pos.x.flx;
                    atn.y.flx = ((EschFastAttenLight*)lgt)->pos.y.flx;
                    atn.z.flx = ((EschFastAttenLight*)lgt)->pos.z.flx;
                    atn.inner = ((EschFastAttenLight*)lgt)->inner.flx;
                    atn.outer = ((EschFastAttenLight*)lgt)->outer.flx;
                }
                else
                {
                    atn.x.flx = ((EschAttenLight*)lgt)->pos.x.flx;
                    atn.y.flx = ((EschAttenLight*)lgt)->pos.y.flx;
                    atn.z.flx = ((EschAttenLight*)lgt)->pos.z.flx;
                    atn.inner = ((EschAttenLight*)lgt)->inner.flx;
                    atn.outer = ((EschAttenLight*)lgt)->outer.flx;
                }

                if (iff.write((lgt->get_type() == ESCH_LGTT_FATTEN)
                              ? iff.makeid('E','F','A','T')
                              : iff.makeid('E','A','T','N'),
                              &atn,sizeof(EschFileLightAtten)))
                {
                    err=ESCH_ERR_FILEERROR;
                    goto save_error_exit;
                }
            }
            else if (lgt->get_type() == ESCH_LGTT_FSPOT
                     || lgt->get_type() == ESCH_LGTT_SPOT)
            {
                EschFileLightSpot   spot;
                memset(&spot,0,sizeof(EschFileLightSpot));

                strncpy(spot.name,lgt->name,ESCH_MAX_NAME);
                spot.flags = lgt->flags;

                byte i = lgt->get_intensity();
                spot.color = i << 16 | i << 8 | i;

                if (lgt->get_type() == ESCH_LGTT_FSPOT)
                {
                    spot.x.flx = ((EschFastSpotLight*)lgt)->pos.x.flx;
                    spot.y.flx = ((EschFastSpotLight*)lgt)->pos.y.flx;
                    spot.z.flx = ((EschFastSpotLight*)lgt)->pos.z.flx;
                    spot.i.flx = ((EschFastSpotLight*)lgt)->dir.i.flx;
                    spot.j.flx = ((EschFastSpotLight*)lgt)->dir.j.flx;
                    spot.k.flx = ((EschFastSpotLight*)lgt)->dir.k.flx;
                    spot.hotspot.flx = ((EschFastSpotLight*)lgt)->hotspot.flx;
                    spot.falloff.flx = ((EschFastSpotLight*)lgt)->falloff.flx;
                    spot.inner.flx = ((EschFastSpotLight*)lgt)->inner.flx;
                    spot.outer.flx = ((EschFastSpotLight*)lgt)->outer.flx;
                }
                else
                {
                    spot.x.flx = ((EschSpotLight*)lgt)->pos.x.flx;
                    spot.y.flx = ((EschSpotLight*)lgt)->pos.y.flx;
                    spot.z.flx = ((EschSpotLight*)lgt)->pos.z.flx;
                    spot.i.flx = ((EschSpotLight*)lgt)->dir.i.flx;
                    spot.j.flx = ((EschSpotLight*)lgt)->dir.j.flx;
                    spot.k.flx = ((EschSpotLight*)lgt)->dir.k.flx;
                    spot.hotspot.flx = ((EschSpotLight*)lgt)->hotspot.flx;
                    spot.falloff.flx = ((EschSpotLight*)lgt)->falloff.flx;
                    spot.inner.flx = ((EschSpotLight*)lgt)->inner.flx;
                    spot.outer.flx = ((EschSpotLight*)lgt)->outer.flx;
                }

                if (iff.write((lgt->get_type() == ESCH_LGTT_FSPOT)
                              ? iff.makeid('E','F','S','P')
                              : iff.makeid('E','S','P','T'),
                              &spot,sizeof(EschFileLightSpot)))
                {
                    err=ESCH_ERR_FILEERROR;
                    goto save_error_exit;
                }
            }
            else // ESCH_LGTT_AMBIENT
            {
                EschFileLightAmbi   amb;
                memset(&amb,0,sizeof(EschFileLightAmbi));

                strncpy(amb.name,lgt->name,ESCH_MAX_NAME);
                amb.flags = lgt->flags;

                byte i = lgt->get_intensity();
                amb.color = i << 16 | i << 8 | i;

                if (iff.write(iff.makeid('E','A','M','B'),
                              &amb,sizeof(EschFileLightAmbi)))
                {
                    err=ESCH_ERR_FILEERROR;
                    goto save_error_exit;
                }
            }
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Meshes
        err=serialize_store_mesh(&iff,meshes);
        if (err)
            goto save_error_exit;

        //陳 Return OK
        iff.leaveform();
        return;

         //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Save Error
         // Handle error return during save
save_error_exit: ;

        iff.leaveform();

        char    str[512];

        sprintf(str,"Error error 0x%x saving file.",(int)err);
                                              
        MessageBox(NULL,
                   str,"Escher Tool",MB_OK | MB_ICONEXCLAMATION);

        AfxThrowArchiveException(CArchiveException::generic);
        return;
	}
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Loading
	else
	{
        ulong               i;
        esch_error_codes    err;
        ulong               ncams=0;
        ulong               nmshs=0;
        ulong               nlgts=0;
        struct hier_type    *hier=0;
        EschFileSceneHDR    header;
        char                pname[ESCH_MAX_NAME];

        // Eventually should make a list of all scenes within the file and
        // user to select.  For now, we just take the first scene form.

        // See if there is a corresponding palette file for this
        // scene...

        char tmp[256], *c;
        strncpy(tmp,ar.GetFile()->GetFilePath(),256);
        for (i=strlen(tmp), c = &tmp[i-1]; c > 0; i--, c--)
        {
            if (*c == '.')
            {
                strcpy(c+1,"VGP");

                if (xf_exist(tmp))
                {
                    strcpy(pfname,tmp);
                    break;
                }

                strcpy(c+1,"PAL");

                if (xf_exist(tmp))
                {
                    strcpy(pfname,tmp);
                    break;
                }

                break;
            }
        }

        //陳� Load palette (required)
        if (!LoadPalette(pfname))
        {
            MessageBox(NULL,
                       "Must have a valid Van Gogh palette","Fatal Error",MB_OK | MB_ICONEXCLAMATION);
            AfxThrowArchiveException(CArchiveException::generic);
        }

        for(;;)
        {
            if (iff.next() != XF_ERR_NONE)
            {
                AfxThrowArchiveException(CArchiveException::endOfFile);
                return;
            }

            if (iff.chunkid != iff.makeid('F','O','R','M')
                || iff.formid != iff.makeid('E','S','E','N'))
                continue;

            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Found an ESEN form
            
            iff.enterform();

            //陳� Handle header
            if (iff.seekchunk(iff.makeid('H','D','R',' '))
                || iff.chunkSize != sizeof(EschFileSceneHDR))
            {
                AfxThrowArchiveException(CArchiveException::badIndex);
                return;
            }

            if (iff.read(&header))
            {
                AfxThrowArchiveException(CArchiveException::generic);
                return;
            }

            //陳� Copy data

            strcpy(name,header.name);
            nmeshes = header.nobjects;
            ncameras = header.ncameras;
            nlights = header.nvectorlights
                      + header.nfpointlights
                      + header.nfattenlights
                      + header.nfspotlights
                      + header.npointlights
                      + header.nattenlights
                      + header.nspotlights;

            // Allocate memory for hiearchy patchup
            if (header.nobjects)
            {
                hier = new hier_type[nmeshes];
                if (!hier)
                {
                    AfxThrowMemoryException();
                    return;
                }
                memset(hier,0,sizeof(hier_type)*nmeshes);
            }

            //陳 Scan and load chunks in form
            while (iff.next() == XF_ERR_NONE)
            {
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Description
                if (iff.chunkid == iff.makeid('D','E','S','C')
                    && iff.chunkSize < 256)
                {
                    if (iff.read(desc))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Author
                else if (iff.chunkid == iff.makeid('A','U','T','H')
                         && iff.chunkSize < 256)
                {
                    if (iff.read(auth))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Copyright
                else if (iff.chunkid == iff.makeid('(','C',')',' ')
                          && iff.chunkSize < 256)
                {
                    if (iff.read(copy))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Meshes
                else if (iff.chunkid == iff.makeid('F','O','R','M') 
                         && iff.formid == iff.makeid('E','M','S','H'))
                {
                    EschMeshDraw    *m;

                    m = new EschMeshDraw;
                    if (!m)
                    {
                        AfxThrowMemoryException();
                        return;
                    }

                    err=m->load(&iff,0,&palette,0,pname,ESCH_MSHLD_USEMFTXT);
                    if (err!=ESCH_ERR_NONE)
                    {
                        delete m;
                        goto load_error_exit;
                    }

                    if (!*pname)
                    {
                        // Root object or not using hierarchies

                        if (meshes)
                            m->sibling(meshes);
                        else
                            meshes=m;
                    }
                    else
                    {
                        // Need to save for later patchup
    
                        strncpy(hier[nmshs].pname,pname,ESCH_MAX_NAME);
                        hier[nmshs].m = m;
                    }
                    nmshs++;
                }

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Cameras
                else if (iff.chunkid == iff.makeid('E','C','A','M'))
                {
                    EschCameraEx *c;
            
                    c = new EschCameraEx;
                    if (!c)
                    {
                        AfxThrowMemoryException();
                        return;
                    }

                    if ((err=c->load(&iff))!=0)
                    {
                        delete c;
                        goto load_error_exit;
                    }

                    if (cameras)
                        c->sibling(cameras);
                    else
                        cameras=c;

                    c->set_bcolor(palette.get_index(VngoColor24bit(20,20,32)));

                    ncams++;
                }

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Lights
                else if (iff.chunkid == iff.makeid('E','A','M','B')
                         || iff.chunkid == iff.makeid('E','V','E','C')
                         || iff.chunkid == iff.makeid('E','F','P','T')
                         || iff.chunkid == iff.makeid('E','F','A','T')
                         || iff.chunkid == iff.makeid('E','F','S','P')
                         || iff.chunkid == iff.makeid('E','P','N','T')
                         || iff.chunkid == iff.makeid('E','A','T','N')
                         || iff.chunkid == iff.makeid('E','S','P','T') )
                {
                    EschLight   *l;
            
                    if (iff.chunkid == iff.makeid('E','A','M','B'))
                        l = new EschLight;
                    else if (iff.chunkid == iff.makeid('E','V','E','C'))
                        l = (EschLight*)new EschVectorLight;
                    else if (iff.chunkid == iff.makeid('E','F','P','T'))
                        l = (EschLight*)new EschFastPointLight;
                    else if (iff.chunkid == iff.makeid('E','F','A','T'))
                        l = (EschLight*)new EschFastAttenLight;
                    else if (iff.chunkid == iff.makeid('E','F','S','P'))
                        l = (EschLight*)new EschFastSpotLight;
                    else if (iff.chunkid == iff.makeid('E','P','N','T'))
                        l = (EschLight*)new EschPointLight;
                    else if (iff.chunkid == iff.makeid('E','A','T','N'))
                        l = (EschLight*)new EschAttenLight;
                    else if (iff.chunkid == iff.makeid('E','S','P','T'))
                        l = (EschLight*)new EschSpotLight;

                    if (!l)
                    {
                        AfxThrowMemoryException();
                        return;
                    }

                    if ((err=l->load(&iff))!=0)
                    {
                        delete l;
                        goto load_error_exit;
                    }

                    if (lights)
                        l->sibling(lights);
                    else
                        lights = l;

                    if (iff.chunkid != iff.makeid('E','A','M','B'))
                        nlgts++;
                }
            }

            //陳 Handle hierarchy patchup
            int             changed;
            EschMeshDraw    *m;

            // Looping, inserting objects that have parents already in drawable
            // tree.
            for(;;)
            {
                changed=0;
                for(i=0; i < nmeshes; i++)
                {
                    if (hier[i].m)
                    {
                        m=(EschMeshDraw*)meshes->find(hier[i].pname);
                        if (m)
                        {
                            changed=1;
                            hier[i].m->adopt(m);
                            hier[i].m=0;
                        }
                    }
                }

                if (!changed)
                    break;
            }

            // See if any objects are still not attached
            for(err=ESCH_ERR_NONE, i=0; i < nmeshes; i++)
            {
                if (hier[i].m)
                {
                    delete hier[i].m;
                    err=ESCH_ERR_INVALIDHIER;
                }
            }

            delete [] hier;

            if (err)
                goto load_error_exit;

            //陳 Verify counts are as expected
            if (ncams != ncameras || nmshs != nmeshes || nlgts != nlights)
            {
                err=ESCH_ERR_MISSINGITEMS;
                goto load_error_exit;
            }

            //陳 Return OK
            iff.leaveform();
            return;

            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Load Error
            // Handle error return during load, must free partial data
load_error_exit: ;

            if (hier)
                delete [] hier;
            iff.leaveform();

            char    str[512];

            sprintf(str,"Escher error 0x%x loading file.",(int)err);
                                                  
            MessageBox(NULL,
                       str,"Escher Tool",MB_OK | MB_ICONEXCLAMATION);

            AfxThrowArchiveException(CArchiveException::generic);
            return;
        }
	}
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc - LoadPalette                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL ToolDoc::LoadPalette(const char *fname)
{
    int             err;
    VngoPal8        *palptr=&palette;
    VngoPalIFF8     loadpal(palptr);

    palptr->init(0);
    err=loadpal.load(fname);

    if (err)
    {
        char    str[512];

        sprintf(str,"Error #%x loading Van Gogh palette file:\n\n%s",(int)err,fname);
                                                  
        MessageBox(NULL,
                   str,"Error",MB_OK | MB_ICONEXCLAMATION);

        return FALSE;
    }  

    if (fname != pfname)
        strcpy(pfname,fname);
 
    LOGPALETTE *lpal = (LOGPALETTE *) ivory_alloc(sizeof(LOGPALETTE)
                                                  + 256*sizeof(PALETTEENTRY));

    lpal->palVersion = 0x300;
    lpal->palNumEntries = 256;

    for (int i=0; i < 256; i++)
    {
        lpal->palPalEntry[i].peRed  = palptr->hw_pal.p[i].r;
        lpal->palPalEntry[i].peGreen= palptr->hw_pal.p[i].g;
        lpal->palPalEntry[i].peBlue = palptr->hw_pal.p[i].b;
        lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
    }

    if (hpal)
        DeleteObject(hpal);

    hpal = CreatePalette(lpal);

    ivory_free( (void**)&lpal );

    if (!hpal)
    {
        MessageBox(NULL,
                   "Failed to create a palette from Van Gogh palette file","Error",MB_OK | MB_ICONEXCLAMATION);

        return FALSE;       
    }

    return TRUE;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭 Message Handlers 旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ToolDoc - OnNewDocument                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL ToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

    strcpy(name,"NoName");
    *desc = 0;
    SetTitle(name);

    flags = COMPRESS;

//陳� Load default palette (required)
    if (!LoadPalette(pfname))
    {
        MessageBox(NULL,
                   "Must have a valid default Van Gogh palette","Fatal Error",MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

	return TRUE;
}

//葦� eof - eshtdoc.cpp 憶�
