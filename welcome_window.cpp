#include "welcome_window.h"
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QStyle>
#include <QPainter>
#include <QPaintEvent>

welcome_window::welcome_window(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget* centralWidget = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout();


    GameButton = new QPushButton("Start Game");
    connect(GameButton,SIGNAL(clicked()),this,SLOT(GameButtonClicked()));

    OptionButton = new QPushButton("Options");
    connect(OptionButton,SIGNAL(clicked()),this,SLOT(OptionButtonClicked()));
    OptionButton->setParent(this);

    InstructionButton = new QPushButton("Instructions");
    connect(InstructionButton,SIGNAL(clicked()),this,SLOT(instructionsButtonClicked()));

    QuitButton = new QPushButton("Quit Game");
    connect(QuitButton,SIGNAL(clicked()),this,SLOT(quitButtonClicked()));

    resizeWindow(1);

    mainLayout->addSpacing(280);
    mainLayout->addWidget(GameButton);
    mainLayout->setAlignment(GameButton,Qt::AlignHCenter);
    mainLayout->addWidget(InstructionButton);
    mainLayout->setAlignment(InstructionButton,Qt::AlignHCenter);
    mainLayout->addWidget(OptionButton);
    mainLayout->setAlignment(OptionButton,Qt::AlignHCenter);
    mainLayout->addWidget(QuitButton);
    mainLayout->setAlignment(QuitButton,Qt::AlignHCenter);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

}

void welcome_window::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/IceBreakerBackground.png").scaled(size()));
    QWidget::paintEvent(e);
}


welcome_window::~welcome_window()
{
}

void welcome_window::GameButtonClicked()
{
    emit startGame();
}

void welcome_window::quitButtonClicked()
{
    emit quitApplication();
}

void welcome_window::instructionsButtonClicked()
{
    emit showInstructions();
}

void welcome_window::OptionButtonClicked()
{
    emit showOptionsWindow();
}


void welcome_window::resizeWindow(int sizefactor)
{
    if(sizefactor == 1)
    {
        QString buttonstyle = "QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,175); color: rgb(255, 255, 255);} \
                                 QPushButton:hover:!pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                 QPushButton:hover:pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}";
        setMaximumSize(700,600);
        setMinimumSize(700,600);
        GameButton->setMaximumSize(300,75);
        GameButton->setMinimumSize(300,75);
        GameButton->setStyleSheet(buttonstyle);
        OptionButton->setMaximumSize(300,75);
        OptionButton->setMinimumSize(300,75);
        OptionButton->setStyleSheet(buttonstyle);
        InstructionButton->setMaximumSize(300,75);
        InstructionButton->setMinimumSize(300,75);
        InstructionButton->setStyleSheet(buttonstyle);
        QuitButton->setMaximumSize(300,75);
        QuitButton->setMinimumSize(300,75);
        QuitButton->setStyleSheet(buttonstyle);
    }
    else if(sizefactor==2)
    {
        setMaximumSize(1000,775);
        setMinimumSize(1000,775);

        QString buttonstyle = "QPushButton {font-family: Courier; font-size: 30px; border-style: outset; border-width: 5px;border-radius: 15px; border-color: white; background-color: rgba(50, 100, 150,175); color: rgb(255, 255, 255);} \
                                 QPushButton:hover:!pressed {font-family: Courier; font-size: 30px; border-style: outset; border-width: 5px;border-radius: 15px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                 QPushButton:hover:pressed {font-family: Courier; font-size: 30px; border-style: outset; border-width: 5px;border-radius: 15px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}";

        GameButton->setMaximumSize(450,75*1.2);
        GameButton->setMinimumSize(450,75*1.2);
        GameButton->setStyleSheet(buttonstyle);
        OptionButton->setMaximumSize(450,75*1.2);
        OptionButton->setMinimumSize(450,75*1.2);
        OptionButton->setStyleSheet(buttonstyle);
        InstructionButton->setMaximumSize(450,75*1.2);
        InstructionButton->setMinimumSize(450,75*1.2);
        InstructionButton->setStyleSheet(buttonstyle);
        QuitButton->setMaximumSize(450,75*1.2);
        QuitButton->setMinimumSize(450,75*1.2);
        QuitButton->setStyleSheet(buttonstyle);
    }
}
