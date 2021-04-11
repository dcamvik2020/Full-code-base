#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(button_clicked()));

    image = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    image->fill(0);
}

MainWindow::~MainWindow()
{
    delete image;
    delete ui;
}

void MainWindow::button_clicked()
{
    QPainter painter(image);
    painter.drawLine(10, 20, 100, 200);
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0, 0, *image);
}
