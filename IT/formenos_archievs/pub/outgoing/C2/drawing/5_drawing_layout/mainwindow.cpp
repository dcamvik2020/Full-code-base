#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    paintWidget = new PaintWidget(this);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(paintWidget->sizePolicy().hasHeightForWidth());
    paintWidget->setSizePolicy(sizePolicy);
    ui->horizontalLayout->addWidget(paintWidget);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(button_clicked()));
    connect(paintWidget, SIGNAL(update_cache()), this, SLOT(draw_picture()));

    can_draw = false;
}

MainWindow::~MainWindow()
{
    delete paintWidget;
    delete ui;
}

void MainWindow::draw_picture()
{
    if (!can_draw)
        return;
    QPainter painter(paintWidget->image);
    painter.drawLine(10, 10, paintWidget->width() - 10, paintWidget->height() - 10);
}

void MainWindow::button_clicked()
{
    can_draw = true;
    draw_picture();
    repaint();
}

