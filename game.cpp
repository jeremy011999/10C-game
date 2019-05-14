#include "game.h"
#include <QGraphicsSceneWheelEvent>
#include <QString>
#include <QMouseEvent>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QTime>
#include <QRandomGenerator>

game::game()
{
    //Make a window for the game to be played in and give it a layout
    gamePlayWindow = new QWidget;
    gamePlayLayout = new QVBoxLayout(gamePlayWindow);

    //Add a quit button
    QPushButton* quitButton = new QPushButton("QUIT GAME");
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitGame()));
    gamePlayLayout->addWidget(quitButton);

    //Add points label
    score_label = new QLabel("Score: " + QString::number(points));
    gamePlayLayout->addWidget(score_label);


    //Make Scene and View for gameplay graphics
    gamescene = new QGraphicsScene();
    view = new QGraphicsView(gamescene);

    //Set color of view
    view->setBackgroundBrush(QBrush(QColor(219, 229, 249),Qt::Dense1Pattern));

    //Make the view unscrollable
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Fix the size of the view and set the scene size to it
    view->setFixedSize(400,500);
    gamescene->setSceneRect(0,0,400,500);

    //Add view to gamelayout
    gamePlayLayout->addWidget(view);
}

void game::run_game()
{
    view->setFocus();
    //Set up the bricks, parameter is the level
    SetUpBricks(2);

    //Make ball and add to scene
    ball* myball = new ball;
    gamescene->addItem(myball);
    ballcount = 1;
    connect(myball,SIGNAL(ball_hit_ground()),this,SLOT(died()));

    //set position of the ball in the scene
    myball->setPos(gamescene->width()/2,gamescene->height()/2+5);


    //make paddle and add to scene
    mypaddle = new paddle;
    gamescene->addItem(mypaddle);

    //set position of the paddle in the scene
    mypaddle->setPos(gamescene->width()/2,gamescene->height()-30);

    //Make paddle focusable and set a timer to make sure nothing else overrides the paddle focus throughout the program
    mypaddle->setFlag(QGraphicsItem::ItemIsFocusable);
    focustimer = new QTimer(this);
    connect(focustimer, SIGNAL(timeout()),this,SLOT(setpaddlefocus()));
    focustimer->start(15);
    mypaddle->setFocus();
}


void game::setpaddlefocus()
{
    if(mypaddle!=nullptr)
    {
       mypaddle->setFocus();
    }
}

void game::update_score_on_brick_hit(int pnts)
{
    points+=pnts;
    score_label->setText("Score: " + QString::number(points));
    if(points%100==0)
    {
        runPowerup();
    }
}


QWidget* game::getGamePlayWindow()
{
    return gamePlayWindow;
}

void game::died()
{
    ballcount--;
    if(ballcount==0)
    {
        emit time_to_enter_results_screen(points);
        gamescene->clear();
        mypaddle=nullptr;
        points = 0;
        score_label->setText("Score: " + QString::number(points));
    }
}

void game::quitGame()
{
    emit time_to_exit_game_screen();
    gamescene->clear();
    mypaddle=nullptr;
    points = 0;
    score_label->setText("Score: " + QString::number(points));
}

/*
 * Make bricks set up
 *
 * @param level
 */
void game::SetUpBricks(int game_level)
{
    if(game_level==1)
    {
        //add bricks to the scene
        for(int j=0;j<4;j++)
        {
            for (int i=0;i<9;i++)
            {
                int bricklevel = (i+j)%3;
                brick* brick_to_add = new brick(gamescene->width()/9,25,bricklevel);
                connect(brick_to_add,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                gamescene->addItem(brick_to_add);
                //set position of new brick in the scene
                brick_to_add->setPos(45*i,25*j);
            }
        }
     }
    if(game_level==2)
    {
        //add bricks to the scene
        for(int j=0;j<4;j++)
        {
            for (int i=0;i<12;i++)
            {
                int bricklevel = (i+j)%3;
                brick* brick_to_add = new brick(gamescene->width()/12,20,bricklevel);
                connect(brick_to_add,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                gamescene->addItem(brick_to_add);
                //set position of new brick in the scene
                brick_to_add->setPos(gamescene->width()/12*i,20*j);
            }
        }
    }
}

void game::runPowerup()
{
    int randomVal = qrand()%2;
    if(randomVal==0)
    {
        ballcount += 2;
        for(int i=0;i<2;i++)
        {
            ball* myball = new ball;
            gamescene->addItem(myball);
            connect(myball,SIGNAL(ball_hit_ground()),this,SLOT(died()));
            //set position of the ball in the scene
            myball->setPos(mypaddle->x()+mypaddle->getwidth(),mypaddle->y()-41-i*10);
        }
    }
    else if(randomVal==1)
    {
        QList<QGraphicsItem*> items_list = gamescene->items();
        for(int i=0;i<items_list.size();i++)
        {
            if(typeid(*items_list[i])==typeid(ball))
                dynamic_cast<ball*>(items_list[i])->power_up_ball();
        }
    }
}


