#ifndef X_ASIENTO_AXIS_H
#define X_ASIENTO_AXIS_H

#include "X_axis_misc.h"
#include "X_asiento.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_asiento_axis
{
public:
    void draw_line();
    void draw_fill();

    float alfa;
    bool grow;
private:
    _X_asiento Asiento;
    _X_axis_misc Eje;
};

#endif // X_ASIENTO_AXIS_H
