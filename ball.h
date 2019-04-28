#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QObject>

class ball:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    ball();
    void move();
    void handle_collision_with_bricks();
public slots:
    void update_ball();
private:
    int x_velocity;
    int y_velocity;
    int ball_width;
    int ball_height;
};

#endif // BALL_H
