#include "X_pedals_axis.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_pedals_axis::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Eje (1)
    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,5,1);

    Axis_misc.draw_line();
    glPopMatrix();

    //Pedales (2)
    glPushMatrix();

    glTranslatef(4,0,0);

    Pedals.draw_line();
    glPopMatrix();

    //Pedales (3)
    glPushMatrix();

    glTranslatef(-4,0,0);
    glRotatef(180,0,1,0);
    glRotatef(180,1,0,0);

    Pedals.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_pedals_axis::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Eje (1)
    glPushMatrix();

    glRotatef(90,0,0,1);
    glScalef(1,5,1);

    Axis_misc.draw_fill();
    glPopMatrix();

    //Pedales (2)
    glPushMatrix();

    glTranslatef(4,0,0);

    Pedals.draw_fill();
    glPopMatrix();

    //Pedales (3)
    glPushMatrix();

    glTranslatef(-4,0,0);
    glRotatef(180,0,1,0);
    glRotatef(180,1,0,0);

    Pedals.draw_fill();
    glPopMatrix();
}


