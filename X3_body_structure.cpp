#include "X3_body_structure.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_body_structure::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure (1)
    glPushMatrix();

    glTranslatef(-2.5,0,0);

    Body_structure.draw_mode(mode);
    glPopMatrix();

    //Axis_body (2)
    glPushMatrix();

    glTranslatef(0,4,0);

    Axis_body.draw_mode(mode);
    glPopMatrix();

    //Body_structure (3)
    glPushMatrix();

    glTranslatef(2.5,0,0);
    glRotatef(180,0,1,0);

    Body_structure.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_body_structure::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure (1)
    glPushMatrix();

    glTranslatef(-2.5,0,0);

    Body_structure.draw_point();
    glPopMatrix();

    //Axis_body (2)
    glPushMatrix();

    glTranslatef(0,4,0);

    Axis_body.draw_point();
    glPopMatrix();

    //Body_structure (3)
    glPushMatrix();

    glTranslatef(2.5,0,0);
    glRotatef(180,0,1,0);

    Body_structure.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X3_body_structure::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_structure (1)
    glPushMatrix();

    glTranslatef(-2.5,0,0);

    Body_structure.draw_line();
    glPopMatrix();

    //Axis_body (2)
    glPushMatrix();

    glTranslatef(0,4,0);

    Axis_body.draw_line();
    glPopMatrix();

    //Body_structure (3)
    glPushMatrix();

    glTranslatef(2.5,0,0);
    glRotatef(180,0,1,0);

    Body_structure.draw_line();
    glPopMatrix();
}

