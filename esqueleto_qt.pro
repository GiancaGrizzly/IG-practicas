HEADERS += \
  X_cone.h \
  X_cube.h \
  X_cylinder.h \
  X_ply_file.h \
  X_ply_revolution.h \
  X_revolution_object.h \
  X_sphere.h \
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


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
