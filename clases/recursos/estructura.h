#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <QObject>
#include <QList>

#include "../posicion.h"
#include "silo.h"

class Estructura
{    
private:
    Posicion pos;
    bool esMovible;
    QList<Silo> silos;
public:
    Estructura();
    Estructura(Posicion posInicial, bool esMovible, QList<Silo> silos);
};

#endif // ESTRUCTURA_H
