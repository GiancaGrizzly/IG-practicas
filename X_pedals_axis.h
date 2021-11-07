#ifndef X_PEDALS_AXIS_H
#define X_PEDALS_AXIS_H

#include "X_pedals.h"
#include "X_axis_misc.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_pedals_axis
{
public:
    void draw_line();
    void draw_fill();

    float alfa = 0;
private:
    _X_pedals Pedals;
    _X_axis_misc Axis_misc;
};

#endif // X_PEDALS_AXIS_H
