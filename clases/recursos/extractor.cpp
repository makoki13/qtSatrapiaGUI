#include "extractor.h"

Extractor::Extractor()
{
    //connect(cronometro, SIGNAL(timeout()),this,SLOT(_extraer()));
}

Extractor::Extractor(Fuente fuente, Silo silo) :
    fuente(fuente.getPosicion(), fuente.getRecurso(), 0) ,
    silo(fuente.getRecurso(), silo.getCapacidad())
{
    connect(cronometro, SIGNAL(timeout()),this,SLOT(_extraer()));
}

Extractor::Extractor(Fuente fuente, Silo silo, long cantidadPorExtraccion, long tiempoPorExtraccion) :
    fuente(fuente.getPosicion(), fuente.getRecurso(), 0) ,
    silo(fuente.getRecurso(), silo.getCapacidad())
{
    setCantidadPorExtraccion(cantidadPorExtraccion);
    setTiempoPorExtraccion(tiempoPorExtraccion);
}

void Extractor::setFuente(Fuente fuente) {
    this->fuente = fuente;
}

void Extractor::setSilo(Silo silo) {
    this->silo = silo;
}

Silo Extractor::getSilo()
{
    return silo;
}

void Extractor::setCantidadPorExtraccion(long cantidad)
{
    if (cantidad > this->silo.getCapacidad()) cantidad = this->silo.getCapacidad();
    this->cantidadPorExtraccion = cantidad;
}

void Extractor::setTiempoPorExtraccion(long segundos)
{
    this->tiempoPorExtraccion = segundos;
}

void Extractor::setTope(long tope)
{
    this->silo.setCapacidad(tope);
}

long Extractor::getCantidadSilo()
{
    return silo.getCantidad();
}

void Extractor::_extraer()
{
   long cantidad = this->fuente.extraer(cantidadPorExtraccion);
   if (cantidad > 0) this->silo.suma(cantidad);
}

void Extractor::extrae()
{
    estado = EN_MARCHA;
    cronometro->start(1000);
}

void Extractor::para()
{
    estado = PARADO;
    cronometro->stop();
}

long Extractor::saca(long cantidad)
{
    long cantidadActualEnSilo = this->silo.getCantidad();
    if (cantidad > cantidadActualEnSilo) cantidad = cantidadActualEnSilo;
    this->silo.resta(cantidad);
    return cantidad;
}

long Extractor::vacia()
{
    long cantidadActualEnSilo = this->silo.getCantidad();
    this->silo.resta(cantidadActualEnSilo);
    return cantidadActualEnSilo;
}

TipoEstadosExtractor Extractor::getEstado()
{
    return this->estado;
}
