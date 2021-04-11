#include "paintwidget.h"
#include <QPainter>

PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
    image = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    image->fill(0);
}

PaintWidget::~PaintWidget()
{
    delete image;
}

void PaintWidget::resizeEvent(QResizeEvent *)
{
    delete image;
    image = new QImage(size(), QImage::Format_ARGB32_Premultiplied);
    image->fill(0);
    emit update_cache();
}

void PaintWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0, 0, *image);
}
