#include "X_prueba.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_prueba::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Eje (1)
    glPushMatrix();

    glRotatef(alfa,1,0,0);

    Pedals_axis.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_prueba::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Eje (1)
    glPushMatrix();

    glRotatef(alfa,1,0,0);

    Pedals_axis.draw_fill();
    glPopMatrix();
}


