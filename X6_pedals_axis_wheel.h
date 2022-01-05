#ifndef X6_PEDALS_AXIS_WHEEL_H
#define X6_PEDALS_AXIS_WHEEL_H

#include "X5_pedals_axis.h"
#include "X1_wheel.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X6_pedals_axis_wheel
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X5_pedals_axis Pedals_axis;
    _X1_wheel Wheel;
};

#endif // X6_PEDALS_AXIS_WHEEL_H
