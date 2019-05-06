#include "paddle.h"
#include <QGraphicsScene>
#include <QDebug>

paddle::paddle():brick_width(50),brick_height(20)
{
    setRect(0,0,brick_width,brick_height);
    setBrush(Qt::red);
}

void paddle::move_left()
{
    if (x()<=0)
        return;
    else
        moveBy(-10,0);
}

void paddle::move_right()
{
    if(x()+brick_width>=scene()->width())
        return;
    else
        moveBy(10,0);
}


void paddle::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:{move_left();break;}
    case Qt::Key_Right:{move_right();break;}
    }
}
