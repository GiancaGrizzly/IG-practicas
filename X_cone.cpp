
#include "X_cone.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_X_cone::_X_cone(float Size)
{
    N = 50;

    Profile.resize(3);
    Profile[0] = _vertex3f(0,-Size/2,0);
    Profile[1] = _vertex3f(Size/2,-Size/2,0);
    Profile[2] = _vertex3f(0,Size/2,0);

    generate_vertex();
    generate_triangles();
    compute_triangles_normals();
}
