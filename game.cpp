#include "game.h"
#include <QGraphicsSceneWheelEvent>
#include <QString>
#include <QMouseEvent>
#include <QObject>
#include <QTimer>

game::game()
{
    //Initialize the game class's welcome window
    welcomewindow = new welcome_window();

    /*
     * Connect the welcome window to game class to start a game
     * startGame() is a signal called from welcome_window when the start game button is pressed
     * run_game() is a slot in game class that starts the game
     */
    connect(welcomewindow,SIGNAL(startGame()),this,SLOT(run_game()));

    //Show the welcome window to the user
    welcomewindow->show();

    //Make a window for the game to be played in and give it a layout
    gamewindow = new QWidget;
    QVBoxLayout* gamelayout = new QVBoxLayout(gamewindow);


    //Make Scene and View for gameplay graphics
    gamescene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView(gamescene);

    //Set color of view
    view->setBackgroundBrush(QBrush(QColor(219, 229, 249),Qt::Dense1Pattern));

    //Make the view unscrollable
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //Add points label and view  to game layout
    score_label = new QLabel("Score: " + QString::number(points));
    gamelayout->addWidget(score_label);
    gamelayout->addWidget(view);

    //Fix the size of the view and set the scene size to it
    view->setFixedSize(400,500);
    gamescene->setSceneRect(0,0,400,500);
}


void game::run_game()
{


    //Make ball and add to scene
    ball* myball = new ball;
    gamescene->addItem(myball);
    connect(myball,SIGNAL(hit_a_brick()),this,SLOT(update_score_on_brick_hit()));

    //set position of the ball in the scene
    myball->setPos(gamescene->width()/2,gamescene->height()/2);


    //make paddle and add to scene
    mypaddle = new paddle;
    gamescene->addItem(mypaddle);

    //set position of the paddle in the scene
    mypaddle->setPos(gamescene->width()/2,gamescene->height()-20);

    //Make paddle focusable and set a timer to make sure nothing else overrides the paddle focus throughout the program
    mypaddle->setFlag(QGraphicsItem::ItemIsFocusable);
    QTimer* focustimer = new QTimer(this);
    connect(focustimer, SIGNAL(timeout()),this,SLOT(setpaddlefocus()));
    focustimer->start(15);
    mypaddle->setFocus();

    this->SetUpBricks(2);

    //show the scene
    gamewindow->show();
}

void game::setpaddlefocus()
{
    mypaddle->setFocus();
}

void game::update_score_on_brick_hit()
{
    points+=10;
    score_label->setText("Score: " + QString::number(points));
}

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
                gamescene->addItem(brick_to_add);
                //set position of new brick in the scene
                brick_to_add->setPos(gamescene->width()/12*i,20*j);
            }
        }
     }
}


