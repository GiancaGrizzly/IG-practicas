#include "X1_axis_body.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_body::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,5,1);

    Cylinder.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_body::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,5,1);

    Cylinder.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_body::draw_fill()
{
    glColor3fv((GLfloat *) &CYAN);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,5,1);

    Cylinder.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_axis_body::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1,5,1);

    Cylinder.draw_chess();
    glPopMatrix();
}

