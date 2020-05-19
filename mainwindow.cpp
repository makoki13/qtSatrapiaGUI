#include <iostream>
#include <QMessageBox>
#include <QColor>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../QtSatrapia/superv_usuario.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setGeometry(300,300,300,300);

    QPalette Pal(palette());
    // Asignar el color de fondo como Negro
    Pal.setColor(QPalette::Background, QColor(55, 0, 55));
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    ui->setupUi(this);
    ui->groupBox->hide();
    ui->txtLogin->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnNuevo_clicked()
{
    ui->groupBox->show();
    ui->groupBox->setDisabled(false);
}

void MainWindow::on_btnEntrar_clicked()
{
    QMessageBox msgBox;
    QString usuario = ui->txtLogin->text();
    QString clave = ui->txtPass->text();

    usuario = usuario.toUpper();

    if (usuario == "") {
        msgBox.setText("Falta el usuario.");
        ui->txtLogin->setFocus();
        msgBox.exec();
        return;
    }
    if (clave == "") {
        msgBox.setText("Falta la contraseña.");
        ui->txtPass->setFocus();
        msgBox.exec();
        return;
    }

    if (SUPERV_Usuario::existe_usuario(usuario, clave) == true) {        
        msgBox.setText("Usuario correcto.");
        msgBox.exec();
    }
    else {        
        msgBox.setText("Usuario no existe o contraseña incorrecta.");
        ui->txtPass->setText("");
        ui->txtLogin->setFocus();
        ui->txtLogin->selectAll();
        msgBox.exec();
        return;
    }

}

void MainWindow::on_txtLogin_returnPressed()
{
    ui->txtPass->setFocus();
}

void MainWindow::on_txtPass_returnPressed()
{
    ui->btnEntrar->setFocus();
}
