#ifndef SUPERV_USUARIO_H
#define SUPERV_USUARIO_H

#include <unordered_map>
#include "usuario.h"

class SUPERV_Usuario
{
    static unordered_map<int, Usuario> usuarios;

    static void add_item( Usuario u);
public:
    SUPERV_Usuario();

    /** Rutinas sobre vector */
    static bool add_item(int id);
    static bool quita_item(int id);
    static Usuario get_item(int id);

    /** Rutinas sobre persistencia */
    static bool existe_usuario(QString correo, QString clave);
    static bool existe_usuario_registrado(QString correo);
    static Usuario crea_usuario(QString correo,QString clave);
    static Usuario carga_usuario(QString correo);
    static bool borra_usuario(QString correo);

    /* Rutinas de gestión */
};

#endif // SUPERV_USUARIO_H
