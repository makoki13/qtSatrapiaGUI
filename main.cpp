#include "mainwindow.h"

#include <QApplication>

#include "./clases/item.h"
#include "./clases/sgbd.h"

int main(int argc, char *argv[])
{
    SGBD s;

    Item::inicializa();

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
