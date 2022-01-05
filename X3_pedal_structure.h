#ifndef X3_PEDAL_STRUCTURE_H
#define X3_PEDAL_STRUCTURE_H

#include "X2_pedal_structure.h"
#include "X_arandela.h"

class _X3_pedal_structure
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X2_pedal_structure Pedal_structure;
    _X_arandela Arandela;
};

#endif // X3_PEDAL_STRUCTURE_H
