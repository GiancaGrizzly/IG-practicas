#include "X_wheel.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_wheel::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,0.3,1);

    Cylinder.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_wheel::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,0.3,1);

    Cylinder.draw_fill();
    glPopMatrix();
}


