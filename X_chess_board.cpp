
#include "X_chess_board.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_X_chess_board::_X_chess_board(float Size)
{
    Vertices.resize(4);
    Vertices[0] = _vertex3f(-Size,-Size,0);
    Vertices[1] = _vertex3f(Size,-Size,0);
    Vertices[2] = _vertex3f(Size,Size,0);
    Vertices[3] = _vertex3f(-Size,Size,0);

    Triangles.resize(2);
    Triangles[0] = _vertex3ui(0,1,3);
    Triangles[1] = _vertex3ui(1,2,3);

    Vertices_texture_coordinates.resize(4);
    Vertices_texture_coordinates[0] = _vertex2f(0,0);
    Vertices_texture_coordinates[1] = _vertex2f(1,0);
    Vertices_texture_coordinates[2] = _vertex2f(1,1);
    Vertices_texture_coordinates[3] = _vertex2f(0,1);


    compute_triangles_normals();
    compute_vertex_normals();

    Textura_file_name = "/home/gianca/IG/practicas/skeleton/texturas/tablero_madera.jpg";
    read_texture();
}
