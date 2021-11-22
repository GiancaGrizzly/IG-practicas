#ifndef X1_COJIN_H
#define X1_COJIN_H

#include "X_cylinder.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X1_cojin
{
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
private:
    _X_cylinder Cylinder;
};

#endif // X1_COJIN_H
