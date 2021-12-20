
#include "X_sphere.h"


using namespace _object3D_ne;

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
 * Función para generar el perfil de la esfera (una semicircunferencia)
 * La semicircunferencia tiene 180º, así que los divido entre M vértices que tiene el
 * perfil, de forma que todos los vértices del perfil quedan a la misma distancia
 * Cada vértice se obtiene al rotar sobre el eje z el vértice anterior
 *
 * Esta versión para obtener el perfil de la esfera la añadí después de ver el tema
 * de las transformaciones, ya que me parecía una buena forma de generar la esfera sin
 * distintos tamaños de triángulos, ya que la versión que había creado antes tenía
 * este inconveniente y me daba problemas con la iluminación
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
