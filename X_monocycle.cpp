#include "X_monocycle.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_monocycle::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    // Rueda (1)
    glPushMatrix();

    glTranslatef(0,4.5,0);
    glRotatef(alfa,1,0,0);
    glScalef(2,9,9);

    Wheel.draw_line();
    glPopMatrix();

    //Pedals_axis (2)
    glPushMatrix();

    glTranslatef(0,4.5,0);
    glRotatef(alfa,1,0,0);

    Pedals_axis.draw_line();
    glPopMatrix();

    //Body (3)
    glPushMatrix();

    glTranslatef(0,3.75,0);

    Body.draw_line();
    glPopMatrix();

    //Asiento_eje (4)
    glPushMatrix();

    glTranslatef(0,Asiento.alfa/100,0);
    glTranslatef(0,15.25,0);
    glRotatef(beta,0,1,0);

    Asiento.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_monocycle::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    // Rueda (1)
    glPushMatrix();

    glTranslatef(0,4.5,0);
    glRotatef(alfa,1,0,0);
    glScalef(2,9,9);

    Wheel.draw_line();
    glPopMatrix();

    //Pedals_axis (2)
    glPushMatrix();

    glTranslatef(0,4.5,0);
    glRotatef(alfa,1,0,0);

    Pedals_axis.draw_fill();
    glPopMatrix();

    //Body (3)
    glPushMatrix();

    glTranslatef(0,3.75,0);

    Body.draw_fill();
    glPopMatrix();

    //Asiento_eje (4)
    glPushMatrix();

    glTranslatef(0,Asiento.alfa/100,0);
    glTranslatef(0,15.25,0);
    glRotatef(beta,0,1,0);

    Asiento.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_monocycle::Initialize_asiento(float a, bool grow)
{
    Asiento.alfa = a;
    Asiento.grow = grow;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

float _X_monocycle::Get_asiento_alfa()
{
    return Asiento.alfa;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_monocycle::Set_asiento_alfa(float step)
{
    Asiento.alfa += step;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

bool _X_monocycle::Get_asiento_grow()
{
    return Asiento.grow;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_monocycle::Set_asiento_grow(bool grow)
{
    Asiento.grow = grow;
}
