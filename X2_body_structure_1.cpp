
#include "X2_body_structure_1.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_body_structure_1::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_body (1)
    Axis_body.draw_point();

    //Body_join (2)
    glPushMatrix();

    glTranslatef(1.25,2,0);

    Body_join.draw_point();
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.25,0);
    glRotatef(90,0,0,1);

    Arandela.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_body_structure_1::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_body (1)
    Axis_body.draw_line();

    //Body_join (2)
    glPushMatrix();

    glTranslatef(1.25,2,0);

    Body_join.draw_line();
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.25,0);
    glRotatef(90,0,0,1);

    Arandela.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_body_structure_1::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_body (1)
    Axis_body.draw_fill();

    //Body_join (2)
    glPushMatrix();

    glTranslatef(1.25,2,0);

    Body_join.draw_fill();
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.25,0);
    glRotatef(90,0,0,1);

    Arandela.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_body_structure_1::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_body (1)
    Axis_body.draw_chess();

    //Body_join (2)
    glPushMatrix();

    glTranslatef(1.25,2,0);

    Body_join.draw_chess();
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.25,0);
    glRotatef(90,0,0,1);

    Arandela.draw_chess();
    glPopMatrix();
}

