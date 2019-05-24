#include "levels_window.h"

levels_window::levels_window(QWidget *parent) : QMainWindow(parent)
{
    QWidget* centralWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    returnButton = new QPushButton("Return to main screen");
    returnButton->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}"));
    connect(returnButton,SIGNAL(clicked()),this,SLOT(returnButtonClicked()));

    QPushButton* level1Button = new QPushButton("level 1");
    level1Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}"));
    connect(level1Button,SIGNAL(clicked()),this,SLOT(level1ButtonClicked()));

    QPushButton* level2Button = new QPushButton("level 2");
    level2Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}"));
    connect(level2Button,SIGNAL(clicked()),this,SLOT(level2ButtonClicked()));

    QPushButton* level3Button = new QPushButton("level 3");
    level3Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}"));
    connect(level3Button,SIGNAL(clicked()),this,SLOT(level3ButtonClicked()));

    QPushButton* level4Button = new QPushButton("level 4");
    level4Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}"));
    connect(level4Button,SIGNAL(clicked()),this,SLOT(level4ButtonClicked()));

    QPushButton* level5Button = new QPushButton("level 5");
    level5Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(50, 100, 150); color: rgb(255, 255, 255);}"));
    connect(level5Button,SIGNAL(clicked()),this,SLOT(level5ButtonClicked()));


    mainLayout->addWidget(level1Button);
    mainLayout->addWidget(level2Button);
    mainLayout->addWidget(level3Button);
    mainLayout->addWidget(level4Button);
    mainLayout->addWidget(level5Button);
    mainLayout->addWidget(returnButton);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);



}

void levels_window::returnButtonClicked()
{
    emit returnToMainWindow();
}

void levels_window::level1ButtonClicked()
{
    emit goToLevel(1);
}

void levels_window::level2ButtonClicked()
{
    emit goToLevel(2);
}

void levels_window::level3ButtonClicked()
{
    emit goToLevel(3);
}

void levels_window::level4ButtonClicked()
{
    emit goToLevel(4);
}

void levels_window::level5ButtonClicked()
{
    emit goToLevel(5);
}
