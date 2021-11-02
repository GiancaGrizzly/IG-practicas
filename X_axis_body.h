#ifndef X_AXIS_BODY_H
#define X_AXIS_BODY_H

#include "X_cylinder.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_axis_body
{
public:
    void draw_line();
    void draw_fill();
private:
    _X_cylinder Cylinder;
};

#endif // X_AXIS_BODY_H
