#include "silo.h"

Silo::Silo(Recurso r, long capacidad) : recurso(r.nombre, capacidad)
{
    this->recurso = r;
}

void Silo::suma(long cantidad)
{
    this->recurso.sumaCantidad(cantidad);
}

long Silo::resta(long cantidad)
{
    return this->recurso.extraeCantidad(cantidad);
}

bool Silo::estaVacio()
{
    return (this->recurso.getCantidad() == 0);
}
