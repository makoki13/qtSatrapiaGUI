#include "mainwindow.h"

#include <QApplication>

#include "../QtSatrapia/item.h"
#include "../QtSatrapia/sgbd.h"

int main(int argc, char *argv[])
{
    SGBD s;

    Item::inicializa();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
