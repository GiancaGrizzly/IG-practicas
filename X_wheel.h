#ifndef X_WHEEL_H
#define X_WHEEL_H

#include "X_cylinder.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_wheel
{
public:
    void draw_line();
    void draw_fill();
private:
    _X_cylinder Cylinder;
};

#endif // X_WHEEL_H
