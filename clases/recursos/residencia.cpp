#include "residencia.h"
#include "recurso.h"

Residencia::Residencia()
{

}

Residencia::Residencia(Posicion pos, long cantidadExtraccion, long tiempoExtraccion)
{
    Almacen almacen = Almacen();
    Silo* silo = new Silo(Recurso("POBLACION",POBLACION) , 5000000);
    almacen.addSilo(silo);
    this->setAlmacen(almacen);

    this->addExtractor(
                new Extractor(
                    Fuente(pos,Recurso("POBLACION",POBLACION),100),
                    *silo,
                    cantidadExtraccion,
                    tiempoExtraccion
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
    this->recogeRecursos(this->getTiempoPorExtraccion("POBLACION"));
}

void Residencia::stop_recoger()
{
    estado = PARADO;
    this->getExtractor("POBLACION")->para();
}

void Residencia::setCantidadPorExtraccion(long cantidad)
{
    //TODO
    //Si el valor es negativo parar el extractor y eliminar poblacion periódicamente
    Edificio::setCantidadPorExtraccion("POBLACION",cantidad);
}


/*
void Residencia::setTiempoPorExtraccion(long cantidad)
{
    //Edificio::setTiempoPorExtraccion(cantidad);
}
*/
