#ifndef TESTCLASES_H
#define TESTCLASES_H

#include <QDialog>

#include "./clases/recursos/edificio.h"
#include "./clases/gestor/nacion.h"

namespace Ui {
class TestClases;
}

class TestClases : public QDialog
{
    Q_OBJECT

public:
    explicit TestClases(QWidget *parent = nullptr);
    ~TestClases();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void muestra();

private:
    Ui::TestClases *ui;

    /*
    Almacen almacen;
    Extractor extractor;
    Edificio edificio;
    */

    Nacion *nacion = new Nacion();

    QTimer *cronometro = new QTimer(this);
};

#endif // TESTCLASES_H
