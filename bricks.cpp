#include "bricks.h"


/*
Constructor for brick object
@param bwidth: sets brick width
@param bheight: set brick height
@param bricklevel: sets level of brick (darkness)
*/
brick::brick(int bwidth,int bheight, int bricklevel):brick_width(bwidth),brick_height(bheight),brick_level(bricklevel),brick_type(bricklevel)
{
    if(brick_level==2)
    {
        darkbrick = new QPixmap(":/Game_Media/Pictures/darkbrick.png");
        setPixmap(*darkbrick);
        scale = brick_width/boundingRect().width();
        setScale(scale);
    }
    else if(brick_level==1)
    {
        mediumbrick = new QPixmap(":/Game_Media/Pictures/mediumbrick.png");
        setPixmap(*mediumbrick);
        scale = brick_width/boundingRect().width();
        setScale(scale);
    }
    else if(brick_level==0)
    {
        lightbrick = new QPixmap(":/Game_Media/Pictures/lightbrick.png");
        setPixmap(*lightbrick);
        scale = brick_width/boundingRect().width();
        setScale(scale);
    }
}

/*
if brick is hit, updates picture as well as current brick level
and removes brick if necessary
*/
void brick::update_hit_brick()
{
    emit update_points(10);
    if(brick_level==2)
    {
        darkcrack = new QPixmap(":/Game_Media/Pictures/darkcrack.png");
        setPixmap(*darkcrack);
        scale = brick_width/boundingRect().width();
        setScale(scale);
        --brick_level;
    }
    else if(brick_level==1)
    {
        if(brick_type==2)
        {
            darkcrack2 = new QPixmap(":/Game_Media/Pictures/darkcrack2.png");
            setPixmap(*darkcrack2);
        }
        else if(brick_type==1)
        {
            mediumcrack = new QPixmap(":/Game_Media/Pictures/mediumcrack.png");
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

/*
destroys current brick and emits to game to get rid of it
and decrease brick count and increase points
*/
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

/*
returns left x coordinate of brick (for collisions)
@return: coordinate as a double
*/
double  brick::getLeftX()
{
    return x();
}

/*
returns right x coordinate of brick (for collisions)
@return: coordinate as a double
*/
double  brick::getRightX()
{
    return x() + boundingRect().width()*scale;
}

/*
returns top y coordinate of brick (for collisions)
@return: coordinate as a double
*/
double brick::getTopY()
{
    return y();
}

/*
returns bottom y coordinate of brick (for collisions)
@return: coordinate as a double
*/
double brick::getBottomY()
{
    return y() + boundingRect().height()*scale;
}

/*
returns middle x coordinate of brick (for collisions)
@return: coordinate as a double
*/
double brick::getMiddleX()
{
    return x() + boundingRect().width()*scale/2;
}

/*
returns middle y coordinate of brick (for collisions)
@return: coordinate as a double
*/
double brick::getMiddleY()
{
    return y() + boundingRect().width()*scale/2;
}

/*
destructor for brick in order to properly deallocate and clean up
pixmaps for brick pictures
*/
brick::~brick()
{
    delete darkbrick;  darkbrick = nullptr;
    delete darkcrack;  darkcrack = nullptr;
    delete darkcrack2; darkcrack2 = nullptr;
    delete mediumbrick; mediumbrick = nullptr;
    delete mediumcrack; mediumcrack = nullptr;
    delete lightbrick; lightbrick = nullptr;
}
