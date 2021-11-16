#ifndef X_AXIS_MISC_H
#define X_AXIS_MISC_H

#include "X_cylinder.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_axis_misc
{
public:
    void draw_line();
    void draw_fill();
    void draw_chess();
private:
    _X_cylinder Cylinder;
};

#endif // X_AXIS_MISC_H
