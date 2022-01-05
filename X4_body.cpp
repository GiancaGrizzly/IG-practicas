#include "X4_body.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_body::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure (1)
    Body_structure_2.draw_mode(mode);

    //Arandela (2)
    glPushMatrix();

    glTranslatef(0,6.5,0);

    Arandela.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_body::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure (1)
    Body_structure_2.draw_point();

    //Arandela (2)
    glPushMatrix();

    glTranslatef(0,6.5,0);

    Arandela.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_body::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure (1)
    Body_structure_2.draw_line();

    //Arandela (2)
    glPushMatrix();

    glTranslatef(0,6.5,0);

    Arandela.draw_line();
    glPopMatrix();
}

