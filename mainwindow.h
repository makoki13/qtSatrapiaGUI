#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnNuevo_clicked();

    void on_btnEntrar_clicked();

    void on_txtLogin_returnPressed();

    void on_txtPass_returnPressed();

    void on_btnRegistrar_clicked();

    void on_txtLogin_2_returnPressed();

    void on_txtPass_2_returnPressed();

    void on_txtPass_3_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
