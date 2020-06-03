#include <iostream>

#include "palacio.h"
#include "../recursos/residencia.h"

Palacio::Palacio()
{
    
}

Palacio* Palacio::creaPalacio()
{
    Palacio *nuevo = new Palacio;

    nuevo->granjas = QVector<Edificio*>();
    nuevo->serrerias = QVector<Edificio*>();
    nuevo->minasPiedra = QVector<Edificio*>();
    nuevo->minasHierro = QVector<Edificio*>();
    nuevo->minasOro = QVector<Edificio*>();

    nuevo->residencias = new Residencia();

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
