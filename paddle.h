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
    QRectF rectangle;
    int x,y,max_width;
    bool hit_wall_left();
    bool hit_wall_right();
    void move_left();
    void move_right();
    void set_left_side(qreal point);
    void set_right_side(qreal point);
    qreal left_side, right_side;

signals:

public slots:
};

#endif // PADDLE_H

