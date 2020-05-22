#include "estructura.h"

Estructura::Estructura()
{

}

Estructura::Estructura(Posicion posInicial, bool esMovible, QList<Silo> silos)
{
    this->pos = posInicial;
    this->esMovible = esMovible;
    this->silos = silos;
}
