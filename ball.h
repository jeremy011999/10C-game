#ifndef BALL_H
#define BALL_H

#include "paddle.h"
#include "bricks.h"
#include <QPointF>
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QtMath>
#include <cmath>
#include <QPainter>


class ball:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    
    /* Constructs ball
     *
     * @param size the size of the ball
     */
    ball(double size);
    
    //moves ball
    void move();

    /* gets middle X coordinate of ball
     *
     * @returns middle X coordinate of ball
     */
    qreal getMiddleXCoord();
    
    /* gets left X coordinate of ball
     *
     * @returns left X coordinate of ball
     */
    qreal getLeftX();
    
    
    /* gets right X coordinate of ball
     *
     * @returns right X coordinate of ball
     */
    qreal getRightX();
    
    
    /* gets top Y coordinate of ball
     *
     * @returns top Y coordinate of ball
     */
    qreal getTopY();
    
    /* gets bottom Y coordinate of ball
     *
     * @returns bottom Y coordinate of ball
     */
    qreal getBottomY();

    // turns the ball into powered up fire ball
    void power_up_ball();
    
    /* Checks if a powerup ball is active
     *
     * @return bool true if powerup ball is active
     */
    bool power_up_ball_active();
    
    // Toggles sound for ball
    void mute_ball();
    
    /* set the level of the ball (its speed)
     *
     * @param level of ball
     */
    void set_level(int level);
    
    /* gets the size of the ball
     *
     * @return double size of the ball
     */
    double get_size();
    
    // Stops the timer that moves the ball
    void stopTimer();
    
    // Clean up data from ball object
    ~ball();
public slots:
    
    // Updates position of ball and checks for collisions.
    void update_ball();
    
    // Starts the timer to move the ball
    void start_moving_ball();
    
    // disables the powerup ball and goes back to regular ball
    void back_to_regular_ball();
signals:
    
    //emitted when ball hits the ground
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
