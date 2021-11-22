#include "X2_asiento_respaldo.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_asiento_respaldo::draw_point()
{
    glMatrixMode(GL_MODELVIEW);

    // Cojin (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Cojin.draw_point();
    glPopMatrix();

    // Cojin (2)
    glPushMatrix();

    glTranslatef(0,1,0);
    glRotatef(90,0,0,1);

    Cojin.draw_point();
    glPopMatrix();

    // Cojin (3)
    glPushMatrix();

    glTranslatef(-2,0,0);

    Cojin.draw_point();
    glPopMatrix();

    // Cojin (4)
    glPushMatrix();

    glTranslatef(2,0,0);

    Cojin.draw_point();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_asiento_respaldo::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    // Cojin (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin (2)
    glPushMatrix();

    glTranslatef(0,1,0);
    glRotatef(90,0,0,1);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin (3)
    glPushMatrix();

    glTranslatef(-2,0,0);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin (4)
    glPushMatrix();

    glTranslatef(2,0,0);

    Cojin.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_asiento_respaldo::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    // Cojin (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin (2)
    glPushMatrix();

    glTranslatef(0,1,0);
    glRotatef(90,0,0,1);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin (3)
    glPushMatrix();

    glTranslatef(-2,0,0);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin (4)
    glPushMatrix();

    glTranslatef(2,0,0);

    Cojin.draw_fill();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_asiento_respaldo::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);

    // Cojin (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Cojin.draw_chess();
    glPopMatrix();

    // Cojin (2)
    glPushMatrix();

    glTranslatef(0,1,0);
    glRotatef(90,0,0,1);

    Cojin.draw_chess();
    glPopMatrix();

    // Cojin (3)
    glPushMatrix();

    glTranslatef(-2,0,0);

    Cojin.draw_chess();
    glPopMatrix();

    // Cojin (4)
    glPushMatrix();

    glTranslatef(2,0,0);

    Cojin.draw_chess();
    glPopMatrix();
}

