#ifndef SNOWFLAKES_H
#define SNOWFLAKES_H

#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QtMultimedia/QMediaPlayer>
#include <QMediaPlayer>
#include "ball.h"
#include "paddle.h"

class snowflake : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    snowflake(double size);
    void move();
    virtual ~snowflake();
    void stop_timer();
public slots:
    virtual void updateSnowflake();
    void snowflakeHit();
signals:
    void snowflake_captured();
protected:
    double y_velocity,x_velocity;
    QPixmap* snowflake_pic = nullptr;
    QTimer* snowflakeTimer = nullptr;
    double flake_size;
};


#endif // SNOWFLAKES_H
