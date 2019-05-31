#include "levels_window.h"

levels_window::levels_window(QWidget *parent) : QMainWindow(parent)
{
    filter1 = new event_filter1(this);
    filter2 = new event_filter2(this);
    filter3 = new event_filter3(this);
    filter4 = new event_filter4(this);
    filter5 = new event_filter5(this);


    QWidget* centralWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    returnButton = new QPushButton("Return to main screen");
    connect(returnButton,&QPushButton::clicked,[this](){emit returnToMainWindow();});

    QPushButton* level1Button = new QPushButton("level 1");
    level1Button->setAttribute(Qt::WA_Hover);
    level1Button->installEventFilter(filter1);
    level1Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255);}"));
    connect(level1Button,&QPushButton::clicked,[this](){emit goToLevel(1);});

    QPushButton* level2Button = new QPushButton("level 2");
    level2Button->setAttribute(Qt::WA_Hover);
    level2Button->installEventFilter(filter2);
    level2Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255);}"));
    connect(level2Button,&QPushButton::clicked,[this](){emit goToLevel(2);});

    QPushButton* level3Button = new QPushButton("level 3");
    level3Button->setAttribute(Qt::WA_Hover);
    level3Button->installEventFilter(filter3);
    level3Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255);}"));
    connect(level3Button,&QPushButton::clicked,[this](){emit goToLevel(3);});

    QPushButton* level4Button = new QPushButton("level 4");
    level4Button->setAttribute(Qt::WA_Hover);
    level4Button->installEventFilter(filter4);
    level4Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255);}"));
    connect(level4Button,&QPushButton::clicked,[this](){emit goToLevel(4);});

    QPushButton* level5Button = new QPushButton("level 5");
    level5Button->setAttribute(Qt::WA_Hover);
    level5Button->installEventFilter(filter5);
    level5Button->setStyleSheet(QString("QPushButton {font-family: Courier; font-size: 15px; background-color: rgb(20, 170, 255); color: rgb(255, 255, 255);}"));
    connect(level5Button,&QPushButton::clicked,[this](){emit goToLevel(5);});

    QHBoxLayout* overall_layout = new QHBoxLayout;
    picture = new level_pic;
    connect(filter1, SIGNAL(show_pic1()),picture,SLOT(pic1()));
    connect(filter2, SIGNAL(show_pic2()),picture,SLOT(pic2()));
    connect(filter3, SIGNAL(show_pic3()),picture,SLOT(pic3()));
    connect(filter4, SIGNAL(show_pic4()),picture,SLOT(pic4()));
    connect(filter5, SIGNAL(show_pic5()),picture,SLOT(pic5()));
    connect(filter1, SIGNAL(blank1()),picture,SLOT(show_blank()));
    connect(filter2, SIGNAL(blank2()),picture,SLOT(show_blank()));
    connect(filter3, SIGNAL(blank3()),picture,SLOT(show_blank()));
    connect(filter4, SIGNAL(blank4()),picture,SLOT(show_blank()));
    connect(filter5, SIGNAL(blank5()),picture,SLOT(show_blank()));




    mainLayout->addWidget(level1Button);
    mainLayout->addWidget(level2Button);
    mainLayout->addWidget(level3Button);
    mainLayout->addWidget(level4Button);
    mainLayout->addWidget(level5Button);
    mainLayout->addWidget(returnButton);


    overall_layout->addWidget(picture);
    overall_layout->addLayout(mainLayout);


    centralWidget->setLayout(overall_layout);
    setCentralWidget(centralWidget);
}

level_pic::level_pic()
{
    this->setPixmap(QPixmap(":/IceBreakerBackground.png"));
}

void level_pic::pic1()
{
    this->setPixmap(QPixmap(":/first.png"));
}

void level_pic::pic2()
{

   this->setPixmap(QPixmap(":/rows.png"));
}

void level_pic::pic3()
{

    this->setPixmap(QPixmap(":/diamond.png"));

}

void level_pic::pic4()
{

    this->setPixmap(QPixmap(":/smiley.png"));

}

void level_pic::pic5()
{

    this->setPixmap(QPixmap(":/pasted image 0.png"));

}

void level_pic::show_blank()
{
    this->setPixmap(QPixmap(":/IceBreakerBackground.png"));
}



