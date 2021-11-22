#include "X3_asiento.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_asiento::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Asiento_base (1)
    Asiento_base.draw_point();

    //Asiento_respaldo (2)
    glPushMatrix();

    glTranslatef(0,1,-2);

    Asiento_respaldo.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_asiento::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Asiento_base (1)
    Asiento_base.draw_line();

    //Asiento_respaldo (2)
    glPushMatrix();

    glTranslatef(0,1,-2);

    Asiento_respaldo.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_asiento::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Asiento_base (1)
    Asiento_base.draw_fill();

    //Asiento_respaldo (2)
    glPushMatrix();

    glTranslatef(0,1,-2);

    Asiento_respaldo.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_asiento::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    //Asiento_base (1)
    Asiento_base.draw_chess();

    //Asiento_respaldo (2)
    glPushMatrix();

    glTranslatef(0,1,-2);

    Asiento_respaldo.draw_chess();
    glPopMatrix();
}

