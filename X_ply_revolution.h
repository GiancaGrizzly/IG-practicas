#ifndef X_PLY_REVOLUTION_H
#define X_PLY_REVOLUTION_H


#include "X_ply_file.h"
#include "X_revolution_object.h"

class _X_ply_revolution : public _file_ply, public _X_revolution_object
{
public:
    _X_ply_revolution();
    void create();

};

#endif // X_PLY_REVOLUTION_H
