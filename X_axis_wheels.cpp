#include "X_axis_wheels.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_axis_wheels::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Eje
    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(0.2,3,0.2);

    Cylinder.draw_line();
    glPopMatrix();

    //Rueda izq
    glPushMatrix();

    glTranslatef(-1.5,0,0);

    Wheel.draw_line();
    glPopMatrix();

    //Rueda dcha
    glPushMatrix();

    glTranslatef(1.5,0,0);

    Wheel.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_axis_wheels::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Eje
    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(0.2,3,0.2);

    Cylinder.draw_fill();
    glPopMatrix();

    //Rueda izq
    glPushMatrix();

    glTranslatef(-1.5,0,0);

    Wheel.draw_fill();
    glPopMatrix();

    //Rueda dcha
    glPushMatrix();

    glTranslatef(1.5,0,0);

    Wheel.draw_fill();
    glPopMatrix();
}


