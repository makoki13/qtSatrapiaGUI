#include "usuario.h"
#include <iostream>

Usuario::Usuario()
{

}

Usuario::Usuario(
        int id,
        QString nombre,
        TipoItem tipo,
        QString correo_electronico,
        QString clave_acceso,
        int ultimo_acceso,
        bool en_linea,
        TipoEstados tipo_estado) : Item(id)
{
    setID( id );
    setNombre( nombre );
    setTipo( tipo );

    _correo_electronico = correo_electronico;
    _clave_acceso = clave_acceso;
    _ultimo_acceso = ultimo_acceso;
    _en_linea = en_linea;
    _tipo = tipo_estado;
}

int Usuario::crear_usuario(
        QString correo_electronico,
        QString clave_acceso)
{
    setNombre( correo_electronico );
    setTipo( USUARIO );
    set_estado( PENDIENTE );
    set_online();
    _correo_electronico = correo_electronico;
    _clave_acceso = clave_acceso;

    //**TODO persistencia_guardar

    return 0;
}

int Usuario::borrar_usuario()
{
    //**TODO persistencia_borrar

    return 0;
}

void Usuario::set_estado(TipoEstados estado)
{
    _tipo = estado;
}

void Usuario::set_online()
{
    _en_linea = true;
}

void Usuario::set_offline()
{
    _en_linea = false;
}

QString Usuario::get_clave()
{
    return _clave_acceso;
}

void Usuario::set_clave(QString clave)
{
    _clave_acceso = clave;
}

