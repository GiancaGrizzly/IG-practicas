#include "X1_wheel.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_wheel::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,0.3,1);

    Cylinder.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_wheel::draw_line()
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,0.3,1);

    Cylinder.draw_line();
    glPopMatrix();
}
