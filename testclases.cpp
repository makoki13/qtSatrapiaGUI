#include <iostream>
#include <QDebug>

#include "testclases.h"
#include "ui_testclases.h"

#include "./clases/posicion.h"

#include "./clases/recursos/recurso.h"
#include "./clases/recursos/fuente.h"
#include "./clases/recursos/silo.h"
#include "./clases/recursos/extractor.h"

using namespace std;

TestClases::TestClases(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestClases)
{
    Posicion miPosicion;
    ui->setupUi(this);

    //Aqui se probará el tema de las clases
    miPosicion.x = 10;
    miPosicion.y = 15;

    //ui->listWidget->addItem("Pos: " + QString::number(miPosicion.x));

    /*
    this->extractor.setSilo(silo);
    this->extractor.setCantidadPorExtraccion(10);
    this->extractor.setTiempoPorExtraccion(5);

    long cantidad = this->extractor.getCantidadSilo();

    ui->listWidget->addItem("Extractor: " + QString::number(cantidad));
    */

    //Almacen almacen;
    /*
    Silo silo(Recurso("ORO",ORO),1000);
    almacen.addSilo(Silo(Recurso("ORO",ORO),1000));
    edificio.setAlmacen(almacen);

    //Fuente fuente(miPosicion,Recurso("ORO",ORO), 10000);
    //Silo siloExtractor(fuente.getRecurso(),1000);

    //Extractor extractor; //TODO Probar el otro constructor
    extractor.setFuente(Fuente(miPosicion,Recurso("ORO",ORO), 10000));
    extractor.setSilo(Silo(Recurso("ORO",ORO),1000));
    extractor.setCantidadPorExtraccion(10);
    extractor.setTiempoPorExtraccion(5);

    edificio.recogeRecursos();
    //edificio.addExtractor(&extractor);
    edificio.addExtractor_new();
    */

    this->nacion->setTipo(TRIBU);

    nacion->addCiudad("GANDIA", true, miPosicion);

    Posicion otraPosicion;

    //Aqui se probará el tema de las clases
    otraPosicion.x = 100;
    otraPosicion.y = 150;

    nacion->addCiudad("CULLERA", false, otraPosicion);
}

TestClases::~TestClases()
{
    delete ui;
}

void TestClases::on_pushButton_clicked()
{    
    //long cantidad = edificio.getCantidadEnAlmacen("ORO");
    //ui->listWidget->addItem("Cantidad: " + QString::number(cantidad));

    QVector<Ciudad *> listaCiudades = nacion->listaCiudades();
    QVectorIterator<Ciudad*> it(listaCiudades);
     while (it.hasNext()) {
        Ciudad *c = it.next();
        qDebug() << c->getNombre() << " " << c->getPosicion().x << " " << c->esCapital();
        if (c->esCapital()) {
            Palacio* p = c->getPalacio();
            qDebug() << "Poblacion: " << p->getPoblacion();
        }
     }

     qDebug() << this->nacion->getTipo() ;
}

void TestClases::on_pushButton_2_clicked()
{
    QVector<Ciudad *> listaCiudades = nacion->listaCiudades();
    QVectorIterator<Ciudad*> it(listaCiudades);
    while (it.hasNext()) {
        Ciudad *c = it.next();
        if (c->getNombre()=="GANDIA") {
            //c->setNombre("GANDIA 2");
            c->setPosicion(Posicion(300,100,100));
            if (c->esCapital()) {
                Palacio* p = c->getPalacio();
                p->addPoblacion(10000); //TODO NO funciona
                return;
            }
            //c->setCapital(false);
        }
    }
}

void TestClases::on_pushButton_3_clicked()
{
    QVector<Ciudad *> listaCiudades = nacion->listaCiudades();
    QVectorIterator<Ciudad*> it(listaCiudades);
    while (it.hasNext()) {
        Ciudad *c = it.next();
        if (c->getNombre()=="GANDIA") {
            if (c->esCapital()) {
                Palacio* p = c->getPalacio();
                p->restaPoblacion(5000);
                return;
            }
            //c->setCapital(false);
        }
    }
}
