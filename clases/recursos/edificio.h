#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "../posicion.h"
#include "almacen.h"
#include "extractor.h"

class Edificio
{
private:
    Posicion pos;
    Almacen almacen;
    QList<Extractor> extractores;
public:
    Edificio();
    Edificio(Almacen almacen);
};

#endif // EDIFICIO_H
