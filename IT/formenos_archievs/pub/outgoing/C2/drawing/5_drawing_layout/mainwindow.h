#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paintwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void draw_picture();
    void button_clicked();

private:
    Ui::MainWindow *ui;
    PaintWidget *paintWidget;
    bool can_draw;
};

#endif // MAINWINDOW_H
