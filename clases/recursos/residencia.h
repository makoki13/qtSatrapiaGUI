#ifndef RESIDENCIA_H
#define RESIDENCIA_H

#include "edificio.h"

class Residencia : Edificio
{
public:
    Residencia();

    void addPoblacion(long cantidad);
    void restaPoblacion(long cantidad);
    long getPoblacion();
};

#endif // RESIDENCIA_H
