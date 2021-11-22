#ifndef X2_ASIENTO_BASE_H
#define X2_ASIENTO_BASE_H

#include "X1_cojin.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X2_asiento_base
{
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
private:
    _X1_cojin Cojin;
};


#endif // X2_ASIENTO_BASE_H
