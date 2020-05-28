#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <QObject>
#include <QTimer>

#include "fuente.h"
#include "silo.h"

enum TipoEstadosExtractor {
    PARADO = 0, EN_MARCHA = 1
};

class Extractor : QObject
{

    Q_OBJECT

private:
    Fuente fuente;
    Silo silo;
    long cantidadPorExtraccion;
    long tiempoPorExtraccion;
    QTimer *cronometro = new QTimer(this);

    TipoEstadosExtractor estado;

public slots:
    void _extraer();

public:
    //TODO: Debe de haber un constructor que acepte una fuente.
    Extractor();
    Extractor(Fuente fuente, Silo silo);

    void setFuente(Fuente f);
    void setSilo(Silo s);
    Silo getSilo();

    void setCantidadPorExtraccion(long cantidad);
    void setTiempoPorExtraccion(long segundos);

    void setTope(long tope);

    long getCantidadSilo();

    void extrae();
    void para();

    long saca(long cantidad);
    long vacia();

    TipoEstadosExtractor getEstado();
};

#endif // EXTRACTOR_H
