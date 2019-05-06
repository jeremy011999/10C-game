#include "bricks.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

brick::brick(int bwidth,int bheight, int bricklevel):brick_width(bwidth),brick_height(bheight),brick_level(bricklevel)
{
    setRect(0,0,brick_width,brick_height);
    if(brick_level==2)
    {
        setBrush(QColor(9,87,162));
    }
    else if(brick_level==1)
        setBrush(QColor(30,145,202));
    else if(brick_level==0)
        setBrush(QColor(158,219,235));
}

void brick::update_hit_brick()
{
    if(brick_level==2)
    {
        setBrush(QColor(30,145,202));
        --brick_level;
    }
    else if(brick_level==1)
    {
        setBrush(QColor(158,219,235));
        --brick_level;
    }
    else if(brick_level==0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
