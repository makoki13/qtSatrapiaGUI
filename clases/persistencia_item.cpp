#include <QString>
#include <QSqlQuery>

#include "persistencia_item.h"
#include "sgbd.h"

Persistencia_Item::Persistencia_Item()
{

}

int Persistencia_Item::getUltimoItemActual()
{
    //TODO cambiar a tabla de parametros.
    QString sql = "SELECT valor_entero FROM parametros WHERE clave='ITEM'";
    QSqlQuery query;

    int ultimo_id;

    query.prepare(sql);

    TRetorno_Consulta datos = SGBD::consulta(query);
    if (datos.filas == 1) {
        ultimo_id = datos.data.first().value(0).toInt();
    }
    else {
        ultimo_id = 0;
    }

    return ultimo_id;
}

void Persistencia_Item::setUltimoItemActual(int valor)
{
    QString sql = "UPDATE parametros SET valor_entero = :valor WHERE clave='ITEM'";
    QSqlQuery query;

    query.prepare(sql);

    query.bindValue(":valor", valor);

    TRetorno_Ejecuta resultado = SGBD::ejecuta(query);
}
