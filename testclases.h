#ifndef TESTCLASES_H
#define TESTCLASES_H

#include <QDialog>

namespace Ui {
class TestClases;
}

class TestClases : public QDialog
{
    Q_OBJECT

public:
    explicit TestClases(QWidget *parent = nullptr);
    ~TestClases();

private:
    Ui::TestClases *ui;
};

#endif // TESTCLASES_H
