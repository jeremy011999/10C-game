#include "game.h"
#include <QGraphicsSceneWheelEvent>
#include <QString>
#include <QMouseEvent>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QTime>
#include <ctime>




game::game()
{
    //Make Scene and View for gameplay graphics
    gamescene = new QGraphicsScene();
    view = new QGraphicsView(gamescene);

    //Set seed for random number generator
    srand(QTime::currentTime().msecsSinceStartOfDay());

    //Make a window for the game to be played in and give it a layout
    gamePlayWindow = new QWidget();
    QPalette pal = gamePlayWindow->palette();

    // set blue background
    pal.setColor(QPalette::Background, QColor(136, 161, 204));
    gamePlayWindow->setAutoFillBackground(true);
    gamePlayWindow->setPalette(pal);

    //make gameplay layout
    gamePlayHLayout = new QHBoxLayout(gamePlayWindow);
    QVBoxLayout* gamePlayRightVLayout = new QVBoxLayout(gamePlayWindow);

    //Make a timer that generates snowflakes and monsters
    fallingObjectsTimer = new QTimer(gamescene);
    connect(fallingObjectsTimer,SIGNAL(timeout()),this,SLOT(itemGenerator()));

    //Add a quit button to return to the home screen
    quitButton = new QPushButton("QUIT GAME");
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitGame()));
    quitButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,175); color: rgb(255, 255, 255)}"));
    quitButton->setMinimumHeight(30);


    //Add points label
    score_label = new QLabel("Score: " + QString::number(points));
    score_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 30px; color: rgb(255, 255, 255);}"));
    score_label->setMinimumSize(200,50);
    score_label->setMaximumSize(200,50);


    //Add lives label
    lives_label = new QLabel("Lives: " + QString::number(lives));
    lives_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 30px; color: rgb(255, 255, 255);}"));



    //Make a label that gives the amount of time of a powerup remaining
    power_up_timer = new QLabel ("");
    power_up_timer->setMinimumSize(200,100);
    power_up_timer->setMaximumSize(200,100);
    power_up_timer->setWordWrap(true);
    power_up_timer->setStyleSheet("QLabel {font-family: Courier; font-size: 20px; color: rgb(255, 255, 255);}");


    //Set color of view
    view->setBackgroundBrush(QBrush(QColor(219, 229, 249),Qt::Dense1Pattern));

    //Make the view unscrollable
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Fix the size of the view and set the scene size to it
//    view->setFixedSize(648,800);
//    gamescene->setSceneRect(0,0,648,800);
    view->setFixedSize(400,500);
    gamescene->setSceneRect(0,0,400,500);


    //Add snowflake powerup meter
    snowflakeMeter = new powerUpMeter;

    gamePlayRightVLayout->addWidget(power_up_timer);
    gamePlayRightVLayout->addSpacing(10);
    gamePlayRightVLayout->addWidget(snowflakeMeter);
    gamePlayRightVLayout->addWidget(score_label);
    gamePlayRightVLayout->addWidget(lives_label);
    gamePlayRightVLayout->addWidget(quitButton);
    gamePlayRightVLayout->setAlignment(Qt::AlignCenter);

    gamePlayHLayout->addWidget(view);
    gamePlayHLayout->addLayout(gamePlayRightVLayout);


    //Make a playlist that plays music on loop
    QMediaPlaylist *playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("qrc:/bensound-jazzyfrenchy.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);


    //Make a music player for the game
    music = new QMediaPlayer(this);
    music->setPlaylist(playlist);

    //setvolume of the music player if not muted
    if (!muted)
        music->setVolume(50);
    else {
        music->setVolume(0);
    }


    //Make a sound for when lives are lost
    lostLifeSound = new QMediaPlayer(this);
    lostLifeSound->setMedia(QUrl("qrc:/67454__splashdust__negativebeep.wav"));
        lostLifeSound->setVolume(250);
    if(muted)
        lostLifeSound->setVolume(0);

    //Make a sound for when lives are lost
    gameOverSound = new QMediaPlayer(this);
    gameOverSound->setMedia(QUrl("qrc:/gameoversound.flac"));
        gameOverSound->setVolume(50);
    if(muted)
        gameOverSound->setVolume(0);

    //Make sound for when snowflakes are captured
    snowflakeCaptureSound = new QMediaPlayer(this);
    snowflakeCaptureSound->setMedia(QUrl("qrc:/snowflake_capture_sound.wav"));
        snowflakeCaptureSound->setVolume(100);
    if(muted)
        snowflakeCaptureSound->setVolume(0);


    //make a timer that continually sets the paddle as the focus once started
    //this timer is needed to  fix bugs that would take the focus off the paddle, making it uncontrollable during gameplay
    focustimer = new QTimer(this);
    connect(focustimer, SIGNAL(timeout()),this,SLOT(setpaddlefocus()));
}

void game::run_game(int lvl)
{
    //set the game level
    game_level=lvl;

    //set brick_count to 0
    brick_count = 0;

    //set ball_count to 0
    ballcount = 0;

    //reset the powerup meter
    snowflakeMeter->set_counter(0);

    //start playing the music
    music->play();

    //Set the view as the focus of the game widget
    view->setFocus();

    //Set up the bricks, depending on level
    SetUpBricks(game_level);

    //make paddle and add to scene
    mypaddle = new paddle(.2*gamescene->width());
    gamescene->addItem(mypaddle);

    //connect paddle to killedByMonster() slot for when monster hits paddle
    connect(mypaddle,SIGNAL(paddleDead()),this,SLOT(killedByMonster()));

    //set position of the paddle in the scene, generalized for different sized scenes
    mypaddle->setPos(gamescene->width()/2-mypaddle->getwidth()/2,gamescene->height()-.06*gamescene->height());

    //Add ball to scene
    ball* myball = generateNewBall();

    //Make paddle focusable
    mypaddle->setFlag(QGraphicsItem::ItemIsFocusable);

    //Set paddle as the focus
    mypaddle->setFocus();

    //start the timer to make sure nothing else overrides the paddle while the game window is open
    focustimer->start(500);

    fallingObjectsTimer->start(1000);
}

void game::itemGenerator()
{
    int randInt = rand()%100;
    if(game_level==1)
    {
        if(randInt<=30)
            blueSnowflakesGenerator();
        else if(randInt<=5)
            monsterGenerator();
    }
    else
    {
        if(randInt<=10)
            blueSnowflakesGenerator();
        else if(randInt>=95)
            greenSnowflakesGenerator();
        else if(randInt>20&&randInt<30)
            monsterGenerator();
    }
}

void game::monsterGenerator()
{
    int randInt = rand() % static_cast<int>(gamescene->width()-.1105*gamescene->width());
    Monster* mymonster = new Monster(.1105*gamescene->width());
    if(muted)
        mymonster->mute_monster();
    connect(mymonster,SIGNAL(update_points(int)),this,SLOT(update_score_on_monster_hit(int)));
    gamescene->addItem(mymonster);
    mymonster->setPos(randInt,0);
}

void game::blueSnowflakesGenerator()
{
    if(some_power_up_is_active())
        return;
    int randInt = rand() % static_cast<int>(gamescene->width()-.075*gamescene->width());
    snowflake* mysnowflake = new snowflake(.075*gamescene->width());
    connect(mysnowflake,SIGNAL(snowflake_captured()),this,SLOT(update_meter_on_snowflake_capture()));
    gamescene->addItem(mysnowflake);
    mysnowflake->setPos(randInt,0);
}

void game::greenSnowflakesGenerator()
{
    if(lives==3)
        return;
    int randInt = rand() % static_cast<int>(gamescene->width()-.075*gamescene->width());
    greenSnowflake* mygreensnowflake = new greenSnowflake(.075*gamescene->width());
    connect(mygreensnowflake,SIGNAL(green_snowflake_captured()),this,SLOT(update_lives_on_green_snowflake_capture()));
    gamescene->addItem(mygreensnowflake);
    mygreensnowflake->setPos(randInt,0);
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
}

void game::update_score_on_monster_hit(int pnts)
{
    points+=pnts;
    score_label->setText("Score: " + QString::number(points));
}

void game::update_meter_on_snowflake_capture()
{
    if(!some_power_up_is_active())
    {
        runPowerup();
        snowflakeCaptureSound->play();
        snowflakeMeter->update_counter();
       //if(snowflakeMeter->is_full())
           // runPowerup();
    }
}

void game::update_lives_on_green_snowflake_capture()
{
    if(lives==3)
        return;
    else {
        snowflakeCaptureSound->play();
        lives++;
        lives_label->setText("Lives: " + QString::number(lives));
    }
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
      ballcount = 0;
      mypaddle = nullptr;
      focustimer->stop();
      fallingObjectsTimer->stop();
      music->stop();
  }
}

void game::reset_game()
{
  clean_up_board();
  game_level = 0;
  points = 0;
  score_label->setText("Score: " + QString::number(points));
  lives = 3;
  lives_label->setText("Lives: " + QString::number(lives));
}

void game::a_ball_hit_ground()
{
  ballcount--;
  if(ballcount==0)
  {
    lives--;
    lives_label->setText("Lives: " + QString::number(lives));
    if(lives <= 0)
    {
        no_more_lives();
    }
    else {
        notifications* lifelost_notification = new notifications;
        gamescene->addItem(lifelost_notification);
        lifelost_notification->display_lost_life();
        lostLifeSound->play();
        QTimer::singleShot(300,this,SLOT(generateNewBall()));
    }
  }
}

void game::no_more_lives()
{
    music->stop();
    notifications* lifelost_notification = new notifications;
    gamescene->addItem(lifelost_notification);
    fallingObjectsTimer->stop();
    QList<QGraphicsItem*> items_list = gamescene->items();
    for(int i=0;i<items_list.size();i++)
    {
        if(typeid(*items_list[i])==typeid(ball)||typeid(*items_list[i])==typeid(Monster)||typeid(*items_list[i])==typeid(snowflake)||typeid(*items_list[i])==typeid(greenSnowflake))
        {
            gamescene->removeItem(items_list[i]);
            delete (items_list[i]);
        }
    }
    lifelost_notification->display_dead();
    gameOverSound->play();
    QTimer::singleShot(3400,[this](){emit time_to_enter_results_screen(points);
        reset_game();});
}


void game::killedByMonster()
{
    lives--;
    lives_label->setText("Lives: " + QString::number(lives));
    if(lives == 0)
    {
        no_more_lives();
    }
    else {
        notifications* lifelost_notification = new notifications;
        gamescene->addItem(lifelost_notification);
        lifelost_notification->display_lost_life();
        lostLifeSound->play();
    }
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
                brick* brick_to_add = new brick(gamescene->width()/9*.9,25,bricklevel);
                brick_count++;
                connect(brick_to_add,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                connect(brick_to_add,SIGNAL(decrease_brick_count()),this,SLOT(decrease_brick_count()));
                gamescene->addItem(brick_to_add);
                //set position of new brick in the scene
                brick_to_add->setPos(gamescene->width()/9*i+2,gamescene->width()/9*.6*j+2);
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
                brick* brick_to_add_left_top = new brick(gamescene->width()/12*.9,20,bricklevel);
                brick_count++;
                connect(brick_to_add_left_top,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                connect(brick_to_add_left_top,SIGNAL(decrease_brick_count()),this,SLOT(decrease_brick_count()));
                gamescene->addItem(brick_to_add_left_top);
                brick* brick_to_add_right_top = new brick(gamescene->width()/12*.9,20,bricklevel);
                brick_count++;
                connect(brick_to_add_right_top,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                connect(brick_to_add_right_top,SIGNAL(decrease_brick_count()),this,SLOT(decrease_brick_count()));
                gamescene->addItem(brick_to_add_right_top);
                brick* brick_to_add_left_bottom = new brick(gamescene->width()/12*.9,20,bricklevel);
                brick_count++;
                connect(brick_to_add_left_bottom,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                connect(brick_to_add_left_bottom,SIGNAL(decrease_brick_count()),this,SLOT(decrease_brick_count()));
                gamescene->addItem(brick_to_add_left_bottom);

                brick* brick_to_add_right_bottom = new brick(gamescene->width()/12*.9,20,bricklevel);
                brick_count++;
                connect(brick_to_add_right_bottom,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                connect(brick_to_add_right_bottom,SIGNAL(decrease_brick_count()),this,SLOT(decrease_brick_count()));

                gamescene->addItem(brick_to_add_right_bottom);
                //set position of new brick in the scene
                brick_to_add_left_top->setPos(gamescene->width()/12*(5-i),gamescene->width()/12*.65*(j-1));
                brick_to_add_right_top->setPos(gamescene->width()/12*(6+i),gamescene->width()/12*.65*(j-1));
                brick_to_add_left_bottom->setPos(gamescene->width()/12*(5-i),gamescene->width()/12*.65*(12-j));
                brick_to_add_right_bottom->setPos(gamescene->width()/12*(6+i),gamescene->width()/12*.65*(12-j));
            }
        }
    }
        if (game_level==2)
        {
            for (int i=0; i<7;i++)
            {
                if (i%2==0)
                {
                    for (int j=0;j<8;j++)
                    {


                        int bricklevel=0;
                        if (j<=3)
                            bricklevel=2;
                        else if (j<=5)
                            bricklevel=1;
                        else if (j<=8)
                            bricklevel=0;

                        brick* brick_to_add = new brick(gamescene->width()/7,gamescene->width()/7*.6,bricklevel);
                        brick_count++;
                        connect(brick_to_add,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
                        connect(brick_to_add,SIGNAL(decrease_brick_count()),this,SLOT(decrease_brick_count()));
                        gamescene->addItem(brick_to_add);
                        brick_to_add->setPos(gamescene->width()/7*i,gamescene->width()/7*.63*j);
                    }
                }
            }
        }
        if (game_level==4)
        {
            int bricklevel=1;
            std::vector<brick*> bricks;
            double unit_width = gamescene->width()/12.0;
            double unit_height= gamescene->width()/12.0*.61;
            for (int i=0; i<19;i++)
            {
            brick* brick_to_add = new brick(gamescene->width()/12*.9,25,bricklevel);
            brick_count++;
            connect(brick_to_add,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
            connect(brick_to_add,SIGNAL(decrease_brick_count()),this,SLOT(decrease_brick_count()));
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
            double unit_height= .04*gamescene->height();
            for (int i=0; i<49;i++)
            {   

            brick* brick_to_add = new brick(gamescene->width()/13.5,25,bricklevel);
            connect(brick_to_add,SIGNAL(update_points(int)),this,SLOT(update_score_on_brick_hit(int)));
            brick_count++;
            connect(brick_to_add,SIGNAL(decrease_brick_count()),this,SLOT(decrease_brick_count()));
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
    int randomVal = rand()%3;
    randomVal=2;

    if(randomVal==0)
    {
        for(int i=0;i<2;i++)
        {
            generateNewBall();
        }
    }


    else if(randomVal==1)
    {
        power_time = 5;
        QList<QGraphicsItem*> items_list = gamescene->items();
        for(int i=0;i<items_list.size();i++)
        {
            if(typeid(*items_list[i])==typeid(ball))
                dynamic_cast<ball*>(items_list[i])->power_up_ball();
        }
    }
    else
    {
        power_time=10;
        mypaddle->power_up_paddle();
    }
    run_powerup_bar_flash_animation();
}

void game::run_powerup_bar_flash_animation()
{
    flash_animation_timer = new QTimer(this);
    power_up_time = new QTimer(this);
    connect(flash_animation_timer,SIGNAL(timeout()),this,SLOT(powerup_meter_flash_helper()));
    connect(power_up_time,SIGNAL(timeout()),this,SLOT(change_time()));
    flash_animation_timer->start(150);
    change_time();
    power_up_time->start(1000);
}

void game::powerup_meter_flash_helper()
{
    if(some_power_up_is_active())
    {
        if(snowflakeMeter->is_empty())
        {
            snowflakeMeter->set_counter(3);
        }
        else if(snowflakeMeter->is_full())
        {
            snowflakeMeter->set_counter(0);
        }
    }
    else
    {
        if (flash_animation_timer!=nullptr)
            flash_animation_timer->stop();
        delete flash_animation_timer;
        flash_animation_timer = nullptr;
        snowflakeMeter->set_counter(0);
        return;
    }
}

void game::change_time()
{
    if (ballcount>1)
        return;
    if(some_power_up_is_active())
    {
        QString s1= "Power-Up Time Remaining:\n"+QString::number(power_time)+" Seconds";
    power_up_timer->setText(s1);
    power_time--;
    }
    else
    {
        power_up_time->stop();
        delete power_up_time;
        power_up_time=nullptr;
        power_up_timer->setText("");
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
        music->setVolume(50);
    else {
        music->setVolume(0);
    }
    //setvolume
    if (!muted)
        lostLifeSound->setVolume(150);
    else {
        lostLifeSound->setVolume(0);
    }

    //setvolume
    if (!muted)
        snowflakeCaptureSound->setVolume(100);
    else {
        snowflakeCaptureSound->setVolume(0);
    }

    //setvolume
    if (!muted)
        gameOverSound->setVolume(50);
    else {
        gameOverSound->setVolume(0);
    }
}


void game::decrease_brick_count()
{
    brick_count--;
    if (brick_count<=0)
    {
        QList<QGraphicsItem*> items_list = gamescene->items();
        for(int i=0;i<items_list.size();i++)
        {
            if(typeid(*items_list[i])==typeid(ball))
            {
                dynamic_cast<ball*>(items_list[i])->stopTimer();
            }
        }
        QTimer::singleShot(40,this,SLOT(nextLevel()));
    }
}

void game::nextLevel()
{
    clean_up_board();
    if(game_level==5)
        emit go_to_game_won_window(points);
    else
        emit just_beat_level(game_level);
}

ball* game::generateNewBall()
{
    ball* myball = new ball(.055*gamescene->width());
    gamescene->addItem(myball);
    if(muted)
        myball->mute_ball();
    ballcount += 1;
    myball->set_level(game_level);
    connect(myball,SIGNAL(ball_hit_ground()),this,SLOT(a_ball_hit_ground()));
    if(ballcount==1)
    {
        myball->setPos(mypaddle->x()+mypaddle->getwidth()/2-myball->get_size()/2,mypaddle->y()-myball->get_size()-2);
        connect(mypaddle,SIGNAL(space_bar_pressed()),myball,SLOT(start_moving_ball()));
        mypaddle->stick_ball_to_paddle();
    }
    else
    {
        myball->setPos(mypaddle->x()+mypaddle->getwidth()*(ballcount-2),mypaddle->y()-myball->get_size()-2);
        myball->start_moving_ball();
    }
    return myball;
}



void game::resizeGame(int size_factor)
{
    if(size_factor==1)
    {
        view->setFixedSize(400,500);
        gamescene->setSceneRect(0,0,400,500);
        snowflakeMeter->setMaximumSize(200,200);
        snowflakeMeter->setMinimumSize(200,200);
        quitButton->setMinimumHeight(30);
        power_up_timer->setStyleSheet("QLabel {font-family: Courier; font-size: 20px; color: rgb(255, 255, 255);}");
        score_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 30px; color: rgb(255, 255, 255);}"));
        lives_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 30px; color: rgb(255, 255, 255);}"));
        score_label->setMinimumSize(200,50);
        score_label->setMaximumSize(200,50);
        power_up_timer->setMinimumSize(200,100);
        power_up_timer->setMaximumSize(200,100);
    }
    else {
        view->setFixedSize(600,750);
        gamescene->setSceneRect(0,0,600,750);
        snowflakeMeter->setMaximumSize(300,300);
        snowflakeMeter->setMinimumSize(300,300);
        quitButton->setMinimumHeight(30*1.5);
        power_up_timer->setStyleSheet("QLabel {font-family: Courier; font-size: 30px; color: rgb(255, 255, 255);}");
        score_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 45px; color: rgb(255, 255, 255);}"));
        lives_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 45px; color: rgb(255, 255, 255);}"));
        score_label->setMinimumSize(200*1.5,50*1.5);
        score_label->setMaximumSize(200*1.5,50*1.5);
        power_up_timer->setMinimumSize(200*1.5,100*1.5);
        power_up_timer->setMaximumSize(200*1.5,100*1.5);
    }
}






game::~game()
{
    delete gamePlayWindow; gamePlayWindow = nullptr;
    delete gamePlayHLayout; gamePlayHLayout = nullptr;
}
