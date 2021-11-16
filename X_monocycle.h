#ifndef X_MONOCYCLE_H
#define X_MONOCYCLE_H

#include "X_asiento_axis.h"
#include "X_body.h"
#include "X_pedals_axis.h"
#include "X_wheel.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_monocycle
{
public:
    void draw_line();
    void draw_fill();

    void Initialize_asiento(float a, bool grow);
    float Get_asiento_alfa();
    void Set_asiento_alfa(float step);
    bool Get_asiento_grow();
    void Set_asiento_grow(bool grow);

    float alfa, beta;
private:
    _X_asiento_axis Asiento;
    _X_body Body;
    _X_pedals_axis Pedals_axis;
    _X_wheel Wheel;
};

#endif // X_MONOCYCLE_H
