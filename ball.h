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
    qreal getMiddleXCoord();
public slots:
    void update_ball();
signals:
    void hit_a_brick();
private:
    double x_velocity;
    double y_velocity;
    int ball_width;
    int ball_height;
    double ball_speed;
};

#endif // BALL_H
