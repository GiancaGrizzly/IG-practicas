
#include "X2_body_structure_2.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_body_structure_2::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_body (1)
    Axis_body.draw_mode(mode);

    //Arandela (2)
    glPushMatrix();

    glTranslatef(0,2.5,0);

    Arandela.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_body_structure_2::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_body (1)
    Axis_body.draw_point();

    //Arandela (2)
    glPushMatrix();

    glTranslatef(0,2.5,0);

    Arandela.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_body_structure_2::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_body (1)
    Axis_body.draw_line();

    //Arandela (2)
    glPushMatrix();

    glTranslatef(0,2.5,0);

    Arandela.draw_line();
    glPopMatrix();
}
