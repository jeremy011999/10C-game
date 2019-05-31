#include "optionswindow.h"
#include <QVBoxLayout>

optionswindow::optionswindow(QWidget *parent) : QWidget(parent)
{
    Mute = new QPushButton("Mute/Unmute Sound");
    Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(200, 10, 10); color: rgb(255, 255, 255);}"));


    connect(Mute,SIGNAL(clicked()),this,SLOT(MuteClicked()));
    connect(Mute,SIGNAL(clicked()),this,SLOT(change_button()));

    QPushButton* back = new QPushButton("Back to Main");
    connect(back,SIGNAL(clicked()),this,SLOT(backToMain()));
    back->setStyleSheet(QString("QPushButton {font-family: Courier;}"));


    QVBoxLayout* optionslayout= new QVBoxLayout;
    optionslayout->addWidget(Mute);
    optionslayout->addWidget(back);
    setLayout(optionslayout);
}

void optionswindow::change_button()
{
    if (muted)
        muted=false;
    else {
        muted=true;
    }
    if (muted)
    Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(10, 200, 10); color: rgb(255, 255, 255);}"));
    else {
        Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(200, 10, 10); color: rgb(255, 255, 255);}"));
    }
}

void optionswindow::MuteClicked()
{
    emit mute();
}

void optionswindow::backToMain()
{
    emit goBackToMain();
}
