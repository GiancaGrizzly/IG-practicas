
#include "X_body_2.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_body_2::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Eje body (1)
    Axis_body.draw_line();

    //Body join (2)
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

void _X_body_2::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Eje body (1)
    Axis_body.draw_fill();

    //Body join (2)
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


