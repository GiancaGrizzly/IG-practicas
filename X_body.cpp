
#include "X_body.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_body::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_2 (1)
    glPushMatrix();

    glTranslatef(-2.5,4,0);

    Body_2.draw_line();
    glPopMatrix();

    //Body_2 (2)
    glPushMatrix();

    glTranslatef(2.5,4,0);
    glRotatef(180,0,1,0);

    Body_2.draw_line();
    glPopMatrix();

    //Eje body (3)
    glPushMatrix();

    glTranslatef(0,8,0);

    Axis_body.draw_line();
    glPopMatrix();

    //Arandela (4)
    glPushMatrix();

    glTranslatef(0,10.5,0);

    Arandela.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_body::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    //Body_2 (1)
    glPushMatrix();

    glTranslatef(-2.5,4,0);

    Body_2.draw_fill();
    glPopMatrix();

    //Body_2 (2)
    glPushMatrix();

    glTranslatef(2.5,4,0);
    glRotatef(180,0,1,0);

    Body_2.draw_fill();
    glPopMatrix();

    //Eje body (3)
    glPushMatrix();

    glTranslatef(0,8,0);

    Axis_body.draw_fill();
    glPopMatrix();

    //Arandela (4)
    glPushMatrix();

    glTranslatef(0,10.5,0);

    Arandela.draw_fill();
    glPopMatrix();
}


