#include "X1_pedal.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_pedal::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,2);

    Cube.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_pedal::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,2);

    Cube.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_pedal::draw_line()
{
    glColor3fv((GLfloat *) &RED);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,2);

    Cube.draw_line();
    glPopMatrix();
}
