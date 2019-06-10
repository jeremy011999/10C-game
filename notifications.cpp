#include "notifications.h"

notifications::notifications()
{
    redpic = new QPixmap(":/Game_Media/Pictures/red.png");
    deadcounter = 0;
}

void notifications::display_lost_life()
{
    setPixmap(*redpic);
    double scale = (scene()->height()*2)/boundingRect().height();
    setScale(scale);
    setPos(-100,-100);
    setOpacity(.5);
    QTimer::singleShot(250, this, SLOT(lost_life_flash()));
}

void notifications::lost_life_flash()
{
    scene()->removeItem(this);
    delete this;
    return;
}

void notifications::display_dead()
{
    setPixmap(*redpic);
    double scale = (scene()->height()*2)/boundingRect().height();
    setScale(scale);
    setPos(-100,-100);
    setOpacity(.03);
    dyingtimer = new QTimer(this);
    connect(dyingtimer,SIGNAL(timeout()), this, SLOT(dying_animation()));
    dyingtimer->start(100);
}

void notifications::dying_animation()
{
    deadcounter++;
    //checks counter and sets opacity of animation
    if(deadcounter<32)
        setOpacity(.03+deadcounter*.03);
    //else, ends timer
    else {
        dyingtimer->stop();
    }
}



notifications::~notifications()
{
    delete redpic;
}


