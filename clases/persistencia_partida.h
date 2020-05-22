#ifndef PERSISTENCIA_PARTIDA_H
#define PERSISTENCIA_PARTIDA_H

#include <unordered_map>

#include "partida.h"

enum TipoEstadoJugador {
    SIN_ESTADO_JUGADOR = -1, FUERA = 0, DENTRO = 1, ABANDONO = 2
};


class TReturn_Partida
{
public:
    int resultado;
    QString mensaje;
    Partida registro;
};

class TReturn_ListaPartidas
{
public:
    int resultado;
    QString mensaje;
    unordered_map<int, Partida> registros;
};


class Persistencia_Partida
{
public:
    Persistencia_Partida();

    static TReturn_Partida crea(int inicio);
    static void setFin(int partida);
    static TReturn_Partida estaRegistradoJugador(int partida, int jugador);
    TReturn_Partida addJugador(int partida, int jugador);
    //void removeJugador(int partida, int jugador);  TODO Jugador
    static void setActiva(int partida);
    static void setDesactiva(int partida);
    static void borra(int partida);

    static TReturn_Partida carga(int id);
    static TReturn_ListaPartidas loadListaPartidas();
};

#endif // PERSISTENCIA_PARTIDA_H
