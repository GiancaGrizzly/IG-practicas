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


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_mode(_object3D_ne::_mode_fill mode)
{
    switch (mode) {
    case MODE_SOLID: draw_fill(); break;
    case MODE_CHESS: draw_chess(); break;
    case MODE_FLAT: draw_lighted_flat_shading(); break;
    case MODE_SMOOTH: draw_lighted_smooth_shading(); break;
//    case MODE_TEXTURE: draw_texture(); break;
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

void _object3D::configure_lighting()
{
    // Luz blanca en el infinito
    GLfloat Light0_position[] = {1,1,1,0};
    GLfloat Light0_ambient[] = {1,1,1};
    GLfloat Light0_diffuse[] = {1,1,1};
    GLfloat Light0_specular[] = {1,1,1};

    // Luz magenta no en el infinito
    GLfloat Light1_position[] = {-1,-1,-1,1};
    GLfloat Light1_ambient[] = {1,0,1};
    GLfloat Light1_diffuse[] = {1,0,1};
    GLfloat Light1_specular[] = {1,0,1};

    // Objeto blanco basico para probar luces
//    GLfloat Material_ambient[] = {0.5,0.5,0.5};
//    GLfloat Material_diffuse[] = {0.5,0.5,0.5};
//    GLfloat Material_specular[] = {0.5,0.5,0.5};
//    GLfloat Material_shininess = 0.6;

    // Esmeralda
    GLfloat Material_ambient[] = {0.0215,0.1745,0.0215};
    GLfloat Material_diffuse[] = {0.07568,0.61424,0.07568};
    GLfloat Material_specular[] = {0.633,0.727811,0.633};
    GLfloat Material_shininess = 0.6;

    // Obsidiana
//    GLfloat Material_ambient[] = {0.05375,0.05,0.06625};
//    GLfloat Material_diffuse[] = {0.18275,0.17,0.22525};
//    GLfloat Material_specular[] = {0.332741,0.328634,0.346435};
//    GLfloat Material_shininess = 0.3;

    glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat*) &Light0_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, (GLfloat*) &Light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, (GLfloat*) &Light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, (GLfloat*) &Light0_specular);

    glLightfv(GL_LIGHT1, GL_POSITION, (GLfloat*) &Light1_position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, (GLfloat*) &Light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, (GLfloat*) &Light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, (GLfloat*) &Light1_specular);

    glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat*) &Material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat*) &Material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat*) &Material_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, Material_shininess*128);
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
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glPolygonMode(GL_FRONT, GL_FILL);

    glBegin(GL_TRIANGLES);
    for (unsigned int i=0; i < Triangles.size(); i++) {
        glNormal3fv((GLfloat *) &Triangles_normals[i]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
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
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glPolygonMode(GL_FRONT, GL_FILL);

    glBegin(GL_TRIANGLES);
    for (unsigned int i=0; i < Triangles.size(); i++) {
        glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glNormal3fv((GLfloat *) &Vertices_normals[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
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
    int n;  // Contador del número de triángulos adyancentes al vértice i
    Vertices_normals.resize(Vertices.size());

    for (unsigned int i=0; i < Vertices.size(); i++) {
        // Inicializo a 0 el vértice y el contador de triángulos adyacentes
        Vertices_normals[i] = _vertex3f(0,0,0);
        n = 0;
        // Acumulo en vertices_normal[i] la suma de las normales de los triángulos adyacentes
        for (unsigned int j=0; j < Triangles.size(); j++) {
            if ( Vertices[i] == Vertices[Triangles[j]._0] or
                 Vertices[i] == Vertices[Triangles[j]._1] or
                 Vertices[i] == Vertices[Triangles[j]._2] )
            {
                Vertices_normals[i] += Triangles_normals[j];
                n++;
            }
        }
        // Calculo la media de la suma anterior y normalizo
        Vertices_normals[i] = (Vertices_normals[i] / n).normalize();
    }
}

