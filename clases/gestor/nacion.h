/**
    El objeto Nacion está asociado a un jugador.
    Una nacion puede ser TRIBU, SATRAPIA  IMPERIO
    Asociado a Nacion hay n ciudades. Una de esas ciudades tiene Palacio que es de donde se controla el juego.
*/

#ifndef NACION_H
#define NACION_H

#include <QVector>

#include "ciudad.h"

enum TipoNaciones {
    TRIBU = 1, SATRAPIA = 2, IMPERIO = 3
};

class Nacion
{
private:
    TipoNaciones tipo;
    QVector<Ciudad*> ciudades;
public:
    Nacion(TipoNaciones tipo);

    void addCiudad();
};

#endif // NACION_H
