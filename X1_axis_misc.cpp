#include "X1_axis_misc.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_misc::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,2,1);

    Cylinder.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_misc::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,2,1);

    Cylinder.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_misc::draw_line()
{
    glColor3fv((GLfloat *) &YEllOW);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,2,1);

    Cylinder.draw_line();
    glPopMatrix();
}
