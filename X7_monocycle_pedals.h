#ifndef X7_MONOCYCLE_PEDALS_H
#define X7_MONOCYCLE_PEDALS_H

#include "X6_pedals_axis_wheel.h"
#include "X1_pedal.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X7_monocycle_pedals
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X6_pedals_axis_wheel Pedals_axis_wheel;
    _X1_pedal Pedal;
};

#endif // X7_MONOCYCLE_PEDALS_H
