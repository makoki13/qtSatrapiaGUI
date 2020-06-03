#ifndef PALACIO_H
#define PALACIO_H

#include <QString>

#include "../recursos/edificio.h"
#include "../recursos/residencia.h"

using namespace std;

class Palacio
{

private:
    QVector<Edificio*> granjas;
    QVector<Edificio*> serrerias;
    QVector<Edificio*> minasPiedra;
    QVector<Edificio*> minasHierro;
    QVector<Edificio*> minasOro;

    Residencia *residencias;
    Edificio cuartel;
    Edificio mercado;
    Edificio almacen;
    Edificio embajada;
    
protected:
    

public:
    
    Palacio();

    Edificio crea_granja();
    static Palacio* creaPalacio();

    long getPoblacion();
    void addPoblacion(long cantidad);
    void restaPoblacion(long cantidad);
   
};

#endif // PALACIO_H

