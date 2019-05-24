#include "optionswindow.h"
#include <QVBoxLayout>



optionswindow::optionswindow(QWidget *parent) : QWidget(parent)
{
    Mute = new QPushButton("Mute/Unmute Sound");
    Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(200, 10, 10); color: rgb(255, 255, 255);}"));


    connect(Mute,SIGNAL(clicked()),this,SLOT(MuteClicked()));
    connect(Mute,SIGNAL(clicked()),this,SLOT(change_button()));
    mute_notification = new QLabel("Mute: OFF");
    mute_notification->setAlignment(Qt::AlignHCenter);

    QPushButton* back = new QPushButton("back to main");
    connect(back,SIGNAL(clicked()),this,SLOT(backToMain()));


    QVBoxLayout* optionslayout= new QVBoxLayout;
    optionslayout->addSpacing(175);
    optionslayout->addWidget(Mute);
    optionslayout->addWidget(mute_notification);
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
    {
        mute_notification->setText("Mute: ON");
        Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(10, 200, 10); color: rgb(255, 255, 255);}"));
    }
    else
    {
        mute_notification->setText("Mute: OFF");
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
