#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_clicked()
{
    QMessageBox::information(this, "Caption", "Text");
}
