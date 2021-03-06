#include "X8_monocycle.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X8_monocycle::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Monocycle_pedals (1)
    glPushMatrix();

    glTranslatef(0,4.5,0);
    glRotatef(angle_pedals_wheel,1,0,0);

    Monocycle_pedals.draw_mode(mode);
    glPopMatrix();

    //Monocycle_asiento_body (2)
    glPushMatrix();

    glTranslatef(0,7.75,0);

    Monocycle_asiento_body.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X8_monocycle::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Monocycle_pedals (1)
    glPushMatrix();

    glTranslatef(0,4.5,0);
    glRotatef(angle_pedals_wheel,1,0,0);

    Monocycle_pedals.draw_point();
    glPopMatrix();

    //Monocycle_asiento_body (2)
    glPushMatrix();

    glTranslatef(0,7.75,0);

    Monocycle_asiento_body.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X8_monocycle::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Monocycle_pedals (1)
    glPushMatrix();

    glTranslatef(0,4.5,0);
    glRotatef(angle_pedals_wheel,1,0,0);

    Monocycle_pedals.draw_line();
    glPopMatrix();

    //Monocycle_asiento_body (2)
    glPushMatrix();

    glTranslatef(0,7.75,0);

    Monocycle_asiento_body.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X8_monocycle::Initialize_asiento_axis()
{
    Monocycle_asiento_body.angle_asiento_axis = 0;
    Monocycle_asiento_body.Initialize_asiento_axis();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X8_monocycle::set_angle_asiento_axis(float step)
{
    Monocycle_asiento_body.angle_asiento_axis += step;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X8_monocycle::set_scale_asiento_axis(float step)
{
    Monocycle_asiento_body.set_scale_asiento_axis(step);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

float _X8_monocycle::get_scale_asiento_axis()
{
    return Monocycle_asiento_body.get_scale_asiento_axis();
}

