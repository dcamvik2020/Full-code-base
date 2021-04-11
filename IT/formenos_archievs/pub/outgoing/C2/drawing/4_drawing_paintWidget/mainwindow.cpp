#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(button_clicked()));

    paintWidget = new PaintWidget(this);
}

MainWindow::~MainWindow()
{
    delete paintWidget;
    delete ui;
}

void MainWindow::button_clicked()
{
    QPainter painter(paintWidget->image);
    painter.drawLine(10, 20, 100, 200);
    repaint();
}
