#include <QSet>

#include "item.h"
#include "jugador.h"

#ifndef PARTIDA_H
#define PARTIDA_H

class Partida : public Item
{
    bool es_activa;
    int inicio;
    int fin;
    int dias;
    int jugadores;

    QSet<int> listaJugadores;

public:
    Partida();
    Partida(
        int id,
        bool activa,
        int inicio,
        int fin,
        int jugadores);

    int crear();
    void setFin();
    void recalculaDias();
    void incrementaJugadores();
    void decrementaJugadores();

    void activa();
    void desactiva();

    bool esActiva();
    int getJugadores();

    void addJugador(int jugador);
    void quitaJugador(int jugador);
};

#endif // PARTIDA_H
