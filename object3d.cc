/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
    glBegin(GL_LINES);

    // glLineWidth(3);  // Para cambiar el grosor de la linea
    // glColor3fv((GLfloat *) &MAGENTA);  // Para cambiar el color de la linea

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

    // glColor3fv((GLfloat *) &BLUE);  // Para cambiar el color del relleno

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

//    glColor3fv((GLfloat *) &BLACK);  // Para cambiar el color del relleno
//    for (unsigned int i=0; i<Triangles.size(); i+=2) {
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
//    }

//    glColor3fv((GLfloat *) &YEllOW);  // Para cambiar el color del relleno
//    for (unsigned int i=1; i<Triangles.size(); i+=2) {
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
//        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
//    }

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
    GLfloat Light_position[] = {1,1,1,0};
    GLfloat Light_ambient[] = {1,1,1};
    GLfloat Material_diffuse[] = {0.7,0,0};
    GLfloat Material_ambient[] = {0.1,0,0};

    glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat*) &Light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, (GLfloat*) &Light_ambient);

    glPolygonMode(GL_FRONT, GL_FILL);

    glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat*) &Material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat*) &Material_diffuse);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glShadeModel(GL_FLAT);

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
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_lighted_smooth_shading()
{

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

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::traslate(const _vertex3f &vector_t)
{
    for (unsigned int i=0; i < Vertices.size(); i++) {
        //Vertices[i].x = Vertices[i].x + vector_t.x;
        //Vertices[i].y = Vertices[i].y + vector_t.y;
        //Vertices[i].z = Vertices[i].z + vector_t.z;
        Vertices[i] = Vertices[i] + vector_t;
    }
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::rotate_Z(const float angle)
{
    float SIN = sin(angle);
    float COS = cos(angle);

    float aux_X;

    for (unsigned int i=0; i < Vertices.size(); i++) {
        aux_X = Vertices[i].x;
        Vertices[i].x = aux_X*COS - Vertices[i].y*SIN;
        Vertices[i].y = aux_X*SIN + Vertices[i].y*COS;
    }
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::scale(const _vertex3f &vector_s)
{
    for (unsigned int i=0; i < Vertices.size(); i++) {
        Vertices[i].x = Vertices[i].x * vector_s.x;
        Vertices[i].y = Vertices[i].y * vector_s.y;
        Vertices[i].z = Vertices[i].z * vector_s.z;
    }
}
