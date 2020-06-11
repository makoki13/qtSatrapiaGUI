/**
    El objeto Nacion está asociado a un jugador.
    Una nacion puede ser TRIBU, SATRAPIA  IMPERIO
    Asociado a Nacion hay n ciudades. Una de esas ciudades tiene Palacio que es de donde se controla el juego.
*/

#ifndef NACION_H
#define NACION_H

#include <QVector>

#include "ciudad.h"
#include "../item.h"

class Nacion
{
private:
    SubtipoItem_CIVILIZACION tipo;
    QVector<Ciudad*> ciudades;
    Ciudad miCiudadTest;
public:
    Nacion();
    Nacion(SubtipoItem_CIVILIZACION tipo);

    void setTipo(SubtipoItem_CIVILIZACION tipo);
    SubtipoItem_CIVILIZACION getTipo();

    void addCiudad(QString nombre, bool esCapital, Posicion pos);
     QVector<Ciudad*> listaCiudades();

     Ciudad* getCiudad(QString nombre);
};

#endif // NACION_H
