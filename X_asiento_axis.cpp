#include "X_asiento_axis.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_asiento_axis::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,1+alfa/100,1);

    Eje.draw_line();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0,alfa/100,0);
    glTranslatef(0,1.5,0);

    Asiento.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_asiento_axis::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,1+alfa/100,1);

    Eje.draw_fill();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0,alfa/100,0);
    glTranslatef(0,1.5,0);

    Asiento.draw_fill();
    glPopMatrix();
}
