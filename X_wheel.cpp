#include "X_wheel.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_wheel::draw_line()
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,0.3,1);

    Cylinder.draw_line();
    glPopMatrix();

    glColor3fv((GLfloat *) &MAGENTA);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_wheel::draw_fill()
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,0.3,1);

    Cylinder.draw_fill();
    glPopMatrix();
}


