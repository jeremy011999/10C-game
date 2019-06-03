#include "optionswindow.h"
#include <QVBoxLayout>

optionswindow::optionswindow(QMainWindow *parent) : QMainWindow(parent)
{
    setStyleSheet(QString("QWidget {background-color: rgb(136, 161, 204);}"));
    QWidget* main = new QWidget;
    title = new QLabel("Options Menu");

    mute_label = new QLabel("Mute: OFF");

    volume_settings = new QLabel("Volume Settings: ");
    difficulty_label = new QLabel("Change Difficulty:");
    size_label = new QLabel("Select Size of Window:");

    select_difficulty = new QComboBox;
    Mute = new QPushButton("Mute/Unmute Sound");
    select_difficulty->addItem("Easy");
    select_difficulty->addItem("Normal");
    select_difficulty->addItem("Hard");
    select_difficulty->setCurrentIndex(1);
    title->setAlignment(Qt::AlignHCenter);

    size_choice_combo_box = new QComboBox;
    size_choice_combo_box->addItem("Small");
    size_choice_combo_box->addItem("Large");
    connect(size_choice_combo_box,SIGNAL(currentIndexChanged(int)),this,SLOT(change_size(int)));




    connect(Mute,SIGNAL(clicked()),this,SLOT(MuteClicked()));
    connect(Mute,SIGNAL(clicked()),this,SLOT(change_button()));
    connect(select_difficulty,SIGNAL(currentIndexChanged(int)),this,SLOT(change_difficulty(int)));

    back = new QPushButton("Back to Main");
    connect(back,SIGNAL(clicked()),this,SLOT(backToMain()));


    QVBoxLayout* overall_layout = new QVBoxLayout;
    overall_layout->setAlignment(Qt::AlignHCenter);
    overall_layout->setAlignment(Qt::AlignVCenter);
    overall_layout->addWidget(title);
    overall_layout->addSpacing(50);
    QGridLayout* optionslayout= new QGridLayout;
    optionslayout->addWidget(volume_settings,0,0);
    optionslayout->addWidget(Mute,0,2);
    optionslayout->setAlignment(Qt::AlignCenter);
    optionslayout->addWidget(mute_label,0,3);
    optionslayout->addWidget(difficulty_label,2,0);
    optionslayout->addWidget(select_difficulty,2,2);
    optionslayout->addWidget(size_label,4,0);
    optionslayout->addWidget(size_choice_combo_box,4,2);
    optionslayout->setSpacing(25);
    overall_layout->addLayout(optionslayout);
    overall_layout->addWidget(back);
    overall_layout->setAlignment(back,Qt::AlignHCenter);
    overall_layout->addSpacing(250);
    main->setLayout(overall_layout);

    resizeWindow(1);

    this->setCentralWidget(main);
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
        Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: "+fontsize+"px; background-color: rgb(200, 10, 10); color: rgb(255, 255, 255);border-style: outset; border-width: 3px;border-radius: 10px; border-color: white}"));
        mute_label->setText("Muted");
    }
    else {
        Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: "+fontsize+"px; background-color: rgb(10, 200, 10); color: rgb(255, 255, 255);border-style: outset; border-width: 3px;border-radius: 10px; border-color: white}"));
        mute_label->setText("Unmuted");
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

void optionswindow::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QWidget::paintEvent(e);
}

void optionswindow::change_difficulty(int x)
{
    emit set_difficulty(x);
}


void optionswindow::change_size(int x)
{
    emit set_sizeFactor(x+1);
}

void optionswindow::resizeWindow(int szefactor)
{
    if(szefactor==1)
    {
        QString buttonstyle = "QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);} \
                                 QPushButton:hover:!pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                 QPushButton:hover:pressed {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}";

        fontsize = "15";

        Mute->setMinimumSize(200,30);
        Mute->setMaximumSize(200,30);

        if (muted)
        {
            Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: "+fontsize+"px; background-color: rgb(200, 10, 10); color: rgb(255, 255, 255);border-style: outset; border-width: 3px;border-radius: 10px; border-color: white}"));
            mute_label->setText("Muted");
        }
        else {
            Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: "+fontsize+"px; background-color: rgb(10, 200, 10); color: rgb(255, 255, 255);border-style: outset; border-width: 3px;border-radius: 10px; border-color: white}"));
            mute_label->setText("Unmuted");
        }

        mute_label->setMaximumWidth(150);
        mute_label->setMinimumWidth(150);
        mute_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px; color: rgb(255, 255, 255);}"));

        select_difficulty->setStyleSheet("QComboBox {font-family: Courier; font-size: 15px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255); border-style: outset; border-width: 3px;border-radius: 10px; border-color: white;}");
        select_difficulty->setMinimumSize(200,30);
        select_difficulty->setMaximumSize(200,30);

        size_choice_combo_box->setStyleSheet("QComboBox {font-family: Courier; font-size: 15px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255); border-style: outset; border-width: 3px;border-radius: 10px; border-color: white;}");
        size_choice_combo_box->setMinimumSize(200,30);
        size_choice_combo_box->setMaximumSize(200,30);

        volume_settings->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px; color: rgb(255, 255, 255);}"));
        difficulty_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px; color: rgb(255, 255, 255);}"));
        size_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px; color: rgb(255, 255, 255);}"));

        title->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 80px; color: rgb(255, 255, 255);}"));
        back->setStyleSheet(buttonstyle);
        back->setFixedSize(175,50);
    }
    else if(szefactor==2)
    {
        QString buttonstyle = "QPushButton {font-family: Courier; font-size: 30px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);} \
                                 QPushButton:hover:!pressed {font-family: Courier; font-size: 30px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                 QPushButton:hover:pressed {font-family: Courier; font-size: 30px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}";

        fontsize = "20";



        Mute->setMinimumSize(250,35);
        Mute->setMaximumSize(250,35);


        if (muted)
        {
            Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: "+fontsize+"px; background-color: rgb(200, 10, 10); color: rgb(255, 255, 255);border-style: outset; border-width: 3px;border-radius: 10px; border-color: white}"));
            mute_label->setText("Muted");
        }
        else {
            Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: "+fontsize+"px; background-color: rgb(10, 200, 10); color: rgb(255, 255, 255);border-style: outset; border-width: 3px;border-radius: 10px; border-color: white}"));
            mute_label->setText("Unmuted");
        }


        mute_label->setMaximumWidth(200);
        mute_label->setMinimumWidth(200);
        mute_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px; color: rgb(255, 255, 255);}"));

        select_difficulty->setStyleSheet("QComboBox {font-family: Courier; font-size: 20px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255); border-style: outset; border-width: 3px;border-radius: 10px; border-color: white;}");
        select_difficulty->setMinimumSize(250,35);
        select_difficulty->setMaximumSize(250,35);

        size_choice_combo_box->setStyleSheet("QComboBox {font-family: Courier; font-size: 20px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255); border-style: outset; border-width: 3px;border-radius: 10px; border-color: white;}");
        size_choice_combo_box->setMinimumSize(250,35);
        size_choice_combo_box->setMaximumSize(250,35);

        volume_settings->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px; color: rgb(255, 255, 255);}"));
        difficulty_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px; color: rgb(255, 255, 255);}"));
        size_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px; color: rgb(255, 255, 255);}"));


        title->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 120px; color: rgb(255, 255, 255);}"));
        back->setStyleSheet(buttonstyle);
        back->setFixedSize(500,100);
    }
}
