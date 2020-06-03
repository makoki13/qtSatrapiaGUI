#ifndef CIUDAD_H
#define CIUDAD_H

#include <QString>

#include "palacio.h"

class Ciudad
{
private:
    bool es_capital;
    QString nombre;
    Posicion posicion;
    Palacio *palacio;
public:
    Ciudad();
    Ciudad(bool esCapital, Posicion posicion);

    static Ciudad creaCiudad(QString nombre, bool esCapital, Posicion posicion);

    void setNombre(QString nombre);
    QString getNombre();

    void setPalacio(Palacio* palacio);
};

#endif // CIUDAD_H
