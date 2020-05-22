#include <iostream>

#include "testclases.h"
#include "ui_testclases.h"

#include "./clases/posicion.h"

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

    cout << "pos: " << miPosicion.x << " , " << miPosicion.y << " , " << miPosicion.z << endl;
}

TestClases::~TestClases()
{
    delete ui;
}
