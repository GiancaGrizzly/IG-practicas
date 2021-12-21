
#include "X_sphere.h"


using namespace _object3D_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_X_sphere::_X_sphere()
{
    N = 60;
    M = 60;

    Profile.resize(M);
    generate_profile();

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

void _X_sphere::generate_profile()
{
    float angle = 3*PI / 2; // 270º en radianes
    float step;

    for (unsigned int i=0; i < M; i++) {
        step = angle + PI*i/(M-1);
        Profile[i].x = cos(step);
        Profile[i].y = sin(step);
        Profile[i].z = 0;
    }
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_sphere::compute_vertex_normals()
{
    Vertices_normals.resize(Vertices.size());

    for (unsigned int i=0; i < Vertices_normals.size(); i++) {
        Vertices_normals[i] = Vertices[i].normalize();
    }
}
