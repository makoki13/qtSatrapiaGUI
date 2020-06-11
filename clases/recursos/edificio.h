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

protected:
    //long cantidadPorExtraccion = 5;
    //long tiempoPorExtraccion = 3;

public:
    Edificio();
    Edificio( Almacen almacen );

    void setAlmacen( Almacen almacen );

    void addExtractor( Extractor *extractor );
    void addExtractor_new();
    void addSiloEnAlmacen(Recurso recurso);    
    void recogeRecursos(long tiempoTimer);

    long getCantidadEnAlmacen(QString nombreRecurso);

    Silo* getSiloDeAlmacen(QString nombreRecurso);

    Extractor* getExtractor(QString nombreRecurso);

    void setCantidadPorExtraccion(QString nombreRecurso, long cantidad);
    long getCantidadPorExtraccion(QString nombreRecurso);
    long getTiempoPorExtraccion(QString nombreRecurso);

public slots:
    void recoge();
};

#endif // EDIFICIO_H
