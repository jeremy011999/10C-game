#include "levels_window.h"

/*
Constructor for levels_window object that constructs event filters for buttons,
    implements all buttons and layouts for window as well as connects event filters
    to said level buttons
@param parent: sets parent to QMainWindow
*/
levels_window::levels_window(QWidget *parent) : QMainWindow(parent)
{
    //constructs event filters for buttons and hover events
    filter1 = new event_filter1(this);
    filter2 = new event_filter2(this);
    filter3 = new event_filter3(this);
    filter4 = new event_filter4(this);
    filter5 = new event_filter5(this);


    //setting up layout and return to main window button
    QWidget* centralWidget = new QWidget();
    mainLayout = new QVBoxLayout();
    returnButton = new QPushButton("Quit");
    connect(returnButton,&QPushButton::clicked,[this](){emit returnToMainWindow();});
    
    //level 1 button constructions and connection to event filter
    level1Button = new QPushButton("Level 1");
    level1Button->setAttribute(Qt::WA_Hover);
    level1Button->installEventFilter(filter1);
    connect(level1Button,&QPushButton::clicked,[this](){emit goToLevel(1);});

    //level 2 button constructions and connection to event filter
    level2Button = new QPushButton("Level 2");
    level2Button->setAttribute(Qt::WA_Hover);
    level2Button->installEventFilter(filter2);
    connect(level2Button,&QPushButton::clicked,[this](){emit goToLevel(2);});

    //level 3 button constructions and connection to event filter
    level3Button = new QPushButton("Level 3");
    level3Button->setAttribute(Qt::WA_Hover);
    level3Button->installEventFilter(filter3);
    connect(level3Button,&QPushButton::clicked,[this](){emit goToLevel(3);});

    //level 4 button constructions and connection to event filter
    level4Button = new QPushButton("Level 4");
    level4Button->setAttribute(Qt::WA_Hover);
    level4Button->installEventFilter(filter4);
    connect(level4Button,&QPushButton::clicked,[this](){emit goToLevel(4);});

    //level 5 button constructions and connection to event filter
    level5Button = new QPushButton("Level 5");
    level5Button->setAttribute(Qt::WA_Hover);
    level5Button->installEventFilter(filter5);
    connect(level5Button,&QPushButton::clicked,[this](){emit goToLevel(5);});
    
    
    QHBoxLayout* overall_layout = new QHBoxLayout;
    picture = new level_pic;
    
    //connecting each filter to the corresponding level picture
    //or blank if mouse has left button
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



    //adding buttons to layout
    mainLayout->addWidget(level1Button);
    mainLayout->addWidget(level2Button);
    mainLayout->addWidget(level3Button);
    mainLayout->addWidget(level4Button);
    mainLayout->addWidget(level5Button);
    mainLayout->addWidget(returnButton);

    directions1 = new QLabel("Choose Level to Start!");
    directions2 = new QLabel("Hover Over Buttons for Preview");
    directions1->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px;color: rgb(255, 255, 255);}"));
    directions2->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px;color: rgb(255, 255, 255);}"));



    overall_layout->addWidget(picture);
    overall_layout->addLayout(mainLayout);

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(directions1);
    vbox->setAlignment(directions1,Qt::AlignCenter);
    vbox->addWidget(directions2);
    vbox->setAlignment(directions2,Qt::AlignCenter);


    vbox->addLayout(overall_layout);

    centralWidget->setStyleSheet(QString("QWidget {background-color: rgb(136, 161, 204);}"));
    centralWidget->setLayout(vbox);
    setCentralWidget(centralWidget);
}

/*
slot to resize window based on optionswindow and connected in gui
@param sizeFactor: corresponds to either small (1) or large (2) windowsize
*/
void levels_window::resizeWindow(int sizeFactor)
{
    if(sizeFactor==1)
    {
        QString buttonstyle = "QPushButton {font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);} \
                                 QPushButton:hover:!pressed {min-width: 100px; min-height = 75px; font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                 QPushButton:hover:pressed {min-width: 100px; min-height = 75px; font-family: Courier; font-size: 20px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}";

        directions1->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 40px;color: rgb(255, 255, 255);}"));
        directions2->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 20px;color: rgb(255, 255, 255);}"));

        returnButton->setStyleSheet(buttonstyle);
        level1Button->setStyleSheet(buttonstyle);
        level2Button->setStyleSheet(buttonstyle);
        level3Button->setStyleSheet(buttonstyle);
        level4Button->setStyleSheet(buttonstyle);
        level5Button->setStyleSheet(buttonstyle);


        returnButton->setFixedSize(255,50);
        level1Button->setFixedSize(255,50);
        level2Button->setFixedSize(255,50);
        level3Button->setFixedSize(255,50);
        level4Button->setFixedSize(255,50);
        level5Button->setFixedSize(255,50);


        picture->setMaximumSize(400,500);
        picture->setMinimumSize(400,500);
    }
    if(sizeFactor==2)
    {
        QString buttonstyle = "QPushButton {font-family: Courier; font-size: 30px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,100); color: rgb(255, 255, 255);} \
                                 QPushButton:hover:!pressed {font-family: Courier; font-size: 30px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgba(50, 100, 150,255); color: rgb(255, 255, 255);}\
                                 QPushButton:hover:pressed {font-family: Courier; font-size: 30px; border-style: outset; border-width: 3px;border-radius: 10px; border-color: white; background-color: rgb(0, 0, 102); color: rgb(255, 255, 255);}";

       directions1->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 60px;color: rgb(255, 255, 255);}"));
       directions2->setStyleSheet(QString("QLabel {font-family: Courier; font-size: 30px;color: rgb(255, 255, 255);}"));

        returnButton->setStyleSheet(buttonstyle);
        level1Button->setStyleSheet(buttonstyle);
        level2Button->setStyleSheet(buttonstyle);
        level3Button->setStyleSheet(buttonstyle);
        level4Button->setStyleSheet(buttonstyle);
        level5Button->setStyleSheet(buttonstyle);


        returnButton->setFixedSize(300,75);
        level1Button->setFixedSize(300,75);
        level2Button->setFixedSize(300,75);
        level3Button->setFixedSize(300,75);
        level4Button->setFixedSize(300,75);
        level5Button->setFixedSize(300,75);

        picture->setMaximumSize(500,625);
        picture->setMinimumSize(500,625);


    }
}



level_pic::level_pic()
{
    this->setPixmap(*blanklvlpic);
    setScaledContents(true);
    setMaximumSize(600,750);
    setMinimumSize(600,750);
}

//void level_pic::paintEvent(QPaintEvent *e) {
//    QPainter painter(this);
//    QWidget::paintEvent(e);
//}

void level_pic::pic1()
{
    this->setPixmap(*firstlvlpic);
}

void level_pic::pic2()
{

   this->setPixmap(*scndlvlpic);
}

void level_pic::pic3()
{

    this->setPixmap(*thrdlvlpic);
}

void level_pic::pic4()
{

    this->setPixmap(*frthlvlpic);

}

void level_pic::pic5()
{
    this->setPixmap(*fthlvlpic);
}

void level_pic::show_blank()
{
    this->setPixmap(*blanklvlpic);
}
