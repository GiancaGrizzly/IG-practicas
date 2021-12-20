#ifndef X4_PEDALS_AXIS_WHEEL_H
#define X4_PEDALS_AXIS_WHEEL_H

#include "X3_pedals_axis.h"
#include "X1_wheel.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X4_pedals_axis_wheel
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X3_pedals_axis Pedals_axis;
    _X1_wheel Wheel;
};

#endif // X4_PEDALS_AXIS_WHEEL_H
