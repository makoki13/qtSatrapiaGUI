#ifndef POSICION_H
#define POSICION_H


class Posicion
{
public:
    Posicion();
    Posicion(long x, long y, long z = 0);

    long x, y, z = 0;
};

#endif // POSICION_H
