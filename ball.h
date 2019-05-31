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
#include <QGraphicsPixmapItem>



class ball:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ball(double size);
    void move();

    qreal getMiddleXCoord();
    qreal getLeftX();
    qreal getRightX();
    qreal getTopY();
    qreal getBottomY();

    void power_up_ball();
    bool power_up_ball_active();
    void mute_ball();
    void set_level(double level);
    double get_size();
    ~ball();
    void stopTimer();
public slots:
    void update_ball();
    void start_moving_ball();
    void back_to_regular_ball();
signals:
    void ball_hit_ground();
private:
    double x_velocity;
    double y_velocity;
    double scale;
    double ballsize;
    double ball_speed;
    QMediaPlayer* player;
    bool is_powered_ball = false;
    bool muted = false;
    QTimer* timer = nullptr;
    QPixmap* fireball = nullptr;
    QPixmap* metalball = nullptr;
};

#endif // BALL_H
