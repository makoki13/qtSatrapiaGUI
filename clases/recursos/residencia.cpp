#include "residencia.h"
#include "recurso.h"

Residencia::Residencia()
{
    Almacen almacen = Almacen();
    Silo silo = Silo(Recurso("POBLACION",POBLACION) , 5000000);
    almacen.addSilo(silo);
    this->setAlmacen(almacen);
}

void Residencia::addPoblacion(long cantidad)
{
    this->getSiloDeAlmacen("POBLACION").suma(cantidad);
}

void Residencia::restaPoblacion(long cantidad)
{
    this->getSiloDeAlmacen("POBLACION").resta(cantidad);
}

long Residencia::getPoblacion()
{
    return this->getCantidadEnAlmacen("POBLACION");
}
