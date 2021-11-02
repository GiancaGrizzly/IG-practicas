#ifndef X_ARANDELA_H
#define X_ARANDELA_H

#include "X_revolution_object.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_arandela : public _X_revolution_object
{
public:
  _X_arandela(float Size=1.0);
  void draw_fill();
};

#endif // X_ARANDELA_H
