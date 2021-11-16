#include "X_asiento.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_asiento::draw_line()
{
    glMatrixMode(GL_MODELVIEW);

    // Cojin horizontal lateral (1)
    glPushMatrix();

    glTranslatef(2,0,-1);
    glRotatef(90,1,0,0);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin horizontal lateral (2)
    glPushMatrix();

    glTranslatef(-2,0,-1);
    glRotatef(90,1,0,0);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin horizontal central (1)
    glPushMatrix();

    glTranslatef(0,0,-2);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin horizontal central (2)
    glPushMatrix();

    glTranslatef(0,0,-1);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin horizontal central (3)
    glPushMatrix();

    glTranslatef(0,0,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin vertical lateral (1)
    glPushMatrix();

    glTranslatef(2,1,1);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin vertical lateral (2)
    glPushMatrix();

    glTranslatef(-2,1,1);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin vertical horizontal (1)
    glPushMatrix();

    glTranslatef(0,1,1);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_line();
    glPopMatrix();

    // Cojin vertical horizontal (2)
    glPushMatrix();

    glTranslatef(0,2,1);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_line();
    glPopMatrix();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_asiento::draw_fill()
{
    glMatrixMode(GL_MODELVIEW);

    // Cojin horizontal lateral (1)
    glPushMatrix();

    glTranslatef(2,0,-1);
    glRotatef(90,1,0,0);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin horizontal lateral (2)
    glPushMatrix();

    glTranslatef(-2,0,-1);
    glRotatef(90,1,0,0);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin horizontal central (1)
    glPushMatrix();

    glTranslatef(0,0,-2);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin horizontal central (2)
    glPushMatrix();

    glTranslatef(0,0,-1);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin horizontal central (3)
    glPushMatrix();

    glTranslatef(0,0,0);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin vertical lateral (1)
    glPushMatrix();

    glTranslatef(2,1,1);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin vertical lateral (2)
    glPushMatrix();

    glTranslatef(-2,1,1);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin vertical horizontal (1)
    glPushMatrix();

    glTranslatef(0,1,1);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_fill();
    glPopMatrix();

    // Cojin vertical horizontal (2)
    glPushMatrix();

    glTranslatef(0,2,1);
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);

    Cojin.draw_fill();
    glPopMatrix();
}


