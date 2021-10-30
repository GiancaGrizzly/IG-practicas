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
    int Vertex_1, Vertex_2, Vertex_3;

    glBegin(GL_LINES);

    // glLineWidth(3);  // Para cambiar el grosor de la linea
    // glColor3fv((GLfloat *) &MAGENTA);  // Para cambiar el color de la linea

    for (unsigned int i=0; i<Triangles.size(); i++) {
        Vertex_1 = Triangles[i]._0;
        Vertex_2 = Triangles[i]._1;
        Vertex_3 = Triangles[i]._2;

        glVertex3fv((GLfloat *) &Vertices[Vertex_1]);
        glVertex3fv((GLfloat *) &Vertices[Vertex_2]);

        glVertex3fv((GLfloat *) &Vertices[Vertex_1]);
        glVertex3fv((GLfloat *) &Vertices[Vertex_3]);

        glVertex3fv((GLfloat *) &Vertices[Vertex_2]);
        glVertex3fv((GLfloat *) &Vertices[Vertex_3]);
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
    int Vertex_1, Vertex_2, Vertex_3;

    glBegin(GL_TRIANGLES);

    // glColor3fv((GLfloat *) &BLUE);  // Para cambiar el color del relleno

    for (unsigned int i=0; i<Triangles.size(); i++) {
        Vertex_1 = Triangles[i]._0;
        Vertex_2 = Triangles[i]._1;
        Vertex_3 = Triangles[i]._2;

        glVertex3fv((GLfloat *) &Vertices[Vertex_1]);
        glVertex3fv((GLfloat *) &Vertices[Vertex_2]);
        glVertex3fv((GLfloat *) &Vertices[Vertex_3]);
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
    int Vertex_1, Vertex_2, Vertex_3;

    glBegin(GL_TRIANGLES);

    glColor3fv((GLfloat *) &BLACK);  // Para cambiar el color del relleno
    for (unsigned int i=0; i<Triangles.size(); i+=2) {
        Vertex_1 = Triangles[i]._0;
        Vertex_2 = Triangles[i]._1;
        Vertex_3 = Triangles[i]._2;

        glVertex3fv((GLfloat *) &Vertices[Vertex_1]);
        glVertex3fv((GLfloat *) &Vertices[Vertex_2]);
        glVertex3fv((GLfloat *) &Vertices[Vertex_3]);
    }

    glColor3fv((GLfloat *) &YEllOW);  // Para cambiar el color del relleno
    for (unsigned int i=1; i<Triangles.size(); i+=2) {
        Vertex_1 = Triangles[i]._0;
        Vertex_2 = Triangles[i]._1;
        Vertex_3 = Triangles[i]._2;

        glVertex3fv((GLfloat *) &Vertices[Vertex_1]);
        glVertex3fv((GLfloat *) &Vertices[Vertex_2]);
        glVertex3fv((GLfloat *) &Vertices[Vertex_3]);
    }

    glEnd();
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




