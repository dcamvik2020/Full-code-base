#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);
    ~PaintWidget();
    QImage *image;

signals:

public slots:

protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void paintEvent(QPaintEvent *);
};

#endif // PAINTWIDGET_H
