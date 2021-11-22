#ifndef X1_BODY_JOIN_H
#define X1_BODY_JOIN_H

#include "X_cube.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X1_body_join
{
public:
    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
private:
    _X_cube Cube;
};

#endif // X1_BODY_JOIN_H
