#ifndef X5_PEDALS_AXIS_H
#define X5_PEDALS_AXIS_H

#include "X4_pedal_structure.h"
#include "X1_axis_misc.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X5_pedals_axis
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X4_pedal_structure Pedal_structure;
    _X1_axis_misc Axis_misc;
};

#endif // X5_PEDALS_AXIS_H
