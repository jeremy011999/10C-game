#include "powerupmeter.h"

powerUpMeter::powerUpMeter(QWidget *parent)
    : QWidget(parent)
{
    setMaximumSize(200,200);
    setMinimumSize(200,200);
}

void powerUpMeter::paintEvent(QPaintEvent *e)
{
    //set the pix map of the powerup meter depending on the counter
    QPainter painter(this);
    if(counter == 0)
         painter.drawPixmap(0, 0, (*emptySnowflake).scaled(this->size()));
    else if(counter == 1)
         painter.drawPixmap(0, 0, (*snowflakeFill1).scaled(this->size()));
    else if(counter == 2)
         painter.drawPixmap(0, 0, (*snowflakeFill2).scaled(this->size()));
    else if(counter == 3)
         painter.drawPixmap(0, 0, (*snowflakeFill3).scaled(this->size()));
    QWidget::paintEvent(e);
}

bool powerUpMeter::is_full()
{
    //see if meter is full
    return counter==3;
}

bool powerUpMeter::is_empty()
{
    //see if meter is empty
    return counter==0;
}

void powerUpMeter::update_counter()
{
    //update the counter value between 0,1,2,3
    counter++;
    counter = counter % 4;
    repaint();
}

void powerUpMeter::set_counter(int num)
{
    //allows the counter to be set to a certain value. Mod 4 makes sure value is between 0-3
    counter = num % 4;
    repaint();
}

powerUpMeter::~powerUpMeter()
{
    //deallocate image memory
    delete  emptySnowflake;  emptySnowflake = nullptr;
    delete  snowflakeFill1; snowflakeFill1 = nullptr;
    delete  snowflakeFill2; snowflakeFill2 = nullptr;
    delete  snowflakeFill3; snowflakeFill3 = nullptr;
}
