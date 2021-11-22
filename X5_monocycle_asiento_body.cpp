#include "X5_monocycle_asiento_body.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_asiento_body::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Body (1)
    Body.draw_point();

    //Asiento_axis (2)
    glPushMatrix();

    glTranslatef(0,7.5,0);
    glTranslatef(0,Asiento_axis.alfa_scale_axis/100,0);
    glRotatef(angle_asiento_axis,0,1,0);

    Asiento_axis.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_asiento_body::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Body (1)
    Body.draw_line();

    //Asiento_axis (2)
    glPushMatrix();

    glTranslatef(0,7.5,0);
    glTranslatef(0,Asiento_axis.alfa_scale_axis/100,0);
    glRotatef(angle_asiento_axis,0,1,0);

    Asiento_axis.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_asiento_body::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Body (1)
    Body.draw_fill();

    //Asiento_axis (2)
    glPushMatrix();

    glTranslatef(0,7.5,0);
    glTranslatef(0,Asiento_axis.alfa_scale_axis/100,0);
    glRotatef(angle_asiento_axis,0,1,0);

    Asiento_axis.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_asiento_body::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    //Body (1)
    Body.draw_chess();

    //Asiento_axis (2)
    glPushMatrix();

    glTranslatef(0,7.5,0);
    glTranslatef(0,Asiento_axis.alfa_scale_axis/100,0);
    glRotatef(angle_asiento_axis,0,1,0);

    Asiento_axis.draw_chess();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_asiento_body::Initialize_asiento_axis()
{
    Asiento_axis.alfa_scale_axis = 0;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X5_monocycle_asiento_body::set_scale_asiento_axis(float step)
{
    Asiento_axis.alfa_scale_axis += step;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

float _X5_monocycle_asiento_body::get_scale_asiento_axis()
{
    return Asiento_axis.alfa_scale_axis;
}

