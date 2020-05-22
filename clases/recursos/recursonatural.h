#ifndef RECURSONATURAL_H
#define RECURSONATURAL_H

#include "recurso.h"

class RecursoNatural : public Recurso
{
public:
    RecursoNatural(QString nombre, long tope = -1);
};

class Comida : public RecursoNatural {
    Comida();
};

class Madera : public RecursoNatural {
    Madera();
};

class Piedra : public RecursoNatural {
    Piedra();
};

class Metal : public RecursoNatural {
    Metal();
};

class Oro : public RecursoNatural {
    Oro();
};

#endif // RECURSONATURAL_H
