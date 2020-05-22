#ifndef ITEM_H
#define ITEM_H

#include <QString>

using namespace std;

enum TipoItem {
    SIN_DEFINIR,
    USUARIO, JUGADOR, PARTIDA, REGION, TERRITORIO, CIVILIZACION, EDIFICIO, CONSEJERO,
    RECURSO, ALMACEN, EXTRACTOR, FUENTE, EJERCITO, INVESTIGACION, VIAJE, OPERACION
};

class Item
{
    static int siguiente_id;
protected:
    int _id;
    TipoItem _tipo;
    QString _nombre;
    bool _persistente;

public:
    //Pone siguiente_id al valor ultimo e incrementa en 1
    static void inicializa();
    //Devuelve el siguiente_id al valor ultimo
    static int getSiguienteID();
    static int getActualID();

    //Crea un item vacio con el siguiente ID libre.
    Item();
    //Crea un item vacio con un ID especifico.
    Item(int id);

    void setID( int id );
    int getID();

    void setTipo( TipoItem tipo);
    TipoItem getTipo();

    void setNombre( QString n );
    QString getNombre();

    //Pendiente de analizar
    void setPersistente( bool valor );
    bool esPersistente();
};

enum SubtipoItem_CIVILIZACION {
    TRIBU, SATRAPIA, IMPERIO
};

enum SubtipoItem_EDIFICIO {
    PALACIO, MERCADO, SILOS, ACADEMIA, CUARTEL, EMBAJADA, TABERNA, IGLESIA
};

enum SubtipoItem_CONSEJERO {
    ECONOMICO, MILITAR, DIPLOMATICO
};

enum SubtipoItem_RECURSO {
    COMIDA, MADERA, PIEDRA, METAL, ORO, JOYAS
};

enum SubtipoItem_EJERCITO {
    INFANTERIA, CABALLERIA, CARRO, ASEDIO, OFICIAL, ESPIA
};

enum SubtipoItem_EJERCITO_INFANTERIA {
    HONDERO, LANCERO, ESPADA, ARQUERO
};

enum SubtipoItem_EJERCITO_CABALLERIA {
    CABALLERO
};

enum SubtipoItem_EJERCITO_CARRO {
    LIGERO, PESADO
};

enum SubtipoItem_EJERCITO_ASALTO {
    ARIETE, ONAGRO
};

enum SubtipoItem_EJERCITO_OFICIAL {
    CAPITAN, CORONEL, GENERAL
};

enum SubtipoItem_OPERACION {
    TRANSACCION, ATAQUE, FORTIFICACION, ASENTAMIENTO, MISION
};

enum SubtipoItem_ESPIA {
    LEAL, TRAIDOR
};

#endif // ITEM_H

