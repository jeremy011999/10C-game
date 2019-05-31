#include "paddle.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>

paddle::paddle(double width):paddle_width(width),is_powered_paddle(false)
{
    paddle_height = paddle_width/8;
    setRect(0,0,paddle_width,paddle_height);
    setBrush(Qt::red);
}

void paddle::move_left()
{
    if (x()<=2)
        return;
    else
        moveBy(-.05*scene()->width(),0);
    if(x()<=2)
        setPos(3,y());
}

void paddle::move_right()
{
    if(x()+paddle_width>=scene()->width()-2)
        return;
    else
        moveBy(.05*scene()->width(),0);
    if(x()+paddle_width>=scene()->width()-2)
        setPos(scene()->width()-3-paddle_width,y());
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
    ball* myball = nullptr;
    if(stick_ball)
    {
        QList<QGraphicsItem*> items_to_find_ball = scene()->items();
        for(int i=0;i<items_to_find_ball.size();i++)
        {
            if(typeid(*items_to_find_ball[i])==typeid(ball))
            {
                myball = dynamic_cast<ball*>(items_to_find_ball[i]);
                break;
            }
        }
    }

    switch(event->key()){
    case Qt::Key_Left:
    {
        move_left();
        if(stick_ball)
        {
            myball->setPos(this->x()+this->getwidth()/2-myball->get_size()/2,this->y()-myball->get_size()-2);
        }
        break;
    }
    case Qt::Key_Right:{
        move_right();
        if(stick_ball)
        {
            myball->setPos(this->x()+this->getwidth()/2-myball->get_size()/2,this->y()-myball->get_size()-2);
        }
        break;
    }
    case Qt::Key_Space:{
        space_press();
        stick_ball = false;
        break;}
    }
}

void paddle::paddleDied()
{
    emit paddleDead();
}

void paddle::space_press()
{
    emit space_bar_pressed();
}

void paddle::power_up_paddle()
{
    paddle_width=paddle_width*2;
    is_powered_paddle=true;
    setRect(0,0,paddle_width,paddle_height);
    setBrush(QColor(255,215,0));
    QTimer::singleShot(10000, this, SLOT(back_to_regular_paddle()));
}

bool paddle::power_up_paddle_active()
{
    return is_powered_paddle;
}
void paddle::back_to_regular_paddle()
{
    paddle_width = paddle_width/2;
    setRect(0,0,paddle_width,paddle_height);
    setBrush(Qt::red);
    is_powered_paddle = false;
}

void paddle::stick_ball_to_paddle()
{
    stick_ball=true;
}
