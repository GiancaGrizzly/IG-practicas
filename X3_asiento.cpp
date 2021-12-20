#include "X3_asiento.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_asiento::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Asiento_base (1)
    Asiento_base.draw_mode(mode);

    //Asiento_respaldo (2)
    glPushMatrix();

    glTranslatef(0,1,-2);

    Asiento_respaldo.draw_mode(mode);
    glPopMatrix();
}

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
