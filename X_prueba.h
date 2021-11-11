#ifndef X_PRUEBA_H
#define X_PRUEBA_H

#include "X_pedals_axis.h"
#include "X_body.h"


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
    _X_body Body;
};

#endif // X_PRUEBA_H
