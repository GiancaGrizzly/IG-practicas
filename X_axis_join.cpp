#include "X_axis_join.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_axis_join::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,1);

    Cube.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_axis_join::draw_fill()
{
    glColor3fv((GLfloat *) &CYAN);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,1);

    Cube.draw_fill();
    glPopMatrix();
}


