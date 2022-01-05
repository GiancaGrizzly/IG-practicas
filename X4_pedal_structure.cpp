#include "X4_pedal_structure.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedal_structure::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Pedal_structure (1)
    Pedal_structure.draw_mode(mode);

    //Axis_misc (2)
    glPushMatrix();

    glTranslatef(0.5,-3.5,0);
    glRotatef(90,0,0,1);

    Axis_misc.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedal_structure::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedal_structure (1)
    Pedal_structure.draw_point();

    //Axis_misc (2)
    glPushMatrix();

    glTranslatef(0.5,-3.5,0);
    glRotatef(90,0,0,1);

    Axis_misc.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedal_structure::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedal_structure (1)
    Pedal_structure.draw_line();

    //Axis_misc (2)
    glPushMatrix();

    glTranslatef(0.5,-3.5,0);
    glRotatef(90,0,0,1);

    Axis_misc.draw_line();
    glPopMatrix();
}

