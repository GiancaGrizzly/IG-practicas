#include "X3_pedals_axis.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_pedals_axis::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_misc (1)
    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,5,1);

    Axis_misc.draw_mode(mode);
    glPopMatrix();

    //Pedal_structure (2)
    glPushMatrix();

    glTranslatef(4,0,0);

    Pedal_structure.draw_mode(mode);
    glPopMatrix();

    //Pedale_structure (3)
    glPushMatrix();

    glTranslatef(-4,0,0);
    glRotatef(180,0,1,0);
    glRotatef(180,1,0,0);

    Pedal_structure.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_pedals_axis::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_misc (1)
    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,5,1);

    Axis_misc.draw_point();
    glPopMatrix();

    //Pedal_structure (2)
    glPushMatrix();

    glTranslatef(4,0,0);

    Pedal_structure.draw_point();
    glPopMatrix();

    //Pedale_structure (3)
    glPushMatrix();

    glTranslatef(-4,0,0);
    glRotatef(180,0,1,0);
    glRotatef(180,1,0,0);

    Pedal_structure.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_pedals_axis::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_misc (1)
    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,5,1);

    Axis_misc.draw_line();
    glPopMatrix();

    //Pedal_structure (2)
    glPushMatrix();

    glTranslatef(4,0,0);

    Pedal_structure.draw_line();
    glPopMatrix();

    //Pedale_structure (3)
    glPushMatrix();

    glTranslatef(-4,0,0);
    glRotatef(180,0,1,0);
    glRotatef(180,1,0,0);

    Pedal_structure.draw_line();
    glPopMatrix();
}
