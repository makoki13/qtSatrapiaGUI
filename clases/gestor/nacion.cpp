#include "nacion.h"

Nacion::Nacion(TipoNaciones tipo)
{
    this->tipo = tipo;
}

void Nacion::addCiudad()
{
    Ciudad *ciudad = new Ciudad();
    this->ciudades.append(ciudad);
}
