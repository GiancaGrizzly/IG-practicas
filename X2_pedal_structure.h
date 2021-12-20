#ifndef X2_PEDAL_STRUCTURE_H
#define X2_PEDAL_STRUCTURE_H

#include "X_arandela.h"
#include "X1_axis_misc.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X2_pedal_structure
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X_arandela Arandela;
    _X1_axis_misc Axis_misc;
};

#endif // X2_PEDAL_STRUCTURE_H
