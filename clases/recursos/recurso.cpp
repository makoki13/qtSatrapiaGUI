#include "recurso.h"

Recurso::Recurso(QString nombre, long tope)
{
    this->tope = tope;
    this->nombre = nombre;
}

long Recurso::getCantidad() {
    return cantidad;
}

long Recurso::setCantidad(long valor)
{
    if (  valor > tope) valor = tope;
    cantidad = valor;
    return valor;
}

void Recurso::sumaCantidad(long suma ) {
    if ( ( ( cantidad + suma ) > tope ) && (tope != -1) ) {
        this->cantidad = tope;
    }
    else {
        cantidad += suma;
    }
}

long Recurso::extraeCantidad(long valor)
{
    if (  valor > cantidad) valor = cantidad;
    cantidad -= valor;

    return valor;
}

void Recurso::setTope(long tope)
{
    this->tope = tope;
}
