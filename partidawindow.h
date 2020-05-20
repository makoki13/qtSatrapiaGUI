#ifndef PARTIDAWINDOW_H
#define PARTIDAWINDOW_H

#include <QDialog>

namespace Ui {
class PartidaWindow;
}

class PartidaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PartidaWindow(QWidget *parent = nullptr);
    ~PartidaWindow();

private:
    Ui::PartidaWindow *ui;
};

#endif // PARTIDAWINDOW_H
