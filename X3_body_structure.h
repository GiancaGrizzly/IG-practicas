#ifndef X3_BODY_STRUCTURE_H
#define X3_BODY_STRUCTURE_H

#include "X2_body_structure.h"
#include "X1_axis_body.h"

class _X3_body_structure
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X2_body_structure Body_structure;
    _X1_axis_body Axis_body;
};

#endif // X3_BODY_STRUCTURE_H
