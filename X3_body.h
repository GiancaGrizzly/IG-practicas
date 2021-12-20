#ifndef X3_BODY_H
#define X3_BODY_H

#include "X2_body_structure_1.h"
#include "X2_body_structure_2.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X3_body
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X2_body_structure_1 Body_structure_1;
    _X2_body_structure_2 Body_structure_2;
};

#endif // X3_BODY_H
