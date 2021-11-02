#ifndef X_PEDALS_H
#define X_PEDALS_H

#include "X_pedal.h"
#include "X_arandela.h"
#include "X_axis_misc.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_pedals
{
public:
    void draw_line();
    void draw_fill();

    float alfa = 0;
private:
    _X_pedal Pedal;
    _X_arandela Arandela;
    _X_axis_misc Axis_misc;
};

#endif // X_PEDALS_H
