#include "ball.h"
#include "paddle.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include "bricks.h"
#include <QtMath>
#include <cmath>
#include <QPainter>


ball::ball(double size):ballsize(size),ball_speed(.3*size)
{
    x_velocity = ball_speed*qCos(qDegreesToRadians(static_cast<double>(90)));
    y_velocity= -ball_speed*qSin(qDegreesToRadians(static_cast<double>(90)));
    fireball = new QPixmap(":/fireball.png");
    metalball = new QPixmap(":/metallball.png");
    setPixmap(*metalball);
    scale = ballsize/boundingRect().width();
    setScale(scale);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update_ball()));

    //hopefully does sound
    player= new QMediaPlayer(this);
    player->setMedia(QUrl("qrc:/impact_metal_small_005.mp3"));
    player->setVolume(100);
}

void ball::move()
{
    moveBy(x_velocity,y_velocity);
}

qreal ball::getMiddleXCoord()
{
    return x()+boundingRect().width()*scale/2;
}

qreal ball::getTopY()
{
    return y();
}

qreal ball::getBottomY()
{
    return y()+boundingRect().height()*scale;
}

qreal ball::getLeftX()
{
    return x();
}

qreal ball::getRightX()
{
    return x()+boundingRect().width()*scale;
}

void ball::power_up_ball()
{
    setPixmap(*fireball);
    is_powered_ball = true;
    QTimer::singleShot(5000, this, SLOT(back_to_regular_ball()));
}

bool ball::power_up_ball_active()
{
    return is_powered_ball;
}
void ball::back_to_regular_ball()
{
    setPixmap(*metalball);
    is_powered_ball = false;
}


void ball::update_ball()
{
    double ballWidth = boundingRect().width()*scale;
    double ballHeight = boundingRect().height()*scale;

    //Check if ball left or right wall, if so then make the velocity switch directions
    if((x()<=0&&x_velocity<0)||((x()+ballWidth)>=scene()->width()&&x_velocity>0))
        x_velocity *= (-1);

    //If ball hits cieling switch y velocity
    if(y()<=0&&y_velocity<0)
        y_velocity *= (-1);

    //If ball hits bottom of screen remove it and clean up its memory
    if((y()+ballHeight)>=scene()->height()&&y_velocity>0)
    {
        scene()->removeItem(this);
        emit ball_hit_ground();
        delete(this);
        return;
    }

    //Check for collisions with items
    QList<QGraphicsItem*> items_ball_hit = collidingItems();
    for(int i=0;i<items_ball_hit.size();i++)
    {
        //Check if the collision was with a brick
        if(typeid(*items_ball_hit[i])==typeid(brick))
        {
            brick* hitbrick = dynamic_cast<brick*>(items_ball_hit[i]);
            if(is_powered_ball)
            {
                player->play();
                hitbrick->destroy_brick();
            }
            else
            {
                 //Check if brick was hit on a right or left side, then change x velocity
                 if(getMiddleXCoord() < hitbrick->x() && y() < hitbrick->getBottomY()-5 &&
                         y()+boundingRect().height()*scale > hitbrick->y()+5 && x_velocity>0)
                     x_velocity = -abs(x_velocity);
                 else if(getMiddleXCoord()>hitbrick->getRightX() && y() < hitbrick->getBottomY()-5 &&
                         y()+boundingRect().height()*scale > hitbrick->y()+5  && x_velocity<0)
                     x_velocity = abs(x_velocity);

                 //Check if brick was hit on a bottom or top side, then change y velocity
                 else if(y()<hitbrick->y()&&y_velocity>0)
                     y_velocity = -abs(y_velocity);
                 else if(y()>hitbrick->y()&&y_velocity<0)
                     y_velocity = abs(y_velocity);
                 player->play();
                 hitbrick->update_hit_brick();
            }

        }

        //Check if a block isn't hit, but instead a paddle is hit
        else if(typeid(*items_ball_hit[i])==typeid(paddle))
        {
            paddle* hitpaddle = dynamic_cast<paddle*>(items_ball_hit[i]);
            double reflection_angle = 0;
            double ball_pos = this->getMiddleXCoord();
            double paddle_pos = hitpaddle->getMiddleXCoord();
            if(ball_pos < paddle_pos)
            {
                reflection_angle = 100+(140-100)*(paddle_pos-ball_pos)/((hitpaddle->getwidth()+ballWidth/2)/2);
                x_velocity = ball_speed*qCos(qDegreesToRadians((reflection_angle)));
            }
            else
            {
                reflection_angle = 80-(80-40)*(ball_pos-paddle_pos)/((hitpaddle->getwidth()+ballWidth/2)/2);
                x_velocity = ball_speed*qCos(qDegreesToRadians((reflection_angle)));
            }
            y_velocity = -ball_speed*qSin(qDegreesToRadians(static_cast<double>(reflection_angle)));
            player->play();
        }
    }
    move();
}

void ball::start_moving_ball()
{
    timer->start(25);
}

void ball::mute_ball()
{
    muted = true;
    player->setVolume(0);
}

void ball::set_level(int level)
{
    if(level == 0)
        ball_speed = .3*ballsize;
    else if(level == 1)
        ball_speed = .45*ballsize;
    else if(level >= 2)
        ball_speed = .6*ballsize;

    //adjust velocities
    x_velocity = ball_speed*qCos(qDegreesToRadians((static_cast<double>(90))));
    y_velocity = -ball_speed*qSin(qDegreesToRadians((static_cast<double>(90))));
}

double ball::get_size()
{
    return ballsize;
}

ball::~ball()
{
    delete fireball;
    delete metalball;
}

void ball::stopTimer()
{
    timer->stop();
}
