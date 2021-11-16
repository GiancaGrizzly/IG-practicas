

#include "X_sphere.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_X_sphere::_X_sphere(float Size)
{
    N = 50;

    Profile.resize(13);

    Profile[0] = _vertex3f(0,-Size/2,0);  //lower cover

    Profile[1] = _vertex3f(Size/8,-0.484122918,0);
    Profile[2] = _vertex3f(Size/4,-0.433012702,0);
    Profile[3] = _vertex3f(0.330756708,-Size*3/8,0);
    Profile[4] = _vertex3f(0.433012702,-Size/4,0);
    Profile[5] = _vertex3f(0.484122918,-Size/8,0);

    Profile[6] = _vertex3f(Size/2,0,0);

    Profile[7] = _vertex3f(0.484122918,Size/8,0);
    Profile[8] = _vertex3f(0.433012702,Size/4,0);
    Profile[9] = _vertex3f(0.330756708,Size*3/8,0);
    Profile[10] = _vertex3f(Size/4,0.433012702,0);
    Profile[11] = _vertex3f(Size/8,0.484122918,0);

    Profile[12] = _vertex3f(0,Size/2,0);  //upper cover

    generate_vertex();
    generate_triangles();
    compute_triangles_normals();
}
