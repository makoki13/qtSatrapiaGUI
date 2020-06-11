#ifndef RESIDENCIA_H
#define RESIDENCIA_H

#include <QObject>
#include <QTimer>

#include "edificio.h"

class Residencia : Edificio
{
private:
    QTimer *cronometro = new QTimer(this);

    TipoEstadosExtractor estado;
    Posicion pos;
public:
    Residencia();
    Residencia(Posicion pos, long cantidadExtraccion, long tiempoExtraccion);

    void addPoblacion(long cantidad);
    void restaPoblacion(long cantidad);
    long getPoblacion();

    void start_recoger();
    void stop_recoger();

    void setCantidadPorExtraccion(long cantidad);
    //void setTiempoPorExtraccion(long cantidad);

};

#endif // RESIDENCIA_H
