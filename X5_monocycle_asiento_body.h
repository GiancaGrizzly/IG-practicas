#ifndef X5_MONOCYCLE_ASIENTO_BODY_H
#define X5_MONOCYCLE_ASIENTO_BODY_H

#include "X4_asiento_axis.h"
#include "X3_body.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X5_monocycle_asiento_body
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);

    void Initialize_asiento_axis();
    void set_scale_asiento_axis(float step);
    float get_scale_asiento_axis();

    float angle_asiento_axis;
private:
    _X4_asiento_axis Asiento_axis;
    _X3_body Body;
};

#endif // X5_MONOCYCLE_ASIENTO_BODY_H
