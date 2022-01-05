#ifndef X8_MONOCYCLE_H
#define X8_MONOCYCLE_H

#include "X7_monocycle_pedals.h"
#include "X5_monocycle_asiento_body.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X8_monocycle
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);

    void Initialize_asiento_axis();
    void set_angle_asiento_axis(float step);
    void set_scale_asiento_axis(float step);
    float get_scale_asiento_axis();

    float angle_pedals_wheel;

private:
    _X7_monocycle_pedals Monocycle_pedals;
    _X5_monocycle_asiento_body Monocycle_asiento_body;
};

#endif // X8_MONOCYCLE_H
