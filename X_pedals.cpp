#include "X_pedals.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_pedals::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Arandela (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Arandela.draw_line();
    glPopMatrix();

    //Eje (2)
    glPushMatrix();

    glTranslatef(0,-1.75,0);

    Axis_misc.draw_line();
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.5,0);
    glRotatef(90,0,0,1);

    Arandela.draw_line();
    glPopMatrix();

    //Eje (4)
    glPushMatrix();

    glTranslatef(0.5,-3.5,0);
    glRotatef(90,0,0,1);

    Axis_misc.draw_line();
    glPopMatrix();

    //Pedal (5)
    glPushMatrix();

    glTranslatef(3,-3.5,0);

    Pedal.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_pedals::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Arandela (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Arandela.draw_fill();
    glPopMatrix();

    //Eje (2)
    glPushMatrix();

    glTranslatef(0,-1.75,0);

    Axis_misc.draw_fill();
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.5,0);
    glRotatef(90,0,0,1);

    Arandela.draw_fill();
    glPopMatrix();

    //Eje (4)
    glPushMatrix();

    glTranslatef(0.5,-3.5,0);
    glRotatef(90,0,0,1);

    Axis_misc.draw_fill();
    glPopMatrix();

    //Pedal (5)
    glPushMatrix();

    glTranslatef(3,-3.5,0);

    Pedal.draw_fill();
    glPopMatrix();
}

