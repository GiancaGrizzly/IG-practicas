#ifndef X1_PEDAL_H
#define X1_PEDAL_H

#include "X_cube.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X1_pedal
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X_cube Cube;
};

#endif // X1_PEDAL_H
