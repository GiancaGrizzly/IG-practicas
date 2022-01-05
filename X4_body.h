#ifndef X4_BODY_H
#define X4_BODY_H

#include "X3_body_structure.h"
#include "X_arandela.h"

class _X4_body
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X3_body_structure Body_structure_2;
    _X_arandela Arandela;
};

#endif // X4_BODY_H
