#include "ciudad.h"

Ciudad::Ciudad()
{

}

Ciudad::Ciudad(bool esCapital, Posicion posicion)
{
    this->es_capital = esCapital;
    this->posicion = posicion;
}

Ciudad Ciudad::creaCiudad(QString nombre, bool esCapital, Posicion posicion)
{
    Ciudad nueva(esCapital, posicion);
    nueva.setNombre(nombre);

    if (nueva.es_capital == true) {
        nueva.setPalacio(Palacio::creaPalacio());
    }

    return nueva;
}

void Ciudad::setNombre(QString nombre)
{
    this->nombre = nombre;
}

QString Ciudad::getNombre()
{
    return this->nombre;
}

void Ciudad::setPalacio(Palacio *palacio)
{
    this->palacio = palacio;
}
