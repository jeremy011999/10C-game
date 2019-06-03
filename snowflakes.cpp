#include "snowflakes.h"
#include <QSound>

snowflake::snowflake(double size):x_velocity(0),y_velocity(2),flake_size(size)
{
    snowflake_pic = new QPixmap(":/snowflake.png");
    setPixmap(*snowflake_pic);
    double Scale = flake_size/boundingRect().width();
    setScale(Scale);
    snowflakeTimer = new QTimer(this);
    connect(snowflakeTimer,SIGNAL(timeout()),this,SLOT(updateSnowflake()));
    snowflakeTimer->start(25);
}


void snowflake::updateSnowflake()
{
    //If ball hits bottom of screen remove it and clean up its memory
    if(y()>scene()->height()&&y_velocity>0)
    {
        snowflakeTimer->stop();
        scene()->removeItem(this);
        delete this;
        return;
    }


    //Check for collisions with items, if hits paddle, get points
    QList<QGraphicsItem*> items_monster_hit = collidingItems();
    for(int i=0;i<items_monster_hit.size();i++)
    {
        //Check if the collision was with a paddle
        if(typeid(*items_monster_hit[i])==typeid(paddle))
        {
            emit snowflake_captured();
            snowflakeHit();
            return;
        }
    }
    move();
}

void snowflake::move()
{
    moveBy(x_velocity,y_velocity);
}

void snowflake::snowflakeHit()
{
    snowflakeTimer->stop();
    scene()->removeItem(this);
    delete this;
}

snowflake::~snowflake()
{
    delete snowflake_pic;
    snowflake_pic = nullptr;
    delete snowflakeTimer;
    snowflakeTimer = nullptr;
}

void snowflake::stop_timer()
{
    snowflakeTimer->stop();
}
