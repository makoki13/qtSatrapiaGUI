#include "fuente.h"

Fuente::Fuente()
{

}

Fuente::Fuente(Posicion pos, Recurso r, long cantidadInicial) : recurso(r.nombre, r.tipo) {
    this->posicion = pos;
    this->recurso = r;
    this->tope = -1;
    this->cantidad = cantidadInicial;
}

long Fuente::extraer(long cantidad)
{
    if (this->tope == -1) return cantidad;

    if (cantidad > this->cantidad) {
        cantidad = this->cantidad;
        this->cantidad = 0;
    }
    else {
        this->cantidad -= cantidad;
    }

    return cantidad;
}

void Fuente::volcar(long cantidad) {
    if (this->tope == -1) return;

    if (this->cantidad +  cantidad > tope) {
        this->cantidad = tope;
    }
    else {
        this->cantidad += tope;
    }
}

Posicion Fuente::getPosicion()
{
    return this->posicion;
}

Recurso Fuente::getRecurso()
{
    return this->recurso;
}
