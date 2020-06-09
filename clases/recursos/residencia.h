#ifndef RESIDENCIA_H
#define RESIDENCIA_H

#include <QObject>
#include <QTimer>

#include "edificio.h"

class Residencia : Edificio
{
private:
    long cantidadPorExtraccion = 100;
    long tiempoPorExtraccion = 1;

    QTimer *cronometro = new QTimer(this);

    TipoEstadosExtractor estado;
    Posicion pos;
public:
    Residencia();
    Residencia(Posicion pos);

    void addPoblacion(long cantidad);
    void restaPoblacion(long cantidad);
    long getPoblacion();

    void start_recoger();
    void stop_recoger();

};

#endif // RESIDENCIA_H
