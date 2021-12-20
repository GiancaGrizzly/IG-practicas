
#include "X_arandela.h"


using namespace _colors_ne;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_X_arandela::_X_arandela(float Size)
{
    N = 50;

    Profile.resize(4);
    Profile[0] = _vertex3f(Size/2,-Size/2,0);
    Profile[1] = _vertex3f(Size*3/4,-Size/2,0);
    Profile[2] = _vertex3f(Size*3/4,Size/2,0);
    Profile[3] = _vertex3f(Size/2,Size/2,0);

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

void _X_arandela::draw_fill()
{
    glColor3fv((GLfloat *) &BLACK);
    _object3D::draw_fill();
}

