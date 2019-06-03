#include "greensnowflake.h"

greenSnowflake::greenSnowflake(double size):snowflake(size)
{
    delete snowflake_pic;
    snowflake_pic = new QPixmap(":/greensnowflake.png");
    setPixmap(*snowflake_pic);
    double scale = flake_size/boundingRect().width();
    setScale(scale);
}

void greenSnowflake::updateSnowflake()
{
    //If ball hits bottom of screen remove it and clean up its memory
    if(y()>scene()->height()&&y_velocity>0)
    {
        snowflakeTimer->stop();
        scene()->removeItem(this);
        delete this;
        return;
    }



    QList<QGraphicsItem*> items_monster_hit = collidingItems();
    for(int i=0;i<items_monster_hit.size();i++)
    {
        //Check if the collision was with a paddle
        if(typeid(*items_monster_hit[i])==typeid(paddle))
        {
            emit green_snowflake_captured();
            plusLifePic = new QPixmap(":/plusLife.png");
            setPixmap(*plusLifePic);
            double scale = flake_size*3.5/boundingRect().width();
            setScale(scale);
            setPos(x(),scene()->height()-40-scale*boundingRect().height());
            snowflakeTimer->stop();
            QTimer::singleShot(2000, this, SLOT(snowflakeHit()));
            return;
        }
    }
    move();
}

greenSnowflake::~greenSnowflake()
{
    delete plusLifePic; plusLifePic = nullptr;
    delete snowflake_pic; snowflake_pic = nullptr;
    delete snowflakeTimer;
    snowflakeTimer = nullptr;
}

