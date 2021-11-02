#include "X_axis_misc.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_axis_misc::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,2,1);

    Cylinder.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_axis_misc::draw_fill()
{
    glColor3fv((GLfloat *) &YEllOW);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,2,1);

    Cylinder.draw_fill();
    glPopMatrix();
}

