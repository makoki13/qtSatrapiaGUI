#ifndef SUPERV_PARTIDA_H
#define SUPERV_PARTIDA_H

#include <unordered_map>
#include "partida.h"

class SUPERV_Partida
{
    static unordered_map<int, Partida> partidas;

public:
    SUPERV_Partida();

    static void loadPartidas();

    /** Rutinas sobre vector */
    static void add_item(Partida p);
    static void quita_item(int id);
    static Partida get_item(int id);

    static Partida nueva();

    static void abre(int id);
    static void cierra(int id);
    static void borra(int id);

    static unordered_map<int, Partida> lista();

    static void addJugador(int partida, int jugador);
    static void quitaJugador(int partida, int jugador);
};

#endif // SUPERV_PARTIDA_H
