#ifndef X_PRUEBA_H
#define X_PRUEBA_H

#include "X_pedals_axis.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_prueba
{
public:
    void draw_line();
    void draw_fill();

    float alfa = 0;
private:
    _X_pedals_axis Pedals_axis;
};

#endif // X_PRUEBA_H
