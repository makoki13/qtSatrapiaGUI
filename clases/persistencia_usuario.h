#ifndef PERSISTENCIA_USUARIO_H
#define PERSISTENCIA_USUARIO_H

#include <QString>
#include "usuario.h"

using namespace std;

class TReturn_Usuario
{
public:
    int resultado;
    QString mensaje;
    Usuario registro;
};

class Persistencia_Usuario
{
public:
    Persistencia_Usuario();

    static TReturn_Usuario existe_usuario(QString nombre, QString clave);
    static TReturn_Usuario existe_usuario_registrado(QString nombre);
    static TReturn_Usuario crea_usuario(int id, QString nombre, QString clave);
    static TReturn_Usuario carga_usuario(QString nombre);
    static TReturn_Usuario borra_usuario(int id);
};

#endif // PERSISTENCIA_USUARIO_H
