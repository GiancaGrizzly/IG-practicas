#include "X_pedal.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_pedal::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,2);

    Cube.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_pedal::draw_fill()
{
    glColor3fv((GLfloat *) &RED);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,2);

    Cube.draw_fill();
    glPopMatrix();
}


