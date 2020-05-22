#include <QTimer>

#include "extractor.h"

Extractor::Extractor(Posicion p, Recurso r, long capacidad) : fuente(p, r) , silo(r, capacidad)
{

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
