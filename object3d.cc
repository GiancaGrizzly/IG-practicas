/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#include "object3d.h"

using namespace _colors_ne;
using namespace _object3D_ne;

#define SIN_ROTATE_LIGHT sin(_360/720)
#define COS_ROTATE_LIGHT cos(_360/720)


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_mode(_mode_fill mode)
{
    switch (mode) {
    case MODE_SOLID: draw_fill(); break;
    case MODE_CHESS: draw_chess(); break;
    case MODE_FLAT: draw_lighted_flat_shading(); break;
    case MODE_SMOOTH: draw_lighted_smooth_shading(); break;
    case MODE_TEXTURE: draw_texture_unlit(); break;
    }
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
    glBegin(GL_LINES);

    for (unsigned int i=0; i<Triangles.size(); i++) {
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0; i<Triangles.size(); i++) {
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glBegin(GL_TRIANGLES);

    for (unsigned int i=0; i<Triangles.size(); i++) {
        if (i%2 == 0) glColor3fv((GLfloat *) &BLACK);
        else          glColor3fv((GLfloat *) &YEllOW);

        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }

    glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_lighted_flat_shading()
{
    configure_lighting();

    glShadeModel(GL_FLAT);

    glEnable(GL_LIGHTING);
    if (state_white_light) glEnable(GL_LIGHT0);
    if (state_magenta_light) glEnable(GL_LIGHT1);

    glBegin(GL_TRIANGLES);
    for (unsigned int i=0; i < Triangles.size(); i++) {
        glNormal3fv((GLfloat *) &Triangles_normals[i]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

    glDisable(GL_LIGHTING);
    if (state_white_light) glDisable(GL_LIGHT0);
    if (state_magenta_light) glDisable(GL_LIGHT1);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_lighted_smooth_shading()
{
    configure_lighting();

    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);
    if (state_white_light) glEnable(GL_LIGHT0);
    if (state_magenta_light) glEnable(GL_LIGHT1);

    glBegin(GL_TRIANGLES);
    glEnable(GL_RESCALE_NORMAL);
    for (unsigned int i=0; i < Triangles.size(); i++) {
        glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glDisable(GL_RESCALE_NORMAL);
    glEnd();

    glDisable(GL_LIGHTING);
    if (state_white_light) glDisable(GL_LIGHT0);
    if (state_magenta_light) glDisable(GL_LIGHT1);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_texture_unlit()
{
    configure_texture();

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);
    for (unsigned int i=0; i < Triangles.size(); i++) {
        glTexCoord2fv((GLfloat *) &Vertices_texture_coordinates[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord2fv((GLfloat *) &Vertices_texture_coordinates[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord2fv((GLfloat *) &Vertices_texture_coordinates[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_texture_flat_lighted()
{
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

    glTexImage2D(GL_TEXTURE_2D,0,3,Textura.width(),Textura.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Textura.bits());

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);
    for (unsigned int i=0; i < Triangles.size(); i++) {
        glTexCoord2fv((GLfloat *) &Vertices_texture_coordinates[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord2fv((GLfloat *) &Vertices_texture_coordinates[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord2fv((GLfloat *) &Vertices_texture_coordinates[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_texture_smooth_lighted()
{
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

    glTexImage2D(GL_TEXTURE_2D,0,3,Textura.width(),Textura.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Textura.bits());

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);
    for (unsigned int i=0; i < Triangles.size(); i++) {
        glTexCoord2fv((GLfloat *) &Vertices_texture_coordinates[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord2fv((GLfloat *) &Vertices_texture_coordinates[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord2fv((GLfloat *) &Vertices_texture_coordinates[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::configure_lighting()
{
    // Luz blanca en el infinito (global)
    GLfloat Light0_position[] = {1,1,1,0};
    GLfloat Light0_ambient[]  = {1,1,1};
    GLfloat Light0_diffuse[]  = {1,1,1};
    GLfloat Light0_specular[] = {1,1,1};

    // Luz magenta no en el infinito (local)
    if (rotate_magenta_light) {
        GLfloat aux = x_magenta_light;
        x_magenta_light = x_magenta_light*COS_ROTATE_LIGHT + z_magenta_light*SIN_ROTATE_LIGHT;
        z_magenta_light =     -aux*SIN_ROTATE_LIGHT + z_magenta_light*COS_ROTATE_LIGHT;
    }
    GLfloat Light1_position[] = {x_magenta_light,1,z_magenta_light,1};
    GLfloat Light1_ambient[]  = {1,0,1};
    GLfloat Light1_diffuse[]  = {1,0,1};
    GLfloat Light1_specular[] = {1,0,1};

    GLfloat Material_ambient[]  = {0.3,0.3,0.3};
    GLfloat Material_diffuse[]  = {0.3,0.3,0.3};
    GLfloat Material_specular[] = {0.3,0.3,0.3};
    GLfloat Material_shininess  = 0.2;

    // Esmeralda
//    GLfloat Material_ambient[]  = {0.0215,0.1745,0.0215};
//    GLfloat Material_diffuse[]  = {0.07568,0.61424,0.07568};
//    GLfloat Material_specular[] = {0.633,0.727811,0.633};
//    GLfloat Material_shininess  = 0.6;

    glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat*) &Light0_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  (GLfloat*) &Light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  (GLfloat*) &Light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, (GLfloat*) &Light0_specular);

    glLightfv(GL_LIGHT1, GL_POSITION, (GLfloat*) &Light1_position);
    glLightfv(GL_LIGHT1, GL_AMBIENT,  (GLfloat*) &Light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  (GLfloat*) &Light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, (GLfloat*) &Light1_specular);

    glMaterialfv(GL_FRONT, GL_AMBIENT,  (GLfloat*) &Material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  (GLfloat*) &Material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat*) &Material_specular);
    glMaterialf (GL_FRONT, GL_SHININESS,Material_shininess*128);

    glPolygonMode(GL_FRONT,GL_FILL);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::configure_texture()
{
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

    glTexImage2D(GL_TEXTURE_2D,0,3,Textura.width(),Textura.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Textura.bits());
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::read_texture()
{
    QImageReader Reader(Textura_file_name);
    Reader.setAutoTransform(true);

    Textura = Reader.read();
    if (Textura.isNull()) exit(-1);

    Textura = Textura.mirrored();
    Textura = Textura.convertToFormat(QImage::Format_RGB888);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::compute_triangles_normals()
{
    _vertex3f A, B;
    Triangles_normals.resize(Triangles.size());
    for (unsigned int i=0; i < Triangles.size(); i++) {
        // A = P1-P0  ******** B = P2-P0
        A = Vertices[Triangles[i]._1] - Vertices[Triangles[i]._0];
        B = Vertices[Triangles[i]._2] - Vertices[Triangles[i]._0];

        // Guardo el producto vectorial entre A y B normalizado
        Triangles_normals[i] = (A.cross_product(B)).normalize();
    }
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::compute_vertex_normals()
{
    // Reservo espacio para las normales e inicializo a 0
    Vertices_normals.resize(Vertices.size(),_vertex3f(0,0,0));
    // Contador del número de triángulos adyancentes al vértice i
    vector<int> n;
    n.resize(Vertices.size(),0);

    // Para cada vértice de cada triángulo, voy acumulando la correspondiente normal del triángulo
    // y incremento el contador que corresponde a ese vértice
    for (unsigned int i=0; i < Triangles.size(); i++) {
        Vertices_normals[Triangles[i]._0] += Triangles_normals[i];
        n[Triangles[i]._0]++;
        Vertices_normals[Triangles[i]._1] += Triangles_normals[i];
        n[Triangles[i]._1]++;
        Vertices_normals[Triangles[i]._2] += Triangles_normals[i];
        n[Triangles[i]._2]++;
    }

    // Divido el valor acumulado en cada vértice por su contador asociado y normalizo el resultado
    for (unsigned int i=0; i < Vertices_normals.size(); i++) {
        Vertices_normals[i] = ( Vertices_normals[i] / n[i] ).normalize();
    }
}

