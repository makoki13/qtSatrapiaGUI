#include <iostream>
#include <QTimer>
#include <QDebug>

#include "edificio.h"

using namespace std;

Silo* Edificio::getSiloDeAlmacen(QString nombreRecurso)
{    
    QList<Silo*> listaSilos = almacen.listaSilos();

    for(int i = 0; i<listaSilos.size(); i++){
        if (listaSilos[i]->nombreRecurso() == nombreRecurso) {
            return listaSilos[i];
        }
    }

    return nullptr;
}

Extractor *Edificio::getExtractor(QString nombreRecurso)
{
    for(int i = 0; i<extractores.size(); i++){
        if (extractores[i]->getSilo().nombreRecurso() == nombreRecurso) {
            return extractores[i];
        }
    }

    return nullptr;
}

void Edificio::setCantidadPorExtraccion(QString nombreRecurso, long cantidad)
{
    for(int i = 0; i<extractores.size(); i++){
        if (extractores[i]->getSilo().nombreRecurso() == nombreRecurso) {
            extractores[i]->setCantidadPorExtraccion(cantidad);
        }
    }
}

long Edificio::getCantidadPorExtraccion(QString nombreRecurso)
{
    for(int i = 0; i<extractores.size(); i++){
        if (extractores[i]->getSilo().nombreRecurso() == nombreRecurso) {
            return extractores[i]->getCantidadPorExtraccion();
        }
    }

    return -1;
}

long Edificio::getTiempoPorExtraccion(QString nombreRecurso)
{
    for(int i = 0; i<extractores.size(); i++){
        if (extractores[i]->getSilo().nombreRecurso() == nombreRecurso) {
            return extractores[i]->getTiempoPorExtraccion();
        }
    }

    return -1;
}

Edificio::Edificio()
{
    connect(cronometro, SIGNAL(timeout()),this,SLOT(recoge()));
}

Edificio::Edificio (Almacen almacen)
{
    this->almacen = almacen;
    connect(cronometro, SIGNAL(timeout()),this,SLOT(recoge()));
}

void Edificio::setAlmacen(Almacen almacen)
{
    this->almacen = almacen;
}

void Edificio::addExtractor( Extractor *extractor )
{
    extractores.append(extractor);
    extractor->extrae();
}

void Edificio::addExtractor_new()
{
    Fuente fuente(this->pos,Recurso("ORO",ORO), 10000);
   Silo siloExtractor(fuente.getRecurso(),1000);

    extractores.append(new Extractor(fuente,siloExtractor,10,5) );
}

void Edificio::addSiloEnAlmacen(Recurso recurso)
{
    Silo* silo = new Silo(recurso,-1);

    almacen.addSilo(silo);
}

void Edificio::recoge()
{    
    QVectorIterator<Extractor*> it(extractores);
     while (it.hasNext()) {
         Extractor *e = it.next();
         long cantidad = e->vacia();
         QString nombreRecurso;

         Silo siloDeExtractor = e->getSilo();
         nombreRecurso = siloDeExtractor.nombreRecurso();
         Silo* siloDeAlmacen = getSiloDeAlmacen( nombreRecurso );

         siloDeAlmacen->suma(cantidad);
     }
}

void Edificio::recogeRecursos(long tiempoTimer)
{
    cronometro->start(tiempoTimer);
}

long Edificio::getCantidadEnAlmacen(QString nombreRecurso)
{
    Silo* siloDeAlmacen = getSiloDeAlmacen( nombreRecurso );
    return siloDeAlmacen->getCantidad();
}


