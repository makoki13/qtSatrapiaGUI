#include <QTimer>

#include "edificio.h"

Silo Edificio::getSiloDeAlmacen(QString nombreRecurso)
{
    Silo silo;

    QList<Silo> listaSilos = almacen.listaSilos();
    QList<Silo>::Iterator it = listaSilos.begin();
    for ( ; it != listaSilos.constEnd(); ++it ) {
        Silo& silo = *it;
        if (silo.nombreRecurso() == nombreRecurso) {
            return silo;
        }
    }

    return silo;
}

Edificio::Edificio()
{

}

Edificio::Edificio (Almacen almacen)
{
    this->almacen = almacen;
}

void Edificio::addExtractor( Extractor *extractor )
{
    extractores.append(*extractor);
    extractor->extrae();
}

void Edificio::addSiloEnAlmacen(Recurso recurso)
{
    Silo silo(recurso,-1);

    almacen.addSilo(silo);
}

void Edificio::recoge()
{
    QList<Extractor>::Iterator it = extractores.begin();
    for ( ; it != extractores.end(); ++it ) {
        Extractor& extractor = *it;
        long cantidad = extractor.vacia();

        Silo siloDeExtractor = extractor.getSilo();
        Silo siloDeAlmacen = getSiloDeAlmacen( siloDeExtractor.nombreRecurso() );

        siloDeAlmacen.suma(cantidad);
    }
}

void Edificio::recogeRecursos()
{
    QTimer *cronometro = new QTimer();
    connect(cronometro, SIGNAL(timeout()),this,SLOT(recoge()));
    cronometro->start(7000);
}


