#ifndef FUENTE_H
#define FUENTE_H

#include "../posicion.h"
#include "recurso.h"


class Fuente
{
private:
    Posicion posicion;
    Recurso recurso;

    long tope;
    long cantidad;
public:    
    Fuente();
    Fuente(Posicion pos, Recurso r);

    long extraer(long cantidad);
    void volcar(long cantidad);

    Posicion getPosicion();
    Recurso getRecurso();
};

#endif // FUENTE_H
