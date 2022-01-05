#include "X3_pedal_structure.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_pedal_structure::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Pedal_structure (1)
    Pedal_structure.draw_mode(mode);

    //Arandela (2)
    glPushMatrix();

    glTranslatef(0,-3.5,0);
    glRotatef(90,0,0,1);

    Arandela.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_pedal_structure::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedal_structure (1)
    Pedal_structure.draw_point();

    //Arandela (2)
    glPushMatrix();

    glTranslatef(0,-3.5,0);
    glRotatef(90,0,0,1);

    Arandela.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_pedal_structure::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedal_structure (1)
    Pedal_structure.draw_line();

    //Arandela (2)
    glPushMatrix();

    glTranslatef(0,-3.5,0);
    glRotatef(90,0,0,1);

    Arandela.draw_line();
    glPopMatrix();
}
