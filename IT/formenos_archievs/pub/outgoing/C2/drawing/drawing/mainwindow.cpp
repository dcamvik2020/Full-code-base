//============================================================================
// Name        : drawing
// Created on  : 09.02.2015
// Written by  : Andrey Tretyakov
// Version     : 6.4E1
// Copyright   : GNU General Public License as published by the Free Software Foundation;
//               either version 3, or (at your option) any later version.
// Description : A simple GUI popular-scientific drawing framework
//============================================================================

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <math.h>

//constructor - initialization
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), //call constructor of base class
    ui(new Ui::MainWindow) //initialize "ui" field by pointer to newly created object
{
    ui->setupUi(this);

    //create dynamic widget
    paintWidget = new PaintWidget(this);
    //setup size, position and other attributes using layout
    //try to put similar widget on form and see build-drawing-Desktop_Qt_5_3_MinGW_32bit-Debug/ui_mainwindow.h
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(paintWidget->sizePolicy().hasHeightForWidth());
    paintWidget->setSizePolicy(sizePolicy);
    ui->horizontalLayout->addWidget(paintWidget);

    //setup status bar
    lb1 = new QLabel("X: ", this);
    statusBar()->addWidget(lb1);
    lb2 = new QLabel(this);
    lb2->setMinimumWidth(50);
    statusBar()->addWidget(lb2);
    lb3 = new QLabel("Y: ", this);
    statusBar()->addWidget(lb3);
    lb4 = new QLabel(this);
    lb4->setMinimumWidth(50);
    statusBar()->addWidget(lb4);

    //setup connection between source of event (that generates/emits "signal") and destination (handler, "slot", that process event)
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(button_clicked()));
    connect(paintWidget, SIGNAL(paint_resized(QSize, QSize)), this, SLOT(paint_resized(QSize, QSize)));
    connect(paintWidget, SIGNAL(paint_double_clicked(int, int)), this, SLOT(paint_double_clicked(int, int)));
    connect(paintWidget, SIGNAL(paint_scrolled(int, int, int)), this, SLOT(paint_scrolled(int, int, int)));
    connect(paintWidget, SIGNAL(paint_mouse_move(int, int)), this, SLOT(paint_mouse_move(int, int)));
    connect(paintWidget, SIGNAL(paint_mouse_button_down(int, int)), this, SLOT(paint_mouse_button_down(int, int)));
    connect(paintWidget, SIGNAL(paint_mouse_button_up()), this, SLOT(paint_mouse_button_up()));

    can_draw = false;
    scale = 10;
    x0 = y0 = 0;
    captured = false;
}

//destructor - free resources
MainWindow::~MainWindow()
{
    delete lb1;
    delete lb2;
    delete lb3;
    delete lb4;
    delete paintWidget;
    delete ui;
}

//called when button is clicked and form and widget is resized, including creation of form
void MainWindow::draw_picture()
{
    QPainter painter(paintWidget->image);
    int d, w = paintWidget->width(), h = paintWidget->height();
    int freqPoints = 1, freqNumbersX = 1, freqNumbersY = 1;
    //axes and captions
    //Ox
    painter.drawLine(0, y0, w, y0);
    painter.drawLine(w - 5, y0 - 5, w, y0); painter.drawLine(w, y0, w - 5, y0 + 5);
    painter.drawText(w - 10, y0 - 7, "x");
    //Oy
    painter.drawLine(x0, 0, x0, h);
    painter.drawLine(x0 - 5, 5, x0, 0); painter.drawLine(x0, 0, x0 + 5, 5);
    painter.drawText(x0 + 8, 10, "y");

    //strokes and numbers
    //preparing
    if (scale == 1)
        freqPoints = 5; else
    if (scale == 2)
        freqPoints = 2;
    //Ox
    int old_left, old_width = 0, new_left, new_width;
    for (int i = -x0 / scale; i <= (w - x0) / scale; i++)
    {
        //strokes
        if (freqPoints > 0 && i % freqPoints == 0)
        {
            d = 2;
            if (i % 10 == 0)
                d = 6; else
            if (i % 2 == 0)
                d = 4;
            painter.drawLine(x0 + i * scale, y0, x0 + i * scale, y0 + d);
        }
        //numbers
        if (freqNumbersX > 0 && i % freqNumbersX == 0)
        {
            QString s;
            s.setNum(i);
            //make sure, that the new number does't overlap previous one; otherwise increase freqNumbersX
            QRect bounds = painter.boundingRect(0, 0, 0, 0, 0, s);
            new_width = bounds.width();
            new_left = x0 + i * scale - new_width / 2;
            if (old_width == 0 || old_left + old_width + 2 < new_left)
            {
                painter.drawText(new_left, y0 + 17, s);
                old_left = new_left;
                old_width = new_width;
            } else
            if (freqNumbersX == 2)
                freqNumbersX = 5; else
            if (freqNumbersX == 20)
                freqNumbersX = 50;
            else
                freqNumbersX *= 2;
        }
    }
    //Oy
    int old_bottom, old_height = 0, new_bottom, new_height;
    for (int i = (y0 - h) / scale; i <= y0 / scale; i++)
    {
        //strokes
        if (freqPoints > 0 && i % freqPoints == 0)
        {
            d = 2;
            if (i % 10 == 0)
                d = 6; else
            if (i % 2 == 0)
                d = 4;
            painter.drawLine(x0 - d, y0 - i * scale, x0, y0 - i * scale);
        }
        //numbers
        if (freqNumbersY > 0 && i % freqNumbersY == 0)
        {
            QString s;
            s.setNum(i);
            //make sure, that the new number does't overlap previous one; otherwise increase freqNumbersY
            QRect bounds = painter.boundingRect(0, 0, 0, 0, 0, s);
            new_height = bounds.height();
            new_bottom = y0 - i * scale + new_height / 2 - 2;
            if (old_height == 0 || old_bottom - old_height - 2 > new_bottom)
            {
                painter.drawText(x0 - bounds.width() - 10, new_bottom, s);
                old_bottom = new_bottom;
                old_height = new_height;
            } else
            if (freqNumbersY == 2)
                freqNumbersY = 5; else
            if (freqNumbersY == 20)
                freqNumbersY = 50;
            else
                freqNumbersY *= 2;
        }
    }

    if (!can_draw)
        return;
    painter.drawLine(10, 10, paintWidget->width() - 10, paintWidget->height() - 10);

    //formula
    //TODO: Add your code here
}

//called when button is clicked
void MainWindow::button_clicked()
{
    can_draw = !can_draw;
    paintWidget->image->fill(0);
    draw_picture();
    repaint();
}

void MainWindow::paint_resized(QSize old_size, QSize new_size)
{
    //set (x0, y0) in a such way, that (w/2, h/2) is fixed
    if (old_size.width() >= 0)
        x0 += (new_size.width() - old_size.width()) / 2;
    else
        x0 = paintWidget->width() / 2;
    if (old_size.height() >= 0)
        y0 += (new_size.height() - old_size.height()) / 2;
    else
        y0 = paintWidget->height() / 2;
    draw_picture();
}

//called when paintWidget is double-clicked
void MainWindow::paint_double_clicked(int x, int y)
{
    x0 = x; y0 = y;
    paintWidget->image->fill(0);
    draw_picture();
    repaint();
}

//called when mouse is over paintWidget and scrolling
void MainWindow::paint_scrolled(int w, int x, int y)
{
    int old_scale = scale;
    scale += w / 100;
    if (scale <= 0)
        scale = 1;
    //solved equations
    x0 = (int)round((x0 - x) * scale / (double)old_scale) + x;
    y0 = (int)round((y0 - y) * scale / (double)old_scale) + y;
    paintWidget->image->fill(0);
    draw_picture();
    repaint();
}

//I like to move it, move it
void MainWindow::paint_mouse_move(int x, int y)
{
    if (captured)
    {
        x0 = saved_x0 + x - saved_x;
        y0 = saved_y0 + y - saved_y;
        paintWidget->image->fill(0);
        draw_picture();
        repaint();
    }
    QString s;
    s.setNum((x - x0) / (double) scale);
    lb2->setText(s);
    s.setNum((y0 - y) / (double) scale);
    lb4->setText(s);
}

void MainWindow::paint_mouse_button_down(int x, int y)
{
    captured = true;
    saved_x = x;
    saved_y = y;
    saved_x0 = x0;
    saved_y0 = y0;
}

void MainWindow::paint_mouse_button_up()
{
    captured = false;
}
