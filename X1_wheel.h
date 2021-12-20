#ifndef X1_WHEEL_H
#define X1_WHEEL_H

#include "X_cylinder.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X1_wheel
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X_cylinder Cylinder;
};

#endif // X1_WHEEL_H
