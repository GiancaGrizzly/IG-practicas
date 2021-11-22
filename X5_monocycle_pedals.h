#ifndef X5_MONOCYCLE_PEDALS_H
#define X5_MONOCYCLE_PEDALS_H

#include "X4_pedals_axis_wheel.h"
#include "X1_pedal.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X5_monocycle_pedals
{
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
private:
    _X4_pedals_axis_wheel Pedals_axis_wheel;
    _X1_pedal Pedal;
};

#endif // X5_MONOCYCLE_PEDALS_H
