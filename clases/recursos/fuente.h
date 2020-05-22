#ifndef FUENTE_H
#define FUENTE_H

#include "../posicion.h"
#include "recurso.h"


class Fuente
{
private:
    Posicion posicion;
    Recurso recurso;
public:    
    Fuente(Posicion pos, Recurso r);

    long extraer(long cantidad);
};

#endif // FUENTE_H
