#ifndef X2_BODY_STRUCTURE_H
#define X2_BODY_STRUCTURE_H

#include "X1_axis_body.h"
#include "X1_body_join.h"
#include "X_arandela.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X2_body_structure
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X1_axis_body Axis_body;
    _X1_body_join Body_join;
    _X_arandela Arandela;
};

#endif // X2_BODY_STRUCTURE_H
