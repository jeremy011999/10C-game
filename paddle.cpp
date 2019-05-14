#include "paddle.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>

paddle::paddle():paddle_width(80),paddle_height(10),is_powered_paddle(false)
{
    setRect(0,0,paddle_width,paddle_height);
    setBrush(Qt::red);
}

void paddle::move_left()
{
    if (x()<=0)
        return;
    else
        moveBy(-20,0);
}

void paddle::move_right()
{
    if(x()+paddle_width>=scene()->width())
        return;
    else
        moveBy(20,0);
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

void paddle::power_up_paddle()
{
    paddle_width=150;
    is_powered_paddle=true;
    setRect(0,0,paddle_width,paddle_height);
    QTimer::singleShot(10000, this, SLOT(back_to_regular_paddle()));
}

bool paddle::power_up_paddle_active()
{
    return is_powered_paddle;
}
void paddle::back_to_regular_paddle()
{
    paddle_width = 80;
    setRect(0,0,paddle_width,paddle_height);
    is_powered_paddle = false;
}
