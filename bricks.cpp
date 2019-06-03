#include "bricks.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

brick::brick(int bwidth,int bheight, int bricklevel):brick_width(bwidth),brick_height(bheight),brick_level(bricklevel),brick_type(bricklevel)
{
    if(brick_level==2)
    {
        darkbrick = new QPixmap(":/darkbrick.png");
        setPixmap(*darkbrick);
        scale = brick_width/boundingRect().width();
        setScale(scale);
    }
    else if(brick_level==1)
    {
        mediumbrick = new QPixmap(":/mediumbrick.png");
        setPixmap(*mediumbrick);
        scale = brick_width/boundingRect().width();
        setScale(scale);
    }
    else if(brick_level==0)
    {
        lightbrick = new QPixmap(":/lightbrick.png");
        setPixmap(*lightbrick);
        scale = brick_width/boundingRect().width();
        setScale(scale);
    }
}

void brick::update_hit_brick()
{
    emit update_points(10);
    if(brick_level==2)
    {
        darkcrack = new QPixmap(":/darkcrack.png");
        setPixmap(*darkcrack);
        scale = brick_width/boundingRect().width();
        setScale(scale);
        --brick_level;
    }
    else if(brick_level==1)
    {
        if(brick_type==2)
        {
            darkcrack2 = new QPixmap(":/darkcrack2.png");
            setPixmap(*darkcrack2);
        }
        else if(brick_type==1)
        {
            mediumcrack = new QPixmap(":/mediumcrack.png");
            setPixmap(*mediumcrack);
        }
        scale = brick_width/boundingRect().width();
        setScale(scale);
        --brick_level;
    }
    else if(brick_level==0)
    {
        scene()->removeItem(this);
        emit decrease_brick_count();
        delete this;
    }
}

void brick::destroy_brick()
{
    if(brick_level==0)
        emit update_points(10);
    else if(brick_level==1)
        emit update_points(20);
    else if(brick_level==2)
        emit update_points(30);
    emit decrease_brick_count();
    scene()->removeItem(this);
    delete this;
}

double  brick::getLeftX()
{
    return x();
}

double  brick::getRightX()
{
    return x() + boundingRect().width()*scale;
}

double brick::getTopY()
{
    return y();
}

double brick::getBottomY()
{
    return y() + boundingRect().height()*scale;
}

double brick::getMiddleX()
{
    return x() + boundingRect().width()*scale/2;
}


double brick::getMiddleY()
{
    return y() + boundingRect().width()*scale/2;
}

brick::~brick()
{
    delete darkbrick;  darkbrick = nullptr;
    delete darkcrack;  darkcrack = nullptr;
    delete darkcrack2; darkcrack2 = nullptr;
    delete mediumbrick; mediumbrick = nullptr;
    delete mediumcrack; mediumcrack = nullptr;
    delete lightbrick; lightbrick = nullptr;
}
