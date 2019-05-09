#include "paddle.h"
#include <QGraphicsScene>
#include <QDebug>

paddle::paddle():paddle_width(50),paddle_height(20)
{
    setRect(0,0,paddle_width,paddle_height);
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
    if(x()+paddle_width>=scene()->width())
        return;
    else
        moveBy(10,0);
}

qreal paddle::getMiddleXCoord()
{
    return x()+paddle_width/2;
}

int paddle::getwidth()
{
    return paddle_width;
}


void paddle::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:{move_left();break;}
    case Qt::Key_Right:{move_right();break;}
    }
}
