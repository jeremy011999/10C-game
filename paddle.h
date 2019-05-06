#ifndef PADDLE_H
#define PADDLE_H

#include<QObject>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QRectF>
#include <QGraphicsRectItem>

class paddle:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    paddle();
    void move();
    void move_left();
    void move_right();
    void keyPressEvent(QKeyEvent* event);
private:
    int brick_width;
    int brick_height;
signals:

public slots:
};

#endif // PADDLE_H
