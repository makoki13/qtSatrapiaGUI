#include <QSqlQuery>
#include <QList>
#include <QVariant>

#include "persistencia_partida.h"
#include "sgbd.h"

Persistencia_Partida::Persistencia_Partida()
{

}

TReturn_Partida Persistencia_Partida::crea(int inicio)
{
    TReturn_Partida t;

    int id = Item::getSiguienteID();

    QString sql =
            "INSERT INTO partida (id, activa, inicio, fin, jugadores) "
            "VALUES (:id, false, :inicio, 0, 0)";
    QSqlQuery query;

    query.prepare(sql);

    query.bindValue(":id", id);
    query.bindValue(":inicio", inicio );

    TRetorno_Ejecuta resultado = SGBD::ejecuta(query);

    QString s = query.executedQuery();

    t.resultado = resultado.resultado;
    t.mensaje = resultado.mensaje;

    Partida p (id, true, 1, 0, 0);

    t.registro = p;

    return t;
}

void Persistencia_Partida::setFin(int partida)
{
    QString sql = "UPDATE partida SET Fin=1 WHERE id=:id";
    QSqlQuery query;

    query.prepare(sql);

    query.bindValue(":id", partida);

    TRetorno_Ejecuta resultado = SGBD::ejecuta(query);
}

TReturn_Partida Persistencia_Partida::estaRegistradoJugador(int partida, int jugador)
{
    TReturn_Partida t;

    QString sql = "SELECT COUNT(*) FROM partidas_jugador WHERE Partida=:partida AND Jugador=:jugador";
    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":partida", partida );
    query.bindValue(":jugador", jugador );

    TRetorno_Consulta datos = SGBD::consulta(query);
    if (datos.filas == 1) {
        int registros = datos.data.first().value(0).toInt();
        t.resultado = ( registros > 0 );
        t.mensaje = "ok";
    }
    else {
        t.resultado = -1;
        t.mensaje = "error";
    }

    return t;
}

TReturn_Partida Persistencia_Partida::addJugador(int partida, int jugador)
{
    TReturn_Partida t = Persistencia_Partida::estaRegistradoJugador( partida, jugador );

    if ( t.resultado == true ) {
        //Poner el estado en "dentro" para esa partida
    }
    else {
        //Registrar usuario
        QString sql = "INSERT INTO partidas_jugador (Partida, Jugador, Estado) VALUES (:partida, :jugador, 1)";
        QSqlQuery query;

        query.prepare(sql);
        query.bindValue(":partida", partida );
        query.bindValue(":jugador", jugador );

        TRetorno_Ejecuta resultado = SGBD::ejecuta(query);
        t.resultado = resultado.resultado;
    }

    return t;
}

/*

void Persistencia_Partida::removeJugador(int partida, int jugador)
{

}
*/

void Persistencia_Partida::setActiva(int partida)
{
    QString sql = "UPDATE partida SET Activa=true WHERE id=:id";
    QSqlQuery query;

    query.prepare(sql);

    query.bindValue(":id", partida);

    TRetorno_Ejecuta resultado = SGBD::ejecuta(query);
}

void Persistencia_Partida::setDesactiva(int partida)
{
    QString sql = "UPDATE partida SET activa=false WHERE id=:id";
    QSqlQuery query;

    query.prepare(sql);

    query.bindValue(":id", partida);

    TRetorno_Ejecuta resultado = SGBD::ejecuta(query);
}

void Persistencia_Partida::borra(int partida)
{
    QString sql = "DELETE FROM partida WHERE id=:id";
    QSqlQuery query;

    query.prepare(sql);

    query.bindValue(":id", partida);

    TRetorno_Ejecuta resultado = SGBD::ejecuta(query);
}

TReturn_Partida Persistencia_Partida::carga(int id)
{
    TReturn_Partida t;

    QString sql = "SELECT Activa,Inicio,Fin,Jugadores FROM partida WHERE Id=:id";
    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":id", id );

    TRetorno_Consulta datos = SGBD::consulta(query);
    if (datos.filas == 1) {
        t.registro.setID(id);
        t.registro.setNombre("");
        int activa = datos.data.first().value(0).toInt();
        if (activa == 1) {
            t.registro.activa();
        }
        else {
            t.registro.desactiva();
        }

        /*
        t.registro.set_inicio(datos.data.first().value(1).toInt());
        t.registro.set_fin(datos.data.first().value(2).toInt());
        t.registro.set_jugadores(datos.data.first().value(3).toInt());
        */
        t.mensaje = "ok";
    }
    else {
        t.resultado = -1;
        t.mensaje = "error";
    }

    return t;

}

TReturn_ListaPartidas Persistencia_Partida::loadListaPartidas()
{
    TReturn_ListaPartidas t;

    QString sql = "SELECT ID,Activa,Inicio,Fin,Jugadores FROM partida";
    QSqlQuery query;

    query.prepare(sql);

    TRetorno_Consulta datos = SGBD::consulta(query);
    if (datos.filas > 0) {
        for (int i = 0; i < datos.filas; ++i) {
            Partida p;

            QList<QVariant> registro = datos.data.at(i);

            p.setID(registro.at(0).toInt());
            p.setNombre("");
            int activa = registro.at(1).toInt();
            if (activa == 1) {
                p.activa();
            }
            else {
                p.desactiva();
            }

            t.registros.insert({p.getID(), p});

            t.mensaje = "ok";
        }
    }
    else {
        t.resultado = -1;
        t.mensaje = "error";
    }

    return t;
}

