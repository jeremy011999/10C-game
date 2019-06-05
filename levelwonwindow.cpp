#include "levelwonwindow.h"

LevelWonWindow::LevelWonWindow():level_just_beat(0)
{
    //make a layout
    mainLayout = new QVBoxLayout();

    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, QColor(50, 100, 150));
    setAutoFillBackground(true);
    setPalette(pal);

    //make a message saying you won the level
    message = new QLabel("Congratulations!\nLevel " + QString::number(level_just_beat) + " Completed !!!");
    message -> setWordWrap(true);
    message->setAlignment(Qt::AlignCenter);
    
    //set stylesheet of message
    message->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 50px; color: rgb(255, 255, 255);}"));

    
    //make a push button to go to next level
    nextLevelButton = new QPushButton("Go To Next Level");
    nextLevelButton->setMinimumSize(400,100);
    nextLevelButton->setMaximumSize(400,100);
    connect(nextLevelButton,SIGNAL(clicked()),this,SLOT(nextLevelButtonClicked()));
    nextLevelButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 30px; background-color: rgb(255, 255, 255); color: rgb(20, 20, 140);}"));

    //make a quit button the returns user to home screen
    quitButton = new QPushButton("Quit Game");
    quitButton->setMinimumSize(400,100);
    quitButton->setMaximumSize(400,100);
    quitButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 30px; background-color: rgb(255, 255, 255); color: rgb(20, 20, 140);}"));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitButtonClicked()));

    //Setup the mainlayout sizing and alignments
    mainLayout->addStretch();
    mainLayout->addWidget(message);
    mainLayout->addSpacing(50);
    mainLayout->addWidget(nextLevelButton);
    mainLayout->addSpacing(50);
    mainLayout->addWidget(quitButton);
    mainLayout->setAlignment(nextLevelButton,Qt::AlignCenter);
    mainLayout->setAlignment(quitButton,Qt::AlignCenter);
    mainLayout->addStretch();
    setLayout(mainLayout);
}

void LevelWonWindow::set_level_just_beat(int lvl_just_beat)
{
    //set the label to the level that was just beat
    level_just_beat = lvl_just_beat;
    message->setText("Congratulations!<br> Level " + QString::number(level_just_beat) + " Completed!!!");
}



void LevelWonWindow::nextLevelButtonClicked()
{
    //go to next level when next level button clicked
    emit goToLevel(level_just_beat+1);
}

void LevelWonWindow::quitButtonClicked()
{
    //return home when quit is clicked
    emit returnToMainWindow();
}
