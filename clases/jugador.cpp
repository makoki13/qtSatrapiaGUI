#include "jugador.h"

Jugador::Jugador(Partida p, Usuario u) : Usuario (
    u.getID(),
    u.getNombre(),
    u.getTipo(),
    u.getNombre(),
    u.get_clave(),
    0,
    true,
    ACTIVO)
{
    _partida = p;
}

bool Jugador::setActivo() {
    return true;
}

bool Jugador::setNoActivo() {
    return true;
}

bool Jugador::setEnLinea() {
    return true;
}

bool Jugador::setFueraDeLinea() {
    return true;
}
