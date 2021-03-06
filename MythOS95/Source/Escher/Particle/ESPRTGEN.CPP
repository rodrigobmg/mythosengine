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
// esprtgen.cpp
//
// Contains the code for the EschParticleGenerator class which creates
// particles based on stochastic parameters.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                 Macros
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

// Returns a uniform psuedo random number between -1.0 and 1.0
#define RANDOM() (float(flx_rand().flx) / 2147483647.0f)

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleGenerator - Constructor                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschParticleGenerator::EschParticleGenerator() :
    EschParticleSystem(),
    func(esch_generate_particle),
    data(0),
    pal(0),
    rot_rate(0),
    var_rot_rate(0),
    rot_rate_low(0),
    rot_rate_high(0),
    init_dir(0,1,0)
{
    dtyp = ESCH_DRWT_PGENERATOR;
};

EschParticleGenerator::EschParticleGenerator(ulong mc) :
    EschParticleSystem(),
    func(esch_generate_particle),
    data(0),
    pal(0),
    rot_rate(0),
    var_rot_rate(0),
    rot_rate_low(0),
    rot_rate_high(0),
    init_dir(0,1,0)
{
    dtyp = ESCH_DRWT_PGENERATOR;

    init(mc);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleGenerator - Destructor                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschParticleGenerator::~EschParticleGenerator()
{
};



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleGenerator - init                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschParticleGenerator::init(ulong mc)
{
    part_accum = 0;

//陳� Call base
    esch_error_codes err = EschParticleSystem::init(mc);
    if (err)
        return err;

//陳� Set default values
    world.reset();                      // Align to world space
    set_sphere(1);                      // Sphere generation area of size 1
    set_parts(1);                       // 1 particle per second
    set_speed(1);                       // 1 unit per second speed
    set_size(0);                        // Size of 0
    set_lifetime(10);                   // 10 frame lifetime
    set_color(1);                       // Color index 1
    set_alpha(255);                     // Alpha level 255

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleGenerator - animate                                          �
//                                                                          �
// This calls the base animate after generating new particles.              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschParticleGenerator::animate()
{
    if (!(flags & ESCH_PRTG_NOAUTOGENERATE))
        generate();

    EschParticleSystem::animate();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleGenerator - generate                                         �
//                                                                          �
// This call generates new particles.                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong EschParticleGenerator::generate()
{
//陳� Determine how many particles to generate this frame based on
//陳� distribution as either frame-based or time-based rates
    if (flags & ESCH_PRTG_FRAMEBASED)
    {
        if (var_parts > 0)
            part_accum += (mean_parts + RANDOM()*var_parts);
        else
            part_accum += mean_parts;
    }
    else
    {
        if (var_parts > 0)
            part_accum += (mean_parts + RANDOM()*var_parts) * interval;
        else
            part_accum += mean_parts * interval;
    }

//陳� Create new particles, if any
    ulong count = 0;
    for(count=0; part_accum >= 1; part_accum -= 1.0f, count++)
    {
        EschParticleGenParams parms(this,data);

        //陳� Compute position/directory based on generation area in local
        if (flags & ESCH_PRTG_CIRCLE)
        {
            //陳陳陳陳� Circular generation area on x/z plane of local coords
            assertMyth("EschParticleGenerator::generate needs valid circle radius",
                       gsize1 > 0);

            parms.pos.x = RANDOM() * gsize1;
            parms.pos.y = 0;
            parms.pos.z = RANDOM() * gsize1;

            parms.velocity.i = init_dir.i;
            parms.velocity.j = init_dir.j;
            parms.velocity.k = init_dir.k;

            assertMyth("EschParticleGenerator::generate needs valid max angle",
                       maxangle >= 0);

            if (maxangle > 0)
            {
                parms.velocity.rotatex(RANDOM()*maxangle);
                parms.velocity.rotatez(RANDOM()*maxangle);
            }
        }
        else if (flags & ESCH_PRTG_RECTANGLE)
        {
            //陳陳陳 Rectangular generation area on x/z plane of local coords
            assertMyth("EschParticleGenerator::generate needs valid rectangle size",
                       (gsize1 > 0) && (gsize2 > 0));

            parms.pos.x = RANDOM() * gsize1;
            parms.pos.y = 0;
            parms.pos.z = RANDOM() * gsize2;

            parms.velocity.i = init_dir.i;
            parms.velocity.j = init_dir.j;
            parms.velocity.k = init_dir.k;

            assertMyth("EschParticleGenerator::generate needs valid max angle",
                       maxangle >= 0);

            if (maxangle > 0)
            {
                parms.velocity.rotatex(RANDOM()*maxangle);
                parms.velocity.rotatez(RANDOM()*maxangle);
            }
        }
        else
        {
            //陳陳陳陳陳陳陳陳� Spherical generation area within local coords
            assertMyth("EschParticleGenerator::generate needs valid sphere radius",
                       gsize1 > 0);

            parms.pos.x = RANDOM() * gsize1;
            parms.pos.y = RANDOM() * gsize1;
            parms.pos.z = RANDOM() * gsize1;

            parms.velocity.i = parms.pos.x;
            parms.velocity.j = parms.pos.y;
            parms.velocity.k = parms.pos.z;

            float mag = parms.velocity.magnitude();
            if (mag > 0)
            {
                parms.velocity /= mag;
            }
            else
            {
                parms.velocity.i = init_dir.i;
                parms.velocity.j = init_dir.j;
                parms.velocity.k = init_dir.k;
            }
        }

        //陳� Transform from local to world for position/velocity
        parms.pos.transform(&world);
        parms.velocity.transform(&world);

        //陳� Compute speed and set into velocity
        if (var_speed > 0)
            parms.velocity *= mean_speed + RANDOM()*var_speed;
        else
            parms.velocity *= mean_speed;

        //陳� Compute size
        if (var_size > 0)
        {
            parms.size = mean_size + RANDOM()*var_size;
            if (parms.size <= 0)
                parms.size = mean_size;
        }
        else
            parms.size = mean_size;

        //陳� Compute color
        if (pal)
        {
            float           t;
            VngoColor24bit  clr;

            if (var_color_r > 0)
                t = float(mean_color_r) + RANDOM()*float(var_color_r);
            else
                t = float(mean_color_r);

            if (t > 255)
                t = 255;
            else if (t < 0)
                t = 0;

            clr.r = byte(t);

            if (var_color_g > 0)
                t = float(mean_color_g) + RANDOM()*float(var_color_g);
            else
                t = float(mean_color_g);

            if (t > 255)
                t = 255;
            else if (t < 0)
                t = 0;

            clr.g = byte(t);

            if (var_color_b > 0)
                t = float(mean_color_b) + RANDOM()*float(var_color_b);
            else
                t = float(mean_color_b);

            if (t > 255)
                t = 255;
            else if (t < 0)
                t = 0;

            clr.b = byte(t);

            if (pal->flags & (VNGO_15BIT|VNGO_16BIT))
            {
                parms.color = clr.compress24() | VNGO_COLOR_24BIT;
            }
            else
            {
                parms.color = pal->get_index(clr);
            }
        }
        else
        {
            parms.color = cindex;
        }

        //陳� Compute lifetime
        if (var_life > 0)
        {
            parms.lifetime = mean_life + RANDOM()*var_life;
            if (parms.lifetime <= 0)
                parms.lifetime = mean_life;
        }
        else
            parms.lifetime = mean_life;

        //陳� Compute alpha
        if (var_alpha > 0)
        {
            float a = float(mean_alpha) + RANDOM()*float(var_alpha);
            if (a > 255)
                a = 255;
            else if (a < 0)
                a = 0;

            parms.alpha = byte(a);
        }
        else
            parms.alpha = mean_alpha;

        if (var_rot_rate > 0)
        {
            float rr = rot_rate + RANDOM()*float(var_rot_rate);
        }
        else if (rot_rate_high || rot_rate_low)
        {
            parms.rot_rate = rot_rate + (rot_rate_high - (RANDOM()*float(rot_rate_high-rot_rate_low)));
        }
        else
            parms.rot_rate = rot_rate;



        //陳� Create new particle with callback
        EschParticle *p = func(&parms);
        if (!p)
            break;

        //陳� Add to system
        add(p);
    }

    return count;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticleGenerator - set_callback                                     �
//                                                                          �
// This sets the callback function for the generator.                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschParticleGenerator::set_callback(EschParticleGenCallback f, void *d)
{
    if (!f)
        func = esch_generate_particle;
    else
        func = f;

    data=d;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭葦 Callback routines 碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_generate_particle
//
// Default callback routine which creates an instance of EschParticle
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschParticle *esch_generate_particle(EschParticleGenParams *parms)
{
    assert(parms != 0 && parms->generator != 0);

    EschParticle *p = new EschParticle(&parms->pos, &parms->velocity,
                                       parms->color, parms->lifetime);
    if (!p)
        return 0;

    if (!(parms->generator->flags & ESCH_PRTG_FRAMEBASED))
        p->set_flags(p->flags | ESCH_PRT_TIMEBASED);

    return p;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_generate_pyramid
//
// Callback routine which creates an instance of EschParticlePyramid
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschParticle *esch_generate_pyramid(EschParticleGenParams *parms)
{
    assert(parms != 0 && parms->generator != 0);

    EschParticlePyramid *p = new EschParticlePyramid(parms->size,
                                                     &parms->pos,
                                                     &parms->velocity,
                                                     parms->color,
                                                     parms->lifetime);
    if (!p)
        return 0;

    if (!(parms->generator->flags & ESCH_PRTG_FRAMEBASED))
        p->set_flags(p->flags | ESCH_PRT_TIMEBASED);

    return p;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_generate_sprite
//
// Callback routine which creates an instance of EschParticleSprite and
// an associated EschSprite instance.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschParticle *esch_generate_sprite(EschParticleGenParams *parms)
{
    assert(parms != 0 && parms->generator != 0 && parms->data != 0);

    EschSprite *sprite = new EschSprite(*((EschSprite*)parms->data));
    if (!sprite)
        return 0;

    sprite->set_position(&parms->pos);
    sprite->set_alpha(parms->alpha);
    sprite->set_flags(sprite->flags & ~ESCH_DRW_SKIP);

    EschParticleSprite *p = new EschParticleSprite(sprite,
                                                   &parms->velocity,
                                                   parms->lifetime);
    if (!p)
    {
        delete sprite;
        return 0;
    }

    if (!(parms->generator->flags & ESCH_PRTG_FRAMEBASED))
        p->set_flags(p->flags | ESCH_PRT_TIMEBASED);

    p->set_rot_rate(parms->rot_rate);

    return p;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_generate_line
//
// Callback routine which creates an instance of EschParticleLine
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschParticle *esch_generate_line(EschParticleGenParams *parms)
{
    assert(parms != 0 && parms->generator != 0);

    EschParticleLine *p = new EschParticleLine(&parms->pos, &parms->velocity,
                                               parms->color, parms->lifetime);
    if (!p)
        return 0;

    if (!(parms->generator->flags & ESCH_PRTG_FRAMEBASED))
        p->set_flags(p->flags | ESCH_PRT_TIMEBASED);

    return p;
}


//葦� End of module - esprtgen.cpp 憶�

