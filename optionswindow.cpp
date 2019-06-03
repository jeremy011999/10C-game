#include "optionswindow.h"
#include <QVBoxLayout>

optionswindow::optionswindow(QMainWindow *parent) : QMainWindow(parent)
{
    setStyleSheet(QString("QWidget {background-color: rgb(136, 161, 204);}"));
    QWidget* main = new QWidget;
    QLabel* title = new QLabel("Options Menu");

    mute_label = new QLabel("Mute: OFF");
    mute_label->setMaximumWidth(100);
    mute_label->setMinimumWidth(100);

    QLabel* volume_settings = new QLabel("Volume Settings: ");
    QLabel* difficulty_label = new QLabel("Change Difficulty:");

    select_difficulty = new QComboBox;
    select_difficulty->setStyleSheet("QComboBox {font-family: Courier; font-size: 12px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255);}");
    Mute = new QPushButton("Mute/Unmute Sound");
    Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(200, 10, 10); color: rgb(255, 255, 255);}"));
    select_difficulty->addItem("Easy");
    select_difficulty->addItem("Normal");
    select_difficulty->addItem("Hard");
    select_difficulty->setCurrentIndex(0);
    volume_settings->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px; color: rgb(255, 255, 255);}"));
    difficulty_label->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px; color: rgb(255, 255, 255);}"));
    title->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 120px; color: rgb(255, 255, 255);}"));
    title->setAlignment(Qt::AlignHCenter);




    connect(Mute,SIGNAL(clicked()),this,SLOT(MuteClicked()));
    connect(Mute,SIGNAL(clicked()),this,SLOT(change_button()));
    connect(select_difficulty,SIGNAL(currentIndexChanged(int)),this,SLOT(change_difficulty(int)));

    QPushButton* back = new QPushButton("Back to Main");
    back->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 2px;border-radius: 5px; border-color: white; background-color: rgba(50, 100, 150,175); color: rgb(255, 255, 255);}"));
    connect(back,SIGNAL(clicked()),this,SLOT(backToMain()));


    QVBoxLayout* overall_layout = new QVBoxLayout;
    overall_layout->setAlignment(Qt::AlignHCenter);
    overall_layout->addWidget(title);
    overall_layout->addSpacing(50);
    QGridLayout* optionslayout= new QGridLayout;
    optionslayout->addWidget(volume_settings,0,0);
    optionslayout->addWidget(Mute,0,2);
    optionslayout->setAlignment(Qt::AlignCenter);
    optionslayout->addWidget(mute_label,0,3);
    //optionslayout->addSpacing(30);
    optionslayout->addWidget(difficulty_label,2,0);
    optionslayout->addWidget(select_difficulty,2,2);
    //optionslayout->addSpacing(60);
    optionslayout->addWidget(back,6,1);
    optionslayout->setSpacing(25);
    overall_layout->addLayout(optionslayout);
    overall_layout->addSpacing(250);
    main->setLayout(overall_layout);

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
        Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(10, 200, 10); color: rgb(255, 255, 255);}"));
        mute_label->setText("Mute: ON");
    }
    else {
        Mute->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15 px; background-color: rgb(200, 10, 10); color: rgb(255, 255, 255);}"));
        mute_label->setText("Mute: OFF");
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
    //painter.drawPixmap(0, 0, QPixmap(":/ice.jpg").scaled(size()));
    QWidget::paintEvent(e);
}

void optionswindow::change_difficulty(int x)
{
    emit set_difficulty(x);
}
