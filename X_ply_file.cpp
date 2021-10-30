
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

    unsigned int pos;   //Variable para ir recorriendo y guardando en el vector de
                        //vertices y de triangulos
    read(Coordinates, Positions);

    //Cada 3 coordenadas leidas del vector de coordenadas, guardo un vertice
    Vertices.resize(Coordinates.size()/3);
    pos = 0;
    for (unsigned int i=0; i < Vertices.size(); i++) {
        Vertices[i].x = Coordinates[pos++];
        Vertices[i].y = Coordinates[pos++];
        Vertices[i].z = Coordinates[pos++];
    }

    //Cada 3 posiciones leidas del vector de posiciones, guardo un triangulo
    Triangles.resize(Positions.size()/3);
    pos = 0;
    for (unsigned int i=0; i < Triangles.size(); i++) {
        Triangles[i]._0 = Positions[pos++];
        Triangles[i]._1 = Positions[pos++];
        Triangles[i]._2 = Positions[pos++];
    }
}
