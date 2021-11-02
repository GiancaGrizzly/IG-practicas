#include "X_cojin.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_cojin::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,3,1);

    Cylinder.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_cojin::draw_fill()
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,3,1);

    Cylinder.draw_fill();
    glPopMatrix();
}


