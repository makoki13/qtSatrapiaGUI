#include <iostream>

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

    Almacen almacen;
    Silo silo(Recurso("ORO",ORO),1000);
    almacen.addSilo(silo);
    edificio.setAlmacen(almacen);

    Fuente fuente(miPosicion,Recurso("ORO",ORO), 10000);
    Silo siloExtractor(fuente.getRecurso(),1000);

    Extractor extractor; //TODO Probar el otro constructor
    extractor.setFuente(fuente);
    extractor.setSilo(siloExtractor);
    extractor.setCantidadPorExtraccion(10);
    extractor.setTiempoPorExtraccion(5);

    edificio.recogeRecursos();
    //edificio.addExtractor(&extractor);
    edificio.addExtractor_new();
}

TestClases::~TestClases()
{
    delete ui;
}

void TestClases::on_pushButton_clicked()
{    
    long cantidad = edificio.getCantidadEnAlmacen("ORO");
    ui->listWidget->addItem("Cantidad: " + QString::number(cantidad));
}

void TestClases::on_pushButton_2_clicked()
{
    //this->extractor.extrae();
}

void TestClases::on_pushButton_3_clicked()
{
    //this->extractor.para();
}
