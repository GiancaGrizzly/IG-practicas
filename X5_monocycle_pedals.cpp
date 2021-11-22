#include "X5_monocycle_pedals.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_pedals::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis_wheel (1)
    Pedals_axis_wheel.draw_point();

    //Pedal (2)
    glPushMatrix();

    glTranslatef(7,-3.5,0);

    Pedal.draw_point();
    glPopMatrix();

    //Pedal (3)
    glPushMatrix();

    glTranslatef(-7,3.5,0);

    Pedal.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_pedals::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis_wheel (1)
    Pedals_axis_wheel.draw_line();

    //Pedal (2)
    glPushMatrix();

    glTranslatef(7,-3.5,0);

    Pedal.draw_line();
    glPopMatrix();

    //Pedal (3)
    glPushMatrix();

    glTranslatef(-7,3.5,0);

    Pedal.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_pedals::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis_wheel (1)
    Pedals_axis_wheel.draw_fill();

    //Pedal (2)
    glPushMatrix();

    glTranslatef(7,-3.5,0);

    Pedal.draw_fill();
    glPopMatrix();

    //Pedal (3)
    glPushMatrix();

    glTranslatef(-7,3.5,0);

    Pedal.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_pedals::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    //Pedals_axis_wheel (1)
    Pedals_axis_wheel.draw_chess();

    //Pedal (2)
    glPushMatrix();

    glTranslatef(7,-3.5,0);

    Pedal.draw_chess();
    glPopMatrix();

    //Pedal (3)
    glPushMatrix();

    glTranslatef(-7,3.5,0);

    Pedal.draw_chess();
    glPopMatrix();
}
