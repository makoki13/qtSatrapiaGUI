#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../QtSatrapia/superv_usuario.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    ui->groupBox->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->groupBox->show();

    if (SUPERV_Usuario::existe_usuario("pablo.makoki@gmail.com","FIRST") == true) {
        cout << "EXISTE!" << endl;
    }
    else {
        cout << "NO EXISTE!" << endl;
    }
}
