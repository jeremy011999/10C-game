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
    
    /* move() moves the snowflake according to x and y velocity
    @param none
    @return void
    */ 
    void move();
    virtual ~snowflake();
    
    /* stop_timer() stops the timer when function is called
    @param none
    @return void
    */
    void stop_timer();
public slots:
    /* updateSnowFlake() is a slot that checks for collisions with the paddle and allows necessary signals and slots to update snowflake
    @param none
    @return void
    */
    virtual void updateSnowflake();
    
    /* snowflakeHit() is a slot that stops the timer and ermoves the snowflake from the scene when hit
    @param
    @return
    */
    void snowflakeHit();
signals:
    /* snowflake_captured() is a signal emitted to capture the snowflake
    @param none
    @return void
    */
    void snowflake_captured();
protected:
    double y_velocity,x_velocity;
    QPixmap* snowflake_pic = nullptr;
    QTimer* snowflakeTimer = nullptr;
    double flake_size;
};


#endif // SNOWFLAKES_H
