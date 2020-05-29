#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <QObject>
#include <QList>

#include "../posicion.h"
#include "silo.h"

class Estructura
{    
private:    
    bool esMovible;
    QList<Silo> silos;
protected:
    Posicion pos;
public:
    Estructura();
    Estructura(Posicion posInicial, bool esMovible, QList<Silo> silos);
};

#endif // ESTRUCTURA_H
