#include "X4_pedals_axis_wheel.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedals_axis_wheel::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis (1)
    Pedals_axis.draw_point();

    //Wheel (2)
    glPushMatrix();

    glScalef(2,9,9);

    Wheel.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedals_axis_wheel::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis (1)
    Pedals_axis.draw_line();

    //Wheel (2)
    glPushMatrix();

    glScalef(2,9,9);

    Wheel.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedals_axis_wheel::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis (1)
    Pedals_axis.draw_fill();

    //Wheel (2)
    glPushMatrix();

    glScalef(2,9,9);

    Wheel.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X4_pedals_axis_wheel::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis (1)
    Pedals_axis.draw_chess();

    //Wheel (2)
    glPushMatrix();

    glScalef(2,9,9);

    Wheel.draw_chess();
    glPopMatrix();
}

