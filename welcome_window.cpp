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


    QPushButton* GameButton = new QPushButton("Start Game");
    GameButton->setMaximumSize(300,75);
    GameButton->setMinimumSize(300,75);

    GameButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,175); color: rgb(255, 255, 255);}"));
    connect(GameButton,SIGNAL(clicked()),this,SLOT(GameButtonClicked()));

    QPushButton* OptionButton = new QPushButton("Options");
    OptionButton->setMaximumSize(300,75);
    OptionButton->setMinimumSize(300,75);
    OptionButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,175); color: rgb(255, 255, 255);}"));
    connect(OptionButton,SIGNAL(clicked()),this,SLOT(OptionButtonClicked()));
    OptionButton->setParent(this);

    QPushButton* InstructionButton = new QPushButton("Instructions");
    InstructionButton->setMaximumSize(300,75);
    InstructionButton->setMinimumSize(300,75);
    InstructionButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,175); color: rgb(255, 255, 255);}"));
    connect(InstructionButton,SIGNAL(clicked()),this,SLOT(instructionsButtonClicked()));

    QPushButton* QuitButton = new QPushButton("Quit Game");
    QuitButton->setMaximumSize(300,75);
    QuitButton->setMinimumSize(300,75);
    QuitButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,175); color: rgb(255, 255, 255);}"));
    connect(QuitButton,SIGNAL(clicked()),this,SLOT(quitButtonClicked()));

    mainLayout->setAlignment(InstructionButton,Qt::AlignHCenter);
    mainLayout->addSpacing(200);
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

    qDebug() << QString::number(GameButton->width());
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


