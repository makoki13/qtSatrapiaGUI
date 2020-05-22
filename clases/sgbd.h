//TODO analizar valores de error
#ifndef SGBD_H
#define SGBD_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QList>
#include <QVariant>

using namespace std;

class TRetorno_Ejecuta {
public:
    //Vale -1 si hay error. 0 si no lo hay
    int resultado;
    //Un valor query.lastError() cuando resultado es -1
    QString mensaje;
    //query.numRowsAffected
    int filas;
};

class TRetorno_Consulta {
public:
    //Vale -1 si hay error. 0 si no lo hay
    int resultado;
    //Un valor query.lastError() cuando resultado es -1
    QString mensaje;
    //Numero de filas de la tabla
    int filas;
    //Tabla de datos
    QList<QList<QVariant>> data;
};

class SGBD
{
    void recrea_tablas();
public:
    SGBD();

    static TRetorno_Ejecuta ejecuta(QSqlQuery query);
    static TRetorno_Consulta consulta(QSqlQuery query);
};

#endif // SGBD_H
