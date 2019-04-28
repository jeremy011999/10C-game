#include "paddle.h"

paddle::paddle()
{
    setRect(0,0,50,20);
}

bool paddle::hit_wall_left()
{
    if (rectangle.left()==left_side)
        return false;
    else
        return true;
}

bool paddle::hit_wall_right()
{
        if(rectangle.right()==right_side)
            return false;
        else
            return true;
}

void paddle::move_left()
{
    x-=10;
}

void paddle::move_right()
{
    x+=10;
}

void paddle::set_left_side(qreal point)
{
    left_side=point;
}

void paddle::set_right_side(qreal point)
{
    right_side=point;
}

