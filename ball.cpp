#include "ball.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include "bricks.h"

ball::ball():x_velocity(5),y_velocity(5),ball_width(30),ball_height(30)
{
    setRect(0,0,ball_width,ball_height);
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update_ball()));
    timer->start(30);
}

void ball::move()
{
    moveBy(x_velocity,y_velocity);
}

void ball::handle_collision_with_bricks()
{

}

void ball::update_ball()
{
    //Check if ball hits a wall, if so then make the velocity switch directions
    if((x()<=0&&x_velocity<0)||(x()+ball_width>=scene()->width()&&x_velocity>0))
        x_velocity *= (-1);
    if((y()<=0&&y_velocity<0)||(y()+ball_height>=scene()->height()&&y_velocity>0))
        y_velocity *= (-1);

    //Check for collisions
    QList<QGraphicsItem*> items_ball_hit = collidingItems();
    for(int i=0;i<items_ball_hit.size();i++)
    {
        //Check if the collision was with a brick
        if(typeid(*items_ball_hit[i])==typeid(brick))
            scene()->removeItem(items_ball_hit[i]);
            delete items_ball_hit[i];
            y_velocity *= -1;
    }
    move();
}

