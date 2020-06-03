#ifndef RECURSO_H
#define RECURSO_H

#include <QString>

enum TipoRecurso {
    COMIDA = 1,
    MADERA = 2,
    PIEDRA = 3,
    HIERRO = 4,
    ORO = 5,
    POBLACION = 6,
};

class Recurso
{    
public:
    QString nombre;
    TipoRecurso tipo;

    Recurso();
    Recurso(QString nombre, TipoRecurso tipo);

    QString getNombre();
    TipoRecurso getTipo();
};

#endif // RECURSO_H
