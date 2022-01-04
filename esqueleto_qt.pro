HEADERS += \
  X1_axis_body.h \
  X1_axis_misc.h \
  X1_body_join.h \
  X1_cojin.h \
  X1_pedal.h \
  X1_wheel.h \
  X2_asiento_base.h \
  X2_asiento_respaldo.h \
  X2_body_structure_1.h \
  X2_body_structure_2.h \
  X2_pedal_structure.h \
  X3_asiento.h \
  X3_body.h \
  X3_pedals_axis.h \
  X4_asiento_axis.h \
  X4_pedals_axis_wheel.h \
  X5_monocycle_asiento_body.h \
  X5_monocycle_pedals.h \
  X6_monocycle.h \
  X_arandela.h \
  X_chess_board.h \
  X_cone.h \
  X_cube.h \
  X_cylinder.h \
  X_ply_file.h \
  X_ply_revolution.h \
  X_revolution_object.h \
  X_sphere.h \
  basic_object3d.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  glwidget.h \
  vertex.h \
  window.h

SOURCES += \
  X1_axis_body.cpp \
  X1_axis_misc.cpp \
  X1_body_join.cpp \
  X1_cojin.cpp \
  X1_pedal.cpp \
  X1_wheel.cpp \
  X2_asiento_base.cpp \
  X2_asiento_respaldo.cpp \
  X2_body_structure_1.cpp \
  X2_body_structure_2.cpp \
  X2_pedal_structure.cpp \
  X3_asiento.cpp \
  X3_body.cpp \
  X3_pedals_axis.cpp \
  X4_asiento_axis.cpp \
  X4_pedals_axis_wheel.cpp \
  X5_monocycle_asiento_body.cpp \
  X5_monocycle_pedals.cpp \
  X6_monocycle.cpp \
  X_arandela.cpp \
  X_chess_board.cpp \
  X_cone.cpp \
  X_cube.cpp \
  X_cylinder.cpp \
  X_ply_file.cpp \
  X_ply_revolution.cpp \
  X_revolution_object.cpp \
  X_sphere.cpp \
  basic_object3d.cc \
  file_ply_stl.cc \
  object3d.cc \
  axis.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


INCLUDEPATH += /home/gianca/IG/practicas/GLEW/include

LIBS += -L/home/gianca/IG/practicas/GLEW/lib -lGLEW \
-L/usr/X11R6/lib64 -lGL

CONFIG += c++11
QT += widgets
