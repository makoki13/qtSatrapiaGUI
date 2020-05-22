#include "recursonatural.h"


RecursoNatural::RecursoNatural(QString nombre, long tope) : Recurso(nombre, tope)
{

}

Comida::Comida() : RecursoNatural("COMIDA") {
    this->cantidad = 0;
}

Madera::Madera() : RecursoNatural("MADERA") {
    this->cantidad = 0;
}

Piedra::Piedra() : RecursoNatural("PIEDRA") {
    this->cantidad = 0;
}

Metal::Metal() : RecursoNatural("METAL") {
    this->cantidad = 0;
}

Oro::Oro() : RecursoNatural("ORO") {
    this->cantidad = 0;
}


