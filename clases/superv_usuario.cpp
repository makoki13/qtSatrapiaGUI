#include <iostream>

#include "superv_usuario.h"
#include "persistencia_usuario.h"

using namespace std;

unordered_map<int, Usuario> SUPERV_Usuario::usuarios;

SUPERV_Usuario::SUPERV_Usuario()
{

}

/** Rutinas sobre vector */
void SUPERV_Usuario::add_item( Usuario u) {
    usuarios.insert({u.getID(),u});
}

bool SUPERV_Usuario::quita_item(int id) {
    SUPERV_Usuario::usuarios.erase(id);

    return true;
}

Usuario SUPERV_Usuario::get_item(int id) {
    return usuarios[id];
}

/** Rutinas sobre persistencia */
bool SUPERV_Usuario::existe_usuario(QString correo, QString clave)
{        
    TReturn_Usuario resultado;

    resultado = Persistencia_Usuario::existe_usuario(correo, clave);    

    cout << "-0- " << resultado.mensaje.toStdString() << "  " << endl;

    if (resultado.mensaje == "ok" ) return true; else return false;
}

bool SUPERV_Usuario::existe_usuario_registrado(QString correo)
{
    TReturn_Usuario resultado;

    resultado = Persistencia_Usuario::existe_usuario_registrado(correo);

    cout << "-0- " << resultado.mensaje.toStdString() << "  " << endl;

    if (resultado.mensaje == "ok" ) return true; else return false;
}

Usuario SUPERV_Usuario::crea_usuario(QString correo, QString clave)
{
    TReturn_Usuario resultado;

    resultado = Persistencia_Usuario::crea_usuario(Item::getSiguienteID(), correo, clave );
    SUPERV_Usuario::add_item(resultado.registro);

    return resultado.registro;
}


Usuario SUPERV_Usuario::carga_usuario(
        QString correo
        ) {
    TReturn_Usuario resultado;

    resultado = Persistencia_Usuario::carga_usuario( correo );
    SUPERV_Usuario::add_item(resultado.registro);

    return resultado.registro;
}

/** Un poco a lo bruto, vaya */
bool SUPERV_Usuario::borra_usuario(QString correo) {
    Usuario u = SUPERV_Usuario::carga_usuario( correo );
    SUPERV_Usuario::quita_item(u.getID());
    Persistencia_Usuario::borra_usuario(u.getID());

    return true;
}

