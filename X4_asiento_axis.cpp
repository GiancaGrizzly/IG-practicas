#include "X4_asiento_axis.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_asiento_axis::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_misc (1)
    glPushMatrix();

    glScalef(1,1+alfa_scale_axis/100,1);

    Axis_misc.draw_mode(mode);
    glPopMatrix();

    //Asiento (2)
    glPushMatrix();

    glTranslatef(0,alfa_scale_axis/100,0);
    glTranslatef(0,1.5,1);

    Asiento.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_asiento_axis::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_misc (1)
    glPushMatrix();

    glScalef(1,1+alfa_scale_axis/100,1);

    Axis_misc.draw_point();
    glPopMatrix();

    //Asiento (2)
    glPushMatrix();

    glTranslatef(0,alfa_scale_axis/100,0);
    glTranslatef(0,1.5,1);

    Asiento.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_asiento_axis::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_misc (1)
    glPushMatrix();

    glScalef(1,1+alfa_scale_axis/100,1);

    Axis_misc.draw_line();
    glPopMatrix();

    //Asiento (2)
    glPushMatrix();

    glTranslatef(0,alfa_scale_axis/100,0);
    glTranslatef(0,1.5,1);

    Asiento.draw_line();
    glPopMatrix();
}
