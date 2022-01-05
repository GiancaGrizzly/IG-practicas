
#include "X_cylinder.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_X_cylinder::_X_cylinder(float Size)
{
    N = 60;

    Profile.resize(4);
    Profile[0] = _vertex3f(0,-Size/2,0);
    Profile[1] = _vertex3f(Size/2,-Size/2,0);
    Profile[2] = _vertex3f(Size/2,Size/2,0);
    Profile[3] = _vertex3f(0,Size/2,0);

    //Any direction
//    Profile[3] = _vertex3f(0,-Size/2,0);
//    Profile[2] = _vertex3f(Size/2,-Size/2,0);
//    Profile[1] = _vertex3f(Size/2,Size/2,0);
//    Profile[0] = _vertex3f(0,Size/2,0);

    generate_vertex();
    generate_triangles();
    compute_triangles_normals();
    compute_vertex_normals();
}
