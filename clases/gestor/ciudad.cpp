#include "ciudad.h"

Ciudad::Ciudad()
{

}

Ciudad::Ciudad(bool esCapital, Posicion posicion)
{
    this->es_capital = esCapital;
    this->posicion = posicion;
}

Ciudad* Ciudad::creaCiudad(QString nombre, bool esCapital, Posicion posicion)
{
    Ciudad* nueva = new Ciudad(esCapital, posicion);
    nueva->setNombre(nombre);

    if (nueva->es_capital == true) {
        nueva->setPalacio(Palacio::creaPalacio());
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

void Ciudad::setCapital(bool valor)
{
    this->es_capital = valor;
}

bool Ciudad::esCapital()
{
    return this->es_capital;
}

void Ciudad::setPosicion(Posicion pos)
{
    this->posicion = pos;
}

Posicion Ciudad::getPosicion()
{
    return this->posicion;
}

void Ciudad::setPalacio(Palacio *palacio)
{
    this->palacio = palacio;
}

Palacio* Ciudad::getPalacio()
{
    return this->palacio;
}
