#ifndef X_SPHERE_H
#define X_SPHERE_H

#include "X_revolution_object.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_sphere : public _X_revolution_object
{
public:
  _X_sphere();
private:
  void generate_profile();
  void compute_vertex_normals();
};

#endif // X_SPHERE_H
