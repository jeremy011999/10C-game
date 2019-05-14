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
    qreal getMiddleXCoord();
    int getwidth();
    void power_up_paddle();
    bool power_up_paddle_active();
    void keyPressEvent(QKeyEvent* event);
private:
    int paddle_width;
    int paddle_height;
    bool is_powered_paddle;
signals:

public slots:
    void back_to_regular_paddle();
};

#endif // PADDLE_H
