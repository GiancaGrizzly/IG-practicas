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

        case Qt::Key_1:Object=OBJECT_TETRAHEDRON;Selected_triangle=-1;break;
        case Qt::Key_2:Object=OBJECT_CUBE;Selected_triangle=-1;break;
        case Qt::Key_3:Object=OBJECT_CONE;Selected_triangle=-1;break;
        case Qt::Key_4:Object=OBJECT_CYLINDER;Selected_triangle=-1;break;
        case Qt::Key_5:Object=OBJECT_SPHERE;Selected_triangle=-1;break;
        case Qt::Key_6:Object=OBJECT_PLY;Selected_triangle=-1;break;
        case Qt::Key_7:Object=OBJECT_HIERARCHICAL;Selected_triangle=-1;break;
        case Qt::Key_8:Object=OBJECT_BOARD;Selected_triangle=-1;break;
        case Qt::Key_0:Object=OBJECT_PLY_REVOLUTION;Selected_triangle=-1;break;

        case Qt::Key_A:
        {
            switch_rotation_magenta_light();

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

        // Modo de dibujado
        case Qt::Key_P:Draw_point=!Draw_point;break;
        case Qt::Key_L:Draw_line=!Draw_line;break;
        case Qt::Key_F:Draw_fill=!Draw_fill;break;
        case Qt::Key_F1:Mode_fill=MODE_SOLID;break;
        case Qt::Key_F2:Mode_fill=MODE_CHESS;break;
        case Qt::Key_F3:Mode_fill=MODE_FLAT;break;
        case Qt::Key_F4:Mode_fill=MODE_SMOOTH;break;
        case Qt::Key_F5:Mode_fill=MODE_TEXTURE_UNLIT;break;
        case Qt::Key_F6:Mode_fill=MODE_TEXTURE_FLAT;break;
        case Qt::Key_F7:Mode_fill=MODE_TEXTURE_SMOOTH;break;

        case Qt::Key_J:switch_state_white_light();break; //activar luz primaria blanca
        case Qt::Key_K:switch_state_magenta_light();break; //activar luz secundaria magenta

        case Qt::Key_C:Projection=PERSPECTIVE;break; //proyección perspectiva
        case Qt::Key_V:Projection=PARALLEL;break; //proyección paralela

        //Movimiento de la cámara
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

//   formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//   Front_plane>0  Back_plane>PlanoDelantero)
  if (Projection == PERSPECTIVE)
    glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
  else
    glOrtho(-Observer_distance,Observer_distance,-Observer_distance,Observer_distance,FRONT_PLANE_PARALLEL,BACK_PLANE_PARALLEL);
}

/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 * Transformacion de vista --> no necesito calcular los angulos pq se donde esta la camara siempre
 * Para una camara general, habria que añadir las funciones que calculen dichas transformaciones
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
    case OBJECT_BOARD:Chess_board.draw_point();break;
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
    case OBJECT_BOARD:Chess_board.draw_line();break;
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_mode(Mode_fill);break;
    case OBJECT_CUBE:Cube.draw_mode(Mode_fill);break;
    case OBJECT_PLY:Ply_file.draw_fill(Selected_triangle);break;
    case OBJECT_CONE:Cone.draw_mode(Mode_fill);break;
    case OBJECT_CYLINDER:Cylinder.draw_mode(Mode_fill);break;
    case OBJECT_SPHERE:Sphere.draw_selection();break;
    case OBJECT_PLY_REVOLUTION:Ply_revolution._X_revolution_object::draw_mode(Mode_fill);break;
    case OBJECT_HIERARCHICAL:Monocycle.draw_mode(Mode_fill);break;
    case OBJECT_BOARD:Chess_board.draw_mode(Mode_fill);break;
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
  glewExperimental = GL_TRUE;
  int err = glewInit();
  if (GLEW_OK != err) {
    // Problem: glewInit failed, something is securely wrong
    QMessageBox MsgBox(this);
    MsgBox.setText("Error: There is not OpenGL drivers\n\nPlease,look for the information of four GPU (AMD, INTEL or NVIDIA) and install the drivers");
    MsgBox.exec();
    Window->close();
  }

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
  glEnable(GL_DEPTH_TEST);

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;

  Mode_fill = MODE_SOLID;
  Projection = PERSPECTIVE;

  Monocycle.angle_pedals_wheel = 0;
  Monocycle.Initialize_asiento_axis();

  step_pedals_wheel = 1;
  step_asiento_axis = 1;
  step_scale_axis = 1;
  grow_scale_asiento_axis = true;

  Prev_mouse_pos.setX(0);
  Prev_mouse_pos.setY(0);

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
 * Evento movimiento del ratón
 *
 *
 *
 *****************************************************************************/

void _gl_widget::mouseMoveEvent(QMouseEvent *MouseEvent)
{
    if (abs(Prev_mouse_pos.x()-MouseEvent->x()) > abs(Prev_mouse_pos.y()-MouseEvent->y())) {
        if (Prev_mouse_pos.x() > MouseEvent->x())
            Observer_angle_y -= ANGLE_STEP;
        else
            Observer_angle_y += ANGLE_STEP;
    }
    else {
        if (Prev_mouse_pos.y() > MouseEvent->y())
            Observer_angle_x -= ANGLE_STEP;
        else
            Observer_angle_x += ANGLE_STEP;
    }

    Prev_mouse_pos.setX(MouseEvent->x());
    Prev_mouse_pos.setY(MouseEvent->y());

    update();
}

/*****************************************************************************//**
 * Evento botón del ratón pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::mousePressEvent(QMouseEvent *MouseEvent)
{
    switch (MouseEvent->button()) {

        case Qt::LeftButton: break;
        case Qt::RightButton:
        {
            Selection_position_x = MouseEvent->x();
            Selection_position_y = height() - MouseEvent->y();
            break;
        }
    }

    update();
}

/*****************************************************************************//**
 * Evento botón del ratón liberado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::mouseReleaseEvent(QMouseEvent *MouseEvent)
{
    switch (MouseEvent->button()) {

        case Qt::LeftButton: break;
        case Qt::RightButton: pick();update();break;
    }

    update();
}

/*****************************************************************************//**
 * Evento rueda del ratón
 *
 *
 *
 *****************************************************************************/

void _gl_widget::wheelEvent(QWheelEvent *WheelEvent)
{

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

// Window_width and Window_height are the widht and height of the device window
// Selection_position_x and Selection_position_y are the coordinates of the mouse

void _gl_widget::pick()
{
  makeCurrent();

  // Frame Buffer Object to do the off-screen rendering
  GLuint FBO;
  glGenFramebuffers(1,&FBO);
  glBindFramebuffer(GL_FRAMEBUFFER,FBO);

  // Texture for drawing
  GLuint Color_texture;
  glGenTextures(1,&Color_texture);
  glBindTexture(GL_TEXTURE_2D,Color_texture);
  // RGBA8
  glTexStorage2D(GL_TEXTURE_2D,1,GL_RGBA8, Window->width(),Window->height());
  // this implies that there is not mip mapping
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

  // Texure for computing the depth
  GLuint Depth_texture;
  glGenTextures(1,&Depth_texture);
  glBindTexture(GL_TEXTURE_2D,Depth_texture);
  // Float
  glTexStorage2D(GL_TEXTURE_2D,1,GL_DEPTH_COMPONENT24, Window->width(),Window->height());

  // Attatchment of the textures to the FBO
  glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,Color_texture,0);
  glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,Depth_texture,0);

  // OpenGL will draw to these buffers (only one in this case)
  static const GLenum Draw_buffers[]={GL_COLOR_ATTACHMENT0};
  glDrawBuffers(1,Draw_buffers);


  /*************************/
  // dibujar escena para seleccion
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glMatrixMode(GL_PROJECTION);

  switch (Object){
  case OBJECT_TETRAHEDRON:Tetrahedron.draw_selection();break;
  case OBJECT_CUBE:Cube.draw_selection();break;
  case OBJECT_PLY:Ply_file.draw_selection();break;
  case OBJECT_CONE:Cone.draw_selection();break;
  case OBJECT_CYLINDER:Cylinder.draw_selection();break;
  case OBJECT_SPHERE:Sphere.draw_selection();break;
  case OBJECT_PLY_REVOLUTION:Ply_revolution._X_revolution_object::draw_selection();break;
  case OBJECT_BOARD:Chess_board.draw_selection();break;
  default:break;
  }
  /*************************/


  // get the pixel
  int Color;
  glReadBuffer(GL_FRONT);
  glPixelStorei(GL_PACK_ALIGNMENT,1);
  glReadPixels(Selection_position_x,Selection_position_y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&Color);


  /*************************/
  // convertir de RGB a identificador
  uint R = uint((Color & 0x000000FF));
  uint G = uint((Color & 0x0000FF00) >> 8);
  uint B = uint((Color & 0x00FF0000) >> 16);

  // actualizar el identificador de la parte seleccionada en el objeto
  Selected_triangle = (R << 16) + (G << 8) + B;
  if (Selected_triangle == 16777215) Selected_triangle = -1;

  cout << Selection_position_x << " -- " << Selection_position_y << " -- " << Color << endl;
  cout << R << " -- " << G << " -- " << B << endl;
  cout << Selected_triangle << endl;

  glUseProgram(0);
  glBindVertexArray(0);
  /*************************/


  glDeleteTextures(1,&Color_texture);
  glDeleteTextures(1,&Depth_texture);
  glDeleteFramebuffers(1,&FBO);
  // the normal framebuffer takes the control of drawing
  glBindFramebuffer(GL_DRAW_FRAMEBUFFER,defaultFramebufferObject());
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _gl_widget::switch_state_white_light()
{
    // Activa/desactiva la luz primaria blanca
    Tetrahedron.state_white_light = !Tetrahedron.state_white_light;
    Cube.state_white_light = !Cube.state_white_light;
    Cone.state_white_light = !Cone.state_white_light;
    Cylinder.state_white_light = !Cylinder.state_white_light;
    Sphere.state_white_light = !Sphere.state_white_light;
    Ply_file.state_white_light = !Ply_file.state_white_light;
    Ply_revolution._X_revolution_object::state_white_light = !Ply_revolution._X_revolution_object::state_white_light;
    Chess_board.state_white_light = !Chess_board.state_white_light;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _gl_widget::switch_state_magenta_light()
{
    // Activa/desactiva la luz secundaria magenta
    Tetrahedron.state_magenta_light = !Tetrahedron.state_magenta_light;
    Cube.state_magenta_light = !Cube.state_magenta_light;
    Cone.state_magenta_light = !Cone.state_magenta_light;
    Cylinder.state_magenta_light = !Cylinder.state_magenta_light;
    Sphere.state_magenta_light = !Sphere.state_magenta_light;
    Ply_file.state_magenta_light = !Ply_file.state_magenta_light;
    Ply_revolution._X_revolution_object::state_magenta_light = !Ply_revolution._X_revolution_object::state_magenta_light;
    Chess_board.state_magenta_light = !Chess_board.state_magenta_light;
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _gl_widget::switch_rotation_magenta_light()
{
    // Activa/desactiva la rotación de la luz magenta
    Tetrahedron.rotate_magenta_light = !Tetrahedron.rotate_magenta_light;
    Cube.rotate_magenta_light = !Cube.rotate_magenta_light;
    Cone.rotate_magenta_light = !Cone.rotate_magenta_light;
    Cylinder.rotate_magenta_light = !Cylinder.rotate_magenta_light;
    Sphere.rotate_magenta_light = !Sphere.rotate_magenta_light;
    Ply_file.rotate_magenta_light = !Ply_file.rotate_magenta_light;
    Ply_revolution._X_revolution_object::rotate_magenta_light = !Ply_revolution._X_revolution_object::rotate_magenta_light;
    Chess_board.rotate_magenta_light = !Chess_board.rotate_magenta_light;
}
