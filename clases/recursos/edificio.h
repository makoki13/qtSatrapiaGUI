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

class Edificio : public QObject , Estructura
{    

    Q_OBJECT

private:    
    QVector<Extractor*> extractores;
    Almacen almacen;

    QTimer *cronometro = new QTimer(this);

public:
    Edificio();
    Edificio( Almacen almacen );

    void setAlmacen( Almacen almacen );

    void addExtractor( Extractor *extractor );
    void addExtractor_new();
    void addSiloEnAlmacen(Recurso recurso);    
    void recogeRecursos();

    long getCantidadEnAlmacen(QString nombreRecurso);

    Silo* getSiloDeAlmacen(QString nombreRecurso);

    Extractor* getExtractor(QString nombreRecurso);

public slots:
    void recoge();
};

#endif // EDIFICIO_H
