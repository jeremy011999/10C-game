#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QObject>
#include <QPointF>
#include <QGraphicsEllipseItem>
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>
#include <QMediaPlayer>



class ball:public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    ball();
    void move();
    qreal getMiddleXCoord();
    void power_up_ball();
public slots:
    void update_ball();
    void back_to_regular_ball();
signals:
    void ball_hit_ground();
private:
    double x_velocity;
    double y_velocity;
    int ball_width;
    int ball_height;
    double ball_speed;
    QMediaPlayer* player;
    bool is_powered_ball = false;
};

#endif // BALL_H
