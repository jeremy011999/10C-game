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
    QHBoxLayout* mainLayout = new QHBoxLayout();

    QPushButton* GameButton = new QPushButton("Start Game");
    GameButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(100, 0, 170); color: rgb(255, 255, 255);}"));
    connect(GameButton,SIGNAL(clicked()),this,SLOT(GameButtonClicked()));

    QPushButton* OptionButton = new QPushButton("Options");
    OptionButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}"));
    connect(OptionButton,SIGNAL(clicked()),this,SLOT(OptionButtonClicked()));

    QPushButton* InstructionButton = new QPushButton("Instructions");
    InstructionButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255);}"));

    QPushButton* QuitButton = new QPushButton("Quit Game");
    QuitButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(20, 20, 140); color: rgb(255, 255, 255);}"));

    mainLayout->addWidget(GameButton);
    mainLayout->addWidget(InstructionButton);
    mainLayout->addWidget(OptionButton);
    mainLayout->addWidget(QuitButton);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
    options= new optionswindow();
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

void welcome_window::OptionButtonClicked()
{
    options->show();
}

void welcome_window::MuteClicked()
{
    emit mute();
}
