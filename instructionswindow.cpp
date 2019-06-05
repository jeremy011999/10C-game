#include "instructionswindow.h"

InstructionsWindow::InstructionsWindow(QWidget *parent) :
    QMainWindow(parent)
{
    
    //Make a widget for each page
    howToPlayPage = new QWidget;
    enemiesPage = new QWidget;
    powerUpsPage = new QWidget;

    //Make a stacked widget
    stackedWidget = new QStackedWidget;

    //setup each page
    setUpHowToPlayPage();
    setUpEnemiesPage();
    setUpPowerUpPage();
    
    //set default index for stacked widget
    stackedWidget->setCurrentIndex(0);

    //set style sheet
    stackedWidget->setStyleSheet(QString("QWidget {background-color: rgb(136, 161, 204);}"));

}



void InstructionsWindow::setUpHowToPlayPage()
{
    //set up page layout
    QVBoxLayout* howToPlayPageLayout = new QVBoxLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;


    //make the instructions label
    QLabel* InstructionsLabel = new QLabel("HOW TO PLAY");
    InstructionsLabel->setMaximumHeight(100);
    InstructionsLabel->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px;color: rgb(0,0,128);}"));

    //make the how to play text
    QLabel* how_to_play_text = new QLabel("- The goal of \"IceBreaker\" is to hit as many ice blocks as possible without losing control of the ball as it flies\n- You can use the arrow keys on your keyboard in order to move the paddle from left to right and hit the ball\n- When you hit all the blocks in one round, you will advance to the next level\n- If your ball hits the ground and you have no more lives, the game will end");
    how_to_play_text->setWordWrap(true);
    how_to_play_text->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px;color: rgb(255, 255, 255);}"));

    //add the text to the layout
    howToPlayPageLayout->addWidget(InstructionsLabel,0,Qt::AlignHCenter);
    howToPlayPageLayout->addWidget(how_to_play_text,0,Qt::AlignHCenter);
    how_to_play_text->setMaximumSize(600,300);


    //make the button style
    QString buttonstyle = "QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);} \
                             QPushButton:hover:!pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                             QPushButton:hover:pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}";

    returnToMain1Button = new QPushButton("Return to Main Menu");
    nextPageEnemyButton = new QPushButton("Next Page: Enemies");

    returnToMain1Button->setStyleSheet(buttonstyle);
    nextPageEnemyButton->setStyleSheet(buttonstyle);

    buttonLayout->addWidget(returnToMain1Button,Qt::AlignLeft);
    buttonLayout->addWidget(nextPageEnemyButton,Qt::AlignRight);

    //set the minimum size of contents
    returnToMain1Button->setMinimumSize(250,50);
    nextPageEnemyButton->setMinimumSize(250,50);
    returnToMain1Button->setMaximumSize(250,50);
    nextPageEnemyButton->setMaximumSize(250,50);
    
    //make connections for the buttons to go between pages
    connect(nextPageEnemyButton,&QPushButton::clicked,[this](){stackedWidget->setCurrentIndex(1);});
    connect(returnToMain1Button,&QPushButton::clicked,[this](){stackedWidget->setCurrentIndex(0); emit returnButtonClicked();});

    howToPlayPageLayout->addLayout(buttonLayout);

    howToPlayPage->setLayout(howToPlayPageLayout);
    stackedWidget->addWidget(howToPlayPage);
    setCentralWidget(stackedWidget);
}



void InstructionsWindow::setUpEnemiesPage()
{
    //set up page layout
    QVBoxLayout* enemiesPageLayout = new QVBoxLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;

    //set up the text for header and explanation
    QLabel* EnemiesLabel = new QLabel("ENEMIES");
    EnemiesLabel->setMaximumHeight(100);
    EnemiesLabel->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px;color: rgb(0,0,128);}"));

    QLabel* enemie_explanation_text = new QLabel("- As you play the game, monster enemies will fly from the sky. In order to kill the monsters you must hit them with the ball and you will gain 20 points.\n- If the monster hits your paddle, you will lose a life. ");
    enemie_explanation_text->setWordWrap(true);
    enemie_explanation_text->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px;color: rgb(255, 255, 255);}"));

    enemiesPageLayout->addWidget(EnemiesLabel,0,Qt::AlignHCenter);
    enemiesPageLayout->addWidget(enemie_explanation_text,0,Qt::AlignHCenter);
    enemie_explanation_text->setMaximumSize(600,300);

    //set buttonstyle
    QString buttonstyle = "QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);} \
                             QPushButton:hover:!pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                             QPushButton:hover:pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}";

    prevPageHow2PlayButton = new QPushButton("Previous Page:\n How to Play");
    nextPagePowerupsButton = new QPushButton("Next Page: Powerups");

    //set stylesheets of buttons
    prevPageHow2PlayButton->setStyleSheet(buttonstyle);
    nextPagePowerupsButton->setStyleSheet(buttonstyle);

    buttonLayout->addWidget(prevPageHow2PlayButton,Qt::AlignLeft);
    buttonLayout->addWidget(nextPagePowerupsButton,Qt::AlignRight);

    //set minimum sizes
    prevPageHow2PlayButton->setMinimumSize(250,50);
    nextPagePowerupsButton->setMinimumSize(250,50);
    prevPageHow2PlayButton->setMaximumSize(250,50);
    nextPagePowerupsButton->setMaximumSize(250,50);

    //set up connections to go between pages
    connect(nextPagePowerupsButton,&QPushButton::clicked,[this](){stackedWidget->setCurrentIndex(2);});
    connect(prevPageHow2PlayButton,&QPushButton::clicked,[this](){stackedWidget->setCurrentIndex(0);});

    enemiesPageLayout->addLayout(buttonLayout);

    enemiesPage->setLayout(enemiesPageLayout);
    stackedWidget->addWidget(enemiesPage);
}



void InstructionsWindow::setUpPowerUpPage()
{
    //initialize powerups page
    QVBoxLayout* powerupsPageLayout = new QVBoxLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;


    //make header and explanation labels
    QLabel* PowerupsLabel = new QLabel("Powerups");
    PowerupsLabel->setMaximumHeight(100);
    PowerupsLabel->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px;color: rgb(0,0,128);}"));

    QLabel* powerup_explanation_text = new QLabel("- The snowflake meter to your right will fill up as you capture blue snowflakes.  When it is full, it will activate a powerup\n- The fireball powerup burns straight through the ice bricks, no matter what color the bricks are.\n- The golden paddle powerup gives you a longer paddle that is also invincible against monsters.\n- The multi-ball powerup puts more balls into the game. No lives are lost when extra balls hit the ground.\n- Green snowflakes will restore up to three lives. ");
    powerup_explanation_text->setWordWrap(true);
    powerup_explanation_text->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px;color: rgb(255, 255, 255);}"));

    powerupsPageLayout->addWidget(PowerupsLabel,0,Qt::AlignHCenter);
    powerupsPageLayout->addWidget(powerup_explanation_text,0,Qt::AlignHCenter);
    powerup_explanation_text->setMaximumSize(600,300);

    //make a stylesheet
    QString buttonstyle = "QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);} \
                             QPushButton:hover:!pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                             QPushButton:hover:pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}";

    prevPageEnemyButton = new QPushButton("Previous Page:\nEnemies");
    returnToMain2Button = new QPushButton("Return to\nMain Screen");

    //set button stylesheets
    prevPageEnemyButton->setStyleSheet(buttonstyle);
    returnToMain2Button->setStyleSheet(buttonstyle);

    buttonLayout->addWidget(prevPageEnemyButton,Qt::AlignLeft);
    buttonLayout->addWidget(returnToMain2Button,Qt::AlignRight);

    //set sizes of buttons
    prevPageEnemyButton->setMinimumSize(250,50);
    returnToMain2Button->setMinimumSize(250,50);
    prevPageEnemyButton->setMaximumSize(250,50);
    returnToMain2Button->setMaximumSize(250,50);

    //connect the buttons to go between pages
    connect(prevPageEnemyButton,&QPushButton::clicked,[this](){stackedWidget->setCurrentIndex(1);});
    connect(returnToMain2Button,&QPushButton::clicked,[this](){stackedWidget->setCurrentIndex(0); emit returnButtonClicked();});


    powerupsPageLayout->addLayout(buttonLayout);
    powerUpsPage->setLayout(powerupsPageLayout);
    
    //add to stacked widget
    stackedWidget->addWidget(powerUpsPage);
}


