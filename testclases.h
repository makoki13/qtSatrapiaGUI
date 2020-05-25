#ifndef TESTCLASES_H
#define TESTCLASES_H

#include <QDialog>

#include "./clases/recursos/extractor.h"

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

private:
    Ui::TestClases *ui;

    Extractor extractor;
};

#endif // TESTCLASES_H
