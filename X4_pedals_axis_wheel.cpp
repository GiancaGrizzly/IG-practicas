#include "X4_pedals_axis_wheel.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedals_axis_wheel::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis (1)
    Pedals_axis.draw_mode(mode);

    //Wheel (2)
    glPushMatrix();

    glScalef(2,9,9);

    Wheel.draw_line();
    glPopMatrix();

    glColor3fv((GLfloat *) &BLUE);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedals_axis_wheel::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis (1)
    Pedals_axis.draw_point();

    //Wheel (2)
    glPushMatrix();

    glScalef(2,9,9);

    Wheel.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedals_axis_wheel::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis (1)
    Pedals_axis.draw_line();

    //Wheel (2)
    glPushMatrix();

    glScalef(2,9,9);

    Wheel.draw_line();
    glPopMatrix();
}
