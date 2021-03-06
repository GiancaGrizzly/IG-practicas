
#include "X2_body_structure.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_body_structure::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Axis_body (1)
    Axis_body.draw_mode(mode);

    //Body_join (2)
    glPushMatrix();

    glTranslatef(1.25,2,0);

    Body_join.draw_mode(mode);
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.25,0);
    glRotatef(90,0,0,1);

    Arandela.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_body_structure::draw_point()
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

void _X2_body_structure::draw_line()
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
