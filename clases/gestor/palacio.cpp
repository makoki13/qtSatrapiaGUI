#include <iostream>

#include "palacio.h"
#include "../recursos/residencia.h"

Palacio::Palacio()
{
    
}

Palacio* Palacio::creaPalacio(Posicion pos)
{
    Palacio *nuevo = new Palacio;

    nuevo->granjas = QVector<Edificio*>();
    nuevo->serrerias = QVector<Edificio*>();
    nuevo->minasPiedra = QVector<Edificio*>();
    nuevo->minasHierro = QVector<Edificio*>();
    nuevo->minasOro = QVector<Edificio*>();

    nuevo->residencias = new Residencia(pos);
    //nuevo->residencias->start_recoger();

    nuevo->jefe = "MAKOKI";

    return nuevo;
}

long Palacio::getPoblacion()
{
    return this->residencias->getPoblacion();
}

void Palacio::addPoblacion(long cantidad) {
    this->residencias->addPoblacion(cantidad);
}

void Palacio::restaPoblacion(long cantidad) {
    this->residencias->restaPoblacion(cantidad);
}

QVector<Edificio *> Palacio::listaGranjas()
{
    return this->granjas;
}
