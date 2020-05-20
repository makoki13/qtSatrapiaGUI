#include "partidawindow.h"
#include "ui_partidawindow.h"

PartidaWindow::PartidaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PartidaWindow)
{
    ui->setupUi(this);
}

PartidaWindow::~PartidaWindow()
{
    delete ui;
}
