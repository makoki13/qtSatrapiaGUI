#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <QObject>

#include "fuente.h"
#include "silo.h"

class Extractor : public QObject
{
    Q_OBJECT;
private:
    Fuente fuente;
    Silo silo;
    long cantidadPorExtraccion;
    long tiempoPorExtraccion;

public slots:
    void _extraer();

public:
    Extractor(Posicion p, Recurso r, long capacidad);

    long extrae();
};

#endif // EXTRACTOR_H
