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



ball::ball():ball_width(30),ball_height(30),ball_speed(8)
{
    x_velocity = ball_speed*qCos(qDegreesToRadians(static_cast<double>(135)));
    y_velocity= -ball_speed*qSin(qDegreesToRadians(static_cast<double>(135)));
    setRect(0,0,ball_width,ball_height);
    setBrush(QColor(0,150,150));
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update_ball()));
    timer->start(25);
}

void ball::move()
{
    moveBy(x_velocity,y_velocity);
}

qreal ball::getMiddleXCoord()
{
    return x()+ball_width/2;
}


void ball::update_ball()
{
    //Check if ball left or right wall, if so then make the velocity switch directions
    if((x()<=0&&x_velocity<0)||(x()+ball_width>=scene()->width()&&x_velocity>0))
        x_velocity *= (-1);

    //If ball hits cieling switch y velocity
    if(y()<=0&&y_velocity<0)
        y_velocity *= (-1);

    //If ball hits bottom of screen remove it and clean up its memory
    if(y()+ball_height>scene()->height()&&y_velocity>0)
    {
        emit ball_hit_ground();
        scene()->removeItem(this);
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
            y_velocity = abs(y_velocity);
            hitbrick->update_hit_brick();
            emit hit_a_brick();
        }

        //Check if a block isn't hit, but instead a paddle is hit
        else if(typeid(*items_ball_hit[i])==typeid(paddle))
        {
            paddle* hitpaddle = dynamic_cast<paddle*>(items_ball_hit[i]);
            double reflection_angle;
            double ball_pos = this->getMiddleXCoord();
            double paddle_pos = hitpaddle->getMiddleXCoord();
            if(ball_pos < paddle_pos)
            {
                reflection_angle = 100+(140-100)*(paddle_pos-ball_pos)/((hitpaddle->getwidth()+ball_width/2)/2);
                x_velocity = ball_speed*qCos(qDegreesToRadians((reflection_angle)));
            }
            else if(ball_pos > paddle_pos)
            {
                reflection_angle = 80-(80-40)*(ball_pos-paddle_pos)/((hitpaddle->getwidth()+ball_width/2)/2);
                x_velocity = ball_speed*qCos(qDegreesToRadians((reflection_angle)));
            }
            y_velocity = -ball_speed*qSin(qDegreesToRadians(static_cast<double>(reflection_angle)));
        }
    }
    move();
}


