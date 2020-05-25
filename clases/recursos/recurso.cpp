#include "recurso.h"

Recurso::Recurso(QString nombre, TipoRecurso tipo)
{
    this->tipo = tipo;
    this->nombre = nombre;
}

QString Recurso::getNombre() {
    return this->nombre;
}

TipoRecurso Recurso::getTipo() {
    return this->tipo;
}
