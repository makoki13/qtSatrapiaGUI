#include "residencia.h"
#include "recurso.h"

Residencia::Residencia()
{

}

Residencia::Residencia(Posicion pos)
{
    Almacen almacen = Almacen();
    Silo* silo = new Silo(Recurso("POBLACION",POBLACION) , 5000000);
    almacen.addSilo(silo);
    this->setAlmacen(almacen);

    this->addExtractor(
                new Extractor(
                    Fuente(pos,Recurso("POBLACION",POBLACION),100),
                    *silo,
                    10,
                    5
                    )
                );

     this->start_recoger();
}

void Residencia::addPoblacion(long cantidad)
{
    Silo* silo = this->getSiloDeAlmacen("POBLACION");
    silo->suma(cantidad);
}

void Residencia::restaPoblacion(long cantidad)
{
    this->getSiloDeAlmacen("POBLACION")->resta(cantidad);
}

long Residencia::getPoblacion()
{
    return this->getCantidadEnAlmacen("POBLACION");
}

void Residencia::start_recoger()
{
    estado = EN_MARCHA;
    //this->getExtractor("POBLACION")->extrae();
    this->recogeRecursos();
}

void Residencia::stop_recoger()
{
    estado = PARADO;
    this->getExtractor("POBLACION")->para();
}
