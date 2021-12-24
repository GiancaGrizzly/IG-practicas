
#include "X_ply_file.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_X_ply_file::_X_ply_file(const string &filename)
{
    if (open(filename) == 1) {
        // Se abre sin error --> crear el objeto
        create();
        close();
    }
    else
        cerr << "Error: error al abrir el archivo PLY " << endl;
}

/*****************************************************************************//**
 *
 *
 *****************************************************************************/

void _file_ply::create()
{
    vector<float> Coordinates;
    vector<unsigned int> Positions;

    unsigned int i,x,y,z;   //Variable para ir recorriendo y guardando en el vector de
                        //vertices y de triangulos
    read(Coordinates, Positions);

    //Cada 3 coordenadas leidas del vector de coordenadas, guardo un vertice
    Vertices.resize(Coordinates.size()/3);
    for (i=0,x=0,y=1,z=2; i < Vertices.size(); i++,x+=3,y+=3,z+=3) {
        Vertices[i] = _vertex3f(Coordinates[x],Coordinates[y],Coordinates[z]);
    }

    //Cada 3 posiciones leidas del vector de posiciones, guardo un triangulo
    Triangles.resize(Positions.size()/3);
    for (i=0,x=0,y=1,z=2; i < Triangles.size(); i++,x+=3,y+=3,z+=3) {
        Triangles[i] = _vertex3ui(Positions[x],Positions[y],Positions[z]);
    }

    compute_triangles_normals();
    compute_vertex_normals();
}
