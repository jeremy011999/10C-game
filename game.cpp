#include "game.h"
#include <QGraphicsSceneWheelEvent>
#include <QString>
#include <QMouseEvent>
#include <QObject>
#include <QTimer>
#include <QDebug>

game::game()
{   //Make a welcome window
    welcomeWindow = new welcome_window;

    //Connect welcome window to play_game() function
    QObject::connect(welcomeWindow,SIGNAL(startGame()),this,SLOT(run_game()));

    //Make a window for the game to be played in and give it a layout
    gamePlayWindow = new QWidget;
    gamePlayLayout = new QVBoxLayout(gamePlayWindow);

    //Make a stacked widget
    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(welcomeWindow);
    stackedWidget->addWidget(gamePlayWindow);
    goToWelcomeWindow();


    //Add points label and view  to game layout
    score_label = new QLabel("Score: " + QString::number(points));
    gamePlayLayout->addWidget(score_label);
    stackedWidget->show();
}


void game::setUpGraphicsView()
{
    if(gamescene!=nullptr)
    {
        gamePlayLayout->removeWidget(view);
        delete view;
        delete gamescene;
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


void game::run_game()
{
    goToGamePlayWindow();
    //Run setUpGraphicsView() to delete any graphics view that was there previously and set up a new one with a paddle
    setUpGraphicsView();

    //Set up the bricks, parameter is the level
    this->SetUpBricks(2);

    //Make ball and add to scene
    ball* myball = new ball;
    gamescene->addItem(myball);
    connect(myball,SIGNAL(hit_a_brick()),this,SLOT(update_score_on_brick_hit()));
    connect(myball,SIGNAL(ball_hit_ground()),this,SLOT(died()));

    //set position of the ball in the scene
    myball->setPos(gamescene->width()/2,gamescene->height()/2);

    //show the scene
   // gamePlayWindow->show();
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

void game::goToGamePlayWindow()
{
    stackedWidget->setCurrentIndex(1);
}

void game::goToWelcomeWindow()
{
    stackedWidget->setCurrentIndex(0);
}

void game::died()
{
//    delete gamewindow;
//    gamewindow = new QWidget;
//   // QWidget* scorewindow = new QWidget;
//    QLabel* score_report = new QLabel("Your score is " + QString::number(points));
//    QVBoxLayout* layout = new QVBoxLayout(gamewindow);
//    layout->addWidget(score_report);
 //   gamePlayWindow->hide();
}

