#ifndef SILO_H
#define SILO_H

#include "recurso.h"

class Silo
{
protected:

    Recurso recurso;
    long capacidad;
    long cantidad;

public:
    Silo();
    Silo(Recurso r, long capacidad);

    void setCapacidad(long tope);
    long getCapacidad();

    long suma(long cantidad);
    long resta(long cantidad);
    bool estaVacio();
    long getCantidad();
};

#endif // SILO_H
