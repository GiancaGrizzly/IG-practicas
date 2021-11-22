#include "X1_pedal.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_pedal::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,2);

    Cube.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_pedal::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,2);

    Cube.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_pedal::draw_fill()
{
    glColor3fv((GLfloat *) &RED);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,2);

    Cube.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_pedal::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(3,1,2);

    Cube.draw_chess();
    glPopMatrix();
}

