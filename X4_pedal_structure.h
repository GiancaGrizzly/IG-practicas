#ifndef _X4_PEDAL_STRUCTURE_H
#define _X4_PEDAL_STRUCTURE_H

#include "X3_pedal_structure.h"
#include "X1_axis_misc.h"

class _X4_pedal_structure
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X3_pedal_structure Pedal_structure;
    _X1_axis_misc Axis_misc;
};

#endif // _X4_PEDAL_STRUCTURE_H
