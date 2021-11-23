
#include "X_sphere.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_X_sphere::_X_sphere(float Size)
{
    N = 60;
    M = 60;

    Profile.resize(M);
    generate_profile(Size/2);   // radio r = 0.5 (Size/2) --> esfera unidad

    generate_vertex();
    generate_triangles();
    compute_triangles_normals();
    compute_vertex_normals();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_sphere::generate_profile(float r)
{
    float SIN = sin(PI/M);
    float COS = cos(PI/M);

    Profile[0] = _vertex3f(0,-r,0);
    for (unsigned int i=1; i < M-1; i++) {
        Profile[i].x = Profile[i-1].x*COS - Profile[i-1].y*SIN;
        Profile[i].y = Profile[i-1].x*SIN + Profile[i-1].y*COS;
        Profile[i].z = 0;
    }
    Profile[M-1] = _vertex3f(0,r,0);
}
