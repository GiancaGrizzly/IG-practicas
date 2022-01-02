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

  typedef enum {MODE_SOLID,MODE_CHESS,MODE_FLAT,MODE_SMOOTH,MODE_TEXTURE_UNLIT,MODE_TEXTURE_FLAT,MODE_TEXTURE_SMOOTH} _mode_fill;
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

  bool state_white_light=true;
  bool state_magenta_light=true;
  bool rotate_magenta_light=false;

  QString Textura_file_name;

  void draw_mode(_object3D_ne::_mode_fill mode);

  void draw_line();
  void draw_fill();
  void draw_chess();
  void draw_lighted_flat_shading();
  void draw_lighted_smooth_shading();
  void draw_texture_unlit();
  void draw_texture_flat_lighted();
  void draw_texture_smooth_lighted();

  protected:
  void read_texture();
  void compute_triangles_normals();
  void compute_vertex_normals();

  private:
  float x_magenta_light=1, z_magenta_light=0;
  QImage Textura;

  void configure_light();
  void configure_material();
  void configure_texture();
};

#endif // OBJECT3D_H
