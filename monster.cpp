#include "monster.h"

Monster::Monster(double width):x_velocity(0),monster_width(width)
{
    y_velocity = .0452*width;
    
    //set picture for monster
    deadmonsterpic = new QPixmap(":/Game_Media/Pictures/deadmonster.png");
    livemonsterpic = new QPixmap(":/Game_Media/Pictures/monster.png");
    setPixmap(*livemonsterpic);
    double scale = monster_width/boundingRect().width();
    setScale(scale);
    
    monsterTimer = new QTimer(this);
    connect(monsterTimer,SIGNAL(timeout()),this,SLOT(updateMonster()));
    monsterTimer->start(25);
    
    //makes player to make sound when monster dies
    monsterplayer = new QMediaPlayer(this);
    monsterplayer->setMedia(QUrl("qrc:/Game_Media/Sounds/monstersound.mp3"));
    monsterplayer->setVolume(50);
}

void Monster::move()
{
    if(scene()!=nullptr)
        moveBy(x_velocity,y_velocity);
}



void Monster::updateMonster()
{
    bool dontmove = false;
    //If ball hits bottom of screen remove it and clean up its memory
    if(y()>scene()->height()&&y_velocity>0)
    {
        scene()->removeItem(this);
        delete(this);
        dontmove = true;
        return;
    }


    //Check for collisions with items
    QList<QGraphicsItem*> items_monster_hit = collidingItems();
    for(int i=0;i<items_monster_hit.size();i++)
    {
        //Check if the collision was with a ball
        if(typeid(*items_monster_hit[i])==typeid(ball))
        {
            emit update_points(20);
            killMonster();
            dontmove=true;
            return;
        }

        //Check if the paddle is hit
        else if(typeid(*items_monster_hit[i])==typeid(paddle))
        {
            paddle* hitpaddle = dynamic_cast<paddle*>(items_monster_hit[i]);
            if(!hitpaddle->power_up_paddle_active())
            {
                scene()->removeItem(this);
                hitpaddle->paddleDied();
                delete this;
                dontmove = true;
                return;
            }
        }
    }
    if(!dontmove)
        move();
}


void Monster::killMonster()
{
    monsterTimer->stop();
    x_velocity = 0; y_velocity = 0;
    monsterplayer->play();
    dyingMonsterAnimation();
}

void Monster::dyingMonsterAnimation()
{
    //make the monster flash when it dies
    flashcount = 0;
    QTimer* dyingAnimationTimer = new QTimer(this);
    connect(dyingAnimationTimer,SIGNAL(timeout()),this,SLOT(updateImage()));
    dyingAnimationTimer->start(250);
    setPixmap(*deadmonsterpic);
    double scale = monster_width*1.1/boundingRect().width();
    setScale(scale);
    livepic=false;
}

void Monster::updateImage()
{
    //switches back and forth between live and dead monster images to make an animation
    if(livepic == true)
    {
        setPixmap(*deadmonsterpic);
        double scale = monster_width*1.1/boundingRect().width();
        setScale(scale);
        livepic=false;
    }
    else
    {
        setPixmap(*livemonsterpic);
        double scale = monster_width/boundingRect().width();
        setScale(scale);
        livepic = true;
    }
    flashcount++;
    if(flashcount>=6&&flashcount<=8)
    {
        _20pointspic = new QPixmap(":/Game_Media/Pictures/20points.png");
        setPixmap(*_20pointspic);
        double scale = monster_width/boundingRect().width();
        setScale(scale);
    }
    if(flashcount>8)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}

Monster::~Monster()
{
    delete deadmonsterpic;
    delete livemonsterpic;
    delete _20pointspic;
    deadmonsterpic = nullptr;
    livemonsterpic = nullptr;
    _20pointspic = nullptr;
}

void Monster::mute_monster()
{
    muted = true;
    monsterplayer->setVolume(0);
}

