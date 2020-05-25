#include "silo.h"

Silo::Silo(Recurso r, long capacidad) : recurso(r.nombre, r.tipo)
{
    this->capacidad = capacidad;
    this->recurso = r;
}

void Silo::setCapacidad(long tope)
{
    this->capacidad = tope;
}

long Silo::getCapacidad()
{
    return this->capacidad;
}

long Silo::suma(long cantidad)
{
    if (this->cantidad + cantidad > this->capacidad) {
        cantidad = this->capacidad - this->cantidad;
        this->cantidad = this->capacidad;
    }
    else {
        this->cantidad += cantidad;
    }

    return cantidad;
}

long Silo::resta(long cantidad)
{
    if (cantidad > this->cantidad) {
        cantidad = this->cantidad;
        this->cantidad = 0;
    }
    else {
        this->cantidad -= cantidad;
    }

    return cantidad;
}

bool Silo::estaVacio()
{
    long cantidad = this->getCantidad();
    return (cantidad == 0);
}

long Silo::getCantidad()
{
    return this->cantidad;
}
