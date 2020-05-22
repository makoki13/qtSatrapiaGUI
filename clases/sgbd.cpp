#include "sgbd.h"

#include <iostream>

#include <QSqlError>

using namespace std;

void SGBD::recrea_tablas() {
    QSqlQuery query;

    query.prepare("DROP TABLE partida");
    ejecuta(query);
    query.prepare("CREATE TABLE partida(id int primary key, activa bool, inicio int, fin int, jugadores int default 0)");
    ejecuta(query);
}

SGBD::SGBD()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("satrapia");

    if(db.open()) {
        cout << "Conexion a [SQLITE] preparada." << endl << endl;
    }

    //SGBD::recrea_tablas();
}

QString getLastExecutedQuery(const QSqlQuery& query)
{
    QString str = query.lastQuery();
    QMapIterator<QString, QVariant> it(query.boundValues());

    it.toBack();

    while (it.hasPrevious())
    {
        it.previous();
        str.replace(it.key(),it.value().toString());
    }
    return str;
}

TRetorno_Ejecuta SGBD::ejecuta(QSqlQuery query)
{    
    TRetorno_Ejecuta resultado;

    resultado.resultado = 0;
    resultado.mensaje = "";
    resultado.filas = 0;

    if(!query.exec())
    {
        resultado.resultado = -1;
        resultado.mensaje = query.lastError().text() +
                " " + query.executedQuery();
    }
    else
    {
        resultado.resultado = 0;
        resultado.filas = query.numRowsAffected();
        resultado.mensaje = "OK " + query.executedQuery();
    }

    return resultado;
}

TRetorno_Consulta SGBD::consulta(QSqlQuery query)
{
    TRetorno_Consulta resConsulta;

    if(!query.exec()) {
        resConsulta.resultado = -1;
        resConsulta.mensaje = query.lastError().text() + " " + query.executedQuery();
        resConsulta.filas = 0;
    }
    else {

        cout << getLastExecutedQuery(query).toStdString() << endl;

        resConsulta.resultado = 0;
        resConsulta.mensaje = "OK " + query.executedQuery();

        QSqlRecord rec = query.record();
        int numColumnas = rec.count();

        resConsulta.filas = 0;
        while(query.next()) {
            resConsulta.filas++;            
            QList<QVariant> registro;
            for (int i=0; i < numColumnas; i++) {                
                registro.append(query.value(i));                
            }
            resConsulta.data.append(registro);
         }
    }

    return resConsulta;
}
