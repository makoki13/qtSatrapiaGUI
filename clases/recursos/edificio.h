#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <QList>

#include "estructura.h"
#include "extractor.h"
#include "almacen.h"

enum TipoEstadosEdificio {
    EN_CONSTRUCCION = 1, TERMINADO = 2, ABANDONADO = 3
};

class Edificio : Estructura
{
private:    
    QList<Extractor> extractores;
    Almacen almacen;
public:
    Edificio();
    Edificio( Almacen almacen );
};

#endif // EDIFICIO_H
