#ifndef X2_BODY_STRUCTURE_2_H
#define X2_BODY_STRUCTURE_2_H

#include "X1_axis_body.h"
#include "X_arandela.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X2_body_structure_2
{
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
private:
    _X1_axis_body Axis_body;
    _X_arandela Arandela;
};

#endif // X2_BODY_STRUCTURE_1_H
