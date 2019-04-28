#include "bricks.h"

brick::brick(int bwidth,int bheight):brick_width(bwidth),brick_height(bheight)
{
    setRect(0,0,brick_width,brick_height);
}

