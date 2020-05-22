#include "testclases.h"


#include <QApplication>

#include "./clases/item.h"
#include "./clases/sgbd.h"

int main(int argc, char *argv[])
{
    SGBD s;

    Item::inicializa();

    QApplication a(argc, argv);

    TestClases w;
    w.show();

    return a.exec();
}
