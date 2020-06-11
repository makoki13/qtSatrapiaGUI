#include "nacion.h"

Nacion::Nacion()
{

}

Nacion::Nacion(SubtipoItem_CIVILIZACION tipo)
{
    this->tipo = tipo;
}

void Nacion::setTipo(SubtipoItem_CIVILIZACION tipoNacion) {
    this->tipo = tipoNacion;
}

SubtipoItem_CIVILIZACION Nacion::getTipo()
{
    return this->tipo;
}

void Nacion::addCiudad(QString nombre, bool esCapital, Posicion pos)
{    
    this->ciudades.append(Ciudad::creaCiudad(nombre,esCapital,pos));
}

QVector<Ciudad *> Nacion::listaCiudades()
{
    return this->ciudades;
}

Ciudad *Nacion::getCiudad(QString nombre)
{
    QVector<Ciudad *> vectorCiudades = this->listaCiudades();
    QVectorIterator<Ciudad*> it(vectorCiudades);
     while (it.hasNext()) {
        Ciudad *c = it.next();
        if (c->getNombre() == nombre) return c;
     }

     return nullptr;
}
