#ifndef ALMACEN_H
#define ALMACEN_H

#include "silo.h"
#include <QList>

class Almacen
{
private:
    QList<Silo*> silos;
public:
    Almacen();

    void addSilo(Silo* silo);
    QList<Silo*> listaSilos();
};

#endif // ALMACEN_H
