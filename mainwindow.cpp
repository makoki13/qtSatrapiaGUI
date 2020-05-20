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
    ui->txtLogin_2->setFocus();
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

void MainWindow::on_btnRegistrar_clicked()
{
    QMessageBox msgBox;
    QString usuario = ui->txtLogin_2->text();
    QString clave = ui->txtPass_2->text();
    QString claveRepeticion = ui->txtPass_3->text();

    usuario = usuario.toUpper();

    if (usuario == "") {
        msgBox.setText("Falta el usuario.");
        ui->txtLogin_2->setFocus();
        ui->txtLogin_2->selectAll();
        msgBox.exec();

        return;
    }
    if (clave == "") {
        msgBox.setText("Falta la contraseña.");
        ui->txtPass_2->setFocus();
        msgBox.exec();

        return;
    }
    if (claveRepeticion == "") {
        msgBox.setText("Falta la confrmación de la contraseña.");
        ui->txtPass_3->setFocus();
        msgBox.exec();

        return;
    }
    if (claveRepeticion != clave) {
        msgBox.setText("La contraseña y su confirmación no coinciden");
        ui->txtPass_2->setText("");
        ui->txtPass_3->setText("");
        ui->txtPass_2->setFocus();
        msgBox.exec();

        return;
    }

    if (SUPERV_Usuario::existe_usuario_registrado(usuario) == true) {
        msgBox.setText("El Usuario ya existe.");        
        msgBox.exec();
        ui->txtLogin_2->setText("");
        ui->txtPass_2->setText("");
        ui->txtPass_3->setText("");
        ui->txtLogin_2->setFocus();

        return;
    }
    else {
        msgBox.setText("Usuario registrado");
        msgBox.exec();
        ui->txtLogin->setText(usuario);
        ui->txtPass->setText(clave);

        SUPERV_Usuario::crea_usuario(usuario, clave);

        return;
    }
}

void MainWindow::on_txtLogin_2_returnPressed()
{
    ui->txtPass_2->setFocus();
}

void MainWindow::on_txtPass_2_returnPressed()
{
    ui->txtPass_3->setFocus();
}

void MainWindow::on_txtPass_3_returnPressed()
{
    ui->btnRegistrar->setFocus();
}
