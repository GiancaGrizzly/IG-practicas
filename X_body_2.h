#ifndef X_BODY_2_H
#define X_BODY_2_H

#include "X_axis_body.h"
#include "X_body_join.h"
#include "X_arandela.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_body_2
{
public:
    void draw_line();
    void draw_fill();
private:
    _X_axis_body Axis_body;
    _X_body_join Body_join;
    _X_arandela Arandela;
};

#endif // X_BODY_2_H
