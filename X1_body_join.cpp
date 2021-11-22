#include "X1_body_join.h"

using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_body_join::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1.5,1,1);

    Cube.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_body_join::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1.5,1,1);

    Cube.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_body_join::draw_fill()
{
    glColor3fv((GLfloat *) &CYAN);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1.5,1,1);

    Cube.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X1_body_join::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glScalef(1.5,1,1);

    Cube.draw_chess();
    glPopMatrix();
}

