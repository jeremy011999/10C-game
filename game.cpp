#include "game.h"
#include <QGraphicsSceneWheelEvent>
#include <QString>

game::game()
{
    w = new welcome_window();
    connect(w,SIGNAL(startGame()),this,SLOT(run_game()));
    w->show();
}



void game::run_game()
{
    QWidget* gamewindow = new QWidget;
    QVBoxLayout* gamelayout = new QVBoxLayout(gamewindow);

    //Make Scene and View
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsView* view = new QGraphicsView(scene);
    view->setBackgroundBrush(QBrush(QColor(219, 229, 249),Qt::Dense1Pattern));
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Add points and view label to game layout
    gamelayout->addWidget(new QLabel("Score: " + QString::number(points)));
    gamelayout->addWidget(view);



    //Fix the size of the view and set the scene size to it
    view->setFixedSize(400,500);
    scene->setSceneRect(0,0,400,500);

    //Make ball and add to scene
    ball* myball = new ball;
    scene->addItem(myball);

    //set position of the ball in the scene
    myball->setPos(scene->width()/2,scene->height()/2);


    //make paddle and add to scene
    paddle* mypaddle = new paddle;
    scene->addItem(mypaddle);

    //set position of the paddle in the scene
    mypaddle->setPos(scene->width()/2,scene->height()-20);
    mypaddle->setFlag(QGraphicsItem::ItemIsFocusable);
    mypaddle->setFocus();

    //add bricks to the scene
    for(int j=0;j<4;j++)
    {
        for (int i=0;i<9;i++)
        {
            int bricklevel = (i+j)%3;
            brick* brick_to_add = new brick(scene->width()/9,25,bricklevel);
            scene->addItem(brick_to_add);
            //set position of new brick in the scene
            brick_to_add->setPos(45*i,25*j);
        }
    }

    //show the scene
    gamewindow->show();
}


