#include <iostream>

#include <QTableWidgetItem>

#include "partidawindow.h"
#include "ui_partidawindow.h"

#include "./clases/superv_partida.h"
#include "./clases/superv_usuario.h"

PartidaWindow::PartidaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PartidaWindow)
{    
    SUPERV_Partida::loadPartidas();

    this->refrescaListaPartidas();

    ui->setupUi(this);
}

PartidaWindow::~PartidaWindow()
{
    delete ui;
}

void PartidaWindow::setUsuario(QString u)
{
    this->usuario = u;
    ui->lblUsuario->setText( u );
}

void PartidaWindow::on_pushButton_2_clicked()
{
    this->close();
}

void PartidaWindow::on_btnNueva_clicked()
{
    Partida partida = SUPERV_Partida::nueva();
    Usuario u = SUPERV_Usuario::carga_usuario(this->usuario);
    SUPERV_Partida::addJugador(partida.getID(), u.getID());

    this->refrescaListaPartidas();
}

void PartidaWindow::refrescaListaPartidas()
{
    unordered_map<int, Partida> partidas = SUPERV_Partida::lista();

    //QTableWidget *tabla = ui->tblListaPartidas;

    //ui->tblListaPartidas->setColumnCount(1);

    int fila = 0;
    for (unordered_map<int, Partida>::iterator it = partidas.begin(); it != partidas.end(); ++it) {
           std::cout << "Key:[" << it->first << "] Value:[" << it->second.esActiva() << "]\n";
           //ui->tblListaPartidas->insertRow(fila+1);
           QTableWidgetItem cell;
           QString valor = "PEPE";
           cell.setText(valor);
           //tabla->setItem(fila,0,&cell);
           fila++;
       }

    cout << "refrescaListaPartida" << endl;
}
