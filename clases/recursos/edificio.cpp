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

    /*
    QList<Silo>::Iterator it = listaSilos.begin();
    for ( ; it != listaSilos.constEnd(); ++it ) {        
 q       if (it->nombreRecurso() == nombreRecurso) {
            return it;
        }
    }
    */

    return nullptr;
}

Extractor *Edificio::getExtractor(QString nombreRecurso)
{
    for(int i = 0; i<extractores.size(); i++){
        if (extractores[i]->getSilo().nombreRecurso() == nombreRecurso) {
            return extractores[i];
        }
    }
    //TODO recorrer vector buscando el extractor del recurso
    return nullptr;
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

    /*
    extractor.setFuente(fuente);
    extractor.setSilo(siloExtractor);
    extractor.setCantidadPorExtraccion(10);
    extractor.setTiempoPorExtraccion(5);
    */

    extractores.append(new Extractor(fuente,siloExtractor,10,5) );
}

void Edificio::addSiloEnAlmacen(Recurso recurso)
{
    Silo* silo = new Silo(recurso,-1);

    almacen.addSilo(silo);
}

void Edificio::recoge()
{
    //QVector<Extractor>::Iterator it = *extractores.begin();

    /*
    for ( ; it != *extractores.end(); ++it ) {
        cout << extractores.size() << endl;
        Extractor& extractor = *it;
        long cantidad = extractor.vacia();

        Silo siloDeExtractor = extractor.getSilo();
        Silo siloDeAlmacen = getSiloDeAlmacen( siloDeExtractor.nombreRecurso() );

        siloDeAlmacen.suma(cantidad);
    }
    */

    QVectorIterator<Extractor*> it(extractores);
     while (it.hasNext()) {
         Extractor *e = it.next();
         long cantidad = e->vacia();

         Silo siloDeExtractor = e->getSilo();
         Silo* siloDeAlmacen = getSiloDeAlmacen( siloDeExtractor.nombreRecurso() );

         siloDeAlmacen->suma(cantidad);

         qDebug() << getCantidadEnAlmacen("ORO");
     }
}

void Edificio::recogeRecursos()
{
    //QTimer *cronometro = new QTimer();
    //connect(cronometro, SIGNAL(timeout()),this,SLOT(recoge()));
    cronometro->start(3000);
}

long Edificio::getCantidadEnAlmacen(QString nombreRecurso)
{
    Silo* siloDeAlmacen = getSiloDeAlmacen( nombreRecurso );
    return siloDeAlmacen->getCantidad();
}


