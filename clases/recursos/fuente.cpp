#include "fuente.h"

Fuente::Fuente(Posicion pos, Recurso r) : recurso(r.nombre) {
    this->posicion = pos;
    this->recurso = r;
}

long Fuente::extraer(long cantidad)
{
    return this->recurso.extraeCantidad(cantidad);
}
