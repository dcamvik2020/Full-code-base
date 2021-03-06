#include "paintwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QFrame>

PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent) {
    setMouseTracking(true);
    QSize size(400, 400);
    image = new QImage(size, QImage::Format_ARGB32_Premultiplied); //fast RGB with alpha
    image->fill(0); //erase trash pixels
    setFocusPolicy(Qt::StrongFocus);
}

PaintWidget::~PaintWidget() {
    delete image;
}

void PaintWidget::resizeEvent(QResizeEvent *event) {
    //recreate cache image with new size
    delete image;
    image = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    image->fill(0);
    //ask MainWidget class to draw picture again ("emit" keyword is an extension of Qt framework)
    emit paint_resized(event->oldSize(), event->size());
}

void PaintWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this); // place for painting
    painter.fillRect(0, 0, this->width(), this->height(), Qt::white);
    painter.drawImage(0, 0, *image);
}


