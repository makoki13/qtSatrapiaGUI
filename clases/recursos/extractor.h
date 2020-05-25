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
    //TODO: Debe de haber un constructor que acepte una fuente.
    Extractor();
    Extractor(Fuente fuente, Silo silo);

    void setFuente(Fuente f);
    void setSilo(Silo s);

    void setCantidadPorExtraccion(long cantidad);
    void setTiempoPorExtraccion(long segundos);

    void setTope(long tope);

    long getCantidadSilo();

    long extrae();
};

#endif // EXTRACTOR_H
