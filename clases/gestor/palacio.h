/**
    El Palacio gestiona los recursos, los edificios y las otras, así como otras variables del juego.
    Los edificios pueden ser:
    Fuera de la ciudad (tienen su propia posicion)
    - Granjas (recurso COMIDA)
    - Serrerias (recurso MADERA)
    - Minas de piedra (recurso PIEDRA), metal (recurso METAL) y oro (recurso ORO)
    Dentro de la ciudad (misma posición)
    - Residencias (Albergan el recurso POBLACION)
    - 1 Cuartel
    - 1 Mercado
    - 1 Almacen donde se almacenaran los recursos
    - 1 Embajada
*/

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

