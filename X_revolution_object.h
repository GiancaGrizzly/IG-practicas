#ifndef X_REVOLUTION_OBJECT_H
#define X_REVOLUTION_OBJECT_H


#include "object3d.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _X_revolution_object : public _object3D
{
    public:
        unsigned int N,M;
        vector<_vertex3f> Profile, Central;
        bool lower, upper;

        void generate_vertex();
        void generate_triangles();

    private:
        void generate_triangles_central (const unsigned int mod);
};


#endif // X_REVOLUTION_OBJECT_H
