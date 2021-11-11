#ifndef X_BODY_H
#define X_BODY_H

#include "X_axis_body.h"
#include "X_body_2.h"
#include "X_arandela.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_body
{
public:
    void draw_line();
    void draw_fill();
private:
    _X_axis_body Axis_body;
    _X_body_2 Body_2;
    _X_arandela Arandela;
};

#endif // X_BODY_H
