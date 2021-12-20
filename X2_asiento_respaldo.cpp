#include "X2_asiento_respaldo.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X2_asiento_respaldo::draw_mode(_object3D_ne::_mode_fill mode)
{
    glMatrixMode(GL_MODELVIEW);

    // Cojin (1)
    glPushMatrix();

    glRotatef(90,0,0,1);

    Cojin.draw_mode(mode);
    glPopMatrix();

    // Cojin (2)
    glPushMatrix();

    glTranslatef(0,1,0);
    glRotatef(90,0,0,1);

    Cojin.draw_mode(mode);
    glPopMatrix();

    // Cojin (3)
    glPushMatrix();

    glTranslatef(-2,0,0);

    Cojin.draw_mode(mode);
    glPopMatrix();

    // Cojin (4)
    glPushMatrix();

    glTranslatef(2,0,0);

    Cojin.draw_mode(mode);
    glPopMatrix();
}

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
