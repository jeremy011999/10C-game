#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QObject>
#include <QPointF>
#include <QGraphicsEllipseItem>


class ball:public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    ball();
    void move();
public slots:
    void update_ball();
private:
    int x_velocity;
    int y_velocity;
    int ball_width;
    int ball_height;
};

#endif // BALL_H
