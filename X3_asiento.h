#ifndef X3_ASIENTO_H
#define X3_ASIENTO_H

#include "X2_asiento_base.h"
#include "X2_asiento_respaldo.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X3_asiento
{
public:
    void draw_point();
    void draw_line();
    void draw_mode(_object3D_ne::_mode_fill mode);
private:
    _X2_asiento_base Asiento_base;
    _X2_asiento_respaldo Asiento_respaldo;
};

#endif // X3_ASIENTO_H
