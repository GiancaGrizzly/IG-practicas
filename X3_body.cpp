#include "X3_body.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_body::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure_1 (1)
    glPushMatrix();

    glTranslatef(-2.5,0,0);

    Body_structure_1.draw_mode(mode);
    glPopMatrix();

    //Body_structure_1 (2)
    glPushMatrix();

    glTranslatef(2.5,0,0);
    glRotatef(180,0,1,0);

    Body_structure_1.draw_mode(mode);
    glPopMatrix();

    //Body_structure_2 (3)
    glPushMatrix();

    glTranslatef(0,4,0);

    Body_structure_2.draw_mode(mode);
    glPopMatrix();
}

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
