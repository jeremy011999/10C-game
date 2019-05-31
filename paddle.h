#ifndef PADDLE_H
#define PADDLE_H

#include<QObject>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QRectF>
#include <QGraphicsRectItem>
#include "ball.h"

class paddle:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    paddle(double width);
    void move();
    void move_left();
    void move_right();
    qreal getMiddleXCoord();
    int getwidth();
    void power_up_paddle();
    bool power_up_paddle_active();
    void keyPressEvent(QKeyEvent* event);
    void paddleDied();
    void space_press();
    void stick_ball_to_paddle();
signals:
    void paddleDead();
    void space_bar_pressed();
public slots:
    void back_to_regular_paddle();
private:
    int paddle_width;
    int paddle_height;
    bool is_powered_paddle;
    bool stick_ball = false;
};

#endif // PADDLE_H
