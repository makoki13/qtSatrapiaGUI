#ifndef TESTCLASES_H
#define TESTCLASES_H

#include <QDialog>

#include "./clases/recursos/edificio.h"

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

private:
    Ui::TestClases *ui;

    Edificio edificio;
};

#endif // TESTCLASES_H
