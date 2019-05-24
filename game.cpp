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
    //Set seed for random number generator
    qsrand(QTime::currentTime().msecsSinceStartOfDay());
    std::srand(time(NULL));

    //Make a window for the game to be played in and give it a layout
    gamePlayWindow = new QWidget;
    gamePlayLayout = new QVBoxLayout(gamePlayWindow);

    //Make a timer that generates monsters (won't start timer until run-game function explicitly starts it)
    generateMonstersTimer = new QTimer(gamescene);
    connect(generateMonstersTimer,SIGNAL(timeout()),this,SLOT(monsterGenerator()));

    //make snowflakes timer
    generateSnowflakesTimer = new QTimer(gamescene);
    connect(generateSnowflakesTimer,SIGNAL(timeout()),this,SLOT(snowflakesGenerator()));

    //Add a quit button to return to the home screen
    QPushButton* quitButton = new QPushButton("QUIT GAME");
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitGame()));
    quitButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(9,87,162); color: rgb(255, 255, 255);}"));
    gamePlayLayout->addWidget(quitButton);

    //Add points label
    score_label = new QLabel("Score: " + QString::number(points));
    score_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 15px; background-color: rgb(158,219,235); color: rgb(255, 255, 255);}"));
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


    power_up_timer = new QLabel ("Power-Up Time Remaining: ");
    gamePlayLayout->addWidget(power_up_timer);

    //Add progress bar to gamelayout
    powerup_meter = new QProgressBar();
    powerup_meter->setOrientation(Qt::Vertical);
    powerup_meter->setMinimum(0);
    powerup_meter->setMaximum(100);
    powerup_meter->setValue(0);
    gamePlayLayout->addWidget(powerup_meter);

    //Make a horizontal layout so that the progress bar is to the right of the game view
    QHBoxLayout* horizontalbox = new QHBoxLayout();
    horizontalbox->addWidget(view);
    horizontalbox->addSpacing(50);
    horizontalbox->addWidget(powerup_meter);
    horizontalbox->addWidget(power_up_timer);

    //Add view and powerup layout to gamelayout
    gamePlayLayout->addLayout(horizontalbox);

    //Make a music player for the game
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/bensoundjazzyfrenchy.mp3"));

    //setvolume of the music player if not muted
    if (!muted)
        music->setVolume(100);
    else {
        music->setVolume(0);
    }

    //make a timer that continually sets the paddle as the focus once started
    //this timer is needed to  fix bugs that would take the focus off the paddle, making it uncontrollable during gameplay
    focustimer = new QTimer(this);
    connect(focustimer, SIGNAL(timeout()),this,SLOT(setpaddlefocus()));
}

void game::run_game(int lvl)
{
    //set the game level
    game_level=lvl;

    //reset the powerup meter
    powerup_meter->setValue(0);

    //start playing the music
    music->play();

    //Set the view as the focus of the game widget
    view->setFocus();

    //Set up the bricks, depending on level
    SetUpBricks(game_level);

    //Make ball and add to scene
    ball* myball = new ball;
    gamescene->addItem(myball);
    if(muted)
        myball->mute_ball();
    ballcount = 1;
    connect(myball,SIGNAL(ball_hit_ground()),this,SLOT(a_ball_hit_ground()));
    myball->set_level(0);

    //set position of the ball in the scene
    myball->setPos(gamescene->width()/2,gamescene->height()/2+5);

    //make paddle and add to scene
    mypaddle = new paddle;
    gamescene->addItem(mypaddle);
    connect(mypaddle,SIGNAL(paddleDead()),this,SLOT(killedByMonster()));

    //set position of the paddle in the scene
    mypaddle->setPos(gamescene->width()/2,gamescene->height()-30);

    //Make paddle focusable and set a timer to make sure nothing else overrides the paddle focus throughout the program
    mypaddle->setFlag(QGraphicsItem::ItemIsFocusable);

    //Set paddle as the focus
    mypaddle->setFocus();

    //Start timer that will refocus the paddle
    focustimer->start(500);




    //set monster timer/ball speed depending on game level
    if(game_level==1)
    {
        myball->set_level(0);
    }
    else if(game_level==2)
    {
        generateMonstersTimer->start(5000);
        myball->set_level(0);
        generateSnowflakesTimer->start(13000);
    }

}

void game::monsterGenerator()
{
    int randInt = qrand() % static_cast<int>(gamescene->width()-50);
    Monster* mymonster = new Monster();
    connect(mymonster,SIGNAL(update_points(int)),this,SLOT(update_score_on_monster_hit(int)));
    gamescene->addItem(mymonster);
    mymonster->setPos(randInt,50);
}

void game::snowflakesGenerator()
{
    if(some_power_up_is_active())
        return;
    int randInt = qrand() % static_cast<int>(gamescene->width()-50);
    snowflake* mysnowflake = new snowflake();
    connect(mysnowflake,SIGNAL(update_meter()),this,SLOT(update_meter_on_snowflake_capture()));
    gamescene->addItem(mysnowflake);
    mysnowflake->setPos(randInt,50);
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
    update_powerup_meter();
    if(powerup_meter->value()==100&&!some_power_up_is_active())
    {
        runPowerup();
        powerup_meter->setValue(0);
    }
}

void game::update_score_on_monster_hit(int pnts)
{
    points+=pnts;
    score_label->setText("Score: " + QString::number(points));
}

void game::update_meter_on_snowflake_capture()
{
    //Only add to powerup meter if no powerup is active
    if(!some_power_up_is_active())
    {
        if(powerup_meter->value()<powerup_meter->maximum()-30)
            powerup_meter->setValue(powerup_meter->value()+30);
        else {
            runPowerup();
            powerup_meter->setValue(0);
        }
    }
}


void game::update_powerup_meter()
{
    //Only add to powerup meter if no powerup is active
    if(!some_power_up_is_active())
        powerup_meter->setValue(powerup_meter->value()+10);
}

bool game::some_power_up_is_active()
{
    bool there_is_a_powered_ball=false;
    bool there_are_multiple_balls=false;
    bool paddle_is_powered = false;

    //Check if there is a red powerup ball active
    QList<QGraphicsItem*> items_list = gamescene->items();
    for(int i=0;i<items_list.size();i++)
    {
        if(typeid(*items_list[i])==typeid(ball))
        {
            if(dynamic_cast<ball*>(items_list[i])->power_up_ball_active())
            {
                there_is_a_powered_ball=true;
                break;
            }
        }
    }

    //Check if there are multiple balls in the scene
    if(ballcount>1)
        there_are_multiple_balls=true;


    //Check if there is a big paddle
    if(mypaddle != nullptr)
    {
        if(mypaddle->power_up_paddle_active())
        paddle_is_powered = true;
    }


    //If any of the above are true, then the powerup is active
    if(there_are_multiple_balls||there_is_a_powered_ball||paddle_is_powered)
        return true;
    else
        return false;
}


QWidget* game::getGamePlayWindow()
{
    return gamePlayWindow;
}

void game::clean_up_board()
{
  if(mypaddle!=nullptr)
  {
      gamescene->clear();
      mypaddle = nullptr;
      focustimer->stop();
      generateMonstersTimer->stop();
      generateSnowflakesTimer->stop();
  }
}

void game::reset_game()
{
  clean_up_board();
  game_level = 0;
  ballcount = 0;
  points = 0;
  score_label->setText("Score: " + QString::number(points));
  music->stop();
}

void game::a_ball_hit_ground()
{
  ballcount--;
  if(ballcount==0)
  {
    emit time_to_enter_results_screen(points);
    reset_game();
  }
}

void game::killedByMonster()
{
    emit time_to_enter_results_screen(points);
    reset_game();
}

void game::quitGame()
{
    emit time_to_exit_game_screen();
    reset_game();
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
    if(game_level==3)
    {
        //add bricks to the scene
        //add bricks to the scene
        for(int j=1;j<7;j++)
        {
            for (int i=0;i<j;i++)
            {
                int bricklevel = (i+j)%3;
                brick* brick_to_add_left_top = new brick(gamescene->width()/12,20,bricklevel);
                connect(brick_to_add_left_top,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                gamescene->addItem(brick_to_add_left_top);
                brick* brick_to_add_right_top = new brick(gamescene->width()/12,20,bricklevel);
                connect(brick_to_add_right_top,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                gamescene->addItem(brick_to_add_right_top);
                brick* brick_to_add_left_bottom = new brick(gamescene->width()/12,20,bricklevel);
                connect(brick_to_add_left_bottom,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                gamescene->addItem(brick_to_add_left_bottom);
                brick* brick_to_add_right_bottom = new brick(gamescene->width()/12,20,bricklevel);
                connect(brick_to_add_right_bottom,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                gamescene->addItem(brick_to_add_right_bottom);
                //set position of new brick in the scene
                brick_to_add_left_top->setPos(gamescene->width()/12*(5-i),20*(j-1));
                brick_to_add_right_top->setPos(gamescene->width()/12*(6+i),20*(j-1));
                brick_to_add_left_bottom->setPos(gamescene->width()/12*(5-i),20*(12-j));
                brick_to_add_right_bottom->setPos(gamescene->width()/12*(6+i),20*(12-j));
            }
        }
    }
    if (game_level==2)
    {
        for (int i=0; i<7;i++)
        {
            if (i%2==0)
            {
            for (int j=0;j<11;j++)
            {


                int bricklevel=0;
                if (j<=3)
                    bricklevel=2;
                else if (j<=7)
                    bricklevel=1;
                else if (j<=11)
                    bricklevel=0;

                brick* brick_to_add = new brick(gamescene->width()/7,20,bricklevel);
                connect(brick_to_add,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                gamescene->addItem(brick_to_add);
                brick_to_add->setPos(gamescene->width()/7*i,20*j);

            }
            }
        }
    }
    if (game_level==4)
    {
        int bricklevel=1;
        std::vector<brick*> bricks;
        double unit_width = gamescene->width()/12.0;
        double unit_height= 20.0;
        for (int i=0; i<19;i++)
        {
        brick* brick_to_add = new brick(gamescene->width()/12,25,bricklevel);
        connect(brick_to_add,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
        bricks.push_back(brick_to_add);
        gamescene->addItem(bricks[i]);
        }
        bricks[0]->setPos(3*unit_width,unit_height);
        bricks[1]->setPos(8*unit_width,unit_height);
        bricks[2]->setPos(5.5*unit_width,3*unit_height);
        for (int i=3; i<=10;i++)
        {
            if (i<7)
                bricks[i]->setPos(unit_width*1,unit_height*(i+2));
            else
            {
                bricks[i]->setPos(unit_width*10,unit_height*(i-2));
            }
        }
        for (int i=11; i<bricks.size();i++)
        {
            bricks[i]->setPos(unit_width*(i-9),unit_height*8);
        }

    }
    if (game_level==5)
    {
        int bricklevel=1;
        std::vector<brick*> bricks;
        double unit_width = gamescene->width()/13.0;
        double unit_height= 20.0;
        for (int i=0; i<49;i++)
        {
        brick* brick_to_add = new brick(gamescene->width()/12,25,bricklevel);
        connect(brick_to_add,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
        bricks.push_back(brick_to_add);
        gamescene->addItem(bricks[i]);
        }
        bricks[0]->setPos(unit_width*1,unit_height*1);
        bricks[1]->setPos(unit_width*2,unit_height*1);
        bricks[2]->setPos(unit_width*5,unit_height*1);
        bricks[3]->setPos(unit_width*6,unit_height*1);
        bricks[4]->setPos(unit_width*7,unit_height*1);
        bricks[5]->setPos(unit_width*9,unit_height*1);
        bricks[6]->setPos(unit_width*10,unit_height*1);
        bricks[7]->setPos(unit_width*11,unit_height*1);
        bricks[8]->setPos(unit_width*1,unit_height*10);
        bricks[9]->setPos(unit_width*2,unit_height*10);
        bricks[10]->setPos(unit_width*3,unit_height*10);
        bricks[11]->setPos(unit_width*5,unit_height*10);
        bricks[12]->setPos(unit_width*6,unit_height*10);
        bricks[13]->setPos(unit_width*7,unit_height*10);
        bricks[14]->setPos(unit_width*9,unit_height*10);
        bricks[15]->setPos(unit_width*10,unit_height*10);
        bricks[16]->setPos(unit_width*11,unit_height*10);
        for (int i=17; i<bricks.size();i++)
        {
            if (i<25)
            {
                bricks[i]->setPos(unit_width*2,unit_height*(i-15));
            }
            else if (i<33)
            {
                bricks[i]->setPos(unit_width*5,unit_height*(i-23));
            }
            else if (i<41)
            {
                bricks[i]->setPos(unit_width*7,unit_height*(i-31));
            }
            else
            {
                bricks[i]->setPos(unit_width*9,unit_height*(i-39));
            }
        }
    }

}

void game::runPowerup()
{
    //power_up_time= new QTimer;
    QTime time = QTime::currentTime();
    int randomVal = std::rand()%3;
    if(randomVal==0)
    {
        ballcount += 2;
        for(int i=0;i<2;i++)
        {
            ball* myball = new ball;
            if(muted)
                myball->mute_ball();
            gamescene->addItem(myball);
            connect(myball,SIGNAL(ball_hit_ground()),this,SLOT(a_ball_hit_ground()));
            //set position of the ball in the scene
            myball->setPos(mypaddle->x()+mypaddle->getwidth(),mypaddle->y()-41-i*10);
        }
    }


    else if(randomVal==1)
    {
        power_time=4;
        QList<QGraphicsItem*> items_list = gamescene->items();
        for(int i=0;i<items_list.size();i++)
        {
            if(typeid(*items_list[i])==typeid(ball))
                dynamic_cast<ball*>(items_list[i])->power_up_ball();
        }
    }
    else
    {
        power_time=9;
        mypaddle->power_up_paddle();
    }
    run_powerup_bar_flash_animation();
}

void game::run_powerup_bar_flash_animation()
{
    flash_animation_timer = new QTimer(this);
    power_up_time= new QTimer(this);
    connect(flash_animation_timer,SIGNAL(timeout()),this,SLOT(powerup_meter_flash_helper()));
    connect(power_up_time,SIGNAL(timeout()),this,SLOT(change_time()));
    flash_animation_timer->start(150);
    power_up_time->start(1000);
}

void game::powerup_meter_flash_helper()
{
    if(some_power_up_is_active())
    {
        if(powerup_meter->value()==0)
        {
            powerup_meter->setValue(100);
        }
        else if(powerup_meter->value()==100)
        {
            powerup_meter->setValue(0);
        }
    }
    else
    {
        flash_animation_timer->stop();
        delete flash_animation_timer;
        flash_animation_timer = nullptr;
        powerup_meter->setValue(0);
        return;
    }
}

void game::change_time()
{
    if (ballcount>1)
        return;
    if(some_power_up_is_active())
    {
        QString s1= "Power-Up Time Remaining: "+QString::number(power_time);
    power_up_timer->setText(s1);
    power_time--;
    }
    else
    {
        power_up_time->stop();
        delete power_up_time;
        power_up_time=nullptr;
        power_up_timer->setText("Power-Up Time Remaining: ");
    }
}

void game::mute_sound()
{
    if (muted)
        muted=false;
    else
        muted=true;

    //setvolume
    if (!muted)
        music->setVolume(100);
    else {
        music->setVolume(0);
    }
}

