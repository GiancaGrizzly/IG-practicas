#ifndef X_AXIS_WHEELS_H
#define X_AXIS_WHEELS_H

#include "X_cylinder.h"
#include "X_wheel.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_axis_wheels
{
public:
    void draw_line();
    void draw_fill();
private:
    _X_cylinder Cylinder;
    _X_wheel Wheel;
};

#endif // X_AXIS_WHEELS_H
