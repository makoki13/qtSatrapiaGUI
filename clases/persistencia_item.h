#ifndef PERSISTENCIA_ITEM_H
#define PERSISTENCIA_ITEM_H


class Persistencia_Item
{
public:
    Persistencia_Item();

    //Para inicializar la variable estatica siguiente_id
    static int getUltimoItemActual();
    static void setUltimoItemActual( int valor );
};

#endif // PERSISTENCIA_ITEM_H
