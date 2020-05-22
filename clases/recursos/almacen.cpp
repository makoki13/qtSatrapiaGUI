#include "almacen.h"

Almacen::Almacen()
{

}

void Almacen::addSilo(Silo silo)
{
   this->silos.insert(this->silos.count(),silo);
}
