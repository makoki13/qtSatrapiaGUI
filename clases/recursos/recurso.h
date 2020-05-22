#ifndef RECURSO_H
#define RECURSO_H

#include <QString>


class Recurso
{
private:
    long tope = -1; //Sin tope

public:
    Recurso(QString nombre, long tope = -1);

    QString nombre;
    long cantidad;

    long getCantidad();
    long setCantidad(long cantidad);
    void sumaCantidad(long cantidad );
    long extraeCantidad(long cantidad );

    void setTope(long tope);
};

#endif // RECURSO_H
