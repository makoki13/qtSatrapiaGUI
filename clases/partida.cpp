#include "partida.h"
#include "jugador.h"

Partida::Partida()
{
    jugadores = 0;
}

Partida::Partida(
    int id,
    bool esActiva,
    int fechaInicio,
    int fechaFin,
    int numJugadores) : Item(id)
{
    if (esActiva == true) activa(); else desactiva();
    inicio = fechaInicio;
    fin = fechaFin;
    jugadores = numJugadores;
}

int Partida::crear()
{
    return 0;
}

void Partida::setFin()
{

}

void Partida::recalculaDias()
{

}

void Partida::incrementaJugadores()
{
    jugadores++;
}

void Partida::decrementaJugadores()
{
    jugadores--;
}

void Partida::activa()
{
    es_activa = true;
}

void Partida::desactiva()
{
    es_activa = false;
}

bool Partida::esActiva()
{
    return es_activa;
}

int Partida::getJugadores()
{
    return jugadores;
}

void Partida::addJugador(int jugador)
{
    listaJugadores.insert(jugador);
    incrementaJugadores();
}

void Partida::quitaJugador(int jugador)
{
    listaJugadores.remove(jugador);
}
