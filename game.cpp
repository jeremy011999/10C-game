#include "game.h"
#include <QGraphicsSceneWheelEvent>
#include <QString>
#include <QMouseEvent>
#include <QObject>
#include <QTimer>
#include <QDebug>

game::game()
{
    //Make a window for the game to be played in and give it a layout
    gamePlayWindow = new QWidget;
    gamePlayLayout = new QVBoxLayout(gamePlayWindow);

    //Add a quit button
    QPushButton* quitButton = new QPushButton("QUIT GAME");
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitGame()));
    gamePlayLayout->addWidget(quitButton);

    //Add points label and view  to game layout
    score_label = new QLabel("Score: " + QString::number(points));
    gamePlayLayout->addWidget(score_label);
}

void game::run_game()
{
    //Set up the graphics view
    setUpGraphicsView();

    //Set up the bricks, parameter is the level
    SetUpBricks(2);

    //Make ball and add to scene
    ball* myball = new ball;
    gamescene->addItem(myball);
    connect(myball,SIGNAL(hit_a_brick()),this,SLOT(update_score_on_brick_hit()));
    connect(myball,SIGNAL(ball_hit_ground()),this,SLOT(died()));

    //set position of the ball in the scene
    myball->setPos(gamescene->width()/2,gamescene->height()/2);
}

void game::setUpGraphicsView()
{

    if(gamescene!=nullptr)
    {
        gamePlayLayout->removeWidget(view);
        delete view;
        view = nullptr;
        delete gamescene;
        gamescene = nullptr;
    }

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

    //make paddle and add to scene
    mypaddle = new paddle;
    gamescene->addItem(mypaddle);

    //set position of the paddle in the scene
    mypaddle->setPos(gamescene->width()/2,gamescene->height()-30);

    //Make paddle focusable and set a timer to make sure nothing else overrides the paddle focus throughout the program
    mypaddle->setFlag(QGraphicsItem::ItemIsFocusable);
    QTimer* focustimer = new QTimer(this);
    connect(focustimer, SIGNAL(timeout()),this,SLOT(setpaddlefocus()));
    focustimer->start(15);
    mypaddle->setFocus();
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


QWidget* game::getGamePlayWindow()
{
    return gamePlayWindow;
}

void game::died()
{
    emit time_to_enter_results_screen(points);
    points = 0;
    score_label->setText("Score: " + QString::number(points));

}

void game::quitGame()
{
    emit time_to_exit_game_screen();
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


