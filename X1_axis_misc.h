#ifndef X1_AXIS_MISC_H
#define X1_AXIS_MISC_H

#include "X_cylinder.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X1_axis_misc
{
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
private:
    _X_cylinder Cylinder;
};

#endif // X1_AXIS_MISC_H
