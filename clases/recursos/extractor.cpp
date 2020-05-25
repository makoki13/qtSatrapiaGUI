#include <QTimer>

#include "extractor.h"

Extractor::Extractor(Fuente fuente, Silo silo) :
    fuente(fuente.getPosicion(), fuente.getRecurso()) ,
    silo(fuente.getRecurso(), silo.getCapacidad())
{

}

void Extractor::setFuente(Fuente fuente) {
    this->fuente = fuente;
}

void Extractor::setSilo(Silo silo) {
    this->silo = silo;
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

long Extractor::extrae()
{
    QTimer timer;
    QObject::connect(
                &timer,
                &QTimer::timeout,
                this,
                QOverload<>::of(&Extractor::_extraer));

    timer.start(1000);

    return 666;
}
