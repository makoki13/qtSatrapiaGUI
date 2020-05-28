#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <QObject>
#include <QList>

#include "estructura.h"
#include "extractor.h"
#include "almacen.h"

enum TipoEstadosEdificio {
    EN_CONSTRUCCION = 1, TERMINADO = 2, ABANDONADO = 3
};

class Edificio : Estructura, public QObject
{    

    Q_OBJECT

private:    
    QList<Extractor> extractores;
    Almacen almacen;

    Silo getSiloDeAlmacen(QString nombreRecurso);
public:
    Edificio();
    Edificio( Almacen almacen );

    void addExtractor( Extractor *extractor );
    void addSiloEnAlmacen(Recurso recurso);
    void recoge();

    void recogeRecursos();
};

#endif // EDIFICIO_H
