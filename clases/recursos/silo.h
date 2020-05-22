#ifndef SILO_H
#define SILO_H

#include "recurso.h"

class Silo
{
private:

    Recurso recurso;

public:
    Silo(Recurso r, long capacidad);

    void suma(long cantidad);
    long resta(long cantidad);
    bool estaVacio();
};

#endif // SILO_H
