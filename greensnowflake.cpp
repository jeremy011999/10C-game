#include "greensnowflake.h"

/*
Constructor for greenSnowflake (inherits from snowflake class
@param size: sets size of base class snowflake
*/
greenSnowflake::greenSnowflake(double size):snowflake(size)
{
    delete snowflake_pic;
    snowflake_pic = new QPixmap(":/Game_Media/Pictures/greensnowflake.png");
    setPixmap(*snowflake_pic);
    double scale = flake_size/boundingRect().width();
    setScale(scale);
}

/*
Updates snowflake either when it collides with something or if it
hits the bottom of the screen
*/
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


    //figures out what snowflake has hit
    QList<QGraphicsItem*> items_monster_hit = collidingItems();
    for(int i=0;i<items_monster_hit.size();i++)
    {
        //Check if the collision was with a paddle
        if(typeid(*items_monster_hit[i])==typeid(paddle))
        {
            if(dynamic_cast<paddle*>(items_monster_hit[i])->ball_is_stuck()==false&&dynamic_cast<paddle*>(items_monster_hit[i])->get_lives()<3)
            {
                emit green_snowflake_captured();
                plusLifePic = new QPixmap(":/Game_Media/Pictures/plusLife.png");
                setPixmap(*plusLifePic);
                double scale = flake_size*3.5/boundingRect().width();
                setScale(scale);
                setPos(x(),scene()->height()-40-scale*boundingRect().height());
                snowflakeTimer->stop();
                QTimer::singleShot(2000, this, SLOT(snowflakeHit()));
                return;
            }
        }
    }
    //otherwise keep moving
    move();
}

/*
Destructor for greenSnowflake cleans up timer
and pixmaps for snowflake
*/
greenSnowflake::~greenSnowflake()
{
    delete plusLifePic; plusLifePic = nullptr;
    delete snowflake_pic; snowflake_pic = nullptr;
    delete snowflakeTimer;
    snowflakeTimer = nullptr;
}

