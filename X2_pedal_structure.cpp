#include "X2_pedal_structure.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_pedal_structure::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    //Arandela (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Arandela.draw_mode(mode);
    glPopMatrix();

    //Axis_misc (2)
    glPushMatrix();

    glTranslatef(0,-1.75,0);

    Axis_misc.draw_mode(mode);
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.5,0);
    glRotatef(90,0,0,1);

    Arandela.draw_mode(mode);
    glPopMatrix();

    //Axis_misc (4)
    glPushMatrix();

    glTranslatef(0.5,-3.5,0);
    glRotatef(90,0,0,1);

    Axis_misc.draw_mode(mode);
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_pedal_structure::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    //Arandela (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Arandela.draw_point();
    glPopMatrix();

    //Axis_misc (2)
    glPushMatrix();

    glTranslatef(0,-1.75,0);

    Axis_misc.draw_point();
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.5,0);
    glRotatef(90,0,0,1);

    Arandela.draw_point();
    glPopMatrix();

    //Axis_misc (4)
    glPushMatrix();

    glTranslatef(0.5,-3.5,0);
    glRotatef(90,0,0,1);

    Axis_misc.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_pedal_structure::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Arandela (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Arandela.draw_line();
    glPopMatrix();

    //Axis_misc (2)
    glPushMatrix();

    glTranslatef(0,-1.75,0);

    Axis_misc.draw_line();
    glPopMatrix();

    //Arandela (3)
    glPushMatrix();

    glTranslatef(0,-3.5,0);
    glRotatef(90,0,0,1);

    Arandela.draw_line();
    glPopMatrix();

    //Axis_misc (4)
    glPushMatrix();

    glTranslatef(0.5,-3.5,0);
    glRotatef(90,0,0,1);

    Axis_misc.draw_line();
    glPopMatrix();
}
