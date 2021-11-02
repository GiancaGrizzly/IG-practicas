HEADERS += \
  X_arandela.h \
  X_axis_body.h \
  X_axis_join.h \
  X_axis_misc.h \
  X_axis_wheels.h \
  X_cojin.h \
  X_cone.h \
  X_cube.h \
  X_cylinder.h \
  X_pedal.h \
  X_pedals.h \
  X_ply_file.h \
  X_ply_revolution.h \
  X_revolution_object.h \
  X_sphere.h \
  X_wheel.h \
  colors.h \
  basic_object3d.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  glwidget.h \
  vertex.h \
  window.h

SOURCES += \
  X_arandela.cpp \
  X_axis_body.cpp \
  X_axis_join.cpp \
  X_axis_misc.cpp \
  X_axis_wheels.cpp \
  X_cojin.cpp \
  X_cone.cpp \
  X_cube.cpp \
  X_cylinder.cpp \
  X_pedal.cpp \
  X_pedals.cpp \
  X_ply_file.cpp \
  X_ply_revolution.cpp \
  X_revolution_object.cpp \
  X_sphere.cpp \
  X_wheel.cpp \
  basic_object3d.cc \
  file_ply_stl.cc \
  object3d.cc \
  axis.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
