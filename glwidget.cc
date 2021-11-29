/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;
using namespace _object3D_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);

  //Inicializo el temporizador y le asigno la funcion idle en cada timeout
  X_timer = new QTimer(this);
  connect(X_timer,SIGNAL(timeout()),this,SLOT(X_idle_event()));
}

/*****************************************************************************//**
 * Slot idle_event para la animacion
 *
 *
 *****************************************************************************/

void _gl_widget::X_idle_event()
{
    // Variable que controla el giro de los pedales
    Monocycle.angle_pedals_wheel -= step_pedals_wheel;

    // Se mantiene el eje en un determinado rango de tamaño
    if (Monocycle.get_scale_asiento_axis() < 0)
        grow_scale_asiento_axis = true;
    else if (Monocycle.get_scale_asiento_axis() > 300)
        grow_scale_asiento_axis = false;

    // En funcion de grow, el eje crece o decrece, y además gira en un sentido u otro
    if (grow_scale_asiento_axis) {
        Monocycle.set_scale_asiento_axis(step_scale_axis);
        Monocycle.set_angle_asiento_axis(step_asiento_axis);
    }
    else {
        Monocycle.set_scale_asiento_axis(-step_scale_axis);
        Monocycle.set_angle_asiento_axis(-step_asiento_axis);
    }

    update();
}

/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
    switch(Keyevent->key()) {

        case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
        case Qt::Key_2:Object=OBJECT_CUBE;break;
        case Qt::Key_3:Object=OBJECT_CONE;break;
        case Qt::Key_4:Object=OBJECT_CYLINDER;break;
        case Qt::Key_5:Object=OBJECT_SPHERE;break;
        case Qt::Key_6:Object=OBJECT_PLY;break;
        case Qt::Key_7:Object=OBJECT_HIERARCHICAL;break;
        case Qt::Key_0:Object=OBJECT_PLY_REVOLUTION;break;

        case Qt::Key_A:
        {
            if (X_timer->isActive())
                X_timer->stop();
            else X_timer->start(0);
            break;
        }

        // Controlador de la rotación de los pedales y la rueda
        case Qt::Key_W:
        {
            if (Keyevent->modifiers() & Qt::ShiftModifier){
                Monocycle.angle_pedals_wheel += step_pedals_wheel; break;
            }
            else if (Keyevent->modifiers() & Qt::ControlModifier) {
                if (step_pedals_wheel > 1) step_pedals_wheel -= 1;
                break;
            }
            else if (Keyevent->modifiers() & Qt::AltModifier) {
                step_pedals_wheel += 1; break;
            }
            else {
                Monocycle.angle_pedals_wheel -= step_pedals_wheel; break;
            }
        }

        // Controlador de la rotación del eje y el sillín
        case Qt::Key_E:
        {
            if (Keyevent->modifiers() & Qt::ShiftModifier){
                Monocycle.set_angle_asiento_axis(step_asiento_axis); break;
            }
            else if (Keyevent->modifiers() & Qt::ControlModifier) {
                if (step_asiento_axis > 1) step_asiento_axis -= 1;
                break;
            }
            else if (Keyevent->modifiers() & Qt::AltModifier) {
                step_asiento_axis += 1; break;
            }
            else {
                Monocycle.set_angle_asiento_axis(-step_asiento_axis); break;
            }
        }

        // Controlador del escalado del eje del sillín
        case Qt::Key_R:
        {
            if (Keyevent->modifiers() & Qt::ShiftModifier){
                if (Monocycle.get_scale_asiento_axis() > 0)
                    Monocycle.set_scale_asiento_axis(-step_scale_axis);
                break;
            }
            else if (Keyevent->modifiers() & Qt::ControlModifier) {
                if (step_scale_axis > 1) step_scale_axis -= 1;
                break;
            }
            else if (Keyevent->modifiers() & Qt::AltModifier) {
                if (step_scale_axis < 5) step_scale_axis += 1;
                break;
            }
            else {
                if (Monocycle.get_scale_asiento_axis() < 300)
                    Monocycle.set_scale_asiento_axis(step_scale_axis);
                break;
            }
        }

        case Qt::Key_P:Draw_point=!Draw_point;break;
        case Qt::Key_L:Draw_line=!Draw_line;break;
        case Qt::Key_F:Draw_fill=!Draw_fill;break;
        case Qt::Key_F1:Mode_fill=MODE_SOLID;break;
        case Qt::Key_F2:Mode_fill=MODE_CHESS;break;
        case Qt::Key_F3:Mode_fill=MODE_FLAT;break;
        case Qt::Key_F4:Mode_fill=MODE_SMOOTH;break;
        case Qt::Key_F5:Mode_fill=MODE_TEXTURE;break;

        case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
        case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
        case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
        case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
        case Qt::Key_PageUp:Observer_distance*=1.2;break;
        case Qt::Key_PageDown:Observer_distance/=1.2;break;
    }

    update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;

    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_PLY:Ply_file.draw_point();break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_point();break;
    case OBJECT_PLY_REVOLUTION:Ply_revolution._X_revolution_object::draw_point();break;

    case OBJECT_HIERARCHICAL:Monocycle.draw_point();break;

    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;

    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_PLY:Ply_file.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_PLY_REVOLUTION:Ply_revolution._X_revolution_object::draw_line();break;

    case OBJECT_HIERARCHICAL:Monocycle.draw_line();break;

    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_mode(Mode_fill);break;

    case OBJECT_CUBE:Cube.draw_mode(Mode_fill);break;
    case OBJECT_PLY:Ply_file.draw_mode(Mode_fill);break;
    case OBJECT_CONE:Cone.draw_mode(Mode_fill);break;
    case OBJECT_CYLINDER:Cylinder.draw_mode(Mode_fill);break;
    case OBJECT_SPHERE:Sphere.draw_mode(Mode_fill);break;
    case OBJECT_PLY_REVOLUTION:Ply_revolution._X_revolution_object::draw_mode(Mode_fill);break;

    case OBJECT_HIERARCHICAL:Monocycle.draw_mode(Mode_fill);break;

    default:break;
    }
  }

}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;

  Mode_fill = MODE_SOLID;

  Monocycle.angle_pedals_wheel = 0;
  Monocycle.Initialize_asiento_axis();

  step_pedals_wheel = 1;
  step_asiento_axis = 1;
  step_scale_axis = 1;

  grow_scale_asiento_axis = true;
}
