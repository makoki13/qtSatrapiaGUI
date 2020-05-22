#ifndef JUGADOR_H
#define JUGADOR_H

#include "usuario.h"
#include "partida.h"

class Jugador: public Usuario
{
    Partida _partida;
    bool _activo;
    bool _en_linea;
public:
    Jugador(Partida p, Usuario u);

    bool setActivo();
    bool setNoActivo();
    bool setEnLinea();
    bool setFueraDeLinea();
};

#endif // JUGADOR_H
