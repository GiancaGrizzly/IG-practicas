/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"


#define PI 3.14159265

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;
  vector<_vertex3f> Triangles_normals;
  vector<_vertex3f> Vertices_normals;
  vector<_vertex2f> Vertices_TexCoord;

  void draw_line();
  void draw_fill();
  void draw_chess();

  void draw_lighted_flat_shading();
  void draw_lighted_smooth_shading();
  void draw_texture();

  void traslate(const _vertex3f &vector_t);
  void rotate_Z(const float angle);
  void scale(const _vertex3f &vector_s);

  void compute_triangles_normals();
  void compute_vertex_normals();

};

#endif // OBJECT3D_H
