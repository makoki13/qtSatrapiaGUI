#include <iostream>

#include "item.h"
#include "persistencia_item.h"

#ifndef GLOBAL_SIGUIENTE
#define GLOBAL_SIGUIENTE
int Item::siguiente_id = -1;
#endif

void Item::inicializa()
{    
    siguiente_id = Persistencia_Item::getUltimoItemActual();
}

int Item::getSiguienteID()
{
    siguiente_id++;
    Persistencia_Item::setUltimoItemActual(siguiente_id);
    return siguiente_id;
}

int Item::getActualID()
{
    return siguiente_id;
}

Item::Item()
{
    _id = -1;
    _nombre = "nombre""";
    _tipo = SIN_DEFINIR;
    _persistente = false;
}

Item::Item(int id)
{
    _id = id;

    _nombre = "nombre""";
    _tipo = SIN_DEFINIR;
    _persistente = false;
}

void Item::setID(int id)
{
    _id = id;
}

int Item::getID()
{
    if (_id == -1) return -1;
    return _id;
}

void Item::setTipo(TipoItem tipo)
{
    _tipo = tipo;
}

TipoItem Item::getTipo()
{
    return _tipo;
}

void Item::setNombre(QString n)
{
    _nombre = n;
}

QString Item::getNombre()
{
    if (_nombre == "") return "";
    return _nombre;
}

void Item::setPersistente(bool valor)
{
    _persistente = valor;
}

bool Item::esPersistente()
{
    return _persistente;
}
