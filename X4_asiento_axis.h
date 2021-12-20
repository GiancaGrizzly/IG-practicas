#ifndef X4_ASIENTO_AXIS_H
#define X4_ASIENTO_AXIS_H

#include "X1_axis_misc.h"
#include "X3_asiento.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X4_asiento_axis
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);

    float alfa_scale_axis;
private:
    _X3_asiento Asiento;
    _X1_axis_misc Axis_misc;
};

#endif // X4_ASIENTO_AXIS_H
