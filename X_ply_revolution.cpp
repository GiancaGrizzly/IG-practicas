
#include "X_ply_revolution.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_X_ply_revolution::_X_ply_revolution()
{
    if (open("/home/gianca/IG/practicas/ply_models/X_copa.ply") == 1) {  // Se abre sin error --> crear el objeto
        //Creo el perfil
        create();

        //Genero los vertices y triangulos
        N = 50;
        generate_vertex();
        generate_triangles();

        //Genero los vertices y triangulos normales
        _X_revolution_object::compute_triangles_normals();
        _X_revolution_object::compute_vertex_normals();

        //Cierro el archivo
        close();
    }
    else
        cerr << "Error: error al abrir el archivo PLY " << endl;
}

/*****************************************************************************//**
 *
 *
 *****************************************************************************/

void _X_ply_revolution::create()
{
    vector<float> Coordinates;
    vector<unsigned int> Positions;

    unsigned int pos;   //Variable para ir recorriendo y guardando en el vector de
                        //vertices y de triangulos
    read(Coordinates, Positions);

    //Cada 3 coordenadas leidas del vector de coordenadas, guardo un vertice
    Profile.resize(Coordinates.size()/3);
    pos = 0;
    for (unsigned int i=0; i < Profile.size(); i++) {
        Profile[i].x = Coordinates[pos++];
        Profile[i].y = Coordinates[pos++];
        Profile[i].z = Coordinates[pos++];
    }
}
