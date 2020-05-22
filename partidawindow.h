#ifndef PARTIDAWINDOW_H
#define PARTIDAWINDOW_H

#include <QDialog>

#include "./clases/usuario.h"

namespace Ui {
class PartidaWindow;
}

class PartidaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PartidaWindow(QWidget *parent = nullptr);
    ~PartidaWindow();

    void setUsuario(QString u);

private slots:
    void on_pushButton_2_clicked();

    void on_btnNueva_clicked();

private:
    Ui::PartidaWindow *ui;

    QString usuario;

    void refrescaListaPartidas();
};

#endif // PARTIDAWINDOW_H
