/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "QImage"
#include "QImageReader"
#include "basic_object3d.h"


namespace _object3D_ne {

  const float PI=3.14159265;
  const float _90=PI/2;
  const float _180=PI;
  const float _270=3*PI/2;
  const float _360=2*PI;

  typedef enum {MODE_SOLID,MODE_CHESS,MODE_FLAT,MODE_SMOOTH,MODE_TEXTURE} _mode_fill;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D: public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;
  vector<_vertex3f> Triangles_normals;
  vector<_vertex3f> Vertices_normals;
  vector<_vertex2f> Vertices_texture_coordinates;

  bool state_light0=true;
  bool state_light1=true;
  bool rotate_light=false;

  QString Textura_file_name;

  void draw_mode(_object3D_ne::_mode_fill mode);

  void draw_line();
  void draw_fill();
  void draw_chess();

  void draw_lighted_flat_shading();
  void draw_lighted_smooth_shading();
  void draw_texture();

  void read_texture();

  void compute_triangles_normals();
  void compute_vertex_normals();

  private:
  float x_light1=1, z_light1=0;
  QImage Textura;

  void configure_lighting();
};

#endif // OBJECT3D_H
