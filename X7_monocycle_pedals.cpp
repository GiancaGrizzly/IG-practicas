#include "X7_monocycle_pedals.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X7_monocycle_pedals::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis_wheel (1)
    Pedals_axis_wheel.draw_mode(mode);

    //Pedal (2)
    glPushMatrix();

    glTranslatef(7,-3.5,0);

    Pedal.draw_mode(mode);
    glPopMatrix();

    //Pedal (3)
    glPushMatrix();

    glTranslatef(-7,3.5,0);

    Pedal.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X7_monocycle_pedals::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis_wheel (1)
    Pedals_axis_wheel.draw_point();

    //Pedal (2)
    glPushMatrix();

    glTranslatef(7,-3.5,0);

    Pedal.draw_point();
    glPopMatrix();

    //Pedal (3)
    glPushMatrix();

    glTranslatef(-7,3.5,0);

    Pedal.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X7_monocycle_pedals::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis_wheel (1)
    Pedals_axis_wheel.draw_line();

    //Pedal (2)
    glPushMatrix();

    glTranslatef(7,-3.5,0);

    Pedal.draw_line();
    glPopMatrix();

    //Pedal (3)
    glPushMatrix();

    glTranslatef(-7,3.5,0);

    Pedal.draw_line();
    glPopMatrix();
}
