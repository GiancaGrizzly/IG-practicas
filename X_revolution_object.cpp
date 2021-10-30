
#include "X_revolution_object.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_revolution_object::generate_vertex()
{
    //Compruebo si hay o no lower y upper cover
    if (Profile[0].x == 0)      //Si la coordenada x del primer punto del perfil es 0
        lower = true;           //entonces el objeto tiene lower cover
    else lower=false;
    if (Profile[Profile.size()-1].x == 0)    //Si la coordenada x del ultimo punto del perfil es 0
        upper = true;           //entonces el objeto tiene upper cover
    else upper=false;

    //Reservo espacio para el vector de vertices de la zona central y para el vector de
    //vertices final, en funcion de si hay o no tapaderas
    //Ademas, introduzco los vertices que correspondan a la zona central, y los vertices
    //extremos al final del vector de vertices final
    if (lower and upper) {      //Si el objeto tiene tapadera inferior y superior
        Central.resize(Profile.size()-2);
        for (unsigned int i=0; i < Central.size(); i++)
            Central[i] = Profile[i+1];

        Vertices.resize(2+N*Central.size());
        Vertices[Vertices.size()-2] = Profile[0];
        Vertices[Vertices.size()-1] = Profile[Profile.size()-1];
    }
    else if (lower) {           //Si el objeto tiene lower cover
        Central.resize(Profile.size()-1);
        for (unsigned int i=0; i < Central.size(); i++)
            Central[i] = Profile[i+1];

        Vertices.resize(1+N*Central.size());
        Vertices[Vertices.size()-1] = Profile[0];
    }
    else if (upper) {           //Si el objeto tiene upper cover
        Central.resize(Profile.size()-1);
        for (unsigned int i=0; i < Central.size(); i++)
            Central[i] = Profile[i];

        Vertices.resize(1+N*Central.size());
        Vertices[Vertices.size()-1] = Profile[Profile.size()-1];
    }
    else {                      //Si el objeto no tiene tapaderas
        Central = Profile;
        Vertices.resize(N*Profile.size());
    }


    //Calculo los vertices de la zona central rotados N veces
    for (unsigned int i=0; i < N; i++) { //N rotaciones
        for (unsigned int j=0; j < Central.size(); j++) { //calculo las coordenadas de cada vertice de la zona central
            Vertices[Central.size()*i+j].x = Central[j].x * cos(i*(2*PI/N));
            Vertices[Central.size()*i+j].y = Central[j].y;
            Vertices[Central.size()*i+j].z = -Central[j].x * sin(i*(2*PI/N));
        }
    }
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _X_revolution_object::generate_triangles_central (const unsigned int mod)
{
    unsigned int M_Central = Central.size();

    //Mismo proceso de generacion de triangulos que la version sin optimizar
    for (unsigned int i=0; i < M_Central-1; i++) { //Central.size()-1 filas
        for (unsigned int j=0; j < N; j++) { //N columnas
            Triangles[i*2*N + 2*j]   = _vertex3ui( (i+M_Central*j)%mod, (i+M_Central+M_Central*j)%mod, (1+i+M_Central*j)%mod );             //Triangulo par
            Triangles[i*2*N + 2*j+1] = _vertex3ui( (i+M_Central+M_Central*j)%mod, (1+i+M_Central+M_Central*j)%mod, (1+i+M_Central*j)%mod ); //Triangulo impar
        }
    }
}


void _X_revolution_object::generate_triangles()
{
    //Reservo espacio para el vector de triangulos y los calculo, en funcion de si hay o no tapaderas
    if (lower and upper) {  //Si el objeto tiene tapadera inferior y superior
        Triangles.resize(2*N*(Central.size()-1) + 2*N);
        unsigned int mod = Vertices.size()-2;   //Variable modulo para la operacion %

        generate_triangles_central(mod);

        //Lower cover
        for (unsigned int i=0; i < N; i++)
            Triangles[2*N*(Central.size()-1) + i]   = _vertex3ui( Vertices.size()-2, (Central.size()+i*Central.size())%mod, (i*Central.size())%mod );

        //Upper cover
        for (unsigned int i=0; i < N; i++)
            Triangles[2*N*(Central.size()-1) + N+i] = _vertex3ui( Vertices.size()-1, (Central.size()-1+i*Central.size())%mod, (2*Central.size()-1+i*Central.size())%mod );
    }
    else if (lower) {   //Si el objeto tiene lower cover
        Triangles.resize(2*N*(Central.size()-1) + N);
        unsigned int mod = Vertices.size()-1;   //Variable modulo para la operacion %

        generate_triangles_central(mod);

        //Lower cover
        for (unsigned int i=0; i < N; i++)
            Triangles[2*N*(Central.size()-1) + i] = _vertex3ui( Vertices.size()-1, (Central.size()+i*Central.size())%mod, (i*Central.size())%mod );
    }
    else if (upper) {   //Si el objeto tiene upper cover
        Triangles.resize(2*N*(Central.size()-1) + N);
        unsigned int mod = Vertices.size()-1;   //Variable modulo para la operacion %

        generate_triangles_central(mod);

        //Upper cover
        for (unsigned int i=0; i < N; i++)
            Triangles[2*N*(Central.size()-1) + i] = _vertex3ui( Vertices.size()-1, (Central.size()-1+i*Central.size())%mod, (2*Central.size()-1+i*Central.size())%mod );
    }
    else {   //Si el objeto no tiene tapaderas
        Triangles.resize(2*N*(Central.size()-1));
        generate_triangles_central(Vertices.size());
    }
}

