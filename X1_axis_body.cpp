#include "X1_axis_body.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_body::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,5,1);

    Cylinder.draw_mode(mode);

    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_body::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,5,1);

    Cylinder.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_body::draw_line()
{
    glColor3fv((GLfloat *) &CYAN);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,5,1);

    Cylinder.draw_line();
    glPopMatrix();
}
