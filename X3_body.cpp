#include "X3_body.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_body::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure_1 (1)
    glPushMatrix();

    glTranslatef(-2.5,0,0);

    Body_structure_1.draw_point();
    glPopMatrix();

    //Body_structure_1 (2)
    glPushMatrix();

    glTranslatef(2.5,0,0);
    glRotatef(180,0,1,0);

    Body_structure_1.draw_point();
    glPopMatrix();

    //Body_structure_2 (3)
    glPushMatrix();

    glTranslatef(0,4,0);

    Body_structure_2.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_body::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure_1 (1)
    glPushMatrix();

    glTranslatef(-2.5,0,0);

    Body_structure_1.draw_line();
    glPopMatrix();

    //Body_structure_1 (2)
    glPushMatrix();

    glTranslatef(2.5,0,0);
    glRotatef(180,0,1,0);

    Body_structure_1.draw_line();
    glPopMatrix();

    //Body_structure_2 (3)
    glPushMatrix();

    glTranslatef(0,4,0);

    Body_structure_2.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_body::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure_1 (1)
    glPushMatrix();

    glTranslatef(-2.5,0,0);

    Body_structure_1.draw_fill();
    glPopMatrix();

    //Body_structure_1 (2)
    glPushMatrix();

    glTranslatef(2.5,0,0);
    glRotatef(180,0,1,0);

    Body_structure_1.draw_fill();
    glPopMatrix();

    //Body_structure_2 (3)
    glPushMatrix();

    glTranslatef(0,4,0);

    Body_structure_2.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_body::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure_1 (1)
    glPushMatrix();

    glTranslatef(-2.5,0,0);

    Body_structure_1.draw_chess();
    glPopMatrix();

    //Body_structure_1 (2)
    glPushMatrix();

    glTranslatef(2.5,0,0);
    glRotatef(180,0,1,0);

    Body_structure_1.draw_chess();
    glPopMatrix();

    //Body_structure_2 (3)
    glPushMatrix();

    glTranslatef(0,4,0);

    Body_structure_2.draw_chess();
    glPopMatrix();
}

