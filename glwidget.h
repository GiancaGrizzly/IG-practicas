/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"

#include "X_cube.h"
#include "X_ply_file.h"
#include "X_cone.h"
#include "X_cylinder.h"
#include "X_sphere.h"
#include "X_ply_revolution.h"
#include "X6_monocycle.h"

//#include "X_arandela.h"
//#include "X2_pedal_structure.h"
//#include "X2_asiento_respaldo.h"
//#include "X2_asiento_base.h"
//#include "X2_body_structure_1.h"
//#include "X2_body_structure_2.h"
//#include "X3_pedals_axis.h"
//#include "X3_body.h"
//#include "X3_asiento.h"
//#include "X4_pedals_axis_wheel.h"
//#include "X4_asiento_axis.h"
//#include "X5_monocycle_pedals.h"
//#include "X5_monocycle_asiento_body.h"

#include <QTimer>


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON, OBJECT_CUBE, OBJECT_PLY, OBJECT_CONE, OBJECT_CYLINDER,
                OBJECT_SPHERE, OBJECT_PLY_REVOLUTION, OBJECT_HIERARCHICAL} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;

private slots:
  void X_idle_event();

private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;

  _X_cube Cube;
  _X_ply_file Ply_file;
  _X_cone Cone;
  _X_cylinder Cylinder;
  _X_sphere Sphere;
  _X_ply_revolution Ply_revolution;
  _X6_monocycle Monocycle;

//  _X_arandela Arandela;
//  _X2_pedal_structure Pedal_structure;
//  _X2_asiento_respaldo Asiento_respaldo;
//  _X2_asiento_base Asiento_base;
//  _X2_body_structure_1 Body_structure_1;
//  _X2_body_structure_2 Body_structure_2;
//  _X3_pedals_axis Pedals_axis;
//  _X3_body Body;
//  _X3_asiento Asiento;
//  _X4_pedals_axis_wheel Pedals_axis_wheel;
//  _X4_asiento_axis Asiento_axis;
//  _X5_monocycle_pedals Monocycle_pedals;
//  _X5_monocycle_asiento_body Monocycle_asiento_body;

  QTimer *X_timer;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;

  bool Draw_lighted_flat_shading;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  int step_pedals_wheel, step_asiento_axis, step_scale_axis;
  bool grow_scale_asiento_axis;
};

#endif
