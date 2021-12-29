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
#include "X_chess_board.h"

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

  typedef enum {OBJECT_TETRAHEDRON, OBJECT_CUBE, OBJECT_PLY, OBJECT_CONE, OBJECT_CYLINDER,
                OBJECT_SPHERE, OBJECT_PLY_REVOLUTION, OBJECT_HIERARCHICAL, OBJECT_BOARD} _object;
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
  // Evento que tiene lugar cuando la animación está activada
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
  _X_chess_board Chess_board;

  // Temporizador para disparar el evento de la animación
  QTimer *X_timer;

  _gl_widget_ne::_object Object;

  // { SOLID, CHESS, LIGHTED_FLAT, LIGHTED_SMOOTH, TEXTURE }
  _object3D_ne::_mode_fill Mode_fill;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  // Variables para controlar los distintos grados de libertad del modelo jerárquico
  int step_pedals_wheel, step_asiento_axis, step_scale_axis;
  bool grow_scale_asiento_axis;


  // Activa/desativa la rotación de la luz secundaria magenta
  void switch_rotation_light1();

  // Activa/desativa la luz primaria blanca y secundaria magenta
  void switch_state_light0();
  void switch_state_light1();
};

#endif
