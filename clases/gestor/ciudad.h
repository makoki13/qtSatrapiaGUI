/**
    Una ciudad tiene varios edificios que son gestionados por el Palacio
    (o la alcadía (eso en proyecto))
    La ciudad tiene una posicion y un nombre
    Hay una única ciudad que alberga el palacio.
*/

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
